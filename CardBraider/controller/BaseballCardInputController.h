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
    FileReader fileReader;
    BaseballCardBraidedList* baseballCards;
    BaseballCard::Condition parseCondition(const string& condition);


public:
    BaseballCardInputController();
    virtual ~BaseballCardInputController();
    void importCardsFromFile(const string& fileName);
    BaseballCardNode* createNode(vector<string> data);
    void addCardFromInput(vector<string> data);
    BaseballCardBraidedList* getBaseballCardsBraidedList();
};
}


#endif // BASEBALLCARDINPUTCONTROLLER_H
