# Clean this up just in case.
find bindings -type f -name '*.c' -delete
find bindings -type f \! -name '__init__.py' -name '*.py' -delete
# Have to do this twice to fix SDL2 Doxygen parsing errors at the moment. Waiting for that to get fixed
find bindings -type f -name "*.i" -print -exec swig -python -castmode -threads -fastdispatch -I$VITASDK/arm-vita-eabi/include {} \;
find bindings -type f -name "*.i" -print -exec swig -python -castmode -threads -fastdispatch -I$VITASDK/arm-vita-eabi/include -doxygen {} \;
mkdir lib
find bindings -name '*.py' -exec cp --parents \{\} lib \;