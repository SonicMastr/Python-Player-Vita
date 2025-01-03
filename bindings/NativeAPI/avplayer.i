%module (moduleimport="import _avplayer") avplayer

%{
#include "psp2/avplayer.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/avplayer.h"