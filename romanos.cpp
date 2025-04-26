#include "romanos.hpp"
#include <map>

int ConversorRomano::converter(const string& romano) {
    map<char, int> valores = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    return 1;
};