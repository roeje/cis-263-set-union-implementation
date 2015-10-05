/*
 * Include your name(s) here
 */

#ifndef GVSU_LIST_UNION
#define GVSU_LIST_UNION

#include <list>
using std::list;

/* The template function below will be tested against different
 * element type (T): int, char, and string. 
 * Nevertheless, you shall write only ONE function below */
template <typename T>
list<T> listUnion (const list<T>& one, const list<T>& two)
{
    list<T> result;
    list<T> tempOne = one;
    list<T> tempTwo = two;
    /* Write your solution here using ONLY std::list operations.
     * (You are not allowed to use other data structures such as
     * map, set, vector, ...). You will, of course, use loops 
     * and conditional statements.
     *
     * Reference: http://en.cppreference.com/w/cpp/container/list.
     */
   for(list<T>::const_iterator it = tempOne.begin(); it != tempOne.end(); ++it) {
       if(it > tempTwo.begin) {
           tempTwo.erase(it);
       }
       else {
           if (it == tempTwo.begin()) {
               result.push_front(it);
           }
           tempTwo.erase(it);
       }
   }

    return result;
}
#endif
