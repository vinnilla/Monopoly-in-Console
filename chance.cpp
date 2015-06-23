// chance.cpp

#include "chance.h"
#include "card.h"
#include "action.h"
#include <cstdlib>
#include <string>
#include <deque>

using namespace std;

Chance::Chance () {
	deck = new Card[16];
	numberofcards = 16;
	int cardNum = 0;
	counter = 0;

	deck[cardNum].populate (6, 0, 
		"Advance to Go", 
		"You advance to go!",
		"You gain $40,000!", 6, 40000, 
		"gotoaction", 0);

	cardNum++;

	deck[cardNum].populate (7, 1, 
		"Advance to Audi S4", 
		"You advance to the Audi S4!",
		" ", 6, 24,
		"moneyaction", 15000);

	cardNum++;

	deck[cardNum].populate (8, 2, 
		"Advance to Nearest Taxi", 
		"You advance to the nearest Taxi.",
		"", 6, 0,
		"moneyaction", -10000);

	cardNum++;

	deck[cardNum].populate (9, 3, 
		"Advance to Nearest Bus Stop", 
		"You advance to the nearest Bus Stop.",
		"", 6, 0,
		"jail", 0);

	cardNum++;

	deck[cardNum].populate (9, 4, 
		"Advance to Nearest Bus Stop", 
		"You advance to the nearest Bus Stop.",
		"", 6, 0,
		"gotoaction", 10);

	cardNum++;

	deck[cardNum].populate (7, 5, 
		"Advance to Toyota Camry", 
		"You advance to the Toyota Camry!",
		"", 6, 11,
		"moneyaction", 2000);

	cardNum++;

	deck[cardNum].populate (1, 6, 
		"Bank Pays Dividend", 
		"",
		"You gain $10,000 from the bank!", 6, 10000,
		"moneyaction", 10000);

	cardNum++;

	deck[cardNum].populate (5, 7, 
		"Get Out of Jail Free", 
		"",
		"", 6, 0,
		"moneyaction", 4000);

	cardNum++;

	deck[cardNum].populate (4, 8, 
		"Go to Jail", 
		"You are sent to jail.",
		"", 6, 0,
		"moneyaction", 20000);

	cardNum++;

	deck[cardNum].populate (10, 9, 
		"Go Back Three Spaces", 
		"You go back three spaces.",
		"", 6, -3,
		"moneyaction", -20000);

	cardNum++;

	deck[cardNum].populate (3, 10, 
		"General Repairs", 
		"",
		"You must pay $625 to repair each upgrade you've made to your vehicles. ", 6, -625,
		"moneyaction", -10000);

	cardNum++;

	deck[cardNum].populate (1, 11, 
		"Pay Poor Tax", 
		"",
		"You pay $3,000 in taxes.", 6, -3000,
		"moneyaction", 5000);

	cardNum++;

	deck[cardNum].populate (7, 12, 
		"Advance to First Bus Stop", 
		"You advance to the first Bus Btop.",
		"", 6, 5,
		"moneyaction", 0);

	cardNum++;

	deck[cardNum].populate (7, 13, 
		"Advance to Maserati GranTurismo", 
		"You advance to the Maserati GranTurismo!",
		"", 6, 39,
		"moneyaction", 2000);

	cardNum++;

	deck[cardNum].populate (2, 14, 
		"Elected Chairman", 
		"",
		"You have been elected chairman of the board. Everyone pays you $10,000.", 6, 10000,
		"moneyaction", 20000);

	cardNum++;

	deck[cardNum].populate (1, 15, 
		"Car Loan Matures", 
		"",
		"Your car loan matures! You gain $20000", 6, 20000,
		"moneyaction", 10000);
}

Chance::~Chance () {
	delete [] deck;
}

void Chance::updateNum(int change) {
	numberofcards = change;
}

void Chance::shuffle () {
	for (int i = 0; i < 1000; i++){
		int a = rand()%16;
		int b = rand()%16;
		Action temp = deck[a].retrieveAction();
		int position = deck[a].retrievePos();
		int tempType = deck[a].retrieveType();
		int tempValue = deck[a].retrieveValue();
		deck[a].changeAction(deck[b].retrieveAction());
		deck[a].changePos(deck[b].retrievePos());
		deck[a].changeType(deck[b].retrieveType());
		deck[a].changeValue(deck[b].retrieveValue());
		deck[b].changeAction(temp);
		deck[b].changePos(position);
		deck[b].changeType(tempType);
		deck[b].changeValue(tempValue);
	}
}



void Chance::reArrange () {
	Action temp = deck[0].retrieveAction();
	int position = deck[0].retrievePos();
	int tempType = deck[0].retrieveType();
	int tempValue = deck[0].retrieveValue();
	for (int i = 1; i < numberofcards; i++) {
		deck[i-1].changeAction(deck[i].retrieveAction());
		deck[i-1].changePos(deck[i].retrievePos());
		deck[i-1].changeType(deck[i].retrieveType());
		deck[i-1].changeValue(deck[i].retrieveValue());
	}
	deck[numberofcards-1].changeAction(temp);
	deck[numberofcards-1].changePos(position);
	deck[numberofcards-1].changeType(tempType);
	deck[numberofcards-1].changeValue(tempValue);
}

int Chance::returnType() {
	return deck[0].retrieveType();
}

int Chance::returnValue() {
	return deck[0].retrieveValue();
}

void Chance::print() {
	deck[0].print();
	deck[0].printAction();
}

void Chance::printDeck() {
	for (int i = 0; i < numberofcards; i++) {
		deck[i].print();
		cout << "Type: " << deck[i].retrieveType() << "Value: " << deck[i].retrieveValue() << endl; 
	}
	cout << "-----------------------------------------------------------" << endl;
}

int Chance::returnNum() {
	return numberofcards;
}

/*void Chance::execaction(Player* player, Bank* bank) {
	deck[counter].execaction(player, bank);
	if (counter < 15) {
		counter++;
	}
	else {
		counter = 0;
	}
}*/
