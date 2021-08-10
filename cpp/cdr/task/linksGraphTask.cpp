#include "../cdrConvector/cdrConvertor.hpp" // CDR Convector Header
#include "../objects/linksGraphObject.hpp" // Links Graph Object Header
#include "../task/linksGraphTask.hpp" // Links Graph Task Header

LinksGraphTask::LinksGraphTask(const CDR &a_cdr, DataBaseManager *a_dataBaseManager) 
: m_cdr(a_cdr)
, m_dataBaseManager(a_dataBaseManager) {
}

void LinksGraphTask::Execute() const {
    CDRConvertor newConvector(this->m_cdr); 
    
    LinksGraphObject newLinksGraphObject = newConvector.CreateLinksGraphObject();  

    this->m_dataBaseManager->Add(newLinksGraphObject);
}