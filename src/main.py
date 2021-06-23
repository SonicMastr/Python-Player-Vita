from ppv.graphics import RGBA
from ppv.graphics import vita2d
print("imported")

vita2d.init()
vita2d.set_vsync(0)
c = 960.0
while True:
    vita2d.begin()
    vita2d.rectangle(c,200.0,500.0,100.0, RGBA(0, 255, 255, 255)) # Cyan
    vita2d.circle(960.0/2, 544.0/2, 200.0, RGBA(255, 0, 255, 255)) # Magenta (Or Purple, IDK)
    vita2d.end()
    c = c - 2.5
    if c == -500.0:
        c = 960.0
