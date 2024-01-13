#ifndef RNDSEED
#define RNDSEED 0
#endif

uint32_t rndx = 123456789 + (RNDSEED);
uint32_t rndy = 362436069 + (RNDSEED);
uint32_t rndz = 521288629 + (RNDSEED);
uint32_t rndw = 88675123 + (RNDSEED);

inline float rnd() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return float(rndw) / UINT32_MAX;
}

inline bool rnd_bool() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return rndw % 2 == 0;
}

inline size_t rnd_size_t(size_t lower, size_t upper) noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return rndw % (upper - lower) + lower;
}

inline size_t rnd_size_t(size_t upper) noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return rndw % upper;
}

inline float rnd_dna_float() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return rndw * 2.0f / UINT32_MAX - 1.0;
}

inline int rnd_dna_binary() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return int(rndw % 2) * 2 - 1;
}

inline int rnd_dna_ternary() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return int(rndw % 3) - 1;
}

inline int rnd_dna_mid_bias_int() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return int(rndw % 5001) - 2500;
}

inline int rnd_dna_out_bias_int() noexcept {
	uint32_t t = rndx ^ (rndx << 11);
	rndx = rndy; rndy = rndz; rndz = rndw;
	rndw ^= t ^ (t >> 8) ^ (rndw >> 19);

	return int(rndw % 61) - 30;
}
