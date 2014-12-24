#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class anagram {
	/* Class for finding all anagrams of a word in a group*/
private:
	string m_strWord, m_strLetters;
public:
	anagram(string strWord) {
		m_strWord = strWord;
		// lower case
		transform(m_strWord.begin(), m_strWord.end(), m_strWord.begin(), ::tolower);
		m_strLetters = m_strWord;
		// letter in word
		sort(m_strLetters.begin(), m_strLetters.end());
	}

	vector<string> matches(vector<string> v_strWords) {
		/* Finds return all anagrams of a word in a group of words*/
		vector<string> v_strAnagrams;
		for (vector<string>::const_iterator it = v_strWords.begin();
			it != v_strWords.end();
			it++)
		{
			string word = *it;
			// make word lower case
			transform(word.begin(), word.end(), word.begin(), ::tolower);
			string strLetters = word;
			// sort letters in word
			sort(strLetters.begin(), strLetters.end());
			// only include anagrams, not the original word
			if (strLetters == m_strLetters && word != m_strWord)
				v_strAnagrams.push_back(*it);
		}
		return v_strAnagrams;
	}
};

#endif