#define TERNARY
#include "../prelude.hpp"

int main() {
	init_mnist();
	init_model();
	init_log(__FILE__);

	rep(gen, GEN) {
		evaluate(logs[gen]);

		print_log(gen);

		elite_selection();

		reps(p, ELITE, POP) {
			tournament_selection();
			twopoint_crossover(parents[i_mom], parents[i_dad], models[p]);
		}

		mutation();
	}

	save_log();
}





