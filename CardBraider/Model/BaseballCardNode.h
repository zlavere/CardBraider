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
    BaseballCardNode* getPrevName() const;
    BaseballCardNode* getPrevCondition() const;
    BaseballCardNode* getPrevYear() const;
    void setNextName(BaseballCardNode& baseballCard);
    void setNextYear(BaseballCardNode& baseballCard);
    void setNextCondition(BaseballCardNode& baseballCard);
    void setPrevName(BaseballCardNode& baseballCard);
    void setPrevYear(BaseballCardNode& baseballCard);
    void setPrevCondition(BaseballCardNode& baseballCard);
    void removeBaseballCard();

private:
    BaseballCard* nodeReference;
    BaseballCardNode* nextName;
    BaseballCardNode* nextCondition;
    BaseballCardNode* nextYear;
    BaseballCardNode* prevName;
    BaseballCardNode* prevCondition;
    BaseballCardNode* prevYear;
};
}
#endif // BASEBALLCARDNODE_H
