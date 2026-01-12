#pragma once
#include <vector>
#include <string>
#include "Value.hpp"

namespace skic {

    // ----------------- Arithmétique -----------------
    Value add(const std::vector<Value>& args);
    Value sub(const std::vector<Value>& args);
    Value mul(const std::vector<Value>& args);
    Value div(const std::vector<Value>& args);
    Value pow(const std::vector<Value>& args);

    // ----------------- Logique -----------------
    Value and_func(const std::vector<Value>& args);
    Value or_func(const std::vector<Value>& args);
    Value not_func(const std::vector<Value>& args);

    // ----------------- Comparaison -----------------
    Value eq(const std::vector<Value>& args);
    Value ne(const std::vector<Value>& args);
    Value gt(const std::vector<Value>& args);
    Value lt(const std::vector<Value>& args);

    // ----------------- IA / Math vectorielle -----------------
    Value dot(const std::vector<Value>& args);    // produit scalaire
    Value matmul(const std::vector<Value>& args); // multiplication matrice
    Value transpose(const std::vector<Value>& args);
    Value reshape(const std::vector<Value>& args);
    Value sum(const std::vector<Value>& args);
    Value mean(const std::vector<Value>& args);

    // ----------------- Vecteurs / matrices / tenseurs -----------------
    Value vector(const std::vector<Value>& args);
    Value matrix(const std::vector<Value>& args);
    Value tensor(const std::vector<Value>& args);

    // ----------------- I/O -----------------
    Value print(const std::vector<Value>& args);
    Value println(const std::vector<Value>& args);

    // ----------------- Métaprogrammation / introspection -----------------
    Value type_of(const std::vector<Value>& args);
    Value shape(const std::vector<Value>& args); // forme d’un vecteur/matrice/tenseur

} // namespace skic
