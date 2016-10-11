//PIECE CLASS - Jordan Irby

#ifndef PIECE_H
#define PIECE_H


class Piece
{
	public:
		// constructor
  		Piece() {empty = true, black = false, white = false;}
  		// Modifiers
  		void flip();
  		void set_black() {empty = false, black = true, white = false;}
  		void set_white() {empty = false, black = false, white = true;}
  		// Accessor
 		bool is_empty()const {if(empty == true) return true;}
  		bool is_black()const {if(black == true) return true;}
 		bool is_white()const {if(white == true) return true;}
	private:
	 	//emptiness, black, and white
	 	bool empty;
	 	bool white;
	 	bool black;
};

#endif
