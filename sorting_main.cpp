#include <iostream>
#include <cstdio>
#include <cstddef>
#include <math.h>
#include <cstring>
#include <cstdint>
#include <cstdlib>

/**************************************************/
/*   This file implements various sorting methods */
/*   Arthur: Richard Chen                         */
/**************************************************/

// namespace Sorting {
using namespace std;

// Constant Declaration
#define MAX_VALID_OPTION 4

// Forward Declaration
void RunInsertionSort(uint16_t* pInput, uint16_t nLength);
void RunSelectionSort(uint16_t* pInput, uint16_t nLength);
void printResult(uint16_t* inputArray, uint16_t nLength);

// Main
int main()
{
    uint16_t nOption = 0, nLength = 0, nInputVal = 0, count = 0;
    cout << "Choose sorting method:\n1. Insertion Sort(Poker Hand)\n2. Merge Sort\n3. Quick Sort\n"
        "4. Selection Sort\n:";
    cin >> nOption;
    uint16_t* inputArray = NULL;
    if (nOption <= MAX_VALID_OPTION)
    {
        cout << "Enter input length:\n";
        cin >> nLength;
        inputArray = new uint16_t[nLength];
        memset(inputArray, 0, sizeof(uint16_t) * nLength);
        do
        {
            nInputVal = rand() % 100;
            //cin >> nInputVal;
            inputArray[count++] = nInputVal;
        } while (count < nLength);
    }

    switch (nOption)
    {
    case 1:
    {
        // Run Insertion Sort
        cout << "\n\n Executing Insertion sort:";
        printResult(inputArray, nLength);
        RunInsertionSort(inputArray, nLength);
        cout << "\n\n Complete Insertion sort:";
        break;
    }
    case 2:
    {
        // Run Merge Sort
        break;
    }
    case 3:
    {
        // Run Quick Sort
        break;
    }
    case 4:
    {
        // Run Selection Sort
        cout << "\n Executing Insertion sort:";
        printResult(inputArray, nLength);
        RunSelectionSort(inputArray, nLength);
        cout << "\nComplete Selection Sort:";
        break;
    }
    default:
        cout << "\nInvalid Option Chosen!\n";
        break;
    }
    printResult(inputArray, nLength);
    delete inputArray;
    return 0;
}

// Insertion Sort
void RunInsertionSort(uint16_t* pInput, uint16_t nLength)
{
    // Insertion sort is similar to playing poker hand. 
    // Where you pick one card and fit into the hand
    // by shifting the bigger cards to right
    // For ex: 1, 5, 8  Draw: 7
    // 1, 5, 7(Insert), 8(Shift)   Draw: 4
    // 1, 4(Insert), 5(shift), 7(shift), 8(shift)
    
    // 1. Create a temp array size of nLength
    uint16_t tmpArray[nLength];

    // 2. Save first value
    uint16_t count = 0;
    tmpArray[count++] = pInput[0];
    
    // 3. Start drawing and inserting till the end
    while (count < nLength)
    {
        uint16_t curVal = pInput[count];
        for (int i = 0; i < count; i++)
        {
            if (tmpArray[i] > curVal)
            {
                // Found a value that is bigger than cur value
                // Shift the values that are bigger by 1
                int shift_count = (count - i > 0) ? (count - i) : 0;
                memcpy(&tmpArray[i+1], &tmpArray[i], shift_count * sizeof(uint16_t));
                // Insert current val
                tmpArray[i] = curVal;
                break;
            }
            else if (i == count-1)
            {
                // Curval is largest number in the deck, put on the rightmost
                tmpArray[i + 1] = curVal;
            }
        }
        count++;
    }
    // 4. Copy the tmpArray to original array
    memcpy(pInput, tmpArray, sizeof(uint16_t) * nLength);
}

// Implementation of selection sort
void RunSelectionSort(uint16_t* pInput, uint16_t nLength)
{
    // Key of selection sort is to find min on each round
    // and put inside the ordered array from small to big
    // non-decreasing order
    // uint16_t pTmpArray[nLength];
    // memset(pTmpArray, 0, sizeof(uint16_t)*nLength);
    for (int i = 0; i < nLength; i++)
    {
        uint16_t min_index = i;
        uint16_t min_val = pInput[i];
        for (int j = i+1; j < nLength; j++)
        {
            if (min_val > pInput[j])
            {
                min_index = j;
                min_val = pInput[j];
            }
        }

        // Swap only if min_index is not current slot
        if (i != min_index)
        {
            // Swap current slot w/ min value
            pInput[min_index] = pInput[i];
            pInput[i] = min_val;
        }
    }
}

void printResult(uint16_t* inputArray, uint16_t nLength)
{
    cout << "Print Array: ";
    for (int i = 0; i < nLength; i++)
    {
        cout << " " << inputArray[i];
        if (i == nLength - 1)
        {
            cout << endl;
        }
    }
}
// } // END NAMESPACE SORTING