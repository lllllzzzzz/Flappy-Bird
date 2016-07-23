#include "Player.hpp"

//using namespace PlayerGame;

const float Player::FALLING_SPEED = .5f;
const float Player::JUMPING_SPEED = 7.f;
const sf::Vector2f Player::PLAYER_SIZE = {35, 35};

Player::Player(/*GameEngine *game,*/ /*const sf::Vector2f position, const sf::Vector2f size*/) :
	m_speed(0),
	m_rotationAngle(0)
{
    shape.setSize(/*PLAYER_SIZE*/{35, 35});
    //shape.setFillColor({0, 255, 0});
    shape.setOrigin(/*PLAYER_SIZE.x*/30 / 2.f, /*PLAYER_SIZE.y*/30 / 2.f);

    m_velocity = {0, 0};
}

Player::~Player()
{

}

void Player::Init(GameEngine *game)
{
	m_engine = game;
	shape.setPosition({m_engine->GetWindowSize().x / 3, m_engine->GetWindowSize().y / 2});
	shape.setTexture(&m_engine->resourceMan.GetTexture("brick.png"));
	m_jumpSound.setBuffer(game->resourceMan.GetSound("jump.wav"));
}

void Player::Cleanup()
{

}

void Player::Reset() noexcept
{
	SetVelocity({0, 0});
	SetPosition({m_engine->GetWindowSize().x / 3, m_engine->GetWindowSize().y / 2});
}

void Player::Update() noexcept
{
    shape.move(m_velocity);

    if (m_rotationAngle <= 45) {
    	//shape.rotate(m_rotationAngle);
    }

    if (top() <= 30) {
    	SetPosition({x(), 30 + 10});
    }

    m_velocity.y += FALLING_SPEED;
}

void Player::Draw()
{

}

void Player::HandleInput(/*PlayState *game*/) noexcept
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        //m_speed += JUMPING_SPEED;
        if (m_velocity.y > 0) {
            m_velocity.y += -JUMPING_SPEED;
        } else {
            m_velocity.y = -JUMPING_SPEED;
        }

        m_rotationAngle = 45;
        if (m_rotationAngle <= 45) {
        	//shape.rotate(m_rotationAngle);
        }

		//if (IsSoundEnabled()) {
	        //game->m_sounds.at(SoundEffect::JUMP).play();
	        m_jumpSound.play();
	    //}
    }
}

void Player::SetPosition(const sf::Vector2f position) noexcept
{
 	shape.setPosition(position);
}

void Player::SetColour(const sf::Color colour) noexcept
{
	//shape.SetColour(colour);
}
