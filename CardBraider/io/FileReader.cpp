#include "FileReader.h"
#include "FileReader.h"

#include <sstream>

namespace io
{
//
// Reads in a file in CSV file cointaing data for a Baseball Card Collection
//
FileReader::FileReader()
{
    //ctor
}
//
// Sets the file name from which the file reader will read.
//
// @param fileName from which to read in files.
//
void FileReader::setFileName(const string& fileName)
{
    this->fileName = fileName;
}

vector<string> FileReader::readInFileLines()
{
    ifstream stream;
    string line;
    vector<string> fileLines;

    stream.open(this->fileName);
    if(!stream)
    {
        cout << "There was an error finding this file." << endl;
    }

    while(stream >> line)
    {
        fileLines.push_back(line);
    }
    stream.close();

    return fileLines;
}

void FileReader::parseFileLines()
{
    vector<string> fileLines = this->readInFileLines();

    this->data.reserve(fileLines.size());

    for(size_t i = 0; i < fileLines.size(); i++)
    {
        vector<string> dataContainer;
        dataContainer.reserve(this->BASEBALL_CARD_ATTRIBUTE_COUNT);
        stringstream stream(fileLines[i]);
        string attribute;

        while(getline(stream, attribute, ','))
        {
            dataContainer.push_back(attribute);
        }

        this->data.push_back(dataContainer);
    }
}

//
// Reads in and parses file lines from a file, such that each attribute of a BaseballCard is in the collection.
//
// @return Collection of strings where each item attribute from a line from the file
//
vector<vector<string>> FileReader::getData()
{
    this->data.clear();
    this->parseFileLines();
    return this->data;
}

FileReader::~FileReader()
{
    //dtor
}
}
