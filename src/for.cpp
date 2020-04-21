#include "for.hpp"
#include <iostream>
#include <string>

void Range::print(size_t indent) {
    std::cout << "[concat";
    for (auto e : elements) {
        std::cout << ' ';
        e->print();
    }
    std::cout << ']';
}

For::For(String* variable, Range* range, Element* body)
    : variable(variable), range(range), body(body) {
}

void For::print(size_t indent) {
    std::cout << std::string(indent, '\t') << "foreach ";
    variable->print();
    std::cout << ' ';
    range->print();
    std::cout << " {\n";
    body->print(indent + 1);
    std::cout << "}";
}

Pattern::Pattern(String* s) : pattern(s) {
}

void Pattern::print(size_t indent) {
    std::cout << "[glob ";
    pattern->print();
    std::cout << "]";
}

Element* Pattern::check_pattern(String* s) {
    if (s->find('*') || s->find('?'))
        return new Pattern(s);
    return s;
}