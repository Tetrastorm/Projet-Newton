#include <SFML/Graphics.hpp>
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include "PlanetFactory.hpp"
#include "Planet.hpp"

static void event_handling(sf::RenderWindow &window)
{
    static sf::Event event;

    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

static void update_all(std::vector<std::unique_ptr<Planet> > &planet_list, float const &delta_time)
{
    for (unsigned short i = 0U; i < planet_list.size(); ++i) {
        planet_list[i]->UpdateBody(delta_time);
    }
}

static void render_all(sf::RenderWindow &window, std::vector<std::unique_ptr<Planet> > const &planet_list)
{
    window.clear(sf::Color(51, 35, 64, 1));
    for (unsigned short i = 0U; i < planet_list.size(); ++i) {
        planet_list[i]->Render(window);
    }
    window.display();
}

int main(void)
{
    unsigned int const WINDOW_SIZE[2] = {800, 600};
    std::vector<std::unique_ptr<Planet> > planet_list;
    float tick = 1.0f;
    PlanetFactory factory;

    if (!getenv("DISPLAY")) {
        return EXIT_FAILURE;
    }
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE[0], WINDOW_SIZE[1]), "Planet Simulator");
    window.setFramerateLimit(60);
    try {
        planet_list.push_back(factory.MakePlanet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.5f, static_cast<float>(WINDOW_SIZE[1]) * 0.5f), 0.01f, sf::Vector2<float>(1.f, 1.f), sf::Vector2<float>(0.f, 0.f), "resources/planet.png", 100.f, 3.f, nullptr));
        //planet_list.push_back(factory.MakePlanet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.85f, static_cast<float>(WINDOW_SIZE[1]) * 0.2f), 0.25f, sf::Vector2<float>(0.5f, 0.5f), sf::Vector2<float>(5.f, 0.f), "resources/planet.png", 100.f, 3.f, std::move(planet_list[0])));
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    while (window.isOpen()) {
        event_handling(window);
        update_all(planet_list, tick);
        render_all(window, planet_list);
    }
    return EXIT_SUCCESS;
}
