#pragma once

#include <string>
#include <iostream>

using namespace std;

struct Item {
	Item() : name(""), price(0), cnt(0) {}
	Item(string n, int p, int c) : name(n), price(p), cnt(c) {}

	string name;
	int price;
	int cnt;
};