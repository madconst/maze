#include <iostream>
#include "maze.h"
#include "svg_view.h"

int main()
{
    const size_t width = 160;
    const size_t height = 90;

    Maze maze(width, height);

    SvgView view(std::cout);
    view.render(maze);
}
