#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int *ptr;
	ptr = (int*) malloc(5*sizeof(int));

	if(!ptr)
	{
		cout << "Memory Allocation Failed";
		exit(1);
	}
	cout << "Initializing values..." << endl << endl;

	for (int i=0; i<5; i++)
	{
		ptr[i] = i*2+1;
	}
	cout << "Initialized values" << endl;

	for (int i=0; i<5; i++)
	{
		/* ptr[i] and *(ptr+i) can be used interchangeably */
		cout << *(ptr+i) << endl;
	}

	free(ptr);
	return 0;
}