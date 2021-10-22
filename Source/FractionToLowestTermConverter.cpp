#include "header.h"

string FractionToLowestTermConverter::convert(Fraction &val) {
    Integer g;
    int gcdCal = g.gcd(val.getNum(), val.getDen());
    stringstream out;
    if (val.getNum() % val.getDen() == 0)
    {
        out << val.getNum() / val.getDen();
    } else if (gcdCal > 1) {
        out << val.getNum() / gcdCal << "/" << val.getDen() / gcdCal;
    } else {
        out << val.toString();
    }
    return out.str();
}