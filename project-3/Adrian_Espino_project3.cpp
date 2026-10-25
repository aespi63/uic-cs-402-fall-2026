
#include <vector>
#include <string>
#include <iostream>

// be sure to change FIRSTNAME and LASTNAME with your own first and last name
#include "Adrian_Espino_project3.h"

using namespace std;

const string who_am_i() {
    return "Adrian Espino";
}


/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement solutions to the problems described below.
 *   You must follow the specifications as written below.
 *
 * - Certain function signatures may not be modified (as it will affect auto
 *   grading). These functions will be specified.
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project3.h."
 *
 * - If you are working in a group, please modify the comments directly below.
 *   
 * - IMPORTANT: If you are working in a group, every member is expected to submit their
 *   source code individually.
 *
 */


/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2


/* Problem 1: "Weird" Tree Traversal 
 *
 * 25 Points
 *
 * In this problem, you are asked to implement what I am calling "weird"
 * traversal on a tree.
 *
 * Definition: A weird traversal on an arbitrary rooted tree (i.e., a node can have
 * any number of children) proceeds as follows.
 *
 *   - First, the traversal visits all even layers in level-order, where we
 *     define the root to be layer 0, its children as layer 1, etc. "Level-
 *     order" here means visiting the nodes in layer i from left to right, 
 *     followed by nodes in layer i+2 from left to right (for even i). In
 *     other words, this traversal, starting from the root, visits all even
 *     layers in level-order (top to bottom, left to right).
 *
 *   - Once all even layers have been visited, all of the odd layers are then
 *     visited, bottom to top and right to left. In other words, this traversal
 *     visits the deepest odd layer first, from right most node to left most node,
 *     then proceeds back up, with the children of the root visited last.
 * 
 * Problem 
 *  - Given a pointer to the root of a Tree (specified as a TreeNode in
 *    the header file), output a vector of integers which represents the 
 *    weird-traversal of the tree.
 *
 * Grading
 *  - This problem is easily solvable using 2 traversals. This will only give
 *    you 15 points. To get full marks, you must solve this problem doing
 *    a single traversal of the tree.
 *      - Note this also means you cannot copy this tree into a different
 *        representation, as this would be at least 2 traversals to solve
 *        the problem (one to put the tree into a different format, then
 *        another traversal to perform weird-traversal).
 * 
 * Assumptions
 *  - Each node in the tree has a unique integer id. However, you cannot
 *    assume that the root is id 0, its first child has id 1, etc. The
 *    ids in the tree are only guaranteed to be unique.
 *  - The tree is in the first-child, next-sibling representation. That is,
 *    a node in a tree only has 2 pointers: one to its first (i.e., left-
 *    most) child, and one to its first (i.e., right) sibling.
 *
 * Examples
 *  - Tree in first-child, next-sibling representation. Consider the following
 *    tree:
 *       0
 *     / | \
 *    1  2  3
 *      /    \
 *     4      5
 *   / | \   /||\
 *  6  7 8  9 ab c
 *
 *    The first-child, next-sibling representation turns this tree into an equivalent
 *    binary tree, where a left branch is the first child in the above tree, and a
 *    right branch is the next sibling in the above tree:
 *               0
 *             /
 *           1
 *             \
 *             [  2  ]
 *            /      \
 *           4       3
 *          /       /
 *         6       5
 *          \     /
 *           7   9
 *            \   \
 *             8   a
 *                  \
 *                   b
 *                    \
 *                     c
 *
 * - Weird-traversal of above tree, given pointer to root labeled "a":
 *   [0, 4, 5, c, b, a, 9, 8, 7, 6, 3, 2, 1]
 *
 * - Other weird-traversal examples
 *    (a)    1   -> [1, 3, 2]
 *         /  \
 *        2    3
 *
 *    (b) -1    -> [-1, 3, 6, -9, 7, 2]
 *        / \
 *      2    7
 *       \  / \
 *       3 6  -9
 */

// Do not modify this function signature.
vector<int> weird_traversal(TreeNode* root) {
    // Your code here!
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    vector<TreeNode*> nodes;   // BFS queue (nodes in visit order)
    vector<int> depths;        // depths[k] is the depth of nodes[k]
    vector<int> odd_ids;       // odd-layer ids, in BFS order

    nodes.push_back(root);
    depths.push_back(0);

    size_t front = 0;          // index of the next node to process
    while (front < nodes.size()) {
        TreeNode* node = nodes[front];
        int depth = depths[front];
        front++;

        if (depth % 2 == 0) {
            result.push_back(node->id);
        } else {
            odd_ids.push_back(node->id);
        }

        // In first-child/next-sibling form, a node's children are its
        // first_child followed by that child's chain of next_siblings.
        for (TreeNode* child = node->first_child; child != nullptr; child = child->next_sibling) {
            nodes.push_back(child);
            depths.push_back(depth + 1);
        }
    }

    // Walk the odd ids backwards: deepest odd layer first, right-most first.
    for (size_t k = odd_ids.size(); k > 0; k--) {
        result.push_back(odd_ids[k - 1]);
    }

    return result;

}



/* Problem 2: Bits-to-Tree 
 *
 * 25 Points
 *
 * In this problem, you are given a vector of bits which represents 
 * a DFS traversal of a tree with the following properties:
 *  1. Non-empty: the tree always has at least 1 node (the root).
 *  2. Unlabeled: the nodes in the tree are not labeled.
 *  3. Ordered: the children of each noded are ordered from left to right.
 *
 * Your goal is to reconstruct the tree given the vector of bits, using
 * the TreeNode struct. The bits in the vector correspond to a DFS
 * traversal in the following way:
 *  - A '1' represents a "down" traversal; and
 *  - A '0' represents a "up" traversal.
 * Moreover, this DFS traversal visits each child in left-to-right order.
 *
 * Helpful Properties of this Problem
 *  - For a tree with n nodes, the input "bits" is valid if and only if
 *      - bits has exactly n-1 1's and n-1 0's;
 *      - bits has even length (i.e., = 2(n-1)); and
 *      - For any prefix of bits (i.e., bits[0,..,i]), #0s <= #1s
 *
 * Other Considerations
 *  - The tree is guaranteed to be non-empty. What type of input would lead
 *    to a tree that is a single root node?
 *  - Defining a helper function for this problem could be useful.
 *
 * Grading
 *  - The returned pointer must be the root of the tree you have reconstructed,
 *    or the nullptr if 'bits' is not a valid encoding.
 *  - Additionally, label each node from 0 to n-1, where the ID of the node
 *    corresponds to its ordering during the pre-order DFS traversal.
 *  - Using your own TreeNode type which represents a tree in a format other
 *    than specified to construct your solution will only yield 15 points. For
 *    full marks, directly construct your tree using the TreeNode struct.
 * 
 * Examples
 *  - [1, 0] ->  0
 *              /
 *             1
 *
 *  - [1, 0, 1, 0, 1, 1, 0, 1, 0, 0]
 *      -> (in a format where each node has a vector of children)
 *                0
 *              / | \
 *             1  2   3
 *                   | \
 *                   4  5
 *      -> (in the required first-child, next sibling format)
 *               0
 *              /
 *             1
 *             \
 *              2
 *               \
 *                3
 *               /
 *              4
 *               \
 *                5
 */

// Do not modify this fuction signature
TreeNode* bits_to_tree(const vector<bool>& bits) {
    // Validation pass over the bit vector (not the tree)
    // Valid iff: even length, no prefix has more 0s than 1s, and the totals balance.
    if (bits.size() % 2 != 0) {
        return nullptr;
    }
    int balance = 0;
    for (bool b : bits) {
        balance += b ? 1 : -1;
        if (balance < 0) {
            return nullptr;  // tried to go "up" from the root
        }
    }
    if (balance != 0) {
        return nullptr;  // never came all the way back up
    }

    int next_id = 0;
    TreeNode* root = new TreeNode{next_id++, nullptr, nullptr};

    // Empty bits -> loop below doesn't run -> single root node, as required.
    vector<TreeNode*> path = {root};
    vector<TreeNode*> last_child = {nullptr};

    for (bool b : bits) {
        if (b) {
            TreeNode* child = new TreeNode{next_id++, nullptr, nullptr};
            TreeNode* parent = path.back();

            if (last_child.back() == nullptr) {
                parent->first_child = child;            // parent's first child
            } else {
                last_child.back()->next_sibling = child; // later child -> sibling link
            }
            last_child.back() = child;

            // Step down into the new node; it has no children yet.
            path.push_back(child);
            last_child.push_back(nullptr);
        } else {
            // Step back up. Validation guarantees we never pop the root.
            path.pop_back();
            last_child.pop_back();
        }
    }
    return root;
}


/* Problem 3: Build a Parse Tree
*
* 25 Points
*
* In this problem, you are asked to build a parse tree
* which represents a Boolean expression you are given 
* as input as a string.
*
* Your goal is that given a string that represents a
* Boolean expression, build a tree that represents 
* evaluating this expression.
*
* Input:
*   - A string expr which represents the Boolean expression
*     you must parse. There are 5 special characters that
*     can appear in these strings:
*       - '^', which represents && (Boolean and),
*       - '|', which represents || (Boolean or),
*       - '~', which represents Boolean not,
*       - '(' and ')', which open and close parentheses
*    In the header file, for the first 3 characters, I have
*    specified 3 const static char variables you can use to help.
*    Other than these 5 characters, the string may contain a-z and
*    A-Z. No other characters will appear in the strings given
*    as input.
* 
* Output:
*   - A pointer to a ParseTreeNode which represents the parse tree
*     of the given string.
*
* More Details:
*   You are expected to build the tree so that a preorder
*     traversal of the tree results in the correct evaluation
*     of the given Boolean expression. This means that the following
*     rules must be followed:
*     1. Expressions are evaluated from left to right
*     1. Anything in parentheses gets evaluated first, before operators
*       outside of the parenthesis
*     2. any NOT gets evaluated next
*     3. any AND or OR gets evaluated next (they have the same precidence)
*   In the case of multiple of the same operater in a row, it gets
*     processed from left to right. 
*   Note that the ParseTreeNode struct always has two children; in the
*     case of a NOT node, you must always leave the right child null.
*
*   Some examples are given below.
*   - Example 1: c | (a ^ b) 
*     Following the rules of Boolean logic, you would evaluate
*     (a ^ b) first, followed by the result of this with v c.
*     This gives the following parse tree:
*
*                    |
*                 /    \
*                c     ^
*                    /  \  
*                   a    b
*
*  - Example 2: a | b ^ c
*    Since all of these operators have the same precidence, we would 
*    evaluate in order from left to right. This gives the following tree
*
*
*                    ^
*                 /    \
*                |      c
*              /  \  
*             a    b
*
*  - Example 3: ~(A ^ b) ^ (c | ~z)
*
*               ^
*           /       \
*          ~         |
*         /        /  \
*        ^        c    ~
*      /  \           /
*     A    b         z
*
* - Example 4: ~(A ^ (c | ~(d ^ e) ^ F) | ~z)
*
*                ~
*               /
*              |
*           /     \
*          ^       ~
*       /   \     /
*      A     ^   z
*           / \
*          |  F
*        /  \
*       c    ~
*           /
*          ^
*         / \
*        d  e
*
*
* Note that in the given strings, there will be no spaces (the whitespace
*   above is to help you see the expressions clearly)
*
*/

// Do not modify this function signature
ParseTreeNode* build_parse_tree(const string& expr) {
    size_t index = 0;
    return parse_expr(expr, index);
}

ParseTreeNode* parse_expr(const string& expr, size_t& index) {
    ParseTreeNode* left = parse_unary(expr, index);
    
    while (index < expr.size() && (expr[index] == AND || expr[index] == OR)) {
        char op = expr[index];
        index++;  // consume operator
        ParseTreeNode* right = parse_unary(expr, index);
        left = make_parse_node(op, left, right); // grow tree to the left
    }

    // Stops at end of string or at a ')' that belongs to the caller.
    return left;
}

ParseTreeNode* make_parse_node(char val, ParseTreeNode* left, ParseTreeNode* right) {
    return new ParseTreeNode{val, left, right};
}

ParseTreeNode* parse_unary(const string& expr, size_t& index) {
    if (index >= expr.size()) {
        return nullptr;
    }

    char c = expr[index];

    if (c == NOT) {
        index++;  // consume '~'
        // NOT applies to the next unary term only (tighter than ^ and |).
        // Recursing on parse_unary also handles stacked NOTs like ~~a.
        // Spec: NOT nodes keep the operand on the left, right stays null.
        return make_parse_node(NOT, parse_unary(expr, index), nullptr);
    }

    if (c == '(') {
        index++;  // consume '('
        ParseTreeNode* inner = parse_expr(expr, index);
        if (index < expr.size() && expr[index] == ')') {
            index++;  // consume ')'
        }
        // Parentheses don't get their own node; they only shape the tree.
        return inner;
    }

    // Otherwise it's a variable (a-z / A-Z): a leaf.
    index++;
    return make_parse_node(c, nullptr, nullptr);
}

// Prints the parse tree in a way that shows the structure of the tree.
// For example, the tree for c|(a^b) would be printed as |(c,^(a,b))
void print_parse(ParseTreeNode* n) {
    if (n == nullptr) return;
    cout << n->val;
    if (n->left_child || n->right_child) {
        cout << "(";
        print_parse(n->left_child);
        if (n->right_child) {
            cout << ",";
            print_parse(n->right_child);
        }
        cout << ")";
    }
}

void print_vec(const vector<int>& v) {
    cout << "[";
    for (size_t k = 0; k < v.size(); k++) {
        cout << v[k] << (k + 1 < v.size() ? ", " : "");
    }
    cout << "]\n";
}

int main() {
    // Problem 2 + Problem 1 together: build the spec's 6-node example and
    // weird-traverse it. Expected tree: 0 -> {1, 2, 3}, 3 -> {4, 5}
    // Even layers: 0, 4, 5   Odd layer (reversed): 3, 2, 1
    vector<bool> bits = {1, 0, 1, 0, 1, 1, 0, 1, 0, 0};
    TreeNode* t = bits_to_tree(bits);
    print_vec(weird_traversal(t));                   // [0, 4, 5, 3, 2, 1]

    // The big example from the Problem 1 spec, built by hand with
    // a=10, b=11, c=12. Expected: [0, 4, 5, 12, 11, 10, 9, 8, 7, 6, 3, 2, 1]
    TreeNode n[13];
    for (int k = 0; k < 13; k++) {
        n[k].id = k;
        n[k].first_child = nullptr;
        n[k].next_sibling = nullptr;
    }
    n[0].first_child = &n[1];
    n[1].next_sibling = &n[2];
    n[2].next_sibling = &n[3];
    n[2].first_child = &n[4];
    n[3].first_child = &n[5];
    n[4].first_child = &n[6];
    n[6].next_sibling = &n[7];
    n[7].next_sibling = &n[8];
    n[5].first_child = &n[9];
    n[9].next_sibling = &n[10];
    n[10].next_sibling = &n[11];
    n[11].next_sibling = &n[12];
    print_vec(weird_traversal(&n[0]));

    // Invalid encodings should give nullptr.
    cout << (bits_to_tree({0, 1}) == nullptr) << "\n";      // 1
    cout << (bits_to_tree({1, 1, 0}) == nullptr) << "\n";   // 1

    // Problem 3 examples from the spec.
    print_parse(build_parse_tree("c|(a^b)"));        cout << "\n";  // |(c,^(a,b))
    print_parse(build_parse_tree("a|b^c"));          cout << "\n";  // ^(|(a,b),c)
    print_parse(build_parse_tree("~(A^b)^(c|~z)"));  cout << "\n";  // ^(~(^(A,b)),|(c,~(z)))
    print_parse(build_parse_tree("~(A^(c|~(d^e)^F)|~z)")); cout << "\n";

    return 0;
}
