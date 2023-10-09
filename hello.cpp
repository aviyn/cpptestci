// Example program
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

namespace numerical_chars {
inline std::ostream &operator<<(std::ostream &os, char c) {
    return std::is_signed<char>::value ? os << static_cast<int>(c)
                                       : os << static_cast<unsigned int>(c);
}

inline std::ostream &operator<<(std::ostream &os, signed char c) {
    return os << static_cast<int>(c);
}

inline std::ostream &operator<<(std::ostream &os, unsigned char c) {
    return os << static_cast<unsigned int>(c);
}
}

//using namespace numerical_chars;

struct test {
    int a{0};
    std::vector<uint8_t> vec = {1,2,3,4};
    test() {};
    test(int a, std::initializer_list<uint8_t> lst) : a{a}, vec{lst} {};
};

int main()
{
  std::string name;
  
  test t{2, {1, 3}};
  for (auto& elm: t.vec) std::cout << std::hex << elm << std::endl;
  
  test t2;
  for (auto& elm: t2.vec) std::cout << elm << std::endl;
  
  t2 = std::move(t);
    for (auto& elm: t.vec) std::cout << elm << std::endl;
   for (auto& elm: t2.vec) std::cout << elm << std::endl;
   
   t = test{5, {6,7}};
   for (auto& elm: t.vec) std::cout << elm << std::endl; 
  //std::cout << "What is your name? ";
  //getline (std::cin, name);
  //std::cout << "Hello, " << name << "!\n";
}

