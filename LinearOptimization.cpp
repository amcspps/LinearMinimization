#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//x in [1.5, 3.2]

double f(double x) {
	return exp(-x) * sin(2 * x);
}
pair<int, double> trial_point_method(double a, double b, double eps) {
	vector<double> net;
	double min = 0;
	double counter = 0;
	do {
		for (int i = 1; i <= 3; i++) {
			net.push_back(a + (b - a) / 4 * i);
		}
		if (f(net[0]) < f(net[1])) {
			counter += 2;
			a = a;
			b = net[1];
			min = (a + net[1]) / 2;
		}
		if (f(net[0]) > f(net[1])) {
			counter += 3;
			if (f(net[1]) < f(net[2])) {
				a = net[0];
				b = net[2];
				min = (net[0] + net[2]) / 2;
			}
			else {
				a = net[1];
				b = b;
				min = (net[1] + b) / 2;
			}
		}
		net.clear();
	} while (b - a > eps);
	return { counter, min };
}
int main() {
	for (double eps = 0.1; eps > 0.0001; eps /= 10) {
		pair<int, double> result = trial_point_method(1.5, 3.2, eps);
		cout << "precision: " << eps << endl;
		cout << "function call counter: " << result.first << endl;
		cout << "result: " << result.second << endl;
		cout << "|x - x_acc|: " << fabs(result.second - 2.12437) << endl;
		cout << "|f(x) - f(x_acc)|: " << fabs(f(result.second) - f(2.12437)) << endl;
		cout << endl;
	}
	
	return 0;
}