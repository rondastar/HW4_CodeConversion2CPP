#include "Player.h" // Player class header
#include <iostream>
#include <string>
#include <vector>

std::vector<Player> g_players;

void setGPlayersCapacity(int capacity) {
	g_players.reserve(capacity);	//Sets the g_players vector capacity to the specified size
}

void addPlayer(std::string name, int num) {
	Player newPlayer = Player{ name, num }; // Creates an object of Player using the args
	g_players.push_back(newPlayer);			// Adds new player to end of vector; resizes vector if needed
}

void prepopulatePlayers() {		// Prepopulates the g_players vector with 5 player objects
	addPlayer("Arancelli", 14);
	addPlayer("Monster", 43);
	addPlayer("Hu", 8);
	addPlayer("Kernster", 57);
	addPlayer("Adnor", 33);
}

void displayPlayer(int i) {
	std::cout << g_players[i].getName() << ' ' << g_players[i].getNumber() << std::endl;
}

void displayAllPlayers() {		// Prints list of names and numbers of all players in the g_players vector
	for (int i = 0; i < g_players.size(); i++)
	{
		displayPlayer(i);
	}
}

// Checks if each player has an odd number, and prints names and numbers of players with odd numbers
void displayPlayersWithOddNumbers() {
	for (int i = 0; i < g_players.size(); i++)
	{
		if (g_players[i].getNumber() % 2 != 0) {
			displayPlayer(i);
		}
	}
}

// Checks if each player has a name starting with a given letter; if true, prints name and number of player
// Informs user if no player has a name starting with the letter.
// NOTE: Case-sensitive! Letter must be capitalized to match with player names.
void displayPlayersStartingWithLetter(char c) {
	bool letterNotFound{ true };
	for (int i = 0; i < g_players.size(); i++)
	{
		if (g_players[i].getName()[0] == c) {
			displayPlayer(i);
			letterNotFound = false;
		}
	}
	if (letterNotFound) {
		std::cout << "There is no player name starting with that letter." << std::endl;
	}
}

int userNumberSelection() { // Prompts user for number of selection and returns number. Used for main menu selection.

	std::cout << "Please enter the number for your selection: ";
	int userNum;
	std::cin >> userNum;
	return userNum;
}

char userCapitalLetter() { // Prompts user for a letter and returns the letter. Used to display player names starting with the letter.

	std::cout << "Please enter a capital letter: ";
	char userChar;
	std::cin >> userChar;
	return userChar;
}

// Prompts user for a capital letter and then displays players whose names start with that letter.
void usersdDisplayPlayersStartingWithLetter() {
	displayPlayersStartingWithLetter(userCapitalLetter());
}

void userAddNewPlayer() {
	std::cout << "Please enter player's name (begin with a capital letter): ";
	std::string userName;
	std::cin >> userName;
	std::cout << "Please enter player's number (must be an integer): ";
	int userNum;
	std::cin >> userNum;
	addPlayer(userName, userNum);
}

void displayMenu() {	// displays main menu
	std::cout << "MAIN MENU\n"
		"1 - Display all players\n"
		"2 - Display players with odd numbers\n"
		"3 - Display players starting with a letter\n"
		"4 - Add a new player\n";
}

void mainMenuSelection(int x) {		// see displayMenu() for menu options
	switch (x) {
	case 1:
		displayAllPlayers();
		return;
	case 2:
		displayPlayersWithOddNumbers();
		return;
	case 3:
		usersdDisplayPlayersStartingWithLetter();
		return;
	case 4:
		userAddNewPlayer();
		return;
	default:
		std::cout << "Invalid selection. \n";
		return;
	}
}

void runMainMenu() {
	displayMenu();		// Displays the main menu

	// Prompts the user to enter the number for their selection
	// Calls the function for users selection
	mainMenuSelection(userNumberSelection());
	std::cout << std::endl; // Adds a blank line for readability when menu refreshes
	runMainMenu();
}

int main() {
	setGPlayersCapacity(7);
	prepopulatePlayers();
	runMainMenu();

	return 0;
}