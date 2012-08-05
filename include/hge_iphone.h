/*
** Haaf's Game Engine 1.8
** Copyright (C) 2009, Alexander Katasonov
**
*/


#ifndef HGE_IPHONE_H
#define HGE_IPHONE_H

typedef void *HANDLE; 
typedef HANDLE HMENU; 
typedef HANDLE HWND;

#define WinMain(hInstance, hPrevInstance, lpCmdLine, nCmdShow)															\
AppMain();																									\
																											\
@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate>		\
{																											\
}																											\
@end \
\
@implementation AppController \
int AppMain();	\
- (void) applicationDidFinishLaunching:(UIApplication*)application \
{ \
	AppMain(); \
} \
\
-(void) applicationWillResignActive:(UIApplication *)application \
{ \
} \
\
-(void) applicationDidBecomeActive:(UIApplication *)application \
{ \
\
} \
\
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application { \
 \
} \
\
@end \
\
int AppMain() 


#endif

