#include <iostream>
#include <vector>
#include "maze.h"
#include "text_view.h"

const std::string TextView::cell_symbols[] = 
        {"╬", "╦", "╠", "╔", 
         "╩", "═", "╚", "╞", 
         "╣", "╗", "║", "╥", 
         "╝", "╡", "╨", " "};

void TextView::render(const Maze& maze) const
{
    const size_t WIDTH = maze.get_width();
    const size_t HEIGHT = maze.get_height();

    std::vector<Maze::Wall> walls{Maze::Top, Maze::Left, Maze::Bottom, Maze::Right};
    // Print out the maze:
    for (size_t y = 0; y < HEIGHT; ++y) {
        for (size_t x = 0; x < WIDTH; ++x) {
            unsigned char wall_mask = 0;
            for (auto wall: walls) {
                wall_mask |= maze.get_wall(x, y, wall) << wall;
            }
            out << cell_symbols[wall_mask];
        }
        out << std::endl;
    }
}
