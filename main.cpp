#include <iostream>
#include <limits>
#include <cstring>
#include <string>
#include <bitset>
#include <vector>
#include <cmath>
#include <fstream>
#include <bitset>
#include <stdio.h>
#include <sstream>

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

std::string xoring(std::string a, std::string b, int n)
{
    std::string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
            ans += "0";
        else
            ans += "1";
    }
    return ans;
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

        return len_b;
    }
    else
    {
        for (int i = 0; i < num_zeros; i++)
        {
            b = '0' + b;
        }
    }

    return len_a;
}


std::string andOperationBitwise(std::string s1, std::string s2)
{

    int length = makeEqualLength(s1, s2);
    std::string res = "";

    for (int i = 0; i < length; i++)
    {
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

    return c_str;
}

std::string NOT(std::string b_str)
{
    const size_t N = 32;
    std::bitset<N> b(b_str);
    std::bitset<N> c = ~b;

    std::string c_str = c.to_string();

    return c_str;

}

std::string add(std::string a, std::string b)
{
    std::string result = "";
    int temp = 0;
    int size_a = a.size() - 1;
    int size_b = b.size() - 1;

    while (size_a >= 0 || size_b >= 0 || temp == 1)
    {
        temp += ((size_a >= 0) ? a[size_a] - '0' : 0);
        temp += ((size_b >= 0) ? b[size_b] - '0' : 0);
        result = char(temp % 2 + '0') + result;
        temp /= 2;
        size_a--; size_b--;
    }
    return result;
}

std::string pasistumiam(std::string s)
{
   int length = 32;
    std::string str = s;
    int s1 = s.length() - length;
    str.erase(0, s1);

    return str;
}

std::string bintohex(const std::string& s) 
{
    std::string out;
    for (int i = 0; i < s.size(); i += 4) 
    {
        int8_t n = 0;
        for (int j = i; j < i + 4; ++j) 
        {
            n <<= 1;
            if (s[j] == '1')
                n |= 1;
        }

        if (n <= 9)
            out.push_back('0' + n);
        else
            out.push_back('a' + n - 10);
    }

    return out;
}

int convertToASCII(std::string s)
{
    int a = 0;
    for (int i = 0; i < s.length(); i++)
    {
        a += (int)s[i];
    }
    return a;
}

struct aaaaaaaaaaa
{
    std::vector<std::string> block;
};


int main()
{
    char ir_kasgi_cia_bus;

    std::cout << "ivedam rankyte (r) ar sakitome is failiuko (f)? ";
    std::cin >> ir_kasgi_cia_bus;

    ar_tas_simboliukas(ir_kasgi_cia_bus, 'r', 'f');
     std::string txt;

    if (ir_kasgi_cia_bus == 'r')
    {
            std::cout << "tekstas ";
            std::cin >> txt;
            //txt = "A Test";
    }

    else if(ir_kasgi_cia_bus == 'f')
    {
        std::string fileName;
        std::cout << "File name (format without .txt ending):  ";
        std::cin >> fileName;

        std::ifstream in(fileName);
        std::stringstream a;
        a << in.rdbuf();
        txt = a.str();
        in.close();

    }

    std::vector<std::string> A;
    
    int k = txt.size() + 1;
    char* c = new char[k];

    for (int i = 0; i < k; i++) 
    {
        c[i] = txt[i];
    }

    int kiek= convertToASCII(txt);

    for (int i = 0; i < txt.size(); i++)
    {
        int num = int(c[i]); 
       // kiek += num;
        int bin;
        bin = getBinaryNumber(num);
        std::string str = std::to_string(bin);
        char addtext = '0';
        while (str.size() != 8)
        {
            str = addtext + str;
        }

        A.push_back(str);
    }
   //std::cout << kiek << std::endl;
    
    delete[] c;

    std::string dieve_padek = "";
    char addtext2 = '1';

    for (int i = 0; i < A.size(); i++)
    {
        dieve_padek = dieve_padek + A.at(i);
    }
    int length = dieve_padek.length();

    dieve_padek = dieve_padek + addtext2;

    while (dieve_padek.length() % 512 != 448)
    {
        dieve_padek += '0';
    }

    int dieve;
    dieve = getBinaryNumber(length);

    std::string str2 = std::to_string(dieve);
    char addtext = '0';
    while (str2.size() != 64)
    {
        str2 = addtext + str2;
    }

    dieve_padek = dieve_padek + str2;
 
        int row=dieve_padek.length()/512;
        int col = (dieve_padek.length() / 512) * (512 / 32);

        std::vector<aaaaaaaaaaa> aaaa;

        for (int i = 0; i < (dieve_padek.length() / 512); i++)
        {
            aaaaaaaaaaa tmp;
            for (int j = 0; j < 512; j += 32)
            {
                tmp.block.push_back(dieve_padek.substr(j, 32));
            }
            aaaa.push_back(tmp);
        }

    for (int i = 0; i < (dieve_padek.length() / 512); i++)
    {
        for (size_t j = 16; j <= 79; j++)
        {
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
    }
     
    std::string h0 = "01100111010001010010001100000001";
    std::string h1 = "11101111110011011010101110001001";
    std::string h2 = "10011000101110101101110011111110";
    std::string h3 = "00010000001100100101010001110110";
    std::string h4 = "11000011110100101110000111110000";
    std::string h5 = "";
    std::string h6 = "";
    std::string h7 = "";

    std::string a1 = h0;
    std::string b1 = h1;
    std::string c1 = h2;
    std::string d1 = h3;
    std::string e1 = h4;

    for (int i = 0; i < (dieve_padek.length() / 512); i++)
    {
        for (int j = 0; j < 80; j++)
        {
            std::string f;
            std::string k;

            if (j < 20)
            {
                std::string BandC = andOperationBitwise(b1, c1);
                std::string notB = andOperationBitwise(NOT(b1), d1);
                f = OR(BandC, notB);
                k = xoring(f, BandC, 32);
            }

            else if (j < 40) 
            {
                std::string BxorC = xoring(b1, c1, 32);
                f = xoring(BxorC, d1, 32);
                k = andOperationBitwise(NOT(BxorC), f);
            }

            else if (j < 60) 
            {
                std::string BandC = andOperationBitwise(b1, c1);
                std::string BandD = andOperationBitwise(b1, d1);
                std::string CandD = andOperationBitwise(c1, d1);
                std::string BandCorBandD = OR(BandC, BandD);
                f = OR(BandCorBandD, CandD);
                k = xoring(f, BandD, 32);
            }

            else 
            {
                std::string BxorC = xoring(b1, c1, 32);
                f = xoring(BxorC, d1, 32);
            }

            std::string word = aaaa[i].block[j];
            std::string tempA = add(StrRotate(a1, 5), f);
            std::string tempB = add(tempA, e1);
            std::string tempC = add(tempB, k);
            std::string temp = add(tempC, word);
            std::string temp1 = add(temp, word);
            std::string temp2 = add(temp1, word);

            temp = pasistumiam(temp);
            e1 = d1;
            d1 = c1;
            c1 = StrRotate(b1, 30);
            b1 = a1;
            a1 = temp;
            temp = temp1;
            temp1 = temp2;
            h5 = pasistumiam(add(temp, temp1));
            h6 = pasistumiam(add(temp2, h5));
            h7 = pasistumiam(add(h6, k));
        }

        h0 = pasistumiam(add(h0, a1));
        h1 = pasistumiam(add(h1, b1));
        h2 = pasistumiam(add(h2, c1));
        h3 = pasistumiam(add(h3, d1));
        h4 = pasistumiam(add(h4, e1));
        
    }

    std::string hash = bintohex(h0) + bintohex(h1) + bintohex(h2) + bintohex(h3) + bintohex(h4) + bintohex(h5) + bintohex(h6) + bintohex(h7);

    std::cout << std::endl;
    std::cout << hash << std::endl;

    return 0;

}

