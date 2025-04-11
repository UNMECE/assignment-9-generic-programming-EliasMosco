#include<iostream>
#include<stdexcept>
template <typename T>
class GenericArray {

private:
    T* data;
    int capacity;
    int length;

    void resize() {
        capacity += 1;
        T* newData = new T[capacity];
        for (int i = 0; i < length; ++i)
            newData[i] = data[i];
        delete[] data;
        data = newData;
    }

public:
    GenericArray(int initSize = 10)
        : capacity(initSize), length(0) {
        data = new T[capacity];
    }

    ~GenericArray() {
        delete[] data;
    }

    void addElement(const T& elem) {
        if (length >= capacity)
            resize();
        data[length++] = elem;
    }
    T sum(){
        T total = data[0];
        for(int i=0; i < length; i++ ){
            total += data[i];
        }
        return total;
    }
    T max(){
        T temp = data[0];
        for(int i=0; i< length; i++){
            if(data[i] > temp){
                temp = data[i];
            }
        }
        return temp;
    }
    T min(){
        T min = data[0];
        for(int i=0; i< length; i++){
            if(data[i] < min){
                min = data[i];
            }
        }
        return min;
    }
    T* slice(int start, int end){
        if(start < 0 || end >= length){
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

        if (location < 0 || location >= length){throw std::out_of_range("Index out of bounds");}
        return  data[location];
    }
    T getData(int index) const {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of bounds");
        return data[index];
    }

    int size() const {
        return length;
    }

    void setData(int index, const T& value) {
        if (index < 0 || index >= length)
            throw std::out_of_range("Index out of bounds");
        data[index] = value;
    }

    
};

int main(){

    GenericArray<int> int_array;
    int_array.addElement(10);
    int_array.addElement(15);
    int_array.addElement(22);
    int_array.addElement(48);
    int_array.addElement(2);
    int_array.addElement(63);
    int_array.addElement(53);
    int_array.addElement(18);
    int_array.addElement(49);



    std::cout << "size of array is " << int_array.size() << std::endl;
    std::cout << "sum of the array is " << int_array.sum() << std::endl;
    std::cout << "maximum and minimum of array is " << int_array.max() << "\t" << int_array.min() << std::endl;
    int *sliced_array = int_array.slice(3,6);
    std::cout << " sliced array: [ "<< sliced_array[0] << ", " << sliced_array[1] << ", " << sliced_array[2] << " ]"<<  std::endl;
    
}
