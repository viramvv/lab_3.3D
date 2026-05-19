#pragma once
#include "Number.h"

class RealPublic : public Number {
public:
    RealPublic();
    RealPublic(double v);
    RealPublic(const RealPublic& other);
    virtual ~RealPublic() {}

    // Специфічні математичні методи варіанту 14
    double Root(int degree) const;
    double PowerOfPi() const;

    // Перевантаження операцій (методи класу)
    RealPublic& operator=(const RealPublic& other);
    RealPublic& operator++();
    RealPublic operator++(int);
    RealPublic& operator--();
    RealPublic operator--(int);

    // Дружні бінарні операції
    friend RealPublic operator-(const RealPublic& a, const RealPublic& b);
    friend RealPublic operator*(const RealPublic& a, const RealPublic& b);
};