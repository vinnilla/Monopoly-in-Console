// community.cpp

#include "community.h"
#include "card.h"
#include "action.h"
#include <cstdlib>
#include <string>
#include <deque>

using namespace std;

Community::Community () {
	deck = new Card[16];
	numberofcards = 16;
	int cardNum = 0;
	counter = 0;

	deck[cardNum].populate (6, 0, 
		"Advance to Go", 
		"You advance to go!",
		"You gain $40,000!", 3, 40000, 
		"gotoaction", 0);

	cardNum++;

	deck[cardNum].populate (1, 1, 
		"Bank Error in your Favor", 
		"",
		"You gain $15,000 from the bank error!", 3, 15000,
		"moneyaction", 15000);

	cardNum++;

	deck[cardNum].populate (1, 2, 
		"Doctor's Fees", 
		"",
		"You lose $10,000 to pay the doctor.", 3, -10000,
		"moneyaction", -10000);

	cardNum++;

	deck[cardNum].populate (5, 3, 
		"Get Out of Jail Free", 
		"",
		"", 3, 0,
		"jail", 0);

	cardNum++;

	deck[cardNum].populate (4, 4, 
		"Go to Jail", 
		"You are sent to jail.",
		"", 3, 0,
		"gotoaction", 10);

	cardNum++;

	deck[cardNum].populate (2, 5, 
		"Birthday", 
		"",
		"You gain $2,000 from everyone!", 3, 2000,
		"moneyaction", 2000);

	cardNum++;

	deck[cardNum].populate (1, 6, 
		"Car Show", 
		"",
		"You gain $10,000 from letting the car show borrow your car!", 3, 10000,
		"moneyaction", 10000);

	cardNum++;

	deck[cardNum].populate (1, 7, 
		"Income Tax Refund", 
		"",
		"You gain $4000 from tax refund.", 3, 4000,
		"moneyaction", 4000);

	cardNum++;

	deck[cardNum].populate (1, 8, 
		"Life Insurance Matures", 
		"",
		"You gain $20,000 from life insurance matures!", 3, 20000,
		"moneyaction", 20000);

	cardNum++;

	deck[cardNum].populate (1, 9, 
		"Pay Hospital Fees", 
		"",
		"You lose $20,000 to pay the hospital.", 3, -20000,
		"moneyaction", -20000);

	cardNum++;

	deck[cardNum].populate (1, 10, 
		"Pay School Fees", 
		"",
		"You lose $10,000 to pay for school fees.", 3, -10000,
		"moneyaction", -10000);

	cardNum++;

	deck[cardNum].populate (1, 11, 
		"Receive Consultancy Fee", 
		"",
		"You gain $5,000 from consulting.", 3, 5000,
		"moneyaction", 5000);

	cardNum++;

	deck[cardNum].populate (3, 12, 
		"Car Repairs", 
		"",
		"You must pay $1000 to repair each upgrade you've made to your vehicles (since custom parts tend to break.)", 3, 1000,
		"moneyaction", 0);

	cardNum++;

	deck[cardNum].populate (1, 13, 
		"Beauty Contest", 
		"",
		"You win $2,000! from coming second place in the beauty pagent!", 3, 2000,
		"moneyaction", 2000);

	cardNum++;

	deck[cardNum].populate (1, 14, 
		"Inheritance", 
		"",
		"You gain $20,000 from your inheritance!", 3, 20000,
		"moneyaction", 20000);

	cardNum++;

	deck[cardNum].populate (1, 15, 
		"Stock Sale", 
		"",
		"You gain $10,000 from selling stocks!", 3, 10000,
		"moneyaction", 10000);
}

Community::~Community () {
	delete [] deck;
}

void Community::updateNum(int change) {
	numberofcards = change;
}

void Community::shuffle () {
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



void Community::reArrange () {
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

int Community::returnType() {
	return deck[0].retrieveType();
}

int Community::returnValue() {
	return deck[0].retrieveValue();
}

void Community::print() {
	deck[0].print();
	deck[0].printAction();
}

void Community::printDeck() {
	for (int i = 0; i < numberofcards; i++) {
		deck[i].print();
		cout << "Type: " << deck[i].retrieveType() << "Value: " << deck[i].retrieveValue() << endl; 
	}
	cout << "-----------------------------------------------------------" << endl;
}

int Community::returnNum() {
	return numberofcards;
}

/*void Community::execaction(Player* player, Bank* bank) {
	deck[counter].execaction(player, bank);
	if (counter < 15) {
		counter++;
	}
	else {
		counter = 0;
	}
}*/
