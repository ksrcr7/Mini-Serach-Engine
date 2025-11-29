#include "DocumentReader.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <filesystem>
#include <fstream>


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

bool DocumentReader::isTextFile(const std::string &path) {
    if(path.size() <= 4)return false;
    if(!path.ends_with(".txt"))return false;
    return true;

}

std::vector<Document> DocumentReader::loadAllDocuments() const {
    std::vector<Document> docs;
    namespace fs = std::filesystem;

    fs::path root = m_root;
    for(const auto& entry : fs::recursive_directory_iterator(root)){
        if(!entry.is_regular_file())continue;

        std::string fullpath = entry.path().string();
        if(!isTextFile(fullpath))continue;

        std::ifstream openFile(fullpath);
        if(!openFile.is_open()){
            std::cerr<<"Can not open file: "<<fullpath<<std::endl;
            continue;
        }

        std::string content,line;
        while (std::getline(openFile,line)){
            content += line;
            content +='\n';
        }
        openFile.close();

        Document doc;
        doc.id = entry.path().filename().string();
        doc.path = fullpath;
        doc.content = content;
        docs.emplace_back(doc);
    }
    return docs;

}


