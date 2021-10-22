#include "header.h"

Fraction::Fraction(){
    _num = 0;
    _den = 1;
}

Fraction::Fraction(long long num, long long den)
{
    _num = num;
    _den = den;
}

long long Fraction::getNum() {
    return _num;
}
long long Fraction::getDen() {
    return _den;
}
void Fraction::setNum(long long val) {
    _num = val;
}
void Fraction::setDen(long long val) {
    _den = val;
}

// 
string Fraction::toString() {
    stringstream out;
    out << _num << "/" << _den;
    return out.str();
}


Fraction::~Fraction()
{
}