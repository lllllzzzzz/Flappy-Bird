#include "movableObject.hpp"

//using namespace FlappyBird;

MovableObject::MovableObject()
{

}

MovableObject::~MovableObject()
{
	
}

void MovableObject::SetVelocity(const sf::Vector2f velocity) noexcept
{
	m_velocity = velocity;
}

sf::Vector2f MovableObject::GetVelocity() const noexcept
{
	return m_velocity;
}

void MovableObject::SetSpeed(const double speed) noexcept
{
	m_speed = speed;
}

double MovableObject::GetSpeed() const noexcept
{
	return m_speed;
}

bool MovableObject::IsAtRest() const noexcept
{
	return !m_velocity.x && !m_velocity.y;
}