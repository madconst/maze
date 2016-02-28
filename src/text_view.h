#ifndef _TEXT_VIEW_H
#define _TEXT_VIEW_H

#include <string>
#include "abstract_view.h"

class TextView: public AbstractView
{
public:
	TextView(std::ostream& out) : AbstractView(out) {}
	void render(const Maze& maze) const;
private:
	/*
	RBLT
	0000 "╬"
	0001 "╦"
	0010 "╠"
	0011 "╔"
	0100 "╩"
	0101 "═"
	0110 "╚"
	0111 "╞"
	1000 "╣"
	1001 "╗"
	1010 "║"
	1011 "╥"
	1100 "╝"
	1101 "╡"
	1110 "╨"
	1111 " "
	*/
	static const std::string cell_symbols[];
};

#endif // _TEXT_VIEW_H