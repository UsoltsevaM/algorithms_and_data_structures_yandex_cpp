#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>

static const size_t sAlphabetSize = 26;

struct TrieNode
{
    TrieNode* children[sAlphabetSize];

    bool isLeaf = false;
    std::vector<std::string> words;
};

TrieNode* createTrieNode()
{
    TrieNode* pNode = new TrieNode;
    pNode->isLeaf = false;

    for (size_t i = 0; i < sAlphabetSize; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void freeTrie(TrieNode* pCurrent)
{
    if (!pCurrent)
        return;

    for (size_t i = 0; i < sAlphabetSize; i++)
        freeTrie(pCurrent->children[i]);

    delete pCurrent;
}

void insert(TrieNode* pRoot, const std::string& word)
{
    TrieNode* pCurrent = pRoot;

    for (size_t i = 0; i < word.size(); i++)
    {
        if (std::islower(word[i]))
            continue;

        int charIdx = word[i] - 'A';
        if (!pCurrent->children[charIdx])
            pCurrent->children[charIdx] = createTrieNode();

        pCurrent = pCurrent->children[charIdx];
    }

    pCurrent->isLeaf = true;
    pCurrent->words.push_back(word);
}

void collectAllWords(TrieNode* pRoot, std::vector<std::string>& res)
{
    if (pRoot->isLeaf)
        res.insert(res.end(), pRoot->words.begin(), pRoot->words.end());

    for (int i = 0; i < sAlphabetSize; i++)
    {
        TrieNode* pCurrent = pRoot->children[i];
        if (pCurrent)
            collectAllWords(pCurrent, res);
    }
}

bool search(TrieNode* pRoot, const std::string& pattern, std::vector<std::string>& res)
{
    TrieNode* pCurrent = pRoot;

    for (size_t i = 0; i < pattern.length(); i++)
    {
        int charIdx = pattern[i] - 'A';
        if (!pCurrent->children[charIdx])
            return false;

        pCurrent = pCurrent->children[charIdx];
    }

    collectAllWords(pCurrent, res);

    return true;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<std::string> dict(n);
    for (int i = 0; i < n; i++)
        std::cin >> dict[i];

    int m = 0;
    std::cin >> m;

    std::cin.ignore();

    std::vector<std::string> patterns(m);
    for (int i = 0; i < m; i++)
        std::getline(std::cin, patterns[i]);

    TrieNode* pRoot = createTrieNode();
    for (const std::string& word : dict)
        insert(pRoot, word);

    for (const auto& pattern : patterns)
    {
        std::vector<std::string> res;
        search(pRoot, pattern, res);
        std::sort(res.begin(), res.end());
        for (const auto& it : res)
            std::cout << it << std::endl;
    }

    return 0;
}