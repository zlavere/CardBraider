#include "DeleteCardController.h"
#include "Utils.h"

namespace controller
{
DeleteCardController::DeleteCardController()
{
    this->baseballCards = nullptr;
}

void DeleteCardController::setBaseballCards(BaseballCardBraidedList& baseballCards)
{
    this->baseballCards = &baseballCards;
}

void DeleteCardController::deleteCardsByLastName(const string& lastName)
{
    this->deleteCards(lastName, *this->baseballCards->getNameHead());
}

void DeleteCardController::deleteCards(const string& lastName, BaseballCardNode& current)
{
    if(current.getNextName() != nullptr)
    {
        this->deleteCards(lastName, *current.getNextName());
    }

    if(toUpperCase(current.getLastName()) == toUpperCase(lastName))
    {
        this->baseballCards->deleteNode(current);
    }
}

DeleteCardController::~DeleteCardController()
{
    //dtor
}
}

