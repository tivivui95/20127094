#include "header.h"
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

Fraction Add(Fraction A, Fraction B) {
    Fraction result(A.getNum()*B.getDen() + B.getNum()*A.getDen(), A.getDen() * B.getDen());
    return result;
}

int main() {
    DynamicArray<int> Arr(5, 1,2,3,4,5);
    cout << "Int array with " << Arr.size() << " elements" << endl;
    for (int i = 0; i < Arr.size(); i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
    Arr.push_back(12);
    cout << "Int array with " << Arr.size() << " elements" << endl;
    for (int i = 0; i < Arr.size(); i++) {
        cout << Arr[i] << " ";
    }
    cout << endl;
    
    DynamicArray<string> StringArr;
    StringArr.push_back("hi");
    StringArr.push_back("everyone");
    cout << "String array with " << StringArr.size() << " elements" << endl;
    for (int i = 0; i < StringArr.size(); i++) {
        cout << StringArr[i] << ", ";
    }
    cout << endl;
    StringArr.push_back("it's");
    StringArr.push_back("me");
    cout << "String array with " << StringArr.size() << " elements" << endl;
    for (int i = 0; i < StringArr.size(); i++) {
        cout << StringArr[i] << ", ";
    }
    cout << endl;
    
    DynamicArray<Fraction> FractionArr;
    Fraction a(1,2);
    Fraction b(3,4);
    Fraction c(1,6);
    FractionArr.push_back(a);
    FractionArr.push_back(b);
    FractionArr.push_back(c);
    Fraction result(0, 1);
    FractionToLowestTermConverter FtL;
    for (int i = 0; i < FractionArr.size(); i++)
        result = Add(result, FractionArr[i]);

    cout << "Sum of all Fractions is: " << FtL.convert(result) << endl;

    string lastNames[] = {"Nguyen", "Tran", "Le", "Phan", "Dang", "Duong", "Do", "Ngo", "Ly", "Mai", "Trinh", "Chung", "Nham", "Ha", "Vu"};
    string firstNames[] = {"Thanh", "Tung", "Van", "Quynh", "Huy", "Phu", "Quan", "Chau", "Viet", "Nam", "Anh", "Tram", "Lam", "Quang", "Duc", "Hai"};
    string middleNames[] = {"Nhat", "Van", "Dat", "Minh", "Duy", "Tuan", "Ngoc", "Bao", "Cong", "Khai", "Thien", "Duc", "Manh", "Bao", "Quoc", "Nhu"};

    Random rng;
    int n = rng.next(10, 20);
    DynamicArray<string> NameArr;
    for (int i = 0; i < n; i++)
    {
        stringstream writer; 
        writer << lastNames[rng.next(14)] << " " << middleNames[rng.next(15)] << " " << firstNames[rng.next(15)];
        NameArr[i] = writer.str(); 
        cout << NameArr[i] << endl;
    }
    cout << n << " names has been generated." << endl;
    cin.get();
    return 0;
}