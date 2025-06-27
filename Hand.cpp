#include <list>
#include <vector>
#include "Card.h"
#include "Hand.h"

// constructor
Hand::Hand(std::vector <int> initialCards) 
{
  for (auto card: initialCards)
      this->cards.push_back(card); // Card is added to the hand
}

// print out the hand from “top to bottom”
void Hand::printMe()
{
  for (auto item: this->cards)
    std::cout << item.name << " of " << item.suit << "(" << item.value << "),";
}


int Hand::size()
{
  int counter = 0;
  // Count the number of cards in the hand
  for (auto q = this->cards.begin(); q != this->cards.end(); q++)
    counter++; 
  std::cout << "This hand has " << counter << " cards." << std::endl;
  return counter;
}

// “deal” a card from the top: remove it and return a copy of it
Card Hand::dealACard()
{    
  Card aCard = this->cards.front();
  this->cards.pop_front(); // Front of the deck is dealt
  return aCard;
}

// add a new card to the top of a Hand
 void Hand::addACard(Card newCard)
{
  this->cards.push_front(newCard); 
}


// return an integer value that represents the sum of all card values in this Hand
int Hand::getPoints()
{
  int points = 0;
  for (auto item: this->cards)
    points += item.value; // Add the value of the card to the total number of points
  return points;
}


// Return true if the Hand currently contains any Ace card
bool Hand::hasAnAce()
{
  for (auto item: this->cards)
    {
      if (item.name == "Ace")
        return true;
    }
  return false;
}

