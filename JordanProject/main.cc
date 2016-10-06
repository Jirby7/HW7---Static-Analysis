#include <queue>
#include <iostream>
#include <string>
#include "othello.h"
#include "piece.h"
#include "game.h"
#include "colors.h"

using namespace std;
using namespace main_savitch_14;

int main()
{
	int j = 0;
	string move;
	Othello o;

	o.restart();
	o.display_status();

	move = o.get_user_move();
	if (o.is_legal(move))
	{
		o.make_move(move);
		o.display_status();
		j++;
	}
	else
	cout << "Cannot make move, try again.";




}
