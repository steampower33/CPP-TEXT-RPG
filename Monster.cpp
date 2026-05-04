
#include "Monster.h"
#include "Player.h"

Monster::Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemValue)
	: Name(name), Hp(hp), Power(power), Defence(defence), DropItemName(dropItemName), DropItemValue(dropItemValue)
{
}

Monster::~Monster()
{
}

void Monster::Attack(Player* player)
{
	cout << "Spraying strong acidic liquid!" << endl;
	int damage = GetPower() - player->GetDefence();
	if (damage <= 0)
		damage = 1;

	string playerName = player->GetName();
	cout << damage << " damage to " << playerName << endl;
	int beforePlayerHP = player->GetHp();
	player->SetHp(beforePlayerHP - damage);
	cout << playerName << " HP: " << beforePlayerHP << " -> " << player->GetHp();
	if (player->GetHp() <= 0)
	{
		cout << "(Dead)" << endl;
		cout << "★ Defeat!" << endl;
	}
	else
		cout << "\n";
}
