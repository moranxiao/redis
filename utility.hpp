#include <iostream>
#include <utility>

template<typename Container>
static inline void Print(const Container& con)
{
    for(const auto& elem : con)
        std::cout << elem << std::endl;
}