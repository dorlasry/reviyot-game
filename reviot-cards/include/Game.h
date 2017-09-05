
#ifndef MYGAME_H_
#define MYGAME_H_



#include <iostream>

#include "Player.h"
#include "Deck.h"
#include <vector>

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck,garbage;                 //The deck of the game
	string configFile;
	int numOfPlayers=0;
        int winner1=-1, winner2=-1;
        int numTurns=0;
        bool winner=0;
        bool verbal=0;
public:
	Game(char* configurationFile);
        Game(const Game &g);
        virtual ~Game();
        void init();
	void addPlayer(Player* p);
	int getNumOfPlayers();
        int getNumOfPlayersC() const;
        string getConfigFile() const;
        Deck getDeck() const;
	void disCards();
	void play();
	void turn(int numTurn);
        void throwFour(int numPlayer, Card* c);
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
        void printNumberOfTurns(); //Print the number of played turns at any given time.
        int maxCardsHigh(int numPlayer);



};

#endif


