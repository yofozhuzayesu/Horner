#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

// n为多项式长度
template <typename Iterator>
int horner(Iterator first, Iterator last, const int x) {
    if (first == last) {
        return 0;
    }
    const auto ret = horner(first + 1, last, x) * x + *first;
    std::cout << ret << ' ';
    return ret;
}

int main() {
    std::vector<int> coefficients = {1, 1, 2,
                                     3};  // 3 * x ^ 3 + 2 * x ^ 2 + x + 1
    horner(std::begin(coefficients), std::end(coefficients), 2);
}
