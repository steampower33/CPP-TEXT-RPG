#include "Thief.h"
#include "Monster.h"

Thief::Thief(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Hp += 30;
	Job = "Thief";
	cout << "* You became a " << Job << "! (Hp + 30)\n";
	cout << "* Stabs dagger!\n";
	PrintPlayerStatus();
}

Thief::~Thief()
{
}

void Thief::Attack(Monster* monster)
{
	cout << "[Rogue] Stabs dagger!" << endl;

	int strikeCount = 5;

	int damage = (Power - monster->GetDefence()) / strikeCount;
	if (damage <= 0)
		damage = 1;

	int beforeMonsterHP = monster->GetHp();
	int afterMonsterHP = monster->GetHp() - damage * strikeCount;

	monster->SetHp(afterMonsterHP);

	string monsterName = monster->GetName();
	cout << " -> " << damage << " damage to " << monsterName << "(x" << strikeCount << ")" << endl;
	cout << monsterName << " HP: " << beforeMonsterHP << " -> " << monster->GetHp();
}
