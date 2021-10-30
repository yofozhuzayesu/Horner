#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int horner(std::vector<int> list, int n, int i, int x,
           std::vector<int> &intermediate_value);

// n为多项式长度
template <typename Container>
int horner(std::vector<int> list, int n, int i, int x,
           std::back_insert_iterator<Container> iter) {
    if (i == n - 1) {
        iter = list[i];
        ++iter;
        return list[i];
    }
    //用于输出每次迭代结果
    int val = horner(list, n, i + 1, x, iter) * x + list[i];
    iter = val;
    ++iter;
    return val;
}

int main() {
    std::vector<int> list = {1, 1, 2, 3};  // 1 + x + 2 * x ^ 2 + 3 * x ^ 3
    std::vector<int> intermediate_value;
    horner(list, std::size(list), 0, 2, std::back_inserter(intermediate_value));
    copy(std::cbegin(intermediate_value), std::cend(intermediate_value),
         std::ostream_iterator<int>(std::cout, " "));
}
