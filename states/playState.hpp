#ifndef PLAY_STATE_HPP
#define PLAY_STATE_HPP

#include <SFML\Audio.hpp>
//#include <chrono>

#include "gameState.hpp"
#include "..\hud\hud.hpp"
#include "..\objects\player.hpp"
#include "..\objects\barrier.hpp"

//namespace SnakeGame
//{
    class PlayState : public GameState
    {
    public:
        PlayState();
        ~PlayState();

        void Init(GameEngine *game);
        void Cleanup();

        void Pause();
        void Resume();

        void HandleEvents();
        void Update();
        void Draw();

        void LoadResources();
        void LoadObjects();

        void NewGame();

        void GenerateNewBarrier();

        inline void SetPlayerScore(const int score) noexcept { m_playerScore = score; }
        inline int GetPlayerScore() const noexcept { return m_playerScore; }
        inline void GainPoints(const int score) noexcept { m_playerScore += score; }

        inline bool IsGameRunning() const noexcept { return m_isGameRunning; }
        inline void SetGameRunning(const bool state) noexcept { m_isGameRunning = state; }

        inline bool IsSoundEnabled() const noexcept { return m_isSoundEnabled; }
        inline void SetSoundEnabled(const bool state) noexcept { m_isSoundEnabled = state; }

        template <class T1, class T2>
        bool IsIntersecting(T1& mA, T2& mB);
        void TestCollision(Player& mSnake, Barrier& mBarrier);

        void HasPlayerPassedBarrier(Player& mPlayer, Barrier& Barrier) noexcept;

        static PlayState* Instance() {
            return &m_PlayState;
        }

        //std::chrono::high_resolution_clock::timePoint1;
        //std::chrono::high_resolution_clock::timePoint2;

    private:
        static PlayState m_PlayState;

        enum /*class*/ SoundEffect : int {
            GET_POINT = 0,
            DEATH = 1,
            JUMP = 2
        };

        sf::Clock clock;
        sf::Time prevTime;

        Player m_player;
        Hud m_hud;

        std::vector<sf::Sound> m_sounds;
        std::vector<Barrier> m_barriers;

        bool m_isSoundEnabled;
        bool m_isGameRunning;
        bool m_playerProgress;

        int m_playerScore;
        int m_highScore;

        /*float lastFt;
        float currentSlice;
        static const float ftStep;
        static const float ftSlice;*/
    };
//}

#endif // PLAY_STATE_HPP
