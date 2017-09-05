#ifndef MYHAND1_H_
#define MYHAND1_H_

#include "Deck.h"

class Hand {

private:
	list<Card*> handCards;
        int counter;
public:


	Hand();
        Hand(const Hand &he);
        virtual ~Hand();
	int getNumberOfCards(); // Get the number of cards in the hand
        int getNumberOfCardsC() const;
	list<Card*> getList() const;
	void insertCard(Card* c);// insert new card to the hand the hand stay sort after the insert
	bool addCard(Card &card); //return true if the card is pushed
	bool removeCard(Card &card);//delete specific card aand return true if it was a deletion
	Card* deleteCard (Card* c);
	bool searchSpecificCard(Card &card); //search specific card
        bool searchFour(Card* c);

	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
};







#endif /* MYHAND_H1_ */
