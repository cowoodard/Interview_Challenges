/*Question 2
 * Write a simple program to list the occurrence count of all those words shown in the following text file. (try not to use third party library)
Following is the content of a text file sometext.txt (file is attachment in the email) :
--------------- beginning of sometext.txt file ---------------------------------------------

Information on the C++ language 

A brief description:

Some general aspects of this language. 

History of C++:

Brief history of the development of this language.

Frequently Asked Questions:

A short list of common questions novice programmers ask.

-------------------------- end of sometext.txt file ---------------
* 
*/

#include <bits/stdc++.h>

using namespace std;

/*Used to print map*/

template <class KTy, class Ty>
void PrintMap(map<KTy, Ty> map)
{
    typedef typename std::map<KTy, Ty>::iterator iterator;
    for (iterator i = map.begin(); i != map.end(); i++)
        cout << i->first << " = " << i->second << endl;
}

int main()
{
    static const char* fileName1 = "sometext.txt";    
	// Will store the word and count.
    map<string, unsigned int> wordsCount;    
    // Begin reading from file:
    ifstream fileStream(fileName1);

        // Check if we've opened the file (as we should have).
    if (fileStream.is_open())
       while (fileStream.good())
         {
             // Store the next word in the file in a local variable.
             string word;
             fileStream >> word;
             
             //Remove Punctuation
             word.erase(remove(word.begin(), word.end(), ':'), word.end());
             word.erase(remove(word.begin(), word.end(), '.'), word.end());
			 
			 //Convert words to uppercare to count same words but with some as capital letters
			 transform(word.begin(), word.end(), word.begin(), ::toupper);

             //Look if it's already there.
             if (wordsCount.find(word) == wordsCount.end()) //First time encountering the word
                 wordsCount[word] = 1; // Initialize it to 1.
             else // Then we've already seen it before..
                 wordsCount[word]++; // Just increment it.
           }
    else  // We couldn't open the file. Report the error in the error stream.
       {
         cerr << "Couldn't open the file." << endl;
         return EXIT_FAILURE;
       }

     // Print the words map.
    cout<<"Word Count"<<endl;
    PrintMap(wordsCount);
    
    return 0;
}
