from NativeAPI.ctrl import *
from vita2d import *

vita2d_init()
vita2d_set_vblank_wait(1)
image = vita2d_load_PNG_file("app0:png.png") # Set Image Object
font = vita2d_load_default_pgf() # Set Font Object
sceCtrlSetSamplingMode(SCE_CTRL_MODE_DIGITAL)

ctrl = SceCtrlData() # Set Control Data Object

def RGBA(r, g, b, a):
    return (a<<24|b<<16|g<<8|r);

c = 960.0
while True:
    vita2d_start_drawing()
    vita2d_clear_screen()

    sceCtrlPeekBufferPositive(0, ctrl, 1) # Poll Input

    if (SCE_CTRL_CROSS & ctrl.buttons):
        vita2d_draw_rectangle(c,200.0,500.0,100.0, RGBA(255, 0, 0, 255)) # Red
        vita2d_pgf_draw_text(font, 0, 100, RGBA(0, 255, 0, 255), 1.0, "Pressing Cross!")
    else:
        vita2d_draw_rectangle(c,200.0,500.0,100.0, RGBA(0, 255, 255, 255)) # Cyan
        vita2d_pgf_draw_text(font, 0, 100, RGBA(255, 255, 255, 255), 1.0, "Not Pressing Cross")

    vita2d_draw_fill_circle(960.0/2, 544.0/2, 200.0, RGBA(255, 0, 255, 255)) # Magenta (Or Purple, IDK)
    vita2d_draw_texture_scale(image, 940.0/2, 544.0/2, 0.8, 0.8)
    vita2d_end_drawing()
    vita2d_swap_buffers()
    c = c - 2.5
    if c == -500.0:
        c = 960.0
