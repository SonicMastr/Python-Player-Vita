%module (moduleimport="import _audiodec") audiodec

%{
#include "psp2/audiodec.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/audiodec.h"