#include <SFML/Window.hpp>
#include <bits/stdc++.h>

#include "fps.h"

int FPS::get_window_fps(){
    sf::Clock clock;
    float time = clock.getElapsedTime().asSeconds();

    int FPS_counter = 0;

    return FPS_counter;
}
