#include "cdrHarvester.hpp" // CDR Harverster Header

int main() {
    CDRHarvester cdrHarvester("127.0.0.1", 4040);
    
    cdrHarvester.RunHarvester();

    return 0;
}