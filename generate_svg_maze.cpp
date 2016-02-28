#include <iostream>
#include "maze.h"
#include "svg_view.h"

int main()
{
    const size_t width = 200;
    const size_t height = 150;

    Maze maze(width, height);

    SvgView view(std::cout);
    view.render(maze);
}
