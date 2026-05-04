#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"

class Monster;

using namespace std;

class Player
{
public:
	Player(string name, int hp, int mp, int power, int defence);
	virtual ~Player() {}

	void PrintPlayerStatus();

	virtual void Attack() = 0;

	string GetName() const { return Name; }
	string GetJob() const { return Job; }
	int GetLevel() const { return Level; }
	int GetHp() const { return Hp; }
	int GetMp() const { return Mp; }
	int GetPower() const { return Power; }
	int GetDefence() const { return Defence; }

	void SetName(const string& name) { Name = name; }
	void SetJob(int job) { Job = job; }
	void SetLevel(int level) { Level = level; }
	void SetHp(int hp) { Hp = hp; }
	void SetMp(int mp) { Mp = mp; }
	void SetPower(int power) { Power = power; }
	void SetDefence(int defence) { Defence = defence; }

protected:
	string Name;
	string Job;
	int Level;
	int Hp;
	int Mp;
	int Power;
	int Defence;
};