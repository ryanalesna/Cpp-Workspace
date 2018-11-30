
#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H
#include <iostream>


class Relationship {
public: 
	Relationship() {}
	Relationship(int i, std::string word) {
		number = i;
		str = word;
	}
	int number;
	std::string str;
	
};

/*Relationship A[2];
int main()
{
	A[0] = Relationship(3, "Fizz");
	A[1] = Relationship(5, "Buzz");
	A[2] = Relationship(7, "Pop");


	for (int i = 1; i <= 100; i++)
	{
		bool bFoundRelationship = false;
		for (int j = 0; j < 2; j++)
		{
			if (i % A[j].number == 0)
			{
				bFoundRelationship = true;
				printf("%s", &A[j].str[0]);
			}
		}
		
		if (!bFoundRelationship)
		{
			printf("%i", i);
		}

		printf("\n");
	}
	system("pause");
}
*/

#endif // FIZZBUZZ_H