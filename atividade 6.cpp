#include <iostream>

using namespace std;

class filaCircular
{
	private:
		int mInicio;
		int mFim;
		int *mDados;
		unsigned int mCapacidade;
		unsigned int nPosicoes;
		
	public:
		filaCircular(int capacidade);
		~filaCircular();
		void enqueue(int dado);
		int dequeue();
		void imprimir();
};

filaCircular::filaCircular(int capacidade)
{
	mInicio = -1;
	mFim = -1;
	mCapacidade = capacidade;
	nPosicoes = 0;
	mDados = new int[mCapacidade];
}

filaCircular::~filaCircular()
{
	delete[] mDados;
}

void filaCircular::enqueue(int dado)
{
    if (mInicio == -1)
    {
        mInicio++;
    }
    mFim = (mFim + 1) % mCapacidade;
    mDados[mFim] = dado;
    nPosicoes++;
}

int filaCircular::dequeue()
{
    int aux;
    aux = mDados[mInicio];
    if (mInicio == mFim) 
    {
        mFim = -1;
        mInicio = -1;
    } else
    {
        mInicio = (mInicio + 1) % mCapacidade;
        nPosicoes--;
        return(aux);
    }
}

void filaCircular::imprimir()
{
	cout << "tamanho=" << nPosicoes
	<< " capacidade=" << mCapacidade
	<< " inicio=" << mInicio
	<< " fim=" << mFim << endl;
	
	for(unsigned int i = 0; i < nPosicoes; i++)
		cout << mDados[i] << " ";
		
	cout << endl;
}

int main()
{
	int quant, num;
	char opcao;
	
	cin >> quant;
	
	filaCircular f1(quant);
	
	do
	{
		cin >> opcao;
		
		switch(opcao)
		{
			case 'e':
				cin >> num;
				f1.enqueue(num);
				break;
				
			case 'd':
				cout << f1.dequeue() << endl;
				break;
				
			case 'i':
				f1.imprimir();
				break;
		}
		
	}while(opcao != 't');
	
	return 0;
}
