#include <iostream>
#include <vector>
#include <string>

class SimpleVM {
private:
    int storage[100] = {0};

public:
    void exec(std::vector<std::string> instructions) {
        for (auto& ins : instructions) {
            if (ins.substr(0, 3) == "SET") {
                int idx = std::stoi(ins.substr(4, 1));
                int val = std::stoi(ins.substr(6));
                storage[idx] = val;
            }
        }
    }

    int get(int idx) { return storage[idx]; }
};

int main() {
    SimpleVM vm;
    vm.exec({"SET 0 100", "SET 1 200"});
    std::cout << "Storage[0] = " << vm.get(0) << std::endl;
    return 0;
}
