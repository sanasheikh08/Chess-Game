//Member 2
class CBoard
{
public:
    CBoard();
    ~CBoard();
    void Print();
    bool IsInCheck(char PieceColor);
    bool CanMove(char PieceColor);
    GamePiece* MainGameBoard[8][8];
};

