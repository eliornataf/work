#include "billingTask.hpp" // Billing Task Header
#include "../objects/billingObject.hpp" // Billing Object Header
#include "../cdrConvector/cdrConvertor.hpp" // CDR Convector Header

BillingTask::BillingTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager)
: m_cdr(a_cdr)
, m_dataBaseManager(a_dataBaseManager)  {
}

void BillingTask::Execute() const {
    CDRConvertor newConvector(this->m_cdr); 

    BillingObject newBillingObject = newConvector.CreateBillingObject();  
    
    this->m_dataBaseManager->Add(newBillingObject);
}
