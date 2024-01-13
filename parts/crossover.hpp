#ifndef FLOAT
inline void onepoint_crossover(const float mom[DNA], const float dad[DNA], float child[DNA])  noexcept {
	size_t point = rnd_size_t(DNA);

	rep( p, point ) child[p] = mom[p];
	reps( p, point, DNA ) child[p] = dad[p];
}

inline void twopoint_crossover(const float mom[DNA], const float dad[DNA], float child[DNA]) noexcept {
	size_t point1 = rnd_size_t(DNA);
	size_t point2 = rnd_size_t(DNA);
	while ( point1 == point2 ) point2 = rnd_size_t(DNA);
	if ( point1 > point2 ) {
		size_t tmppoint = point1; point1 = point2; point2 = tmppoint;
	}

	rep( p, point1 ) child[p] = mom[p];
	reps( p, point1, point2 ) child[p] = dad[p];
	reps( p, point2, DNA ) child[p] = mom[p];
}

void uniform_crossover(const float mom[DNA], const float dad[DNA], float child[DNA]) noexcept {
	rep(d, DNA) {
		child[d] = rnd_bool() ? mom[d] : dad[d];
	}
}
#endif

#ifdef BINARY

inline void onepoint_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	size_t point = rnd_size_t(DNA);

	rep( p, point ) child[p] = mom[p];
	reps( p, point, DNA ) child[p] = dad[p];
}

inline void twopoint_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	size_t point1 = rnd_size_t(DNA);
	size_t point2 = rnd_size_t(DNA);
	while ( point1 == point2 ) point2 = rnd_size_t(DNA);
	if ( point1 > point2 ) {
		size_t tmppoint = point1; point1 = point2; point2 = tmppoint;
	}

	rep( p, point1 ) child[p] = mom[p];
	reps( p, point1, point2 ) child[p] = dad[p];
	reps( p, point2, DNA ) child[p] = mom[p];
}

void uniform_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	rep(d, DNA) {
		child[d] = rnd_bool() ? mom[d] : dad[d];
	}
}

#endif

#ifdef TERNARY

inline void onepoint_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	size_t point = rnd_size_t(DNA);

	rep( p, point ) child[p] = mom[p];
	reps( p, point, DNA ) child[p] = dad[p];
}

inline void twopoint_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	size_t point1 = rnd_size_t(DNA);
	size_t point2 = rnd_size_t(DNA);
	while ( point1 == point2 ) point2 = rnd_size_t(DNA);
	if ( point1 > point2 ) {
		size_t tmppoint = point1; point1 = point2; point2 = tmppoint;
	}

	rep( p, point1 ) child[p] = mom[p];
	reps( p, point1, point2 ) child[p] = dad[p];
	reps( p, point2, DNA ) child[p] = mom[p];
}

void uniform_crossover(const int mom[DNA], const int dad[DNA], int child[DNA]) noexcept {
	rep(d, DNA) {
		child[d] = rnd_bool() ? mom[d] : dad[d];
	}
}

#endif
