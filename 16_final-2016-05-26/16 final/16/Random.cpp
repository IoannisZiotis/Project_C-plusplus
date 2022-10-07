
#include "Random.h"
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
int Random()
{
	
	double val = (double)rand() / RAND_MAX;

	int random;
	if (val < 0.30)       //  5%
		random = 0;
	else if (val < 0.65)  //  5% + 20%
		random = 1;
	else   //  5% + 20% + 30%
		random = 2;
	return random;
}

int Random2(int base, int lim)
{
	int num;
	// Get a pseudo-random number in [base,lim]
	if (lim == 1 && base == 0)
	{
		lim++;
		num = (rand() % lim + base);

	}
	else
	{
		num = (rand() % lim - 1 + base) + 1;

	}

	return num;
}

int Random3()
{
	double val = (double)rand() / RAND_MAX;

	int random;
	if (val < 0.70)       //  5%
		random = 0;
	else
		random = 1;
	return random;
}

int Random4()
{
	double val = (double)rand() / RAND_MAX;

	int random;
	if (val < 0.10)      
		random = 0;
	else if (val < 0.90)
		random = 1;
	else
		random= 3;
	return random;
}

int Random5()
{
	double val = (double)rand()/RAND_MAX;

	int random;
	if (val < 0.80)       
		random = 0;
	else
		random = 1;
	return random;
}