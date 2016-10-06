#ifndef PIECE_H
#define PIECE_H
#include <string>

class Piece {
public:
  // constructor
  Piece() { color = ""; }
  // Modifiers
  void flip();
  void set_black() { color = "B"; }
  void set_white() { color = "W"; }
  // Accessor
  bool is_empty() const;
  bool is_black() const;
  bool is_white() const;
  std::string get_color() const { return color; };
  // Operators
  bool operator!= (const Piece & rhs) const;
  bool operator== (const Piece & rhs) const;

  private:
  std::string color;
};

#endif
