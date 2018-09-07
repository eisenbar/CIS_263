//
//  WordSearch.cpp
//  CS263-HW4
//
//  Ryan Eisenbarth
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>  // needed for transform()
#include <exception>
#include <regex>
#include "WordSearch.h"

WordSearch::WordSearch() {
    /* default constructor requires no additional code */
}

WordSearch::WordSearch(const string& topdir, const string& ignore_file) {
    load_ignored_words(ignore_file);
    /* filter the directory only for files ending with "txt" */
    gvsu::FileSystem dir (topdir, regex{"txt$"});

    for (auto entry : dir) {
        cout << "Reading words from " << entry.second << endl;
        read_words (entry.first + "/" + entry.second);
    }
}

void WordSearch::load_ignored_words(const string& fname) {
    ifstream ign_file (fname);
    if (!ign_file.is_open()) {
        throw ios_base::failure {"Unable to load ignored.txt"};

    }
    string word;
    while (getline(ign_file, word))
        ignored_words.insert(word);
    ign_file.close();
}

void WordSearch::read_words(const string &file_name)
{
    /* a word is THREE OR MORE alphabetical characters (lowercase) */
    const regex word_re {"[a-z]{3,}"};

    /* Alternate declaration of the above regular expr
     const regex word_re {"[[:alpha:]]{3,}"};
     */
    ifstream txt (file_name); /* file is aumatically open */

    string one_line;

    int line = 1;
    string prev = "";
    while (getline(txt, one_line)) {
        /* change to lowercase */
        transform(one_line.begin(), one_line.end(), one_line.begin(), ::tolower);
        /* iterate over the string using a regular expression */
        auto re_begin = sregex_iterator {one_line.begin(),one_line.end(), word_re};
        auto re_end = sregex_iterator{};
        for (auto word = re_begin; word != re_end; ++word) {
            /* if the word is in the ignored list, don't print it */
            if (ignored_words.find(word->str()) == ignored_words.end())
            {
                wordAmount[word->str()] += 1;

                if(prev.length() > 0)
                    nextGuessData[prev][word->str()] += 1;

                prev = word->str();
                total ++;
            }
        }
        line++;
    }
    txt.close(); /* close the file */
}


unsigned long WordSearch::word_count() const {
    return total;
}

set<string> WordSearch::words_of_length (int L) const {

    set<string> words;
    string w;

    //search word amount for words of length L
    //map SI is a map with key String and data Int
    for(auto mapSI: wordAmount) {
        w = mapSI.first;
        if (w.length() == L)
            words.insert(w);
    }

        return words;   /* return an empty set */
}

pair<unsigned int,set<string>> WordSearch::most_frequent_words() const {

    if(wordAmount.empty())
        throw length_error("No Data was Read!");

    set<string> words;

    unsigned int amount = 0;
    int setNum = 0;
    int max = 0;

    for(auto mapSI: wordAmount){
        setNum = mapSI.second;
        if(setNum > max){
            amount = 0;

            //clears out words since a new most frequent was found
            words.clear();
            max = setNum;
        }
        if(setNum == max){
            amount += setNum;
            words.insert(mapSI.first);
        }
    }

    return make_pair(amount, words);
}

set<string> WordSearch::least_frequent_words(int count) const {
    set<string> words;

    string w = "";
    int wCount = 0;

    for(auto mapSI: wordAmount){
        w = mapSI.first;
        wCount = mapSI.second;
        if(wCount <= count)
            words.insert(w);
    }

    return words;

}

string WordSearch::most_probable_word_after(const string& word) const {
    string mostProbable = "";
    int maxCount = 0;
    int count = 0;
    auto map = nextGuessData.at(word);

    //map string int = mapWI
    for(auto mapSI: map){
        count = mapSI.second;
        if(count > maxCount){
            mostProbable = mapSI.first;
            maxCount = count;
        }
    }

    return mostProbable;
}