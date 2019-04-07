#include "BaseballCardBraidedList.h"
using namespace model;
#include "Utils.h"

namespace model
{
BaseballCardBraidedList::BaseballCardBraidedList()
{
    this->nameHead = nullptr;
    this->yearHead = nullptr;
    this->conditionHead = nullptr;
}

void BaseballCardBraidedList::addBaseballCard(BaseballCardNode& newNode)
{
    this->insertBaseballCard(newNode);
}

void BaseballCardBraidedList::insertBaseballCard(BaseballCardNode& newNode)
{
    if(this->nameHead == nullptr)
    {
        this->nameHead = &newNode;
    }
    else
    {
        this->insertIntoNameList(newNode, *this->nameHead, *this->nameHead);
    }

    if(this->yearHead == nullptr)
    {
        this->yearHead = &newNode;
    }
    else
    {
        this->insertIntoYearList(newNode, *this->yearHead, *this->yearHead);
    }

}

// TODO (zach#1#): Add same method for price and year if new.year < curr.year } else if { new.year <= curr.year && new.lastName < curr.lastname

void BaseballCardBraidedList::insertIntoNameList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode)
{
    if(toUpperCase(newNode.getLastName()) < toUpperCase(currentNode.getLastName()))
    {
        if(&currentNode == this->nameHead)
        {
            newNode.setNextName(currentNode);
            this->nameHead = &newNode;
        }
        else
        {
            newNode.setNextName(currentNode);
            previousNode.setNextName(newNode);
        }
    }
    else if(currentNode.getNextName() == nullptr)
    {
        currentNode.setNextName(newNode);
    }
    else
    {
        this->insertIntoNameList(newNode, *currentNode.getNextName(), currentNode);
    }
}

void BaseballCardBraidedList::insertIntoYearList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode)
{
    //TODO Figure out if this is necessary or move last name condition up?
    if(newNode.getYear() < currentNode.getYear())
    {
        if(&currentNode == this->yearHead)
        {
            newNode.setNextYear(currentNode);
            this->yearHead = &newNode;
        }
        else
        {
            newNode.setNextYear(currentNode);
            previousNode.setNextYear(newNode);
        }
    }
    else if (newNode.getYear() <= currentNode.getYear() && toUpperCase(newNode.getLastName()) <= toUpperCase(currentNode.getLastName()))
    {
        if(&currentNode == this->yearHead)
        {
            newNode.setNextYear(currentNode);
            this->yearHead = &newNode;
        }
        else
        {
            newNode.setNextYear(currentNode);
            previousNode.setNextYear(newNode);
        }

    }
    else if(currentNode.getNextYear() == nullptr)
    {
        currentNode.setNextYear(newNode);
    }
    else
    {
        this->insertIntoYearList(newNode, *currentNode.getNextYear(), currentNode);
    }
}

BaseballCardNode* BaseballCardBraidedList::getNameHead()
{
    return this->nameHead;
}

BaseballCardNode* BaseballCardBraidedList::getYearHead()
{
    return this->yearHead;
}

BaseballCardBraidedList::~BaseballCardBraidedList()
{
    //dtor
}
}

