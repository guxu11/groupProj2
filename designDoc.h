//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.

//Please make sure that you include the entire content of this file as comments.

/* Design Doc: communicate your thought process in English.

0. List of members who contributed to the implementation of this project:
Xu Gu
Chan-Chun Yen
Joyce Fu

1. Describe your algorithm for the sentenceSplitter( ) function in pseudocode.
Input:
    fname: the name of the file to be read
    sentences: a vector of strings to store the sentences in the file
Output:
    void (inPlace modification of the sentences vector)
Algorithm:
    // Step 1
    Initialize a string holder outSS
 	inFile = textFile.open(). //open the file
    // Step 2: read each line of the file
    // time complexity: O(n), n=m*k, m is the lines' count of the file, k is the length of the line
    while line := inFile.readLine: // O(m), m is the lines' count of the file
        // add a special sign to the end of each line
        line = line + "&"
        // Step 3 traverse each character in the line
        // time complexity: O(k),  k is the length of the line
        for each character in the line (exclude the special sign at the end of each line):
            // skip the leading space of a sentence
            if character is a space and current sentence is empty:
                jump to next character
            // skip the sentence delimiters, and jump to next character if sentence delimiters' length is 1, otherwise jump to next 2 characters
            if character == '.' or '?':
                if the next character == '"' :
                    jump to next 2 character
                else:
                    jump to next character
            // if the character is not a leading space or a sentence delimiter, append it to sentence holder
            outSS.append(character)
            // sentence is complete, add it to sentences vector and clear sentence holder
            if the next character == '.'or '?' or '&':
                sentences.add(outSS)
                outSS = ""
Time complexity: O(n), n is the number of words in the file, equal to m*k, m is the lines' count of the file, k is the length of the line

2. Describe your algorithm for the wordpairMapping( ) function in pseudocode.
 Input:
    sentences: a vector of sentences
    wordpairFreq_map: empty map
 Output:
    void (InPlace modification of wordpairFreq_map)
 Algorithm:
    for each sentence in sentences: // O(n*m^2), n is the size of sentences, m is the words' count of each sentence
        // Add words in a sentence into a set uniqueWords
        // Step 1: Time Complexity: O(m*k), // m is the words' count of a sentence, and k is the length of each words
        for each word in sentence:
            initialize a set uniqueWords
            word.toLowerCase() // O(k)  k is the length of each words
            uniqueWords.add(word)
        //step 2: Time Complexity: O(m^2) // m is the unique words' count of a sentence
        // Make pairs of words in a sentence and add them and their frequencies into wordpairFreq_map
        for leftWord in uniqueWords:
            for rightWord in uniqueWords:
                // order leftWord and rightWord in a lexicographical order
                if leftWord > rightWord:
                    swap(leftWord, rightWord)
                makePair(leftWord, rightWord)
                // add pairs and their frequencies into wordpairFreq_map
                if wordpairFreq_map.contains[wordPair]:
                    wordpairFreq_map[wordPair]++
                else:
                    wordpairFreq_map[wordPair] := 1

Time complexity: O(n*m^2) // n is the size of sentences, and m is words' count of each sentence.
                          // Considering words' count of each sentence is greater than words' length
*/