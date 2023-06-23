/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 10.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
bool CheckPrimenumber(int n) {
    for (int i = 2; i < n; i++) if (n % i == 0) return false;
    return true;
}
int NearestPrimenumber(int n) {
    while (!CheckPrimenumber(n)) n++;
    return n;
}
int Fibonancci(int n) {// Fibonancci nth
    if (n == 1 || n == 2) return 1;
    return Fibonancci(n - 1) + Fibonancci(n - 2);
}
int NearestFibonancci(int n) {
    int i = 1;
    while (n > Fibonancci(i)) i++;
    return Fibonancci(i);
}
string g(string p1, string p2) {
    int store = 0, rev = 0;
    string s;
    for (int i = 0; i < 10; i++) {
        if (p1[i] + p2[i] - 48 * 2 + store > 9) {
            s += to_string((p1[i] + p2[i] - 48 * 2 + store) % 10);
            store = (p1[i] + p2[i] - 48 * 2 + store) / 10;
        }
        else {
            s += to_string(p1[i] + p2[i] - 48 * 2 + store);
            store = 0;
        }
    }
    return s;
}
int Time(int arr[10000], int N) {
    if (N == 2) return 14*(arr[0] + arr[1]);
    return Time(arr, N - 2) + 14*(abs(arr[N - 4] - arr[N - 2]) + abs(arr[N - 3] - arr[N - 1]));
}
void print(int arr[100][100]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cout << arr[i][j] << " ";
        cout << endl;
    }
}

string notebook1(string ntb1) {
    //get line 1 (s1) and line 2 (s2)
    string s1 = "", s2 = "";
    ifstream file(ntb1);
    if (file.is_open()) {
        getline(file, s1);
        getline(file, s2);
    }
    //check s1
    if ((s1.find("Freq/First/") != 0) || ((int)s1.size() != 14)
        || (s1[11] == '0' && s1[12] == '0' && s1[13] == '0')) return "0000000000";
    for (int j = 11; j < 14; j++)
        if (s1[j] < '0' || s1[j]> '9') return "0000000000";
    //check s2
    if ((int)s2.size() < stoi(s1.substr(11, 3)) * 2 - 1) return "0000000000"; //number of int < n1
    //count
    int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
    for (int j = 0; j < stoi(s1.substr(11, 3)) * 2 - 1; j += 2) arr[(int)s2[j] - 48]++;
    s2 = "";
    for (int j = 0; j < 10; j++) {
        if (arr[j] > 9) arr[j] %= 10;
        s2 += to_string(arr[j]);
    }
    return s2;
}
string notebook2(string ntb2) {
    string n2 = "", s = "";
    ifstream file(ntb2);
    if (!file.is_open()) return"1111111111";
    getline(file, n2);
    // check s1
    if ((int)n2.size() != 5) return "1111111111";
    for (int i = 0; i < (int)n2.size(); i++) if (n2[i] > '9' || n2[i] < '0') return "1111111111";
    if (stoi(n2) < 5 || stoi(n2) > 100) return "1111111111";
    long long cntP = 0;
    for (int i = 0; i < stoi(n2); i++) {
        getline(file, s);
        while (s.find("Pink") >= 0 && s.find("Pink") < (int)s.size()) {
            cntP++;
            s.erase(s.find("Pink"), 4);
        }
        while (s.find("pink") >= 0 && s.find("pink") < (int)s.size()) {
            cntP++;
            s.erase(s.find("pink"), 4);
        }
    }
    if (cntP < 10000) cntP *= cntP; //step1
    while (cntP < pow(10, 9)) cntP = cntP * 10 + 9; //step2;

    return to_string(cntP);
}
string notebook3(string ntb3) {
    // Complete this function to gain point
    ifstream file(ntb3);
    if (!file.is_open()) return"";
    //input number in matrix
    int arr[10][10]; string s;
    for (int i = 0; i < 10; i++) {
        getline(file, s);
        int j = 0; string rev;
        for (int m = 0; m < (int)s.size(); m++) {
            if (s[m] != '|') rev += s[m];
            if (s[m] == '|' || m == (int)s.size() - 1) {
                (stoi(rev) < 0) ? arr[i][j] = -stoi(rev) : arr[i][j] = stoi(rev);
                if (i < j) arr[i][j] = NearestPrimenumber(arr[i][j]);//step 1
                else if (i > j) arr[i][j] = NearestFibonancci(arr[i][j]);//step 2
                j++; rev = "";
            }
        }
    }
    //step 3
    for (int i = 0; i < 10; i++)
        for (int j = 7; j < 9; j++)
            for (int m = 8; m < 10; m++)
                if (arr[i][j] > arr[i][m]) {
                    int rev = arr[i][j];
                    arr[i][j] = arr[i][m];
                    arr[i][m] = rev;
                }
    //max
    s = "";
    for (int i = 0; i < 10; i++) {
        int max = arr[i][0], position = 0;
        for (int j = 1; j < 10; j++) if (max <= arr[i][j]) {
            max = arr[i][j];
            position = j;
        }
        s += to_string(position);
    }
    return s;
}
string generateListPasswords(string pwd1, string pwd2, string pwd3) {
    // Complete this function to gain point
    return pwd1 + ";" + pwd2 + ";" + pwd3 + ";"
        + g(pwd1, pwd2) + ";" + g(pwd1, pwd3) + ";" + g(pwd2, pwd3) + ";"
        + g(g(pwd1, pwd2), pwd3) + ";" + g(pwd1, g(pwd2, pwd3)) + ";"
        + g(g(pwd1, pwd2), g(pwd1, pwd3));
}
bool chaseTaxi(
    int arr[100][100],
    string points,
    string moves,
    string& outTimes,
    string& outCatchUps) {
    for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) arr[i][j] = -9;
    int x = 0, y = 0, present = 0;
    //Time of taxi
    arr[0][0] = 0;
    for (int i = 0; i < (int)moves.size(); i++) {
        if (moves[i] == 'U') x--;
        else if (moves[i] == 'D') x++;
        else if (moves[i] == 'L') y--;
        else y++;
        if (x > 99) x = 99;
        else if (y > 99) y = 99;
        else if (x < 0) x = 0;
        else if (y < 0) y = 0;
        else {
            present += 9;
            arr[x][y] = present;
        }
    }
    //Time of SH
    int arrS[10000], sizeS = 0;
    for (int i = 0; i < (int)points.size(); i++) {
        string numb;
        if (points[i] == '(') {
            for (i++; points[i] != ','; i++) numb += points[i];

            arrS[sizeS] = stoi(numb);
            numb = ""; sizeS++;
            for (i++; points[i] != ')'; i++) numb += points[i];
            arrS[sizeS] = stoi(numb);
            sizeS++;
        }
    }
    for (int j = 2; j <= sizeS; j += 2) {
        if ((int)outCatchUps.size() > 0) {
            outCatchUps += ";";
            outTimes += ";";
        }
        if (outCatchUps.find('Y') < (int)outCatchUps.size() && outCatchUps.find('Y') >= 0) {
            outCatchUps += "-";
            outTimes += "-";
        }
        else {
            outTimes += to_string(Time(arrS, j));
            if (arr[arrS[j - 2]][arrS[j - 1]] >= Time(arrS, j)) outCatchUps += "Y";
            else outCatchUps += "N";
        }
    }
    if (outCatchUps.find('Y') < (int)outCatchUps.size() && outCatchUps.find('Y') >= 0) return true;
    return false;

}

string enterLaptop(string tag, string message) {
    // Complete this function to gain point
    ifstream file(tag);
    if (!file.is_open()) return "";
    string n3, pass, email;
    getline(file, email);
    getline(file, n3);
    for (int i = 0; i < stoi(n3.substr(9, n3.find(" THT Street") - 9)); i++) pass += message;
    return email.substr(7) + ";" + pass;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
