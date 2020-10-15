#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <random>
#include <unistd.h>
#include <bitset>

void symbol(char& symbol, char first, char second, char third, char fourth)
{
    while (!(symbol == first || symbol == second || symbol == third || symbol == fourth))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Invalid size entered" <<std::endl;
        std::cout << "Choose between the options  " << first << " or " << second << " or " << third << " or " << fourth << ": ";
        std::cin >> symbol;
    }
}

std::string StrRotate(std::string& s, int nLeft)
{
    int size = s.size();

    nLeft %= size;

    if (nLeft == 0) return s;

    std::string after = s.substr(0, nLeft);
    std::string before = s.substr(nLeft, size - nLeft);

    return before + after;
}

std::string toHex(int num1) 
{
    if (num1 == 0)
        return "0";
    int num = num1;
    std::string s = "";
    while (num) 
    {
        int temp = num % 16;
        if (temp <= 9)
            s += (48 + temp);
        else
            s += (87 + temp);
        num = num / 16;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool is_hex(char text)
{
    if (!((text >= '0' && text <= '9') || (text >= 'a' && text <= 'f')))
    {
        return false;
    }

    return true;
}

class Timer 
{
    private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    public:
    Timer() : start{std::chrono::high_resolution_clock::now()} {}
    void reset() {
    start = std::chrono::high_resolution_clock::now();
    }
    double elapsed() const {
    return std::chrono::duration<double>
    (std::chrono::high_resolution_clock::now() - start).count();
    }
};

std::string hash (std::string& txt)
{
    int lenght  = 64;
    std::string default_str =   "gets is considered unsafeand has been removed from the latest Ca";
    std::string default_str2  = "Animacinis serialas apie geltonaja seimynele is Springfildo - Ho"; 
    std::string default_str3  = "Start by adding these lines of code into HelloWorld.cpp file. Th";
    std::string default_str4  = "78542695qwg15862423 Hash'avimo metu bet koks92104638724822loph64";
                               
    std::string copy1 = StrRotate(default_str, 32);
    std::string copy2 = StrRotate(default_str2, 17);
    std::string copy3 = StrRotate(default_str3, 32);
    std::string copy4 = StrRotate(default_str4, 50);
    std::string hash = default_str;
    

    if (!txt.empty())
    {
        int  sum = 0;
            for (int i = 0; txt[i] != '\0'; i++)
                sum = sum + txt[i];
            
           // std::cout << std::hex << sum << std::endl;

        for (int i = 0; i < txt.length(); i++)
        {
            for (int j = 0; j < lenght; j++)
            {
                int a = 0;
                int b = 1;
                int c = 2;

                if (j < 32)
                { 
                    do
                    {
                        b++;
                        hash[j] = (txt[i] * copy4[j] * default_str2[j] + b * sum + (txt[b * i % 64] * default_str[j]) ^ (txt[b % txt.length()] * sum)) % 128;
                    }while (is_hex(hash[j]) != 1);
                }

                else
                {
                    do
                    {
                        a++;
                        hash[j] = (txt[i] * sum*sum * default_str3[j] * sum + a * sum + (txt[a * i % 64] * default_str4[j] * sum) ^ (txt[a % txt.length()] * (sum*sum*sum))) % 128;
                    }while (is_hex(hash[j]) != 1);
                }
            } //std::cout << hash << std::endl; // line by line file hashing
        }

           // std::cout << std::endl;
          // std::cout << hash << std::endl;
    }

     if (txt.empty())
        {
            int a1 = 0;
            std::string hash = "";
            for (int i = 0; i < 64; i++)
            {
                int newsymb;
                int tmp1;
                int tmp2;
                int tmp3;
                a1++;
                tmp1 = (copy1[i * i % 64] * a1 *  i) ^ (5 * a1 * i);
                tmp2 = tmp1 & copy4[i * 7 % 64];
                tmp3 = (tmp1 * a1) ^ (tmp2 * i) * 3 + (i * a1) & tmp2;
                newsymb = (tmp3 * 4) ^ (default_str3[i] * a1);
                hash += toHex(newsymb);
            }

            hash = hash.substr(3, 64);
           // std::cout << StrRotate(hash, 50) << std::endl;
            
        }
        //std::cout << std::endl;
        
        return hash;
};

std::string TextToBinaryString(std::string words) 
{
    std::string binaryString = "";
    for (char& _char : words) 
    {
        binaryString +=std::bitset<8>(_char).to_string();
    }
    return binaryString;
}

int char_match (std::string str1, std::string str2,  int& stringLength)
{
   unsigned int matches = 0;

   stringLength = (str1.length() > str2.length()) ? str2.length() : str1.length();

   for(unsigned int i = 0; i < stringLength; ++i)
   {
       if(str1[i] == str2[i])
       {
           ++matches;
       }
   }

    return matches;
}

int char_match1 (std::string str1, std::string str2,  int stringLength)
{
   unsigned int matches = 0;

   for(unsigned int i = 0; i < stringLength; ++i)
   {
       if(str1[i] == str2[i])
       {
           ++matches;
       }
   }

    return matches;
}

std::string string_to_hex(const std::string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

std::string rand_str(const int len)
{
    std::string tmp_s;
    static const char alphanum[] =
    "0123456789" 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    srand((unsigned) time(NULL) * getpid());

    for(int i = 0; i< len; ++i)
         tmp_s += alphanum[rand() % (sizeof(alphanum) -1)];
    return tmp_s;
}

std::string HexToBin(char hexdec) 
{ 
    long int i = 0; 
  
    while (hexdec) { 
  
        switch (hexdec) { 
        case '0': 
            return "0000"; 
            break; 
        case '1': 
            return "0001"; 
            break; 
        case '2': 
            return "0010"; 
            break; 
        case '3': 
            return "0011"; 
            break; 
        case '4': 
            return "0100"; 
            break; 
        case '5': 
            return "0101"; 
            break; 
        case '6': 
            return "0110"; 
            break; 
        case '7': 
            return "0111"; 
            break; 
        case '8': 
            return "1000"; 
            break; 
        case '9': 
            return "1001"; 
            break; 
        case 'A': 
        case 'a': 
            return "1010"; 
            break; 
        case 'B': 
        case 'b': 
            return "1011"; 
            break; 
        case 'C': 
        case 'c': 
            return "1100"; 
            break; 
        case 'D': 
        case 'd': 
            return "1101"; 
            break; 
        case 'E': 
        case 'e': 
            return "1110"; 
            break; 
        case 'F': 
        case 'f': 
            return "1111"; 
            break; 
        default: 
            std::cout << "\nInvalid hexadecimal digit ";
        } 
    } 
}

char rand_strCHAR(const int len)
{
    char tmp_s;
    static const char alphanum[] =
    "0123456789" 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

    srand((unsigned) time(NULL) * getpid());

         tmp_s += alphanum[rand() % (sizeof(alphanum) -1)];
    return tmp_s;
}

void collision_test (const int len)
{
  unsigned int repeats = 0; int a=0;
  for (size_t i = 0; i != 25000; ++i)
  {
    std::string t1 = rand_str(len);
    std::string t2 = rand_str(len);
  /*  if(t1!=t2)
    if(t1 == t2)
    {
        do
        {
            t2 = rand_str(len);
        }while(t1==t2);
  //  }*/
        std::string h1 = hash(t1);
        std::string h2 = hash(t2);

        if (h1 == h2)
        {
              repeats++;
        } 

      a++;
 
  }
   std::cout << "length ->  " << len << "|  repeats ->  " << repeats << "|  times runned ->  " << a << std::endl;
}

void collision_test2 (const int len)
{
    int atsBIN =0, atsHEX =0;
    int prasisuko =0;

    int maxBIN=0, minBIN=256;
    int maxHEX=0, minHEX=64;

    double procBIN =0, procHEX =0;
    
    for (int i=0; i<25000; i++)
    { 
            std::string t1 = rand_str(len);
            std::string t2;
            t2 = t1;
            
                do
                {
                    t2[len-1] = rand_strCHAR(1);
                }while(t1[len-1]==t2[len-1]);
            
                std::string h1 = hash(t1);
                std::string h2 = hash(t2);
                
        std::string BIN1, BIN2;
        int kiekBIN = 0, kiekHEX =0;

        for(int j = 0; j < 64; j++)
        {
            BIN1 = HexToBin(h1[j]);
            BIN2 = HexToBin(h2[j]);

            for(int z = 0; z < 4; z++)
            {
                if(BIN1[z] != BIN2[z])
                {
                    kiekBIN++;
                }
            }
        }
        atsBIN += kiekBIN;

        if(kiekBIN > maxBIN)
        {
            maxBIN = kiekBIN;
        } 

        if(kiekBIN < minBIN)
        {
            minBIN = kiekBIN;
        }
        
        for(int j = 0; j < 64; j++)
        {
            if(h1[j] != h2[j])
            {
                kiekHEX++;
            }
        }

        atsHEX += kiekHEX;

        if(kiekHEX > maxHEX)
        {
            maxHEX = kiekHEX;
        }

        if(kiekHEX < minHEX)
        {
            minHEX = kiekHEX;
        }

       prasisuko++;
    } 
    
    procBIN =  atsBIN / prasisuko * 100 / 256;
    procHEX =  atsHEX / prasisuko * 100 / 64;
    
    double MAX_BIN, MIN_BIN, MAX_HEX, MIN_HEX;

    MAX_BIN = maxBIN * 100 / 256;
    MIN_BIN = minBIN * 100 / 256;

    MAX_HEX = maxHEX * 100 / 64;
    MAX_HEX = minHEX * 100 / 64;

    std::cout << std::endl;
    std::cout << "PERCENTAGE AVERAGE BIN  " <<  procBIN  << "%\n";
    std::cout << "PERCENTAGE MAX BIN  " <<  MAX_BIN << "%\n";
    std::cout << "PERCENTAGE MIN BIN  " <<  MIN_BIN << "%\n";
    std::cout << std::endl;
    std::cout << "PERCENTAGE AVERAGE HEX " << procHEX << "%\n";
    std::cout << "PERCENTAGE MAX HEX  " << MAX_HEX << "%\n";
    std::cout << "PERCENTAGE MIN HEX  " <<  MIN_HEX << "%\n";
}

void read(std::string& txt)
{
    char hand_or_file;

    std::cout << "input by hand (h), input by choosen file (f), collision test 1 (c), collision test 2 (t)? ";
    std::cin >> hand_or_file;

    symbol(hand_or_file, 'h', 'f', 'c', 't');
    

    if (hand_or_file == 'h')
    {
        std::cout << "text ";
        std::cin >> txt;
    }

    else if (hand_or_file == 'f')
    {
        std::string fileName;
        std::cout << "File name (format with .txt ending):  ";
        std::cin >> fileName;
        std::ifstream in(fileName);
        std::stringstream a;
        a << in.rdbuf();
        txt = a.str();
       // hash(txt); // line by line file hashing
        in.close();
    }

    else if (hand_or_file == 'c')
    {
        collision_test(10);
       /* collision_test(100);
        collision_test(150);
        collision_test(300);
        collision_test(500);
        collision_test(1000);*/
    }

    
    else if (hand_or_file == 't')
    {
        collision_test2(10);
       /* collision_test2(100);
        collision_test2(500);
        collision_test2(1000);*/
    }
};


int main()
{
    Timer t; // Paleisti
    std::string txt;
    read(txt);
   // std::cout << hash(txt) << std::endl;
   // std::cout <<  t.elapsed() << " s\n";

    return 0;
}
