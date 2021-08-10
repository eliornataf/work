#include "dataBaseManager.hpp" // Data Base Manager Header 

DataBaseManager::DataBaseManager() 
: m_billingDataBase()
, m_interOperatorSettlementDataBase()
, m_linksGraphDataBase() {
}

void DataBaseManager::Add(const BillingObject &a_billingObject) {
    std::unordered_map<unsigned long, BillingObject>::iterator mapIter = this->m_billingDataBase.find(a_billingObject.GetIMSI());

    if (this->m_billingDataBase.end() != mapIter) {
        (*mapIter).second += a_billingObject;
    }   
    else {
        this->m_billingDataBase.insert(std::make_pair(a_billingObject.GetIMSI(), a_billingObject));
    }
}

void DataBaseManager::Add(const InterOperatorSettlementObject &a_interOperatorSettlementObject) {
    std::unordered_map<unsigned long, InterOperatorSettlementObject>::iterator mapIter = this->m_interOperatorSettlementDataBase.find(a_interOperatorSettlementObject.GetIMSI());

    if (this->m_interOperatorSettlementDataBase.end() != mapIter) {
        (*mapIter).second += a_interOperatorSettlementObject;
    }   
    else {
        this->m_interOperatorSettlementDataBase.insert(std::make_pair(a_interOperatorSettlementObject.GetIMSI(), a_interOperatorSettlementObject));
    }
}

void DataBaseManager::Add(const LinksGraphObject &a_linksGraphObject) {
    std::unordered_map<unsigned long, LinksGraphObject>::iterator mapIter = this->m_linksGraphDataBase.find(a_linksGraphObject.GetIMSI());

    if (this->m_linksGraphDataBase.end() != mapIter) {
        (*mapIter).second += a_linksGraphObject;
    }   
    else {
        this->m_linksGraphDataBase.insert(std::make_pair(a_linksGraphObject.GetIMSI(), a_linksGraphObject));
    }
}