#include <iostream>

using namespace std;
// implement calculate factorial function in here
void printPattern(int n)
{
	if (n <= 0) {
        cout << n;
        return;
    }
    cout << n<<" ";
    printPattern(n - 5);
    cout <<" "<<n;
	
}

//IN LAB
//Q1.5
bool isPalindrome(const char* str) {
    int size = 0;
    for (int i = 1; str[i] != '\0'; i++) size++;
    for (int i = 0; i <= size / 2; i++) {
        //cout << str[i] << " " << str[size - i]<<endl;
        if (str[i] != str[size - i]) return false;
    }
        
    return true;
}
//Q1.6
bool isSpecialNumber(int n) {
    if (n < 2) return false;
    for (int i = 2; i < n; i++) if (n % i == 0) return false;
    int N=0;
    while (n!=0) {
        N += n % 10;
        n /= 10;
    }
    for (int i = 2; i < N; i++) if (N % i == 0) return false;
    return true;
}
//Q1.7
bool checkElementsUniqueness(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i != j && arr[i] == arr[j]) return false;
    }
    return true;
}
//Q1.10
void encrypt(char* text, int shift) {
    if (shift == 0) return;
    int size = 0;
    for (int i = 0; text[i] != '\0'; i++) size++;
    for (int i = 0; i < size; i++) {
        if (text[i] <= 'Z' && text[i] >= 'A') {
            if (text[i] + shift > 90) text[i] = 65 + (text[i] + shift - 91) % 36;
            else text[i] += shift;
        }
        else if (text[i] <= 'z' && text[i] >= 'a') {
            if (text[i] + shift > 122) text[i] = 97 + (text[i] + shift - 123) % 36;
            else text[i] += shift;
        }
    }
}
void decrypt(char* text, int shift) {
    if (shift == 0) return;
    int size = 0;
    for (int i = 0; text[i] != '\0'; i++) size++;
    for (int i = 0; i < size; i++) {
        if (text[i] <= 'Z' && text[i] >= 'A') {
            if (text[i] - shift < 65) text[i] = 90 - (64 - text[i] + shift) % 36;
            else text[i] -= shift;
        }
        else if (text[i] <= 'z' && text[i] >= 'a') {
            if (text[i] - shift < 97) text[i] = 122 - (96 - text[i] + shift) % 36;
            else text[i] -= shift;
        }
    }
}
//2.7
long long int decimalToBinary(int decimal_number)
{
    if (decimal_number == 1) return 1;
    if (decimal_number % 2 == 1)
        return (decimalToBinary(decimal_number / 2)) * 10 + 1;
    return (decimalToBinary(decimal_number / 2)) * 10;

}
//Q2.1
bool checkDuplicate(int* ar, int size){
    if (size == 1) return true;
    for (int i = 0; i < size - 1; i++) if (ar[i] == ar[size - 1]) return false;
    return checkDuplicate(ar, size - 1);
}
//Q2.4
int recursiveSearch(int& n, int m, int arr[], int index)
{
    if (index == n) return -1;
    if (arr[index] == m) {
        if (index != n - 1) {
            for (int i = index; i < n - 1; i++) arr[i] = arr[i + 1];
            delete& arr[index];
        }
        else delete &arr[index];
        return index;
    }
    return recursiveSearch(n, m, arr, index + 1);
}
//3.4
void add(int* ptr, int n, int k){
    ptr[n] = k;
}
//3.3
int calcSum(int* ptr, int n)
{
    int sum=0;
    for (int i = 0; i < n; i++) sum += *(ptr + i);
    return sum;
}

int main(int narg, char** argv)
{
    cout << decimalToBinary(12344);
}