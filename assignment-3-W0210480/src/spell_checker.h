//
// Created by RyanG on 2023-03-17.
//

#ifndef ASSIGNMENT_3_SPELL_CHECKER_H
#define ASSIGNMENT_3_SPELL_CHECKER_H

#include <vector>
#include "BST.h"


class spell_checker {
public:

    void run_program(const std::string &dict_filename,
                     const std::string &misspelled_filename,
                     const std::string &output_filename);

    std::vector<std::string> convert_to_words(std::vector<std::string>
                                              &misspelled_words);

};


#endif //ASSIGNMENT_3_SPELL_CHECKER_H
