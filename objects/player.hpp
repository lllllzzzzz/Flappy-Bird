#ifndef Player_HPP
#define Player_HPP

#include <vector>
#include "..\stateman\gameEngine.hpp"
//#include "..\states\playState.hpp"
#include "movableObject.hpp"
#include "rectangleObject.hpp"

namespace Common {
	enum class Direction {
		NORTH, SOUTH, EAST, WEST
	};
}

using namespace Common;

class GameEngine;

//namespace PlayerGame
//{
	class Player : public MovableObject, public RectangleObject
	{
	public:
		Player(/*GameEngine *game, *//*const sf::Vector2f position, const sf::Vector2f size*/);
		~Player();

		void Init(GameEngine *game);
		void Cleanup();

		void Reset() noexcept;

		void Update() noexcept;
		void Draw();
		void HandleInput(/*PlayState *game*/) noexcept;

		void SetPosition(const sf::Vector2f position) noexcept;
		sf::Vector2f GetPosition() const noexcept { return m_position; }

		void SetSpeed(const double speed) noexcept;
		double GetSpeed() const noexcept { return m_speed; }

		void SetColour(const sf::Color colour) noexcept;
		sf::Color GetColour() const noexcept { return m_colour; }

	private:
		GameEngine *m_engine;

		sf::Vector2f m_position;
		sf::Color m_colour;
		sf::Sound m_jumpSound;

		Direction m_direction;
		double m_speed;

		int m_rotationAngle;

		static const float FALLING_SPEED;
		static const float JUMPING_SPEED;
		static const sf::Vector2f PLAYER_SIZE;
	};
//}

#endif // Player_HPP
