
#include "Monster.h"
#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence)
	: Name(name), Hp(hp), Mp(mp), Power(power), Defence(defence)
{
	Level = 1;
}

void Player::PrintPlayerStatus()
{
	cout << "------------------------------------\n";
	cout << "Name: " << Name << " | Job: " << Job << " | Lv." << Level << endl;
	cout << "HP: " << Hp << " | MP: " << Mp;
	cout << " | Power: " << Power << " | Defense: " << Defence << endl;
	cout << "------------------------------------\n";
}