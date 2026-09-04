


#include <iostream>
#include <algorithm>
#include <chrono>
#include <concepts>
#include <type_traits>

#include "testing.h"
#include "Firstname_Lastname_project1.h"

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */


/** This please add your name here as well **/
const std::string who_am_i() {
    return "Adrian_Espino";
}


/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Adrian Espino
//   Member 2



/* Bubble Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }
     // swap adjacent elements if they are in the wrong order based on the descending flag
    for (int i = 0; i < list.size() - 1; ++i) {
        for (int j = 0; j < list.size() - 1; ++j) {
            if ((descending && list[j] < list[j + 1]) || (!descending && list[j] > list[j + 1])) {
                swap(list[j], list[j + 1]);
            }
        }
    }
    // Your code here!
}


/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. 
 *            Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }
    // Find the minimum (or maximum) element in the remaining list and swap it with the first element
    for (int i = 0; i < list.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < list.size(); ++j) {
            if ((descending && list[j] > list[min_index]) || (!descending && list[j] < list[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(list[i], list[min_index]);
        }
    }
    // Your code here!
}


/* Insertion Sort 
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
//template<typename T>
//void insertion_sort(vector<T> &list, bool descending = false);
template<typename T>
void insertion_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }
    // Go through the list and insert each elemnt into the correct position
    for(int i = 1; i < list.size(); ++i) {
        T key = list[i];
        int j = i - 1;

        while (j >= 0 && ((descending && list[j] < key) || (!descending && list[j] > key))) {
            list[j + 1] = list[j];
            --j;
        }
        list[j + 1] = key;
    }
    // Your code here!
}


/* Quicksort 
 *
 * 10 points
 * 
 * Algorithm: Sorts by first choosing a random pivot from the list, then 
 *            partitioning the list into two halves with respect to the 
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *            
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void quicksort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }

    //Random pivot selection
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<size_t> dis(0, list.size() - 1);
    T pivot = list[dis(gen)];
    // Partition the list into three parts: less than, greater than, and equal to the pivot
    vector<T> less;
    vector<T> greater;
    vector<T> equal;
    // Distribute elements into the three partitions
    for ( T &item : list) {
        if (item <pivot) {
            less.push_back(item);
        } else if (item > pivot) {
            greater.push_back(item);
        } else {
            equal.push_back(item);
        }
    }
    // Recursively sort the less and greater partitions
    quicksort(less, descending);
    quicksort(greater, descending);
    // Clear the original list and concatenate the sorted partitions back into it
    list.clear();
    if (descending) {
        list.insert(list.end(), greater.begin(), greater.end());
        list.insert(list.end(), equal.begin(), equal.end());
        list.insert(list.end(), less.begin(), less.end());
    } else {
        list.insert(list.end(), less.begin(), less.end());
        list.insert(list.end(), equal.begin(), equal.end());
        list.insert(list.end(), greater.begin(), greater.end());
    }
    // Your code here
}



/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template<typename T>
void merge_sort(vector<T> &list, bool decending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }

    size_t mid = list.size() / 2;
    vector<T> left(list.begin(), list.begin() + mid);
    vector<T> right(list.begin() + mid, list.end());

    // breaks the list into two halves and recursively sorts each half
    merge_sort(left, decending);
    merge_sort(right, decending);

    list.clear();
    size_t i = 0;
    size_t j = 0;

    //checks the condition for merging the two halves based on the decending flag
    while(i < left.size() && j < right.size()) {
       bool condition = decending ? (left[i] > right[j]) : (left[i] < right[j]);
        if (condition) {
            list.push_back(left[i]);
            ++i;
        } else {
            list.push_back(right[j]);
            ++j;
        }
    }

        // appends remainder from either left or right to the end of the list
        while (i < left.size()) {
            list.push_back(left[i]);
            ++i;
        }
        while (j < right.size()) {
            list.push_back(right[j]);
            ++j;
        }
    
    // Your code here!
}



/* Your Hybrid Sort
 *
 * 20 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    if (list.size() <= 1) {
        return; // Base case: a list of size 0 or 1 is already sorted
    }

    size_t Threshold = 10; // Threshold for switching to insertion sort

    if (list.size() <= Threshold) {
       insertion_sort(list, descending); // Use insertion sort for small lists
       return;
   }

    mt19937 gen(random_device{}());
    uniform_int_distribution<size_t> dis(0, list.size() - 1);
    T pivot = list[dis(gen)];

    vector<T> less;
    vector<T> greater;
    vector<T> equal;

    for (T &item : list) {
        if (item < pivot) {
            less.push_back(item);
        } else if (item > pivot) {
            greater.push_back(item);
        } else {
            equal.push_back(item);
        }
    }

    list.clear();
    if (descending) {
        list.insert(list.end(), greater.begin(), greater.end());
        list.insert(list.end(), equal.begin(), equal.end());
        list.insert(list.end(), less.begin(), less.end());
        } else {
        list.insert(list.end(), less.begin(), less.end());
        list.insert(list.end(), equal.begin(), equal.end());
        list.insert(list.end(), greater.begin(), greater.end());
        }
      // Your code here!
}


/* Binary Radix Sort
 *
 * 20 points, EXTRA CREDIT
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 * Additional Information:
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 */
//template<class T>
//concept Integral = std::is_integral<T>::value;
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Your code here!
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}



int main() {
    /**** STUDENT CODE HERE ****/ 



    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *   - NOTE: you can uncomment the code below if you are testing your code with the autograder. The 
     *     autograder will throw an error if you run it without uncommenting the code.
     */

    vector<int> test_list {1, 2, 3, 4, 5};
    vector<unsigned int> test_list2 {1, 2, 3, 4, 5};
    vector<StableChar> test_list3  {};
    vector<StableInt> test_list4 {};
    vector<StableString> test_list5 {};
    vector<short> test_list6  {};
    vector<unsigned short> test_list7  {};
    vector<long> test_list8  {};
    vector<unsigned long> test_list9  {};


    insertion_sort(test_list);
    insertion_sort(test_list2);
    insertion_sort(test_list3);
    insertion_sort(test_list4);
    insertion_sort(test_list5);
    insertion_sort(test_list6);
    insertion_sort(test_list7);
    insertion_sort(test_list8);
    insertion_sort(test_list9);


    selection_sort(test_list);
    selection_sort(test_list2);
    selection_sort(test_list3);
    selection_sort(test_list4);
    selection_sort(test_list5);
    selection_sort(test_list6);
    selection_sort(test_list7);
    selection_sort(test_list8);
    selection_sort(test_list9);

    bubble_sort(test_list);
    bubble_sort(test_list2);
    bubble_sort(test_list3);
    bubble_sort(test_list4);
    bubble_sort(test_list5);
    bubble_sort(test_list6);
    bubble_sort(test_list7);
    bubble_sort(test_list8);
    bubble_sort(test_list9);


    merge_sort(test_list);
    merge_sort(test_list2);
    merge_sort(test_list3);
    merge_sort(test_list4);
    merge_sort(test_list5);
    merge_sort(test_list6);
    merge_sort(test_list7);
    merge_sort(test_list8);
    merge_sort(test_list9);

    quicksort(test_list);
    quicksort(test_list2);
    quicksort(test_list3);
    quicksort(test_list4);
    quicksort(test_list5);
    quicksort(test_list6);
    quicksort(test_list7);
    quicksort(test_list8);
    quicksort(test_list9);

    //my_hybrid_sort(test_list);
    //my_hybrid_sort(test_list2);
    //my_hybrid_sort(test_list3);
    //my_hybrid_sort(test_list4);
    //my_hybrid_sort(test_list5);
    //my_hybrid_sort(test_list6);
    //my_hybrid_sort(test_list7);
    //my_hybrid_sort(test_list8);
    //my_hybrid_sort(test_list9);

    //binary_radix_sort(test_list);
    //binary_radix_sort(test_list2);
    //binary_radix_sort(test_list6);
    //binary_radix_sort(test_list7);
    //binary_radix_sort(test_list8);
    //binary_radix_sort(test_list9);

    //radix_sort(test_list);
    //radix_sort(test_list2);
    //radix_sort(test_list6);
    //radix_sort(test_list7);
    //radix_sort(test_list8);
    //radix_sort(test_list9);


    return 0;
}









