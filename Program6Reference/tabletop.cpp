#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "tabletop.h"

using namespace std;

TableTop::TableTop(){
	
	srand(time(NULL));

	cout << "Welcome to the Game of War!" << endl << endl;

	for(int i = 0; i < MAXCARDS; i++){
		Card * card = new Card; // dynamically allocate card
		deck[i] = card; // store the deck to deallocate later
		int suit = i / 13;
		int rank = i % 13;
		card->SetSuitAndRank(suit,rank);
		currentlyInPlay.AddCardToPile(card);
	}

	cout << "Shuffling initial deck..." << endl << endl;
	currentlyInPlay.Shuffle();
	
	// Divvy up the initial pile to the players
	for(int i = 0; i < MAXCARDS; i++){
		// Pull a card off the top of the pile
		Card * card = currentlyInPlay.RemoveTopCard();
		
		if(i % 2 == 0){
			playerA.GetToPlayPile()->AddCardToPile(card);
		}
		else{
			playerB.GetToPlayPile()->AddCardToPile(card);
		}
	}
	
	cout << "Initial 'to play' piles:" << endl << endl;
	cout << "Player A:" << endl;
	playerA.GetToPlayPile()->PrintCards();
	cout << endl;
	cout << "Player B:" << endl;
	playerB.GetToPlayPile()->PrintCards();
	cout << endl;
}

TableTop::~TableTop(){
	for(int i = 0; i < MAXCARDS; i++){
		delete deck[i]; // deallocate memory
	}
}

bool TableTop::DoBattle(){
	// get a card from each playerA
	Card * cardA = playerA.GetToPlayPile()->RemoveTopCard();
	Card * cardB = playerB.GetToPlayPile()->RemoveTopCard();
	currentlyInPlay.AddCardToPile(cardA);
	currentlyInPlay.AddCardToPile(cardB);
	cout << "Player A plays " << cardA->GetRankString() << " of " << cardA->GetSuitString() << "s" << endl;
	cout << "Player B plays " << cardB->GetRankString() << " of " << cardB->GetSuitString() << "s" << endl;
	
	bool tie = false;
	
	if(cardA->GetRank() > cardB->GetRank()){
		cout << "Player A wins the 'currently in play' pile." << endl << endl;
		while(currentlyInPlay.GetNumCards() > 0){
			Card * wonCard = currentlyInPlay.RemoveTopCard();
			playerA.GetPlayedPile()->AddCardToPile(wonCard);
		}
	} else if (cardA->GetRank() < cardB->GetRank()){
		cout << "Player B wins the 'currently in play' pile." << endl << endl;
		while(currentlyInPlay.GetNumCards() > 0){
			Card * wonCard = currentlyInPlay.RemoveTopCard();
			playerB.GetPlayedPile()->AddCardToPile(wonCard);
		}
	} else {
		cout << "There is a tie... Doing another battle." << endl << endl;
		tie = true;
	}
	
	// Replace cards if the 'to play' deck is empty
	
	if(playerA.GetToPlayPile()->GetNumCards() == 0 && playerA.GetPlayedPile()->GetNumCards() > 0){
		cout << "Player A ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;
		while(playerA.GetPlayedPile()->GetNumCards() > 0){
			Card * replacementCard = playerA.GetPlayedPile()->RemoveTopCard();
			playerA.GetToPlayPile()->AddCardToPile(replacementCard);
		}
		
		cout << "Shuffling player A cards..." << endl << endl;
		playerA.GetToPlayPile()->Shuffle();
	}
	
	if(playerB.GetToPlayPile()->GetNumCards() == 0 && playerB.GetPlayedPile()->GetNumCards() > 0){
		cout << "Player B ran out of cards in their 'to play' pile.  Getting cards from the 'played' pile." << endl;
		while(playerB.GetPlayedPile()->GetNumCards() > 0){
			Card * replacementCard = playerB.GetPlayedPile()->RemoveTopCard();
			playerB.GetToPlayPile()->AddCardToPile(replacementCard);
		}

		cout << "Shuffling player B cards..." << endl << endl;
		playerB.GetToPlayPile()->Shuffle();
	}
	
	// Print the current piles.
	
	cout << "Player A has " << playerA.GetToPlayPile()->GetNumCards() << " in their 'to play' pile and " << playerA.GetPlayedPile()->GetNumCards() << " in their 'played' pile." << endl;
	cout << "Player B has " << playerB.GetToPlayPile()->GetNumCards() << " in their 'to play' pile and " << playerB.GetPlayedPile()->GetNumCards() << " in their 'played' pile." << endl;
	cout << endl;

	// Check if anyone has lost.
	
	bool someoneRanOutOfCards = false;
	if(playerA.GetToPlayPile()->GetNumCards() == 0){
		someoneRanOutOfCards = true;
		cout << "Player A ran out of cards.  Player A has lost." << endl;
	}
	if(playerB.GetToPlayPile()->GetNumCards() == 0){
		someoneRanOutOfCards = true;
		cout << "Player B ran out of cards.  Player B has lost." << endl;
	}
	
	// Report to main
	
	if(!someoneRanOutOfCards && tie){
		return DoBattle(); // recursively call DoBattle
	}
	else{
		return someoneRanOutOfCards;
	}
}
