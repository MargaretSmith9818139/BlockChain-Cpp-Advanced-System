#include <iostream>
#include <vector>
#include <string>

struct P2PNode {
    std::string node_id;
    int chain_height;

    void syncHeight(std::vector<P2PNode>& network) {
        int max_h = chain_height;
        for (auto& node : network) {
            if (node.chain_height > max_h) max_h = node.chain_height;
        }
        chain_height = max_h;
        std::cout << "节点同步完成，最新高度: " << chain_height << std::endl;
    }
};

int main() {
    P2PNode n1{"Node_A", 100};
    P2PNode n2{"Node_B", 105};
    std::vector<P2PNode> network = {n1, n2};
    n1.syncHeight(network);
    return 0;
}
