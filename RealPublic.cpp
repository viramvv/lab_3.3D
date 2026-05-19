#include "RealPublic.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RealPublic::RealPublic() : Number() {}
RealPublic::RealPublic(double v) : Number(v) {}
RealPublic::RealPublic(const RealPublic& other) : Number(other) {}

double RealPublic::Root(int degree) const {
    if (degree <= 0) return 0.0;
    if (GetValue() < 0 && degree % 2 == 0) return 0.0; // Валідація кореня
    return std::pow(GetValue(), 1.0 / degree);
}

double RealPublic::PowerOfPi() const {
    return std::pow(M_PI, GetValue());
}

RealPublic& RealPublic::operator=(const RealPublic& other) {
    if (this != &other) {
        Number::operator=(other);
    }
    return *this;
}

RealPublic& RealPublic::operator++() {
    Number::operator++();
    return *this;
}

RealPublic RealPublic::operator++(int) {
    RealPublic temp(*this);
    Number::operator++();
    return temp;
}

RealPublic& RealPublic::operator--() {
    Number::operator--();
    return *this;
}

RealPublic RealPublic::operator--(int) {
    RealPublic temp(*this);
    Number::operator--();
    return temp;
}

RealPublic operator-(const RealPublic& a, const RealPublic& b) {
    return RealPublic(a.GetValue() - b.GetValue());
}

RealPublic operator*(const RealPublic& a, const RealPublic& b) {
    return RealPublic(a.GetValue() * b.GetValue());
}