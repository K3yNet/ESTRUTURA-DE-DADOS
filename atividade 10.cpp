#include <iostream>
using namespace std;

class noh{
    friend class fila;
    private:
        int dado;
        noh *proximo;
    public:
        noh(int valor);
};

noh::noh(int valor){
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
        int desenfileira();
        void enfileira(int valor);
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

void fila::enfileira(int valor){
    noh *novo = new noh(valor);
    if(tamanho == 0) inicio = novo;
    else final->proximo = novo;
    final = novo;
    tamanho++;
}

int fila::desenfileira(){
    int numero = inicio->dado;
    noh *temp = inicio;
    inicio = inicio->proximo;
    delete temp;
    tamanho--;
    if(tamanho == 0) final = NULL;
    return numero;
}

int main(int args, char **argv){
    fila f1, k1;
    int n, k, valor, dado = 0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> valor;
        f1.enfileira(valor);
    }
    cin >> k;

    for(int i=0; i<k; i++){
        valor = f1.desenfileira();
        k1.enfileira(valor);
    }

    for(int i=0; i<=n-k; i++){
        for(int j=0; j<k; j++){
            valor = k1.desenfileira();
            if(valor < 0 and dado == 0){
                dado = valor;
            }
            k1.enfileira(valor);
        }
        if(dado < 0) cout << dado << " ";
        else cout << "inexistente ";
        dado = 0;
        if(i != n-k){    
            k1.desenfileira();
            valor = f1.desenfileira();
            k1.enfileira(valor);
        }
    }

    return 0;
}