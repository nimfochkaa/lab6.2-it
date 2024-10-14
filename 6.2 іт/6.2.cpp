#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) 
{
    for (int i = 0; i < size; i++) 
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void Print(const int* a, const int size) {
    for (int i = 0; i < size; i++) 
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}

int FindMinEvenIndex(const int* a, const int size) 
{
    int minEvenIndex = -1; 
    for (int i = 0; i < size; i++) 
    {
        if (a[i] % 2 == 0) 
        { 
            if (minEvenIndex == -1 || a[i] < a[minEvenIndex]) 
            {
                minEvenIndex = i;
            }
        }
    }
    return minEvenIndex;
}

void SwapFirstWithMinEven(int* a, const int size) 
{
    int minEvenIndex = FindMinEvenIndex(a, size);
    if (minEvenIndex != -1) 
    { 
        swap(a[0], a[minEvenIndex]); 
    }
}

int main() 
{
    srand((unsigned)time(NULL));

    const int n = 10; 
    int a[n];
    int Low = -50;
    int High = 50;

    Create(a, n, Low, High);

    cout << "Original array: ";
    Print(a, n);

    SwapFirstWithMinEven(a, n);

    cout << "Modified array: ";
    Print(a, n);

    return 0;
}
