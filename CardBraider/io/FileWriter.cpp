#include "FileWriter.h"

namespace io {
FileWriter::FileWriter()
{
    //ctor
}

void FileWriter::setOutputFile(const string& fileName)
{
    this->fileName = fileName;
}

void FileWriter::writeDataToFile(const string& data)
{
    ofstream file;
    file.open(this->fileName);
    file << data;
    file.close();
}

FileWriter::~FileWriter()
{
    //dtor
}
}
