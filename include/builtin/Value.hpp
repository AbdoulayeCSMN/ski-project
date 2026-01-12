#pragma once
#include <string>
#include <vector>
#include <variant>
#include <iostream>
#include <memory>

namespace skic {

    // Type générique pour toutes les valeurs
    struct Value {
        enum class Type { INT, FLOAT, BOOL, STRING, VECTOR, MATRIX, TENSOR, VOID } type;

        // Data variant adapté à IA
        std::variant<
            int,
            double,
            bool,
            std::string,
            std::vector<Value>,                     // VECTOR
            std::vector<std::vector<Value>>,        // MATRIX
            std::vector<std::vector<std::vector<Value>>> // TENSOR
        > data;

        // Constructeurs
        Value() : type(Type::VOID) {}
        Value(int v) : type(Type::INT), data(v) {}
        Value(double v) : type(Type::FLOAT), data(v) {}
        Value(bool v) : type(Type::BOOL), data(v) {}
        Value(const std::string& v) : type(Type::STRING), data(v) {}
        Value(const std::vector<Value>& v) : type(Type::VECTOR), data(v) {}
        Value(const std::vector<std::vector<Value>>& v) : type(Type::MATRIX), data(v) {}
        Value(const std::vector<std::vector<std::vector<Value>>>& v) : type(Type::TENSOR), data(v) {}

        // Conversion simple en chaîne pour affichage
        std::string toString() const {
            switch (type) {
                case Type::INT: return std::to_string(std::get<int>(data));
                case Type::FLOAT: return std::to_string(std::get<double>(data));
                case Type::BOOL: return std::get<bool>(data) ? "true" : "false";
                case Type::STRING: return std::get<std::string>(data);
                case Type::VECTOR: return "[vector]";
                case Type::MATRIX: return "[matrix]";
                case Type::TENSOR: return "[tensor]";
                case Type::VOID: return "void";
            }
            return "";
        }
    };

} // namespace skic
