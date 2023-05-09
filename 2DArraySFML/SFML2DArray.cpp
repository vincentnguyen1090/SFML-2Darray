//
// Created by vince on 5/2/2023.
//

#include "SFML2DArray.h"

SFML2DArray::SFML2DArray()
{
    sf::RenderWindow window({1024, 720, 32}, "SFML 2D Array");
    window.setFramerateLimit(60);

    SFMLgrid grid;
    sf::Clock clock;

    while(window.isOpen())
    {
        sf::Event event;
        int time = clock.getElapsedTime().asMilliseconds();


        while(window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            grid.eventHandler(window, event);
        }
        window.clear();
        window.draw(grid);
        window.display();
    }

}
