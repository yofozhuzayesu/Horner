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
    *first = ret;
    return ret;
}

int main() {
    std::vector<int> coefficients = {3, 2, 1,
                                     1};  // 3 * x ^ 3 + 2 * x ^ 2 + x + 1

    // Naive Horner Method
    horner(std::rbegin(coefficients), std::rend(coefficients), 2);
    std::cout << std::endl;

    // Once again! Hi, Indian Mi fans!
    copy(std::cbegin(coefficients), std::cend(coefficients),
         std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    coefficients.pop_back();
    const auto ret =
        horner(std::rbegin(coefficients), std::rend(coefficients), 2);
    std::cout << '\n' << ret << std::endl;
}
