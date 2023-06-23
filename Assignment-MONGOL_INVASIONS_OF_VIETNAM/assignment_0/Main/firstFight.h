/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Nguyen Thanh Nhan
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

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

int result,HP1_1,HP2_1;
int checkHP(int& HP) {
    if (HP < 0) HP = 0;
    else if (HP > 1000) HP = 1000;
    return HP;
}
int checkM(int& M) {
    if (M < 0) M = 0;
    else if (M > 1000) M = 1000;
    return M;
}
bool prime(int a) {
    int s = 0;
    if (a == 1 || a == 0) return 0;
    else {
        for (int i = 2; i < a; i++) if (a % i == 0) s++;
        if (s == 0) return 1;
        else return 0;
    }
}
int getReady(int& HP, const int& ID, int& M, const int& E1) {
    //Complete this function to gain point on task 1
    checkHP(HP); checkM(M);
    //case 1
    if (E1 <= 199 && E1 >= 100) {
        int h = (E1 - 100) % 64;
        int j = HP % 100;
        int WP=0;
        if (M % 2 == 1 && HP >= 500) WP = 1;
        else if (M % 2 == 0) WP = 2;
        switch (ID) {
        case 0: {
            if (j > h) {
                switch (WP) {
                case 1: {
                    if (M >= 300) {
                        HP += 50;
                        M -= 300;
                    }
                    break;
                }
                case 2: {
                    if (M >= 200) {
                        HP += 25;
                        M -= 200;
                    }
                    break;
                }
                }
            }
            break;
        }
        case 1: {
            HP += 75;
            break;
        }
        }
    }
    // case 2
    else if (E1 <= 299 && E1 >= 200) {
        int x = E1 % 4 + 1;
        if (ID == 0) {
            if (M % 2 == 0) {
                switch (x) {
                case 1:
                case 3:
                    break;
                case 2:
                    if (M >= 195) {
                        M -= 195;
                        HP += 7;
                    }
                    break;
                case 4:
                    if (M >= 205) {
                        M -= 205;
                        HP += 11;
                    }
                    break;
                }

            }
            else {
                switch (x) {
                case 2:
                case 4:
                    break;
                case 1:
                    if (M >= 190) {
                        M -= 190;
                        HP += 5;
                    }
                    break;
                case 3:
                    if (M >= 200) {
                        M -= 200;
                        HP += 9;
                    }
                    break;
                }
            }
        }
        else {
            switch (x) {
            case 1:
                if (M >= 190) {
                    M -= 190;
                    HP += 5;
                }
                break;
            case 2:
                if (M >= 195) {
                    M -= 195;
                    HP += 7;
                }
                break;
            case 3:
                if (M >= 200) {
                    M -= 200;
                    HP += 9;
                }
                break;
            case 4:
                if (M >= 205) {
                    M -= 205;
                    HP += 11;
                }
                  break;
            }
        }
    }
    //case 3
    else if (E1 <= 399 && E1 >= 300) {
        int a;
        if (prime(E1 % 10) == 1)  a = 2 * (E1 % 10);
        else a = 1;
        if (HP >= 600) {
            if (prime(HP % 10) == 1) {
                if (M >= 500) {
                    if (ID == 1) {
                        M -= 500;
                        HP += 200;
                    }
                    else {
                        M -= 500;
                        HP = ceil(float(HP) * (1 + 2 * float(a) / 100));
                    }
                }
            }
            else {
                if (M >= 300) {
                    M -= 300;
                    HP = ceil(float(HP) * (1 + float(a) / 100));
                }
            }

        }
    }
    //case 4
    else if (E1 <= 499 && E1 >= 400)
    {
        if (E1 % 5 == 0) HP = (int)ceil(float(HP) * 0.9);
    }
    //case 5
    else if (E1 == 500) {
        HP = (int)ceil(float(HP) * 0.75);
        M = (int)ceil(float(M) * 0.75);
    }
    else return -999;
    checkHP(HP); checkM(M);
    return  HP + M;
    return -1;
}
void variable(int& HP1, int& HP2) {
    checkHP(HP1); checkHP(HP2);
    int u = ceil(float(2 * HP1 * HP2) / float(HP1 + HP2));
    HP1 -= abs(HP2 - u);// HP1 after.
    HP2 -= abs((HP1 + abs(HP2 - u)) + -u); //HP1 before is 'HP1 after' add (float)abs(HP2 - u). 
}
//To determine if win or not
int win_or_not(int& HP1, int& HP2, const int& ID1, const int& ID2) {
     // both teams without leaders
    if (HP1 <= 0)           return -1;
    else if (HP2 <= 0)      return  1;
    else if (HP1 > HP2)     return 1;
    else if (HP1 == HP2)    return 0;
    else if (HP1 < HP2)     return -1;
    return -1;
}
int check_leader_win_or_not(int& HP1, int& HP2, const int& ID1, const int& ID2) {
    if (ID1 == 1 && ID2 == 2) return 0;
    else if (ID1 == 1 && ID2 == 0) {
        if (win_or_not != 0)
        {
            HP2 = 0;
            return 1;
        }
    }
    else if (ID1 == 0 && ID2 == 2) {
        if (win_or_not != 0)
        {
            HP1 = 0;
            return -1;
        }
    }
    else return -999;
    return -1;
}
int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2) {
    //Complete this function to gain point on task 2
    checkHP(HP1); checkHP(HP2);
    if (E2 <= 199 && E2 >= 100) {
        HP2 = ceil(float(HP2) * 1.3);
        HP1 = ceil(float(HP1) * 1.1);
        checkHP(HP1); checkHP(HP2);
        result= check_leader_win_or_not(HP1, HP2, ID1, ID2);
        if (result == -999) {
            variable(HP1, HP2);
            checkHP(HP1); checkHP(HP2);
            result = win_or_not(HP1, HP2, ID1, ID2);
        }
        HP1 = ceil(float(HP1) * 0.8);
        checkHP(HP1); checkHP(HP2);
        return result;
    }
    else if (E2 <= 299 && E2 >= 200) {
        HP1 = ceil(float(HP1) * 1.7);
        HP2 = ceil(float(HP2) * 1.2);
        checkHP(HP1); checkHP(HP2);
        result = check_leader_win_or_not(HP1, HP2, ID1, ID2);
        if (result == -999) {
            variable(HP1, HP2);
            checkHP(HP1); checkHP(HP2);
            result = win_or_not(HP1, HP2, ID1, ID2);
        }
        HP1 = ceil(float(HP1) * 0.8);
        checkHP(HP1); checkHP(HP2);
        return result;
    }
    else if (E2 <= 399 && E2 >= 300) {
        if (E2 < 350) HP1 += 30;
        else HP1 += (E2 % 100);
        checkHP(HP1);
        result = check_leader_win_or_not(HP1, HP2, ID1, ID2);
        if (result == -999) {
            variable(HP1, HP2);
            checkHP(HP1); checkHP(HP2);
            result = win_or_not(HP1, HP2, ID1, ID2);
        }
        HP1 = ceil(float(HP1) * 0.8);
        checkHP(HP1); checkHP(HP2);
        return result;
    }
    else if (E2 <= 499 && E2 >= 400) {
        HP1 = ceil(float(HP1) * 1.3);
        HP2 = ceil(float(HP2) * 0.8);
        checkHP(HP1); checkHP(HP2);
        HP1 = ceil(float(HP1) * 0.5); 
        checkHP(HP1);
        result = check_leader_win_or_not(HP1, HP2, ID1, ID2);
        if (result == -999) {
            variable(HP1, HP2);
            checkHP(HP1); checkHP(HP2);
            result = win_or_not(HP1, HP2, ID1, ID2);
        }
        HP1 = ceil(float(HP1) * 0.8);
        checkHP(HP1); checkHP(HP2);
        return result;
    }
    else return -999;
    return -1;
}
int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3) {
    //Complete this function to gain point on task 3
    checkHP(HP1); checkHP(HP2);
    if (E3 >= 100 && E3 <= 199) {
        HP1 = ceil(float(HP1) * 1.4);
        if (ID1 == 1 ) HP1 *= 2;
        HP2 = ceil(float(HP2) * 1.6);
        checkHP(HP1); checkHP(HP2);
        HP1_1 = HP1;
        if (ID2 == 0) HP2 = ceil(float(HP2) * 0.95);
        result = check_leader_win_or_not(HP1, HP2, ID1, ID2);
        if (result == -999) {
            variable(HP1, HP2);
            checkHP(HP1); checkHP(HP2);
            result = win_or_not(HP1, HP2, ID1, ID2);
        }
        if (result == -1) HP1 = HP1_1;
    }
    else if (E3 >= 200 && E3 <= 299) {
        HP1 = ceil(float(HP1) * 1.4);
        if (ID1 == 1) HP1 *= 2;
        HP2 = ceil(float(HP2) * 1.6);
        checkHP(HP1); checkHP(HP2);
        if (ID2 == 0) HP2 = ceil(float(HP2) * 0.95);
        result = 0;
    }
    else result = -999;
    checkHP(HP1); checkHP(HP2);
    return result;
    return -1;
}
int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4) {
    //Complete this function to gain point on task 4
    checkHP(HP1); checkHP(HP2);
    if (E4 >= 100 && E4 <= 199) {
        if (ID2 == 2) HP2 = ceil(float(HP2) * 0.3);
        else HP2 = ceil(float(HP2) * 0.1);
        result = 0;
    }
    else if (E4 >= 200 && E4 <= 299) {
        HP2 = 0;
        result = 1;
    }
    else result = -999;
    checkHP(HP1); checkHP(HP2);
    return result;
    return -1;
}
////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* firstFight_h */


