//bank.cpp

#include "bank.h"
#include <iostream>

using namespace std;

void Bank::initialize(int wealth) {
	funds = wealth;
}

void Bank::deductFunds(int change) {
	funds -= change;
}

void Bank::addFunds(int change) {
	funds += change;
}

void Bank::print() {
	cout << funds << endl;
}