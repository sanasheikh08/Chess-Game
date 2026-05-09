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
//CBoard Print Function
void CBoard::Print()
{
    // Top border
    cout << "   ===========================================\n";
    for (int iSquareRow = 7; iSquareRow >= 0; --iSquareRow) {
        // Middle row: rank label + pieces/shading
        cout << " " << (iSquareRow + 1) << " |";
        for (int iSquareCol = 0; iSquareCol < 8; ++iSquareCol) {
            GamePiece* piece = MainGameBoard[iSquareRow][iSquareCol];
            bool isDark = (iSquareRow + iSquareCol) % 2 == 0;
            if (piece != nullptr) {
                // e.g. " WP " or " BP "
                cout << " " << piece->GetColor() << piece->GetPiece() << " |";
            }
            else {
                // dark square = shaded with ::::, light = blank
                cout << (isDark ? "::::" : "    ") << "|";
            }
        }
        cout << "\n";
        // Row separator
        cout << "   ===========================================\n";
    }
    // Column labels
    cout << "      1    2    3    4    5    6    7    8\n";
}
// IsInCheck function definition
bool CBoard::IsInCheck(char PieceColor)
{
    int iKingRow = -1, iKingCol = -1;
    for (int iRow = 0; iRow < 8; ++iRow)
        for (int iCol = 0; iCol < 8; ++iCol)
            if (MainGameBoard[iRow][iCol] != nullptr &&
                MainGameBoard[iRow][iCol]->GetColor() == PieceColor &&
                MainGameBoard[iRow][iCol]->GetPiece() == 'K')
            {
                iKingRow = iRow; iKingCol = iCol;
            }
    // King not found 
    if (iKingRow == -1) return false;
    for (int iRow = 0; iRow < 8; ++iRow)
        for (int iCol = 0; iCol < 8; ++iCol)
            if (MainGameBoard[iRow][iCol] != nullptr &&
                MainGameBoard[iRow][iCol]->GetColor() != PieceColor &&
                MainGameBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iKingRow, iKingCol, MainGameBoard))
                return true;
    return false;
}
//CanMove function definition
bool CBoard::CanMove(char PieceColor)
{
    for (int iRow = 0; iRow < 8; ++iRow)
        for (int iCol = 0; iCol < 8; ++iCol)
            if (MainGameBoard[iRow][iCol] != 0 && MainGameBoard[iRow][iCol]->GetColor() == PieceColor)
                for (int iMoveRow = 0; iMoveRow < 8; ++iMoveRow)
                    for (int iMoveCol = 0; iMoveCol < 8; ++iMoveCol)
                        if (MainGameBoard[iRow][iCol]->IsLegalMove(iRow, iCol, iMoveRow, iMoveCol, MainGameBoard)) {
                            GamePiece* qpTemp = MainGameBoard[iMoveRow][iMoveCol];
                            MainGameBoard[iMoveRow][iMoveCol] = MainGameBoard[iRow][iCol];
                            MainGameBoard[iRow][iCol] = 0;
                            bool bCanMove = !IsInCheck(PieceColor);
                            MainGameBoard[iRow][iCol] = MainGameBoard[iMoveRow][iMoveCol];
                            MainGameBoard[iMoveRow][iMoveCol] = qpTemp;
                            if (bCanMove) return true;
                        }
    return false;
}



