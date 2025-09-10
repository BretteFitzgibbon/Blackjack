What This Program Does:

— An object-oriented game of blackjack, with classes for Blackjack, Card, and Hand and a total of 13 methods.

— Incorporates composed classes, list containers and iterators, and vector containers.

________________________________________

How to Build and Run:

In Replit:

1) Create an account on replit.com if you don’t have one

2) Click on the REPL link above

3) Remix this app

4) Run

5) Click on >_Console tab

6) Play a game! Grab a friend to be the dealer, or play as both the player and the dealer — a win-win!

_______________________________________

In the Terminal:

Requires C++ 17

1) Go to the above GitHub link, click on Code, and copy the URL from the HTTPS tab

2) In the terminal: git clone <URL>

3) If you don’t have command line tools installed

xcode-select –install

4) Click Install when the pop-up comes up

5) Agree to the License Agreement

6) Wait about 15 minutes for installation to complete

7) In the terminal, navigate to the game’s directory:

cd Blackjack

8) Compile:

clang++ -std=c++17 *.cpp -o Blackjack

9) Run:

./Blackjack

10) Find a partner and play as many times as it takes for you to win. If you win the first game, stop playing.

_________________________________________

Sample Output:

Dealer’s hand: 0 points
Player’s hand: 0 points
Player’s Turn: Hit (h) or Stand (s)? h

Player hits…
Dealer’s hand: 0 points
Player’s hand: Seven of Hearts(7), 7 points

Player’s Turn again: Hit (h) or Stand (s)? h
Player hits…
Dealer’s hand: 0 points
Player’s hand: Five of Spades(5),Seven of Hearts(7), 12 points

Player’s Turn again: Hit (h) or Stand (s)? h
Player hits…
Dealer’s hand: 0 points
Player’s hand: Queen of Clubs(10),Five of Spades(5),Seven of Hearts(7), 22 points

Dealer wins with 0.
Dealer wins with 0.
Goodbye!

_________________________________________

Note:

— This was a homework assignment in which the professor wrote the test suite.
