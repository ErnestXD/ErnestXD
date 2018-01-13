#include "Singleton.h"
#include "iostream"
#include <fstream>
using namespace std;
const char CDfv [] ="Tekstas.txt";
const char CRfv [] ="Rezultatai.txt";

// Global static pointer used to ensure a single instance of the class.
Singleton* Singleton::m_pInstance = NULL;

/** This function is called to create an instance of the class.
Calling the constructor publicly is not allowed. The constructor
is private and is only called by this Instance function.
*/

Singleton* Singleton::Instance()
{
	if (!Singleton::m_pInstance)   // Only allow one instance of class to be generated.
		Singleton::m_pInstance = new Singleton;

	return Singleton::m_pInstance;
}

void Singleton::writeToLogFile()
{
	cout << "Hello Singleton world" << endl;
}
void Singleton::sk1()
{
	ifstream fd (CDfv);
	ofstream fr (CRfv);
	char b;
	char x = ',';
	char pab = '\n';
	char A[1000];
	int i=0, eil[10], temp = 0, index = 0, simb = 0, sk = 0, max = 0, nr = 0;
	while(!fd.eof())
	{
		fd.get (b);
		A[i] = b;
		i++;
	}
	for(int i = 0; i < 1000;i++)
	{
		if(A[i] == x)
			{
				sk++;
				temp = sk;
				simb ++;
			}
		if(A[i] == pab)
			{
				index++;
				eil[index] = simb;
				fr << index << " Eiluteje rasta "<< simb << " simboliu ',' "<< endl;
				sk = 0;
				simb = 0;
			}
	}
	for (int i = 0; i < 10; i++)
	{
		if (eil[i+1] > eil[i])
		{
			max = eil[i + 1];
			nr = i;
		}
	}
	fr << "Daugiausia simboliu ',' yra eiluteje Nr. " << nr + 1 <<endl;
	fd.close();
	fr.close();
}