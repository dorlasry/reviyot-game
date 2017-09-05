#include "Hand.h"

using namespace std;



/**
 * Hand's constructor.
 */


Hand::Hand() : handCards(0),counter(0) {
}

/**
 * Hand's copy constructor.
 */

Hand:: Hand(const Hand &he):handCards(0),counter(0)
{
    char f,sh;
    for(std::list<Card*>::const_iterator i=he.handCards.begin(); i!= he.handCards.end(); ++i)  //runs on the list of Cards
    {
        if(isFigure(*i)){                                                                      //and inserts a copy according to the 
            f=(*i)->toString().at(0);                                                               //Card's specific features.
            sh=(*i)->toString().at(1);
            FigureCard* fee=new FigureCard(charToShape(sh),charToFigure(f));
            handCards.push_back(fee);
        }
        else{
            int j=0;
            int n=charToInt((*i)->toString().at(j));
            j++;
            while (charToInt((*i)->toString().at(j)) != -1) {
                n = n * 10 + charToInt((*i)->toString().at(j));
                j++;
            }
            sh=(*i)->toString().at(((*i)->toString().length())-1);
            NumericCard* nee=new NumericCard(charToShape(sh), n);
            handCards.push_back(nee);
	}
    }	
    counter=(he.getNumberOfCardsC());
}

/**
 * Game's destructor.
 */
Hand::~Hand(){
        for(std::list<Card*>::iterator i=handCards.begin(); i!=handCards.end() ;++i){
            delete (*i);
        }
}


/**
 * This function checks for four same card by value (a "reviiya") according the input Card's value.
 * @param c- pointer to the input Card
 * @return true- iff there are 4 cards like c 
 */
bool Hand::searchFour(Card* c) {
	int count = 0;
	if(c==nullptr)
            return false;
        std::list<Card*>::iterator temp = handCards.begin();

	for (std::list<Card*>::iterator i = handCards.begin(); count < 4 && i  //runs on all the Cards
			!= handCards.end(); ++i) {
		if (isExist((*i), c))                                         // and checks how many are of the same value as c
			count++;

		if (count == 1)
			temp = i;

	}
	if (count == 4)
            return true;
        else
            return false;
}
/**
 * This function deletes a Card which has the same value as the input Card from the hand, and returns it.
 * @param c- a pointer to the Card
 * @return pointer to the deleted Card
 */
Card* Hand::deleteCard(Card* c) {
	bool b = false;
	Card* d = 0;
        if(getNumberOfCards()==0)
            b=true;
	for (std::list<Card*>::iterator i = handCards.begin(); b == false;){
		if (isExist((*i), c)) {
			d = (*i);
			handCards.remove(*i);
			b = true;
			counter--;
		}
                if(!b){
                    i++;
                    if(i == handCards.end())
                        b=true;
                }
            
        }
	return d;
}

/**
 * This function confirms that the input Card was deleted.
 * @param c- reference to the Card 
 * @return true- iff the card is no longer on the list.
 */
bool Hand::removeCard(Card &card) {

	bool b = false;
	for (std::list<Card*>::iterator i = handCards.begin(); b == false;){ //runs on all Hand Cards
		if (isSameRef((**i), card)) { // checks if the cards are equal
			b = true;
			handCards.remove(*i);
			counter--;
		}
		if(!b){
                    i++;
                    if(i == handCards.end())
                        b=true;
                }
        }
	return b;
}
/**
 * This function searches for a card in the Hand.
 * @param c- reference to the Card to search
 * @return true- iff the card(value and shape) exists in the Hand.
 */

bool Hand::searchSpecificCard(Card &card) {
	bool b = false;
	for (std::list<Card*>::iterator i = handCards.begin(); i != handCards.end()   //runs on all Hand Cards
			&& b == false; ++i)
		if (isSameRef((**i), card)) // checks if the cards are equal
			b = true;

	return b;

}
/**
 * This function confirms that a Card was added to the hand.
 * @param c- reference to the Card 
 * @return true- iff the card was added.
 */

bool Hand::addCard(Card &card)
{

	return searchSpecificCard(card);

}

/**
 * This function inserts card to the Hand. The function keeps the hand sorted.    
 * @param c- pointer to the Card to insert
 */


void Hand::insertCard(Card* c) {
	if (c != 0) {
		bool b = false;

		for (std::list<Card*>::iterator i = handCards.begin(); i
				!= handCards.end() && b == false; ++i) {
			if (sameType(c, (*i))) {                         //the card and i are same type (Figure or Numeric)
				if (isBig(((*i)), c)) {                  //inserts the Card in the appropriate place
					handCards.insert(i, c);
					b = true;

				}

			}

			else if (isFigure((*i))) {                   //the card is Numeric and i is Figure
				handCards.insert(i, c);              //the Numeric is smaller than the Figure
				b = true;

			}

		}

		if (b == false) {//the card c is bigger than all of the Hand's Cards- push it in the end of the Hand
			handCards.push_back(c);

		}

		counter++;
	}
}
/**
 * This function returns the number of cards in the Hand.
 * @return counter- number of Cards in the Hand
 */
int Hand::getNumberOfCards() {
	return counter;
}

/**
 * This function is same as getNumberOfCards but const(for the copy constructor).
 * @return counter-number of Cards in the Hand
 */

int Hand::getNumberOfCardsC() const {
	return counter;
}

/**
 * This function is const (for the copy constructor) returns the list of Card in the Hand   .
 * @return handCards-the list of the Cards in the Hand
 */
list<Card*> Hand::getList() const{
	return handCards;
}
/**
 * This function returns a string representation of the Hand.
 * @return c - the string representation.
 */
string Hand::toString() {
	string c;
	for (std::list<Card*>::iterator i = handCards.begin(); i != handCards.end(); ++i)
		c += (*i)->toString() + " ";

	return c;
}

