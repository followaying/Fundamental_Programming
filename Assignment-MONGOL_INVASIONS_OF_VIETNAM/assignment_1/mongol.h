//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix, const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
int King(const string ID[], const int NID) {
    int result = 0;
    for (int i = 0; i < NID; i++) {
        if (ID[i][0] == 'V' && ID[i][1] == 'U' && ID[i][2] == 'A') {
            result = 1;
            return result;
        }
        for (int j = 1; j < ID[i].size() - 4; j++) {
            if (ID[i][j] == 'T' && ID[i][j + 1] == 'H' && ID[i][j + 2] == 'D') {
                result = 2;
            }
        }
    }
    return result;
}
string binary(const string input1[], const int N1) {
    string newstr;
    int j = 0;
    while (j != N1) {
        int i = 0;
        while (i < input1[i].size()) {
            if (input1[i][j] == ' ') newstr += " ";
            else {
                if (input1[i][j] == '0' && input1[i][j + 1] == '0') {
                    newstr += "0";
                    i++;
                }
                else if (input1[i][j] == '0' && input1[i][j + 1] == '1') {
                    newstr += "1";
                    i++;
                }
                if (input1[i][j] == '1' && input1[i][j + 1] == '0') {
                    newstr += "2";
                    i++;
                }
                else if (input1[i][j] == '1' && input1[i][j + 1] == '1') {
                    newstr += "3";
                    i++;
                }
            }
            i++;
        }
        newstr += '\n';
        j++;
    }
    return newstr;
}
string syn(string str) {
    string rev = "", rev1, newstr = "", str0 = "EFGHIJK", str1 = "LMNOPQR", str2 = "#TUVWXY", str3 = "";
    int i = 0, l = 0, k = 0;
    while (i < str.size()) {
        int j = i;
        while (str[j] != ' ' && str[j] != '\n') {
            rev += str[j];
            j++;
        }// out rev
        if (str[i] == '0') newstr += str0[rev.size() - 1];
        else if (str[i] == '1') newstr += str1[rev.size() - 1];
        else if (str[i] == '2') newstr += str2[rev.size() - 1];
        else if (str[i] == '3') newstr += str3[rev.size() - 1];
        if (str[j] == '\n') newstr += '\n';
        i = j + 1;
        rev.clear();
    }
    //#
    i = 0;
    while (i < newstr.size()) {
        if (newstr[i] == '#') {
            int p = i + 1;
            while (newstr[p] >= 60 && newstr[p] <= 90) {
                p++;
            }
            if (p > i + 1) newstr.insert(p, 1, newstr[p - 1] + 1);
            i = p;
        }
        else i++;
    }
    //@
    i = 0;
    while (i < newstr.size()) {
        if (newstr[i] == '@') {
            int p = i + 1;
            string s = "";
            while (newstr[p] >= 60 && newstr[p] <= 90) {
                s.insert(0, 1, newstr[p]);
                p++;
            }
            newstr.replace(i + 1, p - i - 1, s);
            i = p;
        }
        else i++;
    }
    // delet
    while (newstr.find('@') != -1) {
        newstr.erase(newstr.find('@'), 1);
    }
    while (newstr.find('#') != -1) {
        newstr.erase(newstr.find('#'), 1);
    }
    return newstr;
}
bool oddlength(string str) {
    bool a;
    (str.size() % 2 == 1) ? a = 1 : a = 0;
    return a;
}
string conver(string str) {
    string newstr, Newstr;
    bool a = oddlength;
    if (a == 1)  reverse(str.begin(), str.end());
    else {
        int i = str.size() - 1;
        while (i >= 1) {
            newstr += str[i - 1] + str[i];
        }
    }
    int i = 0;
    while (i < str.size()) {
        (newstr[i] > str[i]) ? Newstr += newstr[i] : Newstr += str[i];
    }
    return Newstr;
}


string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
    string newstr = binary(input1, N1);
    newstr = syn(newstr);
    if (King(ID, NID) == 1) {
        newstr = conver(newstr);
    }
    else if (King(ID, NID) == 2) {
        int i = 0;
        while (i < newstr.size()) {
            newstr.erase(1, 1);
            i += 3;
        }
    }
    return newstr;
}
int decode(const string A, const string B)
{
    int counting = 0, i = 0, r = 0;
    string rev = "";

    while (i <= A.size() - B.size()) {
        int j = 0;
        while (j < B.size()) {
            rev += A[i + j];
            j++;
        }
        if (rev == B) counting++;
        rev.clear();
        i++;
    }
    return counting;
    return -1;
}
string findRoute(const string input3[])
{
    string N1, B1, S;
    int i = 0, x = 0, y = 0;
    while (input3[i] != " ") { // find int of N
        N1 += input3[i];
        i++;
    }
    int N = stoi(N1);
    while (input3[i] != " ") {// find int of B
        B1 += input3[i];
        i++;
    }
    int B = stoi(B1);
    while (i <= input3[i].size()) {// find string of S
        S += input3[i];
        i++;
    }
    if (B < 0) {
        int i = 0;
        while (i <= -B) {
            S += S[0];
            S.erase(0, 1);
            i++;
        }
    }
    else if (B > 0) {// S in the frist time change
        i = 0;
        while (i <= B) {
            S.insert(0, 1, S[S.size() - 1]);
            S.erase(S.size() - 1, 1);
            i++;
        }
    }
    i = 0; // S in the second time change
    while (i < S.size()) {
        int a = abs(N - 2 * i);
        while (a > 0) {
            if (S[i] == 'U') S[i] = 'D';
            else if (S[i] == 'D')S[i] = 'R';
            else if (S[i] == 'R')S[i] = 'L';
            else if (S[i] == 'L')S[i] = 'U';
            a--;
        }
        i++;
    }
    i = 0;
    while (i < S.size()) {
        if (S[i] == 'U') ++y;
        else if (S[i] == 'D') --y;
        else if (S[i] == 'R') ++x;
        else if (S[i] == 'L') --x;
        i++;
    }
    string result = "(,)";
    result.insert(1, to_string(x));
    result.insert(2 + (to_string(x)).size(), to_string(y)); // a string with format (x,y)
    return result;
}
string decodeVfunction(const string A, const string B)
{
    int V1 = 0, V2 = 0;
    string result;
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] == 'V') V1++;
    }
    for (int i = 0; i < B.size() - 1; i++) {
        if (B[i] == 'V') V2++;
    }
    int V = V1 * V2;
    result = "0";
    for (int i = 1; i <= V; i++) {
        result.insert(0, "V(");
        result.insert(result.size(), ")");
    }
    return result;
}
string findBetrayals(const string input5[], const int N5)
{
    int arr[100];
    for (int i = 0; i < N5; i++) {
        string s = input5[i];
        cout << s;
        for (int j = 0; j < 6; j++) {
            arr[(int)(s[j])] += (6 - j);
        }
    }
    int p1 = 0, p2 = 0, p3 = 0;
    int Max1 = 0, Max2 = 0, Max3 = 0;
    for (int i = 90; i >= 65; i--) {
        if (arr[i] >= Max1) p1 = i;
    }
    arr[p1] = 0;
    for (int i = 90; i >= 65; i--) {
        if (arr[i] >= Max1) p2 = i;
    }
    arr[p2] = 0;
    for (int i = 90; i >= 65; i--) {
        if (arr[i] >= Max1) p2 = i;
    }
    char c1 = (char)p1, c2 = (char)p2, c3 = (char)p3;
    string result = "";
    result += c1 + c2 + c3;
    return result;
}
int attack(const string input6[])
{
    int i = 0, count[10] = { 10,10,10,10,10,10,10,10,10,10 };
    while (i < 10) {
        if (input6[i].find("2") == -1) {
            count[i] = -1;
            break;
        }
        while (input6[i].find("1") != -1) {
            count[i]--;
        }
        i++;
    }
    int max = -2, pos = -1; i = 0;
    while (i < 10) {
        if (max < count[i]) {
            pos = i;
            max = count[i];
        }
    }
    if (max == -1) return -1;
    else return pos;
    return -1;
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int N7)
{
    return -1;
}

#endif /* MONGOL_H */
