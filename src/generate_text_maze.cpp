#include <iostream>
#include "maze.h"
#include "text_view.h"

int main()
{
    const size_t width = 40;
    const size_t height = 15;

    Maze maze(width, height);

    TextView view(std::cout);
    view.render(maze);
}
