#include <iostream>
#include <sstream>
#include <string>
#include <cstdarg>
using namespace std;
template <typename Type>

class DynamicArray {
private:
    const int MAX = 128;
    const int STEP = 50;
private:
    Type* _a;
    int _maxSize;
    int _currentSize;
public:
    DynamicArray() {        
        _a = new Type [MAX];
        _maxSize = MAX;
        _currentSize = 0;
    }

    DynamicArray(int num,...) {
        _a = new Type[MAX];
        _maxSize = MAX;
        _currentSize = 0;
        va_list valist;
        va_start(valist, num);
        for (int i = 0; i < num; i++) {
            Type tmpS = va_arg(valist, Type);
            push_back(tmpS);
       }
       va_end(valist); 
    }

    void push_back(Type value) {
        if (_currentSize == _maxSize) {
            _maxSize = _maxSize + STEP;

            Type* temp = new Type[_maxSize];

            for (int i = 0; i < _currentSize; i++) {
                temp[i] = _a[i];
            }

            delete[] _a;
            _a = temp;
        }

        _a[_currentSize] = value;
        _currentSize++;
    }

    int size() {
        return _currentSize;
    }

    Type getAt(int ind) {
        if (ind < 0 || ind >= _currentSize) {
            throw "Index out of range";
        } else
        return _a[ind];
    }

    Type operator[](int index) {
        return getAt(index);
    }

public:
    ~DynamicArray() {
        delete[] _a;
    }
};

int main() {
    DynamicArray<string> Arr(1, "hi");
    // Arr.push_back("hi");
    cout << Arr.size() << endl;
    cout << Arr[0];
    return 0;
}