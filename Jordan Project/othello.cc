#include "othello.h"

Othello::Othello()
{
	black_c = 0;
	white_c = 0;
}

void Othello::make_move(const std::string& move)
{
	if (move != "") {
    int row, col;
    convert(row,col,move);
    if (next_mover() == HUMAN) {
      board[row][col].set_black();
      ++black_c;
    }else {
      board[row][col].set_white();
      ++white_c;
    }
    process_flip(row,col);
  }
  game::make_move(move);
}


void Othello::process_flip(int r, int c)
{
  if (is_ee_flanked(r,c)) flip_angle(r,c+1,0);     //E  - 0 degrees
  if (is_ne_flanked(r,c)) flip_angle(r-1,c+1,45);  //NE - 45 degrees
  if (is_nn_flanked(r,c)) flip_angle(r-1,c,90);    //N  - 90 degrees
  if (is_nw_flanked(r,c)) flip_angle(r-1,c-1,135); //NW - 135 degrees
  if (is_ww_flanked(r,c)) flip_angle(r,c-1,180);   //W  - 180 degrees
  if (is_sw_flanked(r,c)) flip_angle(r+1,c-1,225); //SW - 225 degrees
  if (is_ss_flanked(r,c)) flip_angle(r+1,c,270);   //S  - 270 degrees
  if (is_se_flanked(r,c)) flip_angle(r+1,c+1,315); //SE - 315 degrees
}


void Othello::flip_angle(int r, int c, int angle)
{
  int ro, co;
  if (angle == 0) { ro = 0; co = 1; }
  else if (angle == 45)  { ro = -1; co = 1; }
  else if (angle == 90)  { ro = -1; co = 0; }
  else if (angle == 135) { ro = -1; co = -1; }
  else if (angle == 180) { ro = 0; co = -1; }
  else if (angle == 225) { ro = 1; co = -1; }
  else if (angle == 270) { ro = 1; co = 0; }
  else if (angle == 315) { ro = 1; co = 1; }
  if (board[r][c] != board[r+ro][c+co]) {
    flip_and_update(r,c);
    return;
  }else{
    flip_angle(r+ro,c+co,angle);
    flip_and_update(r,c);
  }
}


void Othello::flip_and_update(const int r, const int c)
{
  board[r][c].flip();
  if (board[r][c].is_black()) {
    ++black_c;
    --white_c;
  }else {
    ++white_c;
    --black_c;
  }
}

void convert(int& r, int& c, string move)
{
  char ch;
  istringstream iss(move);
  if ((move.substr(0,1)).find_first_of("12345678") == string::npos)
    iss >> ch >> r;
  else iss >> r >> ch;
  r -= 1;
  if (ch == 'a' || ch == 'A') c = 0;
  if (ch == 'b' || ch == 'B') c = 1;
  if (ch == 'c' || ch == 'C') c = 2;
  if (ch == 'd' || ch == 'D') c = 3;
  if (ch == 'e' || ch == 'E') c = 4;
  if (ch == 'f' || ch == 'F') c = 5;
  if (ch == 'g' || ch == 'G') c = 6;
  if (ch == 'h' || ch == 'H') c = 7;
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


bool Othello::is_legal(const string& move) const
{
  if (move == "" && !are_moves_available()) return true;
  if (move == "q" || move == "Q") exit(99); //quit program
  // Check if input is valid or not.
  if (move.size() != 2) return false;
  string s1, s2;
  string legal_char = "abcdefghABCDEFGH";
  string legal_nums = "12345678";
  s1 = move.substr(0,1);
  s2 = move.substr(1);
  if ((s1.find_first_of(legal_char) == string::npos ||
       s2.find_first_of(legal_nums) == string::npos)&&
      (s1.find_first_of(legal_nums) == string::npos ||
       s2.find_first_of(legal_char) == string::npos))
    return false;
  // Convert string move to coordinates.
  int row, col;
  convert(row,col,move);
  // Now check that the piece isn't being placed on top of another.
  if (!board[row][col].is_empty()) return false;
  // Check if the move would flank the opposite color in any direction.
  return (is_it_flanked(row,col));
}


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


bool Othello::is_it_flanked(int r, int c) const
{
  if (is_ee_flanked(r,c)) return true;
  if (is_ne_flanked(r,c)) return true;
  if (is_nn_flanked(r,c)) return true;
  if (is_nw_flanked(r,c)) return true;
  if (is_ww_flanked(r,c)) return true;
  if (is_sw_flanked(r,c)) return true;
  if (is_ss_flanked(r,c)) return true;
  if (is_se_flanked(r,c)) return true;
  return false;
}


bool Othello::is_nn_flanked(int r, int c) const
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


bool Othello::is_ee_flanked(int r, int c) const
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


bool Othello::is_ss_flanked(int r, int c) const
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


bool Othello::is_ww_flanked(int r, int c) const
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
