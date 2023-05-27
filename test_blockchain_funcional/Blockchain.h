#ifndef UNTITLED_BLOCKCHAIN_H
#define UNTITLED_BLOCKCHAIN_H
#include "Block.h"
#include "ForwardList.h"
#include "hash_maps.h"
#include "heap_index.h"


class Blockchain {
private:
    int last_num = 0;
    DoubleList<Block> blockchain;
    string pow = "00";
    ChainHash<string, int> emisores;
    Heap<string, float> montos_e;

public:
    Blockchain(){}
    Blockchain(string pow):pow(pow){}
    void add_block(CircularArray<tst_Registro> array){
        ++last_num;
        Block nuevo;
        if(blockchain.is_empty()){
            nuevo = Block(array);
        } else{
            nuevo = Block(last_num, blockchain.back().getHash(), array, pow);
        }
        nuevo.setHash(sha256(nuevo.get_string()));
        nuevo.minar();
        blockchain.push_back(nuevo);
    }

    void insert_data(DoubleList<tst_Registro> list){
        CircularArray<tst_Registro> array(5);
        string nombre = "";
        float monto = 0.0;
        int bloque = 0;
        while (!list.is_empty()){
            nombre = list.front().get_emisor();
            monto = list.front().get_monto();
            if(array.is_full()){
                add_block(array);
                array.clear();
                cout << "full" << endl;
                array.push_back(list.pop_front());
            } else {
                array.push_back(list.pop_front());
            }
            bloque = last_num + 1;
            emisores.insert(nombre, bloque);
            montos_e.push(monto,nombre);
        }
        if(!array.is_empty()){
            add_block(array);
        }
    }

    void ingresar_registro(tst_Registro registro){
      Block actual = blockchain.back();
      string nombre = "";
      float monto = 0.0;
      int bloque = 0;
      nombre = registro.get_emisor();
      monto = registro.get_monto();
      if(actual.getArray().is_full()){
        CircularArray<tst_Registro> array(5);
        array.push_back(registro);
        add_block(array);
      }
      else{
        actual.getArray().push_back(registro);
      }
      bloque = last_num;
      emisores.insert(nombre, bloque);
      montos_e.push(monto,nombre);
    }

    Block getBlock(int index) {
        if (index >= 0 && index < blockchain.size()) {
            return blockchain[index];
        } else {
            cout << "non" << endl;
        }
    }

    int getBlockCount() {
        return blockchain.size();
    }

    void mostrar(){
      for (int i = 0; i < last_num+1; i++) {
        blockchain[i].mostrar();
        cout<<endl;
      }
    }

    void display_hash_map(){
      emisores.display();
    }

    void search_emisor(string emisor){
      cout<<emisor<<" se ha realizado transacciones en los bloques : ";
      emisores.find(emisor)->mostrar();
      cout<<endl;
    }

    void get_maxmonto(){
        cout<<"Las personas que han realizado transacciones con el monto más alto son: "<<endl;
        montos_e.top()->mostrar();
        cout<<endl;
    }
};


#endif //UNTITLED_BLOCKCHAIN_H
