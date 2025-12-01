#ifndef MINI_SEARCH_ENGINE_SEARCHENGINE_H
#define MINI_SEARCH_ENGINE_SEARCHENGINE_H

#include "Indexer.h"
#include "Tokenizer.h"
#include <iostream>
#include <vector>

class SearchEngine{
private:
    Indexer* indexer;
    Tokenizer tokenizer;

public:
    explicit SearchEngine(Indexer* idx):indexer(idx){}
    std::vector<std::string> search(const std::string&);
};




#endif //MINI_SEARCH_ENGINE_SEARCHENGINE_H
