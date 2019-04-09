#include "FileWriter.h"

namespace io {
//
// Writes to a file
//
FileWriter::FileWriter()
{
    //ctor
}

//
// Sets the file to write to.
// @param fileName to write to.
//
void FileWriter::setOutputFile(const string& fileName)
{
    this->fileName = fileName;
}

//
// Writes @data to a file.
// @param data the string to write to the file
// @postcondition the @fileName file is created containing @data
//
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
