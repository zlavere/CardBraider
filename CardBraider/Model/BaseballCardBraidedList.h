#ifndef BASEBALLCARDBRAIDEDLIST_H
#define BASEBALLCARDBRAIDEDLIST_H

#include "BaseballCardNode.h"
using namespace model;

namespace model
{
class BaseballCardBraidedList
{
private:
    BaseballCardNode* nameHead;
    BaseballCardNode* yearHead;
    BaseballCardNode* conditionHead;
    BaseballCardNode* tail;
    void insertIntoNameList(BaseballCardNode& newNode, BaseballCardNode& currentNode);
    void insertIntoConditionList(BaseballCardNode& newNode, BaseballCardNode& currentNode);
    void insertIntoYearList(BaseballCardNode& newNode, BaseballCardNode& currentNode);
    void insertBaseballCard(BaseballCardNode& newNode);

public:
    BaseballCardBraidedList();
    virtual ~BaseballCardBraidedList();
    void addBaseballCard(BaseballCardNode& newCard);
    BaseballCardNode* getNameHead();
    BaseballCardNode* getYearHead();
    BaseballCardNode* getConditionHead();
    BaseballCardNode* getTail();

};
}


#endif // BASEBALLCARDBRAIDEDLIST_H
