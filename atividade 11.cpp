#include <iostream>   
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

typedef unsigned Code;
typedef int Hrr;

class Heap 
{
    Hrr *harr;
    Code *code;
    int heap_size;
    int capacity;
    public:
        Heap(int cap);
        ~Heap();
        bool Inserir(Code codigo, Hrr prioridade);
        bool Retirar(Code* ptCodigo, Hrr* ptPrioridade);
        bool Vazia();
    private:
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        inline int Direito(int i);
        inline int Esquerdo(int i);
        inline int Pai(int i);
};

Heap::Heap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new Hrr[cap];
    code = new Code[cap];

    for(unsigned int i = 0; i < capacity; i++)
    {
		harr[i] = 0;
		code[i] = 0;
	}
}

Heap::~Heap()
{
    delete[] harr;
    delete[] code;
}

void Heap::ArrumarDescendo(int i)
{
    int Esq = Esquerdo(i);
	int Dir = Direito(i);
	
	int maior = i;
	
	if((Esq <= heap_size - 1) and (harr[Esq] > harr[i]))
		maior = Esq;
		
	if((Dir <= heap_size - 1) and (harr[Dir] > harr[maior]))
		maior = Dir;
		
	if(maior != i)
    {
		
		swap(harr[i], harr[maior]);
		swap(code[i], code[maior]);
		
		ArrumarDescendo(maior);
	}
}

void Heap::ArrumarSubindo(int i)
{
    int p = Pai(i);
	
	if((p >= 0) and (harr[i] > harr[p]))
    {
		
		swap(harr[i], harr[p]);
		swap(code[i], code[p]);
		
		ArrumarSubindo(p);
    }
}

int Heap::Pai(int i)
{
    return (i - 1)/2;
}

int Heap::Esquerdo(int i)
{
    return (i * 2) + 1;
}

int Heap::Direito(int i)
{
    return (i * 2) + 2;
}

bool Heap::Retirar(Code* ptCodigo, Hrr* ptPrioridade)
{
    if(Vazia()) 
		return false;
		
	else{
		
		*ptPrioridade = harr[0];
		*ptCodigo = code[0];
		
		swap(harr[0], harr[heap_size - 1]);
		swap(code[0], code[heap_size - 1]);
		
		heap_size--;
		ArrumarDescendo(0);
		
		return true;
	}
}


bool Heap::Vazia()
{
    return (heap_size == 0);
}

bool Heap::Inserir(Code codigo, Hrr prioridade)
{
    if(unsigned(heap_size) == capacity)
		return false;
	else
    {
		code[heap_size] = codigo;
		harr[heap_size] = prioridade;
		ArrumarSubindo(heap_size);
		heap_size++;
		
		return true;
    }
}

int main()
{
    unsigned capacidade;
    cin >> capacidade;
    Heap heap(capacidade);
    char comando;
    Code codigo;
    Hrr prioridade;
    do {
        cin >> comando;
        switch (comando) {
            case 'i': // inserir um processo no heap
                cin >> codigo >> prioridade;
                heap.Inserir(codigo, prioridade);
                break;
            case 'o': // obter um processo do heap
                if (heap.Retirar(&codigo, &prioridade))
                    cout << codigo << ' ' << prioridade << endl;
                else
                    cout << "Nao encontrado" << endl;
                break;
            case 's': //sair
                break;
        }
    } while (comando != 's');
    return 0;
}