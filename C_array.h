#ifndef PROYECTO_C_ARRAY_H
#define PROYECTO_C_ARRAY_H
#include <iostream>

using namespace std;

template <class T>
class CircularArray {
private:
    T* array;
    int capacity{};
    int back{}, front{};

public:
    CircularArray(){
        CircularArray(5);
    }

    explicit CircularArray(int _capacity){
        this->capacity = _capacity;
        this->front = this->back = -1;
        this->array = new T[_capacity];
    }

    //TODO: fix delete
    //virtual ~CircularArray(){
    //    delete[] array;
    //}

    bool push_back(T data){
        if(is_full()) return false;
        if(is_empty()) front = back = 0;
        else back = next(back);
        array[back] = data;
        return true;
    }

    T pop_front(){
        T temp = array[front];
        if(front == back) front = back = -1;
        else front = next(front);
        return temp;
    }

    bool is_full(){
        return front == next(back) && !is_empty();
    }

    bool is_empty(){
        return front == -1;
    }

    int size(){
        if(is_empty())
            return 0;
        else if(is_full()){
            return capacity;
        }
        return (back>=front)? back - front + 1: capacity - front + back + 1;
    }

    void display(){
        for (int i = 0; i < size(); i++)
            cout << array[i];
    }

    string to_string(const string& sep=" "){
        string result;
        for(int i=0; i < size(); i++)
            result += std::string((*this)[i]) + sep;
        return result;
    }

    void clear(){
        front = back = -1;
    }

    T& operator[](int pos){
        return array[(front + pos) % capacity];
    }
private:
    int next(int index){
        return (index + 1) % capacity;
    }

    int prev(int index){
        return (index==0)? capacity - 1: index -1;
    }
};


#endif //PROYECTO_C_ARRAY_H
