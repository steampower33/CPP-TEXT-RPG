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

void Magician::Attack(Monster* monster)
{
	cout << "[Mage] Fires fireball!" << endl;

	int damage = Power - monster->GetDefence();
	if (damage <= 0)
		damage = 1;

	int beforeMonsterHP = monster->GetHp();
	int afterMonsterHP = monster->GetHp() - damage;

	monster->SetHp(afterMonsterHP);

	string monsterName = monster->GetName();
	cout << " -> " << damage << " damage to " << monsterName << endl;
	cout << monsterName << " HP: " << beforeMonsterHP << " -> " << monster->GetHp();
}
