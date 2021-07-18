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
  if(aFirst <= aLast)
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

  const int SIZE_ARRAY = 10;

  int* pArr = getArrayRand(SIZE_ARRAY);
  //int pArr[] = {9,8,7,6,5,4,3,2,1,0};
  cout << "Array before sorting:" << endl;
  printArray((const int*)pArr, SIZE_ARRAY);
  //sortHoara(pArr,0, SIZE_ARRAY-1);
  //sortLomuto(pArr,0, SIZE_ARRAY-1);
  sortThickPartitioning(pArr,0, SIZE_ARRAY-1);

  cout << "Array after sorting:" << endl;
  printArray((const int*)pArr, SIZE_ARRAY);
  freeArray(pArr);
  //*/



  cout << "" << endl; // prints
	return 0;
}
//------------------------------------------------------------------------------
