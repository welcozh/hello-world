#include <iostream>

using namespace std;

double a = 0.01;


int main(int argc, char *argv[])
{
	double b = 0.02;
	long long len = 10000000000;
	
	time_t start, end;
	
	start = time(NULL);
	for(long long i=0;i<len;i++)
	{
		b += 0.005;
	}
	
	end = time(NULL);

	cout << "Time-a: " << end - start << endl;

	start = time(NULL);
	for(long long i=0;i<len;i++)
	{
		b += 0.005;
	}
	
	end = time(NULL);

	cout << "Time-b: " << end - start << endl;

	return 1;
}
