#include "../position.h"
#include <iostream>


int main() {
    Stockfish::Bitboards::init();
    Stockfish::Position::init();
    Stockfish::StateInfo stateInfo;
    Stockfish::Position position;
    position.set("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", false, &stateInfo);
    std::cout << position << std::endl;
}