#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>
using namespace std;

namespace io {
class FileWriter
{
    private:
    string fileName;
    public:
        FileWriter();
        virtual ~FileWriter();
        void setOutputFile(const string& fileName);
        void writeDataToFile(const string& data);
};
}
#endif // FILEWRITER_H
