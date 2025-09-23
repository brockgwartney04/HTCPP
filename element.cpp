#include "element.hpp"
#include <sstream>

namespace HTML{

    void Element::setID(const std::string &val){
        id = val; 
    }

    void Element::setClass(const std::string &val){
        class_spec = val;
    }

    void Element::insertChild(std::unique_ptr<Element> child){
        children.push_back(std::move(child));
    }

    void Element::removeChild(std::unique_ptr<Element> child){

    }

    void Element::addAttribute(std::string attribute, std::string value){
        attributes.insert_or_assign(attribute, value);
    }

    std::string Element::buildAttribute() const {

        std::ostringstream ret_html;

        for(const auto& [attribute, value] : attributes){
            ret_html<<" "<<attribute<<"=\""<<value<<"\"";
        }

        return ret_html.str();
    }

    std::string Element::loopChildren() const{

        std::string ret_html = "";

        for(const auto& child : children){
            ret_html.append(child->buildHTML());
        }

        return ret_html; 
    }

}