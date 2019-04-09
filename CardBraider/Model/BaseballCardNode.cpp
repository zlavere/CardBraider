#include "BaseballCardNode.h"

namespace model
{
//
// Represents a link node in a braided list by a referenced BaseballCard's player's last name, publication year, and condition
//
BaseballCardNode::BaseballCardNode(BaseballCard& nodeReference)
{
    this->nodeReference = &nodeReference;
    this->nextName = nullptr;
    this->nextYear = nullptr;
    this->nextCondition = nullptr;
}

//
// Gets a string representation of the first name of the BaseballCard's player for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return string representation of the first name of the BaseballCard's player.
//
const string& BaseballCardNode::getFirstName() const
{
    return this->nodeReference->getFirstName();
}
//
// Gets a string representation of the last name of the BaseballCard's player for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return string representation of the last name of the BaseballCard's player.
//
const string& BaseballCardNode::getLastName() const
{
    return this->nodeReference->getLastName();
}

//
// Gets a integer representation of the Condition of the BaseballCard based on BaseballCard::Condition enum for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return integer representation / description of the Condition of the BaseballCard
//
const int BaseballCardNode::getConditionValue() const
{
    return this->nodeReference->getCondition();
}

//
// Gets a string representation of the Condition of the BaseballCard based on BaseballCard::Condition enum for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return string representation / description of the Condition of the BaseballCard
//
const string& BaseballCardNode::getConditionDescription() const
{
    int condition = this->nodeReference->getCondition();
    string* conditionDescription = new string("");
    if (condition == BaseballCard::PRISTINE)
    {
        *conditionDescription = "Pristine";
    }
    else if(condition == BaseballCard::EXCELLENT)
    {
        *conditionDescription = "Excellent";
    }
    else if(condition == BaseballCard::GOOD)
    {
        *conditionDescription = "Good";
    }
    else if(condition == BaseballCard::POOR)
    {
        *conditionDescription = "Poor";
    }
    else if(condition == BaseballCard::MINT)
    {
        *conditionDescription = "Mint";
    }
    else
    {
        *conditionDescription = "Unknown";
    }

    return *conditionDescription;
}

//
// Gets an integer representation of the value of the BaseballCard in whole dollar amounts for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return integer representation of the value of the BaseballCard in whole dollar amounts.
//
int BaseballCardNode::getPrice() const
{
    return this->nodeReference->getPrice();
}

//
// Gets an integer representation of the year the BaseballCard was published for the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return integer representation of the year the BaseballCard was published.
//
int BaseballCardNode::getYear() const
{
    return this->nodeReference->getYear();
}

//
// BaseballCardNode referenced as the next in the name linked list.
//
// @precondition none
// @postcondition none
// @return pointer to the BaseballCardNode referenced as the next in the name linked list.
//
BaseballCardNode* BaseballCardNode::getNextName() const
{
    return this->nextName;
}

//
// BaseballCardNode referenced as the next in the year linked list.
//
// @precondition none
// @postcondition none
// @return pointer to the BaseballCardNode referenced as the next in the year linked list.
//
BaseballCardNode* BaseballCardNode::getNextYear() const
{
    return this->nextYear;
}

//
// BaseballCardNode referenced as the next in the condition linked list.
//
// @precondition none
// @postcondition none
// @return pointer to the BaseballCardNode referenced as the next in the condition linked list.
//
BaseballCardNode* BaseballCardNode::getNextCondition() const
{
    return this->nextCondition;
}

//
// Returns the BaseballCard referenced by this node.
//
// @precondition none
// @postcondition none
// @return pointer to the baseballCard referenced by this node.
//
BaseballCard* BaseballCardNode::getNodeReference() const
{
    return this->nodeReference;
}

//
// Sets the next link in the name linked list braid
//
// @param baseballCard to be assigned as the next node.
// @precondition none
// @postcondition The node has been set to the next node following this node in the linked list braid for name
//
void BaseballCardNode::setNextName(BaseballCardNode& baseballCard)
{
    this->nextName = &baseballCard;
}

//
// Sets the next link in the year linked list braid
//
// @param baseballCard to be assigned as the next node.
// @precondition none
// @postcondition The node has been set to the next node following this node in the linked list braid for year
//
void BaseballCardNode::setNextYear(BaseballCardNode& baseballCard)
{
    this->nextYear = &baseballCard;
}

//
// Sets the next link in the condition linked list braid
//
// @param baseballCard to be assigned as the next node.
// @precondition none
// @postcondition The node has been set to the next node following this node in the linked list braid for condtion
//
void BaseballCardNode::setNextCondition(BaseballCardNode& baseballCard)
{
    this->nextCondition = &baseballCard;
}

BaseballCardNode::~BaseballCardNode()
{
    delete this->nodeReference;
    this->nodeReference = nullptr;
}
}
