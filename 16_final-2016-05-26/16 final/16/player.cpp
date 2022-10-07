#include "player.h"
#include "Random.h"

player::player()
{}

player::~player()
{
	
}

//player::player(int x, int y, int mov_line, int target_line, std::string name, int number)
//{
//	new_x = x;
//	new_y = y;
//	new_movline = mov_line;
//	new_targetline = target_line;
//	new_number = number;
//	new_name = name;
//}

std::string player::get_name()     // Method that returns player's name
{
	return new_name;
}

int player::get_x()               // Method that returns player's  x
{
	return new_x;
}
int player::get_y()               // Method that returns player's y
{
	return new_y;
}
int player::get_movline()       // Method that returns player's movement line
{
	return new_movline;
}
int player::get_targetline()   // Method that returns player's targetline(line that he is able to pass the ball)
{
	return new_targetline;
}
void player::set_x(int x)
{
	new_x = x;
}
void player::set_y(int y)
{
	new_y = y;
}
int player::movement(int flag)        //                                   MOVEMENT   METHOD :
{                                     //   Moves the player one position right or left.If this player has the ball he moves him with the ball. 
	int y = this->get_y();            //   After that , ball's position is changed so as player's position.
	if (flag == 0)                    //   To decide in which direction player is going to move we use a random value that is been produced by a random function.
	{                                 //
		y++;                          //
		this->set_y(y);               //
	}                                 //
	else                              //
	{                                 //
		y--;	                      //
		this->set_y(y);               //
	}                                 //
	return y;                         //
}
void player::pass_ball(int target_line,ball * newball)   //                  PASS BALL  METHOD :
{                                                        //  The player that has the ball passes the ball into a random place of a specific line.
	int y = Random2(0, 6);                               //   
 	newball->set_ballx(target_line);                     //
	newball->set_bally(y);                               //
}
