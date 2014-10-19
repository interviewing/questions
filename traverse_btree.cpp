#include <cstdio>
#include <ctime>
#include <limits>
#include <iostream>
#include <string>
#include <queue>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

class Node
{
public:
    Node(int value) :
        m_value(value),
        m_left(NULL),
        m_right(NULL)
    {
        // NOP
    }

    ~Node()
    {
        if (m_left) {
            delete m_left;
        }
        if (m_right) {
            delete m_right;
        }
    }

    void insert(Node* node)
    {
        if (node) {
            if (node->value() < value()) {
                if (m_left) {
                    m_left->insert(node);
                } else {
                    m_left = node;
                }
            } else {
                if (m_right) {
                    m_right->insert(node);
                } else {
                    m_right = node;
                }
            }
        }
    }

    int value() const
    {
        return m_value;
    }

    Node* left() const
    {
        return m_left;
    }

    Node* right() const
    {
        return m_right;
    }

protected:


private:
    int m_value;

    Node* m_left;

    Node* m_right;
};

int get_seed()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return static_cast<int>(ts.tv_sec + ts.tv_nsec);
}

void print_dfs(const Node* node, int level)
{
    if (node) {
        if (node->left()) {
            print_dfs(node->left(), level + 1);
        }
        for (int i = 0; i < level; ++i) {
            std::cout << "\t";
        }
        std::cout << node->value() << "\n";
        if (node->right()) {
            print_dfs(node->right(), level + 1);
        }
    }
}

void print_bfs(const Node* root)
{
    if (root) {
        std::queue<const Node*> q;
        q.push(root);
        while (!q.empty()) {
            const Node* node = q.front();
            q.pop();
            if (node) {
                std::cout << node->value() << "\n";
                if (node->left()) {
                    q.push(node->left());
                }
                if (node->right()) {
                    q.push(node->right());
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    int n = 0;
    int seed = get_seed();
    if (argc > 1) {
        sscanf(argv[1], "%d", &n);
    }
    if (argc > 2) {
        sscanf(argv[2], "%d", &seed);
    }

    //boost::random::uniform_int_distribution<> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    boost::random::uniform_int_distribution<> dist(0, std::numeric_limits<int>::max());
    boost::random::mt19937 gen(get_seed());

    Node* root = 0;
    for (int i = 0; i < n; ++i) {
        const int value = dist(gen);
        Node* node = new Node(value);
        if (root) {
            root->insert(node);
        } else {
            root = node;
        }
    }
    print_dfs(root, 0);
    print_bfs(root);

    delete root;

    return 0;
}
