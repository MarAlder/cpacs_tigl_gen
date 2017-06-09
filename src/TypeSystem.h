#pragma once

#include <boost/variant/recursive_wrapper.hpp>

#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stdexcept>

#include "Variant.hpp"
#include "SchemaParser.h"

namespace tigl {
    class Tables;

    enum class Cardinality {
        Optional,
        Mandatory,
        Vector
    };

    inline auto toString(const Cardinality& c) -> std::string {
        switch (c) {
            case Cardinality::Optional:  return "Optional";
            case Cardinality::Mandatory: return "Mandatory";
            case Cardinality::Vector:    return "Vector";
            default: throw std::logic_error("No toString defined");
        }
    }

    enum class XMLConstruct {
        Element,
        Attribute,
        SimpleContent,
        FundamentalTypeBase
    };

    struct Class;
    struct Enum;

    struct Field {
        std::string originXPath;
        std::string cpacsName;
        std::string typeName;
        XMLConstruct xmlType;
        unsigned int minOccurs = 0;
        unsigned int maxOccurs = 0;

        std::string customName;

        auto cardinality() const -> Cardinality {
            if (minOccurs == 0 && maxOccurs == 1)
                return Cardinality::Optional;
            else if (minOccurs == 1 && maxOccurs == 1)
                return Cardinality::Mandatory;
            else if (minOccurs >= 0 && maxOccurs > 1)
                return Cardinality::Vector;
            else
                throw std::runtime_error("Invalid cardinalities, min: " + std::to_string(minOccurs) + ", max: " + std::to_string(maxOccurs));
        }

        auto name() const -> std::string {
            if (!customName.empty())
                return customName;
            else
                return cpacsName;
        }

        auto fieldName() const -> std::string {
            return "m_" + name();
        }
    };

    // non owning
    struct ClassDependencies {
        // in the context of inheritance
        std::vector<Class*> bases;
        std::vector<Class*> deriveds;

        // in the context of the XML tree
        std::vector<Class*> parents;
        std::vector<Class*> children;
        std::vector<Enum*> enumChildren;
    };

    struct ChoiceElement {
        std::size_t index;
        bool optionalBefore;
    };

    struct Choice;
    using ChoiceElements = std::vector<boost::variant<ChoiceElement, boost::recursive_wrapper<Choice>>>;

    struct Choice {
        std::vector<ChoiceElements> options;
    };

    struct Class {
        std::string originXPath;
        std::string name;
        std::string base;
        std::vector<Field> fields;
        ChoiceElements choices;
        bool pruned = false;

        ClassDependencies deps;
    };

    struct EnumValue {
        std::string cpacsName;
        std::string customName;

        EnumValue() = default;
        EnumValue(const std::string& name)
            : cpacsName(name) {}

        auto name() const -> std::string {
            if (!customName.empty())
                return customName;
            else
                return cpacsName;
        }

        friend auto operator==(const EnumValue& a, const EnumValue& b) -> bool {
            return a.name() == b.name();
        }
    };

    struct EnumDependencies {
        std::vector<Class*> parents;
    };

    struct Enum {
        std::string originXPath;
        std::string name;
        std::vector<EnumValue> values;
        bool pruned = false;

        EnumDependencies deps;
    };

    struct TypeSystem {
        std::unordered_map<std::string, Class> classes;
        std::unordered_map<std::string, Enum> enums;
    };

    auto buildTypeSystem(xsd::SchemaTypes types, const Tables& tables) -> TypeSystem;

    void writeGraphVisFile(const TypeSystem& ts, const std::string& typeSystemGraphVisFile);
}
