%module (moduleimport="import _SDL2_mixer") SDL2_mixer

#define DECLSPEC
#define SDLCALL
#define SDL_FORCE_INLINE
#define SDL_DEPRECATED

#define __VITA__
#define __vita__

%{
#include "SDL2/SDL_mixer.h"
%}

%ignore Mix_HasMusicDecoder;

%include "SDL2/SDL_mixer.h"
%import "SDL2.i"