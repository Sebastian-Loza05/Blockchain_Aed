#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ForwardList {
private:
  struct Node {
    T data;
    Node* next;

    Node(){
      next = nullptr;
    }

    Node(T value){
      data = value;
      next = nullptr;
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
  int nodes;

public:
  ForwardList(){
    head = nullptr;
    nodes = 0;
  }
  ~ForwardList()
  {
    head->killSelf();
  }

  T front(){
    if(head == nullptr) throw std::out_of_range("No tiene elementos");
    else{
      return head->data;
    }
  }

  T back(){
    if (head == nullptr) throw std::out_of_range("No tiene elementos");
    else{
        Node* temp = head;
        while(temp->next != nullptr){
          temp = temp->next;
        }
        return temp->data;
      }
  }

  void push_front(const T &data){
    Node* new_node = new Node(data);
    if(size() == 0){
      head = new_node;
    }
    else{
      new_node->next = head;
      head = new_node;
    }
    nodes++;
  }

  void push_back(const T &data){
    Node *new_node = new Node;
    new_node->data = data;
    Node *temp = head;
    if (size() == 0)
    {
      head = new_node;
      nodes++;
    }
    else{
      while(temp->next != nullptr)
        {
          temp = temp->next;
        }
      temp->next = new_node;
      nodes++;
    }
  }

  T pop_front(){
    if (head == nullptr) throw std::out_of_range("Lista vacía");
    else{
        Node *temp = head;
        T data = temp->data;
        head=head->next;
        temp->next=nullptr;
        nodes--;
        return data;
      }
  }


  T pop_back(){
    if (head == nullptr) throw std::out_of_range("Lista vacía");
    else{
        Node *temp = head;
        while (temp->next->next != nullptr)
          {
            temp = temp->next;
          }
        T data = temp->next->data;
        temp->next=nullptr;
        nodes--;
        return data;
      }
  }

  void insert(const T &data, int pos){
    Node *new_node = new Node(data);
    Node *temp = head;
    if (head == nullptr || nodes-1<pos) throw std::out_of_range("Index out of range");
    else if (pos == 0){
      push_front(data);
    }
    else{
      for (int i = 0; i < pos; i++)
      {
        temp = temp->next;
      }
      new_node->next = temp->next;
      temp->next = new_node;
      nodes++;
    }
  }

  bool remove(int pos){
    Node *temp = head;
    if (head == nullptr || nodes - 1 < pos) throw std::out_of_range("Index out of range");
    else if (pos == 0)
    {
      pop_front();
      return true;
    }
    else
    {
      for (int i = 0; i < pos; i++)
      {
        temp = temp->next;
      }
      temp->next = temp->next->next;
      nodes--;
      return true;
    }
  }

  T& operator[](int pos){
    Node *temp = head;
    for(int i=0;i<pos;i++){
      temp = temp->next;
    }
    return temp->data;
  }

  bool is_empty(){
    if(head == nullptr){
      return true;
    }
    else{
      return false;
    }
  }

  int size(){
    return nodes;
  }

  void clear(){
    head->killSelf();
  }

  void mostrar(){
    Node *temp = head;
    while(temp != nullptr){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    // cout<< endl;
  }
};

