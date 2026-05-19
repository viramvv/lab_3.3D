#pragma once
#include <iostream>
#include <string>

class Number {
private:
    double value;
public:
    Number();
    Number(double v);
    Number(const Number& other);
    virtual ~Number() {}

    bool Init(double v);
    void Read();
    void Display() const;
    std::string toString() const;

    double GetValue() const { return value; }
    void SetValue(double v) { value = v; }

    Number& operator=(const Number& other);
    Number& operator++();
    Number operator++(int);
    Number& operator--();
    Number operator--(int);

    friend Number operator-(const Number& a, const Number& b);
    friend Number operator*(const Number& a, const Number& b);

    friend std::ostream& operator<<(std::ostream& out, const Number& obj);
    friend std::istream& operator>>(std::istream& in, Number& obj);
};