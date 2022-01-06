/**< SFML */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**< END SFML */

#include <bits/stdc++.h> /** BIBLIOTECI STANDARD NECESARE */
#include <detector.hpp> /**< DETECTOR SISTEM OPERARE URL(https://github.com/TerensTare/detector) */

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Airport Manager Simulator - Catarau Cezar-Iulian");

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }


    }
}
