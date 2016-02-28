#ifndef _SVG_H
#define _SVG_H

#include <vector>
#include <list>
#include <string>
#include <memory>
#include <sstream>

namespace Html
{
    constexpr size_t INDENT_WIDTH = 2; // 2 spaces

    class Node
    {
    public:
        virtual ~Node() {}
        virtual std::string serialize(size_t depth) const = 0;
    };

    class TextNode: public Node
    {
    public:
        TextNode(const std::string& text);
        std::string serialize(size_t depth = 0) const;
    private:
        std::string text_;
    };

    class HtmlNode: public Node
    {
    public:
        HtmlNode(const std::string& tag_name);
        HtmlNode(const std::string& tag_name, 
            std::initializer_list<std::pair<std::string, std::string>> attributes);
        virtual HtmlNode& append(Node* child);
        virtual void attr(std::pair<std::string, std::string> attr);
        std::string serialize(size_t depth = 0) const;
    protected:
        std::string tag_name_;
        std::list<std::unique_ptr<Node>> children_;
        std::vector<std::pair<std::string, std::string>> attributes_;
    };

    class Line: public HtmlNode
    {
    public:
        Line(std::initializer_list<std::pair<std::string, std::string>> attributes);
    };

    std::ostream& operator<<(std::ostream& out, const HtmlNode& node);
}

#endif // _SVG_H