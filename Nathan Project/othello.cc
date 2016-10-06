

#include <iostream>
#include <string>
#include "othello.h"

using namespace main_savitch_14;

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
         cout << MAGENTA << i + 1;
         for(j = 0; j < 8; ++j)
         {
            cout << B_GREEN << " ";
            if(board[i][j].get_black() == true)
            {
               cout << BLACK << "0";
            }
            else if(board[i][j].get_white() == true)
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
	
	
	
bool Othello::is_legal(const string& move)const
   {
      int y = move[0];
      int x = move[1];
      if(next_mover() == game::HUMAN)
      {
         if(board[x-1][y-1].get_white())
         {return true;}
         if(board[x-1][y].get_white())
         {return true;}
         if(board[x][y-1].get_white())
         {return true;}
         if(board[x+1][y+1].get_white())
         {return true;}
         if(board[x+1][y].get_white())
         {return true;}
         if(board[x][y+1].get_white())
         {return true;}
         if(board[x-1][y+1].get_white())
         {return true;}
         if(board[x+1][y-1].get_white())
         {return true;}
         else
         {return false;}
      }
      else if(next_mover() == game::COMPUTER)
      {    
         if(board[x-1][y-1].get_black())
         {return true;}
         if(board[x-1][y].get_black())
         {return true;}
         if(board[x][y-1].get_black())
         {return true;}
         if(board[x+1][y+1].get_black())
         {return true;}
         if(board[x+1][y].get_black())
         {return true;}
         if(board[x][y+1].get_black())
         {return true;}
         if(board[x-1][y+1].get_black())
         {return true;}
         if(board[x+1][y-1].get_black())
         {return true;}
         else
         {return false;}
      } 
   }
   
   
   void Othello::make_move(std::string& move) 
   {
      int row, column;
      column = move[0];
      if(column == 65 ||column == 66 || column == 67 || column == 68 || column == 69 || column == 70 || column == 71 || column == 72)
      {
         column = column - 65;
      }
      else
      {
         column = column - 97;
      }
      row = move[1] - 49;
      board[row][column].is_black();
      if(is_legal(move) && next_mover() == game::HUMAN)
      {
         if(board[row - 1][column - 1].get_white())
         {board[row - 1][column - 1].flip();}
         if(board[row - 1][column].get_white())
         {board[row - 1][column].flip();}
         if(board[row][column - 1].get_white())
         {board[row][column - 1].flip();}     
         if(board[row + 1][column + 1].get_white())
         {board[row + 1][column + 1].flip();}
         if(board[row + 1][column].get_white())
         {board[row + 1][column].flip();}
         if(board[row][column + 1].get_white())
         {board[row][column + 1].flip();}   
         if(board[row + 1][column - 1].get_white())
         {board[row + 1][column - 1].flip();}
         if(board[row - 1][column + 1].get_white())
         {board[row - 1][column + 1].flip();}
      }           
      if(is_legal(move) && next_mover() == game::COMPUTER)
      {
         if(board[row - 1][column - 1].get_black())
         {board[row - 1][column - 1].flip();}
         if(board[row - 1][column].get_black())
         {board[row - 1][column].flip();}
         if(board[row][column - 1].get_black())
         {board[row][column - 1].flip();}
         if(board[row + 1][column + 1].get_black())
         {board[row + 1][column + 1].flip();}
         if(board[row + 1][column].get_black())
         {board[row + 1][column].flip();}
         if(board[row][column + 1].get_black())
         {board[row][column + 1].flip();}
         if(board[row + 1][column - 1].get_black())
         {board[row + 1][column - 1].flip();}
         if(board[row - 1][column + 1].get_black())
         {board[row - 1][column + 1].flip();}
      }
   }

   string Othello::get_user_move()
   {
      if(next_mover() == game::HUMAN)
      {
         cout << BLUE <<  "Player One's move" << endl;
         string answer;
         cout << "Enter your move: " << RESET;
         cin >> answer;
         return answer;
      }
      if(next_mover() == game::COMPUTER)
      {
         cout << RED <<  "Player two's move" << endl;
         string answer;
         cout << "Enter your move: " << RESET;
         cin >> answer;
         return answer;
      }
   }
