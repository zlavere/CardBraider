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
    void insertIntoNameList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode);
    void insertIntoConditionList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode);
    void insertIntoYearList(BaseballCardNode& newNode, BaseballCardNode& currentNode, BaseballCardNode& previousNode);
    void insertBaseballCard(BaseballCardNode& newNode);
    void insertIntoYearList(BaseballCardNode& newNode, BaseballCardNode& currentNode);
    void deleteAllCards(BaseballCardNode* current);

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
