#include "DeleteCardController.h"
#include "Utils.h"

namespace controller
{
//
// Handles the deletion of a BaseballCardNode
//
DeleteCardController::DeleteCardController()
{
    this->baseballCards = nullptr;
}

//
// Sets the BaseballCardBraidedList from which nodes may need to be removed.
//
// @param the BaseballCardBraidedList.
//
void DeleteCardController::setBaseballCards(BaseballCardBraidedList& baseballCards)
{
    this->baseballCards = &baseballCards;
}

//
// Initiates the process by which a card will be deleted and references updated based on the player last name.
//
// @param lastName the player's last name input to be deleted.
// @precondition none
// @postcondition All nodes where the players last name matches @lastName are removed from the BaseballCardBraidedList
//
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

