%module (moduleimport="import _SDL2") SDL2

#define DECLSPEC
#define SDLCALL
#define SDL_FORCE_INLINE
#define SDL_DEPRECATED

#define __VITA__
#define __vita__

%{
#include "SDL2/SDL.h"
#include "SDL2/SDL_main.h"
#include "SDL2/SDL_stdinc.h"
#include "SDL2/SDL_assert.h"
#include "SDL2/SDL_atomic.h"
#include "SDL2/SDL_audio.h"
#include "SDL2/SDL_clipboard.h"
#include "SDL2/SDL_cpuinfo.h"
#include "SDL2/SDL_endian.h"
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_filesystem.h"
#include "SDL2/SDL_gamecontroller.h"
#include "SDL2/SDL_haptic.h"
#include "SDL2/SDL_hints.h"
#include "SDL2/SDL_joystick.h"
#include "SDL2/SDL_loadso.h"
#include "SDL2/SDL_log.h"
#include "SDL2/SDL_messagebox.h"
#include "SDL2/SDL_metal.h"
#include "SDL2/SDL_mutex.h"
#include "SDL2/SDL_pixels.h"
#include "SDL2/SDL_power.h"
#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_rwops.h"
#include "SDL2/SDL_sensor.h"
#include "SDL2/SDL_shape.h"
#include "SDL2/SDL_system.h"
#include "SDL2/SDL_surface.h"
#include "SDL2/SDL_thread.h"
#include "SDL2/SDL_timer.h"
#include "SDL2/SDL_version.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_locale.h"
#include "SDL2/SDL_misc.h"
%}

%include <stdint.i>

%include "SDL2/SDL.h"
%include "SDL2/SDL_main.h"
%include "SDL2/SDL_stdinc.h"
%include "SDL2/SDL_assert.h"
%include "SDL2/SDL_atomic.h"
%include "SDL2/SDL_audio.h"
%include "SDL2/SDL_clipboard.h"
%include "SDL2/SDL_cpuinfo.h"
%include "SDL2/SDL_endian.h"
%include "SDL2/SDL_error.h"
%include "SDL2/SDL_events.h"
%include "SDL2/SDL_filesystem.h"
%include "SDL2/SDL_gamecontroller.h"
%include "SDL2/SDL_haptic.h"
%include "SDL2/SDL_hints.h"
%include "SDL2/SDL_joystick.h"
%include "SDL2/SDL_loadso.h"
%include "SDL2/SDL_log.h"
%include "SDL2/SDL_messagebox.h"
%include "SDL2/SDL_metal.h"
%include "SDL2/SDL_mutex.h"
%include "SDL2/SDL_pixels.h"
%include "SDL2/SDL_power.h"
%include "SDL2/SDL_rect.h"
%include "SDL2/SDL_render.h"
%include "SDL2/SDL_rwops.h"
%include "SDL2/SDL_sensor.h"
%include "SDL2/SDL_shape.h"
%include "SDL2/SDL_system.h"
%include "SDL2/SDL_surface.h"
%include "SDL2/SDL_thread.h"
%include "SDL2/SDL_timer.h"
%include "SDL2/SDL_version.h"
%include "SDL2/SDL_video.h"
%include "SDL2/SDL_locale.h"
%include "SDL2/SDL_misc.h"