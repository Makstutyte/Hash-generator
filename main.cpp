#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <chrono>

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

int main()
{
    std::string result;
    Timer t; // Paleisti

    int ilgis  = 64;
    std::string default_str =   "gets is considered unsafeand has been removed from the latest Ca";
    std::string default_str2  = "Animacinis serialas apie geltonaja seimynele is Springfildo - Ho"; 
    std::string default_str3  = "Start by adding these lines of code into HelloWorld.cpp file. Th";
    std::string default_str4  = "7854269854261586242357920045305983218410658942104638724822054564";
                               
    std::string copy1 = StrRotate(default_str, 32);
    std::string copy2 = StrRotate(default_str2, 17);
    std::string copy3 = StrRotate(default_str3, 32);
    std::string copy4 = StrRotate(default_str4, 50);
    std::string hash = default_str;
    

    char ir_kasgi_cia_bus;

    std::cout << "ivedam rankyte (r) ar sakitome is failiuko (f)? ";
    std::cin >> ir_kasgi_cia_bus;

    ar_tas_simboliukas(ir_kasgi_cia_bus, 'r', 'f');
    std::string txt;

    if (ir_kasgi_cia_bus == 'r')
    {
        std::cout << "text ";
        std::cin >> txt;
    }

    else if (ir_kasgi_cia_bus == 'f')
    {
        std::string fileName;
        std::cout << "File name (format with .txt ending):  ";
        std::cin >> fileName;

        std::ifstream in(fileName);
        std::stringstream a;
        a << in.rdbuf();
        txt = a.str();
        in.close();
    }

    if (!txt.empty())
    {
        int  sum = 0;
            for (int i = 0; txt[i] != '\0'; i++)
                sum = sum + txt[i];
            
            std::cout << std::hex << sum << std::endl;
            
        for (int i = 0; i < txt.length(); i++)
        {
            for (int j = 0; j < ilgis; j++)
            {
                int a = 0;
                int b = 1;
                int c = 2;

                if (j < 32)
                { 
                    do
                    {
                        b++;
                        //hash[j] = (txt[i] * copy4[j] * (copy1[j] ^ txt[i]) * default_str2[j] + b + (txt[b * i % ilgis] * txt[j % txt.length()]) ^ (txt[b % txt.length()] * copy1[j])) % 128;
                         hash[j] = (txt[i] * copy4[j] * default_str2[j] + b + (txt[b * i % 64] * default_str[j]) ^ (txt[b % txt.length()] * sum)) % 128;
                    }while (is_hex(hash[j]) != 1);
                }

                else
                {
                    do
                    {
                        a++;
                        //hash[j] = ((txt[i] ^ copy2[j]) * txt[i % txt.length() + a] * copy[j] + txt[i * a % txt.length()] * default_str4[j] + a + (copy2[a * i % ilgis] * default_str4[j]) ^ (txt[a % txt.length()] * default_str3[31])) % 128;
                         hash[j] = ((txt[i] ^ sum) + txt[i * a % txt.length()] * default_str4[j] + a + (copy2[a * i % 64] * sum) ^ (txt[a % txt.length()] * default_str3[j])) % 128;
                    }while (is_hex(hash[j]) != 1);
                }
            }
        }

/*
            int  sum = 0;
            for (int i = 0; txt[i] != '\0'; i++)
                sum = sum + txt[i];
            
            std::cout << std::hex << sum << std::endl;
*/


std::cout << std::endl;
       // std::cout << StrRotate(hash, 50) << std::endl;
     //  random_shuffle(hash.begin(), hash.end());
       std::cout << hash << std::endl;
       std::cout << std::endl;

            for (int j = 0; j < ilgis; j++)
            {
                    do
                    {
                        hash[j] = hash[j] ^ sum ^ sum;
                    }while (is_hex(hash[j]) != 1);
            }
            std::cout << hash << std::endl;
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
            std::cout << StrRotate(hash, 50) << std::endl;
        }
        std::cout << std::endl;
        std::cout <<  t.elapsed() << " s\n";

    return 0;
}
