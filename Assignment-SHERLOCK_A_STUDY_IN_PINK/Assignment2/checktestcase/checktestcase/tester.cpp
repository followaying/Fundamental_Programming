#include "/Fundamental Programming/212/Assignment2/main/main/studyInPink3a.h"  
//đường dẫn dẫn đến file studyInPink3a.h hoặc studyInPink3b.h
// Có thể bỏ bớt thư viện iostream, cmath, string ở tester do chúng được include ở file header
// Ngoài ra KHÔNG thay đổi bất cứ hàm nào trong tester
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
void getInt(string instruction, int& nums1, int& nums2)
{
    int index = instruction.find(',');
    nums1 = stoi(instruction.substr(0, index));
    nums2 = stoi(instruction.substr(index + 1, instruction.length() - index));
}

int main(){
    vector<Point> point_var(100, Point());
    vector<Node*> node_var(100, new Node(Point(0, 0), NULL));
    vector<Path> path_var(100, Path());
    vector<Character> char_var(100, Character());
    Character chMurderer, chWatson;
    string instruction;
    do{
        getline(cin, instruction);
        int index = instruction.find(':');
        string key_word;
        if (index != string::npos){
            key_word = instruction.substr(0, index);
            instruction.erase(instruction.begin(), instruction.begin() + index + 2);
        }
        else{
            cout << "INVALID INSTRUCTION!";
            return 0;
        }
        if (key_word == "init_point"){
            string point_name = instruction.substr(0, instruction.find('/'));
            string point = instruction.substr(instruction.find('/') + 1, instruction.length() - instruction.find('/'));
            int point_index = stoi(point_name.substr(1, point_name.length() - 1));
            int nums1 = 0, nums2 = 0;
            if (point[0] != 'p'){
                getInt(point, nums1, nums2);
                point_var[first_point_index] = Point(nums1, nums2);
            }
            else{
                int point_index = stoi(point.substr(1, point.length() - 1));
                point_var[first_point_index] = point_var[point_index];
            }
            cout << "Success!" << endl;
        }
        else if (key_word == "print_point")
        {
            if (instruction[0] == 'p')
            {
                int point_index = stoi(instruction.substr(1, instruction.length() - 1));
                cout << point_var[point_index].toString() << endl;
                if (point_var[point_index].toString() != "")
                {
                    cout << "Success!" << endl;
                }
                else
                {
                    cout << "Failed";
                    return 0;
                }
            }
            else
            {
                int nums1 = 0, nums2 = 0;
                Point p;
                getInt(instruction, nums1, nums2);
                p = Point(nums1, nums2);
                if (p.toString() != "")
                {
                    cout << p.toString() << endl;
                }
                else
                {
                    cout << "Failed";
                    return 0;
                }
            }
        }
        else if (key_word == "get_distance")
        {
            int idx = instruction.find('/');
            string point1 = instruction.substr(0, instruction.find('/'));
            string point2 = instruction.substr(idx + 1, instruction.length() - idx);
            if (point1[0] == 'p')
            {
                if (point2[0] == 'p')
                {
                    int point1_index = stoi(point1.substr(1, point1.length() - 1));
                    int point2_index = stoi(point2.substr(1, point2.length() - 1));
                    cout << point_var[point1_index].distanceTo(point_var[point2_index]) << endl;
                }
                else
                {
                    int point1_index = stoi(point1.substr(1, point1.length() - 1));
                    int nums1 = 0, nums2 = 0;
                    getInt(point2, nums1, nums2);
                    Point p2(nums1, nums2);
                    cout << point_var[point1_index].distanceTo(p2) << endl;
                }
            }
            else
            {
                if (point2[0] == 'p')
                {
                    int point2_index = stoi(point2.substr(1, point2.length() - 1));
                    int nums1 = 0, nums2 = 0;
                    getInt(point1, nums1, nums2);
                    Point p1(nums1, nums2);
                    cout << point_var[point2_index].distanceTo(p1) << endl;
                }
                else
                {
                    int nums1 = 0, nums2 = 0;
                    getInt(point1, nums1, nums2);
                    Point p1(nums1, nums2);
                    getInt(point2, nums1, nums2);
                    Point p2(nums1, nums2);
                    cout << p2.distanceTo(p1) << endl;
                }
            }
        }
        else if (key_word == "init_node")
        {
            int idx = instruction.find('/');
            int sec_idx = instruction.find('/', idx + 1);
            string first_name = instruction.substr(0, idx);
            string point = instruction.substr(idx + 1, sec_idx - idx - 1);
            string second_name = instruction.substr(sec_idx + 1, instruction.length() - sec_idx);
            int first_index = stoi(first_name.substr(4, first_name.length() - 4));
            Point p;
            if (point[0] != 'p')
            {
                int nums1 = 0, nums2 = 0;
                getInt(point, nums1, nums2);
                p = Point(nums1, nums2);
            }
            else
            {
                int point_index = stoi(point.substr(1, point.length() - 1));
                p = point_var[point_index];
            }
            if (second_name == "NULL" || second_name == "nullptr")
            {
                node_var[first_index] = new Node(p, NULL);
                cout << "Success!" << endl;
            }
            else
            {
                if (second_name == first_name)
                {
                    cout << "INVALID POINTER!";
                    return 0;
                }
                else
                {
                    int second_index = stoi(second_name.substr(4, second_name.length() - 4));
                    node_var[first_index] = new Node(p, node_var[second_index]);
                    cout << "Success!" << endl;
                }
            }
        }
        else if (key_word == "print_node")
        {
            int first_index = stoi(instruction.substr(4, instruction.length() - 4));
            if (node_var[first_index] != NULL)
            {
                cout << node_var[first_index]->toString() << endl;
            }
            else
            {
                cout << "Failed";
                return 0;
            }
        }
        else if (key_word == "init_path")
        {
            cout << "Success!" << endl;
        }
        else if (key_word == "call_path_destructor")
        {
            int first_index = stoi(instruction.substr(4, instruction.length() - 4));
            path_var[first_index].~Path();
            if (path_var[first_index].toString() == "<Path[count:0,length:-1,[]]>")
            {
                cout << "Success!" << endl;
            }
            else
            {
                cout << "Failed";
                return 0;
            }
        }
        else if (key_word == "add_point")
        {
            string path_name = instruction.substr(0, instruction.find('/'));
            int path_index = stoi(path_name.substr(4, path_name.length() - 4));
            string point = instruction.substr(instruction.find('/') + 1, instruction.length() - instruction.find('/'));
            Point p;
            if (point[0] != 'p')
            {
                int nums1 = 0, nums2 = 0;
                getInt(point, nums1, nums2);
                p = Point(nums1, nums2);
            }
            else
            {
                int point_index = stoi(point.substr(1, point.length() - 1));
                p = point_var[point_index];
            }
            path_var[path_index].addPoint(p.getX(), p.getY());
            cout << "Success!" << endl;
        }
        else if (key_word == "print_path")
        {
            int path_index = stoi(instruction.substr(4, instruction.length() - 4));
            cout << path_var[path_index].toString() << endl;
        }
        else if (key_word == "get_last_point")
        {
            int path_index = stoi(instruction.substr(4, instruction.length() - 4));
            Point last = path_var[path_index].getLastPoint();
            cout << last.toString() << endl;
        }
        //Hai hàm này chỉ dành cho các sinh viên thuộc Đồ án 212 KTLT, còn lại không cần quan tâm
        /*else if (key_word == "remove_last")
        {
            int path_index = stoi(instruction.substr(4, instruction.length() - 4));
            bool check = path_var[path_index].removeLast();
            if (check == true)
            {
                cout << "Success!" << endl;
            }
            else
            {
                cout << "Fail to remove last node" << endl;
            }
        }
        else if (key_word == "concatenate")
        {
            int index = instruction.find('/');
            int sec_index = instruction.find('/', index + 1);
            string save_path_name = instruction.substr(0, index);
            int save_index = stoi(save_path_name.substr(4, save_path_name.length() - 4));
            string first_path_name = instruction.substr(index + 1, sec_index - index);
            int first_index = stoi(first_path_name.substr(4, first_path_name.length() - 4));
            string second_path_name = instruction.substr(sec_index + 1, instruction.length() - sec_index);
            int second_index = stoi(second_path_name.substr(4, second_path_name.length() - 4));
            path_var[save_index] = path_var[first_index] + path_var[second_index];
            cout << path_var[save_index].toString() << endl;
        }*/
        else if (key_word == "init_character")
        {
            int index = instruction.find('/');
            string character_var_name = instruction.substr(0, index);
            string character_name = instruction.substr(index + 1, instruction.length() - index);
            int char_index = stoi(character_var_name.substr(4, character_var_name.length() - 4));
            char_var[char_index] = Character(character_name);
            if (char_var[char_index].getName() == character_name)
            {
                cout << "Success!" << endl;
            }
            else
            {
                cout << "Failed";
                return 0;
            }
        }
        else if (key_word == "get_character_name")
        {
            int char_index = stoi(instruction.substr(4, instruction.length() - 4));
            cout << char_var[char_index].getName() << endl;
        }
        else if (key_word == "set_character_name")
        {
            int index = instruction.find('/');
            string character_var_name = instruction.substr(0, index);
            string character_name = instruction.substr(index + 1, instruction.length() - index);
            int char_index = stoi(character_var_name.substr(4, character_var_name.length() - 4));
            char_var[char_index].setName(character_name);
        }
        else if (key_word == "move_to_point")
        {
            int index = instruction.find('/');
            string character_var_name = instruction.substr(0, index);
            int char_index = stoi(character_var_name.substr(4, character_var_name.length() - 4));
            string point = instruction.substr(index + 1, instruction.length() - index);
            Point p;
            if (point[0] != 'p')
            {
                int nums1 = 0, nums2 = 0;
                getInt(point, nums1, nums2);
                p = Point(nums1, nums2);
            }
            else
            {
                int point_index = stoi(point.substr(1, point.length() - 1));
                p = point_var[point_index];
            }
            char_var[char_index].moveToPoint(p.getX(), p.getY());
            cout << "Success!" << endl;
        }
        else if (key_word == "print_character")
        {
            int char_index = stoi(instruction.substr(4, instruction.length() - 4));
            cout << char_var[char_index].toString() << endl;
            if (char_var[char_index].toString() != "")
            {
                cout << "Success!" << endl;
            }
            else
            {
                cout << "Failed";
                return 0;
            }
        }
        else if (key_word == "call_character_destructor")
        {
            int char_index = stoi(instruction.substr(4, instruction.length() - 4));
            char_var[char_index].~Character();
            cout << "Success!" << endl;
        }
        else if (key_word == "get_current_position")
        {
            int char_index = stoi(instruction.substr(4, instruction.length() - 4));
            Point p = char_var[char_index].getCurrentPosition();
            cout << p.toString();
        }
        else if (key_word == "init_Murderer")
        {
            string name = "Murderer";
            int N = stoi(instruction.substr(instruction.find('/') + 1, instruction.length() - instruction.find('/')));
            chMurderer = Character(name);
            string point;
            for (int i = 0; i < N; i++)
            {
                getline(cin, point);
                if (point[0] != 'p')
                {
                    int nums1 = 0, nums2 = 0;
                    getInt(point, nums1, nums2);
                    chMurderer.moveToPoint(nums1, nums2);
                }
                else
                {
                    Point p;
                    int point_index = stoi(point.substr(1, point.length() - 1));
                    p = point_var[point_index];
                    chMurderer.moveToPoint(point_var[point_index].getX(), point_var[point_index].getY());
                }
            }
            cout << "Success!" << endl;
        }
        else if (key_word == "init_Watson")
        {
            string name = "Watson";
            int N = stoi(instruction.substr(instruction.find('/') + 1, instruction.length() - instruction.find('/')));
            chWatson = Character(name);
            string point;
            for (int i = 0; i < N; i++)
            {
                getline(cin, point);
                if (point[0] != 'p')
                {
                    int nums1 = 0, nums2 = 0;
                    getInt(point, nums1, nums2);
                    chWatson.moveToPoint(nums1, nums2);
                }
                else
                {
                    Point p;
                    int point_index = stoi(point.substr(1, point.length() - 1));
                    p = point_var[point_index];
                    chWatson.moveToPoint(point_var[point_index].getX(), point_var[point_index].getY());
                }
            }
            cout << "Success!" << endl;
        }
        else if (key_word == "checkRescue")
        {
            int max_length = stoi(instruction.substr(0, instruction.find('/')));
            int max_distance = stoi(instruction.substr(instruction.find('/') + 1, instruction.length() - instruction.find('/')));
            int out_distance;
            bool check = rescueSherlock(chMurderer, chWatson, max_length, max_distance, out_distance);
            cout << "Max length: " << max_length << endl;
            cout << "Max distance: " << max_distance << endl;
            cout << "Out distance: " << out_distance << endl;
            cout << "Can rescue: " << check << endl;
        }
        else
        {
            cout << "INVALID INSTRUCTION!";
            return 0;
        }
    } while (instruction != "0");
}
