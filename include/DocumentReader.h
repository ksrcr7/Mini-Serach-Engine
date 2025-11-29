#ifndef MINI_SEARCH_ENGINE_DOCUMENTREADER_H
#define MINI_SEARCH_ENGINE_DOCUMENTREADER_H

#pragma once
#include "Document.h"
#include <vector>


class DocumentReader{
private:
    std::string m_root;
    static bool isTextFile(const std::string&);
public:
    explicit DocumentReader(const std::string&);
    [[nodiscard]] std::vector<Document> loadAllDocuments()const;


};





















#endif //MINI_SEARCH_ENGINE_DOCUMENTREADER_H
