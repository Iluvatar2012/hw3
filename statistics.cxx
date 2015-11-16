#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
//--------------------------------------------------
// plenty of lines here
//--------------------------------------------------
void fill (double* const p, const int N) {

	// initialize random number generator with current time stamp
	srand(time(NULL));

	// iterate over all entries
	for (int i=0; i<N; i++)
		p[i] = rand()/(1.*RAND_MAX);
}


void statistics (const double* const p, const int N, double& mean, double& var) {

	// reinitialize variables
	mean = 0;
	var  = 0;

	// iterate the mean of the distribution
	for (int i=0; i<N; i++) {
		mean += p[i];
	}

	mean /= N;

	// iterate the variance of the distribution
	for (int i=0; i<N; i++) {
		var += (p[i] - mean)*(p[i] - mean);
	}

	var /= N;
}


int main(){

	const int N = 100;
	double p[N];

	double mean, var;

	// fill the array with random numbers, do statistical shit
	fill(p, N);
	statistics(p, N, mean, var);

	cout << "Mean = " << mean << endl;
	cout << "Variance = " << var << endl;

	return 0;
}
