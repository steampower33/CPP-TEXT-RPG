#pragma once

#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string name, int hp, int mp, int power, int defence);
	~Warrior();

	void Attack(Monster* monster) override;
};

