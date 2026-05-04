#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player;

class Monster
{
public:
	Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemValue);
	~Monster();

	void Attack(Player* player);

	string GetName() const { return Name; }
	int GetHp() const { return Hp; }
	int GetPower() const { return Power; }
	int GetDefence() const { return Defence; }
	string GetDropItemName() const { return DropItemName; }
	int GetDropItemValue() const { return DropItemValue; }

	void SetName(const string& name) { Name = name; }
	void SetHp(int hp) { Hp = hp; }
	void SetPower(int power) { Power = power; }
	void SetDefence(int defence) { Defence = defence; }
	void SetDropItemName(const string& dropItemName) { DropItemName = dropItemName; }

private:
	string Name;
	int Hp;
	int Power;
	int Defence;
	string DropItemName;
	int DropItemValue;
};

