#include <iostream>
#include "sha256.cpp"

using namespace std;

int main(){
    string str = "Hola mundo";
    SHA256 sha256;
    sha256.add(str.c_str(), str.size());
    cout << sha256.getHash() << endl;
}
