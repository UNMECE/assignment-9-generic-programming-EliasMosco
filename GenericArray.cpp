#include <iostream>

template <typename T>
class GenericArray {
private:
    T* data;
    int capacity;
    int length;

    void resize() {
        capacity += 1;
        T* newData = new T[capacity];
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    GenericArray(int initSize = 10)
        : capacity(initSize), size(0) {
        data = new T[capacity];
    }

    ~GenericArray() {
        delete[] data;
    }

    void addElement(const T& elem) {
        if (size >= capacity)
            resize();
        data[size++] = elem;
    }
    T sum(){
        T total = data[0];
        for(int i=0; i < size; i++ ){
            total += data[i];
        }
        return total;
    }
    T max(){
        T temp = data[0];
        for(int i=0; i< size; i++){
            if(data[i] > temp){
                temp = data[i];
            }
        }
        return temp;
    }
    T min(){
        T min = data[0];
        for(int i=0; i< size; i++){
            if(data[i] < min){
                min = data[i];
            }
        }
        return min;
    }
    T* slice(int start, int end){
        if(start < 0 || end >= size){
            throw std::out_of_range("Slice out of bounds");
        }
        int new_length = end-start;
        T* temp = new T[new_length];
        int index = 0;
        for(int i = start; i < end; i++){
            temp[index] = data[i];
            index++;
        }
        return temp;
    }
    T at(int location){
        if (index < 0 || index >= length){throw std::out_of_range("Index out of bounds");}
        return  data[location];
    }
    T getData(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    int size() const {
        return size;
    }

    void setData(int index, const T& value) {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of bounds");
        data[index] = value;
    }
};