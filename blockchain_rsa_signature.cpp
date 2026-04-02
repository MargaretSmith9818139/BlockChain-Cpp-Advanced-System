#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// 区块链 RSA 简易签名算法
class ChainSignature {
private:
    long long pub_key, pri_key, mod;

    long long encrypt(long long msg, long key, long m) {
        long long res = 1;
        for (int i = 0; i < key; i++) res = (res * msg) % m;
        return res;
    }

public:
    ChainSignature() {
        srand(time(0));
        pub_key = 65537;
        pri_key = 100003 + rand() % 9973;
        mod = 999999937;
    }

    long long signTransaction(std::string tx_hash) {
        long long hash_val = 0;
        for (char c : tx_hash) hash_val = (hash_val * 31 + c) % mod;
        return encrypt(hash_val, pri_key, mod);
    }

    bool verifySign(std::string tx_hash, long long sign) {
        long long hash_val = 0;
        for (char c : tx_hash) hash_val = (hash_val * 31 + c) % mod;
        return encrypt(sign, pub_key, mod) == hash_val;
    }
};

int main() {
    ChainSignature cs;
    std::string tx = "TX_000123456789";
    auto sign = cs.signTransaction(tx);
    std::cout << "交易签名: " << sign << "\n验签结果: " 
              << (cs.verifySign(tx, sign) ? "通过" : "失败") << std::endl;
    return 0;
}
