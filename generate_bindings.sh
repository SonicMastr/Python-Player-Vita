# Clean this up just in case.
find bindings -type f -name '*.c' -delete
find bindings -type f \! -name '__init__.py' -name '*.py' -delete
find bindings -type f -name "*.i" -print -exec swig -python -castmode -threads -fastdispatch -I$VITASDK/arm-vita-eabi/include -doxygen {} \;
mkdir lib
find bindings -name '*.py' -exec cp --parents \{\} lib \;