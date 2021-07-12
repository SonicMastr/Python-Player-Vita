%module (moduleimport="import _GLES2") GLES2

#define __vita__ 1

%{
#include "GLES2/gl2.h"
#include "KHR/khrplatform.h"
%}

%include "KHR/khrplatform.h"
%include "GLES2/gl2platform.h"
%include "GLES2/gl2.h"
%include "GLES2/gl2ext.h"