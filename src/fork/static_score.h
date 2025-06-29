#pragma once

#include "../position.h"


const int PAWN_COST = 100;
const int KNIGHT_COST = PAWN_COST * 3;
const int BISHOP_COST = PAWN_COST * 3;
const int ROOK_COST = PAWN_COST * 5;
const int QUEEN_COST = PAWN_COST * 9;

const int INF_SCORE = PAWN_COST * 100;

int calc_static_score(Stockfish::Position& position);
