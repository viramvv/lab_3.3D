#include "RealPrivate.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

RealPrivate::RealPrivate() : Number() {}
RealPrivate::RealPrivate(double v) : Number(v) {}
RealPrivate::RealPrivate(const RealPrivate& other) : Number(other) {}

void RealPrivate::Read() { Number::Read(); }
void RealPrivate::Display() const { Number::Display(); }
std::string RealPrivate::toString() const { return Number::toString(); }

double RealPrivate::Root(int degree) const {
    if (degree <= 0) return 0.0;
    if (Number::GetValue() < 0 && degree % 2 == 0) return 0.0;
    return std::pow(Number::GetValue(), 1.0 / degree);
}

double RealPrivate::PowerOfPi() const {
    return std::pow(M_PI, Number::GetValue());
}

RealPrivate& RealPrivate::operator=(const RealPrivate& other) {
    if (this != &other) {
        Number::operator=(other);
    }
    return *this;
}

RealPrivate& RealPrivate::operator++() {
    Number::operator++();
    return *this;
}

RealPrivate RealPrivate::operator++(int) {
    RealPrivate temp(*this);
    Number::operator++();
    return temp;
}

std::ostream& operator<<(std::ostream& out, const RealPrivate& obj) {
    out << obj.toString();
    return out;
}

std::istream& operator>>(std::istream& in, RealPrivate& obj) {
    double v;
    in >> v;
    obj.Number::SetValue(v);
    return in;
}