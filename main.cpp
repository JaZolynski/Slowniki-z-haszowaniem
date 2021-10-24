#include <iostream>
#include <vector>


using namespace std;

int hash_function(int a,int b)
{
    return a%b;
}

class slownik_h_l
{
private:
    vector<int>** a;

    int wielkosc;

public:
    slownik_h_l(int c)
    {
        a=new vector<int>* [c];
        for(int i=0; i<c; i++)
            a[i]=new vector<int>;
        wielkosc=c;
    }

    void insertt(int b)
    {
        a[hash_function(b,wielkosc)]->push_back(b);
    }
    void wypisz()
    {
       cout << "****** SLOWNIK Z ADRESOWANIEM ZA POMOCA METODY LANCUCHOWEJ O WIELKOSCI: " << wielkosc << " ******" << endl << endl;
        for(int i=0; i<wielkosc; i++)
        {

            int licznik=a[i]->size();
            for(int j=0; j<licznik; j++)
            {
                cout << a[i]->at(j) << " ";
            }
            cout << endl;
        }
    }
    int findd(int b)
    {
        for(int i=0; i<a[hash_function(b,wielkosc)]->size(); i++)
            if(a[hash_function(b,wielkosc)]->at(i)==b)
                return b;
        return -1;
    }
    void deletee(int b)
    {
        for(int i=0; i<a[hash_function(b,wielkosc)]->size(); i++)
            if(a[hash_function(b,wielkosc)]->at(i)==b)
            {
                a[hash_function(b,wielkosc)]->erase(a[hash_function(b,wielkosc)]->begin()+i);
                i--;
            }

    }

};

class slownik_a_o
{
    int wielkosc;
    int *tab;
public:
    slownik_a_o(int a)
    {
        wielkosc =a;
        tab=new int[a];
        for(int i=0; i<a; i++)
        {
            tab[i]=-1;
        }
    }

    void insertt(int b)
    {
        if(this->findd(b)==-1)
        for(int i=0; i<wielkosc; i++)
        {
            if(tab[hash_function(b+i,wielkosc)]==-1)
            {
                tab[hash_function(b+i,wielkosc)]=b;
                break;
            }

        }
    }
    void wypisz()
    {
        cout << "****** SLOWNIK Z ADRESOWANIEM OTWARTYM O WIELKOSCI: " << wielkosc << " ******" << endl << endl;
        for(int i=0; i<wielkosc; i++)
            cout << tab[i] << ", ";
        cout << endl << endl;
    }
    int findd(int a)
    {
        for(int i=0; i<wielkosc; i++)
        {
            if(tab[hash_function(a+i,wielkosc)]==a)
                return a;
            if(tab[hash_function(a+i,wielkosc)]==-1)
                break;
        }
     return -1;
    }
    void deletee(int a)
    {
         for(int i=0; i<wielkosc; i++)
        {
            if(tab[hash_function(a+i,wielkosc)]==a)
                {
                    tab[hash_function(a+i,wielkosc)]=-2;
                    break;
                }
            if(tab[hash_function(a+i,wielkosc)]==-1)
                 break;

        }
    }


};
int main()
{

    slownik_a_o a(20);
    a.insertt(1);
    a.insertt(11);
    a.insertt(2);
    a.insertt(5);
    a.insertt(9);
    a.insertt(55);
    a.insertt(3);
    a.insertt(4);
    a.insertt(6);
    a.insertt(10);
    a.insertt(11);
    a.deletee(11);
    a.findd(11);

    a.wypisz();








}
