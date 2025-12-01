#include <iostream>
#include "DocumentReader.h"
#include "SearchEngine.h"
#include "Indexer.h"

int main() {
std::string root = "d1";
DocumentReader reader(root);
auto docs = reader.loadAllDocuments();
std::cout<<"Load documents: "<<docs.size()<<std::endl;

Indexer indexer;
indexer.buildIndex(docs);
SearchEngine se(&indexer);

    while (true){
        std::cout<<"\nEnter query (or 'exit'): ";
        std::string query;
        std::getline(std::cin,query);

        if(query == "exit")break;

        auto results = se.search(query);
        std::cout << "\nResults:\n";
        if (results.empty()) {
            std::cout << "  No documents found.\n";
        } else {
            for (const auto& id : results) {
                std::cout << "  - " << id << "\n";
            }
        }
    }
    return 0;




}



