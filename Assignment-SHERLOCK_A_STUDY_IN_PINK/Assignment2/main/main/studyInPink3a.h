/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
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

class Point {
private:
    int x;
    int y;
public:
    Point(int x = 0, int y = 0) :x(x), y (y) {}
    string toString() const;
    int distanceTo(const Point& otherPoint) const;
    int getX() { return this->x; }
    int getY() { return this->y; }
};
class Node {
private:
    Point point;
    Node* next;
    friend class Path;
public:
    Node(const Point& point = Point(), Node* next = NULL): point(point), next(next){}
    string toString() const;
};
class Path {
private:
    Node* head;
    Node* tail;
    int count;
    int length;

public:
    Path() : head(nullptr), tail(nullptr), count(0), length(-1){}
    ~Path();
    void addPoint(int x, int y);
    string toString() const;
    Point getLastPoint() const;
    int getLength() const;
};
class Character {
private:
    string name;
    Path* path;
public:
    Character(const string& name = "") {
        this->name = name;
        this->path = new Path;
    }
    ~Character() {}
    string getName() const;
    void setName(const string& name);
    void moveToPoint(int x, int y);
    string toString() const;
    Path* getPath() const;
};
bool rescueSherlock(
    const Character& chMurderer,
    const Character& chWatson,
    int maxLength,
    int maxDistance,
    int& outDistance){
    if (chWatson.getPath()->getLength() - chMurderer.getPath()->getLength() <= maxLength) {
        outDistance = chWatson.getPath()->getLastPoint().distanceTo(chMurderer.getPath()->getLastPoint());
        if (outDistance <= maxDistance) return true;
        else return false;
    }
    outDistance = -1;
    return false;
}
//POINT
string Point::toString() const {
    return "<Point[" + to_string(x) + "," + to_string(y) + "]>";
}
int Point::distanceTo(const Point& otherPoint) const {
    return ceil(sqrt(pow(x - otherPoint.x, 2) + pow(y - otherPoint.y, 2)));
}
//NODE
string Node::toString() const {
    return "<Node[" +point.toString() + "]>";
}
//PATH
Path::~Path() {
    if (head) {
        Node* rev = head;
        while (rev->next) {
            Node* next = rev->next;
            delete rev;
            rev = next;
        }
        head = nullptr;
    }
    delete tail;
    delete head;
}
void Path::addPoint(int x, int y) {
    if (head == nullptr) {
        head = new Node(Point(x, y), nullptr);
        tail = new Node(Point(x, y), nullptr);
        length = 0;
    }
    else {
        Node* rev = head;
        while (rev->next) rev = rev->next;
        rev->next = new Node(Point(x, y), nullptr);
        tail ->next = new Node(Point(x, y), nullptr);
        length += ceil(tail->point.distanceTo(tail->next->point));
        tail = tail->next;
    }
    count++;
}
string Path::toString() const {
    string s = "<Path[count:" + to_string(count) + ",length:" + to_string(length) + ",[";
    Node *rev = head;
    while (rev) {
        if (rev != head) s += ",";
        s += rev->toString();
        rev = rev->next;
    }
    s += "]]>";
    return s;
}
Point Path::getLastPoint() const { return tail->point;}
int Path::getLength() const { return length;}
//CHARACTER
string Character:: getName() const { return name;}
void Character::setName(const string& name){Character::name = name;}
void Character::moveToPoint(int x, int y) {path->addPoint(x, y);}
string Character::toString() const {
    return "<Character[name:" + name + ",path:" + path->toString()+"]>";
}
Path* Character::getPath () const {return path;}


////////////////////////////////////////////////
///END OF STUDENT'S ANSWER
////////////////////////////////////////////////
#endif /* studyInPink_h */