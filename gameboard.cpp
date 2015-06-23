//gameboard.cpp

#include "gameboard.h"
#include "player.h"
#include "space.h"
#include "action.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Game_Board::Game_Board() {}

Game_Board::Game_Board(int numberofspaces) {
	allSpaces = new Space[numberofspaces];
	int spaceNum = 0;
	allSpaces[spaceNum].populate(false, "        GO       ", "                 ",  spaceNum+1, "    ", 'n', 0, 0, 0,
	"",
	 "",
	  "", 2, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Mazda      ", "        2        ",  spaceNum+1, "    ", '0', 14720, 1472, 4416,
	"You see the Mazda 2! You may purchase the vehicle for $14,720 if you'd like to.",
	 "You see Player ",
	  "'s Mazda 2 and rent it!", 0, 3, 15000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",  spaceNum+1, "    ", '5', 0, 0, 0,
	"You draw a community chest card.",
	 "",
	  "", 3, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Mazda      ", "        3        ", spaceNum+1, "    ", '0', 16945, 1695, 5084,
	"You see the Mazda 3! You may purchase the vehicle for $16,945 if you'd like to.",
	 "You see Player ",
	  "'s Mazda 3 and rent it!", 0, 3, 15000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Income     ", "       Tax       ",  spaceNum+1, "    ", '7', 0, 0, 0,
	"You pay income tax.",
	 "",
	  "", 4, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",  spaceNum+1, "    ", '0', 50000, 5000, 15000,
	"You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and rent a bus!", 0, 1, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "      Civic      ",  spaceNum+1, "    ", '0', 18390, 1839, 5517,
	 "You see the Honda Civic! You may purchase the vehicle for $18,390 if you'd like to.",
	 "You see Player ",
	  "'s Honda Civic and you rent it!", 0, 4, 15000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Chance     ", "                 ",  spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "", 6, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "       CR-Z      ",  spaceNum+1, "    ", '0', 19995, 2000, 6000,
	 "You see the Honda CR-Z! You may purchase the vehicle for $19,995 if you'd like to.",
	 "You see Player ",
	  "'s Honda CR-Z and you rent it!", 0, 4, 15000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Honda      ", "      Accord     ",  spaceNum+1, "    ", '0', 21955, 2196, 6587,
	 "You see the Honda Accord! You may purchase the vehicle for $21,955 if you'd like to.",
	 "You see Player ",
	  "'s Honda Accord and you rent it!", 0, 4, 15000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Jail      ", "                 ",   spaceNum+1, "    ", 'n', 0, 0, 0,
	 "You are visiting the jail.",
	 "",
	  "", 2, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Camry      ",   spaceNum+1, "    ", '0', 22425, 2243, 6728,
	 "You see the Toyota Camry! You may purchase the vehicle for $22,425 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Camry and you rent it!", 0, 5, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Taxi      ", "                 ",   spaceNum+1, "    ", '0', 25000, 2500, 7500,
	 "You see a taxi! You may purchase the vehicle for $25,000 if you'd like to.",
	 "You see Player ",
	  "'s taxi and you rent it!", 0, 2, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Sienna     ",   spaceNum+1, "    ", '0', 26200, 2620, 7860,
	 "You see the Toyota Sienna! You may purchase the vehicle for $26,200 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Sienna and you rent it!", 0, 5, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "      Toyota     ", "      Tundra     ",   spaceNum+1, "    ", '0', 26920, 2692, 8076,
	 "You see the Toyota Tundra! You may purchase the vehicle for $26,920 if you'd like to.",
	 "You see Player ",
	  "'s Toyota Tundra and you rent it!", 0, 5, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus!", 0, 1, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "      CLA250     ",   spaceNum+1, "    ", '0', 29900, 2990, 8970,
	 "You see the Mercedes CLA250! You may purchase the vehicle for $29,900 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes CLA250 and you rent it!", 0, 6, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",   spaceNum+1, "    ", '5', 0, 0, 0,
	 "You draw a community chest card.",
	 "",
	  "", 3, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "    C250 Sport   ",   spaceNum+1, "    ", '0', 35800, 3580, 10740,
	 "You see the Mercedes C250 Sport! You may purchase the vehicle for $35,800 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes C250 Sport and you rent it!", 0, 6, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Mercedes    ", "    C250 Coupe   ",   spaceNum+1, "    ", '0', 38200, 3820, 11460,
	 "You see the Mercedes C250 Coupe! You may purchase the vehicle for $38,200 if you'd like to.",
	 "You see Player ",
	  "'s Mercedes C250 Coupe and you rent it!", 0, 6, 30000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Free      ", "     Parking     ",   spaceNum+1, "    ", 'n', 0, 0, 0,
	 "You land on free parking!",
	 "",
	  "", 2, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        A5       ",   spaceNum+1, "    ", '0', 39000, 3900, 11700,
	 "You see the Audi A5! You may purchase the vehicle for $39,000 if you'd like to.",
	 "You see Player ",
	  "'s Audi A5 and you rent it!", 0, 7, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "     Chance      ", "                 ",   spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "", 6, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        A6       ",   spaceNum+1, "    ", '0', 43100, 4310, 12930,
	 "You see the Audi A6! You may purchase the vehicle for $43,100 if you'd like to.",
	 "You see Player ",
	  "'s Audi A6 and you rent it!", 0, 7, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       Audi      ", "        S4       ",   spaceNum+1, "    ", '0', 48100, 4810, 14430,
	 "You see the Audi S4! You may purchase the vehicle for $48,100 if you'd like to.",
	 "You see Player ",
	  "'s Audi S4 and you rent it!", 0, 7, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus!", 0, 1, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "    535i Sedan   ",   spaceNum+1, "    ", '0', 55100, 5510, 16530,
	 "You see the BMW 535i Sedan! You may purchase the vehicle for $55,100 if you'd like to.",
	 "You see Player ",
	  "'s BMW 535i Sedan and you rent it! ", 0, 8, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "      X535i      ",   spaceNum+1, "    ", '0', 55100, 5510, 16530,
	 "You see the BMW X535i! You may purchase the vehicle for $55,100 if you'd like to.",
	 "You see Player ",
	  "'s BMW X535i and you rent it!", 0, 8, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Taxi      ", "                 ",   spaceNum+1, "    ", '0', 25000, 2500, 7500,
	 "You see a taxi! You may purchase the vehicle for $25,000 if you'd like to.",
	 "You see Player ",
	  "'s taxi and you rent it!", 0, 2, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(true, "       BMW       ", "      X635i      ",   spaceNum+1, "    ", '0', 60800, 6080, 18240,
	 "You see the BMW X635i! You may purchase the vehicle for $60,800 if you'd like to.",
	 "You see Player ",
	  "'s BMW X635i and you rent it!", 0, 8, 45000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Go To      ", "       Jail      ",   spaceNum+1, "    ", '9', 0, 0, 0,
	 "You are arrested and sent to jail.",
	 "",
	  "", 5, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "    Boxster S    ",   spaceNum+1, "    ", '0', 62100, 6210, 18630,
	 "You see the Porsche Boxster S! You may purchase the vehicle for $62,100 if you'd like to.",
	 "You see Player ",
	  "'s Porsche Boxster S and you rent it!", 0, 9, 60000);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "     Cayman S    ",   spaceNum+1, "    ", '0', 63800, 6380, 19140,
	 "You see the Porsche Cayman S! You may purchase the vehicle for $63,800 if you'd like to.",
	 "You see Player ",
	  "'s Porsche Cayman S and you rent it!", 0, 9, 60000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "    Community    ", "      Chest      ",   spaceNum+1, "    ", '5', 0, 0, 0,
	 "You draw a community chest card.",
	 "",
	  "", 3, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Porsche     ", "   911 Carrera   ",   spaceNum+1, "    ", '0', 84300, 8430, 25290,
	 "You see the Porsche 911 Carrera! You may purchase the vehicle for $84,300 if you'd like to.",
	 "You see Player ",
	  "'s Porsche 911 Carrera and you rent it!", 0, 9, 60000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "       Bus       ", "       Stop      ",   spaceNum+1, "    ", '0', 50000, 5000, 15000,
	 "You see a Bus Stop! You may purchase the this bus stop for $50,000 if you'd like to.",
	 "You see Player ",
	  "'s Bus Stop and you rent a bus!", 0, 1, 0);
	allSpaces[spaceNum].UpgradetoFull();
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Chance     ", "                 ",   spaceNum+1, "    ", '6', 0, 0, 0,
	 "You draw a chance card.",
	 "",
	  "", 6, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Maserati    ", "   Quattroporte  ",   spaceNum+1, "    ", '0', 102500, 10250, 30750,
	 "You see the Maserati Quattroporte! You may purchase the vehicle for $102,500 if you'd like to.",
	 "You see Player ",
	  "'s Maserati Quattroporte and you rent it! ", 0, 10, 60000);
	spaceNum++;
	allSpaces[spaceNum].populate(false, "      Luxury     ", "       Tax       ",   spaceNum+1, "    ", '8', 0, 0, 0,
	 "You pay luxury tax.",
	 "",
	  "", 4, 0, 0);
	spaceNum++;
	allSpaces[spaceNum].populate(true, "     Maserati    ", "   GranTurismo   ",   spaceNum+1, "    ", '0', 126500, 12650, 37950,
	 "You see the Maserati Granturismo! You may purchase the vehicle for $126,500 if you'd like to.",
	 "You see Player ",
	  "'s Maserati Granturismo and you rent it! ", 0, 10, 60000); //constructor


}

Game_Board::~Game_Board() { //deconstructor
	delete [] allSpaces;
}

int Game_Board::counterIncrement(int start, int end, int value) {
	//check to see if it is top row of board or bottom row of board -- increment counter differently for the two cases
	if (start < end) {//top row
		return start+value;
	}

	else if (start > end) {//bottom row
		return start-value;
	}
	return 0;
}

string Game_Board::removeSpaces(string input) {
	size_t first = input.find_first_not_of(" ");
	size_t last = input.find_last_not_of(" ");
	size_t length = last - first;
	string buffer;
	if (first != 0 && last != 0) {
		buffer = input.substr(first, length+1);
		return buffer;		
	}

	else {
		return " ";
	}
}

void Game_Board::updateUpdate(Player* player, Bank* bank) {
	int counter = 0;
	int counter2 = 0;
	int decision;
	for (int i = 0; i < 40; i++) {
		int temp = player->retrieveProperty(i);
		if (temp == 1) {
			if (allSpaces[i].returnMonopoly() == true) {
				if (allSpaces[i].returnUpgrade()< 5){
					counter++;
					cout << counter << ". " << left << setw(20) << removeSpaces(allSpaces[i].returnBrand()) + " " + removeSpaces(allSpaces[i].returnModel()) << "    Price: $" << allSpaces[i].returnUpgradePrice() << endl;
				}
				
			}
		}
	}
	if (counter == 0) {
		cout << "You do not own any property that can be upgraded.\n";
	}

	else {
		do {
			cout << "Choose a property to upgrade by entering its number. (enter 0 if you'd like to return to the previous menu)";
			cin >> decision;
			cout << endl;

			if (cin.fail()){
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "That is an invalid input." << endl;
				continue;
			}

			else if (decision < 0 || decision > counter) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a valid choice." << endl;
				continue;
			}

			else if (decision == 0) {
				cin.ignore (10000, '\n');
				break;
			}

			else {
				for (int i = 0; i < 40; i++) {
					int temp = player->retrieveProperty(i);
					if (temp == 1) {
						bool check = allSpaces[i].returnMonopoly();
						if (check) {
							if (allSpaces[i].returnUpgrade()< 5){
								counter2++;
								if (counter2 == decision) {
									if (player->retrieveWealth() < allSpaces[i].returnUpgradePrice()) {
										cout << "You cannot afford the upgrade." << endl;
										continue;
									}
									else {
										player->deductMoney(allSpaces[i].returnUpgradePrice());
										bank->addFunds(allSpaces[i].returnUpgradePrice());
										allSpaces[i].updateUpgrade();
										cout << "You have upgraded your " << removeSpaces(allSpaces[i].returnBrand()) << " " << removeSpaces(allSpaces[i].returnModel()) << ".\n";
										//cout << allSpaces[i].returnUpgrade();
										break; 
									}
								}
							}
						}
					}
				}
			break;
			}

		} while (true);

	}


}

void Game_Board::mortgage(Player* player, Bank* bank) {
	int counter = 0;
	int decision;
	for (int i = 0; i < 40; i++) {
		int temp = player->retrieveProperty(i);
		if (temp == 1) {
			counter++;
			cout << counter << ". " << left << setw(20) << removeSpaces(allSpaces[i].returnBrand()) + " " + removeSpaces(allSpaces[i].returnModel()) << "    Price: $" << allSpaces[i].returnUpgradePrice() << endl;
		}
	}
	if (counter == 0) {
		cout << "You do not own any property that can be mortgaged.\n";
	}

	else {
		do {
			cout << "Choose a property to mortgage by entering its number.\n";
			cin >> decision;
			cout << endl;

			if (cin.fail()){
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "That is an invalid input." << endl;
				continue;
			}

			else if (decision < 0 || decision > counter) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a valid choice." << endl;
				continue;
			}

			else if (decision == 0) {
				cin.ignore (10000, '\n');
				break;
			}

			else {
				for (int i = 0; i < 40; i++) {
					int temp = player->retrieveProperty(i);
					if (temp == 1) {
						counter++;
						if (counter == decision) {
							updateMortgage(i, player, bank);
						}	
					
					}
				}
			break;
			}

		} while (true);

	}


}

void Game_Board::updatePieces(int playerNum, int currentSpace, int previousSpace, char character) {
	for (int i = 0; i < 40; i++) {
		if (currentSpace == i) { //finds the space the player is currently at (the one the player just moved to) and adds the player's piece to the space
			allSpaces[i].updatePieces(playerNum, character);
		}

		if (previousSpace == i) { //find the previous space the player was at before moving and removes the player's piece from the space
			allSpaces[i].updatePieces(playerNum, ' ');
		}
	}
}

void Game_Board::updateSpaces(vector<Player> players, int numPlayers) { //retrieves the player's current position and previous position and alters the corrent spaces
	for (int i = 0; i < numPlayers; i++) {
		int tempCurrentSpace;
		int tempPreviousSpace;
		char tempChar;
		tempCurrentSpace = players[i].returnSpace();
		tempPreviousSpace = players[i].returnSpace2();
		tempChar = players[i].returnChar();
		updatePieces(i, tempCurrentSpace, tempPreviousSpace, tempChar);
	}
}

void Game_Board::updateAction(int space, int change) {
	allSpaces[space].updateAction(change);
}

void Game_Board::updateMonopoly() {
	char owner[3];
	int group;
	int counter = 0;
	bool monopoly = true;
	for (int i = 0; i < 40; i++) {
		if (allSpaces[i].returnMonopoly() == false) {
			group = allSpaces[i].returnGroup();
			for (int j = 0; j < 40; j++) {
				if (allSpaces[j].returnGroup() == group) {
					owner[counter] = allSpaces[j].returnPurchased();
					counter++;
				}
			}
			for (int k = 1; k < counter; k++) {
				if (owner[k] != owner[k-1]) {
						monopoly = false;	
				}

				if (owner[k] == '0') {
					monopoly = false;
				}
			}

			if (monopoly == true) {
				for (int a = 0; a < 40; a++) {
					if (allSpaces[a].returnGroup() == group) {
						allSpaces[a].updateMonopoly(1);
						//cout << "Updated monopoly for space " << a << endl;
					}
				}
			}
		}
		counter = 0;
		monopoly = true;	
	}

	/*
	if (allSpaces[1].returnPurchased() == allSpaces[3].returnPurchased() and allSpaces[1].returnMonopoly() == false and allSpaces[1].returnPurchased()>0){
		cout << "Player " << allSpaces[1].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[1].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[1].returnBrand()) << "s has doubled." << endl;
		allSpaces[1].updateMonopoly(1);
		allSpaces[3].updateMonopoly(1);
	}

	else if (allSpaces[6].returnPurchased() == allSpaces[8].returnPurchased() and allSpaces[6].returnPurchased() == allSpaces[9].returnPurchased() and allSpaces[6].returnMonopoly() == false and allSpaces[6].returnPurchased()>0){
		cout << "Player " << allSpaces[6].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[6].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[6].returnBrand()) << "s has doubled." << endl;
		allSpaces[6].updateMonopoly(1);
		allSpaces[8].updateMonopoly(1);
		allSpaces[9].updateMonopoly(1);
	}

	else if (allSpaces[11].returnPurchased() == allSpaces[13].returnPurchased() and allSpaces[11].returnPurchased() == allSpaces[14].returnPurchased() and allSpaces[11].returnMonopoly() == false and allSpaces[11].returnPurchased()>0){
		cout << "Player " << allSpaces[11].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[11].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[11].returnBrand()) << "s has doubled." << endl;
		allSpaces[11].updateMonopoly(1);
		allSpaces[13].updateMonopoly(1);
		allSpaces[14].updateMonopoly(1);
	}
	
	else if (allSpaces[16].returnPurchased() == allSpaces[18].returnPurchased() and allSpaces[16].returnPurchased() == allSpaces[19].returnPurchased() and allSpaces[16].returnMonopoly() == false and allSpaces[16].returnPurchased()>0){
		cout << "Player " << allSpaces[16].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[16].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[16].returnBrand()) << "s has doubled." << endl;
		allSpaces[16].updateMonopoly(1);
		allSpaces[18].updateMonopoly(1);
		allSpaces[19].updateMonopoly(1);
	}
	
	else if (allSpaces[21].returnPurchased() == allSpaces[23].returnPurchased() and allSpaces[21].returnPurchased() == allSpaces[24].returnPurchased() and allSpaces[21].returnMonopoly() == false and allSpaces[21].returnPurchased()>0){
		cout << "Player " << allSpaces[21].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[21].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[21].returnBrand()) << "s has doubled." << endl;
		allSpaces[21].updateMonopoly(1);
		allSpaces[23].updateMonopoly(1);
		allSpaces[24].updateMonopoly(1);
	}
	
	else if (allSpaces[26].returnPurchased() == allSpaces[27].returnPurchased() and allSpaces[26].returnPurchased() == allSpaces[29].returnPurchased() and allSpaces[26].returnMonopoly() == false and allSpaces[26].returnPurchased()>0){
		cout << "Player " << allSpaces[26].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[26].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[26].returnBrand()) << "s has doubled." << endl;
		allSpaces[26].updateMonopoly(1);
		allSpaces[27].updateMonopoly(1);
		allSpaces[29].updateMonopoly(1);
	}
	
	else if (allSpaces[31].returnPurchased() == allSpaces[32].returnPurchased() and allSpaces[31].returnPurchased() == allSpaces[34].returnPurchased() and allSpaces[31].returnMonopoly() == false and allSpaces[31].returnPurchased()>0){
		cout << "Player " << allSpaces[31].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[31].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[31].returnBrand()) << "s has doubled." << endl;
		allSpaces[31].updateMonopoly(1);
		allSpaces[32].updateMonopoly(1);
		allSpaces[34].updateMonopoly(1);
	}
	
	else if (allSpaces[37].returnPurchased() == allSpaces[39].returnPurchased() and allSpaces[37].returnMonopoly() == false and allSpaces[37].returnPurchased()>0){
		cout << "Player " << allSpaces[37].returnPurchased() << "has a monopoly on all " << removeSpaces(allSpaces[37].returnBrand()) << "s." << endl; 
		cout << "Rent for all " << removeSpaces(allSpaces[37].returnBrand()) << "s has doubled." << endl;
		allSpaces[37].updateMonopoly(1);
		allSpaces[39].updateMonopoly(1);
	}

	else {
		return;
	}
	*/
	
}

void Game_Board::updateMortgage(int space, Player* player, Bank* bank) {
	allSpaces[space].updateMortgage();
	int money = allSpaces[space].returnBuy()/2;
	player->addMoney(money);
	bank->deductFunds(money);
	cout << "You have mortgaged your " << removeSpaces(allSpaces[space].returnBrand()) << " " << removeSpaces(allSpaces[space].returnModel()) << " and received $" << money << " from the bank.\n"; 
}

void Game_Board::unMortgage(Player* player, Bank* bank) {
	int counter = 0;
	int counter2 = 0;
	int decision;
	for (int i = 0; i < 40; i++) {
		int temp = player->retrieveProperty(i);
		if (temp == 1) {
			if (allSpaces[i].returnMortgage()){
				int mortgageprice = allSpaces[i].returnBuy()/2*1.10;
				counter++;
				cout << counter << ". " << removeSpaces(allSpaces[i].returnBrand()) << " " << removeSpaces(allSpaces[i].returnModel()) << "  Price to Unmortgage: $" << mortgageprice << endl;
			}
		}
	}

	if (counter == 0) {
		cout << "You cannot unmortgage any property.\n";
	}

	else {
		do {
			cout << "Choose a property to unmortgage by entering its number. (enter 0 if you'd like to return to the previous menu)";
			cin >> decision;
			cout << endl;

			if (cin.fail()){
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "That is an invalid input." << endl;
				continue;
			}

			else if (decision < 0 || decision > counter) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please enter a valid choice." << endl;
				continue;
			}

			else if (decision == 0) {
				cin.ignore (10000, '\n');
				break;
			}

			else {
				for (int i = 0; i < 40; i++) {
					int temp = player->retrieveProperty(i);
					if (temp == 1) {
						if (allSpaces[i].returnMortgage()){
							counter2++;
							if (counter2 == decision) {
								if (player->retrieveWealth() < allSpaces[i].returnBuy()/2*1.10) {
									cout << "You cannot afford to unmortgage this vehicle." << endl;
									continue;
								}
								else {
									player->deductMoney(allSpaces[i].returnBuy()/2*1.1);
									bank->addFunds(allSpaces[i].returnBuy()/2*1.1);
									allSpaces[i].updateMortgage();
									cout << "You have unmortgaged your " << removeSpaces(allSpaces[i].returnBrand()) << " " << removeSpaces(allSpaces[i].returnModel()) << "!\n";
									break; 
								}
							}
						}
					}
				}
			break;
			}

		} while (true);
	}
	
	
}

void Game_Board::updateBuses() {
	char owned[4];
	int counter = 5;
	int ownedcounter1 = 0;
	int ownedcounter2 = 0;
	char group1='5';
	char group2='5';
	for (int i = 0; i < 4; i++) {
		owned[i] = allSpaces[counter].returnPurchased();
		counter += 10;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = i+1; j < 4; j++) {
			if (owned[i] == owned[j]) {
				if (group1 == '5'){
					if (owned[i] != '0') {
						group1 = owned[i];	
					}
				}

				else if (owned[i] != group1) {
					if (owned[i] != '0'){
						group2 = owned[i];
					}
				}
			}
		}
	}

	for (int i = 0; i < 4; i++){
		if (owned[i] == group1) {
			ownedcounter1++;
		}
		else if (owned[i] == group2) {
			ownedcounter2++;
		}
	}

	for (int i = 5; i<40; i+=10) {
		if (allSpaces[i].returnPurchased() == group1) {
			allSpaces[i].updateMonopoly(ownedcounter1-1); 
			
		}

		else if (allSpaces[i].returnPurchased() == group2) {
			allSpaces[i].updateMonopoly(ownedcounter2-1);
			
		}

	}
	if (ownedcounter1 > 1) {
		cout << "Player " << group1 << " owns " << ownedcounter1 << " bus stops. Rent has been updated accordingly." << endl;
	}
	else if (ownedcounter2 > 1){
		cout << "Player " << group2 << " owns " << ownedcounter2 << " bus stops. Rent has been updated accordingly." << endl;
	}
}

Action Game_Board::retrieveActionClass(int space) {
	Action action = allSpaces[space].returnActionClass();
	return action;
}

string Game_Board::retrieveActionLines(int space) {
	string actionArray[3];
	allSpaces[space].returnAction(actionArray);

	if (allSpaces[space].returnActionType() == 0) { 
		return actionArray[0];
	}
	else if (allSpaces[space].returnActionType() == 1) {
		return actionArray[1] + allSpaces[space].returnPurchased() + actionArray[2] + ".\n";
	}
	return " ";
}


char Game_Board::retrievePurchased(int space) {
	return allSpaces[space].returnPurchased();
}

int Game_Board::retrieveBuy(int space) {
	return allSpaces[space].returnBuy();
}

int Game_Board::retrieveRent(int space) {
	return allSpaces[space].returnRent();
}

int Game_Board::retrieveMortgage(int space) {
	return allSpaces[space].returnMortgage();
}

bool Game_Board::retrieveMonopoly(int space) {
	return allSpaces[space].returnMonopoly();
}

int Game_Board::retrieveNumberofUpgrades(Player player) {
	int counter = 0;
	for (int i = 0; i < 40; i++) {
		if (i != 5 && i != 15 && i != 25 && i != 35 && i != 12 && i != 28) {
			int temp = player.retrieveProperty(i);
			if (temp == 1) {
				counter += allSpaces[i].returnUpgrade();
			}
		}
	}
	return counter;
}

void Game_Board::modifySpace(int space, int change) {
	allSpaces[space].modify(change);
}

void Game_Board::resetSpace(int space) {
	allSpaces[space].reset();
}

void Game_Board::printStats(Player player) {
	cout << "**** Player Statistics ****";
	player.realPrint();
	allSpaces[0].realPrint(allSpaces, player.returnNum());
	cout << "____________________\n";
}

void Game_Board::outputRow(int start, int end){ //output entire row

	cout << "  |";
	for (int i = 0; i < 11; i++) {
		//output top line of tile
		cout << "-----------------|";
	}

	cout  << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++) {
		//output color bar line
		int counter = counterIncrement(start, end, i);
		if (allSpaces[counter].returnColor()) {
			cout <<	"     Level: " << allSpaces[counter].returnUpgrade() << "    |";		
		}
		else {
			cout << "                 |";
		}
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++) {
		//output bottom of color bar line (if it exists)
		//check color bool to see if the space has a color bar
		int counter = counterIncrement(start, end, i);

		if (allSpaces[counter].returnColor() == true) {
			cout << "-----------------|";
		}
		else if (allSpaces[counter].returnColor() == false) {
			cout << "                 |";
		}
		
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output first line of name of tile
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << allSpaces[counter].returnBrand() << "|";
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output second line of name of tile
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << allSpaces[counter].returnModel() << "|" ;
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ) {
		//output price
		//reset counter
		int counter = counterIncrement(start, end, i);

		//check type of tile (ones that can be bought have buyPrice > 0)
		if (allSpaces[counter].returnBuy() > 0) {
			// 0 means tile is not owned
			if (allSpaces[counter].returnPurchased() == '0') {
				cout << "   Buy: $" << allSpaces[counter].returnBuy() << "   |";
			}

			// 1 means tile is owned and at basic rent (no upgrades)
			else if (allSpaces[counter].returnPurchased() == '1' || '2' || '3' || '4') {
				if (allSpaces[counter].returnRent() < 10000) {
					cout << "   Rent: $" << allSpaces[counter].returnRent() << "   |";
				}
				else if (allSpaces[counter].returnRent() < 100000) {
					cout << "  Rent: $" << allSpaces[counter].returnRent() << "   |";
				}
				else {
					cout << "  Rent: $" << allSpaces[counter].returnRent() << "  |";	
				}
				
			}	
		}

		else {
			cout << "                 |";
		}
	}
	cout << endl;

	cout << "  |";
	for (int i = 0; i < 11; i++ ){
		//output the owner of the space
		int counter = counterIncrement(start, end, i);
		if (allSpaces[counter].returnPurchased() == '1' || allSpaces[counter].returnPurchased() == '2'
		 || allSpaces[counter].returnPurchased() =='3' || allSpaces[counter].returnPurchased() =='4') {
			cout << "     Owner: " << allSpaces[counter].returnPurchased() << "    |";		
		}

		else {
			cout << "                 |";
		}
	}
	cout << endl;

	cout << "  |";


	for (int i = 0; i < 11; i++ ) {
		//output characters on tile (if any)
		//reset counter
		int counter = counterIncrement(start, end, i);

		cout << "       " << allSpaces[counter].returnPieces() << "      |" ;
	}
	
	cout << endl;
	cout << "  |";
	for (int i = 0; i < 11; i++) {
		//output bottom line of tile
		cout << "-----------------|";
	}
	cout << endl;
}

void Game_Board::outputColumn(int left, int right, bool bottom) {
	
	cout << "  |";

	//output color bar line
	if (allSpaces[left].returnColor()) {
		cout <<	"     Level: " << allSpaces[left].returnUpgrade() << "    |";		
	}
	else {
		cout << "                 |";
	}


	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";

	//output color bar line
	if (allSpaces[right].returnColor()) {
		cout <<	"     Level: " << allSpaces[right].returnUpgrade() << "    |";		
	}
	else {
		cout << "                 |";
	}


	cout << "\n  |";
	//output bottom of color bar line (if it exists)
	//check color bool to see if the space has a color bar
	if (allSpaces[left].returnColor() == true) {
		cout << "-----------------|";
	}
	else if (allSpaces[left].returnColor() == false) {
		cout << "                 |";
	}
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	if (allSpaces[right].returnColor() == true) {
		cout << "-----------------|";
	}
	else if (allSpaces[right].returnColor() == false) {
		cout << "                 |";
	}
	cout << endl;

	cout << "  |";
	//output first line of name of tile
	cout << allSpaces[left].returnBrand() << "|";
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << allSpaces[right].returnBrand() << "|";
	cout << endl;

	cout << "  |";
	//output second line of name of tile
	cout << allSpaces[left].returnModel() << "|" ;
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << allSpaces[right].returnModel() << "|" ;
	cout << endl;

	cout << "  |";
	//output price
	//check type of tile (ones that can be bought have buyPrice > 0)
	if (allSpaces[left].returnBuy() > 0) {
		// 0 means tile is not owned
		if (allSpaces[left].returnPurchased() == '0') {
			if (allSpaces[left].returnBuy() < 100000){
				cout << "   Buy: $" << allSpaces[left].returnBuy() << "   |";
			}
			else {
				cout << "  Buy: $" << allSpaces[left].returnBuy() << "   |";
			}
		}

		// 1 means tile is owned and at basic rent (no upgrades)
		else if (allSpaces[left].returnPurchased() == '1' || '2' || '3' || '4') {
			if (allSpaces[left].returnRent() < 10000){
				cout << "   Rent: $" << allSpaces[left].returnRent() << "   |";
			}
			else if (allSpaces[left].returnRent() < 100000) {
				cout << "  Rent: $" << allSpaces[left].returnRent() << "   |";
			}
			else {
				cout << "  Rent: $" << allSpaces[left].returnRent() << "  |";	
			}
			
		}	
	}

	else {
		cout << "                 |";
	}
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	if (allSpaces[right].returnBuy() > 0) {
		// 0 means tile is not owned
		if (allSpaces[right].returnPurchased() == '0') {
			if (allSpaces[right].returnBuy() < 100000){
				cout << "   Buy: $" << allSpaces[right].returnBuy() << "   |";
			}
			else {
				cout << "  Buy: $" << allSpaces[right].returnBuy() << "   |";
			}
		}

		// 1 means tile is owned and at basic rent (no upgrades)
		else if (allSpaces[right].returnPurchased() == '1' || '2' || '3' || '4') {
			if (allSpaces[right].returnRent() < 10000){
				cout << "   Rent: $" << allSpaces[right].returnRent() << "   |";
			}
			else if (allSpaces[right].returnRent() < 100000) {
				cout << "  Rent: $" << allSpaces[right].returnRent() << "   |";
			}
			else {
				cout << "  Rent: $" << allSpaces[right].returnRent() << "  |";	
			}
			
		}	
	}

	else {
		cout << "                 |";
	}
	cout << endl;

	cout << "  |";

	//output owner of space (if any)
	if (allSpaces[left].returnPurchased() == '1' || allSpaces[left].returnPurchased() =='2'
	 || allSpaces[left].returnPurchased() =='3' || allSpaces[left].returnPurchased() =='4') {
		cout << "     Owner: " << allSpaces[left].returnPurchased() << "    |";		
	}

	else {
		cout << "                 |";
	}
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	if (allSpaces[right].returnPurchased() == '1' || allSpaces[right].returnPurchased() =='2' || 
		allSpaces[right].returnPurchased() =='3' || allSpaces[right].returnPurchased() =='4') {
		cout << "     Owner: " << allSpaces[right].returnPurchased() << "    |";		
	}

	else {
		cout << "                 |";
	}
	
	cout << endl;

	cout << "  |";


//output characters on tile (if any)
	cout << "       " << allSpaces[left].returnPieces() << "      |" ;
	//create the space in the middle of the board
	for (int i = 0; i < 8; i++) { 
		cout << "                  ";
	}
	cout << "                 |";
	cout << "       " << allSpaces[right].returnPieces() << "      |" ;

	cout << endl;

	if (!bottom) {
		cout << "  |";
		//output bottom line of tile
		cout << "-----------------|";
		//create the space in the middle of the board
		for (int i = 0; i < 8; i++) { 
			cout << "                  ";
		}
		cout << "                 |";
		cout << "-----------------|";
		cout << endl;
	}
}

void Game_Board::print_Board() {
	outputRow(20, 30); //outputs the top row
	for (int i = 0; i < 8; i++) {
		outputColumn(19-i, 31+i, false); //outputs the first 8 rows of the column
	}
	outputColumn(11, 39, true);//outputs the last row fo the column with true bool telling function it is the last row of the column
	outputRow(10, 0); //outputs the bottom row

}