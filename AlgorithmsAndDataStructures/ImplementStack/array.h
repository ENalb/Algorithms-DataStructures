#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array {
public:
    Array(int s);
    ~Array();
    Array(Array&& src) noexcept;
    Array& operator=(Array&& rhs) noexcept;
    void resize(int newSize);
    const int& at(int x) const;
    int& front();
    int& back();
    int* data() noexcept;
    bool empty() const noexcept;
    void fill(int value);
    int size() const noexcept;
    int& operator[](int x);
    friend std::ostream& operator<<(std::ostream& ostr, const Array& arr);
    friend std::istream& operator>>(std::istream& istr, Array& arr);
private:
    int* array;
    int s;
};

#endif
