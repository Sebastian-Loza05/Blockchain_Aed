#ifndef UNTITLED_BLOCK_H
#define UNTITLED_BLOCK_H
#include <iostream>
#include "tst_Registro.h"
#include "C_array.h"
// #include "C:\Users\HP\Desktop\sha256\sha256.h"
#include "sha256/sha256.h"

SHA256 sha256;

using namespace std;

class Block {
private:
    int nro = 0;
    int nonce = 0;
    string anterior;
    string hash;
    string pow;
    CircularArray<tst_Registro> array;
    string base;
    bool valido = false;


public:
    // Testeo: borrar al final
    Block() {
        nro = 1;
        pow = "00";
        CircularArray<tst_Registro> tmp_array(5);
        array = tmp_array;
    }

    Block(CircularArray<tst_Registro> array,  string pow): array(array), pow(pow) {
        nro = 1;
        pow = "00";
        anterior = "0000000000000000000000000000000000000000000000000000000000000000";
    }

    Block(int num, string anterior, CircularArray<tst_Registro> array, string pow): nro(num), anterior(anterior), array(array), pow(pow){}

    const string &getPow() const {
        return pow;
    }

    int getNonce() const {
        return nonce;
    }

    int getNro() const {
        return nro;
    }

    const string &getAnterior() const {
        return anterior;
    }

    bool getValido(){
        return valido;
    }

    CircularArray<tst_Registro> &getArray() {
        return array;
    }

    void setHash(const string &hash) {
        base = get_string();
        Block::hash = hash;
    }

    const string &getHash() const {
        return hash;
    }

    void addNonce() {
        ++nonce;
    }

    void setAnterior(const string &anterior) {
        Block::anterior = anterior;
    }

    void verificar(){
        cout << "Verificando" << endl;
        if(hash.substr(0, pow.length()) != pow){
            valido = false;
            //hash = sha256(get_string());
        }
        valido = true;
    }

    void setValido(bool valido) {
        Block::valido = valido;
    }

    void minar(){
        while(hash.substr(0, pow.length()) != pow){
            addNonce();
            hash = sha256(get_string());
        }
        valido = true;
        base = get_string();
        // cout<<"hash: "<<hash<<endl;
    }

    void mostrar(){
        cout<<"#: "<<nro<<endl;
        cout<<endl;
        cout<<"Nonce: "<<nonce<<endl;
        cout<<endl;
        for(auto i = 0; i < array.size(); i++){
            cout<<"{";
            cout<< array[i].emisor + ", ";
            cout<< array[i].receptor + ", ";
            cout<< to_string(array[i].monto) + ", ";
            cout<< to_string(array[i].dia) + "/";
            cout<< to_string(array[i].mes) + "/";
            cout<< to_string(array[i].ahnio);
            cout<< "}, "<<endl;
        }
        cout<<endl;
        cout<< "Anterior: "<< anterior <<endl;
        cout<<endl;
        cout<<"Hash: "<< hash<<endl;
        cout << endl;
        cout << "Valido: " << boolalpha << valido << endl;
    }

    string get_string(){
        string res;
        string temp;
        temp += to_string(nro) + ", ";
        temp += to_string(nonce) + ", ";
        temp += anterior + ", ";
        for(auto i = 0; i < array.size(); i++){
            temp += "{";
            temp += array[i].emisor + ", ";
            temp += array[i].receptor + ", ";
            temp += to_string(array[i].monto) + ", ";
            temp += to_string(array[i].dia) + ", ";
            temp += to_string(array[i].mes) + ", ";
            temp += to_string(array[i].ahnio) + ", ";
            temp += "}, ";
            res += temp;
            temp = "";
        }
        return res;
    }

};



#endif //UNTITLED_BLOCK_H
