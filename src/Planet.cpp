/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "Planet.hpp"
#include "Utils.hpp"

Planet::Planet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, sf::Vector2<float> const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed, std::unique_ptr<Planet> gravity_center)
{
    sf::FloatRect textRect;

    texture = Utils::LoadTexture(texture_path);
    shape = sf::CircleShape(50);
    shape.setTexture(texture.get());
    rotateSpeed = rotate_speed;
    mass = body_mass;
    speed = start_speed;
    gravityCenter = std::move(gravity_center);

    textRect = shape.getLocalBounds();
    shape.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
    shape.setPosition(start_position);
    shape.setRotation(start_rotation);
    shape.setScale(start_scale);
}

Planet::Planet(Planet const &planet)
{
    texture = planet.texture;
    shape = planet.shape;
    rotateSpeed = planet.rotateSpeed;
    mass = planet.mass;
    speed = planet.speed;
    gravityCenter = nullptr; // std::move(planet.gravityCenter);
}

void Planet::UpdateBody(float const &delta_time)
{
    shape.rotate(rotateSpeed * delta_time);
}

void Planet::Render(sf::RenderWindow &window) const
{
    window.draw(shape);
}
