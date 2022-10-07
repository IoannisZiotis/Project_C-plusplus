#include "defender.h"
#include <time.h>
#include <ctime>
#include <cstdlib>
int steals = 0;
defender::defender()
{
}


defender::~defender()
{
}

defender::defender(int x,int y,int mov_line,int target_line,std::string name,int number,int teamnum)
{
	new_x = x;
	new_y = y;
	new_movline = mov_line;
	new_targetline = target_line;
	new_name = name;
	new_number = number;
	new_yellowcard = 0;
	
}


bool defender::get_yellowcard()
{
	return new_yellowcard;
}

void defender::set_yellowcard(bool yellowcard)
{
	new_yellowcard = yellowcard;
}
// -------------------------------------------------------------- SPECIAL MOVEMENT FOR DEFENDER ------------------------------
int defender::special_mov(ball * newball,int field[][6])                                                                                                                                                                                                                             
{
	if (abs(this->get_x() - (*newball->get_currplayer()).get_x()) == 1 && abs((this->get_y() - (*newball->get_currplayer()).get_y()) == 1) && field[this->get_x()][this->get_y()]!=field[(*newball->get_currplayer()).get_x()][(*newball->get_currplayer()).get_y()])
	{
		int num = Random4();                                   //  Special movement:
		if (num == 1)                                          //  Check's if there is a player with the ball in near position.If it exists this player is going to steal the ball 
			                                                   //  or he will get a yellow card.If he steals the ball we increase steals by 1 and we change ball's position.
		{
			newball->set_ballx(this->get_x());
			newball->set_bally(this->get_y());
			++steals;
			return 0;
		}
		else if (num == 0)
		{
			if (this->get_yellowcard() == 0)
			{
				this->set_yellowcard(1);
				return 0;
			}
		}
		else
		{
			std::cout << " efige" << std::endl;
			return 1;
		}	
	}	
}

