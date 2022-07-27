#include <iostream>
#include <string>

using namespace std;

class noh{
    friend class lista;
    private:
        int chave;
        noh *proximo;
        noh *anterior;
    public:
        noh (int c){
            chave = c;
            proximo = NULL;
            anterior = NULL;
        }
};

class lista{
    private:
        noh *inicio;
        noh *fim;
        int tamanho;
    public:
        lista();
        ~lista();        
        void insereInicio(int c);
        void insereFim (int c);
        int removeRepetidos();//retorna a quantidade de nohs restantes na lista
        bool vazia();
        void imprimeLista();
        void removeInicio();
        void removeFim();
        void removePos();
};
    
lista::lista(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
        
lista::~lista(){
    noh *aux = inicio;
    noh *temp;
    while(aux != NULL){
        temp = aux;
        aux = aux->proximo;
        delete temp;
    }
    tamanho = 0;
}  

void lista::insereInicio (int c){
    
    noh* novo = new noh(c);

    if(tamanho == 0){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->proximo = inicio;
        inicio->anterior = novo;
        inicio = novo;
    }
    tamanho++;
}
        
void lista::insereFim (int c){
    
    noh* novo = new noh(c);

    if(tamanho == 0){
        inicio = novo;
        fim = novo;
    }
    else{
        novo->anterior = fim;
        fim->proximo = novo;
        fim = novo;
    }
    tamanho++;
}
        
int lista::removeRepetidos(){
    
    noh *aux = inicio;
    noh *temp;
    
    while(aux != NULL)
    {
        temp = inicio;
        while(temp != NULL)
        {
            if ((aux->chave == temp->chave) and (aux != temp))
            {
                temp->chave = -1;
            }
            temp = temp->proximo;
        }
        aux = aux->proximo;
    }
    removePos();
    return tamanho;
}
        
void lista::imprimeLista(){
    if (inicio != NULL){
        noh *auxiliar = inicio;
        while (auxiliar->proximo != NULL){
            cout<<"("<<auxiliar->chave<<") ";
            auxiliar =  auxiliar->proximo;
        }
        cout<<"("<<auxiliar->chave<<")"<<endl;
    } else {
            cout<<"VAZIA";
    }
}

void lista::removeInicio()
{
    noh *aux = inicio;
    inicio = aux->proximo;
    delete aux;
}

void lista::removeFim()
{
    noh *aux = inicio;
    noh *temp = NULL;
    while (aux->proximo != NULL)
    {
        temp = aux;
        aux = aux->proximo;
    }
    if (inicio == fim)
    {
        inicio = NULL;
    }
    else
    {
        temp->proximo = NULL;
    }
    delete fim;
    fim = temp;
    tamanho--;
}

void lista::removePos()
{
    noh *aux = inicio;
    noh *temp = NULL;
    while ((aux != NULL))
    {
        temp = aux;
        aux = aux->proximo;
        if (aux !=NULL and aux->chave == -1)
        {
            if (aux == fim)
            {
               removeFim();
               aux = inicio;
            }
            else
            {
                temp->proximo = aux->proximo;
                aux->proximo->anterior = temp;
                tamanho--;
                delete aux;
                aux = temp;
            }
        }
    }
}
    
int main(){
    
    lista listaD;
    
    int chave;
    string dado;
    
    cin>>chave;
    
    while (chave != -1){
        listaD.insereFim(chave);        
        cin>>chave;  
    }
    cout<<listaD.removeRepetidos()<<endl;
    listaD.imprimeLista();
    
    
    return 0;
}