#include "..\stateman\gameEngine.hpp"
#include "playState.hpp"

#include <iostream>
//#include <chrono>

#ifdef _WIN32
//#include <windows.h>
#endif

//const float PlayState::ftStep = 1.f;
//const float PlayState::ftSlice = 1.f;

PlayState PlayState::m_PlayState;

//using namespace FlappyBird;

PlayState::PlayState() :
    m_isSoundEnabled(true),
    m_playerProgress(false),
    m_playerScore(0),
    m_highScore(0),
    m_isGameRunning(true)
    //lastFt{0.f},
    //currentSlice{0.f}
{
    std::srand(time(0));

    prevTime = clock.getElapsedTime();
}

PlayState::~PlayState()
{

}

void PlayState::Init(GameEngine *game)
{
    m_engine = game;

    m_player.Init(game);
    m_hud.Init(m_engine);

    LoadResources();
    LoadObjects();

    NewGame();
}

void PlayState::Cleanup()
{

}

void PlayState::Pause()
{

}

void PlayState::Resume()
{

}

void PlayState::HandleEvents()
{
    //backgroundMusic.play();

    //timePoint1 = std::chrono::high_resolution_clock::now();

    sf::Event event;
    while (m_engine->GetWindow().pollEvent(event)) {
        if (event.type == sf::Event::LostFocus) {
            SetGameRunning(false);
        } else if (event.type == sf::Event::GainedFocus) {
            SetGameRunning(true);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N)) {
        NewGame();
    }

    if (!IsGameRunning()) {
        return;
    }

    m_player.HandleInput();

    for (auto& barrier : m_barriers) {
        if (!barrier.HasPlayerPassed()) {
            TestCollision(m_player, barrier);
            HasPlayerPassedBarrier(m_player, barrier);
            //break;
        }
    }

    //auto ftSeconds(ft / 1000.f);
    //auto fps(1.f / ftSeconds);

    //game->getWindow().setTitle(
    //    "FT: " + std::to_string(ft) + "\tFPS: " + to_string(fps));
}

void PlayState::Update()
{
    if (!IsGameRunning()) {
        return;
    }

    /*currentSlice += lastFt;
    for(; currentSlice >= ftSlice; currentSlice -= ftSlice) {*/
        //ball.update(/*ftStep, */game->getWindowSize());

    m_player.Update();

    for (auto& barrier : m_barriers) {
        barrier.Update();
    }

    //const int RANDOM_HORIZONTAL_DISTANCE_BETWEEN_BARRIERS = (std::rand() % static_cast<int>(m_engine->GetWindowSize().x) / 3) + static_cast<int>(m_engine->GetWindowSize().x) / 3;
    const int RANDOM_HORIZONTAL_DISTANCE_BETWEEN_BARRIERS = static_cast<int>(m_engine->GetWindowSize().x) / 2;
    if (abs(m_barriers.back().left() - m_engine->GetWindowSize().x) >= /*game->GetWindowSize().x / 4*/ RANDOM_HORIZONTAL_DISTANCE_BETWEEN_BARRIERS) {
        GenerateNewBarrier();
    }

    if (m_player.bottom() >= m_engine->GetWindowSize().y) {
        //if (IsSoundEnabled()) {
            m_sounds.at(DEATH).play();
        //}

        NewGame();
    }

    for (auto& barrier : m_barriers) {
        if (barrier.right() <= 0) {
            barrier.Destroy();
        }
    }

    // Remove destroyed barriers from barriers vector
    m_barriers.erase(
        remove_if(begin(m_barriers), end(m_barriers),
            [](const Barrier& mBarrier) { return mBarrier.IsDestroyed(); }),
        end(m_barriers)
    );
}

void PlayState::Draw()
{
    if (!IsGameRunning()) {
        return;
    }

    m_engine->GetWindow().clear(sf::Color::Blue);

    // Draw barriers
    for (auto& barrier : m_barriers) {
        m_engine->GetWindow().draw(barrier.shape);
    }

    // Draw player
    m_engine->GetWindow().draw(m_player.shape);

    // Draw HUD
    m_hud.DisplayHud(/*m_engine, */m_playerScore, m_highScore);

    m_engine->GetWindow().display();

    /*timePoint2 = std::chrono::high_resolution_clock::now();
    auto elapsedTime(timePoint2 - timePoint1);
    float ft{std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(
                     elapsedTime)
                     .count()};

    lastFt = ft;*/
}

/*
 * Starts a new game.
 */
void PlayState::NewGame()
{
    m_player.Reset();

    m_highScore = std::max(m_playerScore, m_highScore);
    m_playerScore = 0;

    m_barriers.clear();
    GenerateNewBarrier();
}

/*
 * Generates a new barrier.
 * A barrier consists of a top, a bottom and a vertical gap the player must travel through.
 */
void PlayState::GenerateNewBarrier()
{
    // Top barrier
    const int TOP_BARRIER_HEIGHT = (std::rand() % (static_cast<int>(m_engine->GetWindowSize().y - 200)) + 80);
    m_barriers.emplace_back(m_engine, sf::Vector2f{static_cast<int>(m_engine->GetWindowSize().x) + 30 / 2, TOP_BARRIER_HEIGHT / 2},
        sf::Vector2f{60, TOP_BARRIER_HEIGHT});

    // Bottom barrier
    const int BOTTOM_BARRIER_HEIGHT = static_cast<int>(m_engine->GetWindowSize().y) - TOP_BARRIER_HEIGHT - 150;
    m_barriers.emplace_back(m_engine, sf::Vector2f{static_cast<int>(m_engine->GetWindowSize().x) + 30 / 2, m_engine->GetWindowSize().y - BOTTOM_BARRIER_HEIGHT / 2},
        sf::Vector2f{60, BOTTOM_BARRIER_HEIGHT + 50});
}

template <class T1, class T2>
bool PlayState::IsIntersecting(T1& mA, T2& mB)
{
    return mA.right() >= mB.left() && mA.left() <= mB.right()
        && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void PlayState::TestCollision(Player& mPlayer, Barrier& mBarrier)
{
    //std::cout << "PlayState testCollision() paddle" << std::endl;

    if (!IsIntersecting(mPlayer, mBarrier)) {
        return;
    }

    //mBarrier.Destroy();
    //std::cout << "collision" << std::endl;

    NewGame();

    //if (IsSoundEnabled()) {
        m_sounds.at(SoundEffect::DEATH).play();
    //}
}

void PlayState::HasPlayerPassedBarrier(Player& mPlayer, Barrier& mBarrier) noexcept
{
    if (mPlayer.left() >= mBarrier.right()) {
        if (!mBarrier.HasPlayerPassed()) {
            mBarrier.SetPlayerPassed(true);
            GainPoints(1);
            //if (IsSoundEnabled()) {
                m_sounds.at(SoundEffect::GET_POINT).play();
            //}
        }
    }
}

void PlayState::LoadResources()
{
    // Set up sounds vector
    for (int i{0}; i < 3; i++) {
        m_sounds.emplace_back(sf::Sound());
    }

    m_sounds.at(SoundEffect::GET_POINT).setBuffer(m_engine->resourceMan.GetSound("get_point.wav"));
    m_sounds.at(SoundEffect::DEATH).setBuffer(m_engine->resourceMan.GetSound("death.wav"));
    m_sounds.at(SoundEffect::JUMP).setBuffer(m_engine->resourceMan.GetSound("jump.wav"));

    //LoadObjects();
}

void PlayState::LoadObjects()
{

}
