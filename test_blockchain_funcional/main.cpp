#include <iostream>
#include "Blockchain.h"

using namespace std;

void ingresar_registro(Blockchain* blockchain){
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
  tst_Registro tst = tst_Registro(nombre, receptor, monto, dia, mes, anhio);
  blockchain->ingresar_registro(tst);
}

void ejecutar(int opcion, Blockchain* blockchain){
  switch (opcion) {
    case 1:
      blockchain->mostrar();
      break;
    case2:
      ingresar_registro(blockchain);
      break;
    case3:

      break;
    case4:

      break;
    case5:

      break;
    default:
      break;
  }
}

void menu(int &opcion, Blockchain* blockchain){
  do{
    cout<<"Escoja una opcion: "<<endl;
    cout<<"[1] Mostrar Blockchain."<<endl;
    cout<<"[2] Insertar Registro."<<endl;
    cout<<"[3] Modificar Blockchain."<<endl;
    cout<<"[4] Buscar emisor."<<endl;
    cout<<"[5] Buscar por monto maximo."<<endl;
    cout<<"[6] Salir."<<endl;
    cin>>opcion;
  }while(opcion < 1 || opcion > 6);
  ejecutar(opcion, blockchain);
}

int main (int argc, char *argv[])
{
  Blockchain* bitcoin = new Blockchain("000");
  cout<<"---------------------------------------------"<<endl;
  cout<<"Bienvenido a Blockchain"<<endl;
  int opcion = 0;
  while (opcion != 6){
    menu(opcion, bitcoin);
  }
  return 0;
}
