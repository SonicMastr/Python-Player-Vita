%module (moduleimport="import _touch") touch

%{
#include "psp2/touch.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/touch.h"