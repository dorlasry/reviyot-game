

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
        int PlayerType;

public:
	Player(string n, int PType);
	Player(const Player &p);
        virtual ~Player();
        string getName() ;
        string getNameC() const;
        virtual Card* ask()=0;
	string toString();
        int getPlayerType() const;


};

class PlayerType1 : public Player { //For strategy 1
public:
	PlayerType1(string np1, int PType);
	PlayerType1(const PlayerType1 &p1);
	PlayerType1(const Player &p);
        virtual ~PlayerType1();
        Card*  theCommonCard();
	virtual Card* ask();
};

class PlayerType2 : public Player {  //For strategy 2
public:
	PlayerType2(string np2, int PType);
        PlayerType2(const PlayerType2 &p2);
	PlayerType2(const Player &p2);
        virtual ~PlayerType2();
        Card*  theUnCommonCard();
        virtual Card* ask();
};

class PlayerType3 : public Player {  //For strategy 3
public:
	PlayerType3(string np3, int PType);
        PlayerType3(const PlayerType3 &p3);
	PlayerType3(const Player &p3);
        virtual ~PlayerType3();
        Card*  theMaxValueCard();
        virtual Card* ask();
};

class PlayerType4 : public Player {  //For strategy 4
public:
	PlayerType4(string np4, int PType);
        PlayerType4(const PlayerType4 &p4);
	PlayerType4(const Player &p4);
        virtual ~PlayerType4();
	Card*  theMinValueCard();
	virtual Card* ask();


};

#endif


