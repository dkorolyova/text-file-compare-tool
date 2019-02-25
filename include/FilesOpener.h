
#ifndef FILESOPENER_H
#define FILESOPENER_H

#include <string>
#include <fstream>
#include <sstream>
#include "FileData.h"

class FilesOpener {
public:
    FilesOpener();
    std::string ReadFile(std::string);
    FileData OpenFiles(std::string, std::string);
    virtual ~FilesOpener();
private:
    std::string path_first_file_;
    std::string path_second_file_;
};

#endif /* FILESOPENER_H */

