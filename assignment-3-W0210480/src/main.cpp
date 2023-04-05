#include "BST.h"
#include "spell_checker.h"

int main(int argc, char *argv[]) {
    // check for correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] <<
                  " <dictionary_file> <misspelled_file> <output_file>\n";
        return 1;
    }

    spell_checker spc;
    spc.run_program(argv[1], argv[2], argv[3]);

    return 0;
}