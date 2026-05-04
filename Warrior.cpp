#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Power += 30;
	Job = "Warrior";
	cout << "* You became a " << Job << "! (Power + 30)\n";
	cout << "* Wields a greatsword!\n";
	PrintPlayerStatus();
}

Warrior::~Warrior()
{
}

void Warrior::Attack()
{
	cout << "Strikes heavily with a greatsword!" << endl;
}
