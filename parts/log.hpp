void init_log(std::string source_code_file_name) {
	codename = source_code_file_name.erase(source_code_file_name.find(".cpp"));
}

void print_log(const size_t gen) noexcept {
	std::printf(" %s | GEN%4zu |  [ best, ave ] : [ %.4f, %.4f ]\n",
			codename.c_str(), gen + 1, logs[gen][0], logs[gen][1]);
}

void set_best_to_log(const float value, float log[LOG]) {
	log[0] = value;
}

void set_ave_to_log(const float value, float log[LOG]) {
	log[1] = value;
}


void save_fitness() {
	std::ofstream ofs(codename + "_sparse.csv");

	if ( !ofs ) throw std::runtime_error("Failed to open file");

	ofs << "accuracy,sparse" << std::endl;

	rep( p, POP ) {
		ofs << std::right << std::setw(8) << ((float)scores[rank[p]] / DATA);
		ofs << ", " << std::right << std::setw(8) << ((float)sparses[rank[p]] / DNA);
		ofs << std::endl;
	}
}

void save_log() {
	std::ofstream ofs(codename + ".csv");

	if ( !ofs ) throw std::runtime_error("Failed to open file");


	ofs << "gen";
	rep(i, LOG) ofs << ", " << codename << "_" << LOGINFO[i];
	ofs << std::endl;

	rep( gen, GEN ) {
		ofs << std::right << std::setw(4) << gen + 1;
		rep(i, LOG) ofs << ", " << std::right << std::setw(8) << logs[gen][i];
		ofs << std::endl;
	}

	#ifdef TERNARY
	save_fitness();
	#endif
}
