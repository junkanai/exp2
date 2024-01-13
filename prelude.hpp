#pragma once

#include <cstddef>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ios>
#include <iomanip>
#include <cmath>

#define rep(i, n)     for ( size_t i = 0;   i < (size_t)(n); ++i )
#define reps(i, s, n) for ( size_t i = (s); i < (size_t)(n); ++i )


/* 固定値 */
static constexpr size_t DATA    = 10000;
static constexpr size_t IN      = 49;
static constexpr size_t MID     = 25;
static constexpr size_t MID2    = 25;
static constexpr size_t OUT     = 10;
static constexpr size_t BIAS    = MID + MID2 + OUT;  /* 60 */
static constexpr size_t DNA     = IN * MID + MID * MID2 + MID2 * OUT + BIAS; /* 2060 */

static constexpr size_t LOG     = 2;
static constexpr std::string_view LOGINFO[LOG] = {"best", "ave"};

static constexpr size_t RANKED  = 20;
static constexpr float SELECT_RATE[RANKED] = {0.1,
											  0.175, 0.25,
											  0.3, 0.35, 0.4,
											  0.425, 0.45, 0.475, 0.5,
											  0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.6};

/* ハイパパラメータ */
static constexpr size_t POP     = 400;
static constexpr size_t GEN     = 4000;
static constexpr size_t MUT     = DNA * 1 / 100; /* 1.0 % */
static constexpr size_t ELITE   = 20;
static constexpr size_t DISPOSE = 40;

/* グローバル変数 */
#ifdef FLOAT
float  images[DATA][IN];
float  models[POP][DNA];
float  parents[POP][DNA];
#endif
#ifdef BINARY
int    images[DATA][IN];
int    models[POP][DNA];
int    parents[POP][DNA];
#endif
#ifdef TERNARY
int    images[DATA][IN];
int    models[POP][DNA];
int    parents[POP][DNA];
int    sparses[POP];
float  total_scores[POP];
#endif

int    labels[DATA];
int    scores[POP];
size_t rank[POP];
float  select_rate[POP];
size_t i_mut[MUT];
size_t i_mom, i_dad;

std::string codename;
float  logs[GEN][LOG];


#include "parts/rnd.hpp"
#include "parts/mnist.hpp"
#include "parts/log.hpp"
#include "parts/selection.hpp"
#include "parts/crossover.hpp"
#include "parts/model.hpp"
#include "parts/mutation.hpp"
