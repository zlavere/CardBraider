#ifndef BASEBALLCARDOUTPUTCONTROLLER_H
#define BASEBALLCARDOUTPUTCONTROLLER_H

#include <string>
using namespace std;

#include "BaseballCardNode.h"
#include "BaseballCardBraidedList.h"
using namespace model;

#include "io/FileWriter.h"
using namespace io;

namespace controller
{
class BaseballCardOutputController
{
private:
    const int NAME_ASC = 0;
    const int NAME_DSC = 1;
    const int YEAR_ASC = 2;
    const int YEAR_DSC = 3;
    const int CONDITION_ASC = 4;
    const int CONDITION_DSC = 5;
    BaseballCardBraidedList* baseballCards;
    const string& getOutputByNameAscending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByNameDescending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByYearAscending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByYearDescending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByConditionAscending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByConditionDescending(string& output, BaseballCardNode& currentNode) const;
    string formatCardData(BaseballCardNode& baseballCard) const;
    string formatCardDataCsv(BaseballCardNode& baseballCard) const;
    const string& getBaseballCardsCsv();
    FileWriter fileWriter;

public:
    BaseballCardOutputController();
    virtual ~BaseballCardOutputController();
    void setBaseballCards(BaseballCardBraidedList& baseballCards);
    const string& getSummaryText(int sortOrderEnum);
    void saveCardsToCsv(const string& fileName);
};
}


#endif // BASEBALLCARDOUTPUTCONTROLLER_H
