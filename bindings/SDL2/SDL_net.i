%module (moduleimport="import _SDL2_net") SDL2_net

#define DECLSPEC
#define SDLCALL
#define SDL_FORCE_INLINE
#define SDL_DEPRECATED

#define __VITA__
#define __vita__

%{
#include "SDL2/SDL_net.h"
%}

%include "SDL2/SDL_net.h"
%import "SDL2.i"