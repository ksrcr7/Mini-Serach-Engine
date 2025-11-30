#include "Indexer.h"
#include <algorithm>

void Indexer::buildIndex(const std::vector<Document> &docs) {
    m_index.clear();
    for(const auto& it : docs){
        auto tokens = m_tokenizer.cleanedText(it.content);
        if(tokens.empty())continue;

        std::sort(tokens.begin(),tokens.end());
        tokens.erase(std::unique(tokens.begin(),tokens.end()),tokens.end());
        for(const auto& token : tokens){
            m_index[token].insert(it.id);
        }
    }

}

std::vector<std::string> Indexer::getDocumentsForToken(const std::string &token) const {
    std::vector<std::string> result;
    auto it = m_index.find(token);
    if (it == m_index.end()) {
        return result;
    }
    result.assign(it->second.begin(), it->second.end());
    return result;
}
