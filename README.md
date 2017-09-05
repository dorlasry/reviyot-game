 C++ program that plays "Reviiyot"(רביעיות.(

• 2 or more players, each plays according to a given strategy. •(N+3)*4 cards (N>=1). An individual card consists of a VALUE and a SHAPE. The values are: 2,3,4,…,N, Jack, Queen, King and Ace. The shapes are Spade(S), Diamond(D), Club(C) and Heart(H). Each value has all 4 shapes. (It is as a standard card deck but with unlimited rank/value. For example a deck of N=12 consists of 2s,3s,...,12s, Jacks, Queens, Kings and Aces.

•The implementation include the following classes:

Card: a single playing card. This class is abstract and holds the shape of the card only.

FigureCard: Inherits from Card. Used for cards with a figure on. That is: Jack, Queen, King and Ace.

NumericCard: Inherits from Card. Used for cards with numeric values. (2, 3, 4, 5, etc…) A card value is the combination of its value and its shape, when “value” is the most significant value while “shape” is the least significant value. Ex: 23C and not C23

Hand: one player's Cards. This is a collection ( Vector) of Card objects representing the cards held by a single player. It include appropriate methods to add and remove cards, search for cards in the hand, getNumberOfCards and a toString function that returns a sorted hand.

Player: This class is abstract, derives from Hand, and holds one player's info. A player has a name. It should include appropriate methods to add and remove cards, search for cards in his/her hand, getNumberOfCards and a toString function that returns the name, and the sorted hand (as describes in Hand). PlayerType1, PlayerType2, PlayerType3, PlayerType4: Derives from Player: This class represents a player with a specific playing strategy (1, 2, 3, or 4).

Deck: This class represents the deck of cards. This is also a collection of Card objects with methods to deal cards, toString function that returns the number of cards in the deck and the cards from top to bottom.

Game: Holds the players and the deck. Handles the flow of the game, user input, output, error handling etc… In order to take a snapshot of the game at any given time, you must provide a copy constructor of this class. Game will also implement the printState() function. This function should be implemented with extra care, since it produces the expected output by which your work will be evaluated. This function prints the cards remaining in the deck from top to bottom in a single line, followed by the name and sorted hand of all players (a single line per player).
