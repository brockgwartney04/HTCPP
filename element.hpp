#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>

/**
 *  Namespace for HTML Framework
 */
namespace HTML{

    class Element; 
    inline std::map<std::string, Element*> GlobalDOMIDs;

    /** 
     *  Base Class in which all HTML Elements are Derived From
    */
    class Element{

        std::string id;
        std::vector<std::unique_ptr<Element>> children;
        std::map<std::string, std::string> attributes;

        protected: 
            std::string class_spec;
            std::string element_name;
            std::string text; 

            std::string buildAttribute() const;

        public:
            virtual ~Element() = default;

            void setID(const std::string &val);
            void setClass(const std::string &val);


            //Todo Classes into types of tags so that things like InsertCHild cannot be called by meta tags, have intermiditary class prolly
            void insertChild(std::unique_ptr<Element> child);
            void removeChild(std::unique_ptr<Element> child);
            
            //TODO: need to account for Boolean Attributes!
            void addAttribute(std::string attribute, std::string value);
            std::string loopChildren() const;
            virtual std::string buildHTML() const = 0;
    };
};