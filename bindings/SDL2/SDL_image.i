%module (moduleimport="import _SDL2_image") SDL2_image

#define DECLSPEC
#define SDLCALL
#define SDL_FORCE_INLINE
#define SDL_DEPRECATED

#define __VITA__
#define __vita__

%{
#include "SDL2/SDL_image.h"
%}

%include "SDL2/SDL_image.h"
%import "SDL2.i"