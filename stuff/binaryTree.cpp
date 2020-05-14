#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
   // int depth = 0;
};

Node* head = new Node();


// Get path by Inode traverse
vector<int> getPath(Node* curr, vector<int> &path) {
    if (curr->left != nullptr) {
       lp = getPath(curr->left, path);
    }
    path.push_back(curr->data);
    if (curr->right != nullptr) {
       rp = getPath(curr->right, path);
    }
    return path;
}

vector<Node*> traverseDepth(vector<Node*> &results, Node* curr, int depth) {
    int maxNodes = pow(2, depth)/2;
    if (curr->depth == depth) {
        results.push_back(curr);
    }
    if (curr->left != nullptr) {
        traverseDepth(results, curr->left, depth);
    }
    if (curr->right != nullptr) {
        traverseDepth(results, curr->right, depth);
    }
    return results;
}

vector<vector<int>> swapChilds(Node* head, vector<int> queries) {
    vector<vector<int>> results;
    for (int i = 0; i<queries.size(); i++) {
        int multiplier = 1;
        bool traversed = true;
        while (traversed) {
            traversed = false;
            vector<Node*> results;
            int depth = queries[i] * multiplier;
            results = traverseDepth(results, head, depth);
            traversed = (results.size()>=1);
            if (traversed) {
                for (int n=0; n<results.size(); n++) {
                    Node* toSwap = results[n]->right;
                    results[n]->right = results[n]->left;
                    results[n]->left = toSwap;
                }
            }
            multiplier++;
        }
        vector<int> path;
        path = getPath(head, path);
        results.push_back(path);
    }
    return results;
}

void createTree(Node* curr, vector<vector<int>> indexes, int idx, int depth = 1) {
    curr->data = idx+1;
    curr->depth = depth;
    if (idx<indexes.size()) {
        if (indexes[idx][0] != -1) {
            curr->left = new Node();
            createTree(curr->left, indexes, indexes[idx][0]-1, curr->depth+1);
        }
        if (indexes[idx][1] != -1) {
            curr->right = new Node();
            createTree(curr->right, indexes, indexes[idx][1]-1, curr->depth+1);
        }
    }
}


vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node* curr = head;
    createTree(curr, indexes, 0);
    vector<vector<int>> results;
    results = swapChilds(curr, queries);
    return results;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
