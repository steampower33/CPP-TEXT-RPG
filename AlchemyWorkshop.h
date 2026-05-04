#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct PotionRecipe {
	string name;
	vector<pair<string, int>> ingredients;
};

class AlchemyWorkshop
{
public:
	AlchemyWorkshop();
	~AlchemyWorkshop();

	void ShowAllRecipes();
	void SearchByName(string name);
	void SearchByIngredient(string ingredient);

private:
	vector<PotionRecipe> PotionRecipes;

};

