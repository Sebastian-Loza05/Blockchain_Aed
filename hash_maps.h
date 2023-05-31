#pragma once
#include <iostream>
#include "forward_list.h"
#include <functional>
#include <math.h>

using namespace std;

template<typename TK, typename TV>
struct Entry{
    TK key;
    ForwardList<TV>* values;
    Entry(){}
    Entry(TK k, ForwardList<TV> *v){
        this->key = k;
        this->values = v;
    }
    Entry(TK k, TV v){
        this->key = k;
        this->values->push_front(v);
    }
    Entry(TK k){
        this->key = k;
        this->values = new ForwardList<TV>();
    }
};

const float maxFillFactor = 0.4;
const int maxColision = 3;

template<typename TK, typename TV>
class ChainHash
{
public:
private:
    ForwardList<Entry<TK, TV>>**  tabla;
    int capacity;//tamanio del array
    int size;//cantidad total de elementos
    hash<TK> hasher;

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        tabla = new ForwardList<Entry<TK, TV>>*[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            tabla[i] = new ForwardList<Entry<TK, TV>>();
        }
    }

    void insert(TK key, TV value){
        if(fillFactor() >= maxFillFactor) rehashing();
        auto hashcode = hasher(key);
        int index = hashcode % capacity;
        if(tabla[index]->size() == 0){
            auto elemento = Entry<TK, TV>(key);
            elemento.values->push_front(value);
            tabla[index]->push_front(elemento);
            this->size++;
        }
        else {
            bool ingresado = false;
            for(auto i = 0; i < tabla[index]->size(); i++){
                if(key == (*tabla[index])[i].key){
                    (*tabla[index])[i].values->push_back(value);
                    ingresado = true;
                }
            }
            if(!ingresado){
                auto elemento = Entry<TK, TV>(key);
                elemento.values->push_front(value);
                tabla[index]->push_front(elemento);
                this->size++;
            }
        }
    }

    double fillFactor(){
        return this->size / (this->capacity * maxColision * 1.0);
    }

    ForwardList<TV>* find(TK key){
        auto hashcode = hasher(key);
        int index = hashcode % capacity;
        for(auto i = 0; i < tabla[index]->size(); i++){
            if(key == (*tabla[index])[i].key){
                return (*tabla[index])[i].values;
            }
        }
        throw ("No existe");
    }

    // void remove(TK key){
    //   auto hashcode = labs(hash<TK>()(key));
    //   bool noexiste = true;
    //   int index = hashcode % capacity;
    //   auto it1 = array[index].begin();
    //   for(auto i = array[index].begin(); i != array[index].end(); i++){
    //     if(key == (*i).key){
    //       if (i == it1)
    //         array[index].pop_front();
    //       else
    //         array[index].erase_after(it1);
    //       noexiste = false;
    //       this->size--;
    //     }
    //     if(i != it1)
    //       it1++;
    //   }
    //   if(noexiste) throw std::out_of_range("No existe");
    //
    // }

    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return tabla[i]->size();
    }

    //Funcion extra para mostrar
    void display(){
        for (int i = 0; i < this->capacity; i++) {
            for(int j = 0; j < tabla[i]->size(); j++){
                cout<< (*tabla[i])[j].key << ": ";
                (*tabla[i])[j].values->mostrar();
                cout<<" - ";
            }
            if(tabla[i]->size() > 0)
                cout<<endl;
        }
    }

    ~ChainHash(){
        // delete tabla;
        // tabla = nullptr;
    }

private:
    void rehashing(){
        int old_capacity = this->capacity;
        this->capacity = this->capacity * 2;
        ForwardList<Entry<TK, TV>>** temp = new ForwardList<Entry<TK, TV>>*[this->capacity];
        for (int i = 0; i < this->capacity; i++) {
            temp[i] = new ForwardList<Entry<TK, TV>>();
        }
        for(auto i = 0; i < old_capacity; i++){
            for(auto j = 0; j < tabla[i]->size(); j++){
                auto hash_code = hasher((*tabla[i])[j].key);
                int index = hash_code % this->capacity;
                temp[index]->push_front(Entry<TK, TV>((*tabla[i])[j].key, (*tabla[i])[j].values));
            }
        }
        tabla = temp;
    }
};
