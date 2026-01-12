#include "packages/activations.hpp"
#include <numeric>
#include <algorithm>

namespace ski { namespace activations {

    double sigmoid(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }

    std::vector<double> sigmoid(const std::vector<double>& x) {
        std::vector<double> result;
        result.reserve(x.size());
        for (double val : x) {
            result.push_back(sigmoid(val));
        }
        return result;
    }

    double tanh(double x) {
        return std::tanh(x);
    }

    std::vector<double> tanh(const std::vector<double>& x) {
        std::vector<double> result;
        result.reserve(x.size());
        for (double val : x) {
            result.push_back(tanh(val));
        }
        return result;
    }

    double relu(double x) {
        return std::max(0.0, x);
    }

    std::vector<double> relu(const std::vector<double>& x) {
        std::vector<double> result;
        result.reserve(x.size());
        for (double val : x) {
            result.push_back(relu(val));
        }
        return result;
    }

    double leaky_relu(double x, double alpha) {
        return x > 0 ? x : alpha * x;
    }

    std::vector<double> leaky_relu(const std::vector<double>& x, double alpha) {
        std::vector<double> result;
        result.reserve(x.size());
        for (double val : x) {
            result.push_back(leaky_relu(val, alpha));
        }
        return result;
    }

    std::vector<double> softmax(const std::vector<double>& x) {
        std::vector<double> result;
        result.reserve(x.size());
        double max_val = *std::max_element(x.begin(), x.end());
        double sum = 0.0;

        for (double val : x) {
            double exp_val = std::exp(val - max_val);
            result.push_back(exp_val);
            sum += exp_val;
        }

        for (double& val : result) {
            val /= sum;
        }

        return result;
    }

}}