#ifndef _SVG_VIEW_H
#define _SVG_VIEW_H

#include "abstract_view.h"

class SvgView: public AbstractView
{
public:
    SvgView(std::ostream& out) : AbstractView(out) {}
    void render(const Maze& maze) const;
};

#endif // _SVG_VIEW_H