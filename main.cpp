#include "div.hpp"
#include <iostream>

int main() {

    HTML::DIV test;

    auto childTest = std::make_unique<HTML::DIV>();
    childTest->addAttribute("style", "color: blue");

    test.insertChild(std::move(childTest));
    std::cout << test.buildHTML();
    return 0;
}