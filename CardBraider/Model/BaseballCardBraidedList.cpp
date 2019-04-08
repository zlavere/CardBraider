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

void BaseballCardBraidedList::setNameHead(BaseballCardNode& newHead)
{
    this->nameHead = &newHead;
}

void BaseballCardBraidedList::setYearHead(BaseballCardNode& newHead)
{
    this->yearHead = &newHead;
}

void BaseballCardBraidedList::setConditionHead(BaseballCardNode& newHead)
{
    this->conditionHead = &newHead;
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

    if(this->conditionHead == nullptr)
    {
        this->conditionHead = &newNode;
    }
    else
    {
        this->insertIntoConditionList(newNode, *this->conditionHead, *this->conditionHead);
    }
}

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

void BaseballCardBraidedList::insertIntoConditionList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode)
{
    if(newNode.getConditionValue() < currentNode.getConditionValue())
    {
        if(&currentNode == this->conditionHead)
        {
            newNode.setNextCondition(currentNode);
            this->conditionHead = &newNode;
        }
        else
        {
            newNode.setNextCondition(currentNode);
            previousNode.setNextCondition(newNode);
        }
    }
    else if (newNode.getConditionValue() == currentNode.getConditionValue() && toUpperCase(newNode.getLastName()) <= toUpperCase(currentNode.getLastName()))
    {
        if(&currentNode == this->conditionHead)
        {
                newNode.setNextCondition(currentNode);
                this->conditionHead = &newNode;
        }
        else
        {
            newNode.setNextCondition(currentNode);
            previousNode.setNextCondition(newNode);
        }
    }
    else if(currentNode.getNextCondition() == nullptr)
    {
        currentNode.setNextCondition(newNode);
    }
    else
    {
        this->insertIntoConditionList(newNode, *currentNode.getNextCondition(), currentNode);
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

BaseballCardNode* BaseballCardBraidedList::getConditionHead()
{
    return this->conditionHead;
}

void BaseballCardBraidedList::deleteNode(BaseballCardNode& node)
{
    BaseballCardNode* prevName = this->findPreviousInNameList(node, *this->nameHead);
    BaseballCardNode* prevYear = this->findPreviousInYearList(node, *this->yearHead);
    BaseballCardNode* prevCondition = this->findPreviousInConditionList(node, *this->conditionHead);

    prevName->setNextName(*node.getNextName());
    prevYear->setNextYear(*node.getNextYear());
    prevCondition->setNextCondition(*node.getNextCondition());

    BaseballCardNode* pNode = &node;

    delete pNode;
    pNode = nullptr;
}

BaseballCardNode* BaseballCardBraidedList::findPreviousInNameList(BaseballCardNode& node, BaseballCardNode& current)
{
    BaseballCardNode* previous = nullptr;
    if(this->nameHead == &node)
    {
        previous = this->nameHead;
        this->nameHead = previous->getNextName();
    }
    else if(current.getNextName() == &node)
    {
        previous = &current;
    }
    else
    {
        this->findPreviousInNameList(node, *current.getNextName());
    }

    return previous;
}

BaseballCardNode* BaseballCardBraidedList::findPreviousInYearList(BaseballCardNode& node, BaseballCardNode& current)
{
    BaseballCardNode* previous = nullptr;
    if(this->yearHead == &node)
    {
        previous = this->yearHead;
        this->yearHead = previous->getNextYear();
    }
    else if(current.getNextYear() == &node)
    {
        previous = &current;
    }
    else
    {
        this->findPreviousInYearList(node, *current.getNextYear());
    }
    return previous;
}

BaseballCardNode* BaseballCardBraidedList::findPreviousInConditionList(BaseballCardNode& node, BaseballCardNode& current)
{
    BaseballCardNode* previous = nullptr;
    if(this->conditionHead == &node)
    {
        previous = this->conditionHead;
        this->conditionHead = previous->getNextCondition();
    }
    else if(current.getNextCondition() == &node)
    {
        previous = &current;
    }
    else
    {
        this->findPreviousInConditionList(node, *current.getNextCondition());
    }
    return previous;
}

void BaseballCardBraidedList::deleteAllCards(BaseballCardNode* current)
{
    if(current != nullptr)
    {
        this->deleteAllCards(current->getNextName());
    }

    delete current;
    current = nullptr;
}

BaseballCardBraidedList::~BaseballCardBraidedList()
{
    this->deleteAllCards(this->nameHead);
}
}

