#include <iostream>
#include <numeric>
#include <array>

bool checkSum(int sumLeft[], int k)
{
	int r = true;
	for (int i = 0; i < k; i++)
	{
		if (sumLeft[i] != 0)
			r = false;
	}

	return r;
}

bool subsetSum(int S[], int n, int sumLeft[], int A[], int k)
{

	if (checkSum(sumLeft, k))
		return true;


	if (n < 0)
		return false;

	bool res = false;


	for (int i = 0; i < k; i++)
	{
		if (!res && (sumLeft[i] - S[n]) >= 0)
		{

			A[n] = i + 1;


			sumLeft[i] = sumLeft[i] - S[n];


			res = subsetSum(S, n - 1, sumLeft, A, k);


			sumLeft[i] = sumLeft[i] + S[n];
		}
	}


	return res;
}


void partition(int S[], int n, int k)
{

	if (n < k)
	{
		std::cout << "Diamond(s) Can`t Be Distributed To " << k <<" Person Equally!"<<std::endl;
		return;
	}


	int sum = std::accumulate(S, S + n, 0);

 	int A[n], sumLeft[k];


	for (int i = 0; i < k; i++)
		sumLeft[i] = sum/k;


	bool res = !(sum % k) && subsetSum(S, n - 1, sumLeft, A, k);

	if (!res)
	{
		std::cout << "Diamond(s) Can`t Be Distributed To " << k <<" Person Equally!"<<std::endl;
		return;
	}


	for (int i = 0; i < k; i++)
	{
		std::cout << "Diamond(s) Distributed to Person " << i+1 << " is: ";
	   	for (int j = 0; j < n; j++)
	 		if (A[j] == i + 1)
	 			std::cout << S[j] << " ";
	 	std::cout << std::endl;
	}
}


int main()
{
int *countDiamondPointer=NULL;
int sumUserEnterDiamonds;
std::cout << "*************************DISTRIBUTION OF DIAMOND(s)***************************" <<std::endl;
 printf("\n");

 std::cout << "==============================================================================" <<std::endl;
 std::cout << "How many person are there to distribute the diamond(s)?" <<std::endl;
	int inputperson;
	std::cin >> inputperson;
	int k = inputperson;
std::cout << "==============================================================================" <<std::endl;


std::cout << "==============================================================================" <<std::endl;
	std::cout << "How many Diamond(s), You are going to enter?" <<std::endl;
	int totalCountDiamonds;
	std::cin >> totalCountDiamonds;
std::cout << "==============================================================================" <<std::endl;

countDiamondPointer=new int[totalCountDiamonds];

int x;
int S[totalCountDiamonds];

int totalUserDiamondsinArray=0;

for(int x = 0; x < totalCountDiamonds ; x++)
{

    printf("Insert Number of Diamond(s) For: %d \n",x+1);

    scanf(" %d", &S[x]);
     printf("\nDiamond(s) Inserted! \n");
std::cout << "==============================================================================" <<std::endl;
}

for(int x = 0; x < totalCountDiamonds ; x++)
{
   totalUserDiamondsinArray=S[x];
 //printf("%d,",totalUserDiamondsinArray);

 	S[totalCountDiamonds] = {totalUserDiamondsinArray};
//printf("%d,",S[totalCountDiamonds]);

}
printf("\n");
std::cout << "**********************************End*****************************************" <<std::endl;
printf("\n");
int n = sizeof(S) / sizeof(S[0]);
partition(S, n, k);
std::cout << "=============================== By Ayushma ===================================" <<std::endl;
delete []S;
return 0;

}
