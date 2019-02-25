#include "../include/FilesOpener.h"

FilesOpener::FilesOpener() {
}

std::string FilesOpener::ReadFile(std::string file) {
    std::string data;
    std::ifstream infile(file);
    std::stringstream text;
    while (getline(infile, data)) {
        text << data << "\n";
    }
    return text.str();
}

FileData FilesOpener::OpenFiles(std::string path_first_file, std::string path_second_file) {
    FileData file_data;
    file_data.SetPathFirst(path_first_file);
    file_data.SetPathSecond(path_second_file);
    file_data.SetText(ReadFile(path_first_file));
    file_data.SetTextToCompare(ReadFile(path_second_file));
    return file_data;
}

FilesOpener::~FilesOpener() {
}