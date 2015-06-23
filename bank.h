//bank.h
#ifndef BANK_H
#define BANK_H

#include <string>
#include <iostream>

using namespace std;

class Bank {
private:
	int funds;

public:
	void initialize(int);
	void deductFunds(int);
	void addFunds(int);
	void print();
};

#endif