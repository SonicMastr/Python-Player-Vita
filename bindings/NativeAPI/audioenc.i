%module (moduleimport="import _audioenc") audioenc

%{
#include "psp2/audioenc.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/audioenc.h"