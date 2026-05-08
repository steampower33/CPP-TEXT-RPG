#pragma once

#include <iostream>
#include <string>
#include <vector>

class Monster;

using namespace std;

class Player
{
public:
	Player(string name, int hp, int mp, int power, int defence);
	virtual ~Player() {}

	void PrintPlayerStatus();

	virtual void Attack(Monster* monster) = 0;

	string GetName() const { return Name; }
	string GetJob() const { return Job; }
	int GetLevel() const { return Level; }
	int GetHp() const { return Hp; }
	int GetMaxHp() const { return MaxHp; }
	int GetMaxMp() const { return MaxMp; }
	int GetMp() const { return Mp; }
	int GetPower() const { return Power; }
	int GetDefence() const { return Defence; }
	int GetExp() const { return Exp; }
	int GetMaxExp() const { return MaxExp; }

	void SetName(const string& name) { Name = name; }
	void SetJob(int job) { Job = job; }
	void SetLevel(int level) { Level = level; }
	void SetHp(int hp) { Hp = hp; }
	void SetMaxHp(int maxHp) { MaxHp = maxHp; }
	void SetMp(int mp) { Mp = mp; }
	void SetMaxMp(int maxMp) { MaxMp = maxMp; }
	void SetPower(int power) { Power = power; }
	void SetDefence(int defence) { Defence = defence; }
	void SetExp(int exp) { Exp = exp; }
	void SetMaxExp(int maxExp) { MaxExp = maxExp; }

protected:
	string Name;
	string Job;
	int Hp;
	int MaxHp;
	int Mp;
	int MaxMp;
	int Power;
	int Defence;

	int Exp;
	int MaxExp;
	int Level;
};