#include<iostream>
#include<string>
#include <algorithm> //library for reverse function
using namespace std;
void mergingArray(int arr1[], int arr2[]);
void commonElements(int arr1[], int arr2[]);
void palindromeChecker(string& userInput);
int main()
{
    string userInput = "";
    int arr1[5] = { 2,5,3,6,1 };
    int arr2[7] = { 4,6,2,9,2,7,5 };
    cout << "Array 1: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << "  ";
    }
    cout << "\nArray 2: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr2[i] << "  ";
    }
    mergingArray(arr1, arr2);
    commonElements(arr1, arr2);
    cout << "\nEnter a Sentence/word:\n";
    getline(cin, userInput);
    palindromeChecker(userInput);
    return 0;
}
void mergingArray(int arr1[], int arr2[]) {
    int i, k = 0, arrMerge[12], temp = 0;
    for (i = 0; i < 5; i++)
    {
        arrMerge[i] = arr1[i]; //adding values of first array
    }
    k = i;
    for (i = 0; i < 7; i++)
    {
        arrMerge[k] = arr2[i]; //adding values of second array
        k++;
    }
    cout << "\nThe New Array (Merged Array):\n";
    for (i = 0; i < k; i++) //printing merged array
        cout << arrMerge[i] << "  ";

    //using bubble sort to sort array in ascending order
    for (int x = 0; x < 11; x++) {
        for (int y = 0; y < 11; y++) {
            if (arrMerge[y] > arrMerge[y + 1]) {
                temp = arrMerge[y];
                arrMerge[y] = arrMerge[y + 1];
                arrMerge[y + 1] = temp;
            }
        }
    }
    cout << "\nSorted Array\n";
    for (int j = 0; j < 12; j++) { //printing sorted array
        cout << arrMerge[j] << "  ";
    }
}
void commonElements(int arr1[], int arr2[]) {
    cout << "\nCommon Elements: \n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            if (arr1[i] == arr2[j]) {
                cout << arr1[i] << "  "; //finding common elements and breaking as soon as a common element is found
                break;
            }
        }
    }
}
void palindromeChecker(string& userInput) {
    string reverseInput = userInput;
    reverse(reverseInput.begin(), reverseInput.end());//using reverse function to reverse the user input
    if (userInput == reverseInput) { //checking if the reversed input matches original input
        cout << "\nIt's a Palindrome!";
    }
    else {
        cout << "\nNot a Palindrome";
    }
}