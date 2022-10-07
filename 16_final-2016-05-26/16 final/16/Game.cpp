#include "Game.h"

Game::Game()
{
}

Game::Game(team * team1,team * team2,ball * ball)
{
	newteam1 = team1;
	newteam2 = team2;
	newball = ball;
}


Game::~Game()
{
}
int count = 0;
int thesi_x, thesi_y;
void Game::runturn(int field[][6])
{
	
	if (newturn == 0)
	{
		thesi_x = newball->get_ballx();
		thesi_y = newball->get_bally();
	}
	newteam1->action(field, newball);
	newteam2->action(field, newball);
	newturn++;
	if (thesi_x == newball->get_ballx() && thesi_y == newball->get_bally() && newball->get_currplayer()==NULL)
	{
		count++;
	}
	else
	{
		count = 1;
		thesi_x = newball->get_ballx();
		thesi_y = newball->get_bally();
	}
	if (count > 5)
	{
		count = 1;
		newball->award(field, newteam1, newteam2);
	}
	int random=Random5();
	if (random == 0)
	{
		if ((newball->get_ballx() == 8 || newball->get_ballx() == 9) && (newball->get_bally() >= 1 && newball->get_bally() <= 4) && field[newball->get_ballx()][newball->get_bally()] == 0)
		{
			this->newteam1->set_goals();
		}
		else if ((newball->get_ballx() == 0 || newball->get_ballx() == 1) && (newball->get_bally() >= 1 && newball->get_bally() <= 4) && field[newball->get_ballx()][newball->get_bally()] == 0)
		{
			this->newteam2->set_goals();
		}
	}
	else
	{
		if (field[newball->get_ballx()][newball->get_bally()] == 0)
		newball->award(field,newteam1,newteam2);
	}
		std::cout << "the position of the ball is " << newball->get_ballx()<<","<<newball->get_bally()<<std::endl;
}

int Game::get_turn()
{
	return newturn;
}

void Game::print_turn()     // This method prints the number of turns
{
	std::cout <<"The number of turns is:" <<this->get_turn()<<std::endl;
}