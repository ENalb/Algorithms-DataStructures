#include "array.h"

Array::Array(int sz){
    s = sz;
    array = new int[s];
}

Array::~Array(){
    delete[] array;
    array = nullptr;
}

Array::Array(Array&& src) noexcept
    : array { std::move(src.array) },
        s { std::move(src.s) }
{
    src.array = nullptr;
    src.s = 0;
}

Array& Array::operator=(Array&& rhs) noexcept{
    if (this == &rhs) { 
        return *this; 
    }
    delete[] array;
    array = std::move(rhs.array);
    s = std::move(rhs.s);
    rhs.array = nullptr;
    rhs.s = 0;
    return *this;
}

int& Array::operator[](int x){
    if(x >= s){
        resize(x + 1);
    }
    return array[x];
}

void Array::resize(int newSize)
{
    int* newArray = new int[newSize];
    for(int i = 0; i < s; ++i){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    s = newSize;
}

const int& Array::at(int x) const{
    if(x >= s || x < 0){
        throw std::out_of_range("");
    }
    return array[x];
}

int& Array::front(){
    return array[0];
}

int& Array::back(){
    return array[s - 1];
}

int* Array::data() noexcept{
    return array;
}

bool Array::empty() const noexcept{
    if(s == 0){
        return true;
    }
    return false;
}

void Array::fill(int value){
    for(int i = 0; i < s; ++i){
        array[i] = value;
    }
}

int Array::size() const noexcept{
    return s;
}

std::ostream& operator<<(std::ostream& ostr, const Array& arr)
{
    for(int i = 0; i < arr.size(); ++i){
        ostr << arr.at(i) << " ";
    }
    return ostr;
}

std::istream& operator>>(std::istream& istr, Array& arr)
{
    int value;
    for(int i = 0; i < arr.size(); ++i){
        istr >> value;
        arr[i] = value;
    }
    return istr;
}
