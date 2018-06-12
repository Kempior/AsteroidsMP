#include "Asteroids/GameObjects/GameObject.hpp"

void GameObject::Draw(sf::RenderWindow &window) {
	sprite.setPosition(position);
	sprite.setRotation(rotation + 180.f);

	window.draw(sprite);
}

bool GameObject::Collide(GameObject &other) const {
	sf::Vector2f diff = position - other.position;

	return sqrtf(diff.x * diff.x + diff.y * diff.y) <= radius + other.radius;
}

sf::Vector2f GameObject::Forward() const {

	sf::Vector2f returnVec(sinf(-rotation * M_PI / 180), cosf(-rotation * M_PI / 180));

	return returnVec;
}
