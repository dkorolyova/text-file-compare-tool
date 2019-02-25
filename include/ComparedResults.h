
#ifndef COMPAREDRESULTS_H
#define COMPAREDRESULTS_H

#include <string>
#include <vector>

class ComparedResults {
public:
    ComparedResults();
    virtual ~ComparedResults();
    void SetHighlightAdded(std::vector<std::pair<int, int> >&);
    void SetHighlightDeleted(std::vector<std::pair<int, int> >&);
    std::vector<std::pair<int, int> > GetHighlightAdded();
    std::vector<std::pair<int, int> > GetHighlightDeleted();
private:
    std::vector<std::pair<int, int> > highlight_added;
    std::vector<std::pair<int, int> > highlight_deleted;
};

#endif /* COMPAREDRESULTS_H */

