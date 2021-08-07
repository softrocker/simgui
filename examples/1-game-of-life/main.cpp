// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include "GameOfLife.h"
#include "simgui.h"
#include "imgui.h"

static auto time_start = std::chrono::high_resolution_clock::now();
static auto time_period_msec = 200;
static auto rows = 40;
static auto cols = 40;

static game_of_life game(rows, cols);
static board b = game.get_board();

void draw_ui()
{
    /* static auto rows = 40;
            static auto cols = 40;*/
    static auto size_square = 20;
    static auto colorBack = ImGui::GetColorU32(IM_COL32(0, 0, 255, 255));
    static auto colorCell = ImGui::GetColorU32(IM_COL32(0, 255, 0, 255));

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    ImGui::Begin("Game of Life");
    // Рисуем доску из 50x50 квадратов (пока пустых):
    const ImVec2 p_base = ImGui::GetCursorScreenPos();
    const auto spacing = 2;
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    auto time_now = std::chrono::high_resolution_clock::now();
    auto d_time = std::chrono::duration_cast<std::chrono::milliseconds>(time_now - time_start).count();
    if (time_period_msec < d_time)
    {
        b = game.next_iteration();
        time_start = time_now;
    }

    for (auto row = 0; row < rows; row++)
    {
        for (auto col = 0; col < cols; col++)
        {
            auto x = p_base.x + col * size_square;
            auto y = p_base.y + row * size_square;
            if (!b.get(row, col))
            {
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + size_square,
                    y + size_square), colorBack);
            }
            else
            {
                draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + size_square,
                    y + size_square), colorCell);
            }

        }
    }

    ImGui::PopStyleVar(3);
    ImGui::End();
};

int main()
{
    game.set(0, 3, true);
    
    game.set(1, 4, true);
    game.set(2, 2, true);
    game.set(2, 3, true);
    game.set(2, 4, true);

    game.set(0, 14, true);
    game.set(1, 13, true);
    game.set(2, 13, true);
    game.set(2, 14, true);
    game.set(2, 15, true);

    simgui(draw_ui);
    std::cout << "Press any key to finish the program." << std::endl;
    char a;
    std::cin >> a;
    simgui(nullptr);



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
