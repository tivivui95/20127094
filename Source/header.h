#include <iostream>
#include <sstream>
#include <string>
#include <cstdarg>
using namespace std;

class Random {
public:
    Random() {
        srand(time(NULL)); // Current time
    }
public:
    int next() {
        int result = rand();
        return result;
    }

    int next(int ceiling) {
        int result = rand() % ceiling;
        return result;
    }

    int next(int floor, int ceiling) {
        int result = rand() % (ceiling - floor) + floor;
        return result;
    }
};

class Fraction
{
private:
    long long _num;
    long long _den;

public:
    Fraction();

    Fraction(long long, long long);

    long long getNum();
    long long getDen();
    void setNum(long long);
    void setDen(long long);

    string toString();

    ~Fraction();
};

class FractionToLowestTermConverter {
public:
    string convert(Fraction&);
    Fraction convertBack(string&); // No need to implement yet
};