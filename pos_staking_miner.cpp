#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class PoSStaker {
public:
    PoSStaker(std::string addr, double balance) : addr(addr), balance(balance) {}

    bool tryMintBlock() {
        // 质押越多，概率越高
        double chance = balance / 10000.0;
        double rand_val = (double)rand() / RAND_MAX;
        return rand_val <= chance;
    }

private:
    std::string addr;
    double balance;
};

int main() {
    srand(time(0));
    PoSStaker staker("Wallet_0x123", 5000);
    std::cout << "出块成功: " << (staker.tryMintBlock() ? "是" : "否") << std::endl;
    return 0;
}
