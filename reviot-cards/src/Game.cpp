#include "Game.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

#include <fstream> 

using namespace std;



/**
 * Games's constructor.
 * The constructor creates the vairable configFile from a given text file.
 */


Game::Game(char* configurationFile): players(0), deck(Deck()),garbage(Deck()),configFile(""){

    std::ifstream file(configurationFile);
    string line;
    if ( file )
    {
        while( getline(file,line))
        {
            if(line[0]!='#' && line!="")
            configFile=configFile+" "+line;
        }
        file.close();
    }
}


/**
 * Games's copy constructor.
 */
Game::Game(const Game &g): players(0),  deck(g.deck), garbage(g.garbage), configFile(g.configFile),numOfPlayers(g.numOfPlayers) {
    Deck *d1= new Deck(g.deck);
    while(!(d1->getList().empty()))
    deck.insertCard(d1->fetchCard());                               //copies the Deck
    int i;
    for(i=0;i<g.numOfPlayers; ++i)                                  //copies all Players
    {
        if(g.players[i]->getPlayerType()==1)
        {
            PlayerType1* p1= new PlayerType1(*g.players[i]);
            players.push_back(p1);
        }
        else if(g.players[i]->getPlayerType()==2){
            PlayerType2* p2= new PlayerType2(*g.players[i]);
            players.push_back(p2);
        }
        else if(g.players[i]->getPlayerType()==3){
            PlayerType3* p3= new PlayerType3(*g.players[i]);
            players.push_back(p3);
        }
        else{
            PlayerType4* p4= new PlayerType4(*g.players[i]);
            players.push_back(p4);
        }
    }
    delete d1;
}



/**
 * Game's destructor.
 */
Game::~Game(){
    for(int i=0;i<numOfPlayers; ++i)        //deletes all Players
        delete players[i];
}

/**
 * This function initializes the Game: finds N and the verbal. Initializes the Deck and the Players according the text file.
 */

void Game::init() {
	
    //Skip all blanks
    int notBlank=0;
    while(configFile.at(notBlank)==' ')                 
        notBlank++;
    
    //Find verbal
    verbal = charToInt(configFile.at(notBlank))==1;
    notBlank++;
    while(configFile.at(notBlank)==' ')                 
        notBlank++;
    
    //Find N
    int N =0;//charToInt(configFile.at(notBlank));
    while(charToInt(configFile.at(notBlank))!=-1 && configFile.at(notBlank)!=' ')
    {
        N=N*10+charToInt(configFile.at(notBlank));
        notBlank++;
    }
    while(configFile.at(notBlank)==' ')                 
        notBlank++;
    
    //Initialize Deck
    string nameP;
    int countCards=0;
    while(countCards<(N+3)*4) {
        if (configFile.at(notBlank)==' ')
            notBlank++;
        else if (charToInt(configFile.at(notBlank)) == -1) {
            deck.insertCard((new FigureCard(charToShape(configFile.at(notBlank+1)),charToFigure(configFile.at(notBlank)))));
                        countCards++;
			notBlank += 2;
        } 
        
        else {
			int num = 0;
			int i=notBlank;
			while (charToInt(configFile.at(i)) != -1) {
				num = num * 10 + charToInt(configFile.at(i));
				i++;
			}
			deck.insertCard((new NumericCard(charToShape(configFile.at(i)), num)));
                        countCards++;
			notBlank = i + 1;
            }
    }
    
    //Initialize Players
    int len=configFile.length();
    while(notBlank<len){
        if(configFile.at(notBlank)==' ')
            notBlank++;
        else{
            string namePlayer="";
            while (configFile.at(notBlank) != ' ') {
				namePlayer += configFile.at(notBlank);
				notBlank++;
			}
            while(configFile.at(notBlank) == ' ')
                notBlank++;
            switch (configFile.at(notBlank)) {
			case '1':
				addPlayer(new PlayerType1(namePlayer, 1));
				break;
			case '2':
				addPlayer(new PlayerType2(namePlayer, 2));
				break;
			case '3':
				addPlayer(new PlayerType3(namePlayer, 3));
				break;
			case '4':
				addPlayer(new PlayerType4(namePlayer, 4));
				break;
			}
            notBlank++;
        }
        
    }
    disCards();

}

/**
 * This function distributes 7 Cards for each Player from the Deck.
 */
void Game::disCards() {
	int i, j;
	for (i = 0; i < numOfPlayers; ++i){
		for (j = 0; j < 7; ++j){
                    Card* c=deck.fetchCard();
                    players[i]->insertCard(c);
                    if(players[i]->searchFour(c))
                        throwFour(i,c);
            }
        }
}

/**
 * This function prints the state of the Game (Deck and Players).
 */
void Game::printState() {
	std::cout << deck.toString() << endl;
	for (int i = 0; i < numOfPlayers; i++)
		std::cout << players[i]->toString()<<endl;
}


/**
 * This function manages the game by playing turns until there's a winner.
 */

void Game::play() {
	while(!winner){
            if(verbal){
                std::cout << "Turn " << numTurns + 1 << endl;
		printState();
            }
            
		turn(numTurns);
                numTurns++;
	}
}
/**
 * This function plays a turn in the Game.
 * choose the appropriate strategy of the player in the turn.update the hands of 2 players- the player that "demand" card(players[numTurn]) and player that give a card("from") update.   checking winners .      .
 * @param numAllTurns - the number of the turns that were played

 */

void Game::turn(int numAllTurns) {
	int numTurn=numAllTurns%numOfPlayers;  //Holds the player who should play now.
	Card* c = players[numTurn]->ask();     
	int from;

        switch (players[numTurn]->getPlayerType()) {       //Checks the Player's type and accordingly, deduces who to ask a Card from.
            case 1:
                    from = maxCardsHigh(numTurn);  
                    break;
            case 2:
                    from = maxCardsHigh(numTurn);
                    break;
            case 3:
                    from =  ((numAllTurns/numOfPlayers+1)%(numOfPlayers-1)-1+(numOfPlayers-1))%(numOfPlayers-1); 
                    if(from>=numTurn) 
                        from=(from+1)%numOfPlayers;
                    break;
            case 4:
                    from =  ((numAllTurns/numOfPlayers+1)%(numOfPlayers-1)-1+(numOfPlayers-1))%(numOfPlayers-1);
                    if(from>=numTurn) 
                        from=(from+1)%numOfPlayers;
                    break;
	}
	if(verbal) std::cout << players[numTurn]->getName() << " asked "               //Prints the turn's info.
			<< players[from]->getName() << " for the value " << stringValue(c->toString()) << endl<< endl;

        int moveCards = 0;
        for (Card* move = players[from]->deleteCard(c); move != nullptr; move= players[from]->deleteCard(c)) {    //transfers cards between the "from" player to the "ask" player

		players[numTurn]->insertCard(move);
            if(players[numTurn]->searchFour(move))                                 //checks for a "reviiya"
                throwFour(numTurn,move);
            moveCards++;
	}
	
	if (moveCards == 0){                             //then the asking player takes a card from the deck
            Card* c=deck.fetchCard();
            players[numTurn]->insertCard(c);
            if(players[numTurn]->searchFour(c))             //checks for a "reviiya"
                throwFour(numTurn,c);   
        }
	else if(players[from]->getNumberOfCards() != 0)     //the asked player takes cards from the deck same amount as were taken from him if he didn't win
		for (int i = 0; i < moveCards; i++) {
                        Card* c=deck.fetchCard();
			players[from]->insertCard(c);
                        if(players[from]->searchFour(c))         //checks for a "reviiya"
                        throwFour(from,c);
                }
        


	if (players[numTurn]->getNumberOfCards() == 0)      //checking and updating winners
        {
            winner1=numTurn;
            winner=1;
        }
        if (players[from]->getNumberOfCards() == 0)
        {
            winner2=from;
            winner=1;
        }
        
        
    

}
/**
 * This function prints a message concerning the winners of the Game.
 */
void Game::printWinner()
{
    if(winner1!=-1 || winner2!=-1){
        if(winner2==-1)
            std::cout<< "***** The Winner is: "<<players[winner1]->getName() << " *****"<< endl;
        else if (winner1==-1)
            std::cout<< "***** The Winner is: "<<players[winner2]->getName() << " *****"<< endl;
        else{
            if(winner1>winner2){
                int temp=winner1;
                winner1=winner2;
                winner2=temp;
            }
            std::cout<< "***** The Winners are: "<<players[winner1]->getName() <<" and "<< players[winner2]->getName() << " *****"<< endl; 
        }
    }
}

/**
 * This function prints the number of the turns which were played.
 */
void Game::printNumberOfTurns()
{
        std::cout<< "Number of turns: "<< numTurns<< endl;
}

/**
 * This function finds the player who has the most Cards except a given Player.
 * @param  numPlayer - the position number of the given Player
 * @return maxHigh - the position number of the required Player. 
 */
int Game::maxCardsHigh(int numPlayer) {
	int maxCards = 0, maxHigh = -1;
	for (int i = 0; i < numOfPlayers; i++)
            if (maxCards <= players[i]->getNumberOfCards() && i != numPlayer) {      
			maxCards = players[i]->getNumberOfCards();
			maxHigh = i;
		}
        
	return maxHigh;
}

/**
 * This function adds a player to the Game.
 * @param  p - a pointer to the new Player. 
 */
void Game::addPlayer(Player* p) {
	players.push_back(p);
	numOfPlayers++;
}

/**
 * This function returns the number of Players in the Game.
 * @return numOfPlayers- the required number. 
 */
int Game::getNumOfPlayers() {
	return numOfPlayers;
}
/**
 * This function is same as getNumOfPlayers but const (for the copy constructor).
 * @return numOfPlayers- number of Players in the game. 
 */
int Game::getNumOfPlayersC() const {
	return numOfPlayers;
}
/**
 * This function returns the configFile of the Game.
 * @return configFile - the configFile
 */
string Game::getConfigFile() const{
    return configFile;
}
/**
 * This function returns the Deck of the Game     .
 * @return deck - the Deck of the Game
 */
Deck Game::getDeck() const{
    return deck;
}

/**
 * This function throw four card from a Player's Hand to the "garbage deck".     .
 * @param numPlayer- position number of the Player , c - a Card of the value to throw four.   
 */
void Game::throwFour(int numPlayer, Card* c){

        for(int i=0; i<4; i++)
            garbage.insertCard(players[numPlayer]->deleteCard(c));
}










