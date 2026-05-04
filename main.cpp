// CPP-TEXT-RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include <vector>
#include "AlchemyWorkshop.h"
#include <random>

void printStatus(string Name, int stat[])
{
	cout << "====================================\n";
	cout << "\t" << Name << "'s Stats\n";
	cout << "====================================\n";

	cout << "HP: " << stat[0] << "\t MP: " << stat[1] << endl;
	cout << "Attack: " << stat[2] << "\t Defense: " << stat[3] << endl;
}

int main()
{
	// STEP 1
	cout << "===========================================\n";
	cout << "\t[Dungeon Escape Text RPG]\n";
	cout << "===========================================\n";

	string name;
	cout << "Enter your hero's name:";
	cin >> name;

	// stat[0] = HP, stat[1] = MP, stat[2] = 공격력, stat[3] = 방어력
	const int SIZE = 4;
	int stat[SIZE] = { 0 };

	// STEP 2
	while (1)
	{
		cout << "Enter HP and MP: ";
		cin >> stat[0] >> stat[1];

		if (stat[0] < 50 || stat[1] < 50)
		{
			cout << "HP or MP is too low. Try again.\n";
		}
		else
		{
			break;
		}
	}

	while (1)
	{
		cout << "Enter Attack and Defense: ";
		cin >> stat[2] >> stat[3];

		if (stat[2] < 50 || stat[3] < 50)
		{
			cout << "Attack or Defense is too low. Try again.\n";
		}
		else
		{
			break;
		}
	}

	printStatus(name, stat);

	// STEP3
	cout << "* You received 5 HP Potions and 5 MP Potions.\n";
	cout << "============================================\n";
	cout << "< Character Upgrade >\n";
	cout << "1. HP UP    2. MP UP    3. Attack x2\n4. Defense x2  5. Show Stats  0. Start Game\n";
	cout << "============================================\n";

	int choice = -1;
	bool isGameStart = false;

	int hpPotionAmount = 20;
	int hpPotionCnt = 5;
	int mpPotionAmount = 20;
	int mpPotionCnt = 5;

	while (!isGameStart)
	{
		cout << "Choose: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			cout << "Starting the game!\n";
			isGameStart = true;
			break;
		}
		case 1:
		{
			if (hpPotionCnt <= 0)
			{
				cout << "Out of HP potions.\n";
				break;
			}
			stat[0] += hpPotionAmount;
			hpPotionCnt--;
			cout << "* HP increased by " << hpPotionAmount << ". (HP Potion used : " << hpPotionCnt << " left)\n";
			break;
		}
		case 2:
		{
			if (mpPotionCnt <= 0)
			{
				cout << "Out of MP potions.\n";
				break;
			}
			stat[1] += mpPotionAmount;
			mpPotionCnt--;
			cout << "* MP increased by " << mpPotionAmount << ". (MP Potion used : " << mpPotionCnt << " left)\n";
			break;
		}
		case 3:
		{
			stat[2] *= 2;
			cout << "Attack increased to " << stat[2] << ".\n";
			break;
		}
		case 4:
		{
			stat[3] *= 2;
			cout << "Defense increased to " << stat[3] << ".\n";
			break;
		}
		case 5:
		{
			printStatus(name, stat);
			break;
		}
		default:
		{
			break;
		}
		}
	}

	// STEP 4
	cout << "< Job Selection >\n";
	cout << name << ", choose your job!\n";
	cout << "1. Warrior 2. Magician 3. Thief 4. Archer\n";

	int job = -1;
	Player* player = nullptr;
	while (player == nullptr)
	{
		cout << "Choose: ";
		cin >> job;
		switch (job)
		{
		case 1: player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]); break;
		case 2: player = new Magician(name, stat[0], stat[1], stat[2], stat[3]); break;
		case 3: player = new Thief(name, stat[0], stat[1], stat[2], stat[3]); break;
		case 4: player = new Archer(name, stat[0], stat[1], stat[2], stat[3]); break;
		default:
			cout << "Wrong Input. Please enter a number between 1 and 4.\n";
			break;
		}
	}

	// STEP 5, 6, 7
	vector<Monster> monsters;
	monsters.push_back({ "Slime", 50, 20, 10, "Slime Jelly", 30 });
	monsters.push_back({ "Golem", 200, 80, 40, "Giant Stone", 120 });
	monsters.push_back({ "Skeleton", 400, 160, 80, "Bone", 240 });

	vector<Item> inventory;
	AlchemyWorkshop workshop;

	// 난수 생성기 초기화
	random_device rd;
	mt19937 gen(rd());
	// 0 부터 (몬스터 배열 크기 - 1) 까지의 범위를 지정
	uniform_int_distribution<int> monsterDist(0, monsters.size() - 1);

	int mainMenuChoice = -1;
	while (mainMenuChoice != 0)
	{
		cout << "=== Main Menu ===\n";
		cout << "1. Enter Dungeon\n";
		cout << "2. Check Inventory\n";
		cout << "3. Potion Shop\n";
		cout << "0. Quit\n";
		cout << "Choose: ";
		cin >> mainMenuChoice;

		switch (mainMenuChoice)
		{
		case 0:
		{
			break;
		}
		case 1:
		{
			int randomIndex = monsterDist(gen);

			Monster monster = monsters[randomIndex];

			cout << "[ Battle Start! ] " << player->GetName() << "(" << player->GetJob() << ") vs " << monster.GetName() << endl;
			while (player->GetHp() > 0 && monster.GetHp() > 0)
			{
				cout << "--- Player Turn ---\n";
				player->Attack();

				int damage = player->GetPower() - monster.GetDefence();
				if (damage <= 0)
					damage = 1;

				int beforeMonsterHP = monster.GetHp();
				int afterMonsterHP = monster.GetHp() - damage;

				monster.SetHp(afterMonsterHP);

				string monsterName = monster.GetName();
				cout << damage << " damage to " << monsterName << endl;
				cout << monsterName << " HP: " << beforeMonsterHP << " -> " << monster.GetHp();
				if (monster.GetHp() <= 0)
				{
					cout << "(Dead)" << endl;
					cout << "★ Victory!" << endl;
					cout << " -> Got: " << monster.GetDropItemName() << "!\n";
					inventory.push_back(Item{ monster.GetDropItemName(), monster.GetDropItemValue()});
					cout << " -> Saved to inventory.\n";
					break;
				}
				else
					cout << "\n";

				cout << "--- Enemy Turn ---\n";
				monster.Attack(player);

				if (player->GetHp() <= 0)
				{
					cout << "The player has died. Game over." << endl;
					return 0;
				}
			}
			break;
		}
		case 2:
		{
			cout << "[Inventory(" << inventory.size() << " / 10)]\n";
			for (int i = 0; i < inventory.size(); i++)
			{
				Item item = inventory[i];
				cout << i + 1 << ". ";
				item.PrintInfo();
				cout << endl;
			}
			break;
		}
		case 3:
		{
			int potionShoptChoice = -1;
			while (potionShoptChoice != 0)
			{
				cout << "=== Potion Shop ===\n";
				cout << "1. Show all recipes\n";
				cout << "2. Search by potion name\n";
				cout << "3. Search by ingredient\n";
				cout << "0. Go back\n";

				cout << "Choose: ";
				cin >> potionShoptChoice;

				string potionName;
				string ingredientName;
				switch (potionShoptChoice)
				{
				case 0:
					break;
				case 1:
					workshop.ShowAllRecipes();
					break;
				case 2:
					cout << "Search potion name: ";
					cin >> potionName;
					workshop.SearchByName(potionName);
					break;
				case 3:
					cout << "Search ingredient: ";
					cin >> ingredientName;
					workshop.SearchByIngredient(ingredientName);
					break;
				default:
					break;
				}
			}
			break;
		}
		default:
		{
			break;
		}
		}
	}

	delete player;
}