#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "..\stateman\gameEngine.hpp"

//using namespace SnakeGame;

class GameEngine;

//namespace SnakeGame
//{
	class GameState
	{
	public:
	    GameState();
	    ~GameState();

	    virtual void Init(GameEngine *game);
	    virtual void Cleanup(/*GameEngine *game*/);

	    virtual void Pause() = 0;
	    virtual void Resume() = 0;

	    virtual void HandleEvents(/*GameEngine *game*/)/* = 0*/;
	    virtual void Update(/*GameEngine *game*/)/* = 0*/;
	    virtual void Draw(/*GameEngine *game*/)/* = 0*/;
	    virtual void LoadResources(/*GameEngine *game*/)/* = 0*/;
	    virtual void LoadObjects()/* = 0*/;

	    GameEngine *m_engine;
	};
//}

#endif // GAME_STATE_HPP
