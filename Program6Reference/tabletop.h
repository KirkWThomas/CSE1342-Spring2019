#ifndef TABLETOP_H
#define TABLETOP_H

#include "card.h"
#include "pile.h"
#include "player.h"

class TableTop{

public:
	
	TableTop();
	
	~TableTop();
	
	bool DoBattle();
	
private:
	Player playerA;
	Player playerB;
	Pile currentlyInPlay;
	Card * deck[MAXCARDS];	
};

#endif