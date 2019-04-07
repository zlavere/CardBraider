#ifndef BASEBALLCARDNODE_H
#define BASEBALLCARDNODE_H

#include "BaseballCard.h"
using namespace model;

namespace model
{
class BaseballCardNode
{
public:
    BaseballCardNode(BaseballCard& nodeReference);
    virtual ~BaseballCardNode();
    BaseballCard* getNodeReference() const;
    const string& getFirstName() const;
    const string& getLastName() const;
    int getYear() const;
    const string& getCondition() const;
    int getPrice() const;
    BaseballCardNode* getNextName() const;
    BaseballCardNode* getNextYear() const;
    BaseballCardNode* getNextCondition() const;
    void setNextName(BaseballCardNode& baseballCard);
    void setNextYear(BaseballCardNode& baseballCard);
    void setNextCondition(BaseballCardNode& baseballCard);

    //TODO Implement Delete card
    //void removeBaseballCard();

private:
    BaseballCard* nodeReference;
    BaseballCardNode* nextName;
    BaseballCardNode* nextCondition;
    BaseballCardNode* nextYear;
};
}
#endif // BASEBALLCARDNODE_H
