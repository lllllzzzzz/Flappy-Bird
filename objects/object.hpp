#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <SFML\Graphics.hpp>

//namespace FlappyBird
//{
	class Object
	{
	public:
		Object();
		~Object();

		void SetPosition(const sf::Vector2f position) noexcept;
		sf::Vector2f GetPosition() const noexcept;
		void SetSize(const sf::Vector2f size) noexcept;
		sf::Vector2f GetSize() const noexcept;
		void Destroy() noexcept;
		bool IsDestroyed() const noexcept;
		void SetColour(const sf::Color colour) noexcept;
		sf::Color GetColour() const noexcept;

		sf::Vector2f m_position;
		sf::Vector2f m_size;
		sf::Color m_colour;

		bool m_isDestroyed;
		bool m_isVisible;
	};
//}

#endif // OBJECT_HPP
