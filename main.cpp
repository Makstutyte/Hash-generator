#include <iostream>
#include <bitset>
#include <limits>
#include <string>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <cmath>

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

    for (int i = 0; i < k; i++) {
        c[i] = txt[i];
        std::cout << c[i];
    }

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
   // std::cout << std::endl;
  //  std::cout << "PRIDEDAME VIENETA I GALA" << std::endl;
   // std::cout << dieve_padek << std::endl;

    while (dieve_padek.length() % 512 != 448)
    {
        dieve_padek += '0';
    }

   /* std::cout << "64 BITAI" << std::endl;
    std::cout << std::endl;
    std::cout << dieve_padek << std::endl;*/

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

    int b = (dieve_padek.length() / 512) * (512 / 32);
    std::vector<std::string> masyvas;
    masyvas.reserve(b*32);
    // std::string masyvas[b];
    int p = 0;
    int kiek_cia = 0;

    for (unsigned i = 0; i < dieve_padek.length(); i += 512)
    {
        // b++
        std::cout << dieve_padek.substr(i, 512) << std::endl;
        std::cout << std::endl;
        std::cout << b << std::endl;

        for (unsigned j = 0; j < dieve_padek.length(); j += 32)
        {
            masyvas.push_back(dieve_padek.substr(j, 32));
            std::cout << masyvas.at(p) << std::endl;
            kiek_cia++;
            p++; 
        }
    }
    dieve_padek.erase();

    std::cout << kiek_cia << std::endl;

    int opa = 0;
    for (size_t i = 16; i <= 79; i++)
    {
        opa++;
        std::string& wordA = masyvas[i - 3];
        std::string& wordB = masyvas[i - 8];
        std::string& wordC = masyvas[i - 14];
        std::string& wordD = masyvas[i - 16];
       
        std::string xorA = "";
        std::string xorB = "";
        std::string xorC = "";
        
                for(int j=0; j<32; j++)
                {

                    if(wordA[j]==wordB[j])
                        xorA+="0";
                        else
                            xorA+="1";
                }

                for(int k=0; k<32; k++)
                {

                    if(xorA[k]==wordC[k])
                        xorB+="0";
                        else
                            xorB+="1";
                }

                for(int l=0; l<32; l++)
                {

                    if(xorB[l]==wordD[l])
                        xorC+="0";
                        else
                            xorC+="1";
                }
                /*
                std::string xorA = xoring(wordA, wordB, 32);
                //string c = xoring(a, b, n)
                std::string xorB = xoring(xorA, wordC, 32);
                std::string xorC = xoring(xorB, wordD, 32);
                */
                std::string newWord = StrRotate(xorC, 1);

                masyvas.push_back(newWord);

                std::cout << masyvas.at(i) << std::endl;
    }

    return 0;

}

