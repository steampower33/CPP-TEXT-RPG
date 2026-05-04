#pragma once

#include <string>
#include <iostream>

using namespace std;

struct Item {
	Item(string n, int p) : name(n), price(p) {}

	string name;
	int price;

	void PrintInfo() const {
		cout << name << "(" << price << "G)";
	}
};