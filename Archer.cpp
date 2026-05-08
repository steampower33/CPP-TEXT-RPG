#include "Archer.h"
#include "Monster.h"

Archer::Archer(string name, int hp, int mp, int power, int defence)
	: Player(name, hp, mp, power, defence)
{
	Defence += 30;
	Job = "Archer";
	cout << "* You became a " << Job << "! (Defence + 30)\n";
	cout << "* Shoots arrow!\n";
	PrintPlayerStatus();
}

Archer::~Archer()
{
}

void Archer::Attack(Monster* monster)
{
	cout << "[Archer] Shoots arrow!" << endl;

	int strikeCount = 3;

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
