//Othello implementaion - Jordan Irby
#include "othello.h"

//Used to reset board at start
void Othello::restart()
   {
      board[3][3].set_white();
      board[4][4].set_white();
      board[3][4].set_black();
      board[4][3].set_black();

      game::restart();
   }

//Displays the status of the board
void Othello::display_status()const
	{
	  int i = 0;
      int j = 0;
      cout << endl << endl;
      cout << BLUE << "\n  Othello Board \n";
      cout << "_____________________\n";
      cout << "  A B C D E F G H \n";
      for(i = 0; i < 8; ++i)
      {
         cout << WHITE << i + 1;
         for(j = 0; j < 8; ++j)
         {
            cout << B_RED << " ";
            if(board[i][j].is_black() == true)
            {
               cout << BLACK << "0";
            }
            else if(board[i][j].is_white() == true)
            {
               cout << WHITE << "0";
            }
            else
            {
               cout << " ";
            }
         }
         cout << RESET;
         cout << endl;
		}
}

// Part 3 of project.
// Computes all possible moves
void Othello::compute_moves(queue<string>& moves) const
{
  for (int r = 0; r < 8; ++r) {
    for (int c = 0; c < 8; ++c) {
      if (board[r][c].is_empty()) {
        if (is_it_flanked(r,c)) moves.push(coord_to_string(r,c));
      }
    }
  }
}

string coord_to_string(const int r, const int c)
{
  string rv;
  if (r == 0) rv = "1";
  else if (r == 1) rv = "2";
  else if (r == 2) rv = "3";
  else if (r == 3) rv = "4";
  else if (r == 4) rv = "5";
  else if (r == 5) rv = "6";
  else if (r == 6) rv = "7";
  else if (r == 7) rv = "8";
  if (c == 0) rv += "a";
  else if (c == 1) return (rv + "b");
  else if (c == 2) return (rv + "c");
  else if (c == 3) return (rv + "d");
  else if (c == 4) return (rv + "e");
  else if (c == 5) return (rv + "f");
  else if (c == 6) return (rv + "g");
  return (rv + "h");
}

// Part 3 of Project
// Evaluates board position and give a score. (+) is good (-) is bad
int Othello::evaluate() const
{
  int b_value = black;
  int w_value = white;
  int corner = 25;
  int x_sqr = 5;
  int stable = 10;

  for (int r = 0; r < 8; ++r) {
    for (int c = 0; c < 8; ++c) {
      //check if piece is empty
      if (!board[r][c].is_empty()) {


        if (moves_completed() < 20) {
          if (((r == c) && (r != 3 || r != 4)) ||
               (r == 1 && c == 6) || (r == 2 && c == 5) ||
               (r == 5 && c == 2) || (r == 6 && c == 1)) {
            if (board[r][c].is_black()) b_value += x_sqr;
            else w_value -= x_sqr;
          }
        }

        //check for corners
        if (((r == 0 || r == 7) && r == c) ||
             (r == 0 && c == 7) ||
             (r == 7 && c == 0))  {
          if (board[r][c].is_black()) b_value += corner;
          else w_value += corner;
        }

        //check for piece stability.
        if (is_it_flanked(r,c)) {
          if (board[r][c].is_black()) w_value += stable;
          else b_value -= stable;
        }

      }
    }
  }
  return (w_value - b_value);
}

//Part 3 of project.
//returns a copy of game
game* Othello::clone() const
{
  return new Othello(*this);
}

//Returns true if piece flanks a color in any directions else returns false
bool Othello::is_it_flanked(int r, int c)const
{
  if (is_e_flanked(r,c)) return true;
  if (is_ne_flanked(r,c)) return true;
  if (is_n_flanked(r,c)) return true;
  if (is_nw_flanked(r,c)) return true;
  if (is_w_flanked(r,c)) return true;
  if (is_sw_flanked(r,c)) return true;
  if (is_s_flanked(r,c)) return true;
  if (is_se_flanked(r,c)) return true;

  else
  return false;
}


// Goes through every spot on the board and looks for empty ones.
// Checks if moving to that spot is a legal move
bool Othello::are_moves_available() const
{
  for (int i = 0; i < 2; ++i) {
    for (int r = 0; r < 8; ++r) {
      for (int c = 0; c < 8; ++c) {
        if (board[r][c].is_empty()) if (is_it_flanked(r,c)) return true;
      }
    }
  }
  return false;
}

//Converts string to ints
void convert_string(int& r, int& c, string move)
{
  char ch;
  istringstream buffer(move);
  if ((move.substr(0,1)).find_first_of("12345678") == string::npos)
    buffer >> ch >> r;
  else buffer >> r >> ch;
  r = r - 1;
  if (ch == 'a' || ch == 'A') c = 0;
  if (ch == 'b' || ch == 'B') c = 1;
  if (ch == 'c' || ch == 'C') c = 2;
  if (ch == 'd' || ch == 'D') c = 3;
  if (ch == 'e' || ch == 'E') c = 4;
  if (ch == 'f' || ch == 'F') c = 5;
  if (ch == 'g' || ch == 'G') c = 6;
  if (ch == 'h' || ch == 'H') c = 7;
}

//Check if move made was legal
bool Othello::is_legal(const string& move)const
{
  // Check if input is valid or not.
  if (move.size() != 2) return false;
  string s1, s2;

  string legal_char = "abcdefghABCDEFGH"; //all legal input for columns
  string legal_nums = "12345678"; //all legal input for rows
  s1 = move.substr(0,1);
  s2 = move.substr(1);

  if ((s1.find_first_of(legal_char) == string::npos ||
       s2.find_first_of(legal_nums) == string::npos)&&
      (s1.find_first_of(legal_nums) == string::npos ||
       s2.find_first_of(legal_char) == string::npos))
    return false;
  //cnvert string move to coordinates.
  int row, col;
  convert_string(row,col,move);
  //check that the piece is placed in empty spot
  if (!board[row][col].is_empty()) return false;
  //check if the move would flank opposite color
  return (is_it_flanked(row,col));
}

//Checks directions to see which pices can be flipped
void Othello::process_flip(int r, int c)
{
  if (is_e_flanked(r,c)) flip_angle(r,c+1,1);     //E = 1
  if (is_ne_flanked(r,c)) flip_angle(r-1,c+1,2);  //NE = 2
  if (is_n_flanked(r,c)) flip_angle(r-1,c,3);    //N = 3
  if (is_nw_flanked(r,c)) flip_angle(r-1,c-1,4); //NW = 4
  if (is_w_flanked(r,c)) flip_angle(r,c-1,5);   //W = 5
  if (is_sw_flanked(r,c)) flip_angle(r+1,c-1,6); //SW = 6
  if (is_s_flanked(r,c)) flip_angle(r+1,c,7);   //S = 7
  if (is_se_flanked(r,c)) flip_angle(r+1,c+1,8); //SE = 8
}

//Places piece on coordinates
void Othello::make_move(const std::string& move)
{
    if (move != "") {
    int row, col;
    convert_string(row,col,move);
    if (next_mover() == HUMAN) {
      board[row][col].set_black();
      ++black;
    }else {
      board[row][col].set_white();
      ++white;
    }
    process_flip(row,col);
  }
    game::make_move(move);
   }

//Handles pieces that need flipped
void Othello::flip_angle(int r, int c, int angle)
{
  int ro, co;
  if (angle == 0) { ro = 0; co = 1; }
  else if (angle == 1)  { ro = -1; co = 1; }
  else if (angle == 2)  { ro = -1; co = 0; }
  else if (angle == 3) { ro = -1; co = -1; }
  else if (angle == 4) { ro = 0; co = -1; }
  else if (angle == 5) { ro = 1; co = -1; }
  else if (angle == 6) { ro = 1; co = 0; }
  else if (angle == 7) { ro = 1; co = 1; }
  {
    update_flip(r,c);
    return;
    flip_angle(r+ro,c+co,angle);
    update_flip(r,c);
  }
}

//Flips all pieces sent
void Othello::update_flip(const int r, const int c)
{
  board[r][c].flip();
  if (board[r][c].is_black()) {
    ++black;
    --white;
  }else {
    ++white;
    --black;
}
}

//Gets the users input
string Othello::get_user_move()const
{
    if(next_mover() == game::HUMAN){
    string answer;
    display_message("\nPlayer One Move, please: \n");
    getline(cin, answer);
    return answer;
  	}

  	if(next_mover() == game::COMPUTER){
  	string answer;
	display_message("\nPlayer Two Move, please: \n");
    getline(cin, answer);
    return answer;
	}
}

//Checks if North Direction would flank any pieces
bool Othello::is_n_flanked(int r, int c) const
{
  if (r == 0) return false;

  if (board[r-1][c].is_empty()) return false;

  int ro = 2;
  if (next_mover() == HUMAN) {
    if (board[r-1][c].is_black()) return false;
    while (r-ro >= 0 && !board[r-ro][c].is_empty()) {
      if (board[r-ro][c].is_black()) return true;
      ++ro;
    }
  }else {
    if (board[r-1][c].is_white()) return false;
    while (r-ro >= 0 && !board[r-ro][c].is_empty()) {
      if (board[r-ro][c].is_white()) return true;
      ++ro;
    }
  }
  return false;
}

//Checks if North-East Direction would flank any pieces
bool Othello::is_ne_flanked(int r, int c) const
{
  if (r == 0 || c == 7) return false;

  if (board[r-1][c+1].is_empty()) return false;

  int ro = 2, co = 2;
  if (next_mover() == HUMAN) {
    if (board[r-1][c+1].is_black()) return false;
    while (r-ro >= 0 && c+co <= 7 && !board[r-ro][c+co].is_empty()) {
      if (board[r-ro][c+co].is_black()) return true;
      ++ro; ++co;
    }
  }else {
    if (board[r-1][c+1].is_white()) return false;
    while (r-ro >= 0 && c+co <= 7 && !board[r-ro][c+co].is_empty()) {
      if (board[r-ro][c+co].is_white()) return true;
      ++ro; ++co;
    }
  }
  return false;
}

//Checks if East Direction would flank any pieces
bool Othello::is_e_flanked(int r, int c) const
{
  if (c == 7) return false;

  if (board[r][c+1].is_empty()) return false;

  int co = 2;
  if (next_mover() == HUMAN) {
    if (board[r][c+1].is_black()) return false;
    while (c+co <= 7 && !board[r][c+co].is_empty()) {
      if (board[r][c+co].is_black()) return true;
      ++co;
    }
  }else {
    if (board[r][c+1].is_white()) return false;
    while (c+co <= 7 && !board[r][c+co].is_empty()) {
      if (board[r][c+co].is_white()) return true;
      ++co;
    }
  }
  return false;
}

//Checks if South-East Direction would flank any pieces
bool Othello::is_se_flanked(int r, int c) const
{
  if (r == 7 || c == 7) return false;

  if (board[r+1][c+1].is_empty()) return false;

  int ro = 2, co = 2;
  if (next_mover() == HUMAN) {
    if (board[r+1][c+1].is_black()) return false;
    while (r+ro <= 7 && c+co <= 7 && !board[r+ro][c+co].is_empty()) {
      if (board[r+ro][c+co].is_black()) return true;
      ++ro; ++co;
    }
  }else {
    if (board[r+1][c+1].is_white()) return false;
    while (r+ro <= 7 && c+co <= 7 && !board[r+ro][c+co].is_empty()) {
      if (board[r+ro][c+co].is_white()) return true;
      ++ro; ++co;
    }
  }
  return false;
}

//Checks if South Direction would flank any pieces
bool Othello::is_s_flanked(int r, int c) const
{
  if (r == 7) return false;

  if (board[r+1][c].is_empty()) return false;

  int ro = 2;
  if (next_mover() == HUMAN) {
    if (board[r+1][c].is_black()) return false;
    while (r+ro <= 7 && !board[r+ro][c].is_empty()) {
      if (board[r+ro][c].is_black()) return true;
      ++ro;
    }
  }else {
    if (board[r+1][c].is_white()) return false;
    while (r+ro <= 7 && !board[r+ro][c].is_empty()) {
      if (board[r+ro][c].is_white()) return true;
      ++ro;
    }
  }
  return false;
}

//Checks if South-West Direction would flank any pieces
bool Othello::is_sw_flanked(int r, int c) const
{
  if (r == 7 || c == 0) return false;

  if (board[r+1][c-1].is_empty()) return false;

  int ro = 2, co = 2;
  if (next_mover() == HUMAN) {
    if (board[r+1][c-1].is_black()) return false;
    while (r+ro <= 7 && c-co >= 0 && !board[r+ro][c-co].is_empty()) {
      if (board[r+ro][c-co].is_black()) return true;
      ++ro; ++co;
    }
  }else {
    if (board[r+1][c-1].is_white()) return false;
    while (r+ro <= 7 && c-co >= 0 && !board[r+ro][c-co].is_empty()) {
      if (board[r+ro][c-co].is_white()) return true;
      ++ro; ++co;
    }
  }
  return false;
}

///Checks if West Direction would flank any pieces
bool Othello::is_w_flanked(int r, int c) const
{
  if (c == 0) return false;

  if (board[r][c-1].is_empty()) return false;

  int co = 2;
  if (next_mover() == HUMAN) {
    if (board[r][c-1].is_black()) return false;
    while (c-co >= 0 && !board[r][c-co].is_empty()) {
      if (board[r][c-co].is_black()) return true;
      ++co;
    }
  }else {
    if (board[r][c-1].is_white()) return false;
    while (c-co >= 0 && !board[r][c-co].is_empty()) {
      if (board[r][c-co].is_white()) return true;
      ++co;
    }
  }
  return false;
}

//Checks if North-West Direction would flank any pieces
bool Othello::is_nw_flanked(int r, int c) const
{
  if (r == 0 || c == 0) return false;

  if (board[r-1][c-1].is_empty()) return false;

  int ro = 2, co = 2;
  if (next_mover() == HUMAN) {
    if (board[r-1][c-1].is_black()) return false;
    while (r-ro >= 0 && c-co >= 0 && !board[r-ro][c-co].is_empty()) {
      if (board[r-ro][c-co].is_black()) return true;
      ++ro; ++co;
    }
  }else {
    if (board[r-1][c-1].is_white()) return false;
    while (r-ro >= 0 && c-co >= 0 && !board[r-ro][c-co].is_empty()) {
      if (board[r-ro][c-co].is_white()) return true;
      ++ro; ++co;
    }
  }
  return false;
}

//Calculates which player is currently winning
bool Othello::winning()
   {
      int row, column;

      int whcnt, blcnt = 0;

      for(row = 0; row < 8; ++row)
      {
         for(column = 0; column < 8; ++ column)
         {
            if(board[row][column].is_white())
            {whcnt++;}
            if(board[row][column].is_black())
            {blcnt++;}
         }
      }
      if(whcnt < blcnt)
      {return game::COMPUTER;}
      if(whcnt > blcnt)
      {return game::HUMAN;}
      if(whcnt = blcnt)
      {return game::NEUTRAL;}
   }
