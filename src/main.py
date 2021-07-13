from SDL2.SDL2 import *
from SDL2.SDL2_image import *

def draw():
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255)
    SDL_RenderClear(renderer)
    dstrect = SDL_Rect()
    dstrect.x = 250
    dstrect.y = 30
    dstrect.w = imageWidth
    dstrect.h = imageHeight
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255)
    SDL_RenderFillRect(renderer, dstrect)
    SDL_RenderCopy(renderer, imageTexture, None, dstrect)
    SDL_RenderPresent(renderer)

def main():
    global window
    global renderer
    global imageTexture
    global imageWidth
    global imageHeight

    print(type(SDL_INIT_VIDEO)) 

    SDL_Init(SDL_INIT_VIDEO)
    IMG_Init(IMG_INIT_PNG)

    window = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 544, SDL_WINDOW_SHOWN)

    SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1")

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED)

    surface = IMG_Load("app0:png.png");
    imageTexture = SDL_CreateTextureFromSurface(renderer, surface);
    imageWidth = surface.w
    imageHeight = surface.h
    SDL_FreeSurface(surface);

    while True:
        draw()

if __name__ == "__main__":
    main()
