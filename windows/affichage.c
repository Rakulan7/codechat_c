#include <SDL/SDL.h>

int main( int argc, char *argv[] )
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error in SDL_Init : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    SDL_Surface * ecran = NULL;
    if ((ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
        fprintf(stderr, "Error in SDL_SetVideoMode : %s\n", SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 239, 213)); // changer la couleur de la fenetre
    SDL_Flip(ecran);

    printf("Fully ");



    // boucle pour que la fenetre reste allumée
    int active = 1;
    SDL_Event event;
    while(active) {
        SDL_WaitEvent(&event);
        switch(event.type) {
            case SDL_QUIT : active = 0; break;
            case SDL_KEYUP : active = 0; break;
            default : break;
        }
    }

    SDL_Quit();
    exit(EXIT_SUCCESS);
}