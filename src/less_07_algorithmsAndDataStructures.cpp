//============================================================================
// Name        : less_07_algorithmsAndDataStructures.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 7 of the algorithms and data structures
//============================================================================

#include <iostream>
using namespace std;
//------------------------------------------------------------------------------
int* getArrayRand(int aSize)
{
  int *pArr = nullptr;
  try {
    pArr = (int*) new int[aSize];
    for(int i = 0; i < aSize; i++)
    {
      pArr[i] = rand()%100;
    }
  }
  catch (const std::exception&)
  {
    cout << "No memory allocated." << endl;
  }
  return pArr;
}
void freeArray(int* pArr)
{
  if(pArr != nullptr)
  {
    delete pArr;
    pArr = nullptr;
  }
}
void printArray(const int* pArr, const int aSize)
{
  for(int i = 0; i < aSize; i++)
  {
    cout << pArr[i] << " ";
  }
  cout << endl;
}
//------------------------------------------------------------------------------
/*
1. Описать в коде улучшенный алгоритм быстрой сортировки
*/

void swapInt(int * pA, int * pB)
{
  int t = *pA; *pA = *pB; *pB = t;
}

void sortHoara(int *pArr, int aFirst, int aLast)
{
  int indFirst = aFirst;
  int indLast = aLast;
  int ref = pArr[(indLast + indFirst)/2];

  do {
    while(pArr[indFirst] < ref) indFirst++;
    while(pArr[indLast] > ref) indLast--;
    if(indFirst <= indLast) {
      swapInt(&pArr[indFirst],&pArr[indLast]);
      indFirst++;
      indLast--;
    }
  }
  while(indFirst <= indLast);
  if(indFirst < aLast) sortHoara(pArr,indFirst,aLast);
  if(aFirst < indLast) sortHoara(pArr,aFirst,indLast);
}

void sortLomuto(int *pArr, int aFirst, int aLast)
{
  if(aFirst < aLast)
  {
    int indFirst = aFirst;
    int ref = pArr[aLast];
    for(int i = aFirst; i < aLast; i++)
    {
      if(pArr[i] <= ref)
      {
        swapInt(&pArr[indFirst],&pArr[i]);
        indFirst++;
      }
    }
    swapInt(&pArr[aLast],&pArr[indFirst]);
    sortLomuto(pArr,aFirst,indFirst-1);
    sortLomuto(pArr,indFirst+1,aLast);
  }
}

void sortThickPartitioning(int *pArr, int aFirst, int aLast)
{
  if(aFirst < aLast)
  {
    int ref = pArr[aLast];

    int l_indFirst = aFirst;
    int l_indLast = aLast - 1;
    int r_indFirst = aFirst - 1;
    int r_indLast = aLast;

    while(l_indFirst <= l_indLast)
    {
      while(pArr[l_indFirst] < ref) l_indFirst++;
      while(pArr[l_indLast] > ref) l_indLast--;
      if(l_indFirst >= l_indLast) break;
      swapInt(&pArr[l_indFirst],&pArr[l_indLast]);
      if(pArr[l_indFirst] == ref)
        swapInt(&pArr[++r_indFirst],&pArr[l_indFirst++]);
      if(pArr[l_indLast] == ref)
        swapInt(&pArr[--r_indLast],&pArr[l_indFirst--]);
    }
    swapInt(&pArr[l_indFirst],&pArr[aLast]);

    l_indLast = l_indFirst - 1;
    l_indFirst++;

    for(int k = aFirst; k <= r_indFirst; k++,l_indLast--)
      swapInt(&pArr[k],&pArr[l_indFirst]);
    for(int k = aLast - 1; k >= r_indLast; k++,l_indFirst++)
      swapInt(&pArr[k],&pArr[l_indFirst]);

    sortThickPartitioning(pArr,aFirst,l_indLast);
    sortThickPartitioning(pArr,l_indFirst,aLast);
  }
}

void sortQuickImprovement(int *pArr, int aFirst, int aLast)
{
  if(aFirst >= aLast) return;
  if( (aLast - aFirst) <= 10)
  {
    int indLast = aFirst;
    while(indLast < aLast)
    {
      indLast++;
      for(int i = aFirst; i < indLast; i++)
        if(pArr[i] > pArr[indLast])
          swapInt(&pArr[i],&pArr[indLast]);
    }
  }
  else
  {
    int ref;
    if(pArr[aFirst] < pArr[(aFirst + aLast)/2])
    {
      if(pArr[aLast] < pArr[(aFirst + aLast)/2])
        if(pArr[aFirst] < pArr[aLast])
          ref = aLast;
        else
          ref = aFirst;
      else
        ref = (aFirst + aLast)/2;
    }
    else
    {
      if(pArr[aLast] < pArr[(aFirst + aLast)/2])
        ref = (aFirst + aLast)/2;
      else
        if(pArr[aFirst] < pArr[aLast])
          ref = aFirst;
        else
          ref = aLast;
    }
    swapInt(&pArr[ref],&pArr[(aFirst + aLast)/2]);

    int indFirst = aFirst;
    int indLast = aLast;

    do {
      while(pArr[indFirst] < pArr[ref]) indFirst++;
      while(pArr[indLast] > pArr[ref]) indLast--;
      if(indFirst <= indLast) {
        swapInt(&pArr[indFirst],&pArr[indLast]);
        indFirst++;
        indLast--;
      }
    }
    while(indFirst <= indLast);
    if(indFirst < aLast) sortQuickImprovement(pArr,indFirst,aLast);
    if(aFirst < indLast) sortQuickImprovement(pArr,aFirst,indLast);
  }
}
//------------------------------------------------------------------------------
/*
2. Сортировать в массиве целых положительных чисел только чётные числа,
нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
то есть массив вида
[0 2 8 3 4 6 5 9 8 2 7 3]
превратить в
[0 2 2 3 4 6 5 9 8 8 7 3]

Результатом работы должен стать один файл с кодом на языке С,
содержащий функцию main и функции,
необходимые для реализации сортировок
*/





//------------------------------------------------------------------------------
int main() {
//------------------------------------------------------------------------------
  // Task 1
  //*
  cout << "Task 1\n" << endl;

  const int SIZE_ARRAY = 20;

  int* pArr = getArrayRand(SIZE_ARRAY);
  //int pArr[] = {9,8,7,6,5,4,3,2,1,0};
  cout << "Array before sorting:" << endl;
  printArray((const int*)pArr, SIZE_ARRAY);
  sortQuickImprovement(pArr,0, SIZE_ARRAY-1);
  cout << "Array after sorting:" << endl;
  printArray((const int*)pArr, SIZE_ARRAY);
  freeArray(pArr);
  //*/
  //------------------------------------------------------------------------------
	return 0;
}
//------------------------------------------------------------------------------
