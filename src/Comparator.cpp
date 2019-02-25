
#include "../include/Comparator.h"

Comparator::Comparator() {
}

std::unique_ptr<ComparedResults> Comparator::Compare(FileData *filedata) {
    text_first_ << filedata->GetText();
    text_second_ << filedata->GetTextToCompare();
    
    while(std::getline(text_first_, data_)) {
        text_of_file1_.push_back(data_);
    }

    while (std::getline(text_second_, data_)) {
        text_of_file2_.push_back(data_);
    }
    
    highlight_added = this->Highlight(text_of_file1_, text_of_file2_);
    highlight_deleted = this->Highlight(text_of_file2_, text_of_file1_);
    
    
    std::unique_ptr<ComparedResults> compared_results(new ComparedResults());

    compared_results->SetHighlightAdded(highlight_added);
    compared_results->SetHighlightDeleted(highlight_deleted);
    return compared_results;
}
    
std::vector<std::pair <int, int> > Comparator::Highlight(std::vector<std::string> text, 
        std::vector<std::string> text_to_compare) {
    std::vector<std::pair<int, int> > highlight;
    count_ = 0;
    for (size_t i = 0; i < text_to_compare.size(); i++) {
        count_ += text_to_compare[i].size() + 1;
        if (std::find(text.begin(), text.end(), text_to_compare[i]) == text.end()) {
            highlight.push_back(std::make_pair(count_ - text_to_compare[i].size(), count_));
        }
    }
    return highlight;
}    

Comparator::~Comparator() {
}