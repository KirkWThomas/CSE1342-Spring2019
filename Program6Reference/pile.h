#ifndef PILE_H
#define PILE_H

#include "card.h"

#define MAXCARDS 52

class Pile{

public:

	Pile();
	
	void AddCardToPile(Card * card);
	
	Card * RemoveTopCard();
	
	int GetNumCards();

	void Shuffle();
	
	void PrintCards();

private:
	
	Card * cards[MAXCARDS]; // an array of card pointers
	int numCards;
		
};

#endif