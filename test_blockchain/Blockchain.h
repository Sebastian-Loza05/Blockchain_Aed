#ifndef UNTITLED_BLOCKCHAIN_H
#define UNTITLED_BLOCKCHAIN_H
#include <iostream>
#include "tst_Registro.h"
#include "C_array.h"
#include "C:\Users\HP\Desktop\sha256\sha256.h"

using namespace std;

class Blockchain {
private:
    int nro = 0;
    int nonce = 0;
    //CircularArray<tst_Registro> array();
    string anterior;
    string hash;
    string pow = "0000";
    Blockchain(int nro): nro(nro) {

    }
public:
    Blockchain() {
        nro = 1;
    }

    const string &getPow() const {
        return pow;
    }

    //void add_register(tst_Registro reg){
        //if(!array().is_full()){
            //array().push_back(reg);
        //} else {
            //add_block(reg);
        //}
    //}

    int getNonce() const {
        return nonce;
    }

    void setHash(const string &hash) {
        Blockchain::hash = hash;
    }

    const string &getHash() const {
        return hash;
    }

    void addNonce() {
        ++nonce;
    }

private:
    //void add_block(tst_Registro reg){
    //    auto nuevo = Blockchain(++nro);
    //    nuevo.anterior = hash;
    //    nuevo.array().push_back(reg);
    //}
};


#endif //UNTITLED_BLOCKCHAIN_H
