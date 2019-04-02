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
    this->baseballCards = new BaseballCardBraidedList();
}

void BaseballCardInputController::importCards(const string& fileName)
{
    this->fileReader.setFileName(fileName);
    vector<vector<string>> fileLines = this->fileReader.getData();
    for(vector<string> current : fileLines)
    {
        this->baseballCards->addBaseballCard(*this->createNode(current));
    }
}

void BaseballCardInputController::addCardFromInput(vector<string> data)
{
    if(this->baseballCards == nullptr)
    {
        this->baseballCards = new BaseballCardBraidedList();
    }

    this->baseballCards->addBaseballCard(*this->createNode(data));
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
//TODO either rename this class or create an output controller
const string& BaseballCardInputController::getSummaryText(int sortOrderEnum)
{
    string* summaryText = new string("");

    if(sortOrderEnum == this->SORT_BY_NAME_ASC)
    {
       this->getOutputByNameAscending(*summaryText, *this->baseballCards->getNameHead());
    }
    else if(sortOrderEnum == this->SORT_BY_NAME_DSC)
    {
        this->getOutputByNameDescending(*summaryText, *this->baseballCards->getNameHead());
    }
    else
    {
        *summaryText = "No cards found.";
    }

    return *summaryText;
}

const string& BaseballCardInputController::getOutputByNameAscending(string& output, BaseballCardNode& currentNode) const
{
    //TODO Create method in BaseballCardNode to format toString()
    output += currentNode.getFirstName() + " " + currentNode.getLastName() + " " + to_string(currentNode.getYear()) + " " + currentNode.getCondition() + " $" + to_string(currentNode.getPrice()) + ".00\n";

    if(currentNode.getNextName() != nullptr)
    {
        output = this->getOutputByNameAscending(output, *currentNode.getNextName());
    }

    return output;
}

const string& BaseballCardInputController::getOutputByNameDescending(string& output, BaseballCardNode& currentNode) const
{
    if(currentNode.getNextName() != nullptr)
    {
        output = this->getOutputByNameDescending(output, *currentNode.getNextName());
    }

    output += currentNode.getFirstName() + " " + currentNode.getLastName() + " " + to_string(currentNode.getYear()) + " " + currentNode.getCondition() + " $" + to_string(currentNode.getPrice()) + ".00\n";

    return output;
}

BaseballCardInputController::~BaseballCardInputController()
{
    delete this->baseballCards;
    this->baseballCards = nullptr;
}
}

