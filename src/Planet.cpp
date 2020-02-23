/*
** EPITECH PROJECT, 2020
** - Project name
** File description:
** - File description
*/

#include "Planet.hpp"

Planet::Planet(sf::Vector2<float> const &start_position, float const &start_rotation, sf::Vector2<float> const &start_scale, sf::Vector2<float> const &start_speed, std::string const &texture_path, float const &body_mass, float const &rotate_speed, std::unique_ptr<Planet> gravity_center)
{
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

Planet::Planet(Planet const &planet)
{
    sprite = planet.sprite;
    texture = planet.texture;
    rotateSpeed = planet.rotateSpeed;
    mass = planet.mass;
    speed = planet.speed;
    //gravityCenter = std::move(planet.gravityCenter);
}

void Planet::UpdateBody(float const &delta_time)
{
    sprite.rotate(rotateSpeed * delta_time);
}

void Planet::Render(sf::RenderWindow &window) const
{
    window.draw(sprite);
}
