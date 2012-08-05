/*
** HGEPort 0.1
** Copyright (C) 2009 Alexander Katasonov
**
*/


#ifndef HGE_TARGET_H
#define HGE_TARGET_H


#include "../../include/hge.h"

class CGfxTarget
{
public:
	
	static CGfxTarget* CreateTarget(int w, int h, bool zbuffer);

public:

	CGfxTarget(DWORD w_, DWORD h_, bool zbuffer_)
	: width(w_), height(h_), zbuffer(zbuffer_)
	{
	}

	virtual ~CGfxTarget(){};


	virtual void		AttachToRender() = 0;
	virtual void		DetachFromRender() = 0;

	virtual int			GetWidth()			{return width;}
	virtual int			GetHeight()			{return height;}
	virtual bool		ZBufferEnabled()	{return zbuffer;}
	virtual HTEXTURE	GetTexture()		{return texture;};

public:
	int		        width;
	int		        height;
	HTEXTURE		texture;
	bool			zbuffer;
};



#endif

