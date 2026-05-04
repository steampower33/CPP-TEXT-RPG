#include "Magician.h"
#include "Monster.h"

Magician::Magician(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Mp += 30;
	Job = "Magician";
	cout << "* You became a " << Job << "! (Mp + 30)\n";
	cout << "* Fires a fireball!\n";
	PrintPlayerStatus();
}

Magician::~Magician()
{
}

void Magician::Attack()
{
	cout << "Casts a fireball!" << endl;
}
