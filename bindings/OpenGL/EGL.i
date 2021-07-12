%module (moduleimport="import _EGL") EGL

#define __vita__ 1
#define EGL_EGL_PROTOTYPES 0

%{
#include "psp2/gxm.h"
#include "psp2/display.h"
#include "KHR/khrplatform.h"
#include "EGL/eglplatform.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"
%}

%include "KHR/khrplatform.h"
%include "EGL/eglplatform.h"
%include "EGL/egl.h"
%include "EGL/eglext.h"