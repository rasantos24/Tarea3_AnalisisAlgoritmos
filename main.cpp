#include "Test.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int getValue(int replaced_value,vector<int> min_heap)
{
    for(int i =0; i<min_heap.size();i++)
    {
        if(min_heap[i] == replaced_value)
            return i;
    }
}

int getMenorPos(int izqV, int derV, int izqP, int derP)
{
    return izqV > derV ? derP : izqP;
}

int hijoIzq(int padrePos)
{
    return 2*padrePos;
}

int hijoDer(int padrePos)
{
    return 2*padrePos+1;
}

int getPadrePos(int hijoPos)
{
    if(hijoPos%2 == 0)
        return (hijoPos - 2) / 2;

    return (hijoPos -1 ) / 2;
}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
    int valuePos = getValue(replaced_value,min_heap);
    min_heap[valuePos] = replacement;
    int padrePos = getPadrePos(valuePos);
    int hijoIzqPos = hijoIzq(valuePos);
    int hijoDerPos = hijoDer(valuePos);

    if(min_heap[valuePos] < min_heap[padrePos])
    {
        while(padrePos >= 0 && min_heap[valuePos] < min_heap[padrePos])
        {
            int padre = min_heap[padrePos];
            min_heap[padrePos] = min_heap[valuePos];
            min_heap[valuePos] = padre;
            valuePos = padrePos;
            padrePos = getPadrePos(valuePos);
        }
    }
    else if(min_heap[valuePos] > min_heap[hijoIzqPos]  || min_heap[valuePos] > min_heap[hijoDerPos])
    {
        while(valuePos < min_heap.size() && (min_heap[valuePos] > min_heap[hijoIzqPos]  || min_heap[valuePos] > min_heap[hijoDerPos]) )
        {
            int menor = getMenorPos(min_heap[hijoIzqPos],min_heap[hijoDerPos],hijoIzqPos,hijoDerPos);
            int hijo = min_heap[menor];
            min_heap[menor] = min_heap[valuePos];
            min_heap[valuePos] = hijo;
            valuePos = menor;
            hijoIzqPos = hijoIzq(valuePos);
            hijoDerPos = hijoDer(valuePos);
        }
    }
    return min_heap;
}

int main ()
{
    test();
    return 0;
}
