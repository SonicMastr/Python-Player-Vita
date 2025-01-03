%module (moduleimport="import _audioout") audioout

%{
#include "psp2/audioout.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/audioout.h"