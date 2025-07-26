#include <iostream>
#include <vector>
#include <string>

void generate(int n, int zeros, int ones, std::string current, std::vector<std::string>& result) {
    if (current.length() == n) {
        result.push_back(current);
        return;
    }

    if (zeros < n / 2) {
        generate(n, zeros + 1, ones, current + '0', result);
    }
    if (ones < zeros) {
        generate(n, zeros, ones + 1, current + '1', result);
    }
}

int main() {
    int num;
    std::cin >> num;

    if (num > 0 && num < 21 && num % 2 == 0) {
        std::vector<std::string> binaries;
        generate(num, 1, 0, "0", binaries);

        for (const auto& bin : binaries) {
            std::string parens;
            for (char c : bin) {
                parens += (c == '0') ? '(' : ')';
            }
            std::cout << parens << std::endl;
        }
    }

    return 0;
}
