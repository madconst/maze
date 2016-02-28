#include <algorithm>
#include "maze.h"

Maze::Maze(size_t width, size_t height) :
    num_of_columns(width),
    num_of_rows(height)
{
    std::random_device rd;
    rengine = std::default_random_engine(rd());
    size_t num_of_cells = num_of_rows * num_of_columns;
    cell_walls.resize((num_of_cells + 3) / 4, 0xff); // 1-bit - all walls are present
    cell_status.resize(num_of_cells / 8 + 1, 0x0); // 0-bit - all cells are pristine (not visited)
    build(0, 0); // build the maze starting from point (0, 0)
}
bool Maze::get_wall(size_t x, size_t y, Wall wall) const
{
    if (x >= num_of_columns || y >= num_of_rows) {
        return true;
    }
    if (wall == Right) {
        return get_wall(x + 1, y, Left);
    } else if (wall == Bottom) {
        return get_wall(x, y + 1, Top);
    } else { // `Top` or `Left` wall
        size_t cell_index = y * num_of_columns + x;
        size_t offset_in_byte = 2 * (cell_index % 4) + wall;
        return (cell_walls[cell_index / 4] >> offset_in_byte) & 0x1;
    }
}
void Maze::remove_wall(size_t x, size_t y, Wall wall)
{
    if (x >= num_of_columns || y >= num_of_rows) {
        return;
    }
    if (wall == Right) {
        remove_wall(x + 1, y, Left);
    } else if (wall == Bottom) {
        remove_wall(x, y + 1, Top);
    } else { // `Top` or `Left` wall:
        size_t cell_index = y * num_of_columns + x;
        size_t offset_in_byte = 2 * (cell_index % 4) + wall;
        cell_walls[cell_index / 4] &= ~(1 << offset_in_byte);
    }
}
void Maze::mark_visited(size_t x, size_t y)
{
    if (x >= num_of_columns || y >= num_of_rows) {
        return;
    }
    size_t cell_index = y * num_of_columns + x;
    size_t offset_in_byte = cell_index % 8;
    cell_status[cell_index / 8] |= 1 << offset_in_byte;
}
bool Maze::is_visited(size_t x, size_t y) const
{
    if (x >= num_of_columns || y >= num_of_rows) {
        return true;
    }

    size_t cell_index = y * num_of_columns + x;
    size_t offset_in_byte = cell_index % 8;
    return cell_status[cell_index / 8] & (1 << offset_in_byte);
}
size_t Maze::get_width() const
{
    return num_of_columns;
}
size_t Maze::get_height() const
{
    return num_of_rows;
}

void Maze::build(size_t x, size_t y)
{
    if (is_visited(x, y)) {
        return;
    }

    mark_visited(x, y);

    std::vector<Wall> walls{Top, Left, Bottom, Right};
    std::shuffle(walls.begin(), walls.end(), rengine);

    for (size_t i = 0; i < walls.size(); ++i) {
        Wall wall = walls[i];
        if (wall == Top && y > 0 && !is_visited(x, y - 1))
        {
            remove_wall(x, y, Top);
            build(x, y - 1);
        }
        if (wall == Left && x > 0 && !is_visited(x - 1, y))
        {
            remove_wall(x, y, Left);
            build(x - 1, y);
        }
        if (wall == Right && !is_visited(x + 1, y))
        {
            remove_wall(x, y, Right);
            build(x + 1, y);
        }
        if (wall == Bottom && !is_visited(x, y + 1))
        {
            remove_wall(x, y, Bottom);
            build(x, y + 1);
        }
    }
}