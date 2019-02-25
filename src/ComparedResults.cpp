
#include "../include/ComparedResults.h"

ComparedResults::ComparedResults() {
}

void ComparedResults::SetHighlightAdded(std::vector<std::pair<int, int> >& highlight_added) {
    this->highlight_added = highlight_added;
}

void ComparedResults::SetHighlightDeleted(std::vector<std::pair<int, int> >& highlight_deleted) {
    this->highlight_deleted = highlight_deleted;
}

std::vector<std::pair<int, int> > ComparedResults::GetHighlightAdded() {
    return highlight_added;
}

std::vector<std::pair<int, int> > ComparedResults::GetHighlightDeleted() {
    return highlight_deleted;
}

ComparedResults::~ComparedResults() {
}