#include <iostream>
#include <vector>

// 难度调整：目标出块时间 10s
int adjustDifficulty(std::vector<int> block_times, int current_diff) {
    int avg = 0;
    for (int t : block_times) avg += t;
    avg /= block_times.size();

    if (avg < 8) return current_diff + 1;
    if (avg > 12 && current_diff > 1) return current_diff - 1;
    return current_diff;
}

int main() {
    std::vector<int> times = {9, 11, 8, 10, 12};
    std::cout << "新难度: " << adjustDifficulty(times, 5) << std::endl;
    return 0;
}
