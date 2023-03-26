#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//x in [1.5, 3.2]

double f(double x) {
	return exp(-x) * sin(2 * x);
}
double trial_point_method(double a, double b) {
	vector<double> net;
	for (int i = 1; i <= 3; i++) {
		net.push_back(a + (b - a) / 4 * i);
	}

}
int main() {
	std::cout << "qwe" << std::endl;
	return 0;
}