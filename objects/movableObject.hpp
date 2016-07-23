#ifndef MOVABLE_OBJECT_HPP
#define MOVABLE_OBJECT_HPP

#include "object.hpp"

//namespace FlappyBird
//{
	class MovableObject : public Object
	{
	public:
		MovableObject();
		~MovableObject();

		void SetVelocity(const sf::Vector2f velocity) noexcept;
		sf::Vector2f GetVelocity() const noexcept;
		void SetSpeed(const double speed) noexcept;
		double GetSpeed() const noexcept;
		bool IsAtRest() const noexcept;

		sf::Vector2f m_velocity;
		double m_speed;
	};
//}

#endif // MOVABLE_OBJECT_HPP
