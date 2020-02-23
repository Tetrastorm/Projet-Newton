#include <SFML/Graphics.hpp>
#include <string>
#include <exception>
#include <vector>
#include <chrono>
#include "Debug.hpp"
#include "PlanetFactory.hpp"
#include "Planet.hpp"
#include "NewtonType.hpp"

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

static void update_all(std::vector<std::shared_ptr<Planet> > &planet_list, float const &delta_time)
{
    for (const std::shared_ptr<Planet> &planet : planet_list) {
        planet->UpdateBody(delta_time);
    }
}

static void render_all(sf::RenderWindow &window, std::vector<std::shared_ptr<Planet> > const &planet_list)
{
    window.clear(sf::Color(0, 0, 0, 0));
    for (const std::shared_ptr<Planet> &planet : planet_list) {
        planet->Render(window);
    }
    window.display();
}

int main(void)
{
    std::vector<std::shared_ptr<Planet>> planet_list;
    PlanetFactory factory;
    std::chrono::steady_clock::time_point ref_point = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point loop_point;
    double time_made;

    if (!getenv("DISPLAY")) {
        Debug::Log(ESeverity::Critical, "No graphical mode detected");
        return EXIT_FAILURE;
    }
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE[0], WINDOW_SIZE[1]), "Newton");
    Debug::Log("Create Window");
    Debug::Log("[Initialisation]\tStart");
    window.setFramerateLimit(60);
    try {
        planet_list.push_back(factory.MakePlanet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.5f, static_cast<float>(WINDOW_SIZE[1]) * 0.5f), 0.01f, sf::Vector2<float>(1.f, 1.f), sf::Vector2<float>(0.f, 0.f), "resources/sun.png", 100.f, 10.f));
        planet_list.push_back(factory.MakePlanet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.85f, static_cast<float>(WINDOW_SIZE[1]) * 0.2f), 0.25f, sf::Vector2<float>(0.5f, 0.5f), sf::Vector2<float>(5.f, 0.f), "resources/gaz_planet_1.png", 100.f, 3.25f, planet_list[0]));
        planet_list.push_back(factory.MakePlanet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.90f, static_cast<float>(WINDOW_SIZE[1]) * 0.90f), 1.f, sf::Vector2<float>(0.3f, 0.3f), sf::Vector2<float>(4.f, 2.f), "resources/rock_planet_1.png", 100.f, 5.f, planet_list[0]));
    } catch (std::exception const &e) {
        Debug::Log(ESeverity::Critical, e.what());
        return EXIT_FAILURE;
    }
    Debug::Log("[Initialisation]\tEnd");

    while (window.isOpen()) {
        event_handling(window);
        loop_point = std::chrono::steady_clock::now();
        time_made = std::chrono::duration_cast<std::chrono::duration<double>>(loop_point - ref_point).count();
        ref_point = loop_point;
        update_all(planet_list, static_cast<float>(time_made));
        render_all(window, planet_list);
    }
    Debug::Log("Game exited");
    return EXIT_SUCCESS;
}
