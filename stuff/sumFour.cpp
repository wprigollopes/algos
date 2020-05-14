#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    // 4 somas - cria um hash de duas somas
    unordered_map<int, vector<vector<int>>> allPairsSums;
    // Vetor de retorno
	vector<vector<int>> quadruplets = {};
	// The first do not access the first and last elements
	for (int i=1; i<array.size()-1; i++) {
        // This block checks if element is on hashmap, if is, put the quadruplet on list
		for (int j=i+1; j<array.size(); j++) {
            // Soma atual
			int currentSum = array[i] + array[j];
            // Pega a diferença
			int difference = targetSum - currentSum;
            // Confere se a diferença está na lista de somas
			if (allPairsSums.find(difference) != allPairsSums.end()) {
                // Se estiver, adiciona em todas as somas
				for (auto pair: allPairsSums[difference]) {
					quadruplets.push_back({pair[0], pair[1], array[i], array[j]});
				}
			}
		}
        // This block constructs sequentially the elements in hashmap
        for (int k=0; k<i; k++) {
            // Pega soma atual para criar hash
            int currentSum = array[i]+array[k];
            // Checa se não existe esse hash
            if (allPairsSums.find(currentSum) == allPairsSums.end() ) {
                allPairsSums.insert({currentSum, {{array[k],array[i]}}});
            } else {
                vector<vector<int>> pairSum = allPairsSums[currentSum];
                pairSum.push_back({array[k],array[i]});
                allPairsSums[currentSum] = pairSum;
            }
        }
	}
    cout << "Teste" << endl;
  return quadruplets;
}


int main() {
    vector<int> array = {1,2,3,4,5,6,7,8,9};
    int targetSum = 10;
    vector<vector<int>> result = fourNumberSum(array, targetSum);
    cout << "Finished" << endl;
    return 0;
}