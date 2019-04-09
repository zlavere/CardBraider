#include "BaseballCard.h"

namespace model
{

//
// Initializes a BaseballCard to store data on regarding the card.
//
// @param firstName Player's First Name
// @param lastName Player's Last Name
// @param year Year the card was released
// @param condition the Condition of the card.
// @param price value of the card in whole dollar ammount
// @precondition none
// @postcondition none
//
BaseballCard::BaseballCard(const string& firstName, const string& lastName, int year, Condition condition, int price)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->year = year;
    this->condition = condition;
    this->price = price;
}

//
// Returns the player featured on the card's first name.
//
// @precondition none
// @postcondition none
// @return string reference for the first name
//
const string& BaseballCard::getFirstName() const
{
    return this->firstName;
}

//
// Returns the player featured on the card's last name.
//
// @precondition none
// @postcondition none
// @return string reference for the last name
//
const string& BaseballCard::getLastName() const
{
    return this->lastName;
}

//
// Returns the condition of the card.
//
// @precondition none
// @postcondition none
// @return enum value of the card condition.
//
BaseballCard::Condition BaseballCard::getCondition() const
{
    return this->condition;
}

//
// Returns the year the card was released.
//
// @precondition none
// @postcondition none
// @return int value for the year
//
int BaseballCard::getYear() const
{
    return this->year;
}

//
// Returns the player featured on the card's first name.
//
// @precondition none
// @postcondition none
// @return int value for the value of the card in whole dollar values
//
int BaseballCard::getPrice() const
{
    return this->price;
}

BaseballCard::~BaseballCard()
{
}
}
