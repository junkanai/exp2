#ifdef FLOAT

void init_model() noexcept {
	rep(p, POP) {
		rep(d, DNA) {
			models[p][d] = rnd_dna_float();
		}
		rank[p] = p;
	}
}

inline int calc_answer(const float model[DNA], const float image[IN]) noexcept {
	float mid[MID];

	rep(m, MID) {
		mid[m] = *model;
		++model;
		rep(i, IN) {
			mid[m] += *model * image[i];
			++model;
		}
		if ( mid[m] < 0 ) mid[m] = 0;
	}

	float out[OUT];

	rep(o, OUT) {
		out[o] = *model;
		++model;
		rep(m, MID) {
			out[o] += mid[m] * (*model);
			++model;
		}
	}

	return (int)(std::max_element(out, out+10) - out);
}

inline int calc_score(const float model[DNA]) {
	int rtn = 0;
	rep(d, DATA) {
		int answer = calc_answer(model, images[d]);
		if ( answer == labels[d] ) rtn += 1;
	}
	return rtn;
}
#endif

#ifdef BINARY

void init_model() noexcept {
	rep(p, POP) {
		rep(d, DNA) {
			models[p][d] = rnd_dna_binary();
		}
		rank[p] = p;
	}
}
#endif

#ifdef TERNARY
void init_model() noexcept {
	rep(p, POP) {
		rep(d, DNA) {
			models[p][d] = rnd_dna_ternary();
		}
		rank[p] = p;
	}
}

inline int calc_answer(const int model[DNA], const int image[IN]) noexcept {
	int mid[MID];

	rep(m, MID) {
		mid[m] = *model;
		++model;
		rep(i, IN) {
			mid[m] += *model * image[i];
			++model;
		}
		if ( mid[m] < 0 ) mid[m] = 0;
	}

	int out[OUT];

	rep(o, OUT) {
		out[o] = *model;
		++model;
		rep(m, MID) {
			out[o] += mid[m] * (*model);
			++model;
		}
	}

	return (int)(std::max_element(out, out+10) - out);
}

inline int calc_score(const int model[DNA]) {
	int rtn = 0;
	rep(d, DATA) {
		int answer = calc_answer(model, images[d]);
		if ( answer == labels[d] ) rtn += 1;
	}
	return rtn;
}

inline int calc_sparse(const int model[DNA]) {
	int rtn = 0;
	rep(d, DNA) {
		if ( model[d] == 0 ) rtn += 1;
	}
	return rtn;
}

#endif

#ifndef TERNARY
void evaluate(float log[LOG]) {
	int sum = 0;

	rep(p, POP) {
		scores[p] = calc_score(models[p]);
		sum += scores[p];
	}

	std::sort(rank, rank+POP,
			[](size_t left, size_t right) -> bool {
			return scores[left] > scores[right];
			});

	set_best_to_log((float)scores[rank[0]] / DATA, log);
	set_ave_to_log((float)sum / (POP * DATA), log);
}

#else

void evaluate(float log[LOG]) {
	int sum = 0;

	rep(p, POP) {
		scores[p] = calc_score(models[p]);
		sparses[p] = calc_sparse(models[p]);
		sum += scores[p];
	}

	std::sort(rank, rank+POP,
			[](size_t left, size_t right) -> bool {
			return scores[left] > scores[right];
			});

	set_best_to_log((float)scores[rank[0]] / DATA, log);
	set_ave_to_log((float)sum / (POP * DATA), log);
}

void evaluate_by_scalar(float log[LOG]) {
	int sum = 0;

	rep(p, POP) {
		scores[p] = calc_score(models[p]);
		sparses[p] = calc_sparse(models[p]);
		sum += scores[p];
		// total_scores[p] = ((float)scores[p] / DATA) * 0.5 + ((float)sparses[p] / DNA) * 0.5;
		total_scores[p] = std::hypot(float(scores[p]) / DATA, float(sparses[p]) / DNA);
	}

	std::sort(rank, rank+POP,
			[](size_t left, size_t right) -> bool {
			return total_scores[left] > total_scores[right];
			});

	set_best_to_log((float)scores[rank[0]] / DATA, log);
	set_ave_to_log((float)sum / (POP * DATA), log);
}
#endif
