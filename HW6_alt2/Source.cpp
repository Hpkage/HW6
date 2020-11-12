// Source.cpp Hiromi Kageyama Nov. 11, 2020
// Write a c++ program that simulates a shopping cart

#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::string;

struct record {
	double price;
	int units;
};

void Add(std::map<string, record>& item, record& stuff, string& name) {
	item.insert({ name, stuff });
}

void remove(std::map<string, record>& item, record& stuff, string& name) {
	auto iter = item.find(name);
	item.erase(iter);
}

int main() {
	std::map<string, record> cart;
	record shirts{ 20.00, 1 };
	record pants{ 30.00, 2 };
	record bread{ 03.37, 3 };
	record milk{ 2.00, 2 };
	record hose{ 100.00, 10 };



	return 0;
}