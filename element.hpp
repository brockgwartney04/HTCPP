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

        protected: 
            std::string class_spec;
            std::string element_name;
            std::string text; 

        public:
            virtual ~Element() = default;

            void setID(const std::string &val);
            void setClass(const std::string &val);

            void insertChild(std::unique_ptr<Element> child);
            void removeChild(std::unique_ptr<Element> child);


            std::string loopChildren() const;
            virtual std::string buildHTML() const = 0;
    };
};