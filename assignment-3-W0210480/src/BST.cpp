//
// Created by RyanG on 2023-03-14.
//

#include "BST.h"

//
void BST::compare(std::string word) {
    NodePtr node = m_root;
    NodePtr parent = nullptr;

    // search for the node to delete
    while (node != nullptr) {
        if (word < node->m_data) {
            // go left
            parent = node;
            node = node->m_left;
        } else if (word > node->m_data) {
            // go right
            parent = node;
            node = node->m_right;
        } else {
            // found the node
            break;
        }
    }

    if (node == nullptr) {
        std::cout << word << std::endl;
        return;
    }
}

std::vector<std::string> BST::open_file(const std::string &file_name) {
    std::ifstream file;
    file.open(file_name);

    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    }

    std::vector<std::string> words;
    std::string line;
    while (std::getline(file, line)) {
        words.push_back(line);
    }
    file.close();

    return words;
}

void BST::save_file(std::string file_name, BST &bst,
                    std::vector<std::string> dictionary_words) {
    std::ofstream file;
    file.open(file_name);

    if (!file.is_open()) {
        std::cout << "Could not open file" << std::endl;
        exit(1);
    }

    bst.create_balanced_tree(dictionary_words, 0, dictionary_words.size() - 1,
                             bst.m_root);
    bst.print(file, bst.m_root, 0);
    file.close();

}

// ADD A BLOCK OF COMMENTS FOR THIS.
void BST::create_balanced_tree(std::vector<std::string> &dictionary_words,
                               int start, int end, NodePtr &node) {
    if (start > end) {
        return;
    }

    // find the middle index
    int mid = (start + end) / 2;
    insert(dictionary_words[mid], node);

    // recursively call the function to create the left subtree
    create_balanced_tree(dictionary_words, start, mid - 1, node->m_left);

    // recursively call the function to create the right subtree
    create_balanced_tree(dictionary_words, mid + 1, end, node->m_right);

}

void BST::insert(std::string word, NodePtr &node) {
    if (node == nullptr) {
        node = new Node;
        node->m_data = word;
        node->m_left = nullptr;
        node->m_right = nullptr;
    } else if (word < node->m_data) {
        insert(word, node->m_left);
    } else if (word > node->m_data) {
        insert(word, node->m_right);
    }
}

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print(output, bst.m_root, 0);
    return output;
}

void BST::print(std::ostream &output, NodePtr &node, int indent) {
    if (node != nullptr) {
        print(output, node->m_right, indent + 8);
        output << std::setw(indent) << node->m_data << std::endl;
        print(output, node->m_left, indent + 8);
    }
}



