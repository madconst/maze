#include "svg_view.h"
#include "svg.h"

void SvgView::render(const Maze& maze) const
{
    using Html::HtmlNode;
    using Html::TextNode;
    using Html::Line;

    out << "<!DOCTYPE html>" << std::endl;

    HtmlNode html("html");

    HtmlNode* style = new HtmlNode("style");
    style->append(new TextNode("line { stroke:rgb(0,0,0); }"));
    html.append(style);

    HtmlNode* body = new HtmlNode("body");
    html.append(body);

    const size_t svg_width = 800, svg_height = 600;
    HtmlNode* svg = new HtmlNode("svg", {
        {"width", std::to_string(svg_width)},
        {"height", std::to_string(svg_height)}
    });
    body->append(svg);

    const size_t cell_width = svg_width / maze.get_width();
    const size_t cell_height = svg_height / maze.get_height();

    // Print out the maze:
    for (size_t y = 0; y < maze.get_height(); ++y) {
        for (size_t x = 0; x < maze.get_width(); ++x) {
            if (maze.get_wall(x, y, Maze::Top)) {
                svg->append(new Line{
                    {"x1", std::to_string(x * cell_width)},
                    {"y1", std::to_string(y * cell_height)},
                    {"x2", std::to_string((x + 1) * cell_width)},
                    {"y2", std::to_string(y * cell_height)}
                });
            }
            if (maze.get_wall(x, y, Maze::Left)) {
                svg->append(new Line{
                    {"x1", std::to_string(x * cell_width)},
                    {"y1", std::to_string(y * cell_height)},
                    {"x2", std::to_string(x * cell_width)},
                    {"y2", std::to_string((y + 1) * cell_height)}
                });
            }
        }
    }
    out << html;
}