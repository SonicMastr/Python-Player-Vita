%module (moduleimport="import _modulemgr") modulemgr

%{
#include "psp2/kernel/modulemgr.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/kernel/modulemgr.h"