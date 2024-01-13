#ifdef FLOAT

inline void choose_i_mut_float() noexcept {
	rep(m, MUT) {
		i_mut[m] = rnd_size_t(DNA);
	}
}

void mutation() noexcept {
	reps( p, ELITE, POP ) {
		choose_i_mut_float();
		rep(m, MUT) models[p][i_mut[m]] = rnd_dna_float();
	}
}

#endif

#ifdef BINARY

inline void choose_i_mut_int() noexcept {
	rep(m, MUT) {
		i_mut[m] = rnd_size_t(BIAS, DNA);
	}
}

void mutation() noexcept {
	reps( p, ELITE, POP ) {
		if ( rnd() < 0.75 ) models[p][rnd_size_t(MID)] = rnd_dna_mid_bias_int();
		else models[p][rnd_size_t(MID, BIAS)] = rnd_dna_out_bias_int();
		choose_i_mut_int();
		rep(m, MUT) models[p][i_mut[m]] = rnd_dna_binary();
	}
}
#endif

#ifdef TERNARY

inline void choose_i_mut_int() noexcept {
	rep(m, MUT) {
		i_mut[m] = rnd_size_t(BIAS, DNA);
	}
}

void mutation() noexcept {
	reps( p, ELITE, POP ) {
		if ( rnd() < 0.75 ) models[p][rnd_size_t(MID)] = rnd_dna_mid_bias_int();
		else models[p][rnd_size_t(MID, BIAS)] = rnd_dna_out_bias_int();
		choose_i_mut_int();
		rep(m, MUT) models[p][i_mut[m]] = rnd_dna_ternary();
	}
}

#endif
