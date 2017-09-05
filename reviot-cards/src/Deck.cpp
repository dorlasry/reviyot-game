#include "Deck.h"

using namespace std;


/**
 * Deck's constructor.
 */
Deck::Deck(): deckCards(0),counter(0){}
/**
 * Deck's copy constructor.
 */
Deck:: Deck(const Deck &de): deckCards(0),counter(0)
{
    char f;
    string num;
    char sh;
    for(std::list<Card*>::const_iterator i=de.deckCards.begin(); i!=de.deckCards.end() ;++i ) //run on the list of cards and copies them
    {
        if(isFigure(*i)){                                                           //for FigureCard
            f=(*i)->toString().at(0);
            sh=(*i)->toString().at(1);
            FigureCard* fee=new FigureCard(charToShape(sh),charToFigure(f));
            deckCards.push_back(fee);
        }
        else{                                                                       ////for NumericCard
            int j=0;
            int n=charToInt((*i)->toString().at(j));
            j++;
            while (charToInt((*i)->toString().at(j)) != -1) {
                n = n * 10 + charToInt((*i)->toString().at(j));
                j++;
            }
            sh=(*i)->toString().at(((*i)->toString().length())-1);
            NumericCard* nee=new NumericCard(charToShape(sh), n);
            deckCards.push_back(nee);
        }
    
    }
    
    counter=(de.getNumberOfCardsC());
}

/**
 * Deck's distructor.
 */
Deck::~Deck(){
        for(std::list<Card*>::iterator i=deckCards.begin(); i!=deckCards.end() ;++i){
            delete (*i);
        }
}
/**
 * This function return the list of cards in deck.
 * @return deckCards- list of Cards.
 */
list<Card*> Deck::getList() const
{
	return deckCards;
}



/**
 * This function pulls a card from the top of the deck and returns it.
 * @return c - a pointer to the pulled card.
 */
Card* Deck :: fetchCard ()
{
	Card* c=0;
	if(counter!=0)
	{
		c=deckCards.front();
		deckCards.pop_front();
		counter--;

	}
	return c;
}


/**
 * This function inserts a card to the deck.
 * @param c - a pointer to the card to be inserted.
 */
void Deck:: insertCard(Card* c)
{
	deckCards.push_back(c);
	counter++;
}

/**
 * This function returns the number of cards in the deck.
 * @return counter - the above-mentioned number.
 */
int Deck:: getNumberOfCards() 
{
	return counter;
}

/**
 * Same as getNumberOfCards but const (in order to use in copy constructor.
 */ 
int Deck:: getNumberOfCardsC() const
{
	return counter;
}

/**
 * This function returns a string representation of the deck's card (top-to-bottom order) such as: "12S QD AS 3H".
 */
string Deck:: toString()
{
	string c="Deck: ";
	for(std::list<Card*>::iterator i=deckCards.begin(); i!= deckCards.end(); ++i)
		c+= (*i)->toString()+" ";

	return c;;
}








