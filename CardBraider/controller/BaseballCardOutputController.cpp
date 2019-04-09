//#define DIAGNOSTIC_OUTPUT
#include "BaseballCardOutputController.h"
#include "Utils.h"

#include <sstream>
#include <iomanip>
using namespace std;

#include "BaseballCard.h"
using namespace model;

namespace controller
{

//
// Handles output for BaseballCardBraidedList
//
BaseballCardOutputController::BaseballCardOutputController()
{
    this->fileWriter = new FileWriter();
}

//
// Gets the collection of BaseballCards in a GUI friendly format sorted by @sortOrderEnum
//
// @param The sort order strategy to be used when forming summary text.
// @return A formatted string for GUI output of the BaseballCardBraidedList
//
const string& BaseballCardOutputController::getSummaryText(int sortOrderEnum) //TODO find a way to free output strings
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

//
// Writes BaseballCardBraidedList as a CSV data file to @fileName
//
// @param the file to which to write the CSV data.
// @precondition none
// @postcondition File created at the @fileName location.
//
void BaseballCardOutputController::saveCardsToCsv(const string& fileName)
{
    this->fileWriter->setOutputFile(fileName);
    string* baseballCardsCsv = new string;
    this->fileWriter->writeDataToFile(this->getBaseballCardsCsv(*baseballCardsCsv, *this->baseballCards->getNameHead()));
}

string BaseballCardOutputController::formatCardDataCsv(BaseballCardNode& baseballCard) const
{
    string formattedData = baseballCard.getLastName() + "," +
                           baseballCard.getFirstName() + "," +
                           to_string(baseballCard.getYear()) + "," +
                           baseballCard.getConditionDescription() + "," +
                           to_string(baseballCard.getPrice());
    return formattedData;
}

string BaseballCardOutputController::getBaseballCardsCsv(string& baseballCardCsv, BaseballCardNode& current)
{
    baseballCardCsv += this->formatCardDataCsv(current) + "\n";

    if(current.getNextName() != nullptr)
    {
        this->getBaseballCardsCsv(baseballCardCsv, *current.getNextName());
    }

    return baseballCardCsv;
}

//
// Sets the BaseballCardBraidedList to be used for output.
//
// @param baseballCards
// @postcondition The active braided list is updated to @baseballCards
//
void BaseballCardOutputController::setBaseballCards(BaseballCardBraidedList& baseballCards)
{
    this->baseballCards = &baseballCards;
}

BaseballCardOutputController::~BaseballCardOutputController()
{
    delete this->fileWriter;
    this->fileWriter = nullptr;
}
}
