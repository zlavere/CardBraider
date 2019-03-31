#include "FileReader.h"
#include "FileReader.h"

#include <sstream>
#include<algorithm>
#include<iterator>
namespace io
{
FileReader::FileReader()
{
    //ctor
}

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

vector<vector<string>> FileReader::getData()
{
    this->parseFileLines();
    return this->data;
}

FileReader::~FileReader()
{
    //dtor
}
}
