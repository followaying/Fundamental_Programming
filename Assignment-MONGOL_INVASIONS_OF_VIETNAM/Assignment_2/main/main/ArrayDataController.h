//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array) {
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout << "[";
    for (int i = 0; i < array.size; i++) {
        std::cout << array.arr[i].ID << " ";
    }
    std::cout << "]" << endl;
}

void initArray(Array& array, int cap) {
    //Init a new array with capacity equals to cap
    //TODO
    array.capacity = cap;
}

void ensureCapacity(Array& array, int newCap) {
    //Extend the capacity of the array
    //TODO
    array.capacity = newCap * 1.5;
}

bool insertAt(Array& array, Soldier element, int pos) {
    //Insert element into a pos in the array
    //Return true if insert successfully, false otherwise
    //TODO
    if (array.arr != NULL && array.size >= array.capacity) ensureCapacity(array, array.capacity);
    if (pos == 0 && array.size == 0 && array.capacity >0) {
        Soldier *newarray = new Soldier[array.capacity];
        newarray->HP = element.HP;
        newarray->ID = element.ID;
        newarray->isSpecial = element.isSpecial;
        array.arr = newarray;
        array.size += 1;
        return true;
    }
    else if (pos == array.size && array.size > 0) {
        array.arr[array.size] = element;
        array.size += 1;
        return true;
    }
    else if (pos >= 0 && pos<array.size && array.size > 0) {
        for (int n = array.size; n > pos; n--) array.arr[n] = array.arr[n - 1];
        array.arr[pos].HP = element.HP;
        array.arr[pos].ID = element.ID;
        array.arr[pos].isSpecial = element.isSpecial;
        array.size += 1;
        return true;
    }
    return false;
}

bool removeAt(Array& array, int idx) {
    //Remove element at index idx in the array
    //Return true if remove successfully, false otherwise
    //TODO
    if (array.size > 0 && idx >= 0 && idx < array.size) {
        for (int n = idx; n < array.size - 1; n++) array.arr[n] = array.arr[n + 1];
        array.size -= 1;
        return true;
    }
    return false;
}

bool removeFirstItemWithHP(Array& array, int HP) {
    //Remove the first element with HP equals to HP
    //Return true if remove successfully, false otherwise
    //TODO
    if (array.size > 0) {
        int n = 0;
        while (array.arr[n].HP != HP && n < array.size) {
            n++;
        }
        if (n < array.size) {
            removeAt(array, n);
            return true;
        }
    }
    return false;
}

int indexOf(Array& array, Soldier soldier) {
    //Find index of soldier (start from 0)
    //Return -1 if the soldier does not exist
    //TODO
    if (array.size > 0) {
        int n = 0;
        while (n < array.size) {
            if (array.arr[n].HP == soldier.HP && array.arr[n].ID == soldier.ID && array.arr[n].isSpecial == soldier.isSpecial) return n;
            n++;
        }
        return -1;
    }
    return -1;
}

int size(Array& array) {
    //Return size of the array
    //TODO
    if (array.size >= 0) return array.size;
    return -1;
}

bool empty(Array& array) {
    //Check whether the array is empty
    //TODO
    if (array.size <= 0) return true;
    return false;
}

string getIDAt(Array& array, int pos) {
    //Get ID of the Soldier at pos
    //TODO
    if (array.size > 0 && pos >= 0 && pos < array.size) return array.arr[pos].ID;
    return "-1";
}

int getHPAt(Array& array, int pos) {
    //Get HP of the Soldier at pos
    //TODO
    if (array.size > 0 && pos >= 0 && pos < array.size) return array.arr[pos].HP;
    return -1;
}

bool setHPAt(Array& array, int HP, int pos) {
    //Set value of HP at pos
    //TODO
    //Return true if set successfully, false otherwise
    if (array.size > 0 && pos >= 0 && pos < array.size) {
        array.arr[pos].HP = HP;
        return true;
    }
    return false;
}

void clear(Array& array) {
    //Delete all of the elements in array
    //TODO
    delete[] array.arr;
    array.size = 0;
    array.capacity = 0;
    array.arr = NULL;
}

bool contains(Array& array, Soldier soldier) {
    //Check if array contains soldier
    //TODO
    if (array.size > 0) {
        for (int n = 0; n < array.size; n++) {
            if (array.arr[n].HP == soldier.HP && array.arr[n].ID == soldier.ID && array.arr[n].isSpecial == soldier.isSpecial) return true;
        }
        return false;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
#pragma once
