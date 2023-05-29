#pragma once
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "forward_list.h"
using namespace std;

template <class T>
class CircularArrayHash
{
private:
    ForwardList<T>* array;
    int capacity;
    int back, front;

public:
    CircularArrayHash(int _capacity = 10)
    {
      this->capacity = _capacity;
      this->array = new ForwardList<T>[_capacity];
      for(int i=0; i<this->capacity;i++){
        array[i] = ForwardList<T>();
      }
      this->front = this->back = -1;//empty
    }
    virtual ~CircularArrayHash(){
      delete[] array;
    }
    void redimensionar(){
      ForwardList<T>* temp = new ForwardList<T>[capacity*2];
      int capacidad_antigua = capacity;
      int capacidad_nueva = capacity*2;
      int back_temp;
      for (auto i = 0; i < size(); i++) {
        temp[(front+i)%capacidad_nueva] = array[(front+i)%capacidad_antigua];
        back_temp = (front+i)%capacidad_nueva; 
      }
      array = temp;
      capacity = capacidad_nueva;
      back = back_temp;
    }
    void push_front(ForwardList<T> data){
      if(is_full()){
        redimensionar();
      }
      if (is_empty()){
        front = 0;
        back = 0;
        array[front] = data;
      }
      else if (front == 0) {
        front = capacity - 1;
        array[front] = data;
      }
      else{
        front = front - 1;
        array[front] = data;
      }
    }
    void push_back(ForwardList<T> data){
      if (is_full())
      {
        redimensionar();
      }
      if (is_empty())
      {
        front = 0;
        back = 0;
        array[back] = data;
      }
      else
      {
        back = (back + 1) % capacity;
        array[back] = data;
      }
    }
    void insert(ForwardList<T> data, int pos){
      int tamano = size();
      int mitad = tamano/2;
      if (is_full()){
        redimensionar();
      }
      if (tamano - pos < mitad)
      {
        int temp = back;
        back = (back + 1) % capacity;
        for(int i = 0; i < (tamano - pos); i++){
          array[(temp + 1) % capacity] = array[temp];
          temp--;
        }
        array[(front+pos) % capacity]= data;
      }
      else
      {
        int temp = front;
        front = (front - 1) % capacity;
        for (int i = 0; i < pos ; i++){
          array[(temp - 1) % capacity] = array[temp];
          temp++;
        }
        array[(front + pos) % capacity] = data;
      }
    }
    ForwardList<T> pop_front(){
      int tamano = size();
      int temp = front;
      if(is_empty()) throw std::range_error("No elements");
      else if(tamano == 1){
        front = -1;
        back = -1;
        return array[temp];
      }else {
        front = (front + 1) % capacity;
        return array[temp];
      }
    }
    ForwardList<T> pop_back(){
      int tamano = size();
      int temp = back;
      if(is_empty()) throw std::range_error("No elements");
      else if(tamano == 1){
        front = -1;
        back = -1;
        return array[back];
      }else if(back == 0){
        back = capacity - 1;
        return array[back];
      }else {
        back = back - 1;
        return array[back];
      }
    }
    bool is_full(){
      int tamano = size();
      if(tamano == capacity){
        return true;
      }
      else{
        return false;
      }
    }
    bool is_empty(){
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }
    int size(){
      if(front > back)
        return capacity + back - front + 1;
      else if (front == -1)
        return 0;
      else
        return back - front +1;
    }
    void clear(){
      front = -1;
      back = -1;
    }
    ForwardList<T>& operator[](int pos){
      return array[(pos+front) % capacity];
    }
    string to_string(string sep=" "){
      string str = "";
      int tamano = size();
      for(int i = 0 ; i < tamano; i ++ ){
        int temp = array[(front + i)%capacity];
        string lol = std::to_string(temp);
        str += lol + sep;
      }
      return str;
    }

private:
    int next(int index){
      if(!is_empty()) throw std::range_error("No elements");
      else{
        index = (index + 1) % capacity;
        return index;
      }
    }
    int prev(int index){
      if(!is_empty()) throw std::range_error("No elements");
      else if(index == 0){
        index = capacity - 1;
        return index;
      }
      else{
        index = (index - 1);
        return index;
      }

    }
};


// template <class T>
// T CircularArray<T>::operator[](int pos){
//   return array[pos];
// }

