void calc_nsga_rank() {
	rep(self, POP) {
		nsga2_rank[self] = 0;
		rep(other, POP) {
			if ( scores[self] < scores[other] && sparses[self] < sparses[other] ) nsga2_rank[self] += 1;
		}
	}
}

void nsga2() {
	calc_nsga_rank();

	// ランク毎にparentsに格納

	// 子個体を生成
}
