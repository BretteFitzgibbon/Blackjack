#include <vector>
#include <string>
#include "Card.h"

/*
Each card ID tells us the exact type of card we need to created. Valid IDs go from 0 to 51; -1 indicates an invalid card.
Note that the cards IDs are ordered by suit and groups in fours like: 
   0 == Ace of Spades 
   1 == Ace of Hearts
   2 == Ace of Diamonds
   3 == Ace of Clubs, 
   4 == Two of Spades
   5 == Two of Hearts
   6 == Two of Diamonds
   7 == Two of Clubs, 
    ...
  */
 
Card::Card(int ID)   
{ 
   // bad card indicator = we'll call this the JOKER
  if (ID == -1)
   { 
      value = -1; 
      name = "Joker";
      suit = "None";
      return;
   }

   std::vector <std::string> suits = {"Spades", "Hearts", "Diamonds", "Clubs"};
   suit = suits[ID % 4]; // assign the name of the suit based on the ID MODULO 4

   // Assign the point value and name based on the DIVISION of ID by 4
  switch(ID/4)
   {     
     case 0: // ACE
      value = 1;
      name = "Ace";
      break;
     
     case 1: // TWO
      value = 2;
      name = "Two";
      break;

     case 2: // THREE
      value = 3;
      name = "Three";
      break;

     case 3: // FOUR
      value = 4;
      name = "Four";
      break;

     case 4: // FIVE
      name = "Five";
      value = 5;
      break;

     case 5: // SIX
      value = 6;
      name = "Six";
      break;

     case 6: // SEVEN
      value = 7;
      name = "Seven";
      break;

     case 7: // EIGHT
      value = 8;
      name = "Eight";
      break;

     case 8: // NINE
      value = 9;
      name = "Nine";
      break;

     case 9: // TEN
      value = 10;
      name = "Ten";
      break;
     
     case 10: // JACK
      value = 10;
      name = "Jack";
      break;

    case 11: // QUEEN
     value = 10;
     name = "Queen";
     break;

    case 12: // KING
     value = 10;
     name = "King";
     break;

     // Joker (JUNK). We should not have one of these in our deck
     default: 
      value = -1; 
      name = "Joker";
      break;
   }
  } 

std::ostream& operator<< (std::ostream& os, Card const &n) 
{
    return os << n.name << " of " << n.suit << "(" << n.value << "), ";  
}