#ifndef MINI_SEARCH_ENGINE_INDEXER_H
#define MINI_SEARCH_ENGINE_INDEXER_H

#include "Tokenizer.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

class Indexer{
private:
    std::unordered_map<std::string,std::unordered_set<std::string>> m_index;
    Tokenizer m_tokenizer;



public:
    void buildIndex(const std::vector<Document>&);
    std::vector<std::string> getDocumentsForToken(const std::string& token) const;


};


















#endif //MINI_SEARCH_ENGINE_INDEXER_H
