//Member 1
#pragma once
#include <iostream>
#include <stdlib.h>

// =============================================
//  Base class & piece declarations
// =============================================

class GamePiece
{
public:
    GamePiece(char PieceColor) : mPieceColor(PieceColor) {}
    virtual ~GamePiece() {}
    virtual char GetPiece() = 0;
    char GetColor() { return mPieceColor; }
    bool IsLegalMove(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
private:
    virtual bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]) = 0;
    char mPieceColor;
};

class PawnPiece : public GamePiece
{
public:
    PawnPiece(char PieceColor) : GamePiece(PieceColor), mHasMoved(false) {}
    ~PawnPiece() {}
    void SetMoved() { mHasMoved = true; }
    bool HasMoved() const { return mHasMoved; }
private:
    virtual char GetPiece() { return 'P'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
    bool mHasMoved;
};

class KnightPiece : public GamePiece
{
public:
    KnightPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~KnightPiece() {}
private:
    virtual char GetPiece() { return 'N'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};

class BishopPiece : public GamePiece
{
public:
    BishopPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~BishopPiece() {}
private:
    virtual char GetPiece() { return 'B'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};

class RookPiece : public GamePiece
{
public:
    RookPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~RookPiece() {}
private:
    virtual char GetPiece() { return 'R'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};

class QueenPiece : public GamePiece
{
public:
    QueenPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~QueenPiece() {}
private:
    virtual char GetPiece() { return 'Q'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};

class KingPiece : public GamePiece
{
public:
    KingPiece(char PieceColor) : GamePiece(PieceColor) {}
    ~KingPiece() {}
private:
    virtual char GetPiece() { return 'K'; }
    bool AreSquaresLegal(int iSrcRow, int iSrcCol, int iDestRow, int iDestCol, GamePiece* GameBoard[8][8]);
};

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

