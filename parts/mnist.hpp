static constexpr size_t MNIST_IMAGE_OFFSET = 16;
static constexpr size_t MNIST_LABEL_OFFSET = 8;

#ifdef FLOAT

void read_images() {
	std::ifstream ifs("../parts/raw/train-images-idx3-ubyte",
					  std::ios::in | std::ios::binary);

	if ( !ifs ) throw std::runtime_error("Failed to open ifs");
	ifs.seekg(MNIST_IMAGE_OFFSET, std::ios_base::beg);

	rep(d, DATA) {
		rep(i, IN) images[d][i] = 0;

		rep(y, 28) rep(x, 28) {
			unsigned char tmp;
			ifs.read((char*)&tmp, sizeof(tmp));
			images[d][(y / 4)*7 + (x / 4)] += (float)tmp;
		}

		rep(i, IN) images[d][i] /= (16 * UINT8_MAX);
	}
}

void show_image(const float image[IN]) {
	rep(y, 7) {
		rep(x, 7) {
			if ( image[y*7+x] < 0.1 ) std::printf("      "); else
			std::printf(" %.3f", image[y*7+x]);
		}
		std::printf("\n");
	}
}

#else

void read_images() {
	std::ifstream ifs("../parts/raw/train-images-idx3-ubyte",
					  std::ios::in | std::ios::binary);

	if ( !ifs ) throw std::runtime_error("Failed to open ifs");
	ifs.seekg(MNIST_IMAGE_OFFSET, std::ios_base::beg);

	rep(d, DATA) {
		rep(i, IN) images[d][i] = 0;

		rep(y, 28) rep(x, 28) {
			unsigned char tmp;
			ifs.read((char*)&tmp, sizeof(tmp));
			images[d][(y / 4)*7 + (x / 4)] += (int)tmp;
		}

		rep(i, IN) images[d][i] /= 16;
	}
}

void show_image(const int image[IN]) {
	rep(y, 7) {
		rep(x, 7) {
			if ( image[y*7+x] < 0.1 ) std::printf("    "); else
			std::printf(" %3d", image[y*7+x]);
		}
		std::printf("\n");
	}
}

#endif

void read_labels() {
	std::ifstream ifs("../parts/raw/train-labels-idx1-ubyte",
					  std::ios::in | std::ios::binary);

	if ( !ifs ) throw std::runtime_error("Failed to open ifs");

	ifs.seekg(MNIST_LABEL_OFFSET, std::ios_base::beg);

	rep(d, DATA) {
		unsigned char tmp;
		ifs.read((char*)&tmp, sizeof(tmp));
		labels[d] = (int)tmp;
	}
}

void init_mnist() {
	read_images();
	read_labels();
}

void test_mnist(const size_t from = 0) {
	std::printf("***** start mnist test *****\n");
	reps(i, from, from + 10) {
		show_image(images[i]);
		std::printf("labels: %d\n", labels[i]);
	}
}

