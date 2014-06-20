// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#ifndef STRICT
#define STRICT
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#endif

// Standard C++ Library includes
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <map>
#include <vector>
#include <exception>

// Standard C Library includes
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <memory>
//#include <assert.h>

// Other libs
#include <Windows.h>

// DirectX includes
#include <d3d11_2.h>
#include <d3dCompiler.h>

#ifdef _DEBUG
#define MGNEW new(_NORMAL_BLOCK,__FILE__, __LINE__)
#else
#define MGNEW new
#endif

#define SAFE_RELEASE( x ) {if(x){(x)->Release();(x)=nullptr;}}
#define SAFE_DELETE( x ) {if(x){delete (x);(x)=nullptr;}}
#define SAFE_DELETE_ARRAY( x ) {if(x){delete[] (x);(x)=nullptr;}}

// TODO: reference additional headers your program requires here
