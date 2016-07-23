#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

#include "stateman\gameEngine.hpp"
#include "states\playState.hpp"

const std::string windowTitle = "Flappy Bird Clone";
constexpr int windowWidth{500};
constexpr int windowHeight{600};
constexpr int framesRate{60};

//using namespace SnakeGame;

int main()
{
    /*FlappyBird::*/GameEngine game{{windowWidth, windowHeight}, framesRate, windowTitle};

    game.ChangeState(/*FlappyBird::*/PlayState::Instance());

    // Game engine loop
    while (game.IsRunning()) {
        game.Run();
    }

    return 0;
}
