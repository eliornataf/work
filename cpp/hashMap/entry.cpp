#include <string> /* String Header */
#include "bookInfo.hpp" /* Book Info Header */
#include "entry.hpp" /* Entry Header */
#include "typesUtilites.hpp" /* Types Utilties */

Entry::Entry(const keyType &a_key, const valueType &a_value) 
: m_key(a_key)
, m_value(a_value) {
}

Entry::~Entry() {
}

Entry::Entry(const Entry &a_other) 
: m_key(a_other.m_key)
, m_value(a_other.m_value) {
}

Entry &Entry::operator=(const Entry &a_other) {
    this->m_key = a_other.m_key;
    this->m_value = a_other.m_value;

    return *this;
}

keyType Entry::GetKey() const {
    return this->m_key;
}

valueType Entry::GetValue() const {
    return this->m_value;
}
