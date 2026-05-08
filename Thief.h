#pragma once

#include "Player.h"

class Thief : public Player
{
public:
	Thief(string name, int hp, int mp, int power, int defence);
	~Thief();

	void Attack(Monster* monster) override;
};

