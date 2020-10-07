#include <iostream>
#include <bitset>
#include <limits>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <cmath>
#include <bitset>

void ar_tas_simboliukas(char& simbolis, char pirmas, char antras)
{
    while (!(simbolis == pirmas || simbolis == antras))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ivestas netinkamas dydis" << std::endl;
        std::cout << "Pasirinkite viena is variantu arba " << pirmas << " arba " << antras << ": ";
        std::cin >> simbolis;
    }
}

int getBinaryNumber(int num)
{
    if (num == 0)
        return 0;
    else
        return (num % 2 + 10 * getBinaryNumber(num / 2));
}

// Function to find the  
// XOR of the two Binary Strings 
std::string xoring(std::string a, std::string b, int n)
{
    std::string ans = "";

    // Loop to iterate over the 
    // Binary Strings 
    for (int i = 0; i < n; i++)
    {
        // If the Character matches 
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
}

// In-place rotates s towards left by d
void leftrotate(std::string& s, int d)
{
    reverse(s.begin(), s.begin() + d);
    reverse(s.begin() + d, s.end());
    reverse(s.begin(), s.end());
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

int makeEqualLength(std::string& a, std::string& b)
{
    int len_a = a.length();
    int len_b = b.length();

    int num_zeros = abs(len_a - len_b);

    if (len_a < len_b)
    {
        for (int i = 0; i < num_zeros; i++)
        {
            a = '0' + a;
        }
        // Return len_b which is highest. 
        // No need to proceed further! 
        return len_b;
    }
    else
    {
        for (int i = 0; i < num_zeros; i++)
        {
            b = '0' + b;
        }
    }
    // Return len_a which is greater or  
    // equal to len_b 
    return len_a;
}


std::string andOperationBitwise(std::string s1, std::string s2)
{
    // Make both strings of same length with the  
    // maximum length of s1 & s2. 
    int length = makeEqualLength(s1, s2);

    // Initialize res as NULL string 
    std::string res = "";

    // We start from left to right as we have  
    // made both strings of same length.  
    for (int i = 0; i < length; i++)
    {
        // Convert s1[i] and s2[i] to int and perform  
        // bitwise AND operation, append to "res" string 
        res = res + (char)((s1[i] - '0' & s2[i] - '0') + '0');
    }
    return res;
}

std::string OR(std::string a_str, std::string b_str)
{
    const size_t N = 32;

    std::bitset<N> a(a_str), b(b_str);
    std::bitset<N> c = a | b;


    std::string c_str = c.to_string();
    // cout << c;
    return c_str;
}

std::string NOT(std::string b_str)
{
    const size_t N = 32;
    std::bitset<N> b(b_str);
    std::bitset<N> c = ~b;

    std::string c_str = c.to_string();
    //cout << c_str;
    return c_str;

}

struct aaaaaaaaaaa
{
    std::vector<std::string> block;
};


int main()
{
    /*
    char ir_kasgi_cia_bus;

    std::cout << "ivedam rankyte (r) ar sakitome is failiuko (f)? ";
    std::cin >> ir_kasgi_cia_bus;

    ar_tas_simboliukas(ir_kasgi_cia_bus, 'r', 'f');
    */

    std::string txt;
    std::vector<std::string> A;

    std::cout << "tekstas ";
    //std::cin >> txt;
    txt = "A Test";
    
    int k = txt.size() + 1;

    char* c = new char[k];

    //std::cout << "kitas perkelimas i charrrrrrrrr " << std::endl;
    for (int i = 0; i < k; i++) {
        c[i] = txt[i];
        std::cout << c[i];
    }//std::cout << "kitas perkelimas i charrrrrrrrr " << std::endl;

    std::cout << c << '\n';

    for (int i = 0; i < txt.size(); i++)
    {
        std::cout << int(c[i]) << std::endl;
        int num = int(c[i]);
        int bin;
        bin = getBinaryNumber(num);
        std::cout << "Binary of the number: " << bin << std::endl;
        std::string str = std::to_string(bin);
        char addtext = '0';
        while (str.size() != 8)
        {
            str = addtext + str;
        }

        A.push_back(str);
    }

    delete[] c;

    std::string dieve_padek = "";
    char addtext2 = '1';

    std::cout << "VEKTORIUS" << std::endl;
    for (int i = 0; i < A.size(); i++)
    {
        std::cout << A.at(i) << ' ';
        dieve_padek = dieve_padek + A.at(i);
    }
    int length = dieve_padek.length();

    dieve_padek = dieve_padek + addtext2;
    std::cout << std::endl;
    std::cout << "PRIDEDAME VIENETA I GALA" << std::endl;
    std::cout << dieve_padek << std::endl;

    while (dieve_padek.length() % 512 != 448)
    {
        dieve_padek += '0';
    }

    std::cout << "64 BITAI" << std::endl;
    std::cout << std::endl;
    std::cout << dieve_padek << std::endl;

    //  eight bit ascii code array

    std::cout << std::endl;
    std::cout << length << std::endl;
    int dieve;
    dieve = getBinaryNumber(length);
    std::cout << dieve << std::endl;

    std::string str2 = std::to_string(dieve);
    char addtext = '0';
    while (str2.size() != 64)
    {
        str2 = addtext + str2;
    }

    std::cout << std::endl;
    std::cout << str2 << std::endl;
    //------------------------------------------
    std::cout << str2.length() << std::endl;
    //------------------------------------------
    dieve_padek = dieve_padek + str2;
    std::cout << std::endl;
    std::cout << dieve_padek << std::endl;
    std::cout << dieve_padek.length() << std::endl;
 
        int row=dieve_padek.length()/512;
        int col = (dieve_padek.length() / 512) * (512 / 32);

        std::vector<aaaaaaaaaaa> aaaa;
        int s = dieve_padek.length() / 512;
         int kiek_cia=0;
        for (int i = 0; i < s; i++)
        {
            aaaaaaaaaaa tmp;
            for (int j = 0; j < 512; j += 32)
            {
                kiek_cia++;
                tmp.block.push_back(dieve_padek.substr(j, 32));
            }
            aaaa.push_back(tmp);
            std::cout << aaaa[0].block[0]<<std::endl;
            std::cout << aaaa[0].block[1] << std::endl;
            std::cout << aaaa[0].block[2] << std::endl;
        }
        
        std::cout <<kiek_cia<< std::endl;

    int opa = 0;
    for (int i = 0; i < s; i++)
    {
        for (size_t j = 16; j <= 79; j++)
        {
            opa++;
            std::string& wordA = aaaa[i].block[j - 3];
            std::string& wordB = aaaa[i].block[j - 8];
            std::string& wordC = aaaa[i].block[j - 14];
            std::string& wordD = aaaa[i].block[j - 16];
            
                    std::string xorA = xoring(wordA, wordB, 32);
                    std::string xorB = xoring(xorA, wordC, 32);
                    std::string xorC = xoring(xorB, wordD, 32);

            std::string newWord = StrRotate(xorC, 1);

            aaaa[i].block.push_back(newWord);
        }

        std::cout << aaaa[0].block[79] << std::endl;
    }
  //  std::cout << "kitas perkelimas i charrrrrrrrr " << std::endl;
    std::cout << aaaa[0].block[79].size() << std::endl;

    std::string h0 = "01100111010001010010001100000001";
    std::string h1 = "11101111110011011010101110001001";
    std::string h2 = "10011000101110101101110011111110";
    std::string h3 = "00010000001100100101010001110110";
    std::string h4 = "11000011110100101110000111110000";

    std::string a1 = h0;
    std::string b1 = h1;
    std::string c1 = h2;
    std::string d1 = h3;
    std::string e1 = h4;

    //žžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžž
    /*
    for (int i = 0; i < ; i++)
    {
        for (int j = 0; j < 80; j++)
        {
            std::string f;
            std::string k;

            if (j < 20)
            {
                std::string BandC = andOperationBitwise(b1, c1);
                std::string notB = andOperationBitwise(NOT(b1), d1);;
                f = OR(BandC, notB);
                k = "01011010100000100111100110011001";
            }

            else if (j < 40) 
            {
                std::string BxorC = xoring(b1, c1, 32);
                f = xoring(BxorC, d1, 32);
                k = "01101110110110011110101110100001";
            }

            else if (j < 60) 
            {
                std::string BandC = andOperationBitwise(b1, c1);
                std::string BandD = andOperationBitwise(b1, d1);
                std::string CandD = andOperationBitwise(c1, d1);
                std::string BandCorBandD = OR(BandC, BandD);
                f = OR(BandCorBandD, CandD);
                k = "10001111000110111011110011011100";
            }

            else 
            {
                std::string BxorC = xoring(b1, c1, 32);
                f = xoring(BxorC, d1, 32);
                k = "11001010011000101100000111010110";
            }

            std::string word = words80[i][j];
            std::string tempA = utils.binaryAddition(StrRotate(a1, 5), f);
            std::string tempB = utils.binaryAddition(tempA, e1);
            std::string tempC = utils.binaryAddition(tempB, k);
            std::string temp = utils.binaryAddition(tempC, word);

            temp = utils.truncate(temp, 32);
            e1 = d1;
            d1 = c1;
            c1 = StrRotate(b1, 30);
            b1 = a1;
            a1 = temp;

        }
    }*/
    //žžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžžž


    return 0;

}

