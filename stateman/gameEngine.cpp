#include <iostream>
#include "gameEngine.hpp"
#include "..\resourceman\resourceManager.hpp"
#include "..\states\gameState.hpp"

//using namespace FlappyBird;

//GameEngine GameEngine::m_GameEngine;

GameEngine::GameEngine(const sf::Vector2f windowSize, const int fps, const std::string& windowTitle) :
    m_window({windowSize.x, windowSize.y}, windowTitle, sf::Style::Titlebar | sf::Style::Close),
    m_windowSize(windowSize),
    m_isWindowMoving(false),
    m_isRunning(true)
{
    m_window.setFramerateLimit(fps);
    m_window.setKeyRepeatEnabled(false);
}

GameEngine::~GameEngine()
{

}

void GameEngine::PushState(GameState* state)
{
    if (!states.empty()) {
        states.top()->Pause();
    }

    states.push(state);

    PeekState()->Init(this);
}

void GameEngine::PopState()
{
    delete states.top();
    states.pop();
}

void GameEngine::ChangeState(GameState* state)
{
    if (!states.empty()) {
        PopState();
    }

    PushState(state);

    PeekState()->Init(this);
}

GameState* GameEngine::PeekState()
{
    if (states.empty()) {
        return nullptr;
    }

    return states.top();
}

void GameEngine::Run()
{
    //HandleWindowEvents();
    HandleEvents();
    Update();
    Draw();
}

void GameEngine::HandleWindowEvents()
{
    // Poll window events
    sf::Event event;
    while (GetWindow().pollEvent(event)) {
        if (IsWindowMoving()) {
            GetWindow().setPosition({sf::Mouse::getPosition().x - GetWindowSize().x / 2, sf::Mouse::getPosition().y - GetWindowSize().y / 2});
        } if (event.type == sf::Event::MouseButtonPressed/* && event.MouseButton.Button == sf::Mouse::Left*/) {
            MoveWindow(true);
        } else if (event.type == sf::Event::MouseButtonReleased/* && event.MouseButton.Button == sf::Mouse::Left*/) {
            MoveWindow(false);
        } else if (event.type == sf::Event::Closed) {
            Quit();
        }
    }
}

void GameEngine::HandleEvents()
{
    states.top()->HandleEvents(/*this*/);
}

void GameEngine::Update()
{
    states.top()->Update(/*this*/);
}

void GameEngine::Draw()
{
    states.top()->Draw(/*this*/);
}

bool GameEngine::IsRunning() const noexcept
{
    return m_isRunning;
}

void GameEngine::Quit() noexcept
{
    m_isRunning = false;
}

bool GameEngine::IsWindowMoving() const noexcept
{
    return m_isWindowMoving;
}

void GameEngine::MoveWindow(const bool moveWindow) noexcept
{
    m_isWindowMoving = moveWindow;
}

sf::RenderWindow& GameEngine::GetWindow()
{
    return m_window;
}

sf::Vector2f GameEngine::GetWindowSize() const noexcept
{
    return m_windowSize;
}

void GameEngine::SetWindowSize(const sf::Vector2f newWindowSize) noexcept
{
    m_windowSize = newWindowSize;
}