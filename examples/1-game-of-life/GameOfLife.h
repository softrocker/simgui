#pragma once

#include <vector>

using board_impl = std::vector<bool>;

class board
{
public:
    void resize(size_t rows, size_t cols) 
    {
        _rows = rows;
        _cols = cols;
        _board_impl.resize(rows * cols, false);
    };
    bool get(size_t row, size_t col) const
    {
        return _board_impl[ _cols * row + col];
    };
    void set(size_t row, size_t col, bool value)
    {
        _board_impl[_cols * row + col] = value;
    };
    size_t rows() const
    {
        return _rows;
    };
    size_t cols() const
    {
        return _cols;
    };
private:

private:
    board_impl _board_impl;
    size_t _rows = 0;
    size_t _cols = 0;
};

class game_of_life
{
public:
    game_of_life(int rows, int cols);
    void set(int row, int col, bool on);
    board next_iteration();
    board get_board();
private:
    int count_neighbors(int row, int col);
    board _board;
};
