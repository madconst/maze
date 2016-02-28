#include <vector>
#include <list>
#include <string>
#include <memory>
#include <sstream>
#include "svg.h"

namespace Html
{
    TextNode::TextNode(const std::string& text) :
        text_(text)
    {}
    std::string TextNode::serialize(size_t depth /*= 0*/) const
    {
        return std::string(depth * INDENT_WIDTH, ' ') + text_;
    }

    HtmlNode::HtmlNode(const std::string& tag_name) : 
        tag_name_(tag_name)
    {}
    HtmlNode::HtmlNode(const std::string& tag_name, std::initializer_list<std::pair<std::string, std::string>> attributes) :
        tag_name_(tag_name)
    {
        for (auto& attr: attributes)
        {   
            attributes_.push_back(attr);
        }
    }
    HtmlNode& HtmlNode::append(Node* child)
    {
        children_.emplace_back(child);
        return *this;
    }
    void HtmlNode::attr(std::pair<std::string, std::string> attr)
    {
        attributes_.push_back(attr);
    }
    std::string HtmlNode::serialize(size_t depth /*= 0*/) const
    {
        std::string indent(depth * INDENT_WIDTH, ' ');
        std::ostringstream oss;
        oss << indent << "<" << tag_name_;
        for (auto& attr: attributes_) {
            oss << " " << attr.first << "=\"" << attr.second << "\"";
        }
        if (children_.empty()) {
            oss << " />";
        } else {
            oss << ">" << std::endl;
            for (auto& child: children_) {
                oss << child->serialize(depth + 1) << std::endl;
            }
            oss << indent << "</" << tag_name_ << ">";
        }
        return oss.str();
    }

    std::ostream& operator<<(std::ostream& out, const HtmlNode& node)
    {
        out << node.serialize();
        return out;
    }

    Line::Line(std::initializer_list<std::pair<std::string, std::string>> attributes) :
        HtmlNode("line", attributes)
    {}
}