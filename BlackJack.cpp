#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "BlackJack.h"

//
// PLAY
//

// the method below has been written for you to help you understand how your methods will be used
  void BlackJack::play() 
{
    std::cout << "Let's Play BlackJack!" << std::endl;

    bool gameOver = false; // Bust means >21
    this->printInstructions(); // print instructions
    this->printBoard(); // print the board

    while(!gameOver) 
    { // keep playing as long as the game is not won by either player
      gameOver = this->takePlayerTurn(); // current player takes a turn
      if (gameOver)
        break;
      this->printBoard(); // print the board if that was a good move
      gameOver = this->takeDealerTurn(); // AI takes a turn
      if (gameOver)
        break;
    } // end while: game over

    // note below that the winning player is who we want, not the current player
    if (getWinningPlayerId() != -1)
      //std::cout << "Congratulations: " << playerNames[getWinningPlayerId()] << " has won the game!" << std::endl;
    //else 
      //std::cout << "Looks like the game was a tie" << std::endl;
    std::cout << "Goodbye!" << std::endl;

  } // end play()


BlackJack::BlackJack(std::vector <std::string> _playerNames, std::vector <int> cardID) : playerNames(_playerNames), deck(cardID){}

void BlackJack::printInstructions()
{
  std::cout << "How to Play BlackJack" << std::endl << std::endl;
  std::cout << "The object of the game is to have a hand of cards whose values add up to 21. Each card has a value matching its number, except for Ace(1) and Jack, Queen, and King (10). A player competes with a dealer. At each turn, the player and dealer can choose to receive another card (hit) or to stop collecting cards (stand). If the player or dealer's total exceeds 21, the game ends and that person loses. If the player has a total of 21, and then the dealer takes a turn and obtains a total of 21, the dealer wins. Otherwise, the player wins. If both the player and the dealer stand, then the person whose total is closest to 21 wins. If the player's and dealer's scores are equal, then the dealer wins." << std::endl << std::endl;
  std::cout << "Have fun!" << std::endl << std::endl;
}// print instructions for the game


void BlackJack::printBoard()
{
  std::cout << "Dealer's hand: ";
  this->dealerHand.printMe();
  std::cout << " ";
  std::cout << this->dealerHand.getPoints(); 
  std::cout << " points" << std::endl;
  std::cout << "Player's hand: ";
  this->playerHand.printMe();
  std::cout << " ";
  std:: cout << this->playerHand.getPoints(); 
  std::cout << " points" << std::endl;
}// print the state of the game: player hand (all cards up), and dealer hand (all cards up)


bool BlackJack::takePlayerTurn()
{
  this->winningPlayerId = -1; // No one has won yet
  char turnChoice; // Hit or stand
  std::cout << "Player's Turn: Hit (h) or Stand (s)? ";
  std::cin >> turnChoice;
  std::cout << std::endl;
  while (turnChoice == 'h')
  {
    std::cout << "Player hits..." << std::endl;
    this->playerHand.addACard(this->deck.dealACard());
    std::cout << "Dealer's hand: ";
    this->dealerHand.printMe();
    std::cout << " " << this->getDealerPoints() <<  " points" << std::endl;
    std::cout << "Player's hand: ";
    this->playerHand.printMe();
    std::cout << " " << this->getPlayerPoints() << " points" << std::endl << std::endl;
    if (this->getPlayerPoints() > 21) // End of game condition
    {
      this->getWinningPlayerId();
      return true;
    }
    std::cout << "Player's Turn again: Hit (h) or Stand (s)? ";
    std::cin >> turnChoice;
  }
  // if (this->getWinningPlayerId() == 0 || this->getWinningPlayerId() == 1)
  //     return true;   
  return false; 
}
  
// Player takes their turn, setting winningPlayerId to -1, 0, or 1, and returning true if the game is over


bool BlackJack::takeDealerTurn()
{
  this->winningPlayerId = -1; // No one has won yet
  char turnChoice; // Hit or stand
  std::cout << "Dealer's Turn: Hit (h) or Stand (s)? ";
  std::cin >> turnChoice;
  std::cout << std::endl;
  while (turnChoice == 'h')
  {
    std::cout << "Dealer hits..." << std::endl << std::endl;
    this->dealerHand.addACard(this->deck.dealACard());
    std::cout << "Dealer's hand: ";
    this->dealerHand.printMe();
    std::cout << " " << this->getDealerPoints() << " points" << std::endl;
    std::cout << "Player's hand: ";
    this->playerHand.printMe();
    std::cout << " " << this->getPlayerPoints() << " points" << std::endl << std::endl;
    if (this->getDealerPoints() >= 21) // End of game condition
    {
      //this->getWinningPlayerId();
      return true;
    }
    std::cout << "Dealer's Turn again: Hit (h) or Stand (s)? ";
  std::cin >> turnChoice;
  }
  if (this->getWinningPlayerId() == 0 || this->getWinningPlayerId() == 1)
      return true;  
 return false; 
}// Dealer takes a turn, setting winningPlayerId to -1, 0, or 1, and returning true if the game is over


int BlackJack::getWinningPlayerId()
{
  if (this->playerHand.getPoints() > 21) // Player goes over the limit
  {
    this->winningPlayerId = 1; // Dealer wins
    std::cout << "Dealer wins with " << this->getDealerPoints() << "." << std::endl;
    return this->winningPlayerId;
  }  
  else if (this->dealerHand.getPoints() == 0) // Player cannot win if dealer has not taken a turn yet
  {
    this->winningPlayerId = -1;
    return this->winningPlayerId;
  }
  else if (this->dealerHand.getPoints() > 21) // Dealer goes over the limit
  {
    this->winningPlayerId = 0; // Player wins
    std::cout << "Player wins with " << this->getPlayerPoints() << "." << std::endl;
    return this->winningPlayerId;
  }
  else if (this->dealerHand.getPoints() >= this->playerHand.getPoints()) // Dealer is closer to 21 than player is
  {
    this->winningPlayerId = 1; // Dealer wins
    std::cout << "Dealer wins with " << this->getDealerPoints() << "." << std::endl;
    return this->winningPlayerId;
  }
  else if (this->playerHand.getPoints() > this->dealerHand.getPoints())// Player is closer to 21 than dealer is
  {
    this->winningPlayerId = 0; // Player wins
    std::cout << "Player wins with " << this->getPlayerPoints() << "." << std::endl;
    return this->winningPlayerId;
  }  
  else
    return this->winningPlayerId; // Placeholder for non-void function
}// return the value of the private winningPlayerId, as set by isWin().


int BlackJack::getPlayerPoints()
{
  return this->playerHand.getPoints();
}// return the points for the player's hand by calling Hand::playerHand->getPoints()


int BlackJack::getDealerPoints()
{
  return this->dealerHand.getPoints();
}// return the points for the dealer's hand by calling Hand::dealerHand->getPoints()