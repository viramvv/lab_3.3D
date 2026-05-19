#pragma once
#include "Number.h"

class RealPrivate : private Number {
public:
    RealPrivate();
    RealPrivate(double v);
    RealPrivate(const RealPrivate& other);
    virtual ~RealPrivate() {}

    // Проксі-методи для збереження інтерфейсу ЛР 1.5/2.5
    void Read();
    void Display() const;
    std::string toString() const;
    double GetValue() const { return Number::GetValue(); }

    double Root(int degree) const;
    double PowerOfPi() const;

    RealPrivate& operator=(const RealPrivate& other);
    RealPrivate& operator++();
    RealPrivate operator++(int);

    // При закритому успадкуванні ми зобов'язані написати власні оператори потоків
    friend std::ostream& operator<<(std::ostream& out, const RealPrivate& obj);
    friend std::istream& operator>>(std::istream& in, RealPrivate& obj);
};