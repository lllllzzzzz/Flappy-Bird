#include "barrier.hpp"

const float Barrier::MOVEMENT_SPEED = 4.f;

Barrier::Barrier(GameEngine *game, const sf::Vector2f position, const sf::Vector2f size) :
	m_playerHasPassed(false)
{
	m_engine = game;

	shape.setPosition(position);
    shape.setSize(size);
    //shape.setFillColor({255, 0, 0});
    shape.setTexture(&game->resourceMan.GetTexture("border_side.png"));
    shape.setOrigin(size.x / 2.f, size.y / 2.f);

    m_velocity = {-MOVEMENT_SPEED, 0};
}

Barrier::~Barrier()
{

}

void Barrier::Update() noexcept
{
	shape.move(m_velocity);

	/*if (HasPlayerPassed()) {
		if (shape.getSize().y <= 275) {
			shape.setSize({shape.getSize().x, shape.getSize().y + 8});

			if (top() <= 0) {
				shape.setPosition({x(), y() + 0});
			} else if (top() >= 0) {
				shape.setPosition({x(), y() - 8});
			}
		}
	}*/
}