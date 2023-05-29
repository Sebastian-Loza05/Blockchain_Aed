#ifndef UNTITLED_BLOCK_H
#define UNTITLED_BLOCK_H
#include <iostream>
#include "tst_Registro.h"
#include "C_array.h"
// #include "C:\Users\HP\Desktop\sha256\sha256.h"
#include "../sha256/sha256.h"

SHA256 sha256;

using namespace std;

class Block {
private:
    int nro = 0;
    int nonce = 0;
    string anterior;
    string hash;
    string pow = "00";
    CircularArray<tst_Registro> array;
    string base;
    bool valido = false;


public:
    // Testeo: borrar al final
    Block() {
        nro = 1;
        CircularArray<tst_Registro> tmp_array(5);
        array = tmp_array;
    }

    Block(CircularArray<tst_Registro> array): array(array) {
        nro = 1;
        anterior = "0000000000000000000000000000000000000000000000000000000000000000";
    }

    Block(int num, string anterior, CircularArray<tst_Registro> array): nro(num), anterior(anterior), array(array){

    }

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

    const CircularArray<tst_Registro> &getArray() const {
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

    void verificar(){
      if(get_string() != base){
        valido = false;
        hash = sha256(get_string());
      }
    }

    void minar(){
      while(hash.substr(0, pow.length()) != pow){
        addNonce();
        hash = sha256(get_string());
      }
      valido = true;
      base = get_string();
      cout<<"hash: "<<hash<<endl;
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
