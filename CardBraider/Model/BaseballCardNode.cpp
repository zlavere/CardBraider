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

const string& BaseballCardNode::getCondition() const
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
    else {
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

BaseballCardNode* BaseballCardNode::getNextName() const
{
    return this->nextName;
}

BaseballCardNode* BaseballCardNode::getNextYear() const
{
    return this->nextYear;
}

BaseballCardNode* BaseballCardNode::getNextCondition() const
{
    return this->nextCondition;
}

BaseballCard* BaseballCardNode::getNodeReference() const
{
    return this->nodeReference;
}

void BaseballCardNode::setNextName(BaseballCardNode& baseballCard)
{
    this->nextName = &baseballCard;
}

void BaseballCardNode::setNextYear(BaseballCardNode& baseballCard)
{
    this->nextYear = &baseballCard;
}

void BaseballCardNode::setNextCondition(BaseballCardNode& baseballCard)
{
    this->nextCondition = &baseballCard;
}

BaseballCardNode::~BaseballCardNode()
{
    //dtor
    //this->removeBaseballCard();
}
}
