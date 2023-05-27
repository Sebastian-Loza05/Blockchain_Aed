#include <iostream>
// #include "Block.h"
#include "Blockchain.h"
#include "tst_Registro.h"
#include "hash_maps.h"
#include "heap_index.h"

using namespace std;

//Test para probar la estructura de hash maps
void test_1(){
  ChainHash<string, int>* hash_nombres = new ChainHash<string, int>();
  hash_nombres->insert("heider", 2);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("juan", 3);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("diana", 2);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("heider", 4);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("diana", 1);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("juan", 4);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("pedro", 5);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("heider", 3);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("diana", 5);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("marcos", 1);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("sebas", 3);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("pedro", 4);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("alonso", 3);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("luis", 7);
  hash_nombres->display();
  cout<<endl;
  hash_nombres->insert("mateo", 5);
  hash_nombres->display();
  cout<<endl;
}

//test de el indexado con hash_map en la blockchain
void test_2(){
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

  emisor = "Pedro";
  receptor = "Juan";
  monto = 730.50;
  dia = 14;
  mes = 8;
  ahnio = 2021;
  list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

  chain->insert_data(list);
  chain->display_hash_map();
  chain->search_emisor("Pedro");
}

void test_3(){
  Heap<string, float> heap_index = Heap<string, float>();
  heap_index.push(100.50, "heider");
  heap_index.push(90.60, "pedro");
  heap_index.push(30.23, "juan");
  heap_index.push(50.50, "pablo");
  heap_index.push(160.50, "diana");
  heap_index.push(200.50, "sebas");
  heap_index.push(100.50, "juan");
  heap_index.push(90.50, "leo");
  heap_index.push(100.50, "pablo");
  heap_index.push(200.50, "marcos");
  heap_index.push(45.50, "mateo");
  heap_index.push(18.50, "sebas");
  heap_index.push(200.50, "heider");
  heap_index.print();
}

void test_4(){
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

  emisor = "Pedro";
  receptor = "Juan";
  monto = 1500;
  dia = 14;
  mes = 8;
  ahnio = 2021;
  list.push_back(tst_Registro(emisor, receptor, monto, dia, mes, ahnio));

  chain->insert_data(list);
  chain->get_maxmonto();
}

int main (int argc, char *argv[])
{
  test_4();
  return 0;
}
