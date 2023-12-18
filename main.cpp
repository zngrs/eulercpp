#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

using namespace std;

double randd() {
	return static_cast<double>(rand()) / (RAND_MAX + 1.0);
}

double summation(const vector<double>& of) {
	if (of.empty()) {
		return 0;
	} else {
		double sum = 0;
		for (const auto& item : of) {
			sum += item;
		}
		return sum;
	}
}

int n_value() {
	// Seed the random number generator

	vector<double> v = {};
	while (summation(v) < 1.0) {
		v.push_back(randd());
	}

	return v.size();
}

int main() {
	float resolution = 10000.00000f; // Use float for resolution
	float sum = 0.0f; // Use float for sum

	for (int i = 0; i < resolution; i++) {
		srand(i * (unsigned)time( NULL ));
		sum += n_value();
		cout << "Current approximation: " << sum / i << endl;
	}

	cout << sum << endl;
	cout << sum / resolution << endl;

	const double EulerConstant = std::exp(1.0);
	double accuracy = (sum / resolution) / EulerConstant * 100;
	cout << accuracy << "% accurate" << endl;



	return 0;
}

