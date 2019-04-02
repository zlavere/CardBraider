#include "BaseballCardNode.h"

namespace model
{
BaseballCardNode::BaseballCardNode(BaseballCard& nodeReference)
{
    this->nodeReference = &nodeReference;
    this->nextName = nullptr;
    this->nextYear = nullptr;
    this->nextCondition = nullptr;
    this->prevName = nullptr;
    this->prevYear = nullptr;
    this->prevCondition = nullptr;
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

BaseballCardNode* BaseballCardNode::getPrevName() const
{
    return this->prevName;
}

BaseballCardNode* BaseballCardNode::getPrevCondition() const
{
    return this->prevCondition;
}

BaseballCardNode* BaseballCardNode::getPrevYear() const
{
    return this->prevYear;
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

void BaseballCardNode::setPrevName(BaseballCardNode& baseballCard)
{
    this->prevName = &baseballCard;
}

void BaseballCardNode::setPrevYear(BaseballCardNode& baseballCard)
{
    this->prevYear = &baseballCard;
}

void BaseballCardNode::setPrevCondition(BaseballCardNode& baseballCard)
{
    this->prevCondition = &baseballCard;
}

void BaseballCardNode::removeBaseballCard()
{
    if(this->nextName != nullptr)
    {
        this->nextName->setPrevName(*this->prevName);
    }

    if(this->nextYear != nullptr)
    {
        this->nextYear->setPrevYear(*this->prevYear);
    }

    if(this->nextCondition != nullptr)
    {
        this->nextCondition->setPrevCondition(*this->prevCondition);
    }

    if(this->prevName != nullptr)
    {
        this->prevName->setNextName(*this->nextName);
    }

    if(this->prevYear != nullptr)
    {
        this->prevYear->setNextYear(*this->nextYear);
    }

    if(this->prevCondition != nullptr)
    {
        this->prevCondition->setNextCondition(*this->nextCondition);
    }
    this->nextName = nullptr;
    this->nextYear = nullptr;
    this->nextCondition = nullptr;
    this->prevName = nullptr;
    this->prevYear = nullptr;
    this->prevCondition= nullptr;
    delete this->nodeReference;
    this->nodeReference = nullptr;
}

BaseballCardNode::~BaseballCardNode()
{
    //dtor
    this->removeBaseballCard();
}
}
