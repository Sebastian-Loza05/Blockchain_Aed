#ifndef UNTITLED_BLOCKCHAIN_H
#define UNTITLED_BLOCKCHAIN_H
#include "Block.h"
#include "ForwardList.h"

SHA256 sha256;

class Blockchain {
private:
    int last_num = 0;
    DoubleList<Block> blockchain;
    string pow = "00";

public:
    void add_block(CircularArray<tst_Registro> array){
        ++last_num;
        Block nuevo;
        if(blockchain.is_empty()){
            nuevo = Block(array);
        } else{
            nuevo = Block(last_num, blockchain.back().getHash(), array);
        }
        sha256(nuevo.get_string());
        cout << nuevo.getNonce() << endl;
        cout << sha256.getHash() << endl;
        //cout << tst.get_string() << endl;

        while (nuevo.getHash().substr(0, pow.size()) != pow) {
            nuevo.addNonce();
            nuevo.setHash(sha256(nuevo.get_string()));
            cout << nuevo.getNonce() << endl;
            cout << nuevo.getHash() << endl;
        }
    }

    void insert_data(DoubleList<tst_Registro> list){
        CircularArray<tst_Registro> array(5);
        while (!list.is_empty()){
            if(array.is_full()){
                add_block(array);
                array.clear();
                cout << "full" << endl;
                array.push_back(list.pop_front());
            } else {
                array.push_back(list.pop_front());
            }
        }
        if(!array.is_empty()){
            add_block(array);
        }
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
};


#endif //UNTITLED_BLOCKCHAIN_H
