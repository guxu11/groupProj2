#ifndef STRINGSPLITTER_FILEIOS_WORDPAIRS_H
#define STRINGSPLITTER_FILEIOS_WORDPAIRS_H

#include<string>
#include<vector>
#include<map>
#include<cctype>
#include<sstream>
#include<set>
#include<iostream>
#include<algorithm>
#include<fstream>

void sentenceSplitter( std::string& fname, std::vector<std::string>& sentences);

void wordpairMapping( std::vector<std::string>& sentences, std::map< std::pair<std::string,std::string>, int> &wordpairFreq_map);

void freqWordpairMmap(std::map< std::pair<std::string,std::string>, int> &wordpairFreq_map, std::multimap<int, std::pair<std::string, std::string> > &freqWordpair_mmap );

void printWordpairs(std::multimap<int,std:: pair<std::string, std::string> > &freqWordpair_multimap, std::string outFname, int topCnt, int botCnt);

#endif //STRINGSPLITTER_FILEIOS_WORDPAIRS_H
