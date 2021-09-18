# Python-Player-Vita (Name to be changed)

Create applications for the PSVita using Python to interface with Native PSVita libraries.

Use the included libraries or even extend the application with your own. The application will automatically run `main.py`


## Build Instructions
- Install VitaSDK
- Install Pigs in a Blanket (For now, due to a bug with VDPM)
- `sh generate_bindings.sh`
- `cmake . build`
- `cd build`
- `make -j4` or `ninja -j 4` depending on generator
