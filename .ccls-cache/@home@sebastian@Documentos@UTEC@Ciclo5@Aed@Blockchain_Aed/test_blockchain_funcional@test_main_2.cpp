#include <iostream>
#include <C:\Users\HP\Desktop\sha256\sha256.h>
#include "Block.h"
#include "Blockchain.h"
#include "tst_Registro.h"
#include "ForwardList.h"

using namespace std;

// Comprobación de constancia de hash y cambio de nonce (completo)
void test_1(){
    SHA256 sha256;
    Block tst = Block();
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
    Block tst = Block();
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
    Block tst = Block();
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

// Creación de registros (completo)
void test_4() {
    Block tst = Block();
    DoubleList<tst_Registro> list{};

    string emisor = "Fabio";
    string receptor = "Javier";
    float monto = 424;
    short dia = 1;
    short mes = 10;
    short ahnio = 2010;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "yo";
    receptor = "yoh";
    monto = 323.50;
    dia = 4;
    mes = 11;
    ahnio = 2012;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Luisa";
    receptor = "Sofia";
    monto = 1000;
    dia = 5;
    mes = 3;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Pedro";
    receptor = "Maria";
    monto = 750.50;
    dia = 12;
    mes = 7;
    ahnio = 2021;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Ana";
    receptor = "David";
    monto = 250.75;
    dia = 20;
    mes = 11;
    ahnio = 2023;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Carolina";
    receptor = "Roberto";
    monto = 1500;
    dia = 8;
    mes = 2;
    ahnio = 2024;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Miguel";
    receptor = "Laura";
    monto = 900.25;
    dia = 17;
    mes = 9;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));
    list.display();

    CircularArray<tst_Registro> array(5);
    while (!list.is_empty()){
        if(array.is_full()){
            cout << "full" << endl;
            list.pop_front();
        } else {
            array.push_back(list.pop_front());
        }
    }

    array.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));
    array.display();
}

// Almacenamiento de registro (completo)
void test_5() {
    DoubleList<tst_Registro> list{};

    string emisor;
    string receptor;
    float monto;
    short dia;
    short mes;
    short ahnio;

    emisor = "yo";
    receptor = "yoh";
    monto = 323.50;
    dia = 4;
    mes = 11;
    ahnio = 2012;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Luisa";
    receptor = "Sofia";
    monto = 1000;
    dia = 5;
    mes = 3;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Pedro";
    receptor = "Maria";
    monto = 750.50;
    dia = 12;
    mes = 7;
    ahnio = 2021;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Ana";
    receptor = "David";
    monto = 250.75;
    dia = 20;
    mes = 11;
    ahnio = 2023;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Carolina";
    receptor = "Roberto";
    monto = 1500;
    dia = 8;
    mes = 2;
    ahnio = 2024;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Miguel";
    receptor = "Laura";
    monto = 900.25;
    dia = 17;
    mes = 9;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));
    //list.display();

    CircularArray<tst_Registro> array(5);
    while (!list.is_empty()){
        if(array.is_full()){
            cout << "full" << endl;
            list.pop_front();
        } else {
            array.push_back(list.pop_front());
        }
    }

    //array.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));
    array.display();

    SHA256 sha256;

    Block tst = Block(array);

    sha256(tst.get_string());
    cout << tst.getNonce() << endl;
    cout << sha256.getHash() << endl;
    //cout << tst.get_string() << endl;

    tst.addNonce();
    sha256(tst.get_string());
    cout << tst.getNonce() << endl;
    cout << sha256.getHash() << endl;
    //cout << tst.get_string() << endl;
}

// Implementación de estructura (pendiente)
void test_6(){
    auto chain = new Blockchain();
    DoubleList<tst_Registro> list{};

    string emisor;
    string receptor;
    float monto;
    short dia;
    short mes;
    short ahnio;

    emisor = "yo";
    receptor = "yoh";
    monto = 323.50;
    dia = 4;
    mes = 11;
    ahnio = 2012;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Luisa";
    receptor = "Sofia";
    monto = 1000;
    dia = 5;
    mes = 3;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Pedro";
    receptor = "Maria";
    monto = 750.50;
    dia = 12;
    mes = 7;
    ahnio = 2021;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Ana";
    receptor = "David";
    monto = 250.75;
    dia = 20;
    mes = 11;
    ahnio = 2023;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Carolina";
    receptor = "Roberto";
    monto = 1500;
    dia = 8;
    mes = 2;
    ahnio = 2024;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    emisor = "Miguel";
    receptor = "Laura";
    monto = 900.25;
    dia = 17;
    mes = 9;
    ahnio = 2022;
    list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

    chain->insert_data(list);
}

int main() {
    test_6();

    return 0;
}
