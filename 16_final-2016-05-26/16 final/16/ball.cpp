#include "ball.h"


ball::ball(int ball_x, int ball_y)
{
	newball_x = ball_x;
	newball_y = ball_y;
	newcurr_player = NULL;
	newpre_player = NULL;
}

int ball::get_ballx()
{
	return newball_x;
}

int ball::get_bally()
{
	return newball_y;
}

void ball::set_ballx(int ball_x)
{
	newball_x = ball_x;
}

void ball::set_bally(int ball_y)
{
	newball_y = ball_y;
}

void ball::award(std::shared_ptr<player> newplayer)   //   -------------------------------------------------------  AWARD METHOD :
{                                                     //  This method takes a player as argument and sets the current player pointer to point to player.This player has the ball,and pre_player pointer points to previous current player.
    newpre_player = newcurr_player;
	newcurr_player = newplayer;
	
}
void ball::award(int field[][6],team * olympiakos,team * panathinaikos)      //----------------------------------------  AWARD METHOD :
{                                                                            // This award method is being called if no one has the ball.It searches for the player that is near to ball and gives to him the ball.
	int i,j,distance,min_i,min_j;                                           
	int min = 1000;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (field[i][j] == 1 || field[i][j] == 2)
			{
				distance= 10 * abs(this->get_ballx() - i) + abs(this->get_bally() - j);
				if (distance < min)
				{
					min = distance;
					min_i = i;
					min_j = j;
				}
			}
		}
	}
	this->set_ballx(min_i);
	this->set_bally(min_j);

	if (field[min_i][min_j]==1)
	{
		for (int k = 0; k < olympiakos->get_team().size(); k++)
		{

			if ((olympiakos->get_team())[k]->get_x() == min_i && (olympiakos->get_team())[k]->get_y() == min_j)
			{
				this->setpre_player(this->get_currplayer());
				this->setcurr_player(olympiakos->get_team()[k]);
			}
		}
	}
	else if (field[min_i][min_j]==2)
	{
		for (int k = 0; k < panathinaikos->get_team().size(); k++)
		{
			if ((panathinaikos->get_team())[k]->get_x() == min_i && (panathinaikos->get_team())[k]->get_y() == min_j)
			{
				this->setpre_player(this->get_currplayer());
				this->setcurr_player(panathinaikos->get_team()[k]);
			}
		}
	}
}

std::shared_ptr<player>  ball::get_currplayer()
{
	return newcurr_player;
}

std::shared_ptr<player>  ball::get_preplayer()
{
	return newpre_player;
}

void ball::setpre_player(std::shared_ptr<player> pre_player)
{
	newpre_player = pre_player;
}

void ball::setcurr_player(std::shared_ptr<player> currplayer)
{
	newcurr_player = currplayer;
}