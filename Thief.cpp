#include "Thief.h"
#include "Monster.h"

Thief::Thief(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Hp += 30;
	Job = "Thief";
	cout << "* You became a " << Job << "! (Hp + 30)\n";
	cout << "* Quickly thrust with a dagger!\n";
	PrintPlayerStatus();
}

Thief::~Thief()
{
}

void Thief::Attack()
{
	cout << "Attempts rapid consecutive stabs with a dagger!" << endl;
}
