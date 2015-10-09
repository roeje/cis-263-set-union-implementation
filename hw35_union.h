/*
 * Include your name(s) here
 */

#ifndef GVSU_LIST_UNION
#define GVSU_LIST_UNION

#include <list>

using std::list;

using namespace std;
//typedef list<T> listType;
/* The template function below will be tested against different
 * element type (T): int, char, and string. 
 * Nevertheless, you shall write only ONE function below */
template<typename T>
list<T> listUnion(const list<T> &one, const list<T> &two) {

//    list<T> tempTwo = two;
//    list<T> tempOne = one;
//    tempOne.unique();
//    tempOne.sort();
//    tempTwo.unique();
//    tempTwo.sort();
    list<T> result = two;
//
//    for (auto it = tempOne.begin(); it != tempOne.end(); ++it) {
//        bool temp = true;
//        for(auto it2 = tempTwo.begin(); it2 != tempTwo.end(); ++it2) {
//
//            if(*it == *it2) {
//                temp = false;
//                tempTwo.erase(tempTwo.begin(), it2);
//                break;
//            }
//        }
//        if(temp) {
//            result.push_back(*it);
//        }
//    }

    for (auto it = one.begin(); it != one.end(); ++it) {
        if (!std::binary_search(two.begin(), two.end(), *it)) {
            result.push_back(*it);
        }
    }
    result.sort();
    result.unique();
    return result;
};


/* Write your solution here using ONLY std::list operations.
 * (You are not allowed to use other data structures such as
 * map, set, vector, ...). You will, of course, use loops
 * and conditional statements.
 *
 * Reference: http://en.cppreference.com/w/cpp/container/list.
 */


//    for (auto it = tempOne.begin(); it != tempOne.end(); ++it) {
//        if (it > tempTwo.begin()) {
//            tempTwo.pop_front();
//        }
//        else {
//            if (it == tempTwo.begin()) {
//                result.push_back(it);
//            }
//            tempTwo.pop_front();
//        }
//    }

//    for (auto it = one.begin(); it != one.end(); ++it) {
//        if(*it > *tempTwo.begin()) {
//            tempTwo.pop_front();
//        }
//        else {
//            if (*it != *tempTwo.begin()) {
//                result.push_back(*it);
//            }
//            tempTwo.pop_front();
//        }
//    }
//    if(tempTwo.size() > 0) {
//        result.merge(tempTwo);
//    }



//}

//    for (list<T>::iterator it = tempOne.begin(); it != tempOne.end(); ++it) {
//        if (*it > *tempTwo.begin()) {
//            tempTwo.pop_front();
//        }
//        else {
//            if (*it == *tempTwo.begin()) {
//                result.push_back(it);
//            }
//            tempTwo.pop_front();
//        }
//    }

//    tempTwo.merge(tempOne);
//    result = tempTwo;


//
//void main {
//        list<int> temp1 {1,2,3,4,5};
//};
#endif
