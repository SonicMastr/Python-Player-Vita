%module (moduleimport="import _threadmgr") threadmgr

%{
#include "psp2/kernel/threadmgr.h"
%}

%include "vitasdk/build_utils.h"
%include "psp2/kernel/threadmgr.h"