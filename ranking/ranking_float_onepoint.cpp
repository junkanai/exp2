#include "../prelude.hpp"

int main() {
	init_mnist();
	init_model_float();
	init_log(__FILE__);

	rep(gen, GEN) {
		evaluate(logs[gen]);

		print_log(gen);

		elite_selection();

		reps(p, ELITE, POP) {
			ranking_selection();
			onepoint_crossover(parents[i_mom], parents[i_dad], models[p]);
		}

		mutation_float();
	}

	save_log();
}
