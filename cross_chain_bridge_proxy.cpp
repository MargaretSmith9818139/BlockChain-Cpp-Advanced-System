#include <iostream>
#include <string>

class CrossChainBridge {
public:
    bool lockAsset(std::string user, double amount, std::string chain) {
        if (amount <= 0) return false;
        std::cout << "用户 " << user << " 在 " << chain << " 锁定 " << amount << " 资产\n";
        return true;
    }

    void mintClaim(std::string target_chain, std::string user) {
        std::cout << "跨链完成：" << target_chain << " 网络为 " << user << " 铸造映射资产\n";
    }
};

int main() {
    CrossChainBridge bridge;
    if (bridge.lockAsset("User_0x111", 500, "Ethereum")) {
        bridge.mintClaim("BSC", "User_0x111");
    }
    return 0;
}
