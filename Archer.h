#pragma once

#include "Player.h"

class Archer : public Player
{
public:
	Archer(string name, int hp, int mp, int power, int defence);
	~Archer();

	void Attack(Monster* monster) override;
};

