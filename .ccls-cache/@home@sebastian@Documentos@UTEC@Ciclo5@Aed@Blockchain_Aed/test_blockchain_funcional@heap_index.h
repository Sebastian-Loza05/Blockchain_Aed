#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include "forward_list.h"

using namespace std;

template<typename TK,typename TV>
struct Nodo{
  TV monto;
  ForwardList<TK>*keys = new ForwardList<TK>();

  Nodo(TV monto) : monto(monto){}
  Nodo(){}
};

template <typename TK,typename TV>
class Heap
{
public:
  enum Type
  {
    MAX_HEAP,
    MIN_HEAP
  };

private:
  Nodo<TK,TV>*elements;
  int capacity;
  int n;
  Type type;

public:
  Heap(Type type = MAX_HEAP) : type(type)
  {
    this->capacity = 10;
    elements = new Nodo<TK,TV>[this->capacity];
    this->n=0;
  }

  ~Heap()
  {
    delete[] elements;
  }

  /*void buildFromArray(T *elements, int n)
  {
    for (size_t i = 0; i < n; i++)
    {
      this->elements[i] = elements[i];
      this->n++;
    }
    for (size_t i = (n / 2) - 1; i < -1; i--)
    {
      heapify_down(i);
    }
  }*/

  int size()
  {
    return n;
  }

  bool is_empty()
  {
    if (this->n == 0)
      return true;
    return false;
  }

  void push(TV value, TK key)
  {
    if (size() == this->capacity)
    {
      Nodo<TK, TV> *newlist = new Nodo<TK, TV>[2 * capacity];
      for (int i = 0; i < n; i++)
      {
        newlist[i] = elements[i];
      }
      elements = newlist;
    }
    auto nuevo = Nodo<TK, TV>(value);
    nuevo.keys->push_front(key);
    this->elements[this->n] = nuevo;
    n++;
    heapify_up_rec(n - 1);
  }

  // T pop()
  // {
  //   T eliminado = elements[0];
  //   elements[0] = elements[n - 1];
  //   elements[n - 1] = eliminado;
  //   n--;
  //   for (size_t i = (n / 2) - 1; i < -1; i--)
  //   {
  //     heapify_down(i);
  //   }
  //   return eliminado;
  // }

  ForwardList<TV>* top()
  {
    return elements[0].keys;
  }


  // static void sortAsc(T *arr, int n)
  // {
  //   Heap<T> *heap = new Heap<T>(arr, n);
  //   int b = n;
  //   for (int i = 0; i < n; i++)
  //   {
  //     T value = heap->pop();
  //     arr[--b] = value;
  //   }
  // }
  //
  // static void sortDesc(T *arr, int n)
  // {
  //   Heap<T> *heap = new Heap<T>(arr, n, Heap<T>::MIN_HEAP);
  //   int b = n;
  //   for (int i = 0; i < n; i++)
  //   {
  //     arr[--b] = heap->pop();
  //   }
  // }

  void print()
  {
    for (size_t i = 0; i < n; i++)
    {
      cout<<elements[i].monto<<": ";
      elements[i].keys->mostrar();
      cout<<endl;
    }
    cout << endl;
  }

private:
  int Parent(int i)
  {
    return (i - 1) / 2;
  }

  int Left(int i)
  {
    return (2 * i + 1);
  }

  int Right(int i)
  {
    return (2 * i + 2);
  }

  void heapify_up(int i)
  {
    Nodo<TK, TV> padre = elements[Parent(i)];
    if (type == 0)
    {
      if (elements[i].monto > padre.monto)
      {
        elements[Parent(i)] = elements[i];
        elements[i] = padre;
      }
      else if (elements[i].monto == padre.monto){
        padre.keys->push_front(elements[i].keys->front());
        elements[i].keys = padre.keys;
      }
    }
    else
    {
      if (elements[i].monto < padre.monto)
      {
        elements[Parent(i)] = elements[i];
        elements[i] = padre;
      }
    }
  }

  void heapify_down(int i)
  {
    Nodo<TK,TV> left_n;
    Nodo<TK,TV> right_n;
    bool exist_r = false;
    bool exist_l = false;

    if (Left(i) < n)
    {
      exist_l = true;
      left_n = elements[Left(i)];
      if (Right(i) < n)
      {
        right_n = elements[Right(i)];
        exist_r = true;
      }
      if (type == 0)
      {
        heapify_down_max(i, left_n, right_n, exist_r);
      }
      /* else
       {
         heapify_down_min(i, left_n, right_n, exist_r);
       }*/
    }

    if (exist_l && elements[i].monto == left_n.monto)
    {
      heapify_down(Left(i));
    }
    else if (exist_r && elements[i].monto == right_n.monto)
    {
      heapify_down(Right(i));
    }
    else
      return;
  }

  void heapify_down_max(int i, Nodo<TK, TV> left_n, Nodo<TK, TV> right_n, bool exist_r)
  {
    if (Right(i) < n && left_n.monto > elements[i].monto && right_n.monto > elements[i].monto)
    {
      if (left_n.monto > right_n.monto)
      {
        Nodo<TK,TV>temp = elements[i];
        elements[i] = left_n;
        elements[Left(i)] = temp;
      }
      else
      {
        Nodo<TK, TV>temp = elements[i];
        elements[i] = right_n;
        elements[Right(i)] = temp;
      }
    }
    else if (left_n.monto > elements[i].monto)
    {
      Nodo<TK, TV>temp = elements[i];
      elements[i] = left_n;
      elements[Left(i)] = temp;
    }
    else if (exist_r && right_n.monto > elements[i].monto)
    {
      Nodo<TK, TV>temp = elements[i];
      elements[i] = right_n;
      elements[Right(i)] = temp;
    }
  }

  /*void heapify_down_min(int i, T left_n, T right_n, bool exist_r)
  {
    if (Right(i) < n && left_n < elements[i] && right_n < elements[i])
    {
      if (left_n < right_n)
      {
        T temp = elements[i];
        elements[i] = left_n;
        elements[Left(i)] = temp;
      }
      else
      {
        T temp = elements[i];
        elements[i] = right_n;
        elements[Right(i)] = temp;
      }
    }
    else if (left_n < elements[i])
    {
      T temp = elements[i];
      elements[i] = left_n;
      elements[Left(i)] = temp;
    }
    else if (exist_r && right_n < elements[i])
    {
      T temp = elements[i];
      elements[i] = right_n;
      elements[Right(i)] = temp;
    }
  }*/

  void heapify_up_rec(int i)
  {
    if (i == 0)
      return;
    else
    {
      Nodo<TK,TV> elem_i = elements[i];
      heapify_up(i);
      if (elements[Parent(i)].monto == elem_i.monto)
        heapify_up_rec(Parent(i));
    }
  }
};
