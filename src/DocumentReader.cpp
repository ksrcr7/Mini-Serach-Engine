#include "DocumentReader.h"
#include <stdexcept>
#include <algorithm>


static bool is_Space(const std::string& st){
    return std::all_of(st.begin(),st.end(),
                       [](unsigned char ch){return std::isspace(ch);});
}


static bool path_validation(const std::string& path){
    if(path.empty())return false;
    if(is_Space(path))return false;
    return true;
}





DocumentReader::DocumentReader(const std::string &path) {
    if(!path_validation(path)){
        throw std::invalid_argument("Path must not be empty.");
    }
    m_root = path;

}
