/*
File Name: CSC161_jjordan_ProgrammingChal3.cpp
Author: Josh Jordan
Date: 3/11/2021
Description:

NOTES:
*/

#include <iostream>
#include <cstdlib>

void PopulateArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    std::cout << std::endl;
}

void RNG(int arr[], int size)
{
    int temp, RandNum;

    for (int i = 0; i < size; i++)
    {
        RandNum = rand() % 100;
        temp = arr[i];
        arr[i] = arr[RandNum];
        arr[RandNum] = temp;
    }
}

void QuickSort(int arr[], int size)
{
    int temp;
    int i = -1;
    int j = 0;
    int pivot = size - 1;

    while (i < pivot)
    {
        if (arr[j] > arr[pivot])
        {
            j++;
        }
        else
        {
            i++;
            temp = arr[i]
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

void PrintArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int const size = 100;
    int QuickSortArr[size];

    PopulateArray(QuickSortArr, size);
    RNG(QuickSortArr, size);
    PrintArray(QuickSortArr, size);

    return 0;
}