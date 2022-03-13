/*
File Name: CSC161_jjordan_ProgrammingChal3.cpp
Author: Josh Jordan
Date: 3/11/2021
Description: Create a program that creates two arrays both size '100'. Each element is to intially count from 1 to 100 with no duplicate numbers and then
the program will randomize both arrays using the "rand()" function. From there the code will sort each array using a different method. Array 1 is sorted
using quick sort and array 2 is sorted using selection. A counter will need to be created and implemented for each comparrison to count to compare the two
different methods. On completion of the program the difference in the two comparrisons will be displayed deeming one more efficient.

NOTES: When I first added my final 1000 item array to my main for the search algo's I was given a green swigly underneath main suggesting to move some stuff
to heap. I dont quite recall if that was a stack overflow issue or what it what. 
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
    int RandNum;

    srand(time(0));

    // populate array from 1 - size //
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
    std::cout << std::endl;

    // interate through the loop one item at a time swapping its current number with a random index //
    for (int i = 0; i < size; i++)
    {
        RandNum = rand() % 100;
        swap(arr, i, RandNum);
    }
}

template <class T>
int partition(T arr[], int first, int last, int &QuickCounter)
{
    T pivot;
    int SmallIndex;;

    // swaps pivot to the front of array //
    swap(arr, first, (first + last) / 2);

    pivot = arr[first]; // sets pivot to the number in index 0 //
    SmallIndex = first; // sets the 'SmallIndex' to index 0 //

    // iterates through the array 1 - 99 //
    for (int i = first + 1; i <= last; i++)
    {
        QuickCounter++;
        if (arr[i] < pivot)
        {
            SmallIndex++;
            swap(arr, SmallIndex, i);
        }
    }
    swap(arr, first, SmallIndex); // swaps the pivot with whatever the small index is //

    return SmallIndex;
}

template <class T>
void recursion_QuickSort(T arr[], int first, int last, int &QuickCounter)
{
    int pivot;

    if (first < last)
    {
        QuickCounter++;
        pivot = partition(arr, first, last, QuickCounter);
        recursion_QuickSort(arr, first, pivot - 1, QuickCounter);
        recursion_QuickSort(arr, pivot + 1, last, QuickCounter);
    }
}

template <class T>
void QuickSort(T arr[], int size, int &QuickCounter)
{
   recursion_QuickSort(arr, 0, size - 1, QuickCounter);
}

// Selection Sort - finds the lowest number in the array and moves it to the front... continues this until array is sorted //
template <class T>
int SelectionSort(T arr[], int size)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        int MinIndex = i;
        // iterate through the array //
        for (int j = i + 1; j < size; j++)
        {
            counter++;
            if (arr[j] < arr[MinIndex]) // finding the smallest element //
            {
                MinIndex = j; // replacing the current 'MinIndex' with the index of 'j' //
            }
        }
        swap(arr, i, MinIndex);
    }
    return counter;
}

template <class T>
int SequentialSearch(T arr[], int size, T target)
{
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        counter++;
        if (arr[i] == target)
        {
            break;
        }
    }
    return counter;
}

template <class T>
int BinarySearch(T arr[], int size, T target)
{
    int mid;
    int counter = 0, first = 0, last = size - 1;
    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (arr[mid] == target)
        {
            counter++;
            found = true;
        }
        else if (arr[mid] > target)
        {
            counter++;
            last = mid - 1;
        }
        else
        {
            counter++;
            first = mid + 1;
        }
    }
    return counter;
}

int main()
{
    int QuickTotal = 0, SelectionTotal = 0, SequentialTotal = 0, BinaryTotal = 0;
    int const size = 100, TestAmount = 100;
    int SelectionCounter = 0, QuickCounter = 0, SequentialCounter = 0, BinaryCounter = 0;
    int QuickSortArr[size], SelectionSortArr[size];
    int SearchArr[1000];

    for (int i = 0; i < TestAmount; i++)
    {
        PopulateAndRNG(QuickSortArr, size);
        QuickSort(QuickSortArr, size, QuickCounter);
        QuickTotal += QuickCounter;
        QuickCounter = 0;

        PopulateAndRNG(SelectionSortArr, size);
        SelectionCounter = SelectionSort(SelectionSortArr, size);
        SelectionTotal += SelectionCounter;
        SelectionCounter = 0;
    }
    std::cout << "Average Quick Sort Comparison's: " << QuickTotal / TestAmount << std::endl;
    std::cout << "Average Selection Sort Comparison's: " << SelectionTotal / TestAmount << std::endl;

    for (int i = 0; i < 1000; i++)
    {
        SearchArr[i] = i + 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        SequentialCounter = SequentialSearch(SearchArr, 1000, i);
        SequentialTotal += SequentialCounter;

        BinaryCounter = BinarySearch(SearchArr, 1000, i);
        BinaryTotal += BinaryCounter;
    }
    std::cout << "Average Sequential Search Comparison's: " << SequentialTotal / 1000 << std::endl;
    std::cout << "Average Binary Search Comparison's: " << BinaryTotal / 1000 << std::endl;

    return 0;
}
