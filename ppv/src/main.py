import ppv_graphics
print("imported")

ppv_graphics.init()
while True:
    ppv_graphics.begin()
    ppv_graphics.rectangle(0,0,200,200) # Default Color is Red for now. Need to create a decimal to hex (RGBA) color converter
    ppv_graphics.end()
