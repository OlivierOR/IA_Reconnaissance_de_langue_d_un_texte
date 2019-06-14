#include <vector>
#include <fstream>
#include <iostream>
#include <ctype.h>
void error(const char* p, const char* p2 = "")
{
std::cerr << p << ' ' << p2 << std::endl;
std::exit(1);
}
void generate_frequencies(const char *filename,
float *frequencies)
{
std::ifstream infile(filename);
if(!infile)
error("Cannot open input file", filename);
std::vector<unsigned int> letter_count(26, 0);
unsigned int num_characters = 0;
char c; char alphabet = 'A';
while(infile.get(c)){
c = tolower(c);
if(c >= 'a' && c <= 'z'){
letter_count[c - 'a']++;
num_characters++;
}

}
std::cout << "Nombre de lettres total :"<< num_characters << '\n';

if(!infile.eof()) error("Something strange happened");
for(unsigned int i = 0; i != 26; i++){
frequencies[i] = letter_count[i]/(double)num_characters;

std::cout << "Nombre de la lettre " << alphabet << " :" << letter_count[i] << '\n';
alphabet++;
}

}
int main(int argc, char* argv[])
{
if(argc != 2) error("Remember to specify an input file");
float frequencies[26];
generate_frequencies(argv[1], frequencies);
std::cout << "Fréquence de chaque lettre pour le nombre total de lettres du texte" << '\n';
for(unsigned int i = 0; i != 26; i++){
std::cout << frequencies[i] << ' ';
}

std::cout << std::endl;

return 0;
}
