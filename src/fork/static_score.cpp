#include "static_score.h"


int calc_static_score(Stockfish::Position &position) {
    Stockfish::Color me = position.side_to_move();
    Stockfish::Color op = ~me;
    return (position.count<Stockfish::PieceType::PAWN>(me) - position.count<Stockfish::PieceType::PAWN>(op)) * PAWN_COST
        + (position.count<Stockfish::PieceType::KNIGHT>(me) - position.count<Stockfish::PieceType::KNIGHT>(op)) * KNIGHT_COST
        + (position.count<Stockfish::PieceType::BISHOP>(me) - position.count<Stockfish::PieceType::BISHOP>(op)) * BISHOP_COST
        + (position.count<Stockfish::PieceType::ROOK>(me) - position.count<Stockfish::PieceType::ROOK>(op)) * ROOK_COST
        + (position.count<Stockfish::PieceType::QUEEN>(me) - position.count<Stockfish::PieceType::QUEEN>(op)) * QUEEN_COST;
}