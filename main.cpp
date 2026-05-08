// CPP-TEXT-RPG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "AlchemyWorkshop.h"
#include "Item.h"
#include "Inventory.h"
#include "PotionManager.h"

#include <vector>

void printStatus(string Name, int stat[])
{
	cout << "====================================\n";
	cout << "\t" << Name << "'s Stats\n";
	cout << "====================================\n";

	cout << "HP: " << stat[0] << "\t MP: " << stat[1] << endl;
	cout << "Attack: " << stat[2] << "\t Defense: " << stat[3] << endl;
}

// 함수를 실행할때는 체력포션과 마나포션 변수의 주소값(&) 전달하고
// 해당 주소값을 전달 받은 다음 해당 위치에 접근하기 위해서는 *을 통해서 해당 주소가 가리키는 위치에 접근을 한다.
// 그러고 그 위치에 값을 덮어쓰는 것이다
// 그리고 만약 포인터를 사용하지 않고 매개변수만 넘겼을 때는 해당 변수의 주소값이 아니고, 그냥 변수 값 자체를 받게되는것이기 되는것이다 
void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
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

		if (stat[0] < 10 || stat[1] < 10)
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

		if (stat[2] < 10 || stat[3] < 10)
		{
			cout << "Attack or Defense is too low. Try again.\n";
		}
		else
		{
			break;
		}
	}

	printStatus(name, stat);

	int HPPotionCnt = 0;
	int HPPotionAmount = 20;
	int MPPotionCnt = 0;
	int MPPotionAmount = 20;
	int count = 10;
	setPotion(count, &HPPotionCnt, &MPPotionCnt);

	cout << "* You received " << HPPotionCnt << " HP Potions and " << MPPotionCnt << " MP Potions.\n";
	cout << "============================================\n";
	cout << "< Character Upgrade >\n";
	cout << "1. HP UP    2. MP UP    3. Attack x2\n4. Defense x2  5. Show Stats  0. Start Game\n";
	cout << "============================================\n";

	int choice = -1;
	bool isGameStart = false;
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
			if (HPPotionCnt <= 0)
			{
				cout << "Out of HP potions.\n";
				break;
			}
			stat[0] += HPPotionAmount;
			HPPotionCnt--;
			cout << "* HP increased by " << HPPotionAmount << ". (HP Potion used : " << HPPotionCnt << " left)\n";
			break;
		}
		case 2:
		{
			if (MPPotionCnt <= 0)
			{
				cout << "Out of MP potions.\n";
				break;
			}
			stat[1] += MPPotionAmount;
			MPPotionCnt--;
			cout << "* MP increased by " << MPPotionAmount << ". (MP Potion used : " << MPPotionCnt << " left)\n";
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

	struct Room {
		Monster monster;
		bool isClear;
	};

	vector<Room> rooms;
	rooms.push_back({ Monster{ "Slime", 30, 20, 10, "Slime Jelly", 10, 200 }, false });
	rooms.push_back({ Monster{ "Goblin", 50, 30, 20, "Goblin Leg", 20, 300 }, false });
	rooms.push_back({ Monster{ "Orc", 80, 40, 30, "Orc Eye", 30, 400 }, false });
	rooms.push_back({ { "Dragon", 200, 80, 40, "Dragon Tail", 60, 1000}, false });

	Inventory<Item> inventory;
	inventory.AddItem({ "HP Potion", 50, 1 });
	inventory.AddItem({ "MP Potion", 50, 1 });

	AlchemyWorkshop workshop;

	{
		PotionManager pm;

		pm.AddRecipe("HP Potion");

		pm.DispensePotion("HP Potion");
		pm.DispensePotion("HP Potion");
		pm.DispensePotion("HP Potion");

		pm.DispensePotion("HP Potion");

		pm.ReturnPotion("HP Potion");

		pm.ReturnPotion("HP Potion");
	}

	int roomIndex = 0;

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
			cout << "[ Dungeon Floor 1]" << endl;

			for (int i = 0; i < rooms.size() - 1; i++)
			{
				auto& monster = rooms[i].monster;
				cout << "Room " << i + 1 << ": " << monster.GetName() << "\t(HP " << monster.GetHp() << ", Attack " << monster.GetPower() << ", Defence " << monster.GetDefence() << ") -> ";

				if (rooms[i].isClear)
					cout << "Clear!" << endl;
				else
				{
					cout << "UnClear" << endl;
				}
			}

			if (roomIndex == 3)
			{
				cout << "★ Boss Room Unlocked!" << endl;
				cout << "Boss Dragon appears!(HP 200, Attack 60, Defense 20)" << endl;
			}

			Monster monster = rooms[roomIndex].monster;

			cout << "[ Battle Start! ] " << player->GetName() << "(" << player->GetJob() << ") vs " << monster.GetName() << endl;
			while (player->GetHp() > 0 && monster.GetHp() > 0)
			{
				cout << "--- Player Turn ---\n";
				cout << "1. Attack" << endl;
				cout << "2. Use Item" << endl;
				cout << "Choose: ";

				int battleChoose = -1;

				cin >> battleChoose;

				switch (battleChoose)
				{
				case 1:
				{
					player->Attack(&monster);
					break;
				}
				case 2:
				{
					inventory.PrintAllItems();

					cout << "Choose Item: ";
					int itemChoose = -1;
					cin >> itemChoose;

					Item* potion = inventory.GetItem(itemChoose - 1);

					if (potion)
					{
						cout << "* " << potion->name << "used! ";
						if (potion->name == string("HP Potion"))
						{
							int beforeHP = player->GetHp();
							player->SetHp(min(beforeHP + 50, player->GetMaxHp()));
							cout << "HP restored by 50 (" << beforeHP << " -> " << player->GetHp() << ")" << endl;
							inventory.RemoveItemAt(itemChoose - 1);
						}
						else if (potion->name == string("MP Potion"))
						{
							int beforeMP = player->GetMp();
							player->SetMp(min(beforeMP + 50, player->GetMaxMp()));
							cout << "MP restored by 50 (" << beforeMP << " -> " << player->GetMp() << ")" << endl;
							inventory.RemoveItemAt(itemChoose - 1);
						}
					}
					else
					{
						cout << "Wrong Input" << endl;
					}

					break;
				}
				default:
					cout << "Wrong Input." << endl;
					break;
				}

				if (monster.GetHp() <= 0)
				{
					cout << "(Dead)" << endl;
					cout << "★ Victory!" << endl;

					int monsterExpReward = monster.GetExpReward();
					player->SetExp(player->GetExp() + monsterExpReward);
					int exp = player->GetExp();
					int maxExp = player->GetMaxExp();
					if (exp >= maxExp)
					{
						int beforeLevel = player->GetLevel();
						int LevelUpAmount = exp / maxExp;
						int afterLevel = beforeLevel + LevelUpAmount;

						player->SetExp(exp - LevelUpAmount * maxExp);
						player->SetMaxExp(player->GetMaxExp() + 40 * LevelUpAmount);
						player->SetLevel(afterLevel);
						cout << "... Level Up Condition Met" << endl;
						cout << " -> Level Up! Lv." << beforeLevel << " -> Lv." << afterLevel << endl;

						player->SetHp(player->GetHp() + 10 * LevelUpAmount);
						player->SetMaxHp(player->GetMaxHp() + 50 * LevelUpAmount);
						player->SetMp(player->GetMp() + 5 * LevelUpAmount);
						player->SetMaxMp(player->GetMaxMp() + 100 * LevelUpAmount);
						player->SetPower(player->GetPower() + 5 * LevelUpAmount);
						cout << " -> HP + " << 10 * LevelUpAmount << ", MP + " << 5 * LevelUpAmount << ", Power + " << 5 * LevelUpAmount << endl;
					}
					else
					{
						cout << " -> +" << monsterExpReward << " EXP! (EXP: " << player->GetExp() << "/" << player->GetMaxExp() << ")" << endl;
					}

					// Save Item To Inventory
					cout << " -> Got: " << monster.GetDropItemName() << "!\n";
					inventory.AddItem({ monster.GetDropItemName(), monster.GetDropItemValue(), 1 });

					rooms[roomIndex].isClear = true;

					if (roomIndex == 3 && rooms[roomIndex].isClear)
					{
						cout << "Dragon defeated!" << endl;
						cout << "=== GAME CLEAR! ===" << endl;
						return 0;
					}

					roomIndex++;

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
			inventory.PrintAllItems();
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