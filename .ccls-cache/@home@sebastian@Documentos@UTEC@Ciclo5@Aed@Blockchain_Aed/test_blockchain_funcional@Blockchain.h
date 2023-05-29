#ifndef UNTITLED_BLOCKCHAIN_H
#define UNTITLED_BLOCKCHAIN_H
#include "Block.h"
#include "ForwardList.h"
#include "hash_maps.h"


class Blockchain {
private:
    int last_num = 0;
    DoubleList<Block> blockchain;
    string pow = "00";
    ChainHash<string, int> emisores;

public:
    void add_block(CircularArray<tst_Registro> array){
        ++last_num;
        Block nuevo;
        if(blockchain.is_empty()){
            nuevo = Block(array);
        } else{
            nuevo = Block(last_num, blockchain.back().getHash(), array);
        }
        nuevo.setHash(sha256(nuevo.get_string()));
        nuevo.minar();
        blockchain.push_back(nuevo);
    }

    void insert_data(DoubleList<tst_Registro> list){
        CircularArray<tst_Registro> array(5);
        string nombre = "";
        int bloque = 0;
        while (!list.is_empty()){
            nombre = list.front().get_emisor();
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
        }
        if(!array.is_empty()){
            add_block(array);
        }
    }
    
    void ingresar_registro(tst_Registro registro){
      Block actual = blockchain.back();
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
    
    void display_hash_map(){
      emisores.display();
    }

    void search_emisor(string emisor){
      cout<<emisor<<" se ha realizado transacciones en los bloques : ";
      emisores.find(emisor)->mostrar();
      cout<<endl;
    }
};


#endif //UNTITLED_BLOCKCHAIN_H
