#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <map>
#include <string>
#include <vector>

namespace word_count {
	using namespace std;

	vector<string> get_words(string strSentence) {
		/* Changes a string into a series of words*/
		vector<string> words;
		string word;
		for (unsigned int iii = 0; iii <= strSentence.length(); iii++) {
			char cLetter = strSentence[iii];
			// Include only letters, numbers and '
			if (isalnum(cLetter))
				word += tolower(cLetter);
			else if (cLetter == '\'' && !word.empty())
				word += cLetter;
			// Add words when a delimiator is found
			else if (!word.empty()) {
				// Remove ' from the end
				if (word.back() == '\'')
					word.pop_back();
				words.push_back(word);
				word.clear();
			}
		}
		return words;
	}

	map<string, int> words(const string strSentence) {
		/* Counts the number of times each word appear in strSentence*/
		vector<string> words = get_words(strSentence);
		map<string, int> mWordCount;
		
		for (vector<string>::const_iterator it = words.begin();
			it != words.end();
			it++)
		{
			mWordCount[*it]++;
		}
		return mWordCount;
	}
};

#endif