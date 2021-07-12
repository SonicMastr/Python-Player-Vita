%module (moduleimport="import _SDL2_ttf") SDL2_ttf

#define DECLSPEC
#define SDLCALL
#define SDL_DEPRECATED

#define __VITA__
#define __vita__

%{
#include "SDL2/SDL_ttf.h"
%}

%include "SDL2/SDL_ttf.h"
%import "SDL2.i"