#include <stdio.h> /* printf */
#include <string.h> /* strlen */

#define MATCH_IS_NOT_FOUND (0)
#define MATCH_IS_FOUND (1)

#define IS_NOT_SAME (0)
#define IS_SAME (1)
#define INDEX_IS_NOT_FOUND (-1)

char *Squeeze(char *str1, char *str2)
{	
	int i, j, k, isMatch;
	
	for (i = k = 0;str1[i] != '\0';++i)
	{
		isMatch = MATCH_IS_NOT_FOUND;
	
		for (j = 0;str2[j] != '\0';++j)
		{
			if (str1[i] == str2[j])
			{
				isMatch = MATCH_IS_FOUND;
				break;
			}
		}
		
		if (MATCH_IS_NOT_FOUND == isMatch)
		{
			str1[k] = str1[i];
			++k;
		}
	}
	
	str1[k] = '\0';
	
	return str1;
}

int Location(char *str1, char *str2)
{
	int i, j, isSame, x, y;
	
	for (i = 0;str1[i] != '\0';++i)
	{
		for (j = 0;str2[j] != '\0';++j)
		{
			if (str1[i] == str2[j])
			{
				isSame = IS_SAME;
			
				for (x = i, y = j;str2[y] != '\0';++x, ++y)
				{
					if (str1[x] != str2[y])
					{
						isSame = IS_NOT_SAME;
						break;
					}
				}
			
				if (isSame == IS_SAME)
				{
					return i;
				}
			}
			else
			{
				break;
			}
		}
	}
	
	return INDEX_IS_NOT_FOUND;
}

void SqueezeTest(void)
{
	/* Test 1 */
	
	char str1[] = "ABCDEF";
	char str2[] = "BKE";
	char *strAfterSqueeze;
	
	/* Test 2 */
	
	char str3[] = "ABCDEF";
	char str4[] = "ABCDEF";

	printf("***************Squeeze Func Test:***************\n\n");

	printf("Test 1:\n");

	strAfterSqueeze = Squeeze(str1, str2);
	
	printf("After the squeeze: %s\n", strAfterSqueeze);
	
	printf("\nTest 2:\n");
	
	strAfterSqueeze = Squeeze(str3, str4);
	
	printf("After the squeeze: %s\n", strAfterSqueeze);
}

void LocationTest(void)
{
	/* Test 1 */
	
	char *str1 = "ABCDEF";
	char *str2 = "CD";
	int foundIndex;
	
	/* Test 2 */
	
	char *str3 = "ABCDEF";
	char *str4 = "BKE";

	printf("\n***************Location Func Test:***************\n\n");

	printf("Test 1:\n");

	foundIndex = Location(str1, str2);

	printf("Found Index is: %d [-1 is not found]\n", foundIndex);
	
	printf("\nTest 2:\n");
	
	foundIndex = Location(str3, str4);

	printf("Found Index is: %d [-1 is not found]\n", foundIndex);
}


int main(void)
{	
	SqueezeTest();

	LocationTest();

	return 0;
}
