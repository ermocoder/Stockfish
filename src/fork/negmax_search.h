#pragma once

#include "../position.h"
#include "../movegen.h"
#include "static_score.h"


extern Stockfish::ExtMove movesBuff[];

int calc_negmax_score(
    Stockfish::Position& position,
    int maxDepth,
    int depth = 0,
    Stockfish::ExtMove* moves = movesBuff
);
