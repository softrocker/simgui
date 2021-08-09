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

static bool active = false; 

ImVec2 operator+(const ImVec2& lhs, const ImVec2& rhs)
{
    return ImVec2(lhs.x + rhs.x, lhs.y + rhs.y);
}

void draw_ui()
{
    static auto size_of_cell = 20;
    static auto color_of_back = ImGui::GetColorU32(IM_COL32(0, 0, 255, 255));
    static auto color_of_cell = ImGui::GetColorU32(IM_COL32(0, 255, 0, 255));

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);

    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

    ImGui::Begin("Game of Life");
	
    const ImVec2 p_base = ImGui::GetCursorScreenPos() + ImVec2(0, 50);
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    auto time_now = std::chrono::high_resolution_clock::now();
    auto d_time = 
        std::chrono::duration_cast<std::chrono::milliseconds>(time_now - time_start).count();
	
	if(ImGui::Button("PAUSE/RESUME"))
	{
		active = !active;
	}

    ImGui::SameLine();

    active ? ImGui::Text("STATE: ACTIVE") : ImGui::Text("STATE: PAUSED");

    if (ImGui::Button("CLEAR"))
    {
        game.clear_board();
    }

    ImGuiIO& io = ImGui::GetIO();
	
    if ((time_period_msec < d_time))
    {
        time_start = time_now;
        b = active ? game.next_iteration() : game.get_board();
    }

    if (ImGui::IsMouseClicked(ImGuiMouseButton_Left))
    {
        auto row = static_cast<int>((io.MousePos.y - p_base.y) / size_of_cell);
        auto col = static_cast<int>((io.MousePos.x - p_base.x) / size_of_cell);
        std::cout << "Cell = " << '(' << row << ',' << col << ')' <<
            std::endl;
        if ((0 <= row) && (row < rows) && (0 <= col) && (col < cols))
        {
            auto value = game.get(row, col);
            game.set(row, col, !value);
        }
    }

    for (auto row = 0; row < rows; row++)
    {
        for (auto col = 0; col < cols; col++)
        {
            auto x = p_base.x + col * size_of_cell;
            auto y = p_base.y + row * size_of_cell;
            if (!b.get(row, col))
            {
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + size_of_cell,
                    y + size_of_cell), color_of_back);
            }
            else
            {
                draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + size_of_cell,
                    y + size_of_cell), color_of_cell);
            }
        }
    }

    ImGui::PopStyleVar(3);
    ImGui::End();
};

int main()
{
    simgui(draw_ui);
    std::cout << "Press any key to finish the program." << std::endl;
    char a;
    std::cin >> a;
    simgui(nullptr);
}