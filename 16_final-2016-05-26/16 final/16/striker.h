#pragma once
#include "player.h"


class striker : public player
{
public:
	striker();
	virtual ~striker();
	striker(int, int, int, int, std::string, int,int);
	void pass_ball(int,ball *);
	int special_mov( ball *,int field[][6]);
	
	
protected:

	
};