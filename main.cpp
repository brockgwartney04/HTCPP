#include "div.hpp"
#include "meta.hpp"
#include <iostream>

int main() {

    HTML::DIV test;
    HTML::Meta title; 

    title.addAttribute("author","Brock J. Gwartney");
    auto childTest = std::make_unique<HTML::DIV>();
    childTest->addAttribute("style", "color: blue");

    test.insertChild(std::move(childTest));
    std::cout << title.buildHTML() << test.buildHTML();
    return 0;
}