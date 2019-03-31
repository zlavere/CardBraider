#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace io
{
class FileReader
{
private:
    const int BASEBALL_CARD_ATTRIBUTE_COUNT = 5;
    string fileName;
    vector<vector<string>> data;
    void parseFileLines();
    vector<string> readInFileLines();

public:
    FileReader();
    virtual ~FileReader();
    vector<vector<string>> getData();
    void setFileName(const string& fileName);
};
}

#endif // FILEREADER_H
