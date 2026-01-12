#include "builtin//fonctions.hpp"
#include <iostream>
#include <cmath>
#include <numeric>
#include <algorithm>

namespace skic {

    // ----------------- Arithmétique -----------------
    Value add(const std::vector<Value>& args) {
        // support pour int / float
        if(args[0].type == Value::Type::INT && args[1].type == Value::Type::INT)
            return Value(std::get<int>(args[0].data) + std::get<int>(args[1].data));
        else
            return Value(std::get<double>(args[0].data) + std::get<double>(args[1].data));
    }

    // ----------------- I/O -----------------
    Value print(const std::vector<Value>& args) {
        for(auto& v : args) std::cout << v.toString() << " ";
        return Value();
    }

    Value println(const std::vector<Value>& args) {
        for(auto& v : args) std::cout << v.toString() << " ";
        std::cout << std::endl;
        return Value();
    }

    // ----------------- IA / Math vectorielle -----------------
    Value sum(const std::vector<Value>& args) {
        if(args[0].type == Value::Type::VECTOR) {
            int total = 0;
            for(auto& v : std::get<std::vector<Value>>(args[0].data))
                total += std::get<int>(v.data); // simplification : vecteur int
            return Value(total);
        }
        return Value();
    }

    // Exemple shape
    Value shape(const std::vector<Value>& args) {
        if(args[0].type == Value::Type::VECTOR)
            return Value((int)std::get<std::vector<Value>>(args[0].data).size());
        if(args[0].type == Value::Type::MATRIX)
            return Value((int)std::get<std::vector<std::vector<Value>>>(args[0].data).size());
        return Value();
    }

    // ... à compléter pour les 200 fonctions

} // namespace skic
