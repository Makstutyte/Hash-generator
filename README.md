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

