#include <iostream>
#include <cstdint>

constexpr std::uint32_t limit{10};

int main() {
    std::uint64_t sum{0};

    // 3
    for(std::uint32_t i = 0; i < 1000; i += 3) {
        if (i % 15 != 0)
            sum += i;
    }
    
    // 5
    for(std::uint32_t i = 0; i < 1000; i += 5) {
        if (i % 15 != 0)
            sum += i;
    }

    std::cout << "Sum = " << sum <<'\n';
}
