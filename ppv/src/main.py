import ppv_graphics
print("imported")

ppv_graphics.init()
c = 960.0
while True:
    ppv_graphics.begin()
    ppv_graphics.rectangle(c,200.0,500.0,100.0)
    ppv_graphics.end()
    c = c - 2.5
    if c == -500.0:
	c = 960.0
