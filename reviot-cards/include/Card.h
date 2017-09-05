
#ifndef CARD_H_
#define CARD_H_


#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
using namespace std;



enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};





/**
 * This class is an abstract class for game cards of a standard (but extended- more number cards) deck.
 */
class Card
{
	private:
		Shape shape;

	public:
		virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
		virtual int getValue() const=0;
		virtual ~Card();    //destructor
		Shape getShape() const;

		Card(Shape sh);

		Card(const Card &c);
};


/**
 * This class represents a royalty card.
 */
class FigureCard : public Card
{
	private:
		Figure figure;
		int Fvalue;

	public:
		FigureCard(Shape sh, Figure f);
		FigureCard(const FigureCard &f);
                virtual ~FigureCard();
		virtual int getValue() const override;
		Figure getFigure() const;
		virtual string toString() override;
};


/**
 * This class represents a numeric card.
 */
class NumericCard : public Card
{
	private:
		int number;
		int Nvalue;
	public:
		NumericCard(Shape sh, int num );
		NumericCard(const NumericCard &f);
                virtual ~NumericCard();
		virtual int getValue() const override;
		int getNumber() const;
		virtual string toString() override;
};

int charToInt(char c);
string stringValue(string s);
Shape charToShape(char sh);
Figure charToFigure(char sh);

bool isFigure(Card* c) ;
bool isBig(Card* c1, Card* c2);
bool isSameRef(Card &c1, Card &c2);
bool isExist(Card* c1, Card* c2);
bool sameType(Card* c1, Card* c2);


#endif

