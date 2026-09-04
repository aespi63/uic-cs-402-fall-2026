# UIC CS 402 Fall 2026

## Project 1: Sorting
In this project, you will implement various sorting algorithms discussed in class. This project contains the following files.
- `Firstname_Lastname_project1.cpp`
    - This is your main file and where all of your code will be implemented. This file also contains relevant instructions for implementing your code.
- `Firstname_Lastname_project1.h`
    - This is the header file for your main file. If you add any helper functions, please be sure to add the appropriate function prototypes to this file.
- `testing.h` and `testing.cpp`
    - These have functions to help test your code; e.g., various functions to generate lists of varying length that you can try to sort. You can also add your own tests to these files.

### Due Date
**Sunday, September 6th, 2026, by 11:59pm Central Time**

### Writing Your Code
This project is distributed through GitHub and you will write your code using git for version control. My advice to you is to commit early and commit often to your repository to accurately track your progress when writing your project solutions. 

The included files in this project all have additional instructions in the code comments; please read them carefully! The comments also include the point breakdowns for each of the functions you will be implementing.

#### Group Work
You are allowed to work in groups of at most 3 people for this project, and I encourage you to work together to learn from each other! 

### Compiling Your Code
I will be compiling your code using `clang++` with the parameter `-std=c++20`. 
In other words, we are using the C++20 standard for this project. 
Your code will not compile if you do not pass this parameter to your compiler. 
Note that some systems may not have clang installed and have gcc/g++ installed instead. 
For development, this should be fine, but you should make sure clang is installed and check your code with respect to `clang++` to ensure there are no errors in your code.

> [!IMPORTANT]
> Do not compile your code with any optimization flags! You should try to make your code as fast as possible without relying on the compiler!

### Testing Your Code
As mentioned above, the `testing.h/.cpp` files have various functions to help test your code. For additional help in testing your code, you can consider the following functions
- `std::is_sorted`: this function returns a bool representing if a list is sorted or not. Let `list` be a vector (NOT a pointer to a vector). Then,
    - `std::is_sorted(list.begin(),list.end())` returns true if and only if `list` is sorted in ascending order;
    - `std::is_sorted(list.begin(),list.end(),std::greater<>{})` returns true if and only if `list` is sorted in descending order.
- `std::sort` and `std::stable_sort` are the built-in sorting functions. You can use them to check the correct order of a list. If `list` is the vector you want to sort, then
    - `std::sort(list.begin(),list.end())` sorts `list` in ascending order, and `std::sort(list.begin(),list.end(),std::greater<>{})` sorts in descending order.
    - Similarly, `std::stable_sort(list.begin(),list.end())` and `std::stable_sort(list.begin(),list.end(),std::greater<>{})` stable sorts in descending order.

### Submission
Your submission will be a GitHub repository. You have 2 options for this.
1. Add me as a collaborator to your GitHub repository. My username is `arblock-uic`. This option works if your repository is public or private.
2. Send me a link to your repository. Note this only works if you make the repository public. 

Note that once you have added me to your repository/sent me the repository link, I will be able to see your future projects as well, so you do not need to repeat this. Moving forward, project submissions will consist of me simply checking your GitHub repository for the last commit before the project deadline. I will also put in place a way for you to submit your project late should you wish to do so.

### Grading
This project is worth the following amount of points.
- Undergraduate Students: 100 points;
- Graduate Students: 125 points.
Please see the code comments for the point breakdowns.

#### Autograder
I will be using an autograder to help speed the process of testing your code. 
The autograder will test your functions against various test cases that I will write. 
Note that the available testing tools provided in `testing.cpp` are not necessarily all tests I will run on your code! Each passed test case will add to the total points received per function (e.g., if I have 20 test cases per function, then passing all 20 gets you the maximum number of points for that function).

#### Manual Inspection
Part of your grade will also come from manual inspection of your code. 
This is because the autograder cannot check if you are implementing the correct algorithms, it can only check that you pass some tests. 
To help make this process smooth and easy, please be sure to write legible and clear code.

#### Project Assessment
There will be a short **in-class, written** assessment after the project is due.
For this project, the assessment is scheduled for **Thursday, September 10th, 2026.**


#### Extra Credit
I will also be implementing all the functions for this project. For a bit of fun, bragging rights, and extra credit, I will run each student's code against my own code and see which one performs better. Each function you implement that can beat my code will earn you 1 point of extra credit on the project (max of 8 points for this project).
