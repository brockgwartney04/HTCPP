#include "element.hpp"

namespace HTML {
    
    class DIV : public Element{


        public:

            DIV(){
                element_name = "div";
                text = "hello World!";
            }
            
            std::string buildHTML() const override {
                return "<" + element_name + buildAttribute() + ">" + text +  loopChildren() + "</" + element_name +">";
            }

    };


};