/**< SFML */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

/**< END SFML */

#include <bits/stdc++.h> /** BIBLIOTECI STANDARD NECESARE */
#include <detector.hpp> /**< DETECTOR SISTEM OPERARE URL(https://github.com/TerensTare/detector) */

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Airport Manager Simulator - Catarau Cezar-Iulian", sf::Style::Close | sf::Style::Titlebar);

    window.setVerticalSyncEnabled(true);

    sf::Font font_roboto;

    font_roboto.loadFromFile("Roboto-Regular.ttf");


    sf::Text headerTitle;

    sf::FloatRect headerTitleRect;
    headerTitle.setString("Airport Control Panel");
    headerTitle.setCharacterSize(20);
    headerTitle.setFont(font_roboto);
    headerTitle.setColor(sf::Color::Black);
    headerTitleRect = headerTitle.getLocalBounds();
    headerTitle.setOrigin(headerTitleRect.left + headerTitleRect.width/2, 0);
    headerTitle.setPosition(sf::Vector2f(400, 0));

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(headerTitle);
        window.display();
    }
}
