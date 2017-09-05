
#include "Card.h"

using namespace std;

/**
 * This function converts a char to the appropriate card shape.
 * @param sh - the char to convert
 * @return c- the appropriate shape
 */
Shape charToShape(char sh)
{
	Shape c;
	switch(sh)
	{
    	case 'C': c=Club;break;
    	case 'D': c=Diamond;break;
    	case 'H': c=Heart;break;
    	case 'S': c=Spade;break;
    }
	return c;
}

/**
 * This function converts a char to the appropriate royalty card figure.
 * @param sh - the char to convert
 * @return c- the appropriate figure
 */
Figure charToFigure(char sh)
{
	Figure c;
	switch(sh)
	{
    	case 'J': c=Jack;break;
    	case 'Q': c=Queen;break;
    	case 'K': c=King;break;
    	case 'A': c=Ace;break;
    }
	return c;
}

/**
 * This function returns the card's shape.
 * @return shape - the card's shape.
 */
Shape Card:: getShape() const
{
    return shape;
}

/**
 * Card's constructor.
 */
Card::Card(Shape sh): shape(sh){}

//Card::Card(): shape(Club) {}

/**
 * Card's copy constructor.
 */
Card:: Card(const Card &c): shape(c.getShape()){}

/**
 * Card's destructor.
 */
Card::~Card(){}


/**
 * FigureCard's constructor.
 */
FigureCard::FigureCard(Shape sh, Figure f): Card(sh), figure(f),Fvalue(0)
{
	switch(f)
	{
            case Jack: Fvalue=-4;break;
	    case Queen: Fvalue=-3;break;
	    case King: Fvalue=-2;break;
	    case Ace: Fvalue=-1;break;
	}
}

/**
 * FigureCard's copy constructor.
 */
FigureCard:: FigureCard(const FigureCard &f): Card(f.getShape()),figure(f.getFigure()), Fvalue(f.getValue()){}

/**
 * FigureCard's destructor.
 */
FigureCard::~FigureCard(){}
/**
 * This function returns the card's figure.
 * @return figure - the card's figure.
 */
Figure FigureCard:: getFigure() const
{
    return figure;
}

/**
 * This function returns the card's value.
 * @return Fvalue - the card's value.
 */
int FigureCard:: getValue() const
{
    return Fvalue;
}

/**
 * This function returns a string representation of the FigureCard.
 * @return c - the string representation.
 */
string FigureCard:: toString()
{
	std::string c;

	switch(getFigure()){
            case Jack: c+="J";break;
	    case Queen: c+="Q";break;
	    case King: c+="K";break;
	    case Ace: c+="A";break;
        }

	switch(getShape()){
            case Club: c+="C";break;
            case Diamond: c+="D";break;
            case Heart: c+="H";break;
            case Spade: c+="S";break;
        }

	return c;
}


/**
 * NumericCard's constructor.
 */
NumericCard::NumericCard(Shape sh, int n): Card(sh), number(n), Nvalue(n){}

/**
 * NumericCard's copy constructor.
 */
NumericCard::NumericCard(const NumericCard &n): Card(n.getShape()), number(n.getNumber()),Nvalue(n.getValue()){}

/**
 * NumericCard's destructor.
 */
NumericCard::~NumericCard(){}

/**
 * This function returns the value of the numeric card.
 * @return Nvalue-  the value
 */
int NumericCard:: getValue() const
{
    return Nvalue;
}

/**
 * This function returns the card's number.
 * @return number -  the card's number
 */
int NumericCard:: getNumber() const
{
    return number;
}

/**
 * This function returns a string representation of the NumericCard.
 * @return c - the string representation.
 */
string NumericCard:: toString()
{
	int n=getNumber();
	std::string c = to_string(n);
	switch(getShape()){
            case Club: c+="C";break;
            case Diamond: c+="D";break;
            case Heart: c+="H";break;
            case Spade: c+="S";break;
        }

	return c;
}

/**
 * This function converts a digit to the appropriate number.
 * @param c - the digit
 * @return i - the number
 */ 
int charToInt(char c)
{
	string s="0123456789";
	int i= s.find(c);
	return i;
}

/**
 * This function converts cuts the end of a string(in order recieve a Card's value with no Shape).
 * @param s - the string
 * @return s.substr(0,n-1) - the cut string
 */ 
string stringValue(string s)
{
    int n=s.length();
    return s.substr(0,n-1);
}


/**
 * This function compares two cards by their custom value.
 * @param c1, c2 - pointers to the two Cards
 * @return true iff c1>c2
 */
bool isBig(Card *c1, Card *c2)
{
	if(c1->getValue() > c2->getValue() )
			return true;
		if(c1->getValue()== c2->getValue() && c1->getShape() > c2->getShape())
			return true;
		else
			return false;
}

/**
 * This function checks if two Cards are of the same value.
 * @param c1, c2 - pointers to the two Cards
 * @return true iff c1 is same type fo c2
 */
bool isExist(Card* c1, Card* c2)
{
	if(c1->getValue() == c2->getValue()  )
			return true;
	else
			return false;
}


/**
 * This function checks if two Cards are the same (type and value).
 * @param c1, c2 - pointers to the two Cards
 * @return true iff c1 is same type fo c2
 */
bool isSameRef(Card &c1, Card &c2)
{
	if(c1.getValue() == c2.getValue() && c1.getShape() == c2.getShape())
		return true;
	else
			return false;
}

/**
 * This function checks if a Card is of Figure type .
 * @param c1 - pointer to the Card
 * @return true iff c is of Figure type
 */
bool isFigure(Card* c) {
	if(c->getValue()<0)
		return true;
	else
		return false;
}

/**
 * This function checks if two Cards are of the same type (Figure or Numeric).
 * @param c1, c2 - pointers to the two Cards
 * @return true iff the Cards are of the same type
 */
bool sameType(Card *c1, Card *c2){
	if((c1->getValue()<0 && c2->getValue()<0) || (c1->getValue()>0 && c2->getValue()>0))
		return true;
	else
		return false;
}



