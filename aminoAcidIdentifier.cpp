#include <iostream>
#include <string>
#include <vector>

struct CodonEssentialAminoAcids { 
    std::string codon; 
    std::string aminoAcid;
};

// Find and print the amino acid and their given codon 
void countingCodons(const std::string &rnaSeq, const std::vector<CodonEssentialAminoAcids> &codonList) { 
    std::vector<int> counts(codonList.size(), 0); 

    for(size_t i = 0; i + 2 < rnaSeq.length(); i +=3){ 
        std::string codon = rnaSeq.substr(i, 3); 
        for(size_t j = 0; j < codonList.size(); j++) { 
            if(codonList[j].codon == codon) {
                counts[j]++; 
            }
        }
    }

    // Printing the results
    for(size_t i = 0; codonList.size(); ++i) { 
        std::cout << "Amino Acid: " << codonList[i].aminoAcid << " Count: " << counts[i] << std::endl; 
    }
}

int main() { 
    std::string rnaSequence = "AAAAAUUUUGGGGGAAGGGCCCCGGGAAAAAAGGUUUAGGUUAAAUUAAAUUUUAAGGGGUUUAAAUUGUGUGUAUAUAAAAGGAAUUUUCCCCAAAUUCGGCUUAAAA";

    //Vector with all essential amino acids and their associated codons 
    std::vector <CodonEssentialAminoAcids> codonList = { 
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUG", "Leucine"},
        {"CUU", "Leucine"},
        {"CUC", "Leucine"},
        {"CUA", "Leucine"},
        {"CUG", "Leucine"},
        {"AUU", "Isoleucine"},
        {"AUC", "Isoleucine"},
        {"AUA", "Isoleucine"},
        {"AUG", "Methionine (Start)"},
        {"GUU", "Valine"},
        {"GUC", "Valine"},
        {"GUA", "Valine"},
        {"GUG", "Valine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Sering"},
        {"UCG", "Serine"},
        {"CCU", "Proline"},
        {"CCC", "Proline"},
        {"CCA", "Proline"},
        {"CCG", "Proline"},
        {"ACU", "Threonine"},
        {"ACC", "Threonine"},
        {"ACA", "Threonine"},
        {"ACG", "Threonine"},
        {"GCU", "Alanine"},
        {"GCC", "Alanine"},
        {"GCA", "Alanine"},
        {"GCG", "Alanine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UAA", "Stop"},
        {"UAG", "Stop"},
        {"CAU", "Histidine"},
        {"CAC", "Histidine"},
        {"CAA", "Glutamine"},
        {"CAG", "Glutamine"},
        {"AAU", "Asparagine"},
        {"AAC", "Asparagine"},
        {"AAA", "Lysine"},
        {"AAG", "Lysine"},
        {"GAU", "Aspartic Acid"},
        {"GAC", "Aspartic Acid"},
        {"GAA", "Glutamic Acid"},
        {"GAG", "Glutamic Acid"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGU", "Stop"},
        {"UGG", "Tryptophan"},
        {"CGU", "Arginine"},
        {"CGC", "Arginine"},
        {"CGA", "Arginine"},
        {"CGG", "Arginine"},
        {"AGU", "Serine"},
        {"AGC", "Serine"},
        {"AGA", "Serine"},
        {"AGG", "Serine"},
        {"GGU", "Glycine"},
        {"GGC", "Glycine"},
        {"GGA", "Glycine"},
        {"GGG", "Glycine"}
    };

    countingCodons(rnaSequence, codonList); 
    
    return 0; 
}

