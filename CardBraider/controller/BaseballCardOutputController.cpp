#include "BaseballCardOutputController.h"
#include "Utils.h"

#include <sstream>
#include <iomanip>
using namespace std;

#include "BaseballCard.h"
using namespace model;

namespace controller {
BaseballCardOutputController::BaseballCardOutputController()
{
    //ctor
}

//TODO find a way to free output strings
const string& BaseballCardOutputController::getSummaryText(int sortOrderEnum)
{
    string* summaryText = new string("");

    if(this->baseballCards->getNameHead() == nullptr)
    {
        *summaryText = "No cards found.";
    }
    else if(sortOrderEnum == this->NAME_ASC)
    {
        this->getOutputByNameAscending(*summaryText, *this->baseballCards->getNameHead());
    }
    else if(sortOrderEnum == this->NAME_DSC)
    {
        this->getOutputByNameDescending(*summaryText, *this->baseballCards->getNameHead());
    }
    else if (sortOrderEnum == this->YEAR_ASC)
    {
        this->getOutputByYearAscending(*summaryText, *this->baseballCards->getYearHead());
    }
    else if (sortOrderEnum == this->YEAR_DSC)
    {
        this->getOutputByYearDescending(*summaryText, *this->baseballCards->getYearHead());
    }
    else if (sortOrderEnum == this->CONDITION_ASC)
    {
        this->getOutputByConditionAscending(*summaryText, *this->baseballCards->getConditionHead());
    }
    else if (sortOrderEnum == this->CONDITION_DSC)
    {
        this->getOutputByConditionDescending(*summaryText, *this->baseballCards->getConditionHead());
    }

    return *summaryText;
}

const string& BaseballCardOutputController::getOutputByNameAscending(string& output, BaseballCardNode& currentNode) const
{
    output += this->formatCardData(currentNode);

    if(currentNode.getNextName() != nullptr)
    {
        output = this->getOutputByNameAscending(output, *currentNode.getNextName());
    }

    return output;
}

const string& BaseballCardOutputController::getOutputByYearAscending(string& output, BaseballCardNode& currentNode) const
{
    output += this->formatCardData(currentNode);

    if(currentNode.getNextYear() != nullptr)
    {
        output = this->getOutputByYearAscending(output, *currentNode.getNextYear());
    }

    return output;
}

const string& BaseballCardOutputController::getOutputByConditionAscending(string& output, BaseballCardNode& currentNode) const
{
    output += this->formatCardData(currentNode);

    if(currentNode.getNextCondition() != nullptr)
    {
        output = this->getOutputByConditionAscending(output, *currentNode.getNextCondition());
    }

    return output;
}

const string& BaseballCardOutputController::getOutputByNameDescending(string& output, BaseballCardNode& currentNode) const
{
    if(currentNode.getNextName() != nullptr)
    {
        output = this->getOutputByNameDescending(output, *currentNode.getNextName());
    }

    output += this->formatCardData(currentNode);

    return output;
}

const string& BaseballCardOutputController::getOutputByYearDescending(string& output, BaseballCardNode& currentNode) const
{
    if(currentNode.getNextYear() != nullptr)
    {
        output = this->getOutputByYearDescending(output, *currentNode.getNextYear());
    }

    output += this->formatCardData(currentNode);

    return output;
}

const string& BaseballCardOutputController::getOutputByConditionDescending(string& output, BaseballCardNode& currentNode) const
{
    if(currentNode.getNextCondition() != nullptr)
    {
        output = this->getOutputByConditionDescending(output, *currentNode.getNextCondition());
    }

    output += this->formatCardData(currentNode);

    return output;
}

string BaseballCardOutputController::formatCardData(BaseballCardNode& baseballCard) const
{
    ostringstream stream;
    stream << setw(12) << left << baseballCard.getFirstName() << setw(12) << left << baseballCard.getLastName() << setw(8) << left << to_string(baseballCard.getYear()) << setw(10) << left << baseballCard.getConditionDescription();
    stream << setw(12) << right << formatCurrencyAsString(baseballCard.getPrice()) << endl;
    string formattedData = stream.str();
    return formattedData;
}

void BaseballCardOutputController::setBaseballCards(BaseballCardBraidedList& baseballCards)
{
    this->baseballCards = &baseballCards;
}

BaseballCardOutputController::~BaseballCardOutputController()
{
    //dtor
}
}

