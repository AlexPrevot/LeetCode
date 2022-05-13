class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        queue<Node*> mem;
        mem.push(root);

        while (mem.size()) {
            int n = mem.size();

            for (int i = 0; i < n; i++) {
                Node* curr = mem.front();
                mem.pop();
                Node* next = i < n - 1 ? mem.front() : nullptr;
                curr->next = next;

                if (curr->left) mem.push(curr->left);
                if (curr->right) mem.push(curr->right);
            }
        }

        return root;
    }
};