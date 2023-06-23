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
int checkHP(int& HP) {
    if (HP > 999) HP =999;
    if else (HP < 0) HP = 0;
    return HP;
}
int checkEXP(int& EXP) {
    if (EXP > 900) EXP = 900;
    if else (EXP < 0) EXP = 0;
    return EXP;
}
int checkM(int& M) {
    if (M > 200) HP = 200;
    if else (M < 0) M = 0;
    return M;
}
int checkE(int& E) {
    if (E > 999) E = 999;
    if else (E < 0) E = 0;
    return E;
}

int firstMeet(int& EXP1, int& EXP2, const int& E1){
    //Complete this function to gain point on task 1
    E1 = checkE(E1);
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    if (E1 <= 399 && E1 >= 0) {
        if (E1 >= 0 && E1 <= 49) EXP2 += 25;
        else if (E1 >= 50 && E1 <= 99) EXP2 += 50;
        else if (E1 >= 100 && E1 <= 149) EXP2 += 85;
        else if (E1 >= 150 && E1 <= 199) EXP2 += 75;
        else if (E1 >= 200 && E1 <= 249) EXP2 += 110;
        else if (E1 >= 250 && E1 <= 299) EXP2 += 135;
        else EXP2 += 160;
        (E1 % 2 == 0) ? EXP1 = int(ceil(float(EXP1)- float(E1) / 5)) : EXP1 = int(ceil(float(EXP1) + float(E1) /10));
    }
    else if (E1 <= 999 && E1 >= 400) {
        if (E1 >= 400 && E1 <= 499) EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
        else if (E1 >= 500 && E1 <= 599) EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
        else if (E1 >= 600 && E1 <= 699) EXP2 = int(ceil(float(EXP2) + float(E1) / 5 + 6));
        else if (E1 >= 700 && E1 <= 799) {
            EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
            EXP2 = checkEXP(EXP2);
            if (EXP2 > 200) EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
        }
        else {
            EXP2 = int(ceil(float(EXP2) + float(E1) / 7 + 9));
            EXP2 = checkEXP(EXP2);
            EXP2 = int(ceil(float(EXP2) + float(E1) / 9 + 11));
            EXP2 = checkEXP(EXP2);
            if (EXP2 > 600) {
                EXP2 = int(ceil(float(EXP2) + float(E1) / 5 + 6));
                EXP2 = checkEXP(EXP2);
            }
            EXP2 = int(ceil(float(EXP2) * 1.15));
        }
        EXP1 = int(ceil(float(EXP1) * 0.9));
    }
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    return EXP1 + EXP2;
}

int investigateScene(int& EXP1, int& EXP2, int& HP2, int& M2, const int& E2){
    //Complete this function to gain point on task 2
    E2 = checkE(E2);
    EXP1 = checkEXP(EXP1);
    EXP2 = checkEXP(EXP2);
    HP2 = checkHP(HP2);
    M2 = checkM(M2);
    //stage 1
    if (E2 >= 0 && E2 <= 299) {

    }
    else if (E2 >= 300 && E2 <= 499) {

    }
    else {

    }
    //stage 2

    return -1;
}

int traceLuggage(int& HP1, int& EXP1, int& M1, const int& E3){
    //Complete this function to gain point on task 3
    E3 = checkE(E3);
    EXP1 = checkEXP(EXP1);
    HP1 = checkHP(HP1);
    M1 = checkM(M1);

    return -1;
}

////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */
