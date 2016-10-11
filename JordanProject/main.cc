//Jordan Irby
//Main file for Othello game project - AI Portion

#include <queue>
#include <iostream>
#include <string>
#include "othello.h"
#include "piece.h"
#include "game.h"
#include "colors.h"

using namespace std;

void play();

int main()
{
  Othello o;

 game::who winner;
  if (winner == 0) cout << "You win!";
  if (winner == 2) cout << "You lose!";
  cout << endl << RESET;
  o.play();
}
