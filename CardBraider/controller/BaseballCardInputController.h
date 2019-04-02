#ifndef BASEBALLCARDINPUTCONTROLLER_H
#define BASEBALLCARDINPUTCONTROLLER_H

#include "io/FileReader.h"
using namespace io;

#include "Model/BaseballCardBraidedList.h"
using namespace model;

namespace controller
{
class BaseballCardInputController
{
private:
    const int LAST_NAME_INDEX = 0;
    const int FIRST_NAME_INDEX = 1;
    const int YEAR_INDEX = 2;
    const int CONDITION_INDEX = 3;
    const int PRICE_INDEX = 4;
    const int SORT_BY_NAME_ASC = 0;
    const int SORT_BY_NAME_DSC = 1;
    FileReader fileReader;
    BaseballCardBraidedList* baseballCards;
    BaseballCard::Condition parseCondition(const string& condition);
    const string& getOutputByNameAscending(string& output, BaseballCardNode& currentNode) const;
    const string& getOutputByNameDescending(string& output, BaseballCardNode& currentNode) const;

public:
    BaseballCardInputController();
    virtual ~BaseballCardInputController();
    void importCards(const string& fileName);
    BaseballCardNode* createNode(vector<string> data);
    const string& getSummaryText(int sortOrderEnum);
    void addCardFromInput(vector<string> data);

};
}


#endif // BASEBALLCARDINPUTCONTROLLER_H
