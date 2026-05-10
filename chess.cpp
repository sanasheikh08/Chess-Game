//Member 1 code Part
#include "chess.h"
using namespace std;

// =============================================
//  GamePiece
// =============================================

bool GamePiece::IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8])
{
    GamePiece* qpDest = GameBoard[iDestRow][iDestCol];
    if ((qpDest == 0) || (mPieceColor != qpDest->GetColor())) {
        return AreSquaresLegal(iSrcRow, iSrcCol, iDestRow, iDestCol, GameBoard);
    }
    return false;
}
// =============================================
//  PawnPiece
// =============================================

bool PawnPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8])
{
    GamePiece* qpDest = GameBoard[iDestRow][iDestCol];
    if (qpDest == 0) {
        if (iSrcCol == iDestCol) {
            if (GetColor() == 'W') {
                if (iDestRow == iSrcRow + 1) return true;
                if (!mHasMoved && iDestRow == iSrcRow + 2 && GameBoard[iSrcRow + 1][iSrcCol] == 0) return true;
            }
            else {
                if (iDestRow == iSrcRow - 1) return true;
                if (!mHasMoved && iDestRow == iSrcRow - 2 && GameBoard[iSrcRow - 1][iSrcCol] == 0) return true;
            }
        }
    }
    else {
        if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
            if (GetColor() == 'W') {
                if (iDestRow == iSrcRow + 1) return true;
            }
            else {
                if (iDestRow == iSrcRow - 1) return true;
            }
        }
    }
    return false;
}
// =============================================
//  KnightPiece
// =============================================

bool KnightPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* /*GameBoard*/[8][8])
{
    if ((iSrcCol == iDestCol + 1) || (iSrcCol == iDestCol - 1)) {
        if ((iSrcRow == iDestRow + 2) || (iSrcRow == iDestRow - 2)) return true;
    }
    if ((iSrcCol == iDestCol + 2) || (iSrcCol == iDestCol - 2)) {
        if ((iSrcRow == iDestRow + 1) || (iSrcRow == iDestRow - 1)) return true;
    }
    return false;
}

// =============================================
//  BishopPiece
// =============================================

bool BishopPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8])
{
    if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) {
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
            iCheckRow != iDestRow;
            iCheckRow += iRowOffset, iCheckCol += iColOffset)
        {
            if (GameBoard[iCheckRow][iCheckCol] != 0) return false;
        }
        return true;
    }
    return false;
}
// =============================================
//  RookPiece
// =============================================

bool RookPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8])
{
    if (iSrcRow == iDestRow) {
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol != iDestCol; iCheckCol += iColOffset) {
            if (GameBoard[iSrcRow][iCheckCol] != 0) return false;
        }
        return true;
    }
    else if (iDestCol == iSrcCol) {
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset; iCheckRow != iDestRow; iCheckRow += iRowOffset) {
            if (GameBoard[iCheckRow][iSrcCol] != 0) return false;
        }
        return true;
    }
    return false;
}
// =============================================
//  QueenPiece
// =============================================

bool QueenPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8])
{
    if (iSrcRow == iDestRow) {
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckCol = iSrcCol + iColOffset; iCheckCol != iDestCol; iCheckCol += iColOffset) {
            if (GameBoard[iSrcRow][iCheckCol] != 0) return false;
        }
        return true;
    }
    else if (iDestCol == iSrcCol) {
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset; iCheckRow != iDestRow; iCheckRow += iRowOffset) {
            if (GameBoard[iCheckRow][iSrcCol] != 0) return false;
        }
        return true;
    }
    else if ((iDestCol - iSrcCol == iDestRow - iSrcRow) || (iDestCol - iSrcCol == iSrcRow - iDestRow)) {
        int iRowOffset = (iDestRow - iSrcRow > 0) ? 1 : -1;
        int iColOffset = (iDestCol - iSrcCol > 0) ? 1 : -1;
        for (int iCheckRow = iSrcRow + iRowOffset, iCheckCol = iSrcCol + iColOffset;
            iCheckRow != iDestRow;
            iCheckRow += iRowOffset, iCheckCol += iColOffset)
        {
            if (GameBoard[iCheckRow][iCheckCol] != 0) return false;
        }
        return true;
    }
    return false;
}

// =============================================
//  KingPiece
// =============================================

bool KingPiece::AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* /*GameBoard*/[8][8])
{
    int iRowDelta = iDestRow - iSrcRow;
    int iColDelta = iDestCol - iSrcCol;
    return ((iRowDelta >= -1) && (iRowDelta <= 1) && (iColDelta >= -1) && (iColDelta <= 1));
}

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
//Member 3 code part 
// =============================================
//  ChessBoard
// =============================================

void ChessBoard::ShowWelcomeScreen()
{
    system("cls");

    cout << "\n";
    cout << "   ===========================================\n";
    cout << "            C++ CONSOLE CHESS GAME                    \n";
    cout << "   ===========================================\n";

    cout << "\n  ==== PIECES ===========================================\n\n";
    cout << "   WP / BP  =  Pawn       WN / BN  =  Knight\n";
    cout << "   WB / BB  =  Bishop     WR / BR  =  Rook\n";
    cout << "   WQ / BQ  =  Queen      WK / BK  =  King\n";
    cout << "   (W = White, B = Black)\n";

    cout << "\n  ==== HOW TO ENTER A MOVE ===========================================\n\n";
    cout << "   The board uses rows 1-8 (bottom to top) and\n";
    cout << "   columns 1-8 (left to right).\n\n";
    cout << "   You will be asked for two numbers:\n";
    cout << "     From (RC) : the square your piece is ON\n";
    cout << "     To   (RC) : the square you want to MOVE TO\n\n";
    cout << "   Type the ROW digit followed by the COLUMN digit as one\n";
    cout << "   two-digit number.  Examples:\n\n";
    cout << "     Row 1, Col 3  ->  type  13\n";
    cout << "     Row 2, Col 5  ->  type  25\n";
    cout << "     Row 7, Col 7  ->  type  77\n\n";
    cout << "   White always starts at rows 1-2.  Black starts at rows 7-8.\n";

    cout << "\n ==== PIECE MOVEMENT RULES ===========================================\n\n";
    cout << "   Pawn   : moves 1 square forward; captures 1 square diagonally\n";
    cout << "   Knight : moves in an L-shape (2 squares + 1 square, any dir)\n";
    cout << "            the ONLY piece that can jump over other pieces\n";
    cout << "   Bishop : moves any number of squares diagonally\n";
    cout << "   Rook   : moves any number of squares horizontally or vertically\n";
    cout << "   Queen  : moves like a Bishop AND a Rook combined\n";
    cout << "   King   : moves exactly 1 square in any direction\n";

    cout << "\n ==== GAME RULES ===========================================\n\n";
    cout << "   * You CANNOT move into check (leaving your own King threatened).\n";
    cout << "   * If your King is in CHECK you must escape it on your next move.\n";
    cout << "   * CHECKMATE : King is in check and has no legal escape -> you lose.\n";
    cout << "   * STALEMATE : No legal moves but King is NOT in check -> draw.\n";
    cout << "   * Capture an opponent piece by moving onto its square.\n";
    cout << "   * White moves first.\n";
    cout << "   * To RESIGN type 0 at the From prompt.\n";

    cout << "\n   ==== BOARD LEGEND ===========================================\n\n";
    cout << "   :::: = dark square (empty)    (blank) = light square (empty)\n";

    cout << "\n ===============================================\n";
    cout << "  Press ENTER to start the game...";
    cin.ignore(10000, '\n');
    cin.get();
}

void ChessBoard::Start()
{
    ShowWelcomeScreen();
    do {
        if (!GetNextMove(mqGameBoard.MainGameBoard)) break;
        AlternateTurn();
    } while (!IsGameOver());
}
// Helper: read a valid integer from cin; returns false on stream failure
static bool readInt(int& out) {
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(10000, '\n');
        return false;
    }
    return true;
}

// =============================================
//  Pawn Promotion 
// =============================================

static GamePiece* PromotePawn(char color)
{
    cout << "\n  ** PAWN PROMOTION! **\n";
    cout << "  Choose a piece to promote to:\n";
    cout << "    Q = Queen\n";
    cout << "    R = Rook\n";
    cout << "    B = Bishop\n";
    cout << "    N = Knight\n";
    cout << "  Your choice: ";

    char choice = ' ';
    while (true) {
        cin >> choice;
        cin.ignore(10000, '\n');
        choice = toupper(choice);
        if (choice == 'Q') return new QueenPiece(color);
        if (choice == 'R') return new RookPiece(color);
        if (choice == 'B') return new BishopPiece(color);
        if (choice == 'N') return new KnightPiece(color);
        cout << "  [!] Invalid choice. Enter Q, R, B, or N: ";
    }
}
bool ChessBoard::GetNextMove(GamePiece* GameBoard[8][8])
{
    bool bValidMove = false;

    do {
        system("cls");

        // ?? Header =============================================?
        cout << "\n";
        cout << "  ===============================================\n";
        cout << "             C++ CONSOLE CHESS GAME             \n";
        cout << "   ===============================================\n\n";

        // Move number & current player
        const char* playerName = (mcPlayerTurn == 'W') ? "WHITE" : "BLACK";
        cout << "  Move #" << mMoveNumber
            << "      " << playerName << " to play";

        // Warn if in check
        if (mqGameBoard.IsInCheck(mcPlayerTurn))
            cout << "   <<  CHECK! >>";
        cout << "\n\n";

        // Show last move if any
        if (mLastMoveMsg[0] != '\0')
            cout << "  Last move: " << mLastMoveMsg << "\n\n";

        // == Legend (compact reminder) ==========================
        cout << "  Pieces: WP/BP=Pawn  WN/BN=Knight  WB/BB=Bishop\n";
        cout << "          WR/BR=Rook  WQ/BQ=Queen   WK/BK=King\n";
        cout << "  Input:  type ROW then COL as one number  (e.g. row 2 col 5 = 25)\n";
        cout << "  Resign: type 0 at the From prompt\n\n";

        // ?? Board =============================================???
        mqGameBoard.Print();
        cout << "\n";

        // ?? Input =============================================???
        cout << "  From (RC): ";
        int iStartMove = 0;
        if (!readInt(iStartMove)) { cout << "  [!] Invalid input.\n"; continue; }

        // Resign
        if (iStartMove == 0) {
            system("cls");
            mqGameBoard.Print();
            cout << "\n   ===============================================\n";
            const char* opponent = (mcPlayerTurn == 'W') ? "BLACK" : "WHITE";
            cout << "   " << playerName << " resigns.  " << opponent << " WINS!\n";
            cout << "   ===============================================\n\n";
            return false;
        }

        int iStartRow = (iStartMove / 10) - 1;
        int iStartCol = (iStartMove % 10) - 1;

        cout << "  To   (RC): ";
        int iEndMove = 0;
        if (!readInt(iEndMove)) { cout << "  [!] Invalid input.\n"; continue; }
        int iEndRow = (iEndMove / 10) - 1;
        int iEndCol = (iEndMove % 10) - 1;

        // == Validate ?? Validate & execute ??????????????????????????????????? execute ===================================
        if ((iStartRow >= 0 && iStartRow <= 7) && (iStartCol >= 0 && iStartCol <= 7) &&
            (iEndRow >= 0 && iEndRow <= 7) && (iEndCol >= 0 && iEndCol <= 7))
        {
            GamePiece* qpCurrPiece = GameBoard[iStartRow][iStartCol];
            if ((qpCurrPiece != nullptr) && (qpCurrPiece->GetColor() == mcPlayerTurn)) {
                if (qpCurrPiece->IsLegalMove(iStartRow, iStartCol, iEndRow, iEndCol, GameBoard)) {
                    GamePiece* qpTemp = GameBoard[iEndRow][iEndCol];
                    GameBoard[iEndRow][iEndCol] = GameBoard[iStartRow][iStartCol];
                    GameBoard[iStartRow][iStartCol] = nullptr;
                    if (!mqGameBoard.IsInCheck(mcPlayerTurn)) {
                        // Mark pawn as moved so it can no longer double-step
                        if (qpCurrPiece->GetPiece() == 'P') {
                            static_cast<PawnPiece*>(qpCurrPiece)->SetMoved();

                            // =============================================
                            //  PAWN PROMOTION 
                            // =============================================
                            bool isPromotion = (mcPlayerTurn == 'W' && iEndRow == 7) ||
                                (mcPlayerTurn == 'B' && iEndRow == 0);
                            if (isPromotion) {
                                GamePiece* promoted = PromotePawn(mcPlayerTurn);
                                delete GameBoard[iEndRow][iEndCol];
                                GameBoard[iEndRow][iEndCol] = promoted;
                                qpCurrPiece = promoted;
                            }
                        }
                        // Build move description (e.g. "WP: 12 -> 13  (captured BP)")
                        int idx = 0;
                        mLastMoveMsg[idx++] = mcPlayerTurn;
                        mLastMoveMsg[idx++] = 'P';
                        mLastMoveMsg[idx++] = ':'; mLastMoveMsg[idx++] = ' ';
                        mLastMoveMsg[idx++] = (char)('0' + iStartRow + 1);
                        mLastMoveMsg[idx++] = (char)('0' + iStartCol + 1);
                        mLastMoveMsg[idx++] = ' '; mLastMoveMsg[idx++] = '-';
                        mLastMoveMsg[idx++] = '>'; mLastMoveMsg[idx++] = ' ';
                        mLastMoveMsg[idx++] = (char)('0' + iEndRow + 1);
                        mLastMoveMsg[idx++] = (char)('0' + iEndCol + 1);
                        if (qpTemp != nullptr) {
                            const char* cap = "  (captured ";
                            for (int i = 0; cap[i]; ++i) mLastMoveMsg[idx++] = cap[i];
                            mLastMoveMsg[idx++] = qpTemp->GetColor();
                            mLastMoveMsg[idx++] = qpTemp->GetPiece();
                            mLastMoveMsg[idx++] = ')';
                        }
                        mLastMoveMsg[idx] = '\0';
                        delete qpTemp;
                        bValidMove = true;
                        ++mMoveNumber;
                    }
                    else {
                        // Undo   move leaves king in check
                        GameBoard[iStartRow][iStartCol] = GameBoard[iEndRow][iEndCol];
                        GameBoard[iEndRow][iEndCol] = qpTemp;
                        cout << "\n  [!] That move leaves your King in check!\n";
                        cout << "      Press ENTER to try again...";
                        cin.ignore(10000, '\n'); cin.get();
                    }
                }
                else {
                    cout << "\n  [!] Illegal move for that piece.\n";
                    cout << "      Press ENTER to try again...";
                    cin.ignore(10000, '\n'); cin.get();
                }
            }
            else {
                cout << "\n  [!] No " << playerName << " piece at that square.\n";
                cout << "      Press ENTER to try again...";
                cin.ignore(10000, '\n'); cin.get();
            }
        }
        else {
            cout << "\n  [!] Coordinates out of range (use rows/cols 1-8).\n";
            cout << "      Press ENTER to try again...";
            cin.ignore(10000, '\n'); cin.get();
        }

    } while (!bValidMove);

    return true;
}

void ChessBoard::AlternateTurn()
{
    mcPlayerTurn = (mcPlayerTurn == 'W') ? 'B' : 'W';
}

bool ChessBoard::IsGameOver()
{
    if (!mqGameBoard.CanMove(mcPlayerTurn)) {
        system("cls");
        mqGameBoard.Print();
        cout << "\n   ===============================================\n";
        if (mqGameBoard.IsInCheck(mcPlayerTurn)) {
            AlternateTurn();
            const char* winner = (mcPlayerTurn == 'W') ? "WHITE" : "BLACK";
            cout << "           CHECKMATE! " << winner << " WINS!          \n";
        }
        else {
            cout << "                STALEMATE! DRAW!             \n";
        }
        cout << "   ===============================================\n\n";
        return true;
    }
    return false;
}




