#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Power += 30;
	Job = "Warrior";
	cout << "* You became a " << Job << "! (Power + 30)\n";
	cout << "* Swings sword!\n";
	PrintPlayerStatus();
}

Warrior::~Warrior()
{
}

void Warrior::Attack(Monster* monster)
{
	cout << "[Warrior] Swings sword!" << endl;

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
