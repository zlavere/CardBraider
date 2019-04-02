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
    this->tail = nullptr;
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
    } else
    {
        this->insertIntoNameList(newNode, *this->nameHead);
    }

}

// TODO (zach#1#): Add same method for price and year if new.year < curr.year } else if { new.year <= curr.year && new.lastName < curr.lastname

void BaseballCardBraidedList::insertIntoNameList(BaseballCardNode& newNode, BaseballCardNode& currentNode)
{

    if(toUpperCase(newNode.getLastName()) < toUpperCase(currentNode.getLastName()))
    {
        if(&currentNode == this->nameHead)
        {
            this->nameHead->setPrevName(newNode);
            newNode.setNextName(*this->nameHead);
            this->nameHead = &newNode;
        }
        else
        {
            newNode.setNextName(currentNode);
            newNode.setPrevName(*currentNode.getPrevName());
            currentNode.getPrevName()->setNextName(newNode);
            currentNode.setPrevName(newNode);
        }
    }
    else if(currentNode.getNextName() == nullptr)
    {
        currentNode.setNextName(newNode);
        newNode.setPrevName(*this->tail);
        this->tail = &newNode;
    }
    else
    {
        this->insertIntoNameList(newNode, *currentNode.getNextName());
    }
}

BaseballCardNode* BaseballCardBraidedList::getNameHead()
{
    return this->nameHead;
}

BaseballCardBraidedList::~BaseballCardBraidedList()
{
    //dtor
}
}

