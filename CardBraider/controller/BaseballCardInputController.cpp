#define DIAGNOSTIC_OUTPUT

#include "BaseballCardInputController.h"
#include "Utils.h"
#include "BaseballCard.h"

using namespace model;

namespace controller
{
BaseballCardInputController::BaseballCardInputController()
{
    this->baseballCards = nullptr;
}

void BaseballCardInputController::importCards(const string& fileName)
{
    if(this->baseballCards != nullptr)
    {
        delete this->baseballCards;
        this->baseballCards = nullptr;
    }

    this->baseballCards = new BaseballCardBraidedList();
    this->fileReader.setFileName(fileName);
    vector<vector<string>> fileLines = this->fileReader.getData();
    for(vector<string> current : fileLines)
    {
        this->baseballCards->addBaseballCard(*this->createNode(current));
    }
}

BaseballCardNode* BaseballCardInputController::createNode(vector<string> data)
{
    string firstName = data[this->FIRST_NAME_INDEX];
    string lastName = data[this->LAST_NAME_INDEX];
    int year = toInt(data[this->YEAR_INDEX], "Invalid year from file import.");
    BaseballCard::Condition condition = this->parseCondition(data[this->CONDITION_INDEX]);
    int price = toInt(data[this->PRICE_INDEX], "Invalid price from file import.");
    BaseballCard* newCard = new BaseballCard(firstName, lastName, year, condition, price);
    BaseballCardNode* newNode = new BaseballCardNode(*newCard);

    return newNode;
}

BaseballCard::Condition BaseballCardInputController::parseCondition(const string& condition)
{
    BaseballCard::Condition result;
    if(toUpperCase(condition).compare("POOR") == 0)
    {
        result = BaseballCard::POOR;
    }
    else if (toUpperCase(condition).compare("GOOD") == 0)
    {
        result = BaseballCard::GOOD;
    }
    else if (toUpperCase(condition).compare("EXCELLENT") == 0)
    {
        result = BaseballCard::EXCELLENT;
    }
    else if (toUpperCase(condition).compare("MINT") == 0)
    {
        result = BaseballCard::MINT;
    }
    else if (toUpperCase(condition).compare("PRISTINE") == 0)
    {
        result = BaseballCard::PRISTINE;
    }
    else
    {
        result = BaseballCard::UNKNOWN;
    }
    return result;
}

BaseballCardInputController::~BaseballCardInputController()
{
    delete this->baseballCards;
    this->baseballCards = nullptr;
}
}

