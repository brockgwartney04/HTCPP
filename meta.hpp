#pragma once
#include "element.hpp"

namespace HTML {

    class Meta;

    class Meta : public Element{

        public:
            std::string buildHTML() const override{
                return "<meta" + buildAttribute() + ">";
            }

    };


}