#include "hud.hpp"

#include <windows.h>

//using namespace FlappyBird;

const sf::Color Hud::BACKGROUND_COLOUR = sf::Color::Black;
const sf::Color Hud::PLAYER_SCORE_COLOUR = sf::Color::Green;
const sf::Color Hud::HIGH_SCORE_COLOUR = sf::Color::Red;
const sf::Color Hud::TEXT_COLOUR = sf::Color::Red;
const int Hud::TEXT_SIZE = 20;
const std::string Hud::TEXT_FONT = "PressStart2P.ttf";
const sf::Vector2f Hud::PLAYER_SCORE_POSITION = {25, 8};
const sf::Vector2f Hud::HIGH_SCORE_POSITION = {65, 8};

Hud::Hud()
{

}

Hud::~Hud()
{

}

void Hud::Init(GameEngine *game)
{
    m_engine = game;
    m_size = {m_engine->GetWindowSize().x, 30};

    text.setFont(m_engine->resourceMan.GetFont("PressStart2P.ttf"));
    text.setCharacterSize(TEXT_SIZE);

    m_scoreBackground.setSize(m_size);
    m_scoreBackground.setFillColor(BACKGROUND_COLOUR);
    m_scoreBackground.setOrigin(0, 0);
}

void Hud::DisplayHud(/*GameEngine *game, */const int playerScore, const int highScore)
{
    //m_engine->GetWindow().draw(m_scoreBackground);

    DisplayPlayerScore(/*game, */playerScore);
    DisplayHighScore(/*game, */std::max(playerScore / 2, highScore / 2));
}

void Hud::DisplayPlayerScore(/*GameEngine *game, */const int playerScore)
{
    text.setColor(PLAYER_SCORE_COLOUR);
    text.setString(std::to_string(playerScore / 2));
    text.setPosition(PLAYER_SCORE_POSITION.x, PLAYER_SCORE_POSITION.y);
    m_engine->GetWindow().draw(text);
}

void Hud::DisplayHighScore(/*GameEngine *game, */const int highScore)
{
    text.setColor(HIGH_SCORE_COLOUR);
    text.setString(std::to_string(highScore));
    text.setPosition(/*HIGH_SCORE_POSITION.x, HIGH_SCORE_POSITION.y*/{25, static_cast<int>(m_engine->GetWindowSize().y) - 30});
    m_engine->GetWindow().draw(text);
}
