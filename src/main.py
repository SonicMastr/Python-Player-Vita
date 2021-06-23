import ppv
from ppv.graphics import RGBA
print("imported")

ppv.graphics.vita2d.init()
c = 960.0
while True:
    ppv.graphics.vita2d.begin()
    ppv.graphics.vita2d.rectangle(c,200.0,500.0,100.0, RGBA(0, 255, 255, 255)) # Cyan
    ppv.graphics.vita2d.circle(960.0/2, 544.0/2, 200.0, RGBA(255, 0, 255, 255)) # Magenta (Or Purple, IDK)
    ppv.graphics.vita2d.end()
    c = c - 2.5
    if c == -500.0:
        c = 960.0
