#include "ProjectHeader.hpp"

int main(void)
{
    // --------------------- Initialization ---------------------------
    InitWindow(variables::screenWidth, variables::screenHeight, ProjectInfo::appName);
    initializeVariables();
    SetTargetFPS(variables::targetFPS);
    SetExitKey(0);

    while (!variables::shouldExit)
    {
        switch (variables::currentLayer)
        {
        case variables::LOADING_SCREEN:
            loadingScreen();
            break;
        case variables::FATAL_ERROR_SCREEN:
            fatalErrorScreen();
            break;
        case variables::EXIT_SCREEN:
            exitScreen();
            break;
        default:
            fatalErrorScreen();
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(variables::fatalErrorTexture);
    UnloadTexture(variables::successTexture);
    UnloadTexture(variables::errorTexture);
    UnloadTexture(variables::bugCatTexture);
    UnloadImage(variables::bugCatGIFImage);
    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}