#ifndef RECTANGLE_OBJECT_HPP
#define RECTANGLE_OBJECT_HPP

#include <SFML\Graphics.hpp>

//namespace FlappyBird
//{
    class RectangleObject
    {
    public:
        RectangleObject();
        ~RectangleObject();

        float x() const noexcept { return shape.getPosition().x; }
        float y() const noexcept { return shape.getPosition().y; }
        float left() const noexcept { return x() - shape.getSize().x / 2.f; }
        float right() const noexcept { return x() + shape.getSize().x / 2.f; }
        float top() const noexcept { return y() - shape.getSize().y / 2.f; }
        float bottom() const noexcept { return y() + shape.getSize().y / 2.f; }

        sf::RectangleShape shape;
    };
//}

#endif // RECTANGLE_OBJECT_HPP
