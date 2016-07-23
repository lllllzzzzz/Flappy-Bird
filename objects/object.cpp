#include "object.hpp"

//using namespace FlappyBird;

Object::Object() :
	m_isVisible(true),
	m_isDestroyed(false)
{

}

Object::~Object()
{

}

void Object::SetPosition(const sf::Vector2f position) noexcept
{
	m_position = position;
}

sf::Vector2f Object::GetPosition() const noexcept
{
	return m_position;
}

void Object::SetSize(const sf::Vector2f size) noexcept
{
	m_size = size;
}

sf::Vector2f Object:: GetSize() const noexcept
{
	return m_size;
}

void Object::Destroy() noexcept
{
	m_isDestroyed = true;
}

bool Object::IsDestroyed() const noexcept
{
	return m_isDestroyed;
}

void Object::SetColour(const sf::Color colour) noexcept
{
	m_colour = colour;
}

sf::Color Object::GetColour() const noexcept
{
	return m_colour;
}
