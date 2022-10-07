#pragma once
#ifndef BALL_H
#define BALL_H
#include <memory>
class team;
#include "team.h"
//class player;
//#include "player.h"

class ball
{
public:
	

	void award(std::shared_ptr<player>);
	void award(int field[][6],team*,team*);
	void set_ballx(int);
	void set_bally(int);
	int get_ballx();
	int get_bally();
	ball(int, int);
	void setpre_player(std::shared_ptr<player>);
	void setcurr_player(std::shared_ptr<player>);
	std::shared_ptr<player> get_currplayer();
	std::shared_ptr<player> get_preplayer();
protected:

private:
	
	int newball_x, newball_y;
    std::shared_ptr<player>  newcurr_player;
	std::shared_ptr<player> newpre_player;
};
#endif