
#include "Player.h"
#include "Game.h"

using namespace std;

/*
 * Player's constructor
 */ 
Player::Player(string n, int PType): name(n), PlayerType(PType){}

/*
 * This function returns the Player's name
 * @return name - the Player's name
 */
string Player::getName() 
{
    return name;
}

/*
 * This function returns the Player's name (needed for Player's copy constructor because the name is 'const') /
 * @return name - the Player's name
 */
string Player::getNameC() const
{
    return name;
}

/*
 * Player's copy constructor
 */
Player::Player(const Player &p): Hand(p), name(p.getNameC()), PlayerType(p.getPlayerType()){}

/*
 * Player's destructor
 */
Player:: ~Player(){}

/*
 * This function returns a string representation of the Player.
 */
string Player::toString()
{
    return name+ ": " +Hand::toString();
}

/*
 * This function returns the Player's type.
 */
int Player::getPlayerType() const
{
    return PlayerType;
}

/*
 * PlayerType1's constructor
 */
PlayerType1::PlayerType1(string np1, int PType): Player(np1,PType){}

/*
 * PlayerType1's copy constructor
 */
PlayerType1::PlayerType1(const PlayerType1 &p1): Player(p1){}

/*
 * PlayerType1's (copy) constructor when the Player's type isn't known
 */
PlayerType1::PlayerType1(const Player &p):Player(p){}

/*
 * PlayerType1's destructor
 */
PlayerType1:: ~PlayerType1(){}


/*
 * This function returns the (higher) most common card fo the Player.
 * @return cMax - a pointer to the Card
 */
Card* PlayerType1:: theCommonCard()
{
    list<Card*> lc=this->getList();
    int countShape=1, maxi=0;
    Card* cMax;
    std::list<Card*>::iterator temp;
    for(std::list<Card*>::iterator i=lc.begin(); i!= lc.end() ; ++i)  //run on all the cards by iterator
    {
        temp=i;
        temp++;
        if(temp!=lc.end() && isExist((*i),(*temp)))              //check how many from each value
            countShape++;
        
        else{
            if(countShape>=maxi){                                   //check if there is a more common card (or higher)
                maxi=countShape;
                cMax=(*i);
            }
                countShape=1;
            }
    }
    return cMax;
}

/*
 * This function returns a Card of the same value as PlayerType1 asks.
 * @return c - a pointer to the Card
 */
Card* PlayerType1:: ask()
{
    Card* c;
    c=theCommonCard();
    return c;
}

/*
 * PlayerType2's constructor
 */
PlayerType2::PlayerType2(string np2, int PType): Player(np2,PType){}

/*
 * PlayerType2's copy constructor
 */
PlayerType2::PlayerType2(const PlayerType2 &p2): Player(p2){}

/*
 * PlayerType2's (copy) constructor when the Player's type isn't known
 */
PlayerType2::PlayerType2(const Player &p2):Player(p2){}

/*
 * PlayerType2's destructor
 */
PlayerType2:: ~PlayerType2(){}

/*
 * This function returns the (lower) most uncommon card fo the Player.
 * @return cMin - a pointer to the Card
 */
Card* PlayerType2:: theUnCommonCard()
{
    list<Card*> lc=this->getList();
    int countShape=1, mini=4;
    Card* cMin;
    std::list<Card*>::iterator temp;                                   
    for(std::list<Card*>::iterator i=lc.begin(); i!= lc.end() ; ++i)  //run on all the cards by iterator 
    {                                                                  
        temp=i;
        temp++;
        if(temp!=lc.end() && isExist((*i),(*temp)))                    //check how many from each value
            countShape++;
        else
        {
            if(countShape<mini)                                         //check if there is a less common card (or lower)
            {
                mini=countShape;
                cMin=(*i);
            }
            countShape=1;
        }
    }
    return cMin;
}


/*
 * This function returns a Card of the same value as PlayerType2 asks.
 * @return c - a pointer to the Card
 */
Card* PlayerType2:: ask()
{
    Card* c;
    c=theUnCommonCard();
    return c;
}

/*
 * PlayerType3's constructor
 */
PlayerType3::PlayerType3(string np3, int PType): Player(np3,PType){}

/*
 * PlayerType3's copy constructor
 */
PlayerType3::PlayerType3(const PlayerType3 &p3): Player(p3){}

/*
 * PlayerType3's (copy) constructor when the Player's type isn't known
 */
PlayerType3::PlayerType3(const Player &p3):Player(p3){}

/*
 * PlayerType3's destructor
 */
PlayerType3:: ~PlayerType3(){}

/*
 * This function returns a Card of the highest value that the Player has.
 * @return - a pointer to the last Card
 */
Card* PlayerType3:: theMaxValueCard()
{
    return this->getList().back();
}

/*
 * This function returns a Card of the same value as PlayerType3 asks.
 * @return c - a pointer to the Card
 */
Card* PlayerType3:: ask()
{
    Card* c;
    c=theMaxValueCard();
    return c;
}

/*
 * PlayerType4's constructor
 */
PlayerType4::PlayerType4(string np4, int PType): Player(np4,PType){}

/*
 * PlayerType4's copy constructor
 */
PlayerType4::PlayerType4(const PlayerType4 &p4): Player(p4){}

/*
 * PlayerType4's (copy) constructor when the Player's type isn't known
 */
PlayerType4::PlayerType4(const Player &p4):Player(p4){}

/*
 * PlayerType4's destructor
 */
PlayerType4:: ~PlayerType4(){}

/*
 * This function returns a Card of the lowest value that the Player has.
 * @return - a pointer to the first Card
 */
Card* PlayerType4::  theMinValueCard()
{
    return this->getList().front();
}

/*
 * This function returns a Card of the same value as PlayerType4 asks.
 * @return c - a pointer to the Card
 */
Card* PlayerType4:: ask()
{
    Card* c;
    c=theMinValueCard();
    return c;
}



