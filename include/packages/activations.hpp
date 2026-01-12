#ifndef SKIC_ACTIVATIONS_HPP
#define SKIC_ACTIVATIONS_HPP

#include <vector>
#include <cmath>

namespace ski { namespace activations {

    // Sigmoid function
    double sigmoid(double x);
    std::vector<double> sigmoid(const std::vector<double>& x);

    // Tanh function
    double tanh(double x);
    std::vector<double> tanh(const std::vector<double>& x);

    // ReLU function
    double relu(double x);
    std::vector<double> relu(const std::vector<double>& x);

    // Leaky ReLU function
    double leaky_relu(double x, double alpha = 0.01);
    std::vector<double> leaky_relu(const std::vector<double>& x, double alpha = 0.01);

    // Softmax function
    std::vector<double> softmax(const std::vector<double>& x);

}}

#endif //SKIC_ACTIVATIONS_HPP