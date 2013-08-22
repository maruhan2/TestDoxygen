/**
 * \file myspell.cpp
 * \author Kevin McSwiggen and Mars Park
 *   Option processing code adapted from Bailey Campbell's NatSelPath.
 *
 * \brief Code for the MySpell spell checking program.
 *
 */

#include "abstractset.hpp"
#include "stringhash.hpp"
#include "hashset.hpp"
#include "stdhashset.hpp"
#include "treeset.hpp"
#include "stdtreeset.hpp"


#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <string>
#include <vector>
#include <list>
#include <cctype>

using namespace std;

/**
 * \brief Print a usage message and exit.
 *
 * \remarks As is conventional, the exit status is 2 if there is a
 *          usage error.
 */
void usage(
    const char* programName)            // Name we were run under
{
    cerr << "Usage:\t" << programName << " [options] fileName" << endl
         << "Switches:" << endl
         << "\t-d\tProduce debugging outout." << endl << endl
         << "\t-h\tConstruct dictionary using custom hashset implementation."
         << endl << endl
         << "\t-H\tConstruct dictionary using STL hashset implementation."
         << endl << endl
         << "\t-t\tConstruct dictionary using custom tree-set implementation."
         << endl << endl
         << "\t-T\tConstruct dictionary using STL set implementation."
         << endl << endl
         << "\tfileName is the location of the dictionary file to check against"
         << endl;
    exit(2);
}

/**
 * \brief Option processing.
 * \details Scan through the arguments, looking at switches.  If we
 *          run into a non-switch argument, exit the function.
 *
 *          If an illegal switch is detected, we will print a usage
 *          message to cerr and terminate the program with an exit
 *          status of 2.
 *
 * \return The number of the first non-switch argument encountered.
 *         If there are no non-switch arguments, the return value
 *         equals argc.
 *
 * \remarks This function is fairly long, even though it does
 *          relatively little.  That is generally true of
 *          switch-processing functions, and it is not considered bad
 *          style so long as the function limits itself to simple
 *          operations such as setting Boolean flags.
 */
int processOptions(
    int argc,                   ///< Argument count passed to main
    const char* argv[],         ///< Argument vector passed to main
    bool& debug,                ///< MODIFIED: set true if debugging enabled
    bool& stdhash,              ///< Set true if using STL unordered set
    bool& ownhash,              ///< Set true if using custom hashset
    bool& stdtree,              ///< Set true if using STL ordered set
    bool& owntree)              ///< Set true if using custom tree
{
    /*
     * Default switch values.
     */
    debug = false;

    int argNo;

    for (argNo = 1;  argNo < argc;  ++argNo)
    {
        if (argv[argNo][0] != '-')      // End of switches?
        {
            break;                      // If so, exit option processing
        }

        /*
         * By convention, the special switch option "--" means that
         * all following arguments are non-option arguments, even if
         * they start with a hyphen.  If we run into that switch, we
         * must skip over it but then exit the option-processing loop.
         */
        if (argv[argNo] == string("--"))
        {
            argNo++;                    // Skip over the --
            break;                      // Go to non-option argument processing
        }

        /*
         * All other switch options should consist of a single hyphen,
         * an alphabetic character, and nothing else.  At this point
         * we know that the hyphen exists.  Check to make sure that
         * there is exactly one character following it.
         */
        if (argv[argNo][1] == '\0' || argv[argNo][2] != '\0')
        {
            usage(argv[0]);
        }

        /*
         * Process switch options.  We do this in a "switch" statement
         * so that it is easy to add new options later.
         */
        switch (argv[argNo][1])
        {
        case 'd':                   // -d: Turn on debugging
            debug = true;
            break;

        case 'h':                   // -d: Turn on debugging
            ownhash = true;
            break;

        case 'H':                   // -d: Turn on debugging
            stdhash = true;
            break;

        case 't':                   // -d: Turn on debugging
            owntree = true;
            break;

        case 'T':                   // -d: Turn on debugging
            stdtree = true;
            break;

        default:                    // Default: unrecognized option
            usage(argv[0]);
            break;
        }
    }

    return argNo;
}

/**
 * \brief Generates a dictionary AbstractSet for MySpell.
 *
 * \details Takes as a parameter a filename and an AbstractSet<string> reference
 *   reading from the file to generate a dictionary in the set.
 */
bool readDictionary(const string& fileName, AbstractSet<string>* ourSet)
{
    ifstream inputStream(fileName.c_str());
    
    if (!inputStream)
    {
        return false; // Could not open the file
    }

    string currentWord = "";
    string charBuffer = "";

    char nextCharacter;

    while (inputStream.get(nextCharacter))
    {
        if (isalpha(nextCharacter))
        {
            for (string::iterator i = charBuffer.begin(); i != charBuffer.end();
                 ++i)
            {
                currentWord += tolower(*i);
            }
            charBuffer = "";
            currentWord += nextCharacter;
        }
        else if (!isspace(nextCharacter))
        {
            charBuffer += nextCharacter;
        }
        else
        {
            if (currentWord.length() != 0 && !ourSet->exists(currentWord))
            {
                ourSet->insert(currentWord);
            }
            charBuffer = "";
            currentWord = "";
        }
    }

    return true;
}

/**
 * \brief Helper function for checkSpelling which generates suggestions.
 *
 * \details Generates spelling suggestions for checkSpelling based on swapped
 *   letters in the original word.
 */
void permuteSpelling(const string& word, AbstractSet<string>* dictionary)
{
    cout << word << ":";
    for (size_t i = 0; i < word.length(); ++i)
    {
        string possible = word;
        for (char j = 'a'; j <= 'z'; ++j)
        {
            possible[i] = j;
            if (dictionary->exists(possible))
            {
                cout << " " << possible;
            }
        }
    }
    cout << endl;
}

/**
 * \brief Checks input against an AbstractSet dictionary of words.
 *
 * \details This function uses a previously-generated dictionary and compares
 *   input from cin against its content, offering spelling suggestions for any
 *   unrecognized words.
 */
void checkSpelling(AbstractSet<string>* dictionary, AbstractSet<string>* seen)
{

    string currentWord = "";
    string charBuffer = "";

    char nextCharacter;

    while (cin.get(nextCharacter))
    {
        if (isalpha(nextCharacter))
        {
            for (string::iterator i = charBuffer.begin(); i != charBuffer.end();
                 ++i)
            {
                currentWord += tolower(*i);
            }
            charBuffer = "";
            currentWord += tolower(nextCharacter);
        }
        else if (!isspace(nextCharacter) && currentWord != "")
        {
            charBuffer += nextCharacter;
        }
        else
        {
            if (currentWord.length() != 0 && !dictionary->exists(currentWord) 
                && !seen->exists(currentWord))
            {
                permuteSpelling(currentWord, dictionary);
                seen->insert(currentWord);
            }
            charBuffer = "";
            currentWord = "";
        }
    }
}

/**
 * \brief Main function for MySpell spellchecker.
 *
 * \details This function processes all option arguments, generates a dictionary
 *   set from the supplied file, and reads from an input source, offering
 *   spelling corrections for unrecognized words.
 */
int main(
    int argc,                           ///< Argument count
    const char* argv[])                 ///< Arguments
{
    bool debug = false;                         // Write debugging output
    bool stdhash = false;                       // Use STL unordered set
    bool ownhash = false;                       // Use custom hashset
    bool stdtree = false;                       // Use STL ordered set
    bool owntree = false;                       // Use custom tree

    AbstractSet<string>* dictSet;
    AbstractSet<string>* readSet;

    /*
     * Process all option arguments.  Note that the last is a reference 
     * parameter, which means that the function can modify it.  The return
     * value is the number of the first non-option argument on the command line.
     */
    int argNo = processOptions(argc, argv, debug, stdhash, ownhash, stdtree, 
        owntree);

    if (stdhash)
    {
        dictSet = new StdHashSet<string>;
        readSet = new StdHashSet<string>;
    }
    else if (ownhash)
    {
        dictSet = new HashSet<string>;
        readSet = new HashSet<string>;
    }
    else if (stdtree)
    {
        dictSet = new StdTreeSet<string>;
        readSet = new StdTreeSet<string>;
    }
    else if (owntree)
    {
        dictSet = new TreeSet<string>;
        readSet = new TreeSet<string>;
    }
    else
    {
        ownhash = true;
        dictSet = new HashSet<string>;
        readSet = new HashSet<string>;
    }

    /*
     * Check the arguments to make sure a dictionary file was supplied.  
     */
    if ((argc - argNo) != 1)
    {
        cerr << "Expecting exactly one dictionary file!" << endl;
        usage(argv[0]);
    }

    string dictionaryFilename(argv[argNo]);

    /// Load our dictionary.
    if (!readDictionary(dictionaryFilename, dictSet))
    {
        cerr << "Could not read dictionary file!" << endl;
        exit(1);
    }

    if (debug) ///< Print out debugging information.
    {
        dictSet->debug();
    }

    /// Generate spelling suggestions.
    checkSpelling(dictSet, readSet);

    /// Delete the dynamically typed dictionary and seen word set.
    delete dictSet;
    delete readSet;

    return 0;
}
