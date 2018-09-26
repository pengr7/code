#include <iostream>
#include <vector>
#include <random>
#include <map>
using namespace std;

class belief_network {
	public:
		belief_network() {
			state["cloudy"] = false;
			state["sprinker"] = false;
			state["rain"] = false;
			state["wet_grass"] = false;
		}
		map<string, bool> state;
};

belief_network prior_sample(belief_network bn) {
	default_random_engine generator(rand());
	uniform_real_distribution<double> distribution;
	if (distribution(generator) < .50)
		bn.state["cloudy"] = true;
	if (bn.state["cloudy"] == true && distribution(generator) < .10
		|| bn.state["cloudy"] == false && distribution(generator) < .50)
		bn.state["sprinker"] = true;
	if (bn.state["cloudy"] == true && distribution(generator) < .80
		|| bn.state["cloudy"] == false && distribution(generator) < .20)
		bn.state["rain"] = true;
	if (bn.state["sprinker"] == true && bn.state["rain"] == true && distribution(generator) < .99
		|| bn.state["sprinker"] == true && bn.state["rain"] == false && distribution(generator) < .90
		|| bn.state["sprinker"] == false && bn.state["rain"] == true && distribution(generator) < .90
		|| bn.state["sprinker"] == false && bn.state["rain"] == false && distribution(generator) < .01)
		bn.state["wet_grass"] = true;
	return bn;
}

bool e(belief_network bn) {
	return bn.state["sprinker"] == true;
}

vector<double> normalize(vector<int> N) {
	return {N[0] / (double)(N[0] + N[1]), N[1] / (double)(N[0] + N[1])};
}

vector<double> rejection_sampling(string X, bool (*e)(belief_network), belief_network bn, int n) {
	vector<int> N(2, 0);
	for (int j = 1; j <= n; j++) {
		belief_network x = prior_sample(bn);
		if (e(x))
			N[1 - x.state[X]]++;
	}
	return normalize(N);
}


void print() {
	belief_network bn;
	vector<double> result = rejection_sampling("rain", e, bn, 100);
	cout << "Rejection sampling: P(Rain | Sprinkler = true)" << endl;
	cout << "<" << result[0] << ", " << result[1] << ">" << endl;
}

int main() {
	print();
	return 0;
}

