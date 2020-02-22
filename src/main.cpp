#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <exception>
#include <vector>
#include <iostream>

class Planet {
public:
    explicit Planet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, float const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed, std::unique_ptr<Planet> gravity_center) {
        sf::FloatRect textRect;
        if (!texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Invalid texture file.");
        }
        sprite = sf::CircleShape(50);
        sprite.setTexture(&texture, false);
        rotateSpeed = rotate_speed;
        mass = body_mass;
        speed = start_speed;
        gravityCenter = std::move(gravity_center);

        textRect = sprite.getLocalBounds();
        sprite.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
        sprite.setPosition(start_position);
        sprite.setRotation(start_rotation);
        sprite.setScale(start_scale);
    }

    Planet(Planet &planet) {
        planet.sprite = sprite;
        planet.texture = texture;
        planet.speed = speed;
        planet.rotateSpeed = rotateSpeed;
        planet.gravityCenter = std::move(gravityCenter);
        planet.mass = mass;
    }

    Planet operator=(Planet const &planet) {
        sprite = planet.sprite;
        texture = planet.texture;
        speed = planet.speed;
        rotateSpeed = planet.rotateSpeed;
        gravityCenter = std::move(planet.gravityCenter);
        mass = planet.mass;
    }

    void UpdateBody(float const &delta_time) {
        sprite.rotate(rotateSpeed * delta_time);
    }

    void Render(sf::RenderWindow &window) const {
        window.draw(sprite);
    }

private:
    sf::Texture texture;
    sf::CircleShape sprite;
    float rotateSpeed;
    float mass;
    float speed;
    std::unique_ptr<Planet>gravityCenter;
};

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

static void update_all(std::vector<std::unique_ptr<Planet>> &planet_list, float const &delta_time)
{
    for (unsigned short i = 0U; i < planet_list.size(); ++i) {
        planet_list[i]->UpdateBody(delta_time);
    }
}

static void render_all(sf::RenderWindow &window, std::vector<std::unique_ptr<Planet>> const &planet_list)
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
    std::vector<std::unique_ptr<Planet>> planet_list;
    float tick = 1.0f;

    if (!getenv("DISPLAY")) {
        return EXIT_FAILURE;
    }
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE[0], WINDOW_SIZE[1]), "Planet Simulator");
    window.setFramerateLimit(60);
    try {
        Planet planet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.5f, static_cast<float>(WINDOW_SIZE[1]) * 0.5f), 0.5f, sf::Vector2<float>(1.0f, 1.0f), 0.f, "resources/planet.png", 100.f, 3.f, nullptr);
        planet_list.emplace_back(std::make_unique<Planet>(planet));
        planet = Planet(sf::Vector2<float>(static_cast<float>(WINDOW_SIZE[0]) * 0.85f, static_cast<float>(WINDOW_SIZE[1]) * 0.2f), 0.25f, sf::Vector2<float>(0.5f, 0.5f), 0.f, "resources/planet.png", 100.f, 3.f, std::move(planet_list[0]));
        planet_list.emplace_back(std::make_unique<Planet>(planet));
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
