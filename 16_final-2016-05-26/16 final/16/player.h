#pragma once

#include "Random.h"
#include <string>
#include <iostream>
class ball;
#include  "ball.h"

class player
{
protected:
	int new_x, new_y, new_number, new_movline, new_targetline;
	std::string new_name;
public:
	virtual int movement(int);
	virtual void pass_ball(int,ball *);
	virtual int special_mov(ball *,int field[][6]) =0 ;
	void set_x(int);
	void set_y(int);
	int get_x();
	int get_y();
	int get_movline();
	int get_targetline();
	
	std::string get_name();
	player();
	/*player(int, int, int, int, std::string, int);*/
	virtual ~player();
	
private:
};

