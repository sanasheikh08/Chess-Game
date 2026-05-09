//Member 2 code Part 
//CBoard class constructor definition
CBoard::CBoard()
{
    for (int iRow = 0; iRow < 8; ++iRow)
        for (int iCol = 0; iCol < 8; ++iCol)
            MainGameBoard[iRow][iCol] = 0;

    // Black pieces
    for (int iCol = 0; iCol < 8; ++iCol)
        MainGameBoard[6][iCol] = new PawnPiece('B');
    MainGameBoard[7][0] = new RookPiece('B');
    MainGameBoard[7][1] = new KnightPiece('B');
    MainGameBoard[7][2] = new BishopPiece('B');
    MainGameBoard[7][3] = new KingPiece('B');
    MainGameBoard[7][4] = new QueenPiece('B');
    MainGameBoard[7][5] = new BishopPiece('B');
    MainGameBoard[7][6] = new KnightPiece('B');
    MainGameBoard[7][7] = new RookPiece('B');

    // White pieces
    for (int iCol = 0; iCol < 8; ++iCol)
        MainGameBoard[1][iCol] = new PawnPiece('W');
    MainGameBoard[0][0] = new RookPiece('W');
    MainGameBoard[0][1] = new KnightPiece('W');
    MainGameBoard[0][2] = new BishopPiece('W');
    MainGameBoard[0][3] = new KingPiece('W');
    MainGameBoard[0][4] = new QueenPiece('W');
    MainGameBoard[0][5] = new BishopPiece('W');
    MainGameBoard[0][6] = new KnightPiece('W');
    MainGameBoard[0][7] = new RookPiece('W');
}
//CBoard Destructor
CBoard::~CBoard()
{
    for (int iRow = 0; iRow < 8; ++iRow)
        for (int iCol = 0; iCol < 8; ++iCol) {
            delete MainGameBoard[iRow][iCol];
            MainGameBoard[iRow][iCol] = 0;
        }
}

