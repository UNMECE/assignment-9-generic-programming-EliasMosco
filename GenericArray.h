#ifndef GENERIC_ARRAY_H
#define GENERIC_ARRAY_H

#include <stdexcept>

template <typename T>
class GenericArray {
private:
    T* data;
    int capacity;
    int length;

    void resize();

public:
    GenericArray(int initSize = 10);
    ~GenericArray();

    void addElement(const T& elem);
    T sum() const;
    T max() const;
    T min() const;

    T* slice(int start, int end) const;
    T at(int index) const;
    T getData(int index) const;
    void setData(int index, const T& value);

    int getSize() const;
};

#include "GenericArray.tpp" // Include the template implementation

#endif // GENERIC_ARRAY_H
