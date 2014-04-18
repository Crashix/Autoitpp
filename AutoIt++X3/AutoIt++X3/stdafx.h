// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <Psapi.h>

//for imagesearch : 

#include <olectl.h> // for OleLoadPicture()
#include <Gdiplus.h> // Used by LoadPicture().
#include <windef.h>
#include <winuser.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <shellapi.h>
#include <string>
#include <vector>
#define DESKTOP_WIDTH GetSystemMetrics(SM_CXSCREEN)
#define DESKTOP_HEIGHT GetSystemMetrics(SM_CYSCREEN)


// TODO: reference additional headers your program requires here
