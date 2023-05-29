#ifndef UNTITLED_TST_REGISTRO_H
#define UNTITLED_TST_REGISTRO_H

using namespace std;

class tst_Registro {
public:
    string emisor;
    string receptor;
    float monto;
    short dia;
    short mes;
    short ahnio;
public:
    tst_Registro(const string &emisor, const string &receptor, float monto, short dia, short mes, short ahnio) : emisor(
            emisor), receptor(receptor), monto(monto), dia(dia), mes(mes), ahnio(ahnio) {}

    tst_Registro() : monto(0), dia(0), mes(0), ahnio(0) {}
    string get_emisor(){return emisor;}
    string get_receptor(){return receptor;}
    float get_monto(){return monto;}

};

ostream& operator << (ostream& os, const tst_Registro& registro){
    os << "(" << registro.emisor << ", " << registro.receptor << ", " << registro.monto << ", " << registro.dia << ", " << registro.mes << ", " << registro.ahnio << "), ";
    cout << endl;
    return os;
}


#endif //UNTITLED_TST_REGISTRO_H
