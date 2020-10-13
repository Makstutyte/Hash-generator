# Hash-generator

Hash function version v0.2, 
program written in C++ 

### The written program performs the following actions:
* accepts string input of any length
* performs hashing operation to convert given string input of any length into a fixed length hash

### The program works in the following steps:
* accepts string input of any length
  * the user is given a possibility to choose wether to enter input by hand or to read from a choosen text file 
  * in case of text file the inside content is read line by line
* hash function calculations are performed using 4 default strings (hash calculations are performed by stimulating all 4 default strings) and ASCII code sum of the whole input file
  * all four strings are fixed lenght - 64 symbols
  * one of the provided strings is set to be the hash value
  * the hash value (which is to be the final answer) is runned trough two *for* loops - one of the size is the actuall input lenght, the other of the size of 64 (we are generating hash of the lenght of 64)
  * while running through two *for* loops every yet to be hash element is calculated by performing *addition*, *multiplication* and *exclusive or logical operations*. All of these calculations are then runned through modulus calculation in order to returns the division remainder, which is then written in the appropriate hash position - it is going to be the final hash element
  * the mention step is performed until the specific hash element is equal to one of the 16 hexidecimal values
* the calculated hash value is outputed

#### If the input string is empty:
* hash value is implemented to be empty string, into which calculated values are going to be inserted
* the hash value is runned trough *for* loop - the size of 64 (we are generating hash of the lenght of 64)
* every yet to be hash element is calculated by performing *addition*, *multiplication* and *exclusive or logical operations*
* element is convertet from decimal value to hexidecimal value, which is then written in the appropriate hash position

#### The difference between normal input calculations and empty string calculations are that:
* in the first case main calculations are performed by manipulating different string values
* in the second case main calculations are performed by manipulating different int values

This was done purely for the sake of curiosity, it doesn't improve the performance of the code.

### Goals for the hash function to be:
* Generating fixed lenght hash (no matter the input size)
* Deterministic - for the same input, the output is always the same
* Efficiency - the hash for any input value is calculated quickly
* Irreversible - from the result of the hash function it is practically impossible to reproduce the initial input
* Collision resistance - it is practically impossible to find such two different arguments to get them the same hash
* Any changes in the given inpit string should provide mostly different hash value

### Experimental research-analysis
1. Written program was tested with different input files
  * two files consisting of only one, but different, character
 
| .txt file | Time | Hash |
| --------------- | --------------- | --------------- |
| 1a.txt| 4.30449s | c9fd649a3213d093da8d03dc2acfa8d168ad1733d82d2bdd3e9dce1dcd86dddc |
| 1b.txt | 4.32255s | b02f440b04dd040d2b40268b2bb2b486fb6d02b6df2f62fd60fdfffdd46fddff |


 * two files consisting of many (> 1000) randomly generated characters
 
 | .txt file | Amount of symbols |Time | Hash |
| --------------- |  --------------- |--------------- | --------------- |
| random1.txt| 1001 | 0.068833s | a27fede001205cfa91856a2d45310b188f6696a825240abd3bc5844fa08bb2f9 |
| random2.txt | 1101 | 0.087909s | eb273d45456e0e10bd2b98d32c0d98e07f1fca9e580296f3c5406081f879bd43 |

 * two identical files consisting of many (> 1000) characters, but differ only by one symbol
 
 | .txt file | Amount of symbols |Time | Hash |
| --------------- |  --------------- |--------------- | --------------- |
| 1.txt| 1001 | 0.07191s | f1dbe3ee2090bd6ee4d0a82c6079e4064ef4ed74480d014d85c2dc24fe72e9be |
| 2.txt | 1001 | 0.059357s | 26c652687fd829bcda38c0b14a414eb8f5e55dd1408bfcb167dedad392ffb341 |

* empty file

| .txt file | Time | Hash |
| --------------- | --------------- | --------------- |
| empty.txt| 0.001002s | 7d510ebe41616e981f535148ade413990995629cc812fa062d4a2bf4c91ff0d2 |

2. The above information and examples show that:
* the written program corresponds with the quality that it is capable to hash a string of any given length
* that the output of the hash function is always the result of the same fixed size (64 characters)
* the hash function is deterministic, for the same input - the output is always the same.
3. Hashing file *konstitucija.txt

| .txt file | Time | Hash |
| --------------- | --------------- | --------------- |
| konstitucija.txt | 3.65642s | 185a79c001e69821a118876a9b79eec501f7e2da96d6b6b353e4310de90e171c |
| konstitucija.txt (changes in the end of the file konstitucija.txt by changing two letters into an uppercase ones)| 3.70872s | 2e6dfa1e967393782a889f6e926799c4ea13aed18ed7e6a320d36828efcd45aa |

Hashing file *konstitucija.txt* line by line 
| .txt file | Time |
| --------------- | --------------- |
| konstitucija.txt| 35.8776s |

4. Collision resistsance analysis

| Amount of symbols | Repeats | 
| --------------- | --------------- | 
| 10 | 0 | 
| 100 | 250 | 
| 500 |     |
| 1000 |    |

 ^ generuojant didelius string (nuo 100 elementu) random teksto generavimo funkcija kazkodel pradeda generuoti vienodus tekstus
 
 | Amount of symbols | Repeats | 
| --------------- | --------------- | 
| 5 | 0 | 
| 7 | 0 | 
| 10 | 0 | 
| 15 | 0 |
| 20 | 0 |
| 25 | 0 |
| 30 | 0 |
| 40 | 0 |
| 100 | 250 | 
