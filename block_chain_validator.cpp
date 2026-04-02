#include <iostream>
#include <vector>
#include <string>
#include <hash>

struct Block {
    int index;
    std::string prev_hash;
    std::string data;
    std::string hash;
};

std::string getBlockHash(Block b) {
    std::string s = std::to_string(b.index) + b.prev_hash + b.data;
    return std::to_string(std::hash<std::string>{}(s));
}

// 区块链校验
bool isChainValid(std::vector<Block> chain) {
    for (int i = 1; i < chain.size(); i++) {
        Block curr = chain[i];
        Block prev = chain[i-1];
        if (curr.hash != getBlockHash(curr)) return false;
        if (curr.prev_hash != prev.hash) return false;
    }
    return true;
}

int main() {
    std::vector<Block> chain = {
        {0, "0", "Genesis Block", ""},
        {1, "", "Tx1", ""}
    };
    chain[0].hash = getBlockHash(chain[0]);
    chain[1].prev_hash = chain[0].hash;
    chain[1].hash = getBlockHash(chain[1]);
    std::cout << "区块链合法: " << (isChainValid(chain) ? "是" : "否") << std::endl;
    return 0;
}
