/*****************************************************************************
* File Name: Data Base Manager
* Written by: Elior Nataf
* Date: 20/6/21
*****************************************************************************/

/*------------------------------- Header Guard ------------------------------*/

#ifndef __DATA_BASE_MANAGER_HPP__
#define __DATA_BASE_MANAGER_HPP__

/*------------------------------- Header Files ------------------------------*/

#include <unordered_map> // std::unordered_map
#include "../objects/billingObject.hpp" // Billing Object Header
#include "../objects/interOperatorSettlementObject.hpp" // Inter Operator Settlement Object Header
#include "../objects/linksGraphObject.hpp" // Links Graph Object Header

/*-------------------------------- Structure -------------------------------*/

class DataBaseManager {
public:
    // Constructor

    DataBaseManager();

    // Destructor

    ~DataBaseManager() = default;

    // Copy Constructor

    DataBaseManager(const DataBaseManager &a_other) = default;

    // Assignment Operator

    DataBaseManager &operator=(const DataBaseManager &a_other) = default;

    // Methods

    void Add(const BillingObject &a_billingObject);
    void Add(const InterOperatorSettlementObject &a_interOperatorSettlementObject);
    void Add(const LinksGraphObject &a_linksGraphObject);

    void Load() const; // TODO
    void Save() const; // TODO

private:
    // Class Members

    std::unordered_map<unsigned long, BillingObject> m_billingDataBase;
    std::unordered_map<unsigned long, InterOperatorSettlementObject> m_interOperatorSettlementDataBase;
    std::unordered_map<unsigned long, LinksGraphObject> m_linksGraphDataBase;
};

#endif /* __DATA_BASE_MANAGER_HPP__ */
