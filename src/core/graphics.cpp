/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** Core functions implementation: graphics
*/


#include "hge_impl.h"
#include "soil/soil.h"
#ifdef WIN32
#include "SDL_opengl.h"
#else
#include "SDL_opengles.h"
#endif
SDL_Renderer* Renderer;


void CALL HGE_Impl::Gfx_Clear(DWORD color)
{
#ifdef WIN32
	if (bZBuffer){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor((float)GETR(color)/0xff, (float)GETG(color)/0xff, (float)GETB(color)/0xff, (float)GETA(color)/0xff);
		glClearDepth(1.0f);
	} else{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor((float)GETR(color)/0xff, (float)GETG(color)/0xff, (float)GETB(color)/0xff, (float)GETA(color)/0xff);
	}
#else
	if (bZBuffer){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor((float)GETR(color)/0xff, (float)GETG(color)/0xff, (float)GETB(color)/0xff, (float)GETA(color)/0xff);
		glClearDepthf(1.0f);
	} else{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor((float)GETR(color)/0xff, (float)GETG(color)/0xff, (float)GETB(color)/0xff, (float)GETA(color)/0xff);
	}
#endif
}

void CALL HGE_Impl::Gfx_SetClipping(int x, int y, int w, int h)
{
	int X, Y, Width, Height;
	float  MinZ, MaxZ;
	int scr_width, scr_height;
	if (!pCurTarget) {		
		scr_width = pHGE->GetScreenWidth();
		scr_height = pHGE->GetScreenHeight();
	}
	else {
		//scr_width = Image_GetWidth((HTEXTURE)pCurTarget->pTex);
		//scr_height = Image_GetHeight((HTEXTURE)pCurTarget->pTex);
		// TODO implements later
		scr_width = pHGE->GetScreenWidth();
		scr_height = pHGE->GetScreenHeight();
	}
	if (!w) {
		X = 0;
		Y = 0;
		Width = scr_width;
		Height = scr_height;
	}
	else {
		if (x < 0) {
			w += x;
			x = 0;
		}
		if (y < 0) {
			h += y;
			y = 0;
		}
		if (x + w > scr_width)
			w = scr_width - x;
		if (y + h > scr_height)
			h = scr_height - y;
		X = x;
		Y = y;
		Width = w;
		Height = h;
	}
	MinZ = -1.0f;
	MaxZ = 1.0f;
	_render_batch();

	// Convert from DirectX to OpenGl
	// TODO Checking when error appears
	glViewport(X, Y, Width, Height);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/*glScalef(1.0f, -1.0f, 1.0f);
	glTranslatef(-0.5f, +0.5f, 0.0f);*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
#ifdef WIN32
	glOrtho((float)X, (float)(X + Width), -((float)(Y + Height)), -((float)Y), MinZ, MaxZ); 
#else
	glOrthof((float)X, (float)(X + Width), -((float)(Y + Height)), -((float)Y), MinZ, MaxZ); 
#endif
}

void CALL HGE_Impl::Gfx_SetTransform(float x, float y, float dx, float dy, float rot, float hscale, float vscale)
{
	//TODO: insert code here
	// TODO checking for correct, implements later
	if (vscale == 0.0f){
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}else{
		glMatrixMode(GL_MODELVIEW);
		glTranslatef(-x, -y, 0.0f);
		glScalef(hscale, vscale, 1.0f);
		glRotatef(-rot, 0.0f, 0.0f, 1.0f);
		glTranslatef(x + dx, y + dy, 0.0f);
	}
	_render_batch();
}

bool CALL HGE_Impl::Gfx_BeginScene(HTARGET targ)
{
	int width	=	nScreenWidth;
	int height	=	nScreenHeight;
	pCurTarget	=	(CRenderTargetList*)targ;


//    glPolygonMode(GL_FRONT, GL_LINE);
	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_DITHER);
	glDisable(GL_FOG);
	glDisable(GL_LIGHTING);
#ifdef WIN32
	glDisable(GL_LOGIC_OP);
#endif
	glDisable(GL_STENCIL_TEST);
#ifdef WIN32
	glDisable(GL_TEXTURE_1D);
#endif
	glDisable(GL_TEXTURE_2D);
	glDepthMask(FALSE);
	

	//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	//if rendering to texture use texture width and height
	//if (pCurTarget)
	//{
	//	width	= pCurTarget->target->GetWidth();
	//	height	= pCurTarget->target->GetHeight();
	//}


	glViewport(0, 0, width, height);
	//TODO: insert code here
	glMatrixMode(GL_PROJECTION);
	
	//Clearing the projection matrix...
	glLoadIdentity();
	
	//Creating an orthoscopic view matrix going from -1 -> 1 in each
	//dimension on the screen (x, y, z). 
#ifdef WIN32
	glOrtho(0, width, height, 0, -1., 1.);
#else
	glOrthof(0, width, height, 0, -1., 1.);
#endif
	glMatrixMode(GL_MODELVIEW);
	//Clearing model view matrix
	glLoadIdentity();
	if (pCurTarget)
		pCurTarget->target->AttachToRender();	
	return true;
}

void CALL HGE_Impl::Gfx_EndScene()
{
//#ifdef  WIN32
	glFlush();
	if (pCurTarget)
	{
		pCurTarget->target->DetachFromRender();
	} 
	else
		System_SwapBuffers();	
	glBindTexture(GL_TEXTURE_2D, 0);
//#else
	//_render_batch(true);
	//SDL_RenderPresent(Renderer);
//#endif
}

void CALL HGE_Impl::Gfx_RenderLine(float x1, float y1, float x2, float y2, DWORD color, float z)
{
	//TODO: insert code here
	//TODO, we need display immediate
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	if (CurBlendMode != BLEND_DEFAULT)
		_SetBlendMode(BLEND_DEFAULT);
	int i = nPrim * HGEPRIM_LINES;
	GLfloat verteces[6] = {
		x1, y1, z, x2, y2, z
	};

	GLubyte colors[8] = {
		(GLubyte)GETR(color), (GLubyte)GETG(color), (GLubyte)GETB(color), (GLubyte)GETA(color),
		(GLubyte)GETR(color), (GLubyte)GETG(color), (GLubyte)GETB(color), (GLubyte)GETA(color)
	};
	glVertexPointer(3, GL_FLOAT, 0, verteces);
	glEnableClientState(GL_VERTEX_ARRAY);

	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
	glEnableClientState(GL_COLOR_ARRAY);

	glDrawArrays(GL_LINES, 0, 1);
	glDisable(GL_BLEND);
}

void CALL HGE_Impl::Gfx_RenderTriple(const hgeTriple *triple)
{
	//TODO: insert code here
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	if (CurPrimType != HGEPRIM_TRIPLES || nPrim >= VERTEX_BUFFER_SIZE || CurTexture != triple->tex || CurBlendMode != triple->blend) {
		_render_batch();
		CurPrimType = HGEPRIM_TRIPLES;
		if (CurBlendMode != triple->blend)
			_SetBlendMode(triple->blend);
		if (triple->tex != CurTexture) {
			glBindTexture(GL_TEXTURE_2D, triple->tex);
			CurTexture = triple->tex;
		}
	}
	int i = nPrim * HGEPRIM_LINES;

	// Vertex 1
	VertexArray[i].x = triple->v[0].x;
	VertexArray[i].y = triple->v[0].y;
	VertexArray[i].z = triple->v[0].z;
	TexArray[i].tx = triple->v[0].tx;
	TexArray[i].ty = triple->v[0].ty;
	ColorArray[i].A = (GLubyte)GETA(triple->v[0].col);
	ColorArray[i].B = (GLubyte)GETB(triple->v[0].col);
	ColorArray[i].G = (GLubyte)GETG(triple->v[0].col);
	ColorArray[i].R = (GLubyte)GETR(triple->v[0].col);

	// Vertex2
	VertexArray[i+1].x = triple->v[1].x;
	VertexArray[i+1].y = triple->v[1].y;
	VertexArray[i+1].z = triple->v[1].z;
	TexArray[i+1].tx = triple->v[1].tx;
	TexArray[i+1].ty = triple->v[1].ty;
	ColorArray[i+1].A = (GLubyte)GETA(triple->v[0].col);
	ColorArray[i+1].B = (GLubyte)GETB(triple->v[0].col);
	ColorArray[i+1].G = (GLubyte)GETG(triple->v[0].col);
	ColorArray[i+1].R = (GLubyte)GETR(triple->v[0].col);

	// Vertex 3
	VertexArray[i+2].x = triple->v[2].x;
	VertexArray[i+2].y = triple->v[2].y;
	VertexArray[i+2].z = triple->v[2].z;
	TexArray[i+2].tx = triple->v[2].tx;
	TexArray[i+2].ty = triple->v[2].ty;
	ColorArray[i+2].A = (GLubyte)GETA(triple->v[0].col);
	ColorArray[i+2].B = (GLubyte)GETB(triple->v[0].col);
	ColorArray[i+2].G = (GLubyte)GETG(triple->v[0].col);
	ColorArray[i+2].R = (GLubyte)GETR(triple->v[0].col);

	nPrim++;
}

void CALL HGE_Impl::Gfx_RenderQuad(const hgeQuad *quad)
{

	//_render_batch();
	CurPrimType = HGEPRIM_QUADS;
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	//if (CurBlendMode != quad->blend)
	_SetBlendMode(quad->blend);
	glBindTexture(GL_TEXTURE_2D, quad->tex);
	CurTexture = quad->tex;

	GLfloat verteces[12] = {
		quad->v[1].x, quad->v[1].y, quad->v[1].z,
		quad->v[0].x, quad->v[0].y, quad->v[0].z,
		quad->v[3].x, quad->v[3].y, quad->v[3].z,
		quad->v[2].x, quad->v[2].y, quad->v[2].z,
	};

	GLfloat texCoords[8] = {
		quad->v[1].tx, quad->v[1].ty,
		quad->v[0].tx, quad->v[0].ty,
		quad->v[3].tx, quad->v[3].ty,
		quad->v[2].tx, quad->v[2].ty,
	};
	GLubyte colors[16] = {
		(GLubyte)GETR(quad->v[1].col), (GLubyte)GETG(quad->v[1].col), (GLubyte)GETB(quad->v[1].col), (GLubyte)GETA(quad->v[1].col),
		(GLubyte)GETR(quad->v[0].col), (GLubyte)GETG(quad->v[0].col), (GLubyte)GETB(quad->v[0].col), (GLubyte)GETA(quad->v[0].col),
		(GLubyte)GETR(quad->v[3].col), (GLubyte)GETG(quad->v[3].col), (GLubyte)GETB(quad->v[3].col), (GLubyte)GETA(quad->v[3].col),
		(GLubyte)GETR(quad->v[2].col), (GLubyte)GETG(quad->v[2].col), (GLubyte)GETB(quad->v[2].col), (GLubyte)GETA(quad->v[2].col),
	};

	glVertexPointer(3, GL_FLOAT, 0, verteces);
	glEnableClientState(GL_VERTEX_ARRAY);

	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);


	glColorPointer(4, GL_UNSIGNED_BYTE, 0, colors);
	glEnableClientState(GL_COLOR_ARRAY);

	GLubyte indices[] = {0,1,2, // first triangle (bottom left - top left - top right)
		0,2,3}; // second triangle (bottom left - top right - bottom right)

	//TODO With opengles we need other function
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	//glDrawArrays(GL_QUADS, 0, 4);
	glDisable(GL_TEXTURE_2D); // Enable Texture Mapping
	//glDisable(GL_BLEND); // Enable Texture Mapping


}

hgeVertex* CALL HGE_Impl::Gfx_StartBatch(int prim_type, HTEXTURE tex, int blend, int *max_prim)
{
	//TODO: insert code here
	_render_batch();
	glEnable(GL_TEXTURE_2D);
	if (CurBlendMode != blend){
		_SetBlendMode(blend);
	}
	if (tex != CurTexture) {
		glBindTexture(GL_TEXTURE_2D, tex);
		CurTexture = tex;
	}
	*max_prim = VERTEX_BUFFER_SIZE / prim_type; // get maximum primitive 
	return 0;
}

void CALL HGE_Impl::Gfx_FinishBatch(int nprim)
{
	//TODO: insert code here
	nPrim = nprim;
}

HTARGET CALL HGE_Impl::Target_Create(int width, int height, bool zbuffer)
{
	CRenderTargetList *pTarget;
	
	pTarget = new CRenderTargetList;
	pTarget->target = CGfxTarget::CreateTarget(width, height, zbuffer);

	if (!(pTarget->target))
	{
		delete pTarget;
		return 0;
	}

	pTarget->next=pTargets;
	pTargets=pTarget;

	return (HTARGET)pTarget;
	
}

void CALL HGE_Impl::Target_Free(HTARGET target)
{
	CRenderTargetList *pTarget=pTargets, *pPrevTarget=NULL;

	while(pTarget)
	{
		if((CRenderTargetList *)target == pTarget)
		{
			if(pPrevTarget)
				pPrevTarget->next = pTarget->next;
			else
				pTargets = pTarget->next;

			if(pTarget->target) 
			{
				delete (pTarget->target);
			}

			delete pTarget;
			return;
		}

		pPrevTarget = pTarget;
		pTarget = pTarget->next;
	}
	

}

HTEXTURE CALL HGE_Impl::Target_GetTexture(HTARGET target_)
{
	CRenderTargetList *targ=(CRenderTargetList *)target_;
	if(target_) return targ->target->GetTexture();
	else return 0;

	return 0;
}

HTEXTURE CALL HGE_Impl::Texture_Create(int width, int height)
{
	//TODO: insert code here
	GLuint texture;
	glGenTextures(1, &texture);
	return texture;
}

HTEXTURE CALL HGE_Impl::Texture_Load(const char *filename, DWORD size, bool bMipmap)
{
	void *data;
	DWORD _size;
	HTEXTURE pTex;
	CTextureList *texItem;
	int w, h, channels;

	if(size)
	{ 
		data=(void *)filename; _size=size; 
	}
	else
	{
		data=pHGE->Resource_Load(filename, &_size);
		if(!data) return NULL;
	}

	
	pTex = SOIL_load_OGL_texture_and_info_from_memory(
								(const unsigned char* const)data,
								_size, 
								SOIL_LOAD_AUTO,
								SOIL_CREATE_NEW_ID,
								(bMipmap ? SOIL_FLAG_MIPMAPS : 0) 
								| SOIL_FLAG_POWER_OF_TWO | SOIL_FLAG_TEXTURE_REPEATS,
								&w, &h, &channels);
	
	if (0 == pTex)	
	{
		_PostError("Can't create texture");
		if(!size) Resource_Free(data);
		return NULL;
	}

	if(!size) Resource_Free(data);
	
	texItem=new CTextureList;
	texItem->tex=(HTEXTURE)pTex;
	texItem->w = w;
	texItem->h = h;
	texItem->next=textures;
	textures=texItem;
	
	return (HTEXTURE)pTex;
}

void CALL HGE_Impl::Texture_Free(HTEXTURE tex)
{
	CTextureList *texItem=textures, *texPrev=0;

	while(texItem)
	{
		if(texItem->tex==tex)
		{
			if(texPrev) texPrev->next=texItem->next;
			else textures=texItem->next;
			delete texItem;
			break;
		}
		texPrev=texItem;
		texItem=texItem->next;
	}
	glDeleteTextures(1, (const GLuint*)&tex);
}

int CALL HGE_Impl::Texture_GetWidth(HTEXTURE tex, bool bOriginal)
{
#ifdef WIN32
	GLint w; 
	glBindTexture(GL_TEXTURE_2D, tex);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &w);
	glBindTexture(GL_TEXTURE_2D, 0);
	return w;
#else
	//Tu.NguyenHoang
	CTextureList *texItem=textures;
	while(texItem)
	{
		if (texItem->tex==tex)
		{
			return texItem->w;
		}
		texItem=texItem->next;
	}
	return 128;
#endif
}


int CALL HGE_Impl::Texture_GetHeight(HTEXTURE tex, bool bOriginal)
{
#ifdef WIN32
	GLint h; 
	glBindTexture(GL_TEXTURE_2D, tex);
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &h);
	glBindTexture(GL_TEXTURE_2D, 0);
	return h;
#else
	//Tu.NguyenHoang
	CTextureList *texItem=textures;
	while(texItem)
	{
		if (texItem->tex==tex)
		{
			return texItem->h;
		}
		texItem=texItem->next;
	}
	return 128;
#endif
}

DWORD * CALL HGE_Impl::Texture_Lock(HTEXTURE tex, bool bReadOnly, int left, int top, int width, int height)
{
	//TODO:
	/*GLvoid *image;
	CTextureList *texItem=textures;
	GLint fmt;

	while(texItem && (texItem->tex!=tex))
	{
		texItem=texItem->next;
	}
	
	if (!texItem)
		return 0;
	
	RECT region;
	int flags;


	if(!width || !height)
	{
	  return 0;
	}
	
	glBindTexture(GL_TEXTURE_2D, tex);


	glGetTexLevelParameter(GL_TEXTURE_2D, 0, GL_TEXTURE_INTERNAL_FORMAT, &fmt);

	if (fmt != GL_RGB/// A) return 0;

	glGetTexImage(GL_TEXTURE_2D, /// 0, GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, image);

	if(FAILED(pTex->LockRect(0, &TRect, prec, flags)))
	{
		_PostError("Can't lock texture");
		return 0;
	}

	return (DWORD *)image;
	/// */
	return 0;

}


void CALL HGE_Impl::Texture_Unlock(HTEXTURE tex)
{
	//TODO: insert code here
}

//////// Implementation ////////

void HGE_Impl::_render_batch(bool bEndScene)
{
	//TODO: insert code here
}

void HGE_Impl::_SetBlendMode(int blend)
{

	glDisable(GL_ALPHA_TEST);
	glEnable(GL_BLEND); // Enable Blending


	if((blend & BLEND_ALPHABLEND) != (CurBlendMode & BLEND_ALPHABLEND))
	{
		if(blend & BLEND_ALPHABLEND) 
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	//Alpha blending
		else 
			glBlendFunc(GL_SRC_ALPHA, GL_ONE); //Addictive	
	}

    if((blend & BLEND_ZWRITE) != (CurBlendMode & BLEND_ZWRITE))
	{
		if(blend & BLEND_ZWRITE) glDepthMask(GL_TRUE);
		else glDepthMask(GL_FALSE);
	}	
	
	if((blend & BLEND_COLORADD) != (CurBlendMode & BLEND_COLORADD))
	{
		if(blend & BLEND_COLORADD) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_ADD); 
		else glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
	}
	
	CurBlendMode = blend;
}

void HGE_Impl::_SetProjectionMatrix(int width, int height)
{
	//TODO: insert code here

	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION);
	
	//Clearing the projection matrix...
	glLoadIdentity();
	
	//Creating an orthoscopic view matrix going from -1 -> 1 in each
	//dimension on the screen (x, y, z). 
#ifdef WIN32
	glOrtho(0, nScreenWidth, nScreenHeight, 0, -1., 1.);
#else
	glOrthof(0, nScreenWidth, nScreenHeight, 0, -1., 1.);
#endif

}




void HGE_Impl::_Resize(int width, int height)
{
	//TODO: insert code here
}

void HGE_Impl::_GfxDone()
{
	//TODO: insert code here
	while (textures)
		Texture_Free(textures->tex);
	if (VertexArray)
		delete VertexArray;
	if (ColorArray)
		delete ColorArray;
	if (TexArray)
		delete TexArray;
	VertexArray = 0;
	ColorArray = 0;
	TexArray = 0;
}


bool HGE_Impl::_GfxRestore()
{
	//TODO: insert code here
	return _init_lost();	
}


bool HGE_Impl::_init_lost()
{
	CRenderTargetList *target=pTargets;

	// Store render target


	// Set common render states

	//pD3DDevice->SetRenderState( D3DRS_LASTPIXEL, FALSE );
	//	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);


	nPrim=0;
	CurPrimType=HGEPRIM_QUADS;
	CurBlendMode = BLEND_DEFAULT;
	CurTexture = NULL;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Enable Alpha Blending (disable alpha testing)
	glEnable(GL_BLEND);	

	return true;
}


bool HGE_Impl::_GfxInit()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_AUDIO)){
		printf("Could not initialize SDL");
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#ifdef WIN32
	int flags = SDL_OPENGL | SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN;
	SDL_SetVideoMode(nScreenWidth, nScreenHeight, 32, flags);
#else
	SDL_WindowID window;
	window = SDL_CreateWindow(NULL, 0, 0, nScreenWidth, nScreenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
	Renderer = SDL_CreateRenderer(window, 0, 0);
#endif
	glShadeModel(GL_SMOOTH);						// Enables Smooth Shading
	_SetProjectionMatrix(nScreenWidth, nScreenHeight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);      // 4-byte pixel alignment
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearStencil(0);                          // clear stencil buffer
#ifdef WIN32
	glClearDepth(1.0f);								// Depth Buffer Setup
#else
	glClearDepthf(1.0f);								// Depth Buffer Setup
#endif
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	//??    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	glDepthFunc(GL_LEQUAL);							// The Type Of Depth Test To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);			// Really Nice Perspective Calculations
	textures = 0;
	VertexArray = 0;
	ColorArray = 0;
	TexArray = 0;
	if(!_init_lost()) return false;
	Gfx_Clear(0);
	return true;
}


