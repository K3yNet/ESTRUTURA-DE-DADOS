#include <iostream>
using namespace std;

class noh{
    friend class fila;
    private:
        string dado;
        noh *proximo;
    public:
        noh(string valor);
};

noh::noh(string valor){
    dado = valor;
    proximo = NULL;
}

class fila{
    private:
        noh *inicio;
        noh *final;
        unsigned tamanho;
    public:
        fila();
        ~fila();
        string desenfileira();
        void enfileira(string valor);
        string returnInicio();
};

fila::fila(){
    inicio = NULL;
    final = NULL;
    tamanho = 0;
}

fila::~fila(){
    while(tamanho > 0){
       noh *temp = inicio;
        inicio = inicio->proximo;
        delete temp;
        tamanho--;
        if(tamanho == 0) final = NULL;
    }
}

void fila::enfileira(string valor){
    noh *novo = new noh(valor);
    if(tamanho == 0) inicio = novo;
    else final->proximo = novo;
    final = novo;
    tamanho++;
}

string fila::desenfileira(){
    string numero = inicio->dado;
    noh *temp = inicio;
    inicio = inicio->proximo;
    delete temp;
    tamanho--;
    if(tamanho == 0) final = NULL;
    return numero;
}

string fila::returnInicio(){
    return inicio->dado;
}

int main(int args, char **argv){
    fila f1;
    string inicio = "1", var;
    int n;
    cin >> n;
    f1.enfileira(inicio);
    for(int i=0; i<n; i++){
        f1.enfileira(inicio + "0");
        f1.enfileira(inicio + "1");
        cout << f1.desenfileira() << " ";
        inicio = f1.returnInicio();
    }
    return 0;
}