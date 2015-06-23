// monopoly.cpp

#include "space.h"
#include "player.h"
#include "bank.h"
#include "card.h"
#include "gameboard.h"
#include "action.h"
#include "community.h"
#include "chance.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <vector>
#include <cmath>


using namespace std;

const int NUMSPACES = 40;
vector<Player> players;
Bank bank;
string Pieces = "1234!@#%^&*+~$";
char decision;
Game_Board board;
int PlayersAlive = 0;

int nomoneyMenu() {
	//menu that outputs when no money is left. not used as mortgaging doesn't work.
	cout << "    Choices    \n";
	cout << "---------------\n";
	cout << "1. Mortgage Car\n";
	cout << "2. Surrender to Opponent\n";
	int number;
	do {
		cout << "Please choose an option from the menu.\n";
		cin >> number;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid input." << endl;
			continue;
		}

		else if (number < 0 || number > 2) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is an invalid number." << endl;
			continue;
		}

		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);
	return number;
}

void nomoneyAction(int i, int iOwner) {
	//int decision = 0;
	//decision = nomoneyMenu();
	//if (decision == 1) {
	//	board.mortgage(&players[i], &bank);

	//}
	//else if (decision == 2) {

	//surrenders everything the player owns to the player that he/she owes (surrendering)
		for (int j = 0; j < NUMSPACES; j++) {
			int temp = players[i].retrieveProperty(j);
			if (temp == 1) {
				board.modifySpace(j, iOwner+1);
			}
		}
		cout << "You have transferred all of your cars to Player " << players[iOwner].returnNum() << ".\n";
		int money = players[i].retrieveWealth();
		players[i].deductMoney(money);
		players[iOwner].addMoney(money);
		cout << "You have given all your money to Player " << players[iOwner].returnNum() << ".\n";
		players[i].updateDead();
		PlayersAlive--;
		cout << "You are out of the game.\n";
	//}
}


int decisionMenu(int currentplayer) {
	//menu that is output showing players their choices in the beginning of their round
	cout << "Player " << players[currentplayer].returnNum() << ", it is your turn." << endl;
	cout << "    Menu    \n";
	cout << "------------\n";
	cout << "1. Roll the Die\n";
	cout << "2. Upgrade Property\n";
	cout << "3. Unmortgage Property\n";
	cout << "4. See your Statistics\n";
	cout << "5. Resign\n";
	int number;
	do {
		cout << "Please choose an option from the menu.\n";
		cin >> number;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid input." << endl;
			continue;
		}

		else if (number < 0 || number > 5) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is an invalid number." << endl;
			continue;
		}

		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);
	return number;
}

int decisionMenu2(int currentplayer) {
	//menu that is output after dice has been rolled
	cout << "Player " << players[currentplayer].returnNum() << ", it is still your turn." << endl;
	cout << "    Menu    \n";
	cout << "------------\n";
	cout << "****1. Roll the Die\n";
	cout << "2. Upgrade Property\n";
	cout << "3. Unmortgage Property\n";
	cout << "4. See your Statistics\n";
	cout << "5. Resign\n";
	cout << "6. End Turn\n";
	int number;
	do {
		cout << "Please choose an option from the menu.\n";
		cin >> number;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid input." << endl;
			continue;
		}

		else if (number < 0 || number > 6) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is an invalid number." << endl;
			continue;
		}

		else if (number == 1) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "You've already rolled. Pick a different option!\n";
		}

		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);
	return number;
}


bool rollJail(int* numbers) {
	//roll dice for jail use
	//if double is rolled, player is released
	int dice1 = rand()%5 + 1;
	int dice2 = rand()%5 + 1;
	numbers[0] = dice1;
	numbers[1] = dice2;
	if (dice1 == dice2) {
		return true;
	}

	else {
		return false;
	}
}

int rollDie () {
	//normal roll function that simulates rolling two 2 sided die
	int dice1 = rand()%5 + 1;
	int dice2 = rand()%5 + 1;
	return dice1+dice2;
	//return 1;
}	

int main() {

	srand (time(0));

	cout << "Welcome to Monopoly 2014 Cars Edition!" << endl;
	int numPlayers;
	do {
		cout << "How many players are playing? ";
		cin >> numPlayers;
		cout << endl;

		if (cin.fail()){
			cin.clear();
			cin.ignore (10000, '\n');
			cout << "That is an invalid input." << endl;
			continue;
		}

		else if (numPlayers < 2 || numPlayers > 4) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "That is an invalid number of players." << endl;
			continue;
		}

		else{
			cin.ignore (10000, '\n');
			break;
		}

	} while (true);

	//dynamically allocate player array
	//players = new Player[numPlayers];
	PlayersAlive = numPlayers;
	char piece;
	for (int i = 0; i < numPlayers; i++) {
		do {
			cout << "These are the avaiable pieces: " << Pieces << endl;
			cout << "Player " << i+1 << ", choose your playing piece: ";
			cin >> piece;
			size_t found = Pieces.find(piece);
			cout << endl;

			if (cin.fail()){
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "You must enter a single character." << endl;
				continue;
			}

			else if (found == string::npos) {
				cin.clear();
				cin.ignore (10000, '\n');
				cout << "You must choose from the list of pieces provided!" << endl;
				continue;
			}

			else{
				cin.ignore (10000, '\n');
				Pieces.erase (found, 1);
				break;
			}

		} while (true);

		players.push_back(Player(piece, i+1, 0, -1, 400000, 0, 0, 0, 0));
		//players[i].populate(piece, i+1, 0, -1, 400000, 0, 0, 0, 0);
	}

	//initialize bank
	bank.initialize(999999999);

	//populate spaces array with information
	Game_Board board (NUMSPACES);


	//populate cards
	Community communitydeck;
	Chance chancedeck;
	communitydeck.shuffle();
	chancedeck.shuffle();

	//start of game -- round 0.
	
	//GAME LOOP!!!
	while (PlayersAlive > 1) {
		for (int i = 0; i < numPlayers; i++){
			board.updateSpaces(players, numPlayers); // updates the board
			board.print_Board(); //prints board for the first time
			cout << "\n\n<^><^><^><^><^><^><^><^><^><^><^><^><^><^>\n";
			int superCounter = 0;
			int superDecision = 0;
		do {
			if (superDecision == 6) { //player resigns
				break;
			} 
			if (players[i].retrieveDead()) { //resigned players get their turns skipped
				break;
			}
			//each player takes their turn in order
			do {
				if (superCounter == 0) {
					superDecision = decisionMenu(i); //players choose from the decision menu
					superCounter++;
				}

				else {
					superDecision = decisionMenu2(i); // this menu pops up after the player has rolled 
				}
				
				if (superDecision == 2) { //upgrades cars
					board.updateUpdate(&players[i], &bank);
				}

				else if (superDecision == 3) { //unmortgages (does nothing as mortgaging doesn't work properly)
					board.unMortgage(&players[i], &bank);
				}

				else if (superDecision == 4) { //prints player stats
					board.printStats(players[i]);
				}

				else if (superDecision == 6) { //player has decided to end turn
					break;
				}

				else if (superDecision == 5) { //player has decided to resign
					char decision;
					do {
						cout << "Are you sure you'd like to resign?? (y/n) ";
						cin >> decision;
						cout << endl;

						if (cin.fail()){
							cin.clear();
							cin.ignore (10000, '\n');
							cout << "That is an invalid input." << endl;
							continue;
						}

						else if (decision != 'y' && decision !='Y' && decision !='n' && decision !='N') {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Please enter Y/N." << endl;
							continue;
						}

						else{
							cin.ignore (10000, '\n');
							break;
						}

					} while (true);

					if (decision == 'y' || decision == 'Y') {
						for (int j = 0; j < NUMSPACES; j++) {
							int temp = players[i].retrieveProperty(j);
							if (temp == 1) {
								board.resetSpace(j); //all owned spaces are reset to original states
							}
						}
						cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
						int money = players[i].retrieveWealth();
						players[i].deductMoney(money);
						bank.addFunds(money);
						cout << "You have given all your money to the bank.\n";
						players[i].updateDead();
						PlayersAlive--;
						cout << "You are out of the game.\n";
						break;
					}
				
				}

			} while(superDecision != 1);

			if (superDecision == 1) {
			
			superDecision = 7;
			Action action = board.retrieveActionClass(players[i].returnSpace());
			int rolled[2]; 
			//check to see if player is in jail
			if (players[i].retrieveJail() == 1 && players[i].retrieveCounter() < 3) {
				if (players[i].retrieveJailfree() == 1) { //if player has get out of jail free
					cout << "Player " << players[i].returnNum() << ", you are in jail, but you have a 'Get Out of Jail Free' card. " << endl;
					do {
						cout << "Would you like to use it?";
						cin >> decision;
						cout << endl;

						if (cin.fail()){
							cin.clear();
							cin.ignore (10000, '\n');
							cout << "That is an invalid input." << endl;
							continue;
						}

						else if (decision != 'y' && decision !='Y' && decision !='n' && decision !='N') {
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Please enter Y/N." << endl;
							continue;
						}

						else{
							cin.ignore (10000, '\n');
							break;
						}

					} while (true);

					if (decision == 'Y' || decision == 'y') {
						players[i].updateJail(0);
						cout << "You are released!" << endl;
						if (communitydeck.returnNum() == 15) {
							communitydeck.updateNum(16);	
						}
						else if (chancedeck.returnNum() == 15) {
							chancedeck.updateNum(16);
						}
					}
				}
				//if player does not have get out of jail free, must roll double or wait three turns
				cout << "Player " << players[i].returnNum() << ", you are in jail. You must roll a double to get out early or wait 3 turns." << endl;
				cout << "\n\nPress enter to roll the die.";
				cin.ignore(10000, '\n');
				bool criminalStatus = rollJail(rolled);
				if (criminalStatus) {
					players[i].updateJail(0);
					cout << "Dice #1: " << rolled[0] << endl;
					cout << "Dice #2: " << rolled[1] << endl;
					cout << "You rolled a double! You are released!" << endl;
				}
				else {
					players[i].updateJailcounter();
					string message;
					stringstream ss;
					ss << 3-players[i].retrieveCounter();
					ss >> message;
					cout << "Dice #1: " << rolled[0] << endl;
					cout << "Dice #2: " << rolled[1] << endl;
					if (message != "0") {
						cout << "You failed to roll a double. You must wait for " << message << " more turns." << endl;
					}
					else {
						cout << "You failed to roll a double. However, you have served your full sentence and have been released." << endl;
					}
					
				}
			}
			

			if (players[i].retrieveCounter() == 3) {
				players[i].updateJail(0);
			}
			//if not in jail, normal game code runs
			if (players[i].retrieveJail() == 0){
				cout << "Player " << players[i].returnNum() << ", press enter to roll the die. ";
				cin.ignore(10000, '\n');
				int moves = rollDie();
				bool passGo = players[i].updateInfo(moves);
				board.updateSpaces(players, numPlayers);
				//board.print_Board();
				cout << "Player " << players[i].returnNum() << ", you advance " << moves << " spaces." << endl;
				

		bool test = true;
		while (test) {
			test = false;

				Action action = board.retrieveActionClass(players[i].returnSpace());
				
				if (passGo){
					players[i].addMoney(40000);
					cout << "You passed go and received $40,000!" << endl;
				}

				int currentSpace = players[i].returnSpace();
				string actionText = board.retrieveActionLines(currentSpace);
				cout << actionText << endl; //output the description of the space
				int type = action.retrieveType(); //retrieve the type of action that should occur

				if (type == 0) { // land on a car that is available for purchase
					char decision;
					if (players[i].retrieveWealth() < board.retrieveBuy(currentSpace)) {
						cout << "You do not have enough money to purchase this." << endl;
					}

					else {
						do {
							cout << "Would you like to make this purchase? (Y/N): ";
							cin >> decision;
							cout << endl;

							if (cin.fail()){
								cin.clear();
								cin.ignore (10000, '\n');
								cout << "That is an invalid input." << endl;
								continue;
							}

							else if (decision != 'y' && decision !='Y' && decision !='n' && decision !='N') {
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Please enter Y/N." << endl;
								continue;
							}

							else{
								cin.ignore (10000, '\n');
								break;
							}

						} while (true);
					}

					if (decision == 'Y' || decision == 'y') {
						board.modifySpace(currentSpace, players[i].returnNum()); //changes space so that it is owned
						int cost = board.retrieveBuy(currentSpace); //retrieve cost of purchase
						players[i].deductMoney(cost); //player gives money to bank
						bank.addFunds(cost);
						players[i].updateProperty(currentSpace); //player is updated
						cout << "You have purchased the space!" << endl;
						if (currentSpace == 12 || currentSpace == 28) {
							board.updateAction(currentSpace, 7); //space action is updated
						}
						else {
							board.updateAction(currentSpace, 1);	
						}
						board.updateMonopoly(); // check for monopoly
						board.updateBuses(); // check for owning more than 1 bus stop
						decision = 'N';
					}

				}// end of type 0

				else if (type == 1) { //land on space that is owned
					int rental = board.retrieveRent(currentSpace); //get rent cost
					char owner = board.retrievePurchased(currentSpace); //get owner
					int iOwner = (owner - '0');
					bool mortgage = board.retrieveMortgage(currentSpace);
					iOwner --;

					if (i == iOwner) {
						cout << "Just kidding! This is your space!" << endl;
					}

					else if (players[i].retrieveWealth() < rental && !mortgage) {
						cout << "Uh oh! You do not have enough money to pay for the rental." << endl;
						//board.printStats(players[i]);
						nomoneyAction(i, iOwner); //lose
							
					}

					else if (!mortgage) {
						players[i].deductMoney(rental); //money is exchanged
						players[iOwner].addMoney(rental);
						cout << "You have paid for the rental." << endl;
					}
				}// end of type 1 (pay rent)

				else if (type == 2) { //outputing descriptors for spaces that do not have an action
					if (currentSpace == 0) {
						cout << "You've landed on Go!\n";
					}

					else if (currentSpace == 10) {
						cout << "You're visitng the jail.\n";
					}

					else if (currentSpace == 20) {
						cout << "You're at free parking!\n";
					}

				}

				else if (type == 3) { //community chest space
					cout << "You draw a card from the community chest." << endl;
					int cardType = communitydeck.returnType(); //retrieve type
					int value = communitydeck.returnValue(); //retrieve value
					//communitydeck.printDeck();
					communitydeck.print(); //print descriptors
					//communitydeck.execaction(&players[i], &bank);
					
					if (cardType == 1) { //type 1 = money is given or taken
						if (value < 0) { //if money is taken, must check if player can pay
							if (players[i].retrieveWealth() < abs(value)){// if not, player loses
								cout << "You cannot afford to pay the amount.\n";
								for (int j = 0; j < NUMSPACES; j++) {
									int temp = players[i].retrieveProperty(j);
									if (temp == 1) {
										board.resetSpace(j);
									}
								}
								cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
								int money = players[i].retrieveWealth();
								players[i].deductMoney(money);
								bank.addFunds(money);
								cout << "You have given all your money to the bank.\n";
								players[i].updateDead();
								PlayersAlive--;
								cout << "You are out of the game.\n";
							}
						}
						else {
						players[i].addMoney(value); //money is exchanged
						bank.deductFunds(value);
						}
					}

					else if (cardType == 2) { //type 2 = money is given to 1 player from all other players
						for (int a = 0; a < numPlayers; a++){
							players[i].addMoney(value);	
						}
						for (int j = 0; j < numPlayers; j++) {
							if (players[j].retrieveWealth() < value) {
								nomoneyAction(j, i);
							}
							else {
								players[j].deductMoney(value);
							}
							
						}
							
					}

					else if (cardType == 3) { // car repairs for each upgrade
						int upgrades = 1000*board.retrieveNumberofUpgrades(players[i]);

						if (players[i].retrieveWealth() < abs(upgrades)){
							cout << "You cannot afford to pay the amount.\n";
							for (int j = 0; j < NUMSPACES; j++) {
								int temp = players[i].retrieveProperty(j);
								if (temp == 1) {
									board.resetSpace(j);
								}
							}
							cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
							int money = players[i].retrieveWealth();
							players[i].deductMoney(money);
							bank.addFunds(money);
							cout << "You have given all your money to the bank.\n";
							players[i].updateDead();
							PlayersAlive--;
							cout << "You are out of the game.\n";
						
						}
						else {
						players[i].deductMoney(upgrades);
						bank.addFunds(upgrades);
						}
					}

					else if (cardType == 4) { // go to jail
						players[i].updateMovement(10);
						players[i].updateJail(1);
					}

					else if (cardType == 5) { // get out of jail free card
						players[i].updateJailfree(1);
					}

					else if (cardType == 6) { // go to go
						players[i].updateMovement(0);
						players[i].addMoney(value);
					}

					communitydeck.reArrange();

					if (cardType == 5) { // if out of jail free card is taken, deck shrinks until card is used
						communitydeck.updateNum(15);
					}
				}

				else if (type == 6) { //chance deck
					cout << "You draw a card from chance." << endl;
					int cardType = chancedeck.returnType();
					int value = chancedeck.returnValue();
					//chancedeck.printDeck();
					chancedeck.print();
					//chancedeck.execaction(&players[i], &bank);
					
					if (cardType == 1) { //money given or taken
						if (value < 0) {
							if (players[i].retrieveWealth() < abs(value)){
								cout << "You cannot afford to pay the amount.\n";
								for (int j = 0; j < NUMSPACES; j++) {
									int temp = players[i].retrieveProperty(j);
									if (temp == 1) {
										board.resetSpace(j);
									}
								}
								cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
								int money = players[i].retrieveWealth();
								players[i].deductMoney(money);
								bank.addFunds(money);
								cout << "You have given all your money to the bank.\n";
								players[i].updateDead();
								PlayersAlive--;
								cout << "You are out of the game.\n";
								
							}
						}
						else {
						players[i].addMoney(value);
						bank.deductFunds(value);
						}	
					}

					else if (cardType == 2) { //same as type 2 for community
		
						for (int a = 0; a < numPlayers; a++){
							players[i].addMoney(value);	
						}
						for (int j = 0; j < numPlayers; j++) {
							if (players[j].retrieveWealth() < value) {
								nomoneyAction(j, i);
							}
							else {
								players[j].deductMoney(value);
							}
							
						}
							
					}

					else if (cardType == 3) { // pay for car repairs per upgrade
						int upgrades = 625*board.retrieveNumberofUpgrades(players[i]);

						
						if (players[i].retrieveWealth() < abs(upgrades)){
							cout << "You cannot afford to pay the amount.\n";
							for (int j = 0; j < NUMSPACES; j++) {
								int temp = players[i].retrieveProperty(j);
								if (temp == 1) {
									board.resetSpace(j);
								}
							}
							cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
							int money = players[i].retrieveWealth();
							players[i].deductMoney(money);
							bank.addFunds(money);
							cout << "You have given all your money to the bank.\n";
							players[i].updateDead();
							PlayersAlive--;
							cout << "You are out of the game.\n";
		
						}
					
						else {
						players[i].deductMoney(upgrades);
						bank.addFunds(upgrades);
						}
					}

					else if (cardType == 4) { // go to jail
						players[i].updateMovement(10);
						players[i].updateJail(1);
					}

					else if (cardType == 5) { // get out of jail free
						players[i].updateJailfree(1);
					}

					else if (cardType == 6) { // go to go
						players[i].updateMovement(0);
						players[i].addMoney(value);
					}

					else if (cardType == 7) { // go to space
						passGo = players[i].updateMovement(value);
						test = true;
					}

					else if (cardType ==8) { // go to nearest taxi
						int curspace = players[i].returnSpace();
						int distance1 = abs(curspace-12);
						int distance2 = abs(curspace-28);
						if (distance1 < distance2) {
							players[i].updateMovement(12);
						}
						else {
							players[i].updateMovement(28);
						}
						test = true;
					}

					else if (cardType == 9) { // go to nearest bus stop
						int curspace = players[i].returnSpace();
						int distance[4];
						int counter = 0;
						for (int j = 5; j<37; j+=10) {
							distance[counter] = abs(curspace-j);
							counter++;
						}
						int smallest = distance[0];
						int smallestlocation = 0;
						for (int j = 1; j < 4; j++) {
							if (distance[j] < smallest) {
								smallest = distance[j];
								smallestlocation = j;
							}
						}

						if (smallestlocation == 0) {
							players[i].updateMovement(5);
						}

						else if (smallestlocation == 1) {
							players[i].updateMovement(15);
						}

						else if (smallestlocation == 2) {
							players[i].updateMovement(25);
						}

						else if (smallestlocation == 3) {
							players[i].updateMovement(35);
						}
						test = true;
					}

					else if (cardType == 10) { // go back number of spaces
						players[i].updateInfo(value);
						test = true;
					}

					chancedeck.reArrange();

					if (cardType == 5) {
						chancedeck.updateNum(15);
					}
				}

				else if (type == 4) { //income tax
					char decision;
					if (players[i].returnSpace() == 4) {
						do {
							cout << "Would you like to pay $40,000 or 10% of your total assets (cash on hand, property and upgrades)? (M for $40,000 or A for assets): ";
							cin >> decision;
							cout << endl;

							if (cin.fail()){
								cin.clear();
								cin.ignore (10000, '\n');
								cout << "That is an invalid input." << endl;
								continue;
							}

							else if (decision != 'm' && decision !='M' && decision !='a' && decision !='A') {
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Please enter M/A." << endl;
								continue;
							}

							else{
								cin.ignore (10000, '\n');
								break;
							}

						} while (true);

						if (decision == 'M' || decision == 'm') { //choose to pay $40,000
							if (players[i].retrieveWealth() < 40000){
								cout << "You cannot afford to pay the amount.\n";
								for (int j = 0; j < NUMSPACES; j++) {
									int temp = players[i].retrieveProperty(j);
									if (temp == 1) {
										board.resetSpace(j);
									}
								}
								cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
								int money = players[i].retrieveWealth();
								players[i].deductMoney(money);
								bank.addFunds(money);
								cout << "You have given all your money to the bank.\n";
								players[i].updateDead();
								PlayersAlive--;
								cout << "You are out of the game.\n";
							
							}
							else {


							players[i].deductMoney(40000);
							bank.addFunds(40000);
							cout << "You have given $40,000 to the bank." << endl;
							}
						}

						else if (decision == 'A' || decision == 'a') { //choose to pay 10% of all assets
							int assets = 0;
							assets += players[i].retrieveWealth();
							for (int j = 0; j < 40; j++){
								if (players[i].retrieveProperty(j) == 1){
									assets += board.retrieveBuy(j);
								}
							}

							int tenPercent = assets*0.10;
							if (players[i].retrieveWealth() < tenPercent){
								for (int j = 0; j < NUMSPACES; j++) {
									int temp = players[i].retrieveProperty(j);
									if (temp == 1) {
										board.resetSpace(j);
									}
								}
								cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
								int money = players[i].retrieveWealth();
								players[i].deductMoney(money);
								bank.addFunds(money);
								cout << "You have given all your money to the bank.\n";
								players[i].updateDead();
								PlayersAlive--;
								cout << "You are out of the game.\n";
								
							}
							else {


							players[i].deductMoney(tenPercent);
							bank.addFunds(tenPercent);
							string output;
							stringstream ss;
							ss << tenPercent;
							ss >> output;
							cout << "You have given $" << output << " to the bank." << endl;
							}
						}
					}//end of income tax
					
					else { //pay luxury tax ($15,000)
						int luxTax = 15000;
						if (players[i].retrieveWealth() < luxTax){
								cout << "You cannot afford to pay the amount.\n";
								for (int j = 0; j < NUMSPACES; j++) {
									int temp = players[i].retrieveProperty(j);
									if (temp == 1) {
										board.resetSpace(j);
									}
								}
								cout << "All of your cars are now owned by the bank and can be repurchased. Any upgrades have been undone.\n";
								int money = players[i].retrieveWealth();
								players[i].deductMoney(money);
								bank.addFunds(money);
								cout << "You have given all your money to the bank.\n";
								players[i].updateDead();
								PlayersAlive--;
								cout << "You are out of the game.\n";
						
						}
						else{
						players[i].deductMoney(luxTax);
						bank.addFunds(luxTax);
						cout << "You have given $" << luxTax << " to the bank for luxury tax." << endl;
						}
					}//end of luxury tax

				}//end of type 4 (tax)

				//if player lands on gotojail, player is sent to jail
				else if (type == 5) {
					players[i].updateMovement(10);
					players[i].updateJail(1);
					cout << "You are sent to jail!" << endl;

				}//end of type 5 (jail)

				else if (type == 7) { // taxi space mechanism 
					int rental;
					if (board.retrieveMonopoly(currentSpace)) {
						rental = moves*2000;
					} 

					else {
						rental = moves*800;
					}

					char owner = board.retrievePurchased(currentSpace);
					int iOwner = (owner - '0');
					bool mortgage = board.retrieveMortgage(currentSpace);
					iOwner --;

					if (i == iOwner) {
						cout << "Just kidding! This is your space!" << endl;
					}

					else if (players[i].retrieveWealth() < rental && !mortgage) {
						cout << "Uh oh! You do not have enough money to pay for the rental." << endl;
						//board.printStats(players[i]);
						nomoneyAction(i, iOwner);
						

					}

					else if (!mortgage) {
						players[i].deductMoney(rental);
						players[iOwner].addMoney(rental);
						cout << "You have paid for the rental (based on the number you rolled.)" << endl;
					}
				}
					

			}

		}
			//cout << "\n\nEnd of Turn Statistics\n";
			//board.printStats(players[i]);
		//	board.updateSpaces(players, numPlayers);
		//	board.print_Board();
			}

		
		} while (true);
		}
	

	}
	cout << "***** *   * **\n";
	cout << "*     **  * *  *\n";
	cout << "***** * * * *   *\n";
	cout << "*     *  ** *  *\n";
	cout << "***** *   * **\n";
	cout << "Player " << players[0].returnNum() << " wins!\n";
	//delete [] players;
	return 0;
}