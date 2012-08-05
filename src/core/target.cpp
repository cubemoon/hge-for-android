/*
** HGEPort 0.1
** Copyright (C) 2009, Alexander Katasonov
**
*/


#include "target.h"
#ifdef WIN32
PFNGLGENFRAMEBUFFERSEXTPROC glGenFramebuffersEXT;
PFNGLBINDFRAMEBUFFEREXTPROC glBindFramebufferEXT;
PFNGLFRAMEBUFFERTEXTURE2DEXTPROC glFramebufferTexture2DEXT;
PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteFramebuffersEXT;
PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC glCheckFramebufferStatusEXT;
PFNGLRENDERBUFFERSTORAGEEXTPROC glRenderbufferStorageEXT;

PFNGLGENRENDERBUFFERSEXTPROC glGenRenderbuffersEXT;
PFNGLBINDFRAMEBUFFEREXTPROC glBindRenderbufferEXT;
PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC glFramebufferRenderbufferEXT;
PFNGLDELETEFRAMEBUFFERSEXTPROC glDeleteRenderbuffersEXT;
#endif

class CGfxTargetFrameBufferOG : public CGfxTarget
{
	DWORD			frameBuffer;
	DWORD			depthBuffer;

public:
				CGfxTargetFrameBufferOG(DWORD w, DWORD h, bool zbuffer);
	virtual		~CGfxTargetFrameBufferOG();

	virtual void	AttachToRender();
	virtual void	DetachFromRender();

};



CGfxTargetFrameBufferOG::CGfxTargetFrameBufferOG(DWORD w_, DWORD h_, bool zbuffer_)
	: CGfxTarget(w_, h_, zbuffer_)
{
	long gl_error;
#ifdef WIN32
	glGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC)SDL_GL_GetProcAddress("glGenFramebuffersEXT");
	glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)SDL_GL_GetProcAddress("glBindFramebufferEXT");
	glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)SDL_GL_GetProcAddress("glFramebufferTexture2DEXT");
	glDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC)SDL_GL_GetProcAddress("glDeleteFramebuffersEXT");
	glCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)SDL_GL_GetProcAddress("glCheckFramebufferStatusEXT");
	glRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC)SDL_GL_GetProcAddress("glRenderbufferStorageEXT");


	glGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC)SDL_GL_GetProcAddress("glGenRenderbuffersEXT");
	glBindRenderbufferEXT= (PFNGLBINDFRAMEBUFFEREXTPROC)SDL_GL_GetProcAddress("glBindRenderbufferEXT");
	glFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)SDL_GL_GetProcAddress("glFramebufferRenderbufferEXT");
	glDeleteRenderbuffersEXT= (PFNGLDELETEFRAMEBUFFERSEXTPROC)SDL_GL_GetProcAddress("glDeleteRenderbuffersEXT");
#endif
	frameBuffer = 0;
	depthBuffer = 0;


	/*if (!GLEW_EXT_framebuffer_object)
	{
		throw 1;
	}*/


	
	glEnable(GL_TEXTURE_2D);

	glGenTextures(1, (unsigned int*)(&texture));					// Create 1 Texture
	glBindTexture(GL_TEXTURE_2D, texture);			// Bind The Texture
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE); // automatic mipmap generation included in OpenGL v1.4
#ifdef WIN32
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
#else
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
#endif
	glBindTexture(GL_TEXTURE_2D, 0);			// Bind The Texture

	/*if (GL_ERROR(gl_error))
	{
		throw 1;
	}*/
	
	glDisable(GL_TEXTURE_2D);

   // create framebuffer
#ifdef WIN32
	glGenFramebuffersEXT(1, (unsigned int*)(&frameBuffer));
	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);
#else
	glGenFramebuffersOES(1, (unsigned int*)(&frameBuffer));
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, frameBuffer);
#endif

	//create render buffer
	if (zbuffer)
	{
#ifdef WIN32
		glGenRenderbuffersEXT(1, (unsigned int*)(&depthBuffer));
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, depthBuffer);
		glRenderbufferStorageEXT(GL_RENDERBUFFER_EXT, GL_DEPTH_COMPONENT, width, height);
		glBindRenderbufferEXT(GL_RENDERBUFFER_EXT, 0);
#else
		glGenRenderbuffersOES(1, (unsigned int*)(&depthBuffer));
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, depthBuffer);
		glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, width, height);
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, 0);
#endif
	}
#ifdef WIN32
	// attach texture
	glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, texture, 0);
	// Attach to the FBO for depth
	glFramebufferRenderbufferEXT(GL_FRAMEBUFFER_EXT, GL_DEPTH_ATTACHMENT_EXT, GL_RENDERBUFFER_EXT, depthBuffer); 

	glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
#else
	// attach texture
	glFramebufferTexture2DOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, texture, 0);
	// Attach to the FBO for depth
	glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, depthBuffer); 

	glBindFramebufferOES(GL_FRAMEBUFFER_OES, 0);
#endif
	if (!texture || !frameBuffer)
		throw 1;
}

CGfxTargetFrameBufferOG::~CGfxTargetFrameBufferOG()
{
	if (texture)
		glDeleteTextures(1, (unsigned int*)(&texture));
	
	if (frameBuffer)
	{
#ifdef WIN32
		glDeleteFramebuffersEXT(1, (unsigned int*)(&frameBuffer));
#else
		glDeleteFramebuffersOES(1, (unsigned int*)(&frameBuffer));
#endif
	}
	
	if (depthBuffer)
	{
#ifdef WIN32
		glDeleteRenderbuffersEXT(1, (unsigned int*)(&depthBuffer));
#else
		glDeleteRenderbuffersOES(1, (unsigned int*)(&depthBuffer));
#endif
	}
}

void CGfxTargetFrameBufferOG::AttachToRender()
{
	// set the rendering destination to FBO
#ifdef WIN32
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, frameBuffer);
#else
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, frameBuffer);
#endif
}

void CGfxTargetFrameBufferOG::DetachFromRender()
{
#ifdef WIN32
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
#else
	glBindFramebufferOES(GL_FRAMEBUFFER_OES, 0);
#endif
}



CGfxTarget* CGfxTarget::CreateTarget(int w, int h, bool zbuffer)
{
	try {
		return (CGfxTarget*)(new CGfxTargetFrameBufferOG(w, h, zbuffer));
	}
	catch(...)
	{
		return 0;
	}

}
