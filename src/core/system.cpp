/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Core system functions
*/

#include "hge_impl.h"
#include <string.h>
#define LOWORDINT(n) ((int)((signed short)(LOWORD(n))))
#define HIWORDINT(n) ((int)((signed short)(HIWORD(n))))


const char *WINDOW_CLASS_NAME = "HGE__WNDCLASS";


int			nRef=0;
HGE_Impl*	pHGE=0;


HGE* CALL hgeCreate(int ver)
{
	if(ver==HGE_VERSION)
		return (HGE*)HGE_Impl::_Interface_Get();
	else
		return 0;
}


HGE_Impl* HGE_Impl::_Interface_Get()
{
	if(!pHGE) pHGE=new HGE_Impl();

	nRef++;

	return pHGE;
}


void CALL HGE_Impl::Release()
{
	nRef--;

	if(!nRef)
	{
		if(pHGE->hwnd) pHGE->System_Shutdown();
		Resource_RemoveAllPacks();
		delete pHGE;
		pHGE=0;
	}
}

void SetVSync(bool sync)
{
	
}



bool CALL HGE_Impl::System_Initiate()
{	
	// Init subsystems	
	Random_Seed();
	if(!_GfxInit()) { System_Shutdown(); return false; }	
	if(!_SoundInit()) { System_Shutdown(); return false; }
	System_Log("Init done.\n");
	return true;
}

void CALL HGE_Impl::System_Shutdown()
{
	System_Log("\nFinishing..");

	_ClearQueue();
	_SoundDone();
	_GfxDone();
	_DonePowerStatus();
	SDL_Quit();
	System_Log("The End.");
}


bool CALL HGE_Impl::System_Start()
{
	//Tu.NguyenHoang Gameloop here	
	if(!procFrameFunc) {
		_PostError("System_Start: No frame function defined");
		return false;
	}
	bActive=true;
	// MAIN LOOP
	bool done = false;
	while (!done) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {	
			//ProcessInput : Will implement later
			done = ProcessInput(&event);
			if (done)
				break;
		}
		//Process FrameRate
		dt = SDL_GetTicks() - t0;				
		if (dt >= nFixedDelta)
		{
			fDeltaTime = dt / 1000.0f;
			if (fDeltaTime > 0.2f){
				if (nFixedDelta)
					fDeltaTime = nFixedDelta / 1000.0f;
				else
					fDeltaTime = 0.01f;
			}
			fTime += fDeltaTime;
			t0 = SDL_GetTicks();
			if (t0 - t0fps < 1000)
				cfps++;
			else {
				nFPS = cfps;
				cfps = 0;
				t0fps = t0;
			}
			//UpdateFrame
			if (procFrameFunc()){
				break;
			}
			_ClearQueue();
			//Render
			if (procRenderFunc)
				procRenderFunc();
			//_ClearQueue();
		}
		else{
			if (nFixedDelta && dt + 3 < nFixedDelta)
				SDL_Delay(1);
		}
	}

	_ClearQueue();

	bActive=false;

	return true;
}
//Tu.NguyenHoang add function Process Input
int CALL HGE_Impl::SDLKeyToHgeKey(int key)
{
	switch(key)
	{		
		 case SDL_SCANCODE_BACKSPACE:	 return HGEK_BACKSPACE;
		 case SDL_SCANCODE_TAB:          return HGEK_TAB;		 
		 case SDL_SCANCODE_PAUSE:        return HGEK_PAUSE;
		 case SDL_SCANCODE_ESCAPE:       return HGEK_ESCAPE;
		 case SDL_SCANCODE_SPACE:        return HGEK_SPACE;
		 case SDL_SCANCODE_COMMA:        return HGEK_COMMA;
		 case SDL_SCANCODE_MINUS:        return HGEK_MINUS;
		 case SDL_SCANCODE_PERIOD:       return HGEK_PERIOD;
		 case SDL_SCANCODE_SLASH:        return HGEK_SLASH;
		 case SDL_SCANCODE_0:            return HGEK_0;
		 case SDL_SCANCODE_1:            return HGEK_1;
		 case SDL_SCANCODE_2:            return HGEK_2;
		 case SDL_SCANCODE_3:            return HGEK_3;
		 case SDL_SCANCODE_4:            return HGEK_4;
		 case SDL_SCANCODE_5:            return HGEK_5;
		 case SDL_SCANCODE_6:            return HGEK_6;
		 case SDL_SCANCODE_7:            return HGEK_7;
		 case SDL_SCANCODE_8:            return HGEK_8;
		 case SDL_SCANCODE_9:            return HGEK_9;		 
		 case SDL_SCANCODE_SEMICOLON:    return HGEK_SEMICOLON;
		 case SDL_SCANCODE_EQUALS:       return HGEK_EQUALS;		 
		 case SDL_SCANCODE_BACKSLASH:    return HGEK_BACKSLASH;
		 case SDL_SCANCODE_A:            return HGEK_A;
		 case SDL_SCANCODE_B:            return HGEK_B;
		 case SDL_SCANCODE_C:            return HGEK_C;
		 case SDL_SCANCODE_D:            return HGEK_D;
		 case SDL_SCANCODE_E:            return HGEK_E;
		 case SDL_SCANCODE_F:            return HGEK_F;
		 case SDL_SCANCODE_G:            return HGEK_G;
		 case SDL_SCANCODE_H:            return HGEK_H;
		 case SDL_SCANCODE_I:            return HGEK_I;
		 case SDL_SCANCODE_J:            return HGEK_J;
		 case SDL_SCANCODE_K:            return HGEK_K;
		 case SDL_SCANCODE_L:            return HGEK_L;
		 case SDL_SCANCODE_M:            return HGEK_M;
		 case SDL_SCANCODE_N:            return HGEK_N;
		 case SDL_SCANCODE_O:            return HGEK_O;
		 case SDL_SCANCODE_P:            return HGEK_P;
		 case SDL_SCANCODE_Q:            return HGEK_Q;
		 case SDL_SCANCODE_R:            return HGEK_R;
		 case SDL_SCANCODE_S:            return HGEK_S;
		 case SDL_SCANCODE_T:            return HGEK_T;
		 case SDL_SCANCODE_U:            return HGEK_U;
		 case SDL_SCANCODE_V:            return HGEK_V;
		 case SDL_SCANCODE_W:            return HGEK_W;
		 case SDL_SCANCODE_X:            return HGEK_X;
		 case SDL_SCANCODE_Y:            return HGEK_Y;
		 case SDL_SCANCODE_Z:            return HGEK_Z;
		 case SDL_SCANCODE_DELETE:       return HGEK_DELETE;
		/* case SDL_SCANCODE_KP0:          return HGEK_NUMPAD0;
		 case SDL_SCANCODE_KP1:          return HGEK_NUMPAD1;
		 case SDL_SCANCODE_KP2:          return HGEK_NUMPAD2;
		 case SDL_SCANCODE_KP3:          return HGEK_NUMPAD3;
		 case SDL_SCANCODE_KP4:          return HGEK_NUMPAD4;
		 case SDL_SCANCODE_KP5:          return HGEK_NUMPAD5;
		 case SDL_SCANCODE_KP6:          return HGEK_NUMPAD6;
		 case SDL_SCANCODE_KP7:          return HGEK_NUMPAD7;
		 case SDL_SCANCODE_KP8:          return HGEK_NUMPAD8;
		 case SDL_SCANCODE_KP9:          return HGEK_NUMPAD9;*/
		 /*case SDL_SCANCODE_KP_PERIOD:    return HGEK_DECIMAL;
		 case SDL_SCANCODE_KP_DIVIDE:    return HGEK_DIVIDE;
		 case SDL_SCANCODE_KP_MULTIPLY:  return HGEK_MULTIPLY;
		 case SDL_SCANCODE_KP_MINUS:     return HGEK_SUBTRACT;
		 case SDL_SCANCODE_KP_PLUS:      return HGEK_ADD;*/
		 case SDL_SCANCODE_UP:           return HGEK_UP;
		 case SDL_SCANCODE_DOWN:         return HGEK_DOWN;
		 case SDL_SCANCODE_RIGHT:        return HGEK_RIGHT;
		 case SDL_SCANCODE_LEFT:         return HGEK_LEFT;
		 case SDL_SCANCODE_INSERT:       return HGEK_INSERT;
		 case SDL_SCANCODE_HOME:         return HGEK_HOME;
		 case SDL_SCANCODE_END:          return HGEK_END;
		 case SDL_SCANCODE_PAGEUP:       return HGEK_PGUP;
		 case SDL_SCANCODE_PAGEDOWN:     return HGEK_PGDN;
		 case SDL_SCANCODE_F1:           return HGEK_F1;
		 case SDL_SCANCODE_F2:           return HGEK_F2;
		 case SDL_SCANCODE_F3:           return HGEK_F3;
		 case SDL_SCANCODE_F4:           return HGEK_F4;
		 case SDL_SCANCODE_F5:           return HGEK_F5;
		 case SDL_SCANCODE_F6:           return HGEK_F6;
		 case SDL_SCANCODE_F7:           return HGEK_F7;
		 case SDL_SCANCODE_F8:           return HGEK_F8;
		 case SDL_SCANCODE_F9:           return HGEK_F9;
		 case SDL_SCANCODE_F10:          return HGEK_F10;
		 case SDL_SCANCODE_F11:          return HGEK_F11;
		 case SDL_SCANCODE_F12:          return HGEK_F12;		 
	/*	 case SDL_SCANCODE_NUMLOCK:      return HGEK_NUMLOCK;
		 case SDL_SCANCODE_SCROLLOCK:    return HGEK_SCROLLLOCK;*/
		 default:                return 0;
	}
}
bool CALL HGE_Impl::ProcessInput(SDL_Event* event)
{
	switch(event->type)
	{
		case SDL_QUIT:
			return true;
		case SDL_KEYDOWN:
			pHGE->_BuildEvent(INPUT_KEYDOWN,SDLKeyToHgeKey(event->key.keysym.scancode),event->key.keysym.scancode,0,-1,-1);												
			break;
		case SDL_KEYUP:
			pHGE->_BuildEvent(INPUT_KEYUP,SDLKeyToHgeKey(event->key.keysym.scancode),event->key.keysym.scancode,0,0,0);				
			break;
		case SDL_MOUSEBUTTONDOWN:
			{
				if(event->button.button == SDL_BUTTON_LEFT)
				{
					pHGE->_BuildEvent(INPUT_MBUTTONDOWN,HGEK_LBUTTON,0,0,event->button.x,event->button.y);
				}
				if(event->button.button == SDL_BUTTON_RIGHT)
				{
					pHGE->_BuildEvent(INPUT_MBUTTONDOWN,HGEK_RBUTTON,event->button.button,0,event->button.x,event->button.y);
				}
			}
			break;				
		case SDL_MOUSEBUTTONUP:
			{
				if(event->button.button == SDL_BUTTON_LEFT)
				{
					pHGE->_BuildEvent(INPUT_MBUTTONUP,HGEK_LBUTTON,0,0,event->button.x,event->button.y);
				}
				if(event->button.button == SDL_BUTTON_RIGHT)
				{
					pHGE->_BuildEvent(INPUT_MBUTTONUP,HGEK_RBUTTON,0,0,event->button.x,event->button.y);
				}
			}
			break;
		case SDL_MOUSEMOTION:
			{
				pHGE->_BuildEvent(INPUT_MOUSEMOVE,0,0,0,event->button.x,event->button.y);
			}
			break;
	}
	return false;
}
void CALL HGE_Impl::System_SwapBuffers()
{
	//SwapBuffers(GetDC(hwnd));	
	SDL_GL_SwapBuffers();
}

void CALL HGE_Impl::System_SetStateBool(hgeBoolState state, bool value)
{
	switch(state)
	{
		case HGE_WINDOWED:		//TODO: add code here
								//if(hwndParent) break;
								//bWindowed=value;
			
								
								break;

		case HGE_ZBUFFER:		//TODO:  add code here
								break;

		case HGE_TEXTUREFILTER: //TODO:
								break;

		case HGE_USESOUND:		if(bUseSound!=value)
								{
									bUseSound=value;
									if(bUseSound && hwnd) _SoundInit();
									if(!bUseSound && hwnd) _SoundDone();
								}
								break;

		case HGE_HIDEMOUSE:		bHideMouse=value; break;

		case HGE_DONTSUSPEND:	bDontSuspend=value; break;
	}
}

void CALL HGE_Impl::System_SetStateFunc(hgeFuncState state, hgeCallback value)
{
	switch(state)
	{
		case HGE_FRAMEFUNC:		 procFrameFunc=value; break;
		case HGE_RENDERFUNC:	 procRenderFunc=value; break;
		case HGE_FOCUSLOSTFUNC:	 procFocusLostFunc=value; break;
		case HGE_FOCUSGAINFUNC:	 procFocusGainFunc=value; break;
		case HGE_GFXRESTOREFUNC: procGfxRestoreFunc=value; break;
		case HGE_EXITFUNC:		 procExitFunc=value; break;
	}
}

void CALL HGE_Impl::System_SetStateHwnd(hgeHwndState state, HWND value)
{
	switch(state)
	{
		case HGE_HWNDPARENT:	if(!hwnd) hwndParent=value; break;
	}
}

void CALL HGE_Impl::System_SetStateInt(hgeIntState state, int value)
{
	switch(state)
	{
		case HGE_SCREENWIDTH:	//TODO:
				nScreenWidth=value;
			break;

		case HGE_SCREENHEIGHT:	//TODO:
			nScreenHeight=value;
			break;

		case HGE_SCREENBPP:		//TODO:
			nScreenBPP=value;	
			break;

		case HGE_SAMPLERATE:	if(!hBass) nSampleRate=value;
								break;

		case HGE_FXVOLUME:		nFXVolume=value;
								_SetFXVolume(nFXVolume);
								break;

		case HGE_MUSVOLUME:		nMusVolume=value;
								_SetMusVolume(nMusVolume);
								break;

		case HGE_STREAMVOLUME:	nStreamVolume=value;
								_SetStreamVolume(nStreamVolume);
								break;

		case HGE_FPS:		//TODO:
								nHGEFPS=value;
								if(nHGEFPS>0) nFixedDelta=int(1000.0f/value);
								else nFixedDelta=0;
								break;
	}
}

void CALL HGE_Impl::System_SetStateString(hgeStringState state, const char *value)
{
	FILE *hf;
	
	switch(state)
	{
		case HGE_ICON:			szIcon=value;
								//if(pHGE->hwnd) SetClassLong(pHGE->hwnd, GCL_HICON, (LONG)LoadIcon(pHGE->hInstance, szIcon));
								break;
		case HGE_TITLE:			strcpy(szWinTitle,value);
								//if(pHGE->hwnd) SetWindowText(pHGE->hwnd, szWinTitle);
								break;
		case HGE_INIFILE:		if(value) strcpy(szIniFile,Resource_MakePath(value));
								else szIniFile[0]=0;
								break;
		case HGE_LOGFILE:		if(value)
								{
									strcpy(szLogFile,Resource_MakePath(value));
									hf=fopen(szLogFile, "w");
									if(!hf) szLogFile[0]=0;
									else fclose(hf);
								}
								else szLogFile[0]=0;
								break;
	}
}

bool CALL HGE_Impl::System_GetStateBool(hgeBoolState state)
{
	switch(state)
	{
		case HGE_WINDOWED:		return bWindowed;
		case HGE_ZBUFFER:		return bZBuffer;
		case HGE_TEXTUREFILTER:	return bTextureFilter;
		case HGE_USESOUND:		return bUseSound;
		case HGE_DONTSUSPEND:	return bDontSuspend;
		case HGE_HIDEMOUSE:		return bHideMouse;
	}

	return false;
}

hgeCallback CALL HGE_Impl::System_GetStateFunc(hgeFuncState state)
{
	switch(state)
	{
		case HGE_FRAMEFUNC:		return procFrameFunc;
		case HGE_RENDERFUNC:	return procRenderFunc;
		case HGE_FOCUSLOSTFUNC:	return procFocusLostFunc;
		case HGE_FOCUSGAINFUNC:	return procFocusGainFunc;
		case HGE_EXITFUNC:		return procExitFunc;
	}

	return NULL;
}

HWND CALL HGE_Impl::System_GetStateHwnd(hgeHwndState state)
{
	return 0;
}

int CALL HGE_Impl::System_GetStateInt(hgeIntState state)
{
	switch(state)
	{
		case HGE_SCREENWIDTH:	return nScreenWidth;
		case HGE_SCREENHEIGHT:	return nScreenHeight;
		case HGE_SCREENBPP:		return nScreenBPP;
		case HGE_SAMPLERATE:	return nSampleRate;
		case HGE_FXVOLUME:		return nFXVolume;
		case HGE_MUSVOLUME:		return nMusVolume;
		case HGE_STREAMVOLUME:	return nStreamVolume;
		case HGE_FPS:			return nHGEFPS;
		case HGE_POWERSTATUS:	return nPowerStatus;
	}

	return 0;
}

const char* CALL HGE_Impl::System_GetStateString(hgeStringState state) {
	switch(state) {
		case HGE_ICON:			return szIcon;
		case HGE_TITLE:			return szWinTitle;
		case HGE_INIFILE:		if(szIniFile[0]) return szIniFile;
								else return 0;
		case HGE_LOGFILE:		if(szLogFile[0]) return szLogFile;
								else return 0;
	}

	return NULL;
}

char* CALL HGE_Impl::System_GetErrorMessage()
{
	return szError;
}

void CALL HGE_Impl::System_Log(const char *szFormat, ...)
{
#ifndef HGE_USE_SDL
	FILE *hf = NULL;
	va_list ap;
	
	if(!szLogFile[0]) return;

	hf = fopen(szLogFile, "a");
	if(!hf) return;

	va_start(ap, szFormat);
	vfprintf(hf, szFormat, ap);
	va_end(ap);

	fprintf(hf, "\n");

	fclose(hf);
#endif
#ifdef OS_ANDROID
	DEBUG_OUT("--------------------%s",szFormat);
#endif


}

bool CALL HGE_Impl::System_Launch(const char *url)
{
	return false;
}

void CALL HGE_Impl::System_Snapshot(const char *filename)
{
	//TODO: insert code here
}

//////// Implementation ////////


HGE_Impl::HGE_Impl()
{
//	hInstance=GetModuleHandle(0);
//	hwnd=0;
	bActive=false;
	szError[0]=0;

	textures=0;

	hBass=0;
	bSilent=false;
	streams=0;

	hSearch=0;
	res=0;

	queue=0;
	Char=VKey=Zpos=0;
	Xpos=Ypos=0.0f;
	bMouseOver=false;
	bCaptured=false;

	nHGEFPS=HGEFPS_UNLIMITED;
	fTime=0.0f;
	fDeltaTime=0.0f;
	nFPS=0;
	
	procFrameFunc=0;
	procRenderFunc=0;
	procFocusLostFunc=0;
	procFocusGainFunc=0;
	procGfxRestoreFunc=0;
	procExitFunc=0;
	szIcon=0;
	strcpy(szWinTitle,"HGE");
	nScreenWidth=800;
	nScreenHeight=600;
	nScreenBPP=32;
	bWindowed=false;
	bZBuffer=false;
	bTextureFilter=true;
	szLogFile[0]=0;
	szIniFile[0]=0;
	bUseSound=true;
	nSampleRate=44100;
	nFXVolume=100;
	nMusVolume=100;
	nStreamVolume=100;
	nFixedDelta=0;
	bHideMouse=true;
	bDontSuspend=false;
	hwndParent=0;

	nPowerStatus=HGEPWR_UNSUPPORTED;
	hKrnl32 = NULL;	
	strcpy (szAppPath, "");
}

void HGE_Impl::_PostError(char *error)
{
	System_Log(error);
	strcpy(szError,error);
}

void HGE_Impl::_FocusChange(bool bAct)
{
	bActive=bAct;

	if(bActive)
	{
		if(procFocusGainFunc) procFocusGainFunc();
	}
	else
	{
		if(procFocusLostFunc) procFocusLostFunc();
	}
}


void HGE_Impl::_AdjustWindow()
{
	
}
DWORD CALL HGE_Impl::GetScreenWidth() {
	return nScreenWidth;
}

DWORD CALL HGE_Impl::GetScreenHeight() {
	return nScreenHeight;
}

DWORD CALL HGE_Impl::GetScreenDeapth() {
	return nScreenBPP;
}
