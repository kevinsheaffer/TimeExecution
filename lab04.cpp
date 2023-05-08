#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;

unsigned long long geom_suml (int x, int n);

unsigned long long geom_sum2 (int x, int n);

int main()
{
	int x = 1;
	int n = 1;

	cout << "Please enter x: ";
	cin >> x;

	cout << "Please enter n: ";
	cin >> n;

	using clock = chrono::steady_clock;

	clock::time_point start = clock::now();

	cout << geom_suml(x, n) << endl;

	clock::time_point end = clock::now();
	   
	clock::duration time_span = end - start;
	double nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
	cout << "The execution time is : " << nseconds << endl;

	start = clock::now();

	cout << geom_sum2(x, n) << endl;

	end = clock::now();

	time_span = end - start;
	nseconds = double(time_span.count()) * clock::period::num / clock::period::den;
	cout << "The execution time is : " << nseconds << endl;

	return 0;
}


unsigned long long geom_suml (int x, int n){
	unsigned long long result = 0;

	for(int i=0; i<=n; i++)
	{
		unsigned long long xpow = 1;
		for(int j=0; j<i; j++)
			xpow = xpow * x; 

		result += xpow;
	}

	return result;
}


unsigned long long geom_sum2 (int x, int n){
	unsigned long long result = 0;

	for(int i=0; i<=n; i++)
	{
		result = result * x + 1;
	}

	return result;
}
