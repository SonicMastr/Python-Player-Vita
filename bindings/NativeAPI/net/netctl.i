%module (moduleimport="import _netctl") netctl

%{
#include "psp2/net/netctl.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/net/netctl.h"