/**< SFML */

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

/**< END SFML */

#include <bits/stdc++.h> /** BIBLIOTECI STANDARD NECESARE */
#include <detector.hpp> /**< DETECTOR SISTEM OPERARE URL(https://github.com/TerensTare/detector) */

/**< CUSTOM HEADERS */

#include "fps.h" /**< Header folosit a afisa FPS-urile */

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Airport Manager Simulator - Catarau Cezar-Iulian", sf::Style::Close | sf::Style::Titlebar);

    //window.setVerticalSyncEnabled(true);

    sf::Font font_roboto;

    font_roboto.loadFromFile("Roboto-Regular.ttf");

    sf::Text _TextIndex[200]; /**< Array pentru indexarea butoanelor */
    unsigned lastButtonIndex = -1;
    unsigned currentButton = 0;

    /**< HEADER TITLE */
    sf::Text headerTitle;

    sf::FloatRect headerTitleRect;
    headerTitle.setString("Airport Control Panel");
    headerTitle.setCharacterSize(30);
    headerTitle.setFont(font_roboto);
    headerTitle.setColor(sf::Color::Black);
    headerTitleRect = headerTitle.getLocalBounds();
    headerTitle.setOrigin(headerTitleRect.left + headerTitleRect.width/2, 0);
    headerTitle.setPosition(sf::Vector2f(400, 0));
    /**< END HEADER TITLE */

    /**< STATUS BUTTON */
    sf::Text status_button;
    status_button.setString("Status");
    status_button.setCharacterSize(20);
    status_button.setFont(font_roboto);
    status_button.setColor(sf::Color::Black);
    //status_button.setStyle(sf::Text::Underlined);
    status_button.setPosition(sf::Vector2f(25, 100));

    _TextIndex[++lastButtonIndex] = status_button;
    /**< END STATUS BUTTON */


    /**< EMPLOYERS BUTTON */
    sf::Text employers_button;
    employers_button.setString("Employers");
    employers_button.setCharacterSize(20);
    employers_button.setFont(font_roboto);
    employers_button.setColor(sf::Color::Black);
    //employers_button.setStyle(sf::Text::Underlined);
    employers_button.setPosition(sf::Vector2f(25, 150));

    _TextIndex[++lastButtonIndex] = employers_button;
    /**< END EMPLOYERS BUTTON */


    /**< EMPLOYERS BUTTON */
    sf::Text test_button;
    test_button.setString("Test");
    test_button.setCharacterSize(20);
    test_button.setFont(font_roboto);
    test_button.setColor(sf::Color::Black);
    //employers_button.setStyle(sf::Text::Underlined);
    test_button.setPosition(sf::Vector2f(25, 200));

    _TextIndex[++lastButtonIndex] = test_button;
    /**< END EMPLOYERS BUTTON */



    sf::Clock clock; /**< Pentru ceas */
    sf::Time elapsed_time;


    FPS cFPS;

    while(window.isOpen())
    {
        //sf::Thread thread(&cFPS.get_window_fps, &cFPS);
        //thread.launch();
        sf::Event event;

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::Closed:
                window.close();
            default:
                break;
            }
        }

        if(clock.getElapsedTime().asSeconds() > 0.15)
        {


            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && currentButton < lastButtonIndex)
            {
                std::cout<<"Buton down apasat";
                currentButton++;
                _TextIndex[currentButton].setStyle(sf::Text::Underlined);

                std::cout<<currentButton;

                for(int i=0; i<=lastButtonIndex; i++)
                    if(i != currentButton)
                        _TextIndex[i].setStyle(sf::Text::Regular);

                clock.restart();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && currentButton > 0)
            {
                std::cout<<"Buton up apasat";
                currentButton--;
                _TextIndex[currentButton].setStyle(sf::Text::Underlined);

                std::cout<<currentButton;

                for(int i=0; i<=lastButtonIndex; i++)
                    if(i != currentButton)
                        _TextIndex[i].setStyle(sf::Text::Regular);

                clock.restart();
            }
        }

        window.clear(sf::Color::White);
        window.draw(headerTitle);
        for(int i=0; i<=lastButtonIndex; i++)
            window.draw(_TextIndex[i]);

        window.display();
    }
}
