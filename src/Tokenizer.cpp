#include "Tokenizer.h"
#include <algorithm>
#include <cctype>

static bool is_space(const std::string& st){
    return std::all_of(st.begin(),st.end(),
                       [](unsigned char ch){return std::isspace(ch);});
}


std::vector<std::string> Tokenizer::cleanedText(const std::string &text) {
    std::vector<std::string> cleaned;
    if(text.empty() || is_space(text))return cleaned;

    std::string temp;
    for(unsigned char ch : text) {
        if (std::isspace(ch)) {
            if (!temp.empty()) {
                cleaned.emplace_back(temp);
            }
            temp.clear();
            continue;
        }
        if (std::isalpha(ch)) {
            temp += static_cast<char>(std::tolower(ch));
        }
        else if (std::isdigit(ch)) {
            temp += static_cast<char>(ch);
        }

        else {
            if(!temp.empty()){
                cleaned.emplace_back(temp);
            }
            temp.clear();
            continue;
        }

    }
    if(!temp.empty())cleaned.emplace_back(temp);

    return cleaned;


}
