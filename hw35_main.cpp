#include <algorithm>
#include <string>
#include <random>
#include <iostream>
using namespace std;

#include "gvsu_cis.h"
#include "hw35_union.h"

TEST_CASE ("Union of integers")
{
    list<int> one_empty;
    list<int> two {40, 12, -4, 13, 24, 35, 12};
    list<int> unique {5, 23, 33, 19, 67, 21, 45, -4};

    SECTION("Union of two empty lists") {
        auto result = listUnion (one_empty, one_empty);
        REQUIRE (result.size() == 0);
    }

    SECTION("Union of an empty list with non-empty") {
        auto result1 = listUnion (one_empty, two);
        auto result2 = listUnion (two, one_empty);
        REQUIRE (result1.size() > 0);
        REQUIRE (result2.size() < two.size());
        REQUIRE (result1.size() == result2.size());
        for (auto x : two) {
            auto pos = find (result1.begin(), result1.end(), x);
            REQUIRE (pos != result1.end());
        }
    }
}


TEST_CASE ("Union of characters")
{
    list<char> longer {'a', 'r', 'q', 'e', '$', '#', '2', 'w'};
    list<char> shorter {'b', 'q', 'G', 'h'};

    SECTION("Union of two empty lists") {
        auto result = listUnion (longer, shorter);
        REQUIRE (result.size() <= longer.size() + shorter.size());
    }

    SECTION("Union of an empty list with non-empty") {
        auto result1 = listUnion (longer, shorter);
        REQUIRE (result1.size() > 0);
        for (auto x : longer) {
            auto pos = find (result1.begin(), result1.end(), x);
            REQUIRE (pos != result1.end());
        }
        for (auto x : shorter) {
            auto pos = find (result1.begin(), result1.end(), x);
            REQUIRE (pos != result1.end());
        }
    }
}

TEST_CASE ("Union of strings")
{
    list<string> michigan {"Lansing", "Allendale", "Zeeland",
        "Muskegon", "Okemos", "Ypsilanti", "Jackson", "Brighton",
        "Holland", "Detroit"};
    list<string> ohio {"Columbus", "Cincinnati", "Dayton", "Cleveland",
    "Sandusky","Decatur", "Richmond"};

    SECTION("Union of two empty lists") {
        auto result = listUnion (michigan, ohio);
        REQUIRE (result.size() <= michigan.size() + ohio.size());
    }

    SECTION("Union of an empty list with non-empty") {
        auto result1 = listUnion (michigan, ohio);
        REQUIRE (result1.size() > 0);
        for (auto x : michigan) {
            auto pos = find (result1.begin(), result1.end(), x);
            REQUIRE (pos != result1.end());
        }
        for (auto x : ohio) {
            auto pos = find (result1.begin(), result1.end(), x);
            REQUIRE (pos != result1.end());
        }
    }
}

TEST_CASE ("Randomly generated integers") {

    class gv_randomizer {
    public:
        gv_randomizer(int N) : uniform(N/3, N) {}
        gv_randomizer(const gv_randomizer&) {}
        /* override the function-call operator */
        unsigned int operator()  () {
            return uniform(eng);
        }
    private:
        std::random_device eng;
        std::uniform_int_distribution<unsigned int> uniform;
    };

//    FAIL ("Comment out this FAIL assertion, after your change N");
//    /* start testing with a small value of N, and gradually increase N. Can
//     * your code handle up to 100 thousand within a "reasonable" amount of
//     * time? */
    const unsigned int N = 100000;
    list<unsigned int> one, two;

    /* resize and initialize the list */
    one.resize(N, 0);
    two.resize(N, 0);

    /* place random values into each list */
    auto mygen = gv_randomizer(N);  /* create a FUNCTOR object */
    generate (one.begin(), one.end(), mygen);
    generate (two.begin(), two.end(), gv_randomizer(N));

    /* perform various union operations */
    auto r1 = listUnion (one, one);
    auto r2 = listUnion (two, two);
    auto r3 = listUnion (one, two);
    REQUIRE (r3.size() <= r1.size() + r2.size());

    /* create an auxiliary array */
    vector<int> vals (one.begin(), one.end());
    std::uniform_int_distribution<unsigned int> selector (0, vals.size() - 1);
    std::random_device rd;

    /* randomly select 20% of the items for match */
    for (int k = 0; k < N / 5; k++) {
        int pos = selector(rd);
        int choice = vals[pos];
        auto where = find (r3.begin(), r3.end(), choice);
        REQUIRE (where != r3.end());
    }
}


