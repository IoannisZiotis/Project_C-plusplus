#pragma once
class player;//
#include "player.h"
#include <vector>
#include "Random.h"
//#include "ball.h"
//class defender;
//#include "defender.h"

#include <memory>

class team
{
public:
	team();
	team(std::vector <std::shared_ptr<player>>,std::string);
	virtual ~team();
	int new_mistakes = 0;
	int new_passes = 0;
	int new_goals=0;
	float new_mist_perc,new_passesperc;
	 void action(int kappa[][6],ball * newball);
	 std::vector<std::shared_ptr<player>> get_team();
	 void set_passes();
	 void set_mistakes();
	 void set_goals();
	 void set_mistperc(float);
	 void set_passesperc(float);
	 int get_goals();
	 int get_mistakes();
	 int get_passes();
	 float get_mistperc();
	 float get_passesperc();
	 void print_goals();
	 void print_mistakes(std::string);
	 void print_passes();
	 void print_team();
private:
	std::vector<std::shared_ptr<player>> new_team;
	std::vector<std::shared_ptr<player>> pteam;
	std::string new_teamname;
	int newteam_num;
};


