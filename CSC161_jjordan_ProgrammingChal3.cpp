/*
File Name: CSC161_jjordan_ProgrammingChal3.cpp
Author: Josh Jordan
Date: 3/11/2021
Description: Create a program that creates two arrays both size '100'. Each element is to intially count from 1 to 100 with no duplicate numbers and then
the program will randomize both arrays using the "rand()" function. From there the code will sort each array using a different method. Array 1 is sorted
using quick sort and array 2 is sorted using selection. A counter will need to be created and implemented for each comparrison to count to compare the two
different methods. On completion of the program the difference in the two comparrisons will be displayed deeming one more efficient.

NOTES: first series of issues is writing up the quick sort. most issues are related to recursion and overall syntax on how it's supposed to be written.
*/

#include <iostream>
#include <cstdlib>

template <class T>
void swap(T arr[], int first, int second)
{
    T temp;

    temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
    
}

void PopulateAndRNG(int arr[], int size)
{
    int temp, RandNum;

    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        RandNum = rand() % 100;
        swap(arr, i, RandNum);
    }
}

/// COPIED FORM SLIDES - NEEDS DIAGNOSIS FOR PERSONAL //

//template <class T>
//int partition(T arr[], int first, int last)
//{
//    T pivot;
//    int SmallIndex;
//
//    swap(arr, first, (first + last) / 2);
//
//    pivot = arr[first];
//    SmallIndex = first;
//
//    for (int i = first + 1; i <= last; i++)
//    {
//        if (list[i] < pivot)
//        {
//            SmallIndex++;
//            swap(arr, SmallIndex, i);
//        }
//    }
//    swap(arr, first, SmallIndex);;
//
//    return SmallIndex;
//}

template <class T>
int QuickSort(T arr[], int size)
{
    int counter = 0;


}

// Selection Sort - finds the lowest number in the array and moves it to the front... continues this until array is sorted //
template <class T>
int SelectionSort(T arr[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[MinIndex])
            {
                MinIndex = j;
                counter++;
            }
        }
        swap(arr, i, MinIndex);
    }
    return counter;
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
    int QuickCounter, SelectionCounter;
    int const size = 100;
    int QuickSortArr[size], SelectionSortArr[size];

    PopulateAndRNG(QuickSortArr, size);
    std::cout << "----- Randomized Arrays -----\n";
    PrintArray(QuickSortArr, size);

    PopulateAndRNG(SelectionSortArr, size);
    
    std::cout << "\n----- Quick Sorted Array -----\n";
    //QuickCounter = QuickSort(QuickSortArr, size);
    //PrintArray(QuickSortArr, size);

    std::cout << "\n----- Selection Sorted Array -----\n";
    SelectionCounter = SelectionSort(SelectionSortArr, size);
    PrintArray(SelectionSortArr, size);

    std::cout << "Comparrisons: " << SelectionCounter << std::endl;

    return 0;
}