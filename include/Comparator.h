
#ifndef COMPARATOR_H
#define COMPARATOR_H

#include <vector>
#include <sstream>
#include <algorithm>
#include <memory>
#include "ComparedResults.h"
#include "FileData.h"
#include "../include/ComparedResults.h"

class Comparator {
public:
    Comparator();
    std::unique_ptr<ComparedResults> Compare(FileData*);
    std::vector<int> GetAddedLines();
    std::vector<std::pair<int, int> > Highlight(std::vector<std::string>, 
        std::vector<std::string>);
    virtual ~Comparator();
private:
    std::stringstream text_first_;
    std::stringstream text_second_;
    std::string data_;
    std::vector<std::string> text_of_file1_;
    std::vector<std::string> text_of_file2_;
    std::vector<std::pair<int, int> > highlight_added;
    std::vector<std::pair<int, int> > highlight_deleted;
    size_t count_;
};

#endif /* COMPARATOR_H */

