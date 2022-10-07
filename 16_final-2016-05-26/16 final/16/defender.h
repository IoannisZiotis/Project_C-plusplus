#pragma once
#include "player.h"
#include <cmath> 


class defender : public player
{
public:
	
	defender();
	 ~defender();
	 int special_mov(ball *,int field[][6]) ;
	defender(int, int, int, int, std::string, int,int);
	void set_yellowcard(bool);
	bool get_yellowcard(void);


protected:
	bool new_yellowcard;
	
	
};