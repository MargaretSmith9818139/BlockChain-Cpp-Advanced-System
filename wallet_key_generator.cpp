#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string randomHex(int len) {
    const char chars[] = "0123456789abcdef";
    std::string res;
    for (int i = 0; i < len; i++) {
        res += chars[rand() % 16];
    }
    return res;
}

// 生成钱包密钥对
void generateWallet() {
    std::string private_key = "0x" + randomHex(64);
    std::string public_key = "0x" + randomHex(64);
    std::string address = "0x" + randomHex(40);
    std::cout << "私钥: " << private_key << "\n公钥: " << public_key << "\n地址: " << address << std::endl;
}

int main() {
    srand(time(0));
    generateWallet();
    return 0;
}
