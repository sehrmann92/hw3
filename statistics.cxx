#include <cmath>
#include <iostream>
#include <cstdlib> 		//package for random number
#include <ctime>		//package for time to create more random number;

using namespace std;

void randnr(double* p, int N);
void calc(double& mean, double& var,double* p, int N);

int main()
{
   const int N = 100;
   double p[N];
   double mean, var;

   randnr(p,N);
   calc(mean,var,p,N);
   cout << "Mean = " << mean << endl;
   cout << "Variance = " << var << endl;

   return 0;
}

//construction random number with pointer
void randnr(double* p, int N)
{
	srand(time(NULL)); //create (really) random numbers
	for(int i=0;i<N;i++)
		p[i]=double(rand())/RAND_MAX;
}

//calculation mean value and variance with refernce, get data with pointer
void calc(double& mean, double& var,double* p, int N)
{
	mean=0.0;
	for(int i=0;i<N;i++)
		mean+=p[i];
	mean/=N;
	
	var=0.0;
	for(int i=0;i<N;i++)
		var+=(p[i]-mean)*(p[i]-mean);
	var/=N;
}