#ifndef BARRIER_HPP
#define BARRIER_HPP

#include "..\stateman\gameEngine.hpp"
#include "movableObject.hpp"
#include "rectangleObject.hpp"

class Barrier : public MovableObject, public RectangleObject
{
public:
	Barrier(GameEngine *game, const sf::Vector2f position, const sf::Vector2f size);
	~Barrier();

	void Update() noexcept;

	inline void SetPlayerPassed(const bool state) noexcept { m_playerHasPassed = state; }
	inline bool HasPlayerPassed() const noexcept { return m_playerHasPassed; }

private:
	GameEngine *m_engine;

	sf::Vector2f m_position;
	sf::Color m_colour;

	double m_speed;

	bool m_playerHasPassed;

	static const float MOVEMENT_SPEED;
};

#endif // BARRIER_HPP
