#include "striker.h"


striker::striker()
{
}


striker::~striker()
{
}

striker::striker(int x, int y, int mov_line, int target_line, std::string name, int number,int teamnum)
{
	new_x = x;
	new_y = y;
	new_movline = mov_line;
	new_targetline = target_line;
	new_name = name;
	new_number = number;
	
}

void striker::pass_ball(int target_line,ball * newball)     // Pass ball for striker:
{                                                           // If striker has the ball he will shoot the ball  in the middle columns.This depends.We use a random function that  
	int y = Random3();                                      // returns a middle column place with 70% probability.
	if (y = 0)
	{
		newball->set_ballx(target_line);
		newball->set_bally(Random2(2,3));
	}
	else
	{
		newball->set_ballx(target_line);
		newball->set_bally(Random2(Random2(0, 1),Random2(4,5)));
	}
}

// ---------------------------------------------------------------- SPECIAL MOVEMENT FOR STRIKER -----------------------------------------------------------------
int striker::special_mov(ball * newball, int field[][6])
{
	int newy=0, y = 0, distance2=0, distance1=0;
	if (field[(*newball->get_currplayer()).get_x()][(*newball->get_currplayer()).get_y()] == field[this->get_x()][this->get_y()])
	{
		if (field[this->get_x()][this->get_y()] == 1)//proti omada                              // Special movement for striker:
		{                                                                                       // Check's if someone in his team has the ball.If it is striker will move 2 positions away from the closest opponent.
			for (y = 0; y < this->get_y(); y++)                                                 // 
			{

				if (field[this->get_x()][y] == 2)
				{
					distance1 = this->get_y() - y;
				}
			}
			for (y = this->get_y() + 1; y < 6; y++)
			{
				if (field[this->get_x()][y] == 2)
				{
					distance2 = y - this->get_y();
				}
			}
			if (distance1 < distance2)
			{
				newy = this->get_y() + 2;

				if (this->get_y() + 2 <= 5 && field[this->get_x()][this->get_y() + 2] == 0)
				{
						field[this->get_x()][this->get_y()] = 0;
						field[this->get_x()][this->get_y() + 2] = 1;
					
				}
				else
					newy = this->get_y();
			}
			else
			{
				/*  ---------- What happens if the new position has another player?? -----------        */
				/*------------ Temporary solution stays in the same place -----------------------------*/
				newy = this->get_y() - 2;
				

				if (this->get_y() - 2 >=0 && field[this->get_x()][this->get_y() - 2] == 0)
				{
					field[this->get_x()][this->get_y()] = 0;
					field[this->get_x()][this->get_y() - 2] = 1;

				}
				else
					newy = this->get_y();
			}
		}
		if (field[this->get_x()][this->get_y()] == 2)//2h omada
		{
			for (y = 0; y < this->get_y(); y++)
			{
				if (field[this->get_x()][y] == 1)
				{
					distance1 = this->get_y() - y;
				}
			}
			for (y = this->get_y() + 1; y < 6; y++)
			{
				if (field[this->get_x()][y] == 1)
				{
					distance2 = y - this->get_y();
				}
			}
			if (distance1 < distance2)
			{
				newy = this->get_y() + 2;

				if (this->get_y() + 2 <= 5 && field[this->get_x()][this->get_y() + 2] == 0)
				{
					field[this->get_x()][this->get_y()] = 0;
					field[this->get_x()][this->get_y() + 2] = 2;

				}
				else
					newy = this->get_y();
			}
		
			else
			{
				newy = this->get_y() - 2;


				if (this->get_y() - 2 >= 0 && field[this->get_x()][this->get_y() - 2] == 0)
				{
					field[this->get_x()][this->get_y()] = 0;
					field[this->get_x()][this->get_y() - 2] = 2;

				}
				else
					newy = this->get_y();
			}
		}
		this->set_y(newy);

	}
	return 0;
}