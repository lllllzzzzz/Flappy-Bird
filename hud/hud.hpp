#ifndef HUD_HPP
#define HUD_HPP

#include <SFML\Graphics.hpp>
#include "..\stateman\gameEngine.hpp"
//#include "..\states\gameState.hpp"

//namespace FlappyBird
//{
    class Hud
    {
    public:
        Hud();
        ~Hud();

        void Init(GameEngine *game);

        void DisplayHud(/*/*GameEngine *game, */const int playerScore, const int highScore);
        void DisplayPlayerScore(/*GameEngine *game, */const int playerScore);
        void DisplayHighScore(/*GameEngine *game, */const int highScore);

        sf::Vector2f GetSize() const noexcept { return m_size; }

    private:
        GameEngine *m_engine;
        sf::Vector2f m_size;
        sf::RectangleShape m_scoreBackground;

        sf::Text text;
        sf::Font font;

        static const sf::Color BACKGROUND_COLOUR;
        static const sf::Color PLAYER_SCORE_COLOUR;
        static const sf::Color HIGH_SCORE_COLOUR;
        static const sf::Color TEXT_COLOUR;
        static const int TEXT_SIZE;
        static const std::string TEXT_FONT;
        static const sf::Vector2f PLAYER_SCORE_POSITION;
        static const sf::Vector2f HIGH_SCORE_POSITION;
    };
//}

#endif // HUD_HPP