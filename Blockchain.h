#ifndef PROYECTO_BLOCKCHAIN_H
#define PROYECTO_BLOCKCHAIN_H
#include "Block.h"
#include "C_array.h"
#include "Double_list.h"
#include "hash_maps.h"
#include "heap_index.h"


class Blockchain {
private:
    int last_num = 0;
    Double_list<Block> blockchain;
    string pow;
    ChainHash<string, int> emisores;
    Heap<string, float> montos_e;

public:
    Blockchain(){
        pow = "00";
    }
    Blockchain(string pow):pow(pow){}
    void add_block(CircularArray<tst_Registro> array){
        ++last_num;
        Block nuevo;
        if(blockchain.is_empty()){
            nuevo = Block(array, pow);
        } else{
            nuevo = Block(last_num, blockchain.back().getHash(), array, pow);
        }
        nuevo.setHash(sha256(nuevo.get_string()));
        nuevo.minar();
        blockchain.push_back(nuevo);
    }

    void insert_data(Double_list<tst_Registro> list){
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
        string nombre = "";
        float monto = 0.0;
        int bloque = 0;
        nombre = registro.get_emisor();
        monto = registro.get_monto();
        if(blockchain.is_empty()){
            CircularArray<tst_Registro> array(5);
            array.push_back(registro);
            add_block(array);
        }
        else{
            if(blockchain.back().getArray().is_full()){
                CircularArray<tst_Registro> array(5);
                array.push_back(registro);
                add_block(array);
            }
            else{
                blockchain.back().getArray().push_back(registro);
                blockchain.back().setHash(blockchain.back().get_string());
                blockchain.back().minar();
            }
        }
        bloque = last_num;
        emisores.insert(nombre, bloque);
        montos_e.push(monto,nombre);
    }

    void modificar(int num_bloque, int num_reg){
        for(int i = (num_bloque-1); i < blockchain.size(); i++){
            actualizar_anterior(i);
        }
        for(int j = (num_bloque-1); j < blockchain.size(); j++){
            verificar_pow(j);
        }
        for(int index = (num_bloque-1); index < blockchain.size(); index++){
            if(index != 0) {
                blockchain[index].minar();
            }
            blockchain[index].minar();
        }
    }

    void actualizar_anterior(int index){
        if(index != 0) {
            blockchain[index].setAnterior(blockchain[index - 1].getHash());
        }
        blockchain[index].setHash(sha256(blockchain[index].get_string()));
    }

    void verificar_pow(int index){
        //blockchain[index].verificar();
        //cout << "Verificando" << endl;
        if(blockchain[index].getHash().substr(0, pow.length()) != pow){
            blockchain[index].setValido(false);
            //hash = sha256(get_string());
        }
    }


    Block& getBlock(int index) {
        index--;
        if (index >= 0 && index < blockchain.size()) {
            return blockchain[index];
        } else {
            cout << "non" << endl;
        }
    }

    int getBlockCount() {
        return blockchain.size();
    }

    Double_list<Block>& getBlockchain(){
        return blockchain;
    }

    void mostrar(){
        if(blockchain.is_empty())
            cout<<"La blockchain esta vacia"<<endl;
        else{
            for (int i = 0; i < last_num; i++) {
                blockchain[i].mostrar();
                cout<<endl;
            }
        }
    }

    void display_hash_map(){
        emisores.display();
    }

    void search_emisor(string emisor){
        try{
            cout<<emisor<<" ha realizado transacciones en los bloques : ";
            emisores.find(emisor)->mostrar();
            cout<<endl;
        }
        catch (const char* error){
            cout<<emisor<<" no ha realizado ninguna transaccion."<<endl;
        }
    }

    void get_maxmonto(){

        cout<<"Las personas que han realizado transacciones con el monto más alto son: "<<endl;
        cout<<"Monto: "<<montos_e.top().monto<<"  ";
        cout<<"Emisores: ";
        montos_e.top().keys->mostrar();
        cout<<endl;
    }
};


#endif //PROYECTO_BLOCKCHAIN_H
