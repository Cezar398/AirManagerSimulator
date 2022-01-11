#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <bits/stdc++.h>

#include "status.hpp"

void Status::initializare()
{
    sf::RenderWindow status_window(sf::VideoMode(800, 600), "Status Page", sf::Style::Close | sf::Style::Titlebar);

    sf::Font font_roboto;

    font_roboto.loadFromFile("Roboto-Regular.ttf");

    /**< STATUS TITLE */
    sf::Text status_title;
    status_title.setString("Status Airport");
    status_title.setCharacterSize(20);
    status_title.setFont(font_roboto);
    status_title.setColor(sf::Color::Black);
    //employers_button.setStyle(sf::Text::Underlined);
    status_title.setPosition(sf::Vector2f(25, 200));
    /**< END STATUS TITLE */


    while(status_window.isOpen())
    {
        sf::Event status_event;

        while(status_window.pollEvent(status_event))
        {
            switch(status_event.type)
            {
            case sf::Event::Closed:
                status_window.close();
            case sf::Event::LostFocus:
                status_window.requestFocus();
                break;
            }
        }
        status_window.clear(sf::Color::White);
        status_window.draw(status_title);
        status_window.display();
    }
}
