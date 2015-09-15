/* ----------------------------------------------------------------------------
 * Copyright &copy; 2015 Duy Nguyen <andy21996@fullerton.edu>
 * Released under the [MIT License] (http://opensource.org/licenses/MIT)
 * ------------------------------------------------------------------------- */

/**
 * A program to read unsigned integers from a text file and separate them into
 * two files, one for primes, another for composites.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <climits>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;

int findMax(ifstream& input)
{
    int num = 0,
        max = INT_MIN;
    while (input >> num)
    {
        if (num > max)
            max = num;
    }
    return max;
}
    
void openInFile (ifstream& ss, string fileName)
{
    ss.open(fileName);
}

void openOutFile (ofstream& ss, string fileName)
{
    ss.open(fileName);
}

bool isPrime (int num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else 
    {
        int i = 2;
        bool cont = true;
        
        do
        {
            if (num % i == 0)
                cont = false;
            else
                i++;
        } while ((i < num/2) && (cont));
        
        if (!cont)
            return false;
        else
            return true;
    }
}

void outPrime(ifstream& input, ostream& out)
{
    int num = 0;
    while (input >> num)
        if (isPrime(num))
            out << num << endl;
}

void outComposite(ifstream& input, ostream& out)
{
    int num = 0;
    while (input >> num)
        if (!isPrime(num))
            out << num << endl;
}

int main()
{
    //Max integer in file
    ifstream openFile;
    openFile.open("input.txt");
    cout << "The max integer is: " << findMax(openFile) << endl;
    openFile.close();
    
    //Prime number file
    ofstream outPrimeS;
    ifstream inPrimeS;
    openInFile(inPrimeS, "input.txt");
    openOutFile(outPrimeS, "prime.txt");
    outPrime(inPrimeS, outPrimeS);
    
    //Composite number file
    ofstream outCompositeS;
    ifstream inCompositeS;
    openInFile(inCompositeS, "input.txt");
    openOutFile(outCompositeS, "composite.txt");
    outComposite(inCompositeS, outCompositeS);
    
    return 0;
}

