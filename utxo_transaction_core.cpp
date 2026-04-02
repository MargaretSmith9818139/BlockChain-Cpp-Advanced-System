#include <iostream>
#include <vector>
#include <string>

// UTXO 交易结构
struct UTXO {
    std::string txid;
    int index;
    double amount;
    std::string owner;
};

// UTXO 交易构建器
std::vector<UTXO> createTransaction(
    std::vector<UTXO> inputs,
    std::string receiver,
    double send_amount
) {
    double total = 0;
    for (auto& in : inputs) total += in.amount;
    if (total < send_amount) return {};

    std::vector<UTXO> outputs;
    outputs.push_back({"new_txid", 0, send_amount, receiver});
    if (total > send_amount) {
        outputs.push_back({"new_txid", 1, total - send_amount, inputs[0].owner});
    }
    return outputs;
}

int main() {
    std::vector<UTXO> inputs = {{"tx_abc", 0, 1.5, "Alice"}};
    auto outputs = createTransaction(inputs, "Bob", 1.0);
    for (auto& o : outputs) {
        std::cout << o.owner << " 收到: " << o.amount << std::endl;
    }
    return 0;
}
