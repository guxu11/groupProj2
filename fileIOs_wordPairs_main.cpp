#include <iostream>
#include"fileIOs_wordPairs.h"

// unit test for sentenceSplitter - 1
bool test_sentenceSplitter1() {
    std::string fileName = "/Users/guxu/CLionProjects/GroupProj2/test_inputs/test_input1.txt"; // test_input1.txt contains 2 lines and  4 sentence
    std::vector<std::string> sentences;
    sentenceSplitter(fileName, sentences);
    if (sentences.size() != 4) {
        return false;
    }
    return true;
}

// unit test for sentenceSplitter - 2
bool test_sentenceSplitter2() {
    std::string fileName = "/Users/guxu/CLionProjects/GroupProj2/test_inputs/test_input2.txt"; // test_input2.txt contains 3 lines and  5 sentence
    std::vector<std::string> sentences;
    sentenceSplitter(fileName, sentences);
    if (sentences.size() != 5) {
        return false;
    }
    return true;
}
// unit test for sentenceSplitter - 3
// test for empty file
bool test_sentenceSplitter3() {
    std::string fileName = "/Users/guxu/CLionProjects/GroupProj2/test_inputs/test_input3.txt"; // test_input3.txt is empty
    std::vector<std::string> sentences;
    sentenceSplitter(fileName, sentences);
    if (sentences.size() != 0) {
        return false;
    }
    return true;
}

// unit test for wordpairMapping - 1
bool test_wordpairMapping1() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    std::vector<std::string> sentences = {"test1 123 test2 456", "123 test1 test3 test2", "test2, 234"};
    wordpairMapping(sentences, wordpairFreq_map);
    if (wordpairFreq_map.size() != 10) {
        return false;
    }
    return true;
}

// unit test for wordpairMapping - 2
bool test_wordpairMapping2() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    std::vector<std::string> sentences = {"test1 123 test2 456", "123 test1 test3 test2", "test2 234 test1 haha"};
    wordpairMapping(sentences, wordpairFreq_map);
    if (wordpairFreq_map.size() != 14) {
        return false;
    }
    return true;
}

// unit test for wordpairMapping - 3
// test for empty sentences
bool test_wordpairMapping3() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    std::vector<std::string> sentences;
    wordpairMapping(sentences, wordpairFreq_map);
    if (wordpairFreq_map.size() != 0) {
        return false;
    }
    return true;
}

// unit test for freqWordpairMmap - 1
bool test_freqWordpairMmap1() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test1", "test2"), 5));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test2", "test3"), 3));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test4", "test5"), 1));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test2", "test5"), 2));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test9", "test10"), 1));
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);
    if (freqWordpair_mmap.size() != 5) return false;
    if (freqWordpair_mmap.find(1)->second.first != "test4" || freqWordpair_mmap.find(1)->second.second != "test5") return false;
    if (freqWordpair_mmap.find(5)->second.first != "test1" || freqWordpair_mmap.find(5)->second.second != "test2") return false;
    if (freqWordpair_mmap.find(2)->second.first != "test2" || freqWordpair_mmap.find(2)->second.second != "test5") return false;
    if (freqWordpair_mmap.find(3)->second.first != "test2" || freqWordpair_mmap.find(3)->second.second != "test3") return false;
    return true;
}

// unit test for freqWordpairMmap - 2
bool test_freqWordpairMmap2() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test1", "test2"), 1));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test2", "test3"), 1));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test4", "test5"), 1));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test2", "test5"), 2));
    wordpairFreq_map.insert(std::make_pair(std::make_pair("test9", "test10"), 1));
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);
    if (freqWordpair_mmap.size() != 5) return false;
    if (freqWordpair_mmap.find(1)->second.first != "test1" || freqWordpair_mmap.find(1)->second.second != "test2") return false;
    if (freqWordpair_mmap.find(2)->second.first != "test2" || freqWordpair_mmap.find(2)->second.second != "test5") return false;
    return true;
}
// unit test for freqWordpairMmap - 3
// test for empty wordpairFreq_map
bool test_freqWordpairMmap3() {
    std::map<std::pair<std::string, std::string>, int> wordpairFreq_map;
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpairMmap(wordpairFreq_map, freqWordpair_mmap);
    if (freqWordpair_mmap.size() != 0) return false;
    return true;
}

// unit test for printWordpairs - 1
bool test_printWordpairs1() {
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpair_mmap.insert(std::make_pair(1, std::make_pair("test1", "test2")));
    freqWordpair_mmap.insert(std::make_pair(2, std::make_pair("test2", "test3")));
    freqWordpair_mmap.insert(std::make_pair(3, std::make_pair("test4", "test5")));
    freqWordpair_mmap.insert(std::make_pair(4, std::make_pair("test2", "test5")));
    freqWordpair_mmap.insert(std::make_pair(5, std::make_pair("test9", "test10")));
    std::string outFname = "/Users/guxu/CLionProjects/GroupProj2/test_outputs/test_output1.txt";
    int topCnt = 3;
    int botCnt = 2;
    printWordpairs(freqWordpair_mmap, outFname, topCnt, botCnt);
    std::ifstream outFile(outFname);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return false;
    }
    bool res = true;
    std::string line;
    std::getline(outFile, line);
    if (line != "<test9, test10>: 5") res = false;
    std::getline(outFile, line);
    if (line != "<test2, test5>: 4")  res = false;
    std::getline(outFile, line);
    if (line != "<test4, test5>: 3")  res = false;
    std::getline(outFile, line);
    if (line != "<test1, test2>: 1")  res = false;
    std::getline(outFile, line);
    if (line != "<test2, test3>: 2")  res = false;
    outFile.close();
    return res;
}
// unit test for printWordpairs - 2
bool test_printWordpairs2() {
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    freqWordpair_mmap.insert(std::make_pair(1, std::make_pair("test1", "test2")));
    freqWordpair_mmap.insert(std::make_pair(2, std::make_pair("test2", "test3")));
    freqWordpair_mmap.insert(std::make_pair(3, std::make_pair("test4", "test5")));
    freqWordpair_mmap.insert(std::make_pair(4, std::make_pair("test2", "test5")));
    freqWordpair_mmap.insert(std::make_pair(5, std::make_pair("test9", "test10")));
    std::string outFname = "/Users/guxu/CLionProjects/GroupProj2/test_outputs/test_output2.txt";
    int topCnt = 4;
    int botCnt = 1;
    printWordpairs(freqWordpair_mmap, outFname, topCnt, botCnt);
    std::ifstream outFile(outFname);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return false;
    }
    bool res = true;
    std::string line;
    std::getline(outFile, line);
    if (line != "<test9, test10>: 5") res = false;
    std::getline(outFile, line);
    if (line != "<test2, test5>: 4")  res = false;
    std::getline(outFile, line);
    if (line != "<test4, test5>: 3")  res = false;
    std::getline(outFile, line);
    if (line != "<test2, test3>: 2")  res = false;
    std::getline(outFile, line);
    if (line != "<test1, test2>: 1")  res = false;
    outFile.close();
    return res;
}

// unit test for printWordpairs - 3
bool test_printWordpairs3() {
    std::multimap<int, std::pair<std::string, std::string>> freqWordpair_mmap;
    std::string outFname = "/Users/guxu/CLionProjects/GroupProj2/test_outputs/test_output3.txt";
    int topCnt = 3;
    int botCnt = 2;
    printWordpairs(freqWordpair_mmap, outFname, topCnt, botCnt);
    std::ifstream outFile(outFname);
    if (!outFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return false;
    }
    bool res = true;
    std::string line;
    std::getline(outFile, line);
    if (!line.empty()) res = false;
    outFile.close();
    return res;
}

int main() {
    // unit tests for sentenceSplitter
    std::cout << std::boolalpha << test_sentenceSplitter1() << std::endl;
    std::cout << std::boolalpha << test_sentenceSplitter2() << std::endl;
    std::cout << std::boolalpha << test_sentenceSplitter3() << std::endl;

    // unit tests for wordpairMapping
    std::cout << std::boolalpha << test_wordpairMapping1() << std::endl;
    std::cout << std::boolalpha << test_wordpairMapping2() << std::endl;
    std::cout << std::boolalpha << test_wordpairMapping3() << std::endl;

    // unit tests for freqWordpairMmap
    std::cout << std::boolalpha << test_freqWordpairMmap1() << std::endl;
    std::cout << std::boolalpha << test_freqWordpairMmap2() << std::endl;
    std::cout << std::boolalpha << test_freqWordpairMmap3() << std::endl;

    // unit tests for printWordpairs
    std::cout << std::boolalpha << test_printWordpairs1() << std::endl;
    std::cout << std::boolalpha << test_printWordpairs2() << std::endl;
    std::cout << std::boolalpha << test_printWordpairs3() << std::endl;
    return 0;
}
