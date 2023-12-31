//
//  main.cpp
//  BookAnalyzer
//
//  Created by Josh Barton on 8/31/23.
//

#include <iostream>
#include <fstream> //file stream
#include <cstdlib> // For exit() function
#include <vector>
#include "bookAnalyzer.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //use argv to allow the user to pass a filename and keyword to look for
    std::string filename = argv[1];
    std::string keyWordFromUser = argv[2];
    
    //create stream variable that will input the book
    std::ifstream inputBookStream;
    inputBookStream.open(filename);

    //check to see if book stream opened properly
    if( inputBookStream.fail() ) {
        std::cout << "Failed to open file.\n";
        // Kill the program and exit with a return value of 1
        exit(1);

    }
    
    //create a string varible that each word of the file text will be read into
    std::string word;
    
    //create a vector to store the words from the book
    std::vector<std::string> allWordsOfBook;

    //use a while loop to stream in the entire book
    while (inputBookStream >> word) {
        //std::cout << "Read in: " << word << "\n";
        allWordsOfBook.push_back(word);
    }

    
    //print out Book Title
    std::cout << findBookTitle(allWordsOfBook) << std::endl;
    
    //print out Book Author
    std::cout << findBookAuthor(allWordsOfBook) << std::endl;
    
    //print out number of words in the file
    std::cout << "Number of words: " << calculateTotalNumOfWordsInFile(allWordsOfBook) << std::endl;
    
    //print out number of characters in the file
    std::cout << "Number of characters: " << calculateTotalNumOfCharactersInFile(allWordsOfBook) << std::endl;
    
    //print out the shortest word in the file and the longest word
    std::cout << "The shortest word is: " << findShortestWordInBook(allWordsOfBook) << "\nThe longest word is: " << findLongestWordInBook(allWordsOfBook) << std::endl;
    
    
//    //ask fo a key word
//    std::cout << "Please enter a word to search for:" << std::endl;
//
//    //create a keyword variable that will store the input from the user
//    std::string keyWordFromUser;
//    //get the keyword from the user
//    std::cin >> keyWordFromUser;
    
    
    
    //print out the number of times the word appears in the book
    std::cout << "The word " << keyWordFromUser << " appears " << findHowManyTimesKeyWordAppears(keyWordFromUser, allWordsOfBook) << " times:" << std::endl;
    
    //assign variable to the return value of calculate total num of characters function
    int totalNumOfCharacters = calculateTotalNumOfCharactersInFile(allWordsOfBook);
    

    //call the keyword and statistics function
    giveKeyWordStatisticsAndInformation(keyWordFromUser, totalNumOfCharacters, allWordsOfBook);
    
    
    return 0;
}
