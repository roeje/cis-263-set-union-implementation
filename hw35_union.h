/*
 * Jesse Roe, Tyler Paquet, and Brandon Attala
 */

#ifndef GVSU_LIST_UNION
#define GVSU_LIST_UNION

#include <list>

using std::list;

using namespace std;
template<typename T>
list<T> listUnion(const list<T> &one, const list<T> &two) {
    /*Temp variable used in second version the uses erase*/
//    list<T> tempTwo = two;

    /*results contains all values from list one*/
    list<T> result = two;

    for (auto it = one.begin(); it != one.end(); ++it) {
        /*binary search is used find values in list two that are present in list one.
         * If a duplicate is NOT found the value in list two the the value in list one is added to the results list.
         * */
        if (!std::binary_search(two.begin(), two.end(), *it)) {
            result.push_back(*it);
        }
    }
/*
 * Version of method that uses erase to shrink second list each time a duplicate is found.
 * This causes the loop to resemble log(N) or close to it.
 */
//    for (auto it = one.begin(); it != one.end(); ++it) {
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

    result.sort();
    result.unique();
    return result;
};

#endif
