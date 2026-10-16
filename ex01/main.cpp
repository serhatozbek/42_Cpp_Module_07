#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T& element) {
    element++;
}

void multiplyByTen(int& element) {
    element *= 10;
}

int main() {
    std::cout << "--- TEST 1: Normal Tam Sayi Dizisi (int) ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = 5;

    std::cout << "Orijinal: ";
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "1 Artirildi: ";
    ::iter(intArray, intLen, incrementElement<int>);
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "10 ile Carpildi: ";
    ::iter(intArray, intLen, multiplyByTen);
    ::iter(intArray, intLen, printElement<int>);
    std::cout << "\n\n";

    std::cout << "--- TEST 2: Const (Degistirilemez) String Dizisi ---" << std::endl;
    const std::string strArray[] = {"42", "Kocaeli", "Istanbul"};
    size_t strLen = 3;

    std::cout << "Stringler: ";
    ::iter(strArray, strLen, printElement<std::string>);
    std::cout << "\n\n";

    std::cout << "--- TEST 3: Karakter (char) Dizisi ---" << std::endl;
    char charArray[] = {'a', 'b', 'c'};

    std::cout << "Orijinal: ";
    ::iter(charArray, 3, printElement<char>);
    std::cout << std::endl;

    std::cout << "1 Artirildi (ASCII): ";
    ::iter(charArray, 3, incrementElement<char>);
    ::iter(charArray, 3, printElement<char>);
    std::cout << std::endl;

    return 0;
}
