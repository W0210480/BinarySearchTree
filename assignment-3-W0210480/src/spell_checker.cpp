//
// Created by RyanG on 2023-03-17.
//

#include <regex>
#include "spell_checker.h"

// function to handle file processing
void spell_checker::run_program(const std::string &dict_filename,
                                const std::string &misspelled_filename,
                                const std::string &output_filename) {

    BST bst;

    // argv[1] - dictionary file
    std::vector<std::string> dictionary_words = bst.open_file(dict_filename);

    // argv[2] - misspelled file
    std::vector<std::string> misspelled_words = bst.open_file(misspelled_filename);

    // argv[3] - output file
    bst.save_file(output_filename, bst, dictionary_words);

    // convert to words
    std::vector<std::string> words = convert_to_words(misspelled_words);

    // compare function
    for (const auto &word: words) {
        bst.compare(word);
    }

}


std::vector<std::string> spell_checker::convert_to_words
        (std::vector<std::string> &misspelled_words) {
    std::vector<std::string> string;
    for (const auto &line: misspelled_words) {
        // Remove special characters and numbers using regex
        std::string clean_line = std::regex_replace
                (line, std::regex("[^a-zA-Z\\s]"), " ");
        std::istringstream iss(clean_line);
        std::string word;
        while (iss >> word) {
            // convert to lowercase
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            string.push_back(word);
        }
    }

    return string;
}






