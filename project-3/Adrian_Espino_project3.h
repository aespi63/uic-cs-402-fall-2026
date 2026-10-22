
#ifndef ADRIAN_ESPINO_PROJECT3
#define ADRIAN_ESPINO_PROJECT3

#include <vector>
#include <string>

using namespace std;

// Struct for tree in first-child, next-sibling representation
struct TreeNode {
    int id;
    TreeNode* first_child;
    TreeNode* next_sibling;
};

const static char AND = '^';
const static char OR = '|';
const static char NOT = '~';


struct ParseTreeNode {
    char val; // AND, OR, NOT, or some other char not in this set
    ParseTreeNode* left_child;
    ParseTreeNode* right_child;
};


// function delcarations
vector<int> weird_traversal(TreeNode* root);
TreeNode* bits_to_tree(const vector<bool>& bits);
ParseTreeNode* build_parse_tree(const string& expr);

// Helpers
ParseTreeNode* make_parse_node(char val, ParseTreeNode* left, ParseTreeNode* right);
ParseTreeNode* parse_expr(const string& expr, size_t& index);
ParseTreeNode* parse_unary(const string& expr, size_t& index);

#endif


