#ifndef CIRCULAR_ARRAY_C_ARRAY_H
#define CIRCULAR_ARRAY_C_ARRAY_H
#include <iostream>

using namespace std;

// declaracion  : int current
// begin()      : current = front
// end()        : current = (array + 1)%back = next(back)
//operator++()  : next(current)
//operator--()  : prev(current)
//operator*()   : array[current]
// ** validar para cuando el array este lleno

template <class T>
class CircularArray {
private:
    T* array;
    int capacity{};
    int back{}, front{};

public:
    CircularArray(){
        CircularArray(10);
    }

    CircularArray(int _capacity){
        this->capacity = _capacity;
        this->front = this->back = -1;
        this->array = new T[_capacity];
    }

    virtual ~CircularArray(){
        delete[] array;
    }

    void push_front(T data){
        if(is_full()) throw "The array is full";
        if(is_empty()) front = back = 0;
        else front = prev(front);
        array[front] = data;
    }

    bool push_back(T data){
        if(is_full()) return false;
        if(is_empty()) front = back = 0;
        else back = next(back);
        array[back] = data;
        return true;
    }

    void insert(T data, int pos){
        int n = size();
        if(pos < 0 || pos > n) throw "index out of range";
        if(n == capacity) throw "The array is full";
        if(pos == 0)
            push_front(data);
        else {
            for (int i = n - 1; i >= pos; i--)
                (*this)[i+1] = (*this)[i];
            (*this)[pos] = data;
            back = next(back);
        }
    }

    T pop_front(){
        if(is_empty()) throw "The array is empty";
        T temp = array[front];
        if(front == back) front = back = -1;
        else front = next(front);
        return temp;
    }

    T pop_back(){
        if(is_empty()) throw "The array is empty";
        T temp = array[back];
        if(front == back) front = back = -1;
        else back = prev(back);
        return temp;
    }

    bool is_full(){
        return front == next(back) && !is_empty();
    }

    bool is_empty(){
        return front == -1;
    }

    int size(){
        if(is_empty()) return 0;
        return (back>=front)? back - front + 1: capacity - front + back + 1;
    }

    void display(){
        for (int i = 0; i < size(); i++)
            cout<<(*this)[i]<<",";
        cout<<endl;
    }

    string to_string(const string& sep=" "){
        string result = "";
        for(int i=0; i < size(); i++)
            result += std::string((*this)[i]) + sep;
        return result;
    }

    void clear(){
        front = back = -1;
    }

    T& operator[](int pos){
        if(pos >= capacity) throw "index out of range";
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


#endif //CIRCULAR_ARRAY_C_ARRAY_H
