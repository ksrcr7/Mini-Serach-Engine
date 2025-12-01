#include "SearchEngine.h"
#include <algorithm>
#include <unordered_map>

static bool is_Space(const std::string& st){
    return std::all_of(st.begin(),st.end(),
                       [](unsigned char ch){return std::isspace(ch);});
}

std::vector<std::string> SearchEngine::search(const std::string &query) {
    std::vector<std::string> result;
    if(query.empty() || is_Space(query))return result;

    auto tokenize = tokenizer.cleanedText(query);
    std::unordered_map<std::string ,int> score;

    for(const auto& token : tokenize){
        auto docsForToken = indexer->getDocumentsForToken(token);
        for(const auto& it : docsForToken)
            ++score[it];

    }

    std::vector<std::pair<std::string,int>> vec(score.begin(),score.end());
    std::sort(vec.begin(),vec.end(),
              [](const auto &a,const auto&b){
                  return a.second > b.second;
    });

    result.reserve(vec.size());
    for(const auto& [key,value] : vec){
        result.emplace_back(key);
    }
    return result;

}
