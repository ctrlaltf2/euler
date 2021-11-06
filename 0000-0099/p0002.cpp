#include <iostream>

constexpr std::uint64_t limit{4'000'000};

int main() { std::uint64_t sum{0};
    std::uint64_t a{0}, b{1};

    while(b < limit) {
        if(b % 2 == 0)
            sum += b;

        std::swap(a, b);
        b += a;
    }

    std::cout << sum << '\n';
}
