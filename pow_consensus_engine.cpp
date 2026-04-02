#include <iostream>
#include <string>
#include <sstream>
#include <hash>

std::string calcHash(const std::string& input) {
    std::hash<std::string> hasher;
    std::stringstream ss;
    ss << std::hex << hasher(input);
    return ss.str();
}

// PoW 工作量证明
void runPoW(int difficulty) {
    std::string prefix(difficulty, '0');
    int nonce = 0;
    while (true) {
        std::string input = "BLOCK_HEIGHT_10086_NONCE_" + std::to_string(nonce);
        std::string hash = calcHash(input);
        if (hash.substr(0, difficulty) == prefix) {
            std::cout << "挖矿成功！\nNonce: " << nonce << "\nHash: " << hash << std::endl;
            break;
        }
        nonce++;
    }
}

int main() {
    runPoW(4);
    return 0;
}
