//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string input3);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
//int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////

int King(const string ID[], const int NID) {
    int i = 0;
    while( i < NID) {
        if (ID[i].find("VUA") == 0) return 1;
        else if (ID[i].find("THD") > 0 && ID[i].find("THD") < ID[i].size()-3) return 2;
        else i++;
    }
    if (i == NID - 1) return 0;
    return 0;
}
string binary(const string input1[], const int N1) {
    string newstr="";
    int i = 0;
    while (i < N1){
        int j = 0;
        while (j <= (int)input1[i].size()){
            if (input1[i][j] == ' ' && i < (int)(input1[i].size() - 1) && input1[i][j+1] != ' '){
                newstr += ' ';
                j--;
            }
            else if (input1[i][j] == '0' && input1[i][j + 1] == '0') newstr += '0';
            else if (input1[i][j] == '0' && input1[i][j + 1] == '1') newstr += '1';
            else if (input1[i][j] == '1' && input1[i][j + 1] == '0') newstr += '2';
            else if (input1[i][j] == '1' && input1[i][j + 1] == '1') newstr += '3';
            j+=2;
        }
        newstr += '|';
        i++;
    } 
    return newstr;
}
string c1(string newstr) {
    //@
    string s;
    while (true) {
        int p = newstr.find("@");
        if (p >= 0 && p < (int)newstr.size()) { // p ton tai
            if (p != (int)newstr.size() - 1) {
                int i = p + 1;
                while (newstr[i] >= 'A' && newstr[i] <= 'Z') i++;
                if (i > p + 1) {// ton tai ascii o giua
                    s.clear();
                    int j = i - 1;
                    while (j >= p + 1) {
                        s += newstr[j];
                        j--;
                    }
                    newstr.replace(p + 1, s.size(), s);
                }
            }
            newstr.erase(p, 1);
        }
        else break;
    }
    return newstr;
}
string c2(string newstr) {
    string rev=""; 
    while (true) {
        int p = newstr.find("#"); rev = newstr; cout << newstr << endl;
        if (p >= 0 && p < (int)newstr.size()) { // p exist
            if (p != (int)newstr.size() - 1) { //p not at the end
                int i = p + 1;
                while (newstr[i] >= 'A' && newstr[i] <= 'Z') i++;
                if (i - p == 1) newstr.erase(p, 1);
                else{
                    rev.erase(i, rev.length() - 1); rev.erase(0, p + 1);
                    if (i > p + 1){   // from p to i has ascii
                        if (rev[rev.length() - 1] == 'Z') rev += 'A';
                        else rev += (rev[rev.length() - 1] + 1);
                    }
                    newstr.replace(p, rev.length(), rev);
                }
            }
        }
        else break;
    }
    return newstr;
}
string syn(string str) {
    string rev = "", rev1, newstr = "", str0 = "EFGHIJK", str1 = "LMNOPQR", str2 = "#TUVWXY", str3 = "@ASZBCD";
    int i = 0, r;
    while (i < (int)str.size()) {
        int j = i;
        while (str[j] != ' ' && str[j] != '|') {
            rev += str[j];
            j++;
        }// out rev
        if ((int)rev.size() % 7 == 0) r = 7;
        else r = (int)rev.size() % 7;
        if (str[i] == '0') newstr += str0[r - 1];
        else if (str[i] == '1') newstr += str1[r - 1];
        else if (str[i] == '2') newstr += str2[r - 1];
        else if (str[i] == '3') newstr += str3[r - 1];
        if (str[j] == '|') newstr += '|';
        i = j + 1;
        rev.clear();  
    }
    int f1 = newstr.find('@'), f2 = newstr.find('#');
    if (f1 < f2 && f1 != -1) {
        //@ 
        newstr = c1(newstr);
        //#
        newstr = c2(newstr);
    }
    else if (f1 > f2 && f2 != -1) {
        //#
        newstr = c2(newstr);
        //@
        newstr = c1(newstr);
    }
    else if (f1 != -1 && f2 == -1) newstr = c1(newstr);
    else if (f2 != -1 && f1 == -1) newstr = c2(newstr);
    // delete
    while (true) {
        int a = newstr.find("@");
        if (a >= 0 && a < (int)newstr.size()) {
            if (newstr[a - 1] == '|') {
                newstr.erase(newstr.find('@'), 1);
                newstr.erase(a-1, 1);
            }
            newstr.erase(newstr.find('@'), 1);
        }    
        else break;
    }
    while (true) {
        int b = newstr.find("#");
        if (b >= 0 && b < (int)newstr.size()) newstr.erase(newstr.find('#'), 1); 
        else break;
    }
    return newstr;
}
bool odd(int n) {
    if (n % 2 == 1) return true;
    else return false;
}
string converse(string str) {
    if (odd((int)str.size())){
        reverse(str.begin(), str.end());
        return str;
    }
    else {
        string newstr = "";
        int i = (int)str.size()-1;
        while (i > 0) {
            newstr += str[i - 1]; newstr += str[i];
            i -= 2;
        }
        return newstr;
    }
}
string conver(string str) {
    string newstr, rev;
    int i = 0;
    while (i < (int)str.size()) {
        if (str[i] == '|') {
            newstr += converse(rev);
            newstr += '|';
            rev.clear();
        }
        else if (i == (int)str.size()-1) newstr += converse(rev);
        else rev += str[i];
        i++;
    }
    return newstr;
}
string competion(string str,string Str) {
    string newstr; 
    int i = 0;
    while (i < (int)str.size()) {
        if (str[i] == '|') newstr+= '|';
        else {
            if (str[i] > Str[i]) newstr += str[i];
            else newstr += Str[i];
        }
        i++;
    }
    return newstr;
}
string delete3(string str) {
    if (str.size() == 1) {
        str.clear();
        return str;
    }
    string newstr;
    int i = 0;
    while (i < (int)str.size()) {
        if (i % 3 != 0) newstr += str[i];
        i++;
    }
    return newstr;
}
string Delete(string str) {
    string newstr, rev;
    int i = 0;
    while (i < (int)str.size()) {
        if (str[i] == '|') {
            newstr += delete3(rev);
            rev.clear();
            newstr +='|';
        }
        else if (((int)rev.size() == 1) && (i == ((int)str.size() - 1))) return newstr;
        else if (i == ((int)str.size() - 1)) newstr += delete3(rev);
        else rev += str[i];
        i++;
    }
    return newstr;
}
string tran(string str) {
    if ((int)str.size() == 1) {
        return str;
     }
    char rev; int i = 0;
    while (i < (int)str.size() - 1) {
        int j = i + 1;
        while (j < (int)str.size()) {
            if (str[i] > str[j]) {
                rev = str[i];
                str[i] = str[j];
                str[j] = rev;
            }
            j++;
        }
        i++;
    }
    return str;
}
string ASCII(string str) {
    string newstr, rev;
    int i = 0;
    while (i < (int)str.size()) {
        if (str[i] == '|') {
            newstr += tran(rev);
            newstr += str[i];
            rev.clear();
        }
        else if (i == (int)str.size() - 1) newstr += rev;
        else rev += str[i];
        i++;
    }
    return newstr;
}

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1){
    string newstr = binary(input1, N1);
    newstr = syn(newstr);
    if (King(ID, NID) == 1) {
        string rev = newstr;
        newstr = conver(newstr);
        newstr = competion(rev, newstr);
    }
    else if (King(ID, NID) == 2) {
        newstr = Delete(newstr);
        newstr = ASCII(newstr); 
    }
    while ((int)newstr.find("|") != -1) {
        newstr.replace((int)newstr.find('|'), 1, " ");
    }
    newstr.pop_back();
    return newstr;
 }


int decode(const string A, const string B)
{
    int counting = 0, i = 0;
    string rev = "";
    while (i <= (int)A.size() - (int)B.size()) {
        int j = 0;
        while (j < (int)B.size()) {
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
string findRoute(const string input3)
{
    string N1, B1, S, result="";
    int i = 0, x = 0, y = 0;
    while (input3[i] != ' ') { // find int of N
        N1 += input3[i];
        i++;
    }
    int N = atoi(N1.c_str());
    i++;
    while (input3[i] != ' ') {// find int of B
        B1 += input3[i];
        i++;
    }
    int B = atoi(B1.c_str());
    i++;

    while (i < (int)input3.size()) {// find string of S
        S += input3[i];
        i++;
    }
    i = 0;
    if (B < 0) {// S in the frist time change
        while (i < -B) {
            S += S[0];
            S.erase(0, 1);
            i++;
        }
    }
    else if (B > 0) {
        while (i < B) {
            S.insert(0, 1, S[(int)S.size() - 1]);
            S.erase((int)S.size() - 1, 1);
            i++;
        }
    }
    i = 0; // S in the second time change
    while (i < (int)S.size()) {
        int a = abs(N - 2 * i);
        while (a > 0) {
            if (S[i] == 'U') S[i] = 'D';
            else if (S[i] == 'D')S[i] = 'L';
            else if (S[i] == 'L')S[i] = 'R';
            else if (S[i] == 'R')S[i] = 'U';
            a--;
        }
        i++;
    }
    i = 0;
    while (i < (int)S.size()) {
        if (S[i] == 'U') ++y;
        else if (S[i] == 'D') --y;
        else if (S[i] == 'R') ++x;
        else if (S[i] == 'L') --x;
        i++;
    }
    result = "(,)";
    result.insert(1, to_string(x));
    result.insert(2 + ((int)(to_string(x)).size()), to_string(y)); // a string with format (x,y)
    return result;
}
string decodeVfunction(const string A, const string B)
{
    int V1 = 0, V2 = 0;
    string result;
    for (int i = 0; i < (int)A.size() - 1; i++) {
        if (A[i] == 'V') V1++;
    }
    for (int i = 0; i < (int)B.size() - 1; i++) {
        if (B[i] == 'V') V2++;
    }
    int V = V1 * V2;
    result = "0";
    for (int i = 1; i <= V; i++) {
        result.insert(0, "V(");
        result.insert((int)result.size(), ")");
    }
    return result;
}
string findBetrayals(const string input5[], const int N5)
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int arr[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int i = 0;
    while (i < N5) {
        int j = 0;
        while (j < 6){
            arr[str.find(input5[i][j])] += 6 - j;
            j++;
        }
        i++;
    }
    int p1 = 0, p2 = 0, p3 = 0,Max =0;
    i = 25; 
    while (i >= 0) {
        if (arr[i] >= Max) {
            p1 = i;
            Max = arr[i];
        }
        i--;
    }
    arr[p1] = -1; Max = 0;
    i = 25; 
    while( i >= 0) {
        if (arr[i] >= Max){
            p2 = i;
            Max = arr[i];
        }
        i--;
    }
    arr[p2] = -1; Max = 0;
    i = 25; 
    while (i >= 0){
        if (arr[i] >= Max) {
            p3 = i;
            Max = arr[i];
        }
        i--;
    }
    string result = "";
    result += str[p1]; result += str[p2]; result += str[p3];
    return result;
}
int attack(const string input6[])
{
    int i = 0, count[10] = {10,10,10,10,10,10,10,10,10,10 };
    while (i < 10) {
        if (input6[i].find('2') >=0 && input6[i].find('2') < 10) {
            count[i] = -1;
        }
        else {
            string rev = input6[i];
            while (true) {
                if (rev.find('1') >= 0 && rev.find('1') < 10) {
                    count[i]--;
                    rev.erase(rev.find('1'), 1);
                }
                else break;
            }
        }
        i++;
    }
    int max = -2, pos = -1; i = 0;

    while (i < 10) {
        if (max <= count[i]) {
            pos = i;
            max = count[i];
        }
        i++;
    }
    if (max == -1) return -1;
    else return pos;
    return -1;
}
void productarr(int N7,int B[100][100], int A1[100][100], int A2[100][100]) {
    int i = 0;
    while (i < N7) {
        int k = 0;
        while (k < N7 ) {     

            B[i][k] = 0;
            int j = 0;
            while (j < N7 ) {
                B[i][k] += (A1[i][j] * A2[j][k]);
                j++;
            }
            k++;
        }
        i++;
    }
}
void stringtoarr(string s, int N7, int arr[100][100]) {
    int a = 0, i = 0, j = 0, b;
    string rev;
    while (a < (int)s.size() + 1) {
        if (s[a] == ' ' || a == (int)s.size()) {
            b = atoi(rev.c_str()); 
            arr[i][j] = b;
            if (j == N7 - 1) {
                j = 0;
                i++;
            }
            else j++;
            rev.clear();
        }
        else rev += s[a];
        a++;

    }
}
void check(int arr[100][100], int N7) {
    int i = 0;
    while (i < N7) {
        int j = 0;
        while (j < N7) {
            cout << arr[i][j] << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    cout << "-------" << endl;

}
void change(int A[100][100], int B[100][100], int N7) {
    int i = 0;
    while (i < N7) {
        int j = 0;
        while (j < N7) {
            B[i][j] = A[i][j];
            j++;
        }
        i++;
    }
}
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int k)
{
    string n7="", v="", I, J;
    int m = 0;
    while (input7Str[m] != ' ') {
        n7 += input7Str[m];
        m++;
    }
    m++;
    while (input7Str[m] != ' ') {
        v += input7Str[m];
        m++;
    }
    m++;
    while (input7Str[m] != ' ') {
        I += input7Str[m];
        m++;
    }
    m++;
    while (m < (int)input7Str.size()) {
        J += input7Str[m];
        m++;
    }
    int N7 = atoi(n7.c_str()), V = atoi(v.c_str()), i = atoi(I.c_str()), j = atoi(J.c_str());
    int arr0[100][100], arr1[100][100], result[100][100];
    m = 1;
    stringtoarr(input7Matrix[0], N7, arr0);
    while (m < k) {
        stringtoarr(input7Matrix[m], N7, arr1);
        productarr(N7, result, arr0, arr1);
        change(result, arr0, N7);
        m++;
    }
    int R = abs(result[i][j] % V);
    return R;
    return -1;
}

#endif /* MONGOL_H */
