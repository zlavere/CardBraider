#include "BaseballCardNode.h"

namespace model
{
BaseballCardNode::BaseballCardNode(BaseballCard& nodeReference)
{
    this->nodeReference = &nodeReference;
    this->nextName = nullptr;
    this->nextYear = nullptr;
    this->nextCondition = nullptr;
}

const string& BaseballCardNode::getFirstName() const
{
    return this->nodeReference->getFirstName();
}

const string& BaseballCardNode::getLastName() const
{
    return this->nodeReference->getLastName();
}

const int BaseballCardNode::getConditionValue() const
{
    return this->nodeReference->getCondition();
}

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

int BaseballCardNode::getPrice() const
{
    return this->nodeReference->getPrice();
}

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
