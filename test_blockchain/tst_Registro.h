#ifndef UNTITLED_TST_REGISTRO_H
#define UNTITLED_TST_REGISTRO_H

using namespace std;

class tst_Registro {
private:
    string nro_cuenta;
    int dia;
    int mes;
    int ahnio;
    float deposito;
    float retiro;
    float saldo;
public:
    tst_Registro(const string &nroCuenta, int dia, int mes, int ahnio, float deposito, float retiro, float saldo)
            : nro_cuenta(nroCuenta), dia(dia), mes(mes), ahnio(ahnio), deposito(deposito), retiro(retiro), saldo(saldo) {}
};


#endif //UNTITLED_TST_REGISTRO_H
