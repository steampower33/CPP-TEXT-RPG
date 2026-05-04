#include "AlchemyWorkshop.h"

AlchemyWorkshop::AlchemyWorkshop()
{
	PotionRecipes.push_back(PotionRecipe{ "HPPotion", {{"Herb", 1}, {"ClearWater", 1}} });
	PotionRecipes.push_back(PotionRecipe{ "StaminaPotion", {{"Herb", 1}, {"Berry", 1}} });
}

AlchemyWorkshop::~AlchemyWorkshop()
{
}

void AlchemyWorkshop::ShowAllRecipes()
{
	for (auto& r : PotionRecipes)
	{
		cout << "-> " << r.name << ": ";
		for (int i = 0; i < r.ingredients.size(); i++)
		{
			auto& ingre = r.ingredients[i];
			cout << ingre.first << " x " << ingre.second;
			if (i != r.ingredients.size() - 1)
				cout << ", ";
		}
		cout << endl;
	}
}

void AlchemyWorkshop::SearchByName(string name)
{
	for (auto& r : PotionRecipes)
	{
		if (r.name == name)
		{
			cout << "-> " << r.name << ": ";
			for (int i = 0; i < r.ingredients.size(); i++)
			{
				auto& ingre = r.ingredients[i];
				cout << ingre.first << " x " << ingre.second;
				if (i != r.ingredients.size() - 1)
					cout << ", ";
			}
			cout << endl;
			return;
		}
	}

	cout << "Cannot find the potion with that name." << endl;
}

void AlchemyWorkshop::SearchByIngredient(string ingredient)
{
	int cnt = 0;
	for (auto& r : PotionRecipes)
	{
		for (int i = 0; i < r.ingredients.size(); i++)
		{
			if (r.ingredients[i].first == ingredient)
			{
				cout << "-> " << r.name << ": ";
				for (int j = 0; j < r.ingredients.size(); j++)
				{
					cout << r.ingredients[j].first << " x " << r.ingredients[j].second;
					if (j != r.ingredients.size() - 1)
						cout << ", ";
				}
				cout << endl;
				cnt++;
			}
		}
	}
	cout << "Found " << cnt << " recipes." << endl;
}
