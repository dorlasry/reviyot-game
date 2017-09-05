

#ifndef MYDECK_H_
#define MYDECK_H_



#include <list>
#include "Card.h"


using namespace std;

/**
 * This class represents the a deck of cards during the game.
 */
class Deck
{
	private:
		list<Card*> deckCards;
		int counter;

	public:
		Deck();
		Deck(const Deck &de);
                ~Deck();
                const Card*  getH() const;
		list<Card*> getList() const;

		Card* fetchCard();
		int getNumberOfCards() ;
                int getNumberOfCardsC() const;
		void insertCard(Card* c);
		string toString();
};







#endif /* MYDECK_H_ */
