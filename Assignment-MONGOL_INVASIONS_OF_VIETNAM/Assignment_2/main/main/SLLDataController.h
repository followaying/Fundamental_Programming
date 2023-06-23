//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Singly Linked List
void print(SLinkedList& list) {
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head) {
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL" << endl;
}

bool insertAt(SLinkedList& list, Soldier element, int pos) {
    //Insert element into a pos in the SLL
    //Return true if insert successfully, false otherwise
    //TODO
    if (pos < 0 || pos > list.size) return false;
    SoldierNode* rev = new SoldierNode(element, NULL);
    if (list.size == 0) {
        if (pos == 0){
            list.head = rev;
            list.size+=1;
            return true;
        }
    }
    else if (list.size != 0) {
        int i = 0;
        SoldierNode* head = list.head;
        if (pos == 0) {  
            rev->next = list.head;
            list.head = rev;
            list.size += 1;
            return true;
        }
        else if (pos == list.size) { // add tail
            while (head->next != NULL) head = head->next;
            rev->next = head->next;
            head->next = rev;
            list.size += 1;
            return true;
        }
        else {
            while (i != pos - 1 && head->next != NULL) {
                i++;
                head = head->next;
            }
            if (i != pos - 1) return false;
            rev->next = head->next;
            head->next = rev;
            list.size += 1;
            return true;
        }
    }
    delete rev;
    return false;
}

bool removeAt(SLinkedList& list, int idx) {
    //Remove element at index idx in the SLL
    //Return true if remove successfully, false otherwise
    //TODO
        if (idx == 0 && list.size >0) {
            list.head = list.head->next;
            list.size -= 1;
            return true;
        }
        else if (idx == list.size - 1 && list.size > 1) {
            SoldierNode* head = list.head;
            while (head->next->next != NULL) head = head->next;
            head->next = head->next->next;
            list.size -= 1;
            return true;
        }
        else if (idx > 0 && idx < list.size && list.size>1) {
            int i = 0;
            SoldierNode* head = list.head, * rev = new SoldierNode;
            while (i != idx-1 && head->next != NULL ) {
                head = head->next;
                i++;
            }
            if (i != idx-1) return false;
            rev = head->next;
            head->next = head->next->next;
            rev = NULL;
            delete rev;
            list.size -= 1;
            return true;
        }
    return false;
}

bool removeFirstItemWithHP(SLinkedList& list, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    SoldierNode* head = list.head; 
    if (list.size > 0) {
        int pos=0;
        while (head != NULL && head->data.HP != HP) {
            head = head->next;
            pos += 1;
        }
        if (head == NULL) return false;
        if (removeAt(list, pos)) return true;
        else return false;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if (list.size > 0) {
        SoldierNode* head = list.head;
        int position = 0;
        if (head != NULL) {
            while (head != NULL) {
                if (head->data.HP == soldier.HP && head->data.ID == soldier.ID && head->data.isSpecial == soldier.isSpecial) break;
                head = head->next;
                position++;
            }
            if (head == NULL) return -1;
            return position;
        }
    }
    return -1;
}

int size(SLinkedList& list) {
    //Return size of the list
    //TODO
    if (list.size > 0) return list.size;
    return 0;
}

bool empty(SLinkedList& list) {
    //Check whether the list is empty
    //TODO
    if (list.size <= 0) return true;
    return false;
}

void clear(SLinkedList& list) {
    //Delete all of the elements in list
    //TODO
    if (list.size > 0) {
        SoldierNode* head = list.head, * rev = new SoldierNode;
        head = NULL;
        delete head;
        list.head = NULL;
        list.size = 0;
    }
}

string getIDAt(SLinkedList& list, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
    if (list.size == 1 && pos == 0) return head->data.ID;
    else if (list.size > 1 && pos >= 0 && pos < list.size) {
        int i = 0;
        while (i < pos && head != NULL) {
            head = head->next;
            i++;
        }
        if (head != NULL) return head->data.ID;
    }
    return "-1";
}

int getHPAt(SLinkedList& list, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    SoldierNode* head = list.head;
    if (list.size == 1 && pos == 0) return head->data.HP;
    if (list.size > 0 && pos < list.size && pos >= 0) {
        int i = 0;
        while (i < pos && head != NULL) {
            head = head->next;
            i++;
        }
        if (head != NULL) return head->data.HP;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (pos == 0 && list.size >= 1) {
        list.head->data.HP = HP;
        return true;
    }
    else if (pos > 0 && list.size > 1 && pos < list.size) {
        SoldierNode* head = list.head;
        int i = 0;
        while (i < pos && head != NULL) {
            head = head->next;
            i++;
        }
        head->data.HP = HP;
        return true; 
    }
    
    return false;
}

bool contains(SLinkedList& list, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    if (list.size > 0) {
        SoldierNode* head = list.head;
        while (head != NULL) {
            if (head->data.HP == soldier.HP && head->data.ID == soldier.ID && head->data.isSpecial == soldier.isSpecial) break;
            head = head->next;
        }
        if (head != NULL) return true;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* SLLDataControler_h */
#pragma once
