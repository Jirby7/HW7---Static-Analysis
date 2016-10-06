//OTHELLO CLASS

#ifndef OTHELLO_H
#define OTHELLO_H

#include <iostream>
#include <string>
#include <sstream>
#include "game.h"
#include "piece.h"
#include "colors.h"


using namespace main_savitch_14;


class Othello: public game
{
	public:
		//Constructor & Destructor
		Othello();

		//Virtual functions that may not be overriden
		virtual std::string get_user_move()const;

		//Virtual functions that must be overridden
		virtual void make_move(const std::string& move);//
		virtual void restart();

		//Purely virtual functions
		virtual game* clone()const {return NULL;}
		virtual void compute_moves(std::queue<std::string>& moves)const {};
		virtual void display_status()const;
		virtual int evaluate()const {};
		virtual bool is_game_over()const {} ;
		virtual bool is_legal(const std::string& move)const;

		//Functions that handle flips
  		void process_flip(int r, int c);
  		void flip_angle(int r, int c, int angle);
  		void flip_and_update(const int r, const int c);

  		// Calls the flanking functions
  		bool is_it_flanked(int r, int c) const;
  		// All options for flanking directions
  		bool is_nn_flanked(int r, int c) const;
  		bool is_ne_flanked(int r, int c) const;
  		bool is_ee_flanked(int r, int c) const;
  		bool is_se_flanked(int r, int c) const;
  		bool is_ss_flanked(int r, int c) const;
  		bool is_sw_flanked(int r, int c) const;
  		bool is_ww_flanked(int r, int c) const;
  		bool is_nw_flanked(int r, int c) const;

  		//Checks for open move spaces
  		bool are_moves_available() const;
	private:
		int black_c;
		int white_c;
		Piece board[8][8];
};

//Converts string into integers
void convert(int& r, int& c, string move);
//takes local and makes it a string
string coord_to_string(const int r, const int c);


#endif
