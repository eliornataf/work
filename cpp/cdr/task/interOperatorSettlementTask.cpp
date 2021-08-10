#include "../cdrConvector/cdrConvertor.hpp" // CDR Convector Header
#include "../objects/interOperatorSettlementObject.hpp" // Inter Operator Settlement Object Header
#include "../task/interOperatorSettlementTask.hpp" // Inter Operator Settlement Task Header

InterOperatorSettlementTask::InterOperatorSettlementTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager) 
: m_cdr(a_cdr) 
, m_dataBaseManager(a_dataBaseManager) {
}

void InterOperatorSettlementTask::Execute() const {
    CDRConvertor newConvector(this->m_cdr); 
    
    InterOperatorSettlementObject newInterOperatorSettlementObject = newConvector.CreateInterOperatorSettlementObject();  

    this->m_dataBaseManager->Add(newInterOperatorSettlementObject);
}