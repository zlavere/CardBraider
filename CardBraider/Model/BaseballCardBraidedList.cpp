#include "BaseballCardBraidedList.h"
using namespace model;
#include "Utils.h"

namespace model
{
//
// Handles logic for braiding a list of BaseballCardNode(s) as well as references to the heads of each braid.
//
BaseballCardBraidedList::BaseballCardBraidedList()
{
    this->nameHead = nullptr;
    this->yearHead = nullptr;
    this->conditionHead = nullptr;
}

//
// Adds a BaseballCard to the current collection of baseball cards
//
// @param newNode the node that reference the new BaseballCard to be added
// @precondition none
// @postcondition Collection of cards now contains the card.
//
void BaseballCardBraidedList::addBaseballCard(BaseballCardNode& newNode)
{
    this->insertBaseballCard(newNode);
}

//
// Sets the head of the Last Name based braid in the braided list.
//
// @param the BaseballCardNode to be set as the head of the NameList
// @precondition none
// @postcondition newHead the nameHead assigned to newHead at the head of the linked list.
//
void BaseballCardBraidedList::setNameHead(BaseballCardNode& newHead)
{
    this->nameHead = &newHead;
}

//
// Sets the head of the year based braid in the braided list.
//
// @param the BaseballCardNode to be set as the head of the Year List.
// @precondition none
// @postcondition newHead the newHead is now at the head of the year linked list.
//
void BaseballCardBraidedList::setYearHead(BaseballCardNode& newHead)
{
    this->yearHead = &newHead;
}

//
// Sets the head of the condition based braid in the braided list.
//
// @param the BaseballCardNode to be set as the head of the Condition List.
// @precondition none
// @postcondition newHead the newHead is now at the head of the condition linked list.
//
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

//
// Returns a pointer to the node at the head of the name list.
//
// @precondition none
// @postcondition none
// @return a pointer to the node at the head of the name list.
//
BaseballCardNode* BaseballCardBraidedList::getNameHead()
{
    return this->nameHead;
}

//
// Returns a pointer to the node at the head of the year list.
//
// @precondition none
// @postcondition none
// @return a pointer to the node at the head of the year list.
//
BaseballCardNode* BaseballCardBraidedList::getYearHead()
{
    return this->yearHead;
}

//
// Returns a pointer to the node at the head of the condition list.
//
// @precondition none
// @postcondition none
// @return a pointer to the node at the head of the condition list.
//
BaseballCardNode* BaseballCardBraidedList::getConditionHead()
{
    return this->conditionHead;
}

//
// Deletes a BaseballCardNode from the braided list.
//
// @precondition none
// @postcondition node is removed from the braided list.
//
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

BaseballCardNode* BaseballCardBraidedList::findPreviousInYearList(BaseballCardNode& node, BaseballCardNode& current) //TODO: Investigate optimizing this algorithm
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
//
// private
// Destroys all cards in the braided list on delete of Braidedlist
//
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

    this->nameHead = nullptr;
    this->yearHead = nullptr;
    this->conditionHead = nullptr;
}
}

