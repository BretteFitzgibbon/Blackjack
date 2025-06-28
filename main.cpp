#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

#include "Hand.h"
#include "Card.h"
#include "BlackJack.h"
#include "testMe.h"

int main() 
{
  testMe();   

  // Hand with one card indicated via ID == 0 (ace of spades)
  Hand oneCardHand({0});   
  oneCardHand.printMe();     // print the hand

  std::cout << std::endl << std::endl;

  // Hand with two cards indicated via ID == 0, and ID == 7 (two of clubs)
  Hand twoCardHand({0, 7});  
  twoCardHand.printMe();      // print the hand

  std::cout << std::endl << std::endl;


  srand(time(NULL)); //set the random number seed based on current time  , for the shuffle
  std::vector<int> cardIDs; // fill this up with card ids zero to 51
  for(int i = 0; i < 52; i++)  
    cardIDs.push_back(i); // push integers which represent card IDS 
  std::random_device rd; // random number generator
  std::mt19937 g(rd()); // random seed
  std::shuffle(cardIDs.begin(), cardIDs.end(), g); // user iterators to shuffle the vector of cardIDs

  Hand myDeck(cardIDs); // give the Hand constructor a vector of INTEGERS 
  myDeck.printMe(); // print the Hand we constructed


  BlackJack game({"Player A", "Dealer"}, cardIDs);   
  game.play(); // play the game 

  return 0; 
}
