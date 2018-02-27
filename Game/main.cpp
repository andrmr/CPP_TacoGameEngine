#include "Engine/Graphics/RenderEngine.h"

using namespace Engine;

int main() {
    Graphics::RenderEngine engine;
    engine.Begin();


    engine.Draw();

    SDL_Delay(3000);

    engine.Stop();

    return 0;
}
