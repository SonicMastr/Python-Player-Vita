cmake_minimum_required(VERSION 3.0)

set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "VITASDK toolchain file")
set(VITASDK_CMAKE_FILE "$ENV{VITASDK}/share/vita.cmake" CACHE PATH "VITASDK CMake functions file")
include("${VITASDK_CMAKE_FILE}" REQUIRED)

project(ppv)

add_compile_options(
  -O3
  -Wall -Wextra -Wdouble-promotion -Wshadow -Wundef
  -fsingle-precision-constant -fno-common
)

include_directories(
    "include"
    "$ENV{VITASDK}/arm-vita-eabi/include/python2.7"
)

# Build self

set(ELF "ppv.elf")
set(SELF "ppv.self")

find_package(OpenSSL REQUIRED)

file(GLOB_RECURSE bindings_c
  bindings/*.c
)

file(GLOB_RECURSE bindings_py
  bindings/*.py
)

add_executable("${ELF}"
  ${bindings_c}
  src/main.c
)

target_link_libraries("${ELF}"
  python2.7
  SceAudioenc_stub
  SceAudiodec_stub
  SceAudioIn_stub
  SceAvPlayer_stub
  SceCamera_stub
  ScePower_stub
  SceNet_stub
  SceNetCtl_stub
  ScePspnetAdhoc_stub
  SceSsl_stub
  SceSysmodule_stub
  vita2d
  pib
  libScePiglet_stub
  SceShaccCg_stub
  taihen_stub
  SceAppMgr_stub
  SceAppUtil_stub
  ScePgf_stub 
  ScePvf_stub
  ${OPENSSL_LIBRARIES}
  SDL2_image
  SDL2_mixer
  SDL2_ttf
  SDL2_net
  SDL2_gfx
  SDL2
  SDL2main
  vorbisfile
  vorbis
  ogg
  mpg123
  FLAC
  mikmod
  opus
  freetype
  jpeg
  png
  webp
  SceMotion_stub
  SceCommonDialog_stub
  SceHid_stub
  SceGxm_stub
  SceAudio_stub
  ScePower_stub
  SceDisplay_stub
  SceCtrl_stub
  SceTouch_stub
  SceIofilemgr_stub
  SceSsl_stub
  SceSysmodule_stub
  pthread
  ${SDL2_LIBRARIES}
  gcc
  z
  m
)

vita_create_self("${SELF}"
  "${ELF}"
  UNSAFE
  COMPRESS
)

# Build VPK

set(VPK "ppv.vpk")
set(TITLE_NAME "Python Player")
set(TITLE_ID "PPVA00001")
set(TITLE_VER "01.00")

vita_create_vpk("${VPK}" "${TITLE_ID}" "${SELF}"
  NAME "${TITLE_NAME}"
  VERSION "${TITLE_VER}"
  FILE "$ENV{VITASDK}/arm-vita-eabi/lib/python27.zip" lib/python27.zip
  FILE lib/bindings lib/python2.7
  FILE src/main.py main.py
  FILE png.png png.png
)