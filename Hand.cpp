#include <list>
#include <vector>

#include "Card.h"
#include "Hand.h"

Hand::Hand(std::vector <int> initialCards) // Constructor
{
  for (auto card: initialCards)
      this->cards.push_back(card); // Card is added to the hand
}


void Hand::printMe()
{
  for (auto item: this->cards)
    std::cout << item.name << " of " << item.suit << "(" << item.value << "),";
}// print out the hand from “top to bottom”


int Hand::size()
{
  int counter = 0;
  for (auto q = this->cards.begin(); q != this->cards.end(); q++)
    counter++; // Count the number of cards in the hand
  std::cout << "This hand has " << counter << " cards." << std::endl;
  return counter;
}


Card Hand::dealACard()
{    
  Card aCard = this->cards.front();
  this->cards.pop_front(); // Front of the deck is dealt
  return aCard;
}
// “deal” a card from the top: remove it and return a copy of it

 void Hand::addACard(Card newCard)
{
  this->cards.push_front(newCard); 
}
// add a new card to the top of a Hand


int Hand::getPoints()
{
  int points = 0;
  for (auto item: this->cards)
    points += item.value; // Add the value of the card to the total number of points
  return points;
}
// return an integer value that represents the sum of all card values in this Hand


bool Hand::hasAnAce()
{
  for (auto item: this->cards)
    {
      if (item.name == "Ace")
        return true;
    }
  return false;
}
// BONUS: return true if the Hand currently contains any Ace card
