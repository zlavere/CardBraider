#ifndef DELETECARDCONTROLLER_H
#define DELETECARDCONTROLLER_H

#include "BaseballCardNode.h"
#include "BaseballCardBraidedList.h"
using namespace model;

namespace controller
{
class DeleteCardController
{
private:
    BaseballCardBraidedList* baseballCards;

public:
    DeleteCardController();
    virtual ~DeleteCardController();
    void deleteCardsByLastName(const string& lastName);
    void deleteCards (const string& lastName, BaseballCardNode& current);
    void setBaseballCards(BaseballCardBraidedList& baseballCards);
};
}


#endif // DELETECARDCONTROLLER_H
