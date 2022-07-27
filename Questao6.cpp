#include <iostream>
using namespace std;

class noh{
    friend class lista;
    private:
        int chave;
        noh *proximo;
    public:
        noh (int c){
            chave = c;
            proximo = NULL;
        }
};

class lista {
    private:
        noh* inicio;
        noh* fim;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(int dado);
        void insere(int dado, int pos);
        void remove(int posicao);
        void removeInicio();
        void removeFim();
        int procura(int valor);
        void imprime();
        inline bool vazia();
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

// método básico que *percorre* a lista, imprimindo seus elementos
void lista::imprime() {
    noh* aux = inicio;
    while (aux != NULL) {
        cout << aux->chave << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

// insere por padrão no final da lista
void lista::insere (int c){
    
    noh* novo = new noh(c);

    if(tamanho == 0)
    {
        inicio = novo;
        fim = novo;
    }
    else{
        fim->proximo = novo;
        fim = novo;
    }
    tamanho++;
}

// insere um dado em uma determinada posição da lista
void lista::insere(int c, int posicao){
    
    noh* novo = new noh(c);
    
    if (tamanho == 0)
    {
        inicio = novo;
        fim = novo;
    }
    else
    {
        noh *aux = inicio;
        for (int i = 0; i < tamanho - 1; i++)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    tamanho++;
}

// remove o item da posição passada por parâmetro
// Atenção - o código deve tratar de posição inválidas
void lista::remove(int posicao)
{
    noh *aux = inicio;
    noh *temp = NULL;
    
    for (int i = 0; i < posicao; i++)
    {
        temp = aux;
        aux = aux->proximo;
    }
    if (aux == inicio)
    {
        removeInicio();
    }
    else if (aux == fim)
    {
        removeFim();
    }
    else
    {
        temp->proximo = aux->proximo;
        tamanho--;
        delete aux;
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

// procura por um elemento e retorna a posição ou -1 se não encontrado
int lista::procura(int valor)
{
    int pos = 0;
    if (inicio != NULL)
    {
        noh *auxiliar = inicio;
        bool flag = true;
        while ((auxiliar->proximo != NULL) and (auxiliar->chave != valor) and (flag == true))
        {
            auxiliar =  auxiliar->proximo;
            pos++;
            flag = false;
        }
    } 
    else 
    {
        cout<<"VAZIA";
    }
    return pos;
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    if (inicio == fim)
    {
        return true;
    }
    else
        return false;
}

int main() {
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}