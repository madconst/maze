#ifndef _MAZE_H
#define _MAZE_H

#include <vector>
#include <cstddef>
#include <random>

class Maze
{
public:
    enum Wall { Top = 0, Left = 1, Bottom = 2, Right = 3 };
    Maze(size_t width, size_t height);
    bool get_wall(size_t x, size_t y, Wall wall) const;
    size_t get_width() const;
    size_t get_height() const;
private:
    void remove_wall(size_t x, size_t y, Wall wall);
    void mark_visited(size_t x, size_t y);
    bool is_visited(size_t x, size_t y) const;
    void build(size_t x, size_t y);

    const size_t num_of_columns, num_of_rows;
    std::vector<unsigned char> cell_walls; // 2 walls per cell: top and left
    std::vector<unsigned char> cell_status; // 1 bit per cell: 0 - pristine, 1 - visited
    std::default_random_engine rengine;
};

#endif // _MAZE_H
