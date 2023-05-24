#include <iostream>
#include <C:\Users\HP\Desktop\sha256\sha256.h>
#include "Blockchain.h"

using namespace std;

// Comprobación de constancia de hash y cambio de nonce (completo)
void test_1(){
    SHA256 sha256;
    Blockchain tst = Blockchain();
    sha256(&tst, 64);
    cout << tst.getNonce() << endl;
    cout << sha256.getHash() << endl;

    tst.addNonce();
    sha256(&tst, 64);
    cout << tst.getNonce() << endl;
    cout << sha256.getHash() << endl;
}

// Actualización de nonce e implementación de mining con Proof of Work (completo)
void test_2(){
    SHA256 sha256;
    string pow = "146e";
    Blockchain tst = Blockchain();
    sha256(&tst, 64);
    cout << tst.getNonce() << endl;
    string t_hash = sha256.getHash();
    cout << t_hash << endl;
    cout << pow << endl;
    cout << t_hash.substr(0, pow.size()) << endl;

    while (t_hash.substr(0, pow.size()) != pow) {
        tst.addNonce();
        t_hash = sha256(&tst, 64);
        cout << tst.getNonce() << endl;
        cout << t_hash << endl;
    }
}

// Lectura y uso de variables de clase (completo)
void test_3(){
    SHA256 sha256;
    Blockchain tst = Blockchain();
    sha256(&tst, 64);
    cout << tst.getNonce() << endl;
    tst.setHash(sha256.getHash());
    cout << tst.getPow() << endl;
    cout << tst.getHash().substr(0, tst.getPow().size()) << endl;

    while (tst.getHash().substr(0, tst.getPow().size()) != tst.getPow()) {
        tst.addNonce();
        tst.setHash(sha256(&tst, 64));
        cout << tst.getNonce() << endl;
        cout << tst.getHash() << endl;
    }
}

// Creación de bloques (pendiente)
void test_4(){
    SHA256 sha256;
    Blockchain tst = Blockchain();
    sha256(&tst, 64);
    cout << tst.getNonce() << endl;
    tst.setHash(sha256.getHash());
    cout << tst.getPow() << endl;
    cout << tst.getHash().substr(0, tst.getPow().size()) << endl;

    while (tst.getHash().substr(0, tst.getPow().size()) != tst.getPow()) {
        tst.addNonce();
        tst.setHash(sha256(&tst, 64));
        cout << tst.getNonce() << endl;
        cout << tst.getHash() << endl;
    }
}

int main() {
    test_1();

    return 0;
}
