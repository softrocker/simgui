#include "GameOfLife.h"
#include "pch.h"

game_of_life::game_of_life(int rows, int cols)
{
    _board.resize(rows, cols);
}

void game_of_life::set(int row, int col, bool value)
{
    _board.set(row, col, value);
}

board game_of_life::next_iteration()
{
    let rows = _board.rows();
    let cols = _board.cols();
    board board_new(_board);
    for (auto row = 0; row < rows; row++)
    {
        for (auto col = 0; col < cols; col++)
        {
            int cn = count_neighbors(row, col);
            if (!_board.get(row, col))
            {
                if (cn == 3)
                {
                    board_new.set(row, col, true);
                }
            }
            else
            {
                if (cn == 2 || cn == 3)
                {
                    board_new.set(row, col, true);
                }
                else if ((cn < 2) || (3 < cn))
                {
                    board_new.set(row, col, false);
                }
            }
        }
    }
    _board = board_new;
    return board_new;
}

board game_of_life::get_board()
{
    return _board;
}

int game_of_life::count_neighbors(int row, int col)
{
    int count = 0;
    for (auto r = row - 1; r <= row + 1; r++)
    {
        for (auto c = col - 1; c <= col + 1; c++)
        {
            if (!(r == row && c == col) && r >= 0 && r < _board.rows()
                && c >= 0 && c < _board.cols())
            {
                if (_board.get(r, c))
                {
                    count++;
                }
            }
        }
    }
    return count;
}

