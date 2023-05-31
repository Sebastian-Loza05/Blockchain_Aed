#include <iostream>
#include "Blockchain.h"
// #include "tst_registro.h"

using namespace std;

tst_Registro ingresar_registro(){
    string nombre;
    string receptor;
    float monto;
    short dia;
    short mes;
    short anhio;
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Nombre del receptor: ";
    cin>>receptor;
    do {
        cout<<"Monto a transferir: ";
        cin>>monto;
    }while (monto < 1);

    do {
        cout<<"Ingrese el dia: ";
        cin>>dia;
    }while (dia < 1 || dia>30);

    do {
        cout<<"Ingrese el mes: ";
        cin>>mes;
    }while (mes < 1 || mes>12);

    do {
        cout<<"Ingrese el anhio: ";
        cin>>anhio;
    }while (anhio>2023);
    return tst_Registro(nombre, receptor, monto, dia, mes, anhio);
}

void modificar_registro(Blockchain* blockchain){
    auto lista = blockchain->getBlockchain();
    int num_bloque = 1;
    if(!lista.is_empty()){
        do{
            cout<<"Ingrese el numero de bloque que quiere modificar [1"<<" - "<<lista.size()<<"]: ";
            cin>>num_bloque;
            cout<<endl;
        }while(num_bloque < 1 ||  num_bloque > lista.size());
        auto bloque = blockchain->getBlock(num_bloque);
        cout<<"Este es el bloque que has escogido: "<<endl;
        cout<<endl;
        bloque.mostrar();

        auto array = bloque.getArray();
        int num_array;
        do{
            cout<<"Que registro quieres modificar? [1"<<" - "<<array.size()<<"]: ";
            cin>>num_array;
            cout<<endl;
        }while(num_array < 1 ||  num_array > array.size());

        cout<<"Ingrese los datos del registro modificados: "<<endl;
        auto tst = ingresar_registro();
        array[num_array-1] = tst;
        blockchain->modificar(num_bloque, num_array);
    }

}

void buscar_emisor(Blockchain* blockchain){
    string nombre;
    do{
        cout<<"Ingrese el nombre del emisor que desea buscar: ";
        cin>>nombre;
        cout<<endl;
    }while(nombre == " ");
    blockchain->search_emisor(nombre);

}

void ejecutar(int opcion, Blockchain* blockchain){
    switch (opcion) {
        case 1:
            blockchain->mostrar();
            break;
        case 2: {
            auto tst = ingresar_registro();
            blockchain->ingresar_registro(tst);
            break;
        }
        case 3:
            modificar_registro(blockchain);
            break;
        case 4:
            buscar_emisor(blockchain);
            break;
        case 5:
            blockchain->get_maxmonto();
            break;
        default:
            break;
    }
}

void menu(int &opcion, Blockchain* blockchain){
    do{
        cout<<endl;
        cout<<endl;
        cout<<"Escoja una opcion: "<<endl;
        cout<<"[1] Mostrar Blockchain."<<endl;
        cout<<"[2] Insertar Registro."<<endl;
        cout<<"[3] Modificar Blockchain."<<endl;
        cout<<"[4] Buscar emisor."<<endl;
        cout<<"[5] Buscar por monto maximo."<<endl;
        cout<<"[6] Salir."<<endl;
        cin>>opcion;
        cout<<endl;
    }while(opcion < 1 || opcion > 6);
    ejecutar(opcion, blockchain);
}

int main (int argc, char *argv[])
{
    Blockchain* bitcoin = new Blockchain("00");
    cout<<"---------------------------------------------"<<endl;
    cout<<"Bienvenido a Blockchain"<<endl;
    int opcion = 0;
    while (opcion != 6){
        menu(opcion, bitcoin);
    }
    return 0;
}
