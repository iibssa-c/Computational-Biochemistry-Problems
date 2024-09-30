// What is Smith-Waterman algorithm?
// It is a dynamic programming algorithm that is used for local sequence alignment. By comparing DNA, RNA, or protein sequences 
// and identify regions of similarity it optimzes a scoreing matrix that can be used to visualize the alignment.

// What is a scoring matrix?
// A scoring matrix is a table that shows the degree of similarity between each pair of symbols or characters in two sequences.
// It is used to compare DNA, RNA, or protein sequences and identify regions of similarity.

// What is a traceback?
// A traceback is a process of backtracking through a scoring matrix to identify the best local alignment between two sequences.
// It is used to visualize the alignment and to identify the regions of similarity between two sequences.

// Local Alignment:
// The algorithm focuses on matching sequences that show the highest similarity b/t two sequences. Ideal for finding regions of high local similarity in an otherwise diverse sequence.

// Scoring System:
// The scoring matrix will match positive points for similar characters and negative points for different characters and gaps (insertions/deletions).

// Dynamic Programming:
// A matrix is built where each cell (i,j) will represenbt the most optimal alignment score b/t the first i bases of sequence A and the first j bases of sequence B.
// The score is calculated using a scoring system and a gap penalty.

// Gap Penalty:
// A gap penalty is a negative value assigned to gaps in the alignment. It is used to penalize gaps in the alignment and to prevent the algorithm from creating long gaps.

// Algorithm Steps:

// Initialization - Create a scoring matrix with H dimensions (m+1, n+1) for sequences A of length m and seqeunce B of length n. Cells of the first row and column are set to 0.
    // Fill the Matrix - For each cell (i,j) calculate the scoring using:
    // Value from diagonal (match/mismatch): H(i-1, j-1) + score(A[i], B[j])
    // Value from the left (gap in sequence B): H(i, j-1) - gap penalty
    // Value from above (gap in sequence A): H(i-1,j)-gap penalty
    // Zero to allow for local alignement to start fresh
// Traceback - Start at the highest value in the matrix and backtrack to find the best local alignment.
// Visualization - The resulting matrix can be visualized to show the best local alignment between two sequences.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

// Define the scoring system
const int matchScore = 1; 
const int mismatchScore = -1; 
const int gapPenalty = -1;

// Initialize the scoring matrix
std::vector<std::vector<int>> initializeScoringMatrix(const std::string& seqA, const std::string& seqB){
    int m = seqA.length(); 
    int n = seqB.length(); 

    // Create 2D vector with m+1 rows and n+1 columns
    std::vector<std::vector<int>> scoringMatrix(m+1, std::vector<int>(n+1, 0));
    
    // Fill first row and column to 0
    for (int i = 1; i <= m; i++) { 
        scoringMatrix[i][0] = 0; 
    }
    for (int j = 1; j <= n; j++) { 
        scoringMatrix[0][j] = 0; 
    }
    return scoringMatrix; 
}

// Fill scoring matrix
std::tuple<std::vector<std::vector<int>>, std::string, std::string> fillScoringMatrixWithAlignment(const std::string& seqA, const std::string& seqB){
    std::vector<std::vector<int>> scoringMatrix = initializeScoringMatrix(seqA, seqB);
    int m = seqA.length();
    int n = seqB.length(); 

    std::string alignmentA = ""; 
    std::string alignmentB = "";

    int maxScore = 0; 
    int maxX = 0; 
    int maxY = 0;

    for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++){ 
            int match = scoringMatrix[i-1][j-1] + (seqA[i-1] == seqB[j-1] ? matchScore : mismatchScore);
            int gapSeqA = scoringMatrix[i-1][j] + gapPenalty;
            int gapSeqB= scoringMatrix[i][j-1] + gapPenalty;
            scoringMatrix[i][j] = std::max({0, match, gapSeqA, gapSeqB});
        }
    }

    // Find max score in matrix 
    for (int i = 0; i <= m; i++){ 
        for (int j = 0; j <= n; j++){ 
            if (scoringMatrix[i][j] > maxScore){ 
                maxScore = scoringMatrix[i][j]; 
                maxX = i; 
                maxY = j; 
            }
        }
    }

    // Traceback and get alignment 
    while(maxX > 0 && maxY > 0){ 
        if (seqA[maxX-1] == seqB[maxY -1]){
            alignmentA = seqA[maxX-1] + alignmentA;
            alignmentB = seqB[maxY-1] + alignmentB;
            maxX--;
            maxY--;
        } else if (scoringMatrix[maxX-1][maxY] > scoringMatrix[maxX][maxY-1]){ 
            alignmentA = seqA[maxX-1] + alignmentA; 
            alignmentB = '-' + alignmentB; 
            maxX--;
            maxY--; 
        } else{ 
            alignmentA = '-' + alignmentA;
            alignmentB = seqB[maxY-1] + alignmentB; 
            maxY--;
        }

    }
    return std::make_tuple(scoringMatrix, alignmentA, alignmentB);
}

// Visualize the scoring matrix
void visualizeScoringMatrix(const std::vector<std::vector<int>>& scoringMatrix){ 
    int m = scoringMatrix.size();
    int n = scoringMatrix[0].size(); 

    for (int i = 0; i < m; i++){ 
        for (int j = 0; j < n; j++){ 
            std::cout << scoringMatrix[i][j] << " ";
        }
        std::cout << std::endl; 
    }
}

// Main function 
int main(){ 
    std::string seqA = "ACACATACAGGCCCCCCCGGAATTATATTAAATTGGGCCCTTTA"; 
    std::string seqB = "AGACATACACCCGGGAAAATTTCCCGGGAGGGCCTTAATGACCG"; 

    auto [filledMatrix, alignmentA, alignmentB] = fillScoringMatrixWithAlignment(seqA, seqB);

    std::cout << "Sequence A: " << alignmentA << std::endl;
    std::cout << "Sequence B: " << alignmentB << std::endl;

    std::cout << "\nScoring Matrix:\n";
    visualizeScoringMatrix(filledMatrix); 

    return 0;
}





