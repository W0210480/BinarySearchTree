//
// Created by RyanG on 2023-03-14.
//

#ifndef ASSIGNMENT_3_BST_H
#define ASSIGNMENT_3_BST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

struct Node;

using NodePtr = Node *;

struct Node {
    std::basic_string<char> m_data{-1};
    NodePtr m_left{nullptr};
    NodePtr m_right{nullptr};
};

class BST {
private:
    NodePtr m_root{nullptr};

public:

    void compare(std::string word);

    std::vector<std::string> open_file(const std::string &file_name);

    void save_file(std::string file_name, BST &bst, std::vector<std::string>
    dictionary_words);

    void create_balanced_tree(std::vector<std::string> &dictionary_words,
                              int start, int end, NodePtr &node);

    friend std::ostream &operator<<(std::ostream &output, BST &bst);

private:
    void insert(std::basic_string<char> word, NodePtr &node);

    void print(std::ostream &output, NodePtr &node, int indent);

};


#endif //ASSIGNMENT_3_BST_H
