#define DIAGNOSTIC_OUTPUT
#include "BaseballCardInputController.h"

#include "Utils.h"

namespace controller
{
//
// Handles input into the Baseball Card collection
// from User and File input
//
BaseballCardInputController::BaseballCardInputController()
{
    this->baseballCards = nullptr;
}

//
// Imports a Baseball Card Collection from a file into the BaseballCardBraidedList
//
// @param fileName the file name from which to import the collection.
// @precondition none
// @postcondition File is parsed and the braided list is created from the contents of the file.
//
void BaseballCardInputController::importCardsFromFile(const string& fileName)
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

//
// Imports a Baseball Card from user input into the BaseballCardBraidedList
//
// @param data the user input from which a BaseballCard can be created
// @precondition none
// @postcondition User input is parsed and baseball card is created and added to the BraidedList
//
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
    if(this->baseballCards == nullptr)
    {
        this->baseballCards = new BaseballCardBraidedList();
    }

    string firstName = data[this->FIRST_NAME_INDEX];
    string lastName = data[this->LAST_NAME_INDEX];
    int year = toInt(data[this->YEAR_INDEX], "Invalid year.");
    BaseballCard::Condition condition = this->parseCondition(data[this->CONDITION_INDEX]);
    int price = toInt(data[this->PRICE_INDEX], "Invalid price.");
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

//
// Gets the BaseballCardBraidedList
//
// @return the BaseballCardBraidedList
//
BaseballCardBraidedList* BaseballCardInputController::getBaseballCardsBraidedList()
{
    return this->baseballCards;
}

BaseballCardInputController::~BaseballCardInputController()
{
    delete this->baseballCards;
    this->baseballCards = nullptr;
}
}

