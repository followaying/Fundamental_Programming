// lab_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

//Q1.1: DELETE WH
void process1_1(char str[], char outstr[]) {
    int length = 0, size = 0;
    for (int i = 0; str[i] != '\0'; i++) if (str[i] != ' ') size = i;
    for (int i = 0; i<=size; i++) 
        if (!(str[i] == ' ' && length == 0) && !(length > 0 && str[i] == ' ' && outstr[length - 1] == ' ')) {
            outstr[length] = str[i];
            length++;
        }
    outstr[length] = '\0';
}
//Q1.2: REVERSE
void process1_2(const char* str, char* outstr) {
    int size = 0;
    for (int i = 0; str[i] != '\0'; i++) size++;
    for (int i = size-1; i >= 0; i--) outstr[size - i-1] = str[i];
    outstr[size] = '\0';
}
//Q1.5: returns the decimal value of binary string str.
int calc(char str[]) {
    int calc = 0;
    for (int i = 0; i < (int)strlen(str); i++) 
        if (str[i] == '1') {
            int rev = 1;
            for (int j = 0; j < (int)strlen(str) - i - 1; j++) rev *= 2;
            calc += rev;
        }
    return calc;
}
//Q2.7: cut a string from index
void cutString(string s, int index) {
    if (index < int(s.size())) {
        s = s.substr(index, int(s.size()) - index);
        cout << s;
    }
}
//Q2.6: Find All index of s2 in s1 
void findAllIndex(string s1, string s2) {
    bool initial = true;
    int old = 0;
    while (s1.find(s2) >= 0 && s1.find(s2) < int(s1.size())) {
        if (initial) initial = false;
        else cout << " ";
        cout << s1.find(s2)+ old;
        old += int(s2.size());
        s1.erase(s1.find(s2), int(s2.size()));
    }
    if (initial) cout << -1;
}
//Q3.1: Find colum whose sum is max
int findMaxColumn(int arr[][1000], int row, int col) {
    int max,index=0;
    for (int i = 0; i < col; i++) {
        int sum=0;
        for (int j = 0; j < row; j++) sum += arr[j][i];
        if (i == 0) max = sum;
        if (sum > max) {
            max = sum;
            index = i;
        }
    }
    return index;

}
//Q3.2: product of all elements on the main diagonal of this array
int diagonalProduct(int arr[][1000], int row, int col) {
    int product = arr[0][0];
    for (int i = 1; i < row; i++) product *= arr[i][i];
    return product;
}
//Q3.3:Check whether the given array is symmetric matrix or not; return true if it is, otherwise return false.
bool isSymmetric(int arr[][1000], int row, int col) {
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (arr[i][j] != arr[j][i]) return false;
    return true;
}
//Q3.3:Find the absolute value of the difference between the sums of two diagonal containing the cell which is represented by x and y of the given array.
int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sum1 = arr[x][y], sum2 = arr[x][y];
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) sum1 += arr[i][j];
    for (int i = x + 1, j = y + 1; i <row && j <col; i++, j++) sum1 += arr[i][j];
    for (int i = x - 1, j = y + 1; i >= 0 && j <col; i--, j++) sum2 += arr[i][j];
    for (int i = x + 1, j = y - 1; i < row && j >=0; i++, j--) sum2 += arr[i][j];
    if (sum1 > sum2) return sum1 - sum2;
    else return sum2 - sum1;
}
//4.2
void calSum(string str) {
    string rev;
    int sum = 0;
    for (int i = 0; i < (int)str.size(); i++) {
        if (str[i] != ' ') rev += str[i];
        else {
            if (stoi(rev) > 0) sum += stoi(rev);
            rev = "";
        }
    }
    if (stoi(rev) > 0) sum += stoi(rev);
    cout << sum;
}*/
////IN LAB
//Q1.3
void process(const char* name, char* outstr) {
    char rev[100];
    bool already = false, inital = true;
    int j = 0, size =0;
    for (int i = 0; i < strlen(name); i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            if (inital) inital = false;
            if (already) rev[j] = name[i] + 32;
            else rev[j] = name[i];
            already = true;
            j++;
            size=j;
        }
        else if (name[i] >= 'a' && name[i] <= 'z') {
            if (inital) inital = false;
            if (!already) rev[j] = name[i] - 32;
            else rev[j] = name[i]; j++;
            already = true;
            size =j;
        }
        else if (!inital) { rev[j] = ' '; j++; already = false; }
        else already = false;
    }
    j = 0;
    for (int i = 0; i < size; i++) {
        if ((rev[i] <= 'Z' && rev[i] >= 'A') || (rev[i] <= 'z' && rev[i] >= 'a') || (rev[i]==' ' && outstr[j-1]!=' ')) {
            outstr[j] = rev[i];
            j++;
        }
    }
    outstr[j] = '\0';
}
void printFirstRepeatedWordchar(char str[]) {
    char s[100];
    int length =0, time =0,i = 0;
    for (; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            s[length] = str[i];
            length++;
        }
        if (str[i] == ' '|| str[i+1] == '\0' ) {
            s[length] = '\0';
            for (int j = 0; str[j] != '\0'; j++) {
                if (str[j] == s[0]) {
                    int m=1;
                    for (; s[m] != '\0'; m++) if (str[j + m] != s[m]) break;
                    if (s[m] == '\0') time++;
                }
            }
            if (time >= 2){
                cout << s;
                break;
            }
            //clear;
            length = 0;
            time = 0;
            for(int j = 0; s[j] != '\0'; j++) s[j] = '\0';
        }
    }
    if (str[i] == '\0') cout << "No Repetition";
}
//Q2.4:
void replaceString(string s, string s1, string s2) {
    int position = -1;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == s1[0]) {
            int j = 1;
            for (; j < (int)s1.size(); j++)
                if (s[i + j] != s1[j]) break;
            if (j == (int)s1.size()) position = i;
        }
    }
    if (position >=0) s.replace(position, int(s1.size()), s2);
    cout << s;
}
//Q2.5:
void deleteWord(string s, string s1) {
    while (s.find(s1) >= 0 && s.find(s1) <= (int)s.size()) s.erase(s.find(s1), (int)s1.size());
    cout << s;
}
//Q2.1:
/*int max = -1;
string s, rev;
cin >> s;
for (int i = 0; i < (int)s.size(); i++) {
    if (rev == "" || rev.back() == s[i]) rev += s[i];
    else {
        if ((int)rev.size() > max) max = (int)rev.size();
        rev = s[i];
    }
    if (i == (int)s.size() - 1 && (int)rev.size() > max) max = (int)rev.size();

cout << max;
}*/
//3.4
int ascendingRows(int arr[][1000], int row, int col) {
    int total = 0,j;
    for (int i = 0; i < row; i++) {
        for (j = 1; j < col; j++)
            if (arr[i][j] < arr[i][j - 1]) break;
        if (j == col) total++;
    }
    return total;
        
}
//3.5
int primeColumns(int arr[][1000], int row, int col) {
    int total=0;
    for (int i = 0; i < col; i++) {
        int sum=0;
        for (int j = 0; j < row; j++) sum += arr[j][i];
        //check
        int j = 2;
        for (; j < sum; j++) if (sum % j == 0) break;
        if (j == sum) total++;
    }
    return total;
}
//4.3
void uppercase(string output) {
    string str;
    cin >> str;
    ofstream f(output);
    for (int i = 0; i < (int)str.size(); i++) if (str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
    f << str;
}
//4.1
/*
void threeChars(string fileName) {
    ifstream text;
    text.open(fileName);
    string str;
    while (getline(text, str)) {
        if (str == "***") break;
        int i;
        for (i = 0; i < (int)str.size(); i++) if (i > 0 && str[i] < str[i - 1]) {
            cout << "false\n";
            break;
        }
        if (i == (int)str.size()) cout << "true\n";
    }
}*/


int main(){
    char str[] = "  abc  def  ghi  ";
    char* outstr = new char[strlen(str) + 1];
    process1_2(str, outstr);
    cout << outstr<<"|";
    
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
