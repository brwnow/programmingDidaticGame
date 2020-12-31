#include "core/main.h"

#include <SDL.h>
#include <SDL_ttf.h>

#include "utils/log/log.h"
#include "core/video/video.h"
#include "core/input/events.h"
#include "core/input/keyboard.h"
#include "core/video/window.h"

int main(int argc, char *argv[]) {
    UNUSED(argc);
    UNUSED(argv);

    if(appInit() == false)
        return 0;

    if(windowStartup("Breno Game", 800, 600) == false)
        return 0;

    if(TTF_Init() != 0) {
        logCritical("Failed to initialize TTF SDL extension - reason %s", SDL_GetError());

        return 0;
    }

    TTF_Font *font = TTF_OpenFont("res/fonts/AlexBrush-Regular.ttf", 80);
    TTF_Font *font2 = TTF_OpenFont("res/fonts/SEASRN__.ttf", 32);
    SDL_Surface *fontSurface = NULL;
    SDL_Surface *exitMsg = NULL;
    SDL_Color fontColor = {145, 242, 145, 255};
    SDL_Color fontColor2 = {242, 145, 145, 255};

    if(font != NULL) {
        fontSurface = TTF_RenderText_Blended(font, "Eu sou o que eu quero ser!", fontColor);
        exitMsg = TTF_RenderText_Blended(font2, "! PRESSIONE ESC PARA SAIR !", fontColor2);
    }

    TTF_CloseFont(font);
    TTF_CloseFont(font2);
    font = NULL;

    SDL_Surface *screen = windowGetScreen();

    while(isKeyPressed(SDL_SCANCODE_ESCAPE) == false) {
        SDL_PumpEvents();

        if(screen != NULL && fontSurface != NULL && exitMsg != NULL) {
            int screenWidth = screen->w;
            int screenHeight = screen->h;
            int fontSurfWidth = fontSurface->w;
            int fontSurfHeigth = fontSurface->h;
            int exitMsgWidth = exitMsg->w;
            int exitMsgHeigth = exitMsg->h;
            SDL_Rect destRect = {   (screenWidth - fontSurfWidth) / 2,
                                    (screenHeight - fontSurfHeigth) / 2,
                                    fontSurfWidth,
                                    fontSurfHeigth };
            SDL_Rect destExitMsgRect = {(screenWidth - exitMsgWidth) / 2,
                                        screenHeight * 75 / 100,
                                        exitMsgWidth,
                                        exitMsgHeigth };

            SDL_BlitSurface(fontSurface, &(fontSurface->clip_rect), screen, &destRect);
            SDL_BlitSurface(exitMsg, &(exitMsg->clip_rect), screen, &destExitMsgRect);
        }

        windowFlipPage();

        SDL_Delay(25);
    }

    SDL_FreeSurface(fontSurface);
    SDL_FreeSurface(exitMsg);
    SDL_FreeSurface(screen);
    fontSurface = NULL;
    exitMsg = NULL;
    screen = NULL;

    TTF_Quit();
    windowClose();
    appEnd();

    return 0;
}

bool appInit(void) {
    logInfo("Initializing application");

    logInit();

    if(SDL_Init(SDL_INIT_TIMER) != 0) {
        logCritical("SDL initialization failed - reason: %s", SDL_GetError());

        return false;
    } else if(videoInit() == false) {
        return false;
    } else if(eventsInit() == false) {
        return false;
    } else if(keyboardInit() == false) {
        return false;
    } else {
        logInfo("Application succesfully initialized");

        return true;
    }
}

void appEnd(void) {
    logInfo("Stopping application");

    keyboardEnd();
    eventsEnd();
    videoEnd();
    SDL_Quit();
}