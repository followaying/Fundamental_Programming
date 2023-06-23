/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2022
    * Author: Tran Huy
    * Date: 06.01.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef studyInPink_h
#define studyInPink_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

////////////////////////////////////////////////////////////////////////
///STUDENT'S ANSWER BEGINS HERE
///Complete the following functions
///DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
//Check HP in [0; 999]
int checkHP(int& HP) {
    if (HP > 999) HP = 999;
    else if (HP < 0) HP = 0;
    return HP;
}
//Check EXP in [0; 900]
int checkEXP(int& EXP) {
    if (EXP > 900) EXP = 900;
    else if (EXP < 0) EXP = 0;
    return EXP;
}
//Check M in [0; 200]
int checkM(int& M) {
    if (M > 2000) M = 2000;
    else if (M < 0) M = 0;
    return M;
}
//increase EXP with d
void increase(int& EXP1, int& EXP2, float d) {
    EXP2 += int(ceil(d));
    EXP1 += int(ceil(d / 3));
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
}
//Find Pink
bool LookingP(int& HP, int& EXP, int& M, int P[],int n, int E3) {
    for (int i = 1; i <= n; i++) {
        if (P[i - 1] == 80) {
            HP -= P[i - 1] * i * 2;
            EXP += (1000 - P[i - 1] * i) % 101;
            M = int(ceil(float(M) - i * float(E3) / 9));
            EXP = checkEXP(EXP);
            HP = checkHP(HP);
            M = checkM(M);
            return true;
        }
    }
    M = int(ceil(float(M) -n * n * float(E3) / 9));
    EXP = checkEXP(EXP);
    HP = checkHP(HP);
    M = checkM(M);
    return false;
}

int firstMeet(int& EXP1, int& EXP2, const int& E1) {
    //Complete this function to gain point on task 1
    if (E1 > 999 || E1 < 0) return -999;
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    if (E1 <= 399 && E1 >= 0) {
        if (E1 >= 0 && E1 <= 49) EXP2 += 25;
        else if (E1 >= 50 && E1 <= 99) EXP2 += 50;
        else if (E1 >= 100 && E1 <= 149) EXP2 += 85;
        else if (E1 >= 150 && E1 <= 199) EXP2 += 75;
        else if (E1 >= 200 && E1 <= 249) EXP2 += 110;
        else if (E1 >= 250 && E1 <= 299) EXP2 += 135;
        else if (E1 >= 300 && E1 <= 399)EXP2 += 160;
        (E1 % 2 == 0) ? EXP1 = int(ceil(float(EXP1) - float(E1) / 5)) : EXP1 = int(ceil(float(EXP1) + float(E1) / 10));
    }
    else  if (E1>=400 && E1<=999) {
        if (E1 >= 400 && E1 <= 499) EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
        else if (E1 >= 500 && E1 <= 599) EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
        else if (E1 >= 600 && E1 <= 699) EXP2 = int(ceil(float(EXP2) + float(E1) / 5 + 6));
        else if (E1 >= 700 && E1 <= 799) {
            EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
            EXP2 = checkEXP(EXP2);
            if (EXP2 > 200) EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
        }
        else if (E1 >= 800 && E1 <= 999) {
            EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
            EXP2 = checkEXP(EXP2);
            EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
            EXP2 = checkEXP(EXP2);
            if (EXP2 > 600) {
                EXP2 = int(ceil(float(EXP2) + float(E1) / 5 + 6));
                EXP2 = checkEXP(EXP2);
                EXP2 = int(ceil(float(EXP2) * 1.15));
            }
        }
        EXP1 = int(ceil(float(EXP1) -float(E1)*0.1));
    }
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    return EXP1 + EXP2;
}
int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2) {
    //Complete this function to gain point on task 2
    if (E2 > 999 || E2 < 0) return -999;
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    HP2 = checkHP(HP2);
    M2 = checkM(M2);
    //stage 1
    increase(EXP1, EXP2, float(E2) / 9 + 10);
    if (E2 >= 300 && E2 <= 999) {
        increase(EXP1, EXP2, float(E2) * 0.35);
        if (E2 >= 500 && E2 <= 999) increase(EXP1, EXP2, 0.17 * (float(E2) / 9 + 10 + float(E2) * 0.35));
    }
    //stage 2
    HP2 = int(ceil(HP2 - (pow(float(E2), 3) / pow(2, 23))));
    if (E2 % 2 == 0) M2 = int(M2 + ceil(pow(float(E2), 2) / 50));
    HP2 = checkHP(HP2);
    M2 = checkM(M2);
    return EXP2 + HP2 + M2 + EXP1;
}
int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3) {
    //Complete this function to gain point on task 3
    if (E3 > 999 || E3 < 0) return -999;
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkM(M1);
    bool find = false;
    //Street 1
    int P1[9] = {1, 3, 5, 7, 9, 11, 13, 15, 17}, i;
    for (i = 1; i <= 9; i++)  P1[i-1] = (P1[i-1] + E3) % 26 + 65;
    find = LookingP(HP1, EXP1, M1, P1, 9, E3);
    //Street 2
    int P2[7] = {2,3,5,7,11,13,17}, s = 0, m;
    for (i = 1; i <= 7; i++) {
        P2[i - 1] = (P2[i - 1] + E3) % 26;
        s += P2[i - 1];
    }
    m = int(ceil(float(s) / 7));
    for (i = 1; i <= 7; i++)  P2[i - 1] = (P2[i - 1] + s + m) % 26 + 65;
    bool finded = find;
    find = LookingP(HP1, EXP1, M1, P2, 7, E3);
    if (finded && !find) find = true;
    //Street 3
    int P3[20], max=-1, j =0;
    for (i = 2; j!=20; i++) if ((i * i) % 2 == 0) {
        P3[j] = i * i;
        j++;
    }// set up P3
    for (i = 1; i <= 20; i++) {//update 1
        P3[i - 1] = (P3[i - 1] + int(pow(E3, 2))) % 113;
        if (max < P3[i - 1]) max = P3[i - 1];
    }
    for (i=1;i<=20;i++) P3[i - 1] = int(ceil( float(P3[i - 1] + E3) / max)) % 26 + 65; // update 2 
    for (i = 1; i <=20; i++) if (P3[20-i] == 80) {
            HP1 -= P3[20 - i] * i * 3;
            EXP1 += (3500 - P3[20 - i] * i) % 300;
            M1 = ceil(M1 - i * float(E3) / 9);
            find = true;
            break;
    }//LookingP
    if (i == 21) M1 = int(ceil(M1 - 20 * 20 * float(E3) / 9));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkM(M1);
    //Street 4
    int P4[12] = { 31,28,31,30,31,30,31,31,30,31,30,31}, min, min_idx =1;
    for (i = 1; i <= 12; i++) { //update 1
        P4[i-1] = (P4[i-1] + int(pow(ceil(float(E3) / 29), 3))) % 9;
        if (i == 1) min = P4[i - 1];
        if (P4[i - 1] < min) {
            min = P4[i - 1];
            min_idx = i;
        }
    }
    for (i = 1; i <= 12; i++) P4[i - 1] = ((P4[i - 1] + E3) * int(ceil(float(min) / float(min_idx))))% 26 + 65; // update 2
    for (i = 1; i <= 12; i++) if (P4[12 - i] == 80) {
        HP1 -= P4[12 - i] * i * 4;
        EXP1 += (4500 - P4[12 - i] * i) % 400;
        M1 = int(ceil(M1 - i * float(E3) / 9));
        find = true;
        break;
    } //LookingP        
    if (i == 13) M1 = int(ceil(M1 - 12 * 12 * float(E3) / 9));
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkM(M1);
    if (!find) {//Unless finding
        HP1 -= ((59 * E3) % 900);
        EXP1 -= ((79 * E3) % 300);
        EXP1 = checkEXP(EXP1);
        HP1 = checkHP(HP1);
        M1 = checkM(M1);
        return -1;
    }
    return HP1 + EXP1 + M1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
