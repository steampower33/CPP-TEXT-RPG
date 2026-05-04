#include "Archer.h"
#include "Monster.h"

Archer::Archer(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Defence += 30;
	Job = "Archer";
	cout << "* You became a " << Job << "! (Defence + 30)\n";
	cout << "* Shoot an arrow!\n";
	PrintPlayerStatus();
}

Archer::~Archer()
{
}

void Archer::Attack()
{
	cout << "Shoots a deadly arrow!" << endl;
}
