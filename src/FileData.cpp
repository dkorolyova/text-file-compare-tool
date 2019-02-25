
#include "../include/FileData.h"

FileData::FileData() {
}

void FileData::SetText(std::string text_file_first) {
    text_ = text_file_first;
}

void FileData::SetTextToCompare(std::string text_file_second) {
    text_to_compare_ = text_file_second;
}

std::string FileData::GetText() {
    return text_;
}

std::string FileData::GetTextToCompare() {
    return text_to_compare_;
}

void FileData::SetPathFirst(std::string path_first_file) {
    this->path_first_file_ = path_first_file;
}

void FileData::SetPathSecond(std::string path_second_file) {
    this->path_second_file_ = path_second_file;
}

std::string FileData::GetPathFirst() {
    return path_first_file_;
}

std::string FileData::GetPathSecond() {
    return path_second_file_;
}

bool FileData::IsEmpty() {
    return (this->GetText().empty()) && (this->GetTextToCompare().empty());
}

FileData::~FileData() {
}

