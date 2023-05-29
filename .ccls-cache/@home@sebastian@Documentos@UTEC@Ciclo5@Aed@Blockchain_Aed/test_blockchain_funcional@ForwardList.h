#ifndef UNTITLED_FORWARDLIST_H
#define UNTITLED_FORWARDLIST_H
#include <iostream>
#include "tst_Registro.h"

using namespace std;

template<class T>
class DoubleList{
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(){
            next = nullptr;
            prev = nullptr;
        }

        Node(T value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }

        void killSelf(){
          if(this != nullptr){
            next->killSelf();
          }
          delete this;
        }
    };

private:
    Node* head;
    Node* tail;
    int nodes;

public:
    DoubleList() {
        nodes = 0;
        head = nullptr;
        tail = nullptr;
    }

    // TODO: Fix delete
    ~DoubleList(){
      head->killSelf();
    }

    T& front(){
        if(!is_empty()) {
            return head->data;
        }
        throw runtime_error("Lista vacía");
    }

    T& back(){
        if(!is_empty()) {
            return tail->data;
        }
        throw runtime_error("Lista vacía");
    }

    void push_back(T data){
        Node *nuevo = new Node(data);
        nuevo->prev = tail;
        nuevo->next = nullptr;

        if(tail!= nullptr){
            tail->next = nuevo;
        }
        tail = nuevo;

        if(head==nullptr){
            head = nuevo;
        }
        ++nodes;
    }

    T pop_front(){
        if(!is_empty()){
            Node* temp = head;
            head = head->next;
            if(head!=nullptr){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }
            T pop = temp->data;
            delete temp;
            --nodes;
            return pop;
        }
        throw runtime_error("Lista vacía");
    }

    T& operator[](int pos){
        auto temp = retornarNode(pos);
        return temp->data;
    }

    bool is_empty(){
        return size() == 0;
    }

    int size(){
        return nodes;
    }

    void clear(){
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
        nodes = 0;
    }

    void display(){
        Node* actual = head;
        while (actual != nullptr) {
            cout << "Emisor: " << actual->data.emisor << endl;
            cout << "Receptor: " << actual->data.receptor << endl;
            cout << "Monto: " << actual->data.monto << endl;
            cout << "Dia: " << actual->data.dia << endl;
            cout << "Mes: " << actual->data.mes << endl;
            cout << "Ahnio: " << actual->data.ahnio << endl;
            cout << endl;
            actual = actual->next;
        }
    }


    //método auxiliar
    Node* retornarNode(int pos) {
        if (pos == 0) {
            return head;
        }
        if (pos == (nodes - 1)) {
            return tail;
        }
        if (pos <= size() / 2) {
            Node *temp = head;
            int i = 0;
            while (i++ < pos) {
                temp = temp->next;
            }
            return temp;
        }
        if (pos > size()/ 2) {
            Node *temp = tail;
            int i = 0;
            while (i++ < (nodes - 1) - pos) {
                temp = temp->prev;
            }
            return temp;
        }
        throw runtime_error("Error posición incorrecta");
    }
};


#endif //UNTITLED_FORWARDLIST_H
