#include <string> /* std::string */
#include "hashFunc.hpp" /* Hash Function */
#include "typesUtilites.hpp" /* Types Utilites Header */
  
size_t HashFunc::GetIndex(const keyType &a_key) const {
    return std::hash<keyType>{}(a_key);
}