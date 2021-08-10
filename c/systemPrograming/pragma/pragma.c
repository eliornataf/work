#include <stdio.h> /* printf */

struct SWithoutPragma
{
    char m_ch;
    double m_dVar;
    char m_ch2;
};

#pragma pack (push, 1)

struct SWithPragma
{
    char m_ch;
    double m_dVar;
    char m_ch2;
};

#pragma pack (pop)

int main(void)
{
    printf("The size of struct without pragma: %ld\n", sizeof(struct SWithoutPragma));
    printf("The size of struct with pragma: %ld\n", sizeof(struct SWithPragma));

    return 0;
}