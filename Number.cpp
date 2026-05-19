#include "Number.h"
#include <sstream>

Number::Number() : value(0.0) {}
Number::Number(double v) : value(v) {}
Number::Number(const Number& other) : value(other.value) {}

bool Number::Init(double v) {
    value = v;
    return true; 
}

void Number::Read() {
    std::cout << "Введіть числове значення: ";
    std::cin >> value;
}

void Number::Display() const {
    std::cout << toString() << std::endl;
}

std::string Number::toString() const {
    std::stringstream ss;
    ss << value;
    return ss.str();
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

Number& Number::operator++() {
    value += 1.0;
    return *this;
}

Number Number::operator++(int) {
    Number temp(*this);
    value += 1.0;
    return temp;
}

Number& Number::operator--() {
    value -= 1.0;
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    value -= 1.0;
    return temp;
}

Number operator-(const Number& a, const Number& b) {
    return Number(a.value - b.value);
}

Number operator*(const Number& a, const Number& b) {
    return Number(a.value * b.value);
}

std::ostream& operator<<(std::ostream& out, const Number& obj) {
    out << obj.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Number& obj) {
    in >> obj.value;
    return in;
}