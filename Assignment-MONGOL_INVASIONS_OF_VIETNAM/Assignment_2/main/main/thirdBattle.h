//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier) {
    //Return true if push successfully, false otherwise
    //TODO
    if (array.size == 0) {
        array.capacity = 100;
        Soldier* newarray = new Soldier[array.capacity];
        newarray->HP = soldier.HP;
        newarray->ID = soldier.ID;
        newarray->isSpecial = soldier.isSpecial;
        array.arr = newarray;
        array.size += 1;
        return true;
    }
    
    if (array.size > 0 && array.capacity > array.size) {
        for (int n = array.size; n > 0; n--) array.arr[n] = array.arr[n - 1];
        array.arr[0].HP = soldier.HP;
        array.arr[0].ID = soldier.ID;
        array.arr[0].isSpecial = soldier.isSpecial;
        array.size += 1;
        return true;
    }
    return false;
}

bool pop(Array& array) {
    //Return true if pop successfully, false otherwise
    //TODO
    if (array.size > 0) {
        for (int n = 0; n < array.size - 1; n++) array.arr[n] = array.arr[n + 1];
        array.size -= 1;
        return true;
    }
    return false;
}

Soldier top(Array& array) {
    //TODO
    if (array.size > 0) return array.arr[0];
    return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier) {
    //Return true if enqueue successfully, false otherwise
    //TODO
    SoldierNode *head = list.head, * rev = new SoldierNode(soldier, NULL);
    if (list.size==0) {
        list.head = rev;
        list.size += 1;
        rev = NULL;
        delete rev;
        return true;
    }
    if (list.size>0){
        while (head->next != NULL) head = head->next;
        head->next = rev;
        rev = NULL; 
        delete rev;
        list.size += 1;
        return true;
    }
    return false;
}

bool dequeue(SLinkedList& list) {
    //Return true if dequeue successfully, false otherwise
    //TODO
    if (list.size>0) {
        SoldierNode* head = list.head;
        list.head = list.head->next;
        list.size -= 1;
        return true;
    }
    return false;
}

Soldier front(SLinkedList& list) {
    //TODO
    SoldierNode* head = list.head, * rev = head;
    if (list.size>0) return head->data;
    return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list) {
    if (list.size > 1) {
        SoldierNode* head = list.head, * rev = new SoldierNode, * newlist = new SoldierNode();
        while (head != NULL) {
            rev = head->next;
            head->next = newlist;
            newlist = head;
            head = rev;
        }
        head = list.head;
        while (head->next->next != NULL) head = head->next;
        rev = head->next;
        head->next = NULL;
        delete rev;
        list.head = newlist;   
    }
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////


SLinkedList merge(SLinkedList& list1, SLinkedList& list2) {
    //TODO
    if (list1.size == 0 && list1.size != 0) return list2;
    else if (list1.size != 0 && list2.size == 0) return list1;
    else if (list1.size > 0 && list2.size > 0) {
        SLinkedList newlist;
        newlist.size = list1.size + list2.size;
        newlist.head = new SoldierNode(*new Soldier(0, 0, "M"), NULL);
        SoldierNode* head = newlist.head, * head1 = list1.head, * head2 = list2.head;
        while (head1 != NULL && head2 != NULL) {
            if (head2->data.HP < head1->data.HP) {
                SoldierNode* rev = new SoldierNode(head2->data, NULL);
                head->next = rev;
                head = head->next;
                head2 = head2->next;
                rev = NULL;
                delete rev;

            }
            else if (head2->data.HP == head1->data.HP) {
                if (head2->data.isSpecial < head1->data.isSpecial) {
                    SoldierNode* rev = new SoldierNode(head2->data, NULL);
                    head->next = rev;
                    head = head->next;
                    head2 = head2->next;
                    rev = NULL;
                    delete rev;
                }
                else if (head2->data.isSpecial == head1->data.isSpecial) {
                    if (head2->data.ID <= head1->data.ID) {
                        SoldierNode* rev = new SoldierNode(head2->data, NULL);
                        head->next = rev;
                        head = head->next;
                        head2 = head2->next;
                    }
                    else {
                        SoldierNode* rev = new SoldierNode(head1->data, NULL);
                        head->next = rev;
                        head = head->next;
                        head1 = head1->next;
                        rev = NULL;
                        delete rev;
                    }
                }
                else {
                    SoldierNode* rev = new SoldierNode(head1->data, NULL);
                    head->next = rev;
                    head = head->next;
                    head1 = head1->next;
                    rev = NULL;
                    delete rev;
                }
            }
            else {
                SoldierNode* rev = new SoldierNode(head1->data, NULL);
                head->next = rev;
                head = head->next;
                head1 = head1->next;
                rev = NULL;
                delete rev;
            }

        }
        if (head1 == NULL && head2 != NULL) {
            head = newlist.head;
            while (head->next != NULL) head = head->next;
            head->next = head2;
        }
        else if (head2 == NULL && head1 != NULL) {
            head = newlist.head;
            while (head->next != NULL) head = head->next;
            head->next = head1;
        }
        newlist.head = newlist.head->next;
        return newlist;
    }

    
    return SLinkedList();
}

//You can write your own functions here

//End your own functions

#endif /* thirdBattle_h */
