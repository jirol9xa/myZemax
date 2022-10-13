#include "widget.h"
#include "actionManager.h"
#include "button.h"
#include "videoSettings.h"
#include <cstdio>
#include <SFML/Graphics.hpp>


int main()
{ 
    using Settings::Heigth;
    using Settings::Width;

    sf::RenderWindow window(sf::VideoMode(Width, Heigth), "myZemax");

    ActionManager mng;    
    Render render(&window);

    Button RedBut({0, 0}, {255, 0, 0});
    Button GreenBut({10, 0}, {0, 255, 0});
    Button BlueBut({20, 0}, {0, 0, 255});

    BlueBut.register_callbacks(&mng, &render);
    GreenBut.register_callbacks(&mng, &render);
    BlueBut.register_callbacks(&mng, &render);

    return 0;
}