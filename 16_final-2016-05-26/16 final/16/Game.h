#pragma once
#include "team.h"
#include "Random.h"
class Game
{
public:
	Game();
	Game(team *,team *,ball *);
	virtual ~Game();
	int newturn=0;
	void runturn(int field[][6]);
	int get_turn();
	void print_turn();
protected:
private:
	
	team * newteam1;
	team * newteam2;
	ball * newball;
	
};