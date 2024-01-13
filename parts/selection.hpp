void elite_selection() noexcept {
	rep(p, POP) rep(d, DNA) {
		parents[p][d] = models[p][d];
	}

	rep(e, ELITE) rep(d, DNA) {
		models[e][d] = parents[rank[e]][d];
	}
}

inline void ranking_selection() noexcept {
	bool selected = false;
	float tmp = rnd();

	rep(r, RANKED) {
		if ( tmp <= SELECT_RATE[r] ) {
			i_mom = r; selected = true; break;
		}
	}
	if ( !selected ) {
		i_mom = rnd_size_t(ELITE, POP - DISPOSE);
	}

	do {
		tmp = rnd();
		selected = false;

		rep(r, RANKED) {
			if ( tmp <= SELECT_RATE[r] ) {
				i_dad = r; selected = true; break;
			}
		}
		if ( !selected ) {
			i_dad = rnd_size_t(ELITE, POP - DISPOSE);
		}
	} while ( i_mom == i_dad );
}

void roulette_selection_prepare() noexcept {
	size_t total = 0;
	size_t total_sum = 0;

	rep(p, POP) {
		total_sum += scores[p];
	}

	rep(p, POP) {
		total += scores[p];
		select_rate[p] = (float)total / total_sum;
	}
}

inline void roulette_selection() noexcept {
	float tmp = rnd();
	rep(p, POP) {
		if ( tmp <= select_rate[p] ) {
			i_mom = p; break;
		}
	}

	do {
		tmp = rnd();
		rep(p, POP) {
			if ( tmp <= select_rate[p] ) {
				i_dad = p; break;
			}
		}
	} while ( i_mom == i_dad );
}

inline void tournament_selection() noexcept {
	size_t cand1 = rnd_size_t(POP);
	size_t cand2 = rnd_size_t(POP);
	size_t cand3 = rnd_size_t(POP);
	size_t cand4 = rnd_size_t(POP);

	if ( scores[cand1] > scores[cand2] ) {
		if ( scores[cand3] > scores[cand4] ) {
			if ( scores[cand1] > scores[cand3] ) i_mom = cand1;
			else i_mom = cand3;
		} else {
			if ( scores[cand1] > scores[cand4] ) i_mom = cand1;
			else i_mom = cand4;
		}
	} else {
		if ( scores[cand3] > scores[cand4] ) {
			if ( scores[cand2] > scores[cand3] ) i_mom = cand2;
			else i_mom = cand3;
		} else {
			if ( scores[cand2] > scores[cand4] ) i_mom = cand2;
			else i_mom = cand4;
		}
	}

	do {
		cand1 = rnd_size_t(POP);
		cand2 = rnd_size_t(POP);
		cand3 = rnd_size_t(POP);
		cand4 = rnd_size_t(POP);

		if ( scores[cand1] > scores[cand2] ) {
			if ( scores[cand3] > scores[cand4] ) {
				if ( scores[cand1] > scores[cand3] ) i_mom = cand1;
				else i_mom = cand3;
			} else {
				if ( scores[cand1] > scores[cand4] ) i_mom = cand1;
				else i_mom = cand4;
			}
		} else {
			if ( scores[cand3] > scores[cand4] ) {
				if ( scores[cand2] > scores[cand3] ) i_mom = cand2;
				else i_mom = cand3;
			} else {
				if ( scores[cand2] > scores[cand4] ) i_mom = cand2;
				else i_mom = cand4;
			}
		}
	} while ( i_mom == i_dad );
}
