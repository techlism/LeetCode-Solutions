#include <unordered_map>
#include <vector>
using namespace std;

int countSubarraysWithXOR(vector<int>& A, int B) {
    unordered_map<int, int> prefixXORCount;
    int count = 0;
    int prefixXOR = 0;

    for (int num : A) {
        // Update the current prefix XOR
        prefixXOR ^= num;

        // If the current prefix XOR is equal to B, we found a subarray
        if (prefixXOR == B) {
            count++;
        }

        // If there exists a prefix XOR such that (prefixXOR ^ B) has been seen before
        int targetXOR = prefixXOR ^ B;
        if (prefixXORCount.find(targetXOR) != prefixXORCount.end()) {
            count += prefixXORCount[targetXOR];
        }

        // Update the frequency of the current prefix XOR
        prefixXORCount[prefixXOR]++;
    }

    return count;
}
