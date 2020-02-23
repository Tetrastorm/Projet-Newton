#include <SFML/Graphics.hpp>
#include <string>
#include <exception>
#include <vector>
#include <chrono>
#include "Debug.hpp"
#include "PlanetFactory.hpp"
#include "Planet.hpp"
#include "NewtonType.hpp"
#include "Utils.hpp"

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
    for (const std::shared_ptr<IObject> &planet : planet_list) {
        planet->Tick(delta_time);
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

static void init_planet(std::vector<std::shared_ptr<Planet>> &planet_list)
{
    PlanetFactory factory;

    Debug::Log("[Initialisation]\tStart");
    planet_list.push_back(factory.MakePlanet(Utils::GetPositionOnScreen(0.5f, 0.5f), 0.01f, sf::Vector2<float>(1.f, 1.f), sf::Vector2<float>(0.f, 0.f), "resources/sun.png", 100.f, 10.f));
    planet_list.push_back(factory.MakePlanet(Utils::GetPositionOnScreen(0.85f, 0.2f), 0.25f, sf::Vector2<float>(0.5f, 0.5f), sf::Vector2<float>(10.f, 50.f), "resources/gaz_planet_1.png", 100.f, 3.25f, planet_list[0]));
    planet_list.push_back(factory.MakePlanet(Utils::GetPositionOnScreen(0.9f, 0.9f), 1.f, sf::Vector2<float>(0.3f, 0.3f), sf::Vector2<float>(40.f, 20.f), "resources/rock_planet_1.png", 100.f, 5.f, planet_list[0]));
    planet_list.push_back(factory.MakePlanet(Utils::GetPositionOnScreen(0.1f, 0.5f), 1.f, sf::Vector2<float>(0.2f, 0.2f), sf::Vector2<float>(-5.f, 60.f), "resources/gaz_planet_1.png", 100.f, 25.f, planet_list[0]));
    Debug::Log("[Initialisation]\tEnd");
}

static void main_loop(std::vector<std::shared_ptr<Planet>> &planet_list, sf::RenderWindow &window)
{
    std::chrono::steady_clock::time_point ref_point = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point loop_point;
    double time_made;

    while (window.isOpen()) {
        event_handling(window);
        loop_point = std::chrono::steady_clock::now();
        time_made = std::chrono::duration_cast<std::chrono::duration<double>>(loop_point - ref_point).count();
        ref_point = loop_point;
        update_all(planet_list, static_cast<float>(time_made));
        render_all(window, planet_list);
    }
}

int main(void)
{
    std::vector<std::shared_ptr<Planet>> planet_list;

    if (!getenv("DISPLAY")) {
        Debug::Log(ESeverity::Critical, "No graphical mode detected");
        return EXIT_FAILURE;
    }
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE[0], WINDOW_SIZE[1]), "Newton");
    Debug::Log("Create Window");
    window.setFramerateLimit(60);
    try {
        init_planet(planet_list);
    } catch (std::exception const &e) {
        Debug::Log(ESeverity::Critical, e.what());
        return EXIT_FAILURE;
    }
    main_loop(planet_list, window);
    Debug::Log("Game exited");
    return EXIT_SUCCESS;
}
