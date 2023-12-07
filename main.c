#include <SDL/SDL.h>

int main() {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface * ecran = SDL_SetVideoMode(2000, 1000, 32, SDL_HWSURFACE);
    SDL_Event event;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 239, 213));
    SDL_Flip(ecran);






    int active = 1;
    while(active) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT : active = 0; break;
        }
    }

    SDL_FreeSurface(ecran);
    SDL_Quit();
    exit(EXIT_SUCCESS);

}