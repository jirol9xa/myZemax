#include "widget.h"
#include "actionManager.h"
#include "button.h"
#include "videoSettings.h"
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "canvas.h"


int main()
{ 
    using Settings::Heigth;
    using Settings::Width;

    sf::RenderWindow window(sf::VideoMode(Width, Heigth), "myZemax");

    ActionManager mng;    
    Render render(&window);

    Button red_but({0, 0}, {255, 0, 0});
    Button green_but({100, 0}, {0, 255, 0});
    Button blue_but({200, 0}, {0, 0, 255});

    Canvas canvas({300, 300}, {255, 255, 255}, &mng);
    canvas.setHeight(200);
    canvas.setWidth (200);

    red_but.register_callbacks  (&mng, &render);
    green_but.register_callbacks(&mng, &render);
    blue_but.register_callbacks (&mng, &render);
    canvas.register_callbacks   (&mng, &render);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            Vec2 pos = {size_t(sf::Mouse::getPosition(window).x),
                        size_t(sf::Mouse::getPosition(window).y)};
            mng.onClick(pos, true);
        }
        else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            Vec2 pos = {size_t(sf::Mouse::getPosition(window).x),
                        size_t(sf::Mouse::getPosition(window).y)};
            mng.onClick(pos, false);
        }

        render.drawAll();

        window.display();
        window.clear();
    }

    return 0;
}