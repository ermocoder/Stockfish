#include "negmax_search.h"
#include "static_score.h"
#include "../movegen.h"


Stockfish::ExtMove movesBuff[1000];

int calc_negmax_score(
    Stockfish::Position& position,
    int maxDepth,
    int depth,
    Stockfish::ExtMove* moves
) {
    if (position.is_draw(depth)) {
        return 0;
    }
    if (depth >= maxDepth) {
        return calc_static_score(position);
    }
    Stockfish::ExtMove* movesEnd = Stockfish::generate<Stockfish::LEGAL>(position, moves);
    if (moves == movesEnd) {
        return position.checkers() ? -INF_SCORE : 0;
    }
    int score = -INF_SCORE;
    Stockfish::StateInfo nextState;
    for (auto move = moves; move != movesEnd; move++) {
        position.do_move(*move, nextState);
        score = std::max(score, -calc_negmax_score(position, maxDepth, depth + 1, movesEnd));
        position.undo_move(*move);
    }
    return score;
}
