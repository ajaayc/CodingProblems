#include <queue>
#include <iostream>
#include <stack>
#include <limits>
#include <map>
#define COUNT 10 

using namespace std;

//This solution uses O(n) memory for recursion
//It uses O(26^n) time avg in order to count the number of words
//that can be generated from tiles, where n is the number of
//characters in tiles. We can consider it to be O(a^n), where
//a is the number of unique characters in the input tiles string.
//a is bounded by 26.
//In the best case where there's only one letter e.g. AAAAAAAA,
//it would take O(n) time.
//It saves a lot on memory by ensuring that we don't store all
//of the generated words -- just the counts
class Solution {
public:
    void countWords(std::map<char,int>& charCounts, int& numWords){
        for(auto it = charCounts.begin(); it != charCounts.end(); ++it){
            char currChar = it->first;
            int currCharCount = it->second;

            if(currCharCount != 0){
                --charCounts[currChar];
                numWords += 1;
                countWords(charCounts,numWords);
                ++charCounts[currChar];
            }
        }
    }

    int numTilePossibilities(string tiles) {
        //Create a map of counts for each letter
        std::map<char,int> charCounts;

        for(char c:tiles){
            charCounts[c] += 1;
        }

        int numWords = 0;
        //Recurse
        countWords(charCounts,numWords);
        return numWords;
    }
};

int main(){
    Solution s;
    //string tiles = "AAB";
    string tiles = "AAABBC";
    int count = s.numTilePossibilities(tiles);

    cout << "Num words for " << tiles << ": " << count << endl;
}
