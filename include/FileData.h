
#ifndef FILEDATA_H
#define FILEDATA_H

#include <string>

class FileData {
public:
    FileData();
    void SetText(std::string);
    void SetTextToCompare(std::string);
    std::string GetText();
    std::string GetTextToCompare();
    void SetPathFirst(std::string);
    void SetPathSecond(std::string);
    std::string GetPathFirst();
    std::string GetPathSecond();
    bool IsEmpty();
    virtual ~FileData();
private:
    std::string text_;
    std::string text_to_compare_;
    std::string path_first_file_;
    std::string path_second_file_;
};

#endif /* FILEDATA_H */

