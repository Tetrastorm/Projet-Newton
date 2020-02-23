/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "Planet.hpp"
#include "Utils.hpp"

Planet::Planet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, sf::Vector2<float> const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed, std::shared_ptr<Planet> &gravity_center)
{
    sf::FloatRect textRect;

    texture = Utils::TextureLoader(texture_path);
    shape = sf::CircleShape(50);
    shape.setTexture(texture.get());
    rotateSpeed = rotate_speed;
    mass = body_mass;
    speed = start_speed;
    gravityCenter = gravity_center;

    textRect = shape.getLocalBounds();
    shape.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    shape.setPosition(start_position);
    shape.setRotation(start_rotation);
    shape.setScale(start_scale);
    bHidden = false;
}

Planet::Planet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, sf::Vector2<float> const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed)
{
    sf::FloatRect textRect;

    texture = Utils::TextureLoader(texture_path);
    shape = sf::CircleShape(50);
    shape.setTexture(texture.get());
    rotateSpeed = rotate_speed;
    mass = body_mass;
    speed = start_speed;
    gravityCenter = nullptr;

    textRect = shape.getLocalBounds();
    shape.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    shape.setPosition(start_position);
    shape.setRotation(start_rotation);
    shape.setScale(start_scale);
    bHidden = false;
}

bool const &Planet::IsHidden(void) const
{
    return (bHidden);
}

void Planet::SetIsHidden(bool const &new_value)
{
    bHidden = new_value;
}

void Planet::Tick(float const &delta_time)
{
    shape.rotate(rotateSpeed * delta_time);
    shape.move(speed * delta_time);
    if (gravityCenter != nullptr) {
        gravityCenter->shape.getPosition();
        speed.x -= ((shape.getPosition().x - gravityCenter->shape.getPosition().x) / gravityCenter->shape.getPosition().x) * GRAVITY * delta_time;
        speed.y -= (shape.getPosition().y - gravityCenter->shape.getPosition().y) / gravityCenter->shape.getPosition().y * GRAVITY * delta_time;
    }
}

void Planet::Render(sf::RenderWindow &window) const
{
    if (!bHidden) {
        window.draw(shape);
    }
}
