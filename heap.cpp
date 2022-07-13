#include <iostream>   
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

typedef int Harr;

class Heap 
{
    Harr *harr;
    int heap_size;
    int capacity;
    public:
        Heap(int cap);
        ~Heap();
        bool Inserir(Harr num);
        bool Retirar(Harr* num);
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
    harr = new Harr[cap];

    for(unsigned int i = 0; i < capacity; i++)
    {
		harr[i] = 0;
	}
}

Heap::~Heap()
{
    delete[] harr;
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

		ArrumarDescendo(maior);
	}
}

void Heap::ArrumarSubindo(int i)
{
    int p = Pai(i);
	
	if((p >= 0) and (harr[i] > harr[p]))
    {	
		swap(harr[i], harr[p]);
		
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

bool Heap::Retirar(Harr* num)
{
    if(Vazia()) 
		return false;
		
	else{
		
		*num = harr[0];
		
		swap(harr[0], harr[heap_size - 1]);
		
		heap_size--;
		ArrumarDescendo(0);
		
		return true;
	}
}


bool Heap::Vazia()
{
    return (heap_size == 0);
}

bool Heap::Inserir(Harr num)
{
    if(unsigned(heap_size) == capacity)
		return false;
	else
    {
		harr[heap_size] = num;
		ArrumarSubindo(heap_size);
		heap_size++;
		
		return true;
    }
}

int main()
{
    unsigned capacity;
    cin >> capacity;
    Heap heap(capacity);
    
    char comando;
    Harr Harr;
    do
    {
        cin >> comando;
        switch (comando)
        {
            case 'i': // inserir um processo no heap
                cin >> Harr;
                heap.Inserir(Harr);
                break;
            case 'o': // obter um processo do heap
                if (heap.Retirar(&Harr))
                    cout << Harr << endl;
                else
                    cout << "Nao encontrado" << endl;
                break;
            case 's': //sair
                break;
        }
    } while (comando != 's');
    return 0;
}