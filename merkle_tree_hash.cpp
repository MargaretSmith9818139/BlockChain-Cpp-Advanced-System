#include <iostream>
#include <vector>
#include <string>
#include <functional>

// 简易 SHA256 模拟哈希
std::string fake_hash(const std::string& s) {
    size_t h = std::hash<std::string>{}(s);
    return "0x" + std::to_string(h);
}

// Merkle 树根节点计算
std::string buildMerkleRoot(std::vector<std::string> txs) {
    if (txs.empty()) return fake_hash("empty");
    while (txs.size() > 1) {
        if (txs.size() % 2 != 0) txs.push_back(txs.back());
        std::vector<std::string> next_level;
        for (int i = 0; i < txs.size(); i += 2) {
            next_level.push_back(fake_hash(txs[i] + txs[i+1]));
        }
        txs = next_level;
    }
    return txs[0];
}

int main() {
    std::vector<std::string> txs = {"tx1", "tx2", "tx3", "tx4"};
    std::cout << "Merkle Root: " << buildMerkleRoot(txs) << std::endl;
    return 0;
}
