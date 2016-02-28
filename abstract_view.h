#ifndef _ABSTRACT_VIEW_H
#define _ABSTRACT_VIEW_H

#include <ostream>
#include "maze.h"

class AbstractView
{
public:
	AbstractView() = delete;
	explicit AbstractView(std::ostream& out_) : out(out_) {}
	virtual ~AbstractView() {}
	virtual void render(const Maze& maze) const = 0;
protected:
	std::ostream& out;
};

#endif // _ABSTRACT_VIEW_H