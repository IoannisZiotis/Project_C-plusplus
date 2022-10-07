#include <iostream>
#include <fstream>
#include "defender.h"
#include "striker.h"
#include "team.h"
#include <vector>
#include <sstream>
#include <string>
#include "Random.h"
#include "Game.h"
#include <time.h>
#include <ctime>



extern int steals;                   // variable that represents all steals in the game
void print_field(int field[10][6]);  // 2d array that represents the field
void print_steals();                 // function that prints the variable steals


int main()
{
	int field[10][6];
	srand(time(NULL));
	int i, j;
	for (i = 0; i < 10; i++)      // field's initialization with zero
	{
		for (j = 0; j < 6; j++)
		{
			field[i][j] = 0;
		}
	}
	std::vector <std::vector <std::string> > data;     // vector
	std::ifstream infile("C:\players.txt");            // read from file
	std::vector <std::shared_ptr<player>> team1;      // vector with pointer's
	std::vector <std::shared_ptr<player>> team2;      
	while (infile)                                  //                                PASSING
	{                                               //                                  
		std::string s;                              //                                FILE'S
		if (!getline(infile, s)) break;             //                                                           
		                                            //                                DATA
		std::istringstream ss(s);                   //                                 
		std::vector <std::string> record;           //                                INTO
		                                            //                                     
		while (ss)                                  //                                A
		{                                           //
			std::string s;                          //                                VECTOR
			if (!getline(ss, s, '|')) break;        //
			record.push_back(s);                    //
		}

		data.push_back(record);
	}
	for (i = 0; i<16; i++)
	{
		if (data[i][1]=="defender" && i<=7)
		{
			team1.push_back(std::make_shared<defender> (std::stoi(data[i][3]), std::stoi(data[i][4]), std::stoi(data[i][5]), std::stoi(data[i][6]), data[i][0], std::stoi(data[i][2]),0));
			field[std::stoi(data[i][3])][std::stoi(data[i][4])] = 1;
		} 
		else if (data[i][1] == "defender" && i > 7)
		{	
			team2.push_back(std::make_shared<defender> (std::stoi(data[i][3]), std::stoi(data[i][4]), std::stoi(data[i][5]), std::stoi(data[i][6]), data[i][0], std::stoi(data[i][2]),1));
			field[std::stoi(data[i][3])][std::stoi(data[i][4])] = 2;
		}
		else if (data[i][1] == "striker" && i <= 7)
		{	
			team1.push_back(std::make_shared<striker> (std::stoi(data[i][3]), std::stoi(data[i][4]), std::stoi(data[i][5]), std::stoi(data[i][6]), data[i][0], std::stoi(data[i][2]),0));
			field[std::stoi(data[i][3])][std::stoi(data[i][4])] = 1;
		}
		else
		{
			team2.push_back(std::make_shared<striker> (std::stoi(data[i][3]), std::stoi(data[i][4]), std::stoi(data[i][5]), std::stoi(data[i][6]), data[i][0], std::stoi(data[i][2]),1));
			field[std::stoi(data[i][3])][std::stoi(data[i][4])] = 2;
		}
	}


	team olympiakos(team1,"olympiakos");                           //creation of object type team
	team panathinaikos(team2, "panathinaikos");
	ball newball(Random2(0,9),Random2(0,5));                                             // creation of object type ball
	Game game(&olympiakos, &panathinaikos, &newball);        

	while (olympiakos.get_goals()<7 && panathinaikos.get_goals()<7 )    // The game ends if one team scores 7 goals
	{                                                                    
		std::cout <<"Guros: "<< game.get_turn()<<"\n";
		game.runturn(field);                                           // method that does the main event
		print_field(field);                                            // function that prints field
		print_steals();                                                
		game.print_turn();                                             // method that prints number of turns       
		olympiakos.print_goals();                                      // method that prints goals of first team
		panathinaikos.print_goals();                                   // method that prints goals of second team
		olympiakos.print_passes();                                     // method that prints first team's passes 
		panathinaikos.print_passes();                                  // method that prints second team's passes
		olympiakos.print_mistakes("panathinaikos");                    // method that prints first team's mistakes
		panathinaikos.print_mistakes("olympiakos");                    // method that prints second team's mistakes 
		olympiakos.print_team();
		panathinaikos.print_team();
	}
	olympiakos.set_mistperc(((float)(panathinaikos.get_mistakes() / ((float)olympiakos.get_passes()+(float)panathinaikos.get_mistakes())) * 100));
	std::cout << "First team's mistake percentage is :" << olympiakos.get_mistperc() << std::endl;
	panathinaikos.set_mistperc(((float)(olympiakos.get_mistakes() / ((float)panathinaikos.get_passes()+(float)olympiakos.get_mistakes())) * 100));
	std::cout << "Second team's mistake percentage is :" << panathinaikos.get_mistperc() << std::endl;
	olympiakos.set_passesperc(((float)(olympiakos.get_passes() / ((float)olympiakos.get_passes() + (float)panathinaikos.get_mistakes())) * 100));
	std::cout << "First team's successful passes percentage is :" << olympiakos.get_passesperc() << std::endl;
	panathinaikos.set_passesperc(((float)(panathinaikos.get_passes() / ((float)panathinaikos.get_passes() + (float)olympiakos.get_mistakes())) * 100));
	std::cout << "Second team's successful passes percentage is :" << panathinaikos.get_passesperc() << std::endl;
	
	if (!infile.eof())
	{
		std::cerr << "ok!\n";
	}
	system("pause");
}

void print_field(int field[][6])
{
	for (int k = 0; k < 10; k++)
	{
		for (int j = 0; j < 6; j++)
			std::cout << field[k][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_steals()
{
	std::cout <<"The number of steals is:" <<steals << std::endl;
}