//OTHELLO CLASS - Jordan Irby

#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include "game.h"
#include "piece.h"
#include "colors.h"


using namespace main_savitch_14;


class Othello: public game
{
	public:
		//Constructor & Destructor
		~Othello() {};
		Othello() {};

		//Virtual functions that may not be overriden
		std::string get_user_move()const;

		//Virtual functions that must be overridden
		void make_move(const std::string& move);//
		void restart();

		//Purely virtual functions
		game* clone()const;
		void compute_moves(std::queue<std::string>& moves)const;
		void display_status()const;
		int evaluate()const;
		bool is_game_over()const {} ;
		bool is_legal(const std::string& move)const;

		//Functions to help with the othello pieces
		bool are_moves_available()const;

		//Functions to deal with a flip issue
		void process_flip(int r, int c);
		void flip_angle(int r, int c, int angle);
		void update_flip(const int r, const int c);

		// Calls all of the following flanked functions.
  		bool is_it_flanked(int r, int c) const;
  		// Check if direction is flanked functions.
  		bool is_n_flanked(int r, int c) const;
  		bool is_ne_flanked(int r, int c) const;
 		bool is_e_flanked(int r, int c) const;
  		bool is_se_flanked(int r, int c) const;
 		bool is_s_flanked(int r, int c) const;
 		bool is_sw_flanked(int r, int c) const;
  		bool is_w_flanked(int r, int c) const;
  		bool is_nw_flanked(int r, int c) const;

		//Checks for winning player
		bool winning();
	private:
		//Arrays to handle to the pieces of the board
		Piece board[8][8];

		//Counts the white and black pieces on the board
		int black;
		int white;
};

string coord_to_string(const int r, const int c);

#endif
