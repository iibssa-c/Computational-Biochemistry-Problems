#include <iostream>
#include <string>

// Count nucleotides A, T, C, G
void countNucleotides(const std::string &dnaSeq) { 
    int countA, countT, countC, countG; 
    countA = 0;
    countT = 0; 
    countC = 0; 
    countG = 0; 

    for (size_t i = 0; i < dnaSeq.size(); i++) { 
        char nucleotide = dnaSeq[i]; 
        switch (nucleotide) {
            case 'A' : countA++; 
            break;

            case 'T' : countT++; 
            break; 
            
            case 'C' : countC++; 
            break; 

            case 'G' : countG++; 
            break;

            default: 
            break; 
        }
    }
    std::cout << "A: " << countA << "\nT: " << countT << "\nC: " << countC << "\nG: " << countG << std::endl;  
}

int main() { 
    std::string dnaSeq = "AAAAAAAAAAAATTTTTTTTTTTTTTTTTTTTGGGGGGGGGGGCGCGCGGGCGCGGTTTTTTTAAAAAAAAAATTCCCCAAAA"; 
    countNucleotides(dnaSeq); 

    return 0;  
}


