#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <stack>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "..\resourceman\resourceManager.hpp"
#include "..\states\gameState.hpp"

using namespace FlappyBird;

class GameState;

//namespace FlappyBird
//{
    class GameEngine
    {
    public:
        GameEngine(const sf::Vector2f windowSize, const int fps, const std::string& windowTitle);
        ~GameEngine();

        void PushState(GameState* state);
        void PopState();
        void ChangeState(GameState* state);
        GameState* PeekState();

        void Run();

        void HandleWindowEvents();
        void HandleEvents();
        void Update();
        void Draw();

        bool IsRunning() const noexcept;
        void Quit() noexcept;

        bool IsWindowMoving() const noexcept;
        void MoveWindow(const bool moveWindow) noexcept;

        sf::RenderWindow& GetWindow();
        sf::Vector2f GetWindowSize() const noexcept;
        void SetWindowSize(const sf::Vector2f newWindowSize) noexcept;
        //static GameEngine* Instance() {
        //    return &m_GameEngine;
        //}

        ResourceManager resourceMan;

    private:
        //static GameEngine m_GameEngine;
        sf::RenderWindow m_window;

        std::stack<GameState*> states;

        sf::Vector2f m_windowSize;
        bool m_isWindowMoving;
        bool m_isRunning;
    };
//}

#endif // GAME_ENGINE_HPP
