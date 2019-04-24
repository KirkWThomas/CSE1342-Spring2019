#include <iostream>
#include <stdlib.h>
#include "pile.h"

Pile::Pile(){
	numCards = 0;
}

void Pile::AddCardToPile(Card * card){
	// adds a card to the end of the array		
	cards[numCards] = card;
	numCards++;
}

Card * Pile::RemoveTopCard(){
	// removes a card from the end of the array
	Card * cardToReturn = cards[numCards - 1];
	numCards--;
	return cardToReturn;
}

int Pile::GetNumCards(){
	return numCards;
}

void Pile::Shuffle(){
	// do random swaps
	int n = MAXCARDS * 2;
	for(int i = 0; i < n; i++){
		int c1 = rand() % numCards;
		int c2 = rand() % numCards;
		Card * temp = cards[c1];
		cards[c1] = cards[c2];
		cards[c2] = temp;
	}
}

void Pile::PrintCards(){
	std::cout << "There are " << numCards << " cards in the pile." << std::endl;
	for(int i = 0; i < numCards; i++){
		std::cout << "Card " << (i + 1) << ", " << cards[i]->GetRankString() << " of " << cards[i]->GetSuitString() << "s" << std::endl;
	}
}