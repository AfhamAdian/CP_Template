# Codeforces-Solve

Here is all my Codeforces practices and solves.

## Strategy
1. How to solve:
    -Examine Test Cases
    -Analyze why it is behaving that way
    -Come with a Hypothesis
    -Disprove the Hypothesis
    
    -Prepare a code outline
    -check if the code outline validates the test cases
    -code
    -think of corner case before submitting 

2. If a code is above 100 lines AND requires EXTRA FUNCTIONS to be built - LOOK AGAIN!!! It's not the right idea.



## Ideas 

    1. abs(a1-a2)+abs(a2-a3) === abs(a1-a3) if a2 is in the middle of a1 and a3.
    
    2. (a+b)%m == 0 Equivalent to a%m+b%m == 0 or m



## Lessons

    1. Two pointers on sorted array for finding a difference ( subtract operation )
        1.1 : Two pointers on a prefix sum arrray to find how many task ( each task has a time ) can be done within a certain time ( 1400_BOOKs )
        
        1.2 : To Visualize Two Pointers -> Sliding Window

    2. Number -> String : makes many operations easier
    String -> Number : stoll() built in

    3.Binary search to find the value or max lower value of a given target in a array

    4.Kedanes Algo to find Maximum sub Array

    5.Longest contiguous subarray to fit in a certain sum limit

    6. :::: I :::: Use Set when you have to find the largest value smaller than a given value or ( the smallest value larger than a given value )
        O(logn) :
        find()
        upper_boud()
        lower_bound()
        count()
        insert()
        erase()

    7.  a.resize(unique(a.begin(), a.end()) - a.begin());
        fill_n(arr, k, -1);
        reverse()
        is_sorted()

    8.Use multiset : implemented with RBT, find = O(logn)
        8.1 find()
        8.2 equal range

    9. Far faster hash table
    #include <ext/pb_ds/assoc_container.hpp>
    using namespace __gnu_pbds;
    gp_hash_table<int, int> table;
    const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
    struct chash
    {
        int operator()(int x) const { return x ^ RANDOM; }
    };
    gp_hash_table<key, int, chash> table;



<h2>Beutiful problems :<h2>
1. 1100_large_addition
2. 1400_books
3. 1200_Equalize
4. CSES_Towers
5. 1200_Same_difference
6. 1200_M_Arrays : sum of adjacent a,b divisible by m === ( a%m + b%m == m or 0 )
7. 1300_Money_Trees : Two Pointers
8.*** CSES : Array_Division -> Most Beutiful Binary Search 
9. 1400_Have Your Cake and Eat It Too (continuos segement permutation bruteforce)
10. 1400_C. Sasha and the Casino (most beutiful constructive algo yet)
11. CSES Traffic_Light
