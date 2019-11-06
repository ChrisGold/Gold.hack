#include <iostream>
#include "src/Level.h"
#include "src/Game.h"

int main()
{
    Game g;
    g.init();
    g.loop();    
    return 0;
}