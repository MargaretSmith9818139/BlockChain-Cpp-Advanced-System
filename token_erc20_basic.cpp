#include <iostream>
#include <unordered_map>
#include <string>

class ERC20Basic {
private:
    std::unordered_map<std::string, double> balances;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> allowed;

public:
    void transfer(std::string from, std::string to, double amount) {
        if (balances[from] >= amount) {
            balances[from] -= amount;
            balances[to] += amount;
        }
    }

    void mint(std::string addr, double amount) {
        balances[addr] += amount;
    }

    double balanceOf(std::string addr) {
        return balances[addr];
    }
};

int main() {
    ERC20Basic token;
    token.mint("Creator", 1000000);
    token.transfer("Creator", "User", 1000);
    std::cout << "User 余额: " << token.balanceOf("User") << std::endl;
    return 0;
}
