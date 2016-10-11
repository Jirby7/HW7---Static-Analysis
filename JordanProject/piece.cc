//Piece implementaion - Jordan Irby
#include "piece.h"

void Piece::flip()
{
	if (is_white() == true)
		set_black();
	else if (is_black() == true)
		set_white();
}
