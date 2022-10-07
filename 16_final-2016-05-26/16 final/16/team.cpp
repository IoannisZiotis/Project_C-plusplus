#include "team.h"


team::team()
{
}


team::~team()
{
}

team::team(std::vector<std::shared_ptr<player>> team,std::string team_name)   // Team's constructor
{
	int i;
	for ( i = 0; i < team.size(); i++)
		new_team.push_back(team[i]);
	new_teamname = team_name;
	new_goals = 0;
	new_mistakes = 0;
	new_passes = 0;
}


void team::action(int field[][6],ball * newball)                                             // ------------------------------------------------------------------------------------------------------------------------------------------------                         ACTION   METHOD :                                
{                                                                                            //     This method calls movement method or pass ball or special movement for each player.  
	int i, j = 0, flag,count =0,thesi_x=newball->get_ballx(),thesi_y=newball->get_bally();
	for (i = 0; i < this->new_team.size(); ++i)
	{
		if (Random() == 0)//movement                                                         //      Movement method                                                                                                                                                                                                           
		{
			(this->new_team[i])->get_x();
			if ((this->new_team[i])->get_y() == 0 && field[(this->new_team[i])->get_x()][this->new_team[i]->get_y() + 1] != 1 && field[(this->new_team[i])->get_x()][this->new_team[i]->get_y() + 1] != 2)  // Check's if the player is located at the first column of field 
			{
				if (field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] == 1)                                                                                                                     // Check's if he is  a first team's player       
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))                                                                         // Check's if the player has the ball
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 1;                                                                                                              // Move's the player with movement method 
						newball->set_bally(this->new_team[i]->get_y());	                                                                                                                                    // Move's the ball.	
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 1;
					}
				}
				else                                                                                                                                                                                        // Check's if he is  a second team's player        
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 2;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 2;
					}

				}
			

			}
			else if (this->new_team[i]->get_y() == 5 && field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] != 1 && field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] != 2)     // Check's if the palyer is located at last columnt of field                                                                      
			{
				
				if (field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] == 1)
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{

						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 1;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 1;
					}
				}
				else
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 2;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 2;
					}

				}
				field[this->new_team[i]->get_x()][this->new_team[i]->get_y() + 1] = 0;
			}
			else if (this->new_team[i]->get_y() != 0 && this->new_team[i]->get_y() != 5 && (field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] == 1 || field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] == 2))
			{
	
				if (field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] == 1)
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 1;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 1;
					}
				}
				else
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 2;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(0)] = 2;
					}
				}
				field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] = 0;
			}
			else if (this->new_team[i]->get_y() != 0 && this->new_team[i]->get_y() != 5 && (field[this->new_team[i]->get_x()][this->new_team[i]->get_y() + 1] == 1 || field[this->new_team[i]->get_x()][this->new_team[i]->get_y() + 1] == 2))
			{
				if (field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] == 1)
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 1;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 1;
					}
				}
				else
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 2;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(1)] = 2;
					}

				}
				field[this->new_team[i]->get_x()][this->new_team[i]->get_y() + 1] = 0;
			}
			else if (this->new_team[i]->get_y() != 0 && this->new_team[i]->get_y() != 5)
			{
				flag = Random2(0, 1);
				if (field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] == 1)
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(flag)] = 1;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(flag)] = 1;
				}
				else
				{
					if ((newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y()))
					{
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(flag)] = 2;
						newball->set_bally(this->new_team[i]->get_y());
					}
					else
						field[this->new_team[i]->get_x()][this->new_team[i]->movement(flag)] = 2;

				}
				if (flag == 0)
				{
					field[this->new_team[i]->get_x()][this->new_team[i]->get_y() - 1] = 0;
				}
				else
				{
					field[this->new_team[i]->get_x()][this->new_team[i]->get_y() + 1] = 0;
				}
			}
		}
		else if (Random() == 1)//pass ball
		{
			
			
			if (this->new_team[i]->get_x() == newball->get_ballx() && this->new_team[i]->get_y() == newball->get_bally())
			{
				this->new_team[i]->pass_ball(this->new_team[i]->get_targetline(), newball);
				newball->setpre_player(newball->get_currplayer());
				std::shared_ptr<player> ptr = NULL;
				newball->setcurr_player(ptr);
			}
				
		}
		else // special movement                                     
		{                                                                                                 
			if (newball->get_currplayer() != NULL)                        
			{
				
				/*this->new_team[i]->special_mov(newball, field);*/

				if (this->new_team[i]->special_mov(newball, field) == 1)    // Check's if player has two yellow cards.If that happens he is going to be removed from the game.
				{
			//		field[this->new_team[i]->get_x()][this->new_team[i]->get_y()] = 0;
	//				*this->new_team.erase(this->new_team.begin()+(i-1));
				}
			}
		}
		
		//award
		if (newball->get_currplayer() == NULL)
		{
			if (abs(this->new_team[i]->get_x() - newball->get_ballx()) == 1 && abs((this->new_team[i]->get_y() - newball->get_bally()) == 1) || (abs(this->new_team[i]->get_x() - newball->get_ballx()) == 0 && abs((this->new_team[i]->get_y() - newball->get_bally()) == 0)))
			{
				newball->award(this->new_team[i]);	
			}
			if (newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y())
			{
				newball->award(this->new_team[i]);
			}

		}
		if (newball->get_ballx() == this->new_team[i]->get_x() && newball->get_bally() == this->new_team[i]->get_y())
		{
			newball->award(this->new_team[i]);
		}
		if (newball->get_preplayer() != NULL &&newball->get_currplayer()!=NULL)
		{
			if (field[(newball->get_currplayer())->get_x()][newball->get_currplayer()->get_y()] == field[newball->get_preplayer()->get_x()][newball->get_preplayer()->get_y()])
			{
				this->set_passes();
				newball->setpre_player(NULL);
			}
			else
			{
				this->set_mistakes();
				newball->setpre_player(NULL);
			}
		}
		
		

	}
}

std::vector<std::shared_ptr<player>> team::get_team()
{
	return new_team;
}
void team::set_passes()
{
	new_passes++;
}
void team::set_mistakes()
{
	new_mistakes++;
}
void team::set_goals()
{
	new_goals++;
}
int team::get_goals()
{
	return new_goals;
}
float team::get_mistperc()
{
	return new_mist_perc;
}

void team::set_mistperc(float x)
{
	new_mist_perc = x;
}
int team::get_passes()
{
	return new_passes;
}
int team::get_mistakes()
{
	return new_mistakes;
}

void team::set_passesperc(float x)
{
	new_passesperc = x;
}
float team::get_passesperc()
{
	return new_passesperc;
}
void team::print_goals()
{
	std::cout << "The number of goals of " << this->new_teamname << " is:" << this->get_goals()<<std::endl;
}
void team::print_mistakes(std::string name)
{
	std::cout << "The number of mistakes of " << name << " is:" << this->get_mistakes() << std::endl;
}
void team::print_passes()
{
	std::cout << "The number of passes of " << this->new_teamname << " is:" << this->get_passes() << std::endl;
}

void team::print_team()
{
	for (int i = 0; i < this->new_team.size(); i++)
	{
		std::cout << this->new_team[i]->get_name() << std::endl;
		std::cout << "the position of "  << this->new_team[i]->get_name() <<" is "<< this->new_team[i]->get_x() <<","<< this->new_team[i]->get_y()<<std::endl;
		std::cout << "his target line is: " << this->new_team[i]->get_targetline() << " and his movement line is: " << this->new_team[i]->get_movline() << std::endl << std::endl;
	}
}