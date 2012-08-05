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


bool CALL HGE_Impl::System_Initiate()
{
	// Init subsystems

	return false;
}

void CALL HGE_Impl::System_Shutdown()
{
	System_Log("\nFinishing..");

	System_Log("The End.");
}


bool CALL HGE_Impl::System_Start()
{
  //todo:
	return false;
}

void CALL HGE_Impl::System_SwapBuffers()
{
//todo:
}

void CALL HGE_Impl::System_SetStateBool(hgeBoolState state, bool value)
{
//todo:
}

void CALL HGE_Impl::System_SetStateFunc(hgeFuncState state, hgeCallback value)
{
//todo:
}

void CALL HGE_Impl::System_SetStateHwnd(hgeHwndState state, HWND value)
{
//todo:
}

void CALL HGE_Impl::System_SetStateInt(hgeIntState state, int value)
{
//todo:
}

void CALL HGE_Impl::System_SetStateString(hgeStringState state, const char *value)
{
//todo:
}

bool CALL HGE_Impl::System_GetStateBool(hgeBoolState state)
{
//todo:

	return false;
}

hgeCallback CALL HGE_Impl::System_GetStateFunc(hgeFuncState state)
{
//todo:

	return NULL;
}

HWND CALL HGE_Impl::System_GetStateHwnd(hgeHwndState state)
{
//todo:

	return 0;
}

int CALL HGE_Impl::System_GetStateInt(hgeIntState state)
{
//todo:

	return 0;
}

const char* CALL HGE_Impl::System_GetStateString(hgeStringState state) {
//todo:

	return NULL;
}

char* CALL HGE_Impl::System_GetErrorMessage()
{
	return szError;
}

void CALL HGE_Impl::System_Log(const char *szFormat, ...)
{
//todo:
}

bool CALL HGE_Impl::System_Launch(const char *url)
{
//todo:
return false;
}

void CALL HGE_Impl::System_Snapshot(const char *filename)
{
	//TODO: insert code here
}

//////// Implementation ////////


HGE_Impl::HGE_Impl()
{

}

void HGE_Impl::_PostError(char *error)
{
	System_Log(error);
	strcpy(szError,error);
}

void HGE_Impl::_FocusChange(bool bAct)
{
}


void HGE_Impl::_AdjustWindow()
{
}

