#include <iostream>
#include <stdlib.h>
#include <ctime>
#include<random>

using namespace std;

class Num
{
    int num, integer_bits; 
    void random()
    {
        // std::random_device rd; // obtain a random number from hardware
        // std::mt19937 gen(rd()); // seed the generator
        // std::uniform_int_distribution<> distr(25, 63);
        // for(int n=0; n<40; ++n)
        // std::cout << distr(gen) << ' ';

    }

    public : Num(int bits)
    {
        integer_bits = bits;
        if(integer_bits<1 || integer_bits>4)
        {
            cout<<"Please re enter integer count";
        }
        else
        {
            num = 4729;

        }
    }

    int Bulls(int user_num)
    {
        int diff, bulls;
        diff = num - user_num;
        bulls = 0;
        while (diff>0) 
        {
            bulls = bulls + (diff%10>0 ? 0 : 1);
            diff = diff/10;
        }
        return bulls;
    }

    int Cows(int user_num)
    {
        int cows,i,j,temp,digit;
        int arr[integer_bits];
        temp = num;
        i=integer_bits-1;
        while(temp>0)
        {
            j = temp % 10;
            arr[i] = j;
            temp = temp / 10;
            --i;
        }
        cows = 0;
        for(i=integer_bits-1;i>=0;--i)
        {
            digit = user_num % 10;
            user_num = user_num / 10;
            for(j=integer_bits-1;j>=0;--j)
            {
                if(i==j)
                {
                    continue;
                }
                else
                {
                    if(digit == arr[j])
                    {
                        cows += 1;
                    }
                }
            }
        }
        return cows;
    }
    ~Num()
    {

    }
    int send()
    {
        return num;
    }
};

int main()
{
    int asa, bull, cow;
    Num number(4);
    cout<<"Enter 4 digit number"<<endl;
    cin>>asa;
    
    while (1)
    {
        
        if(number.send()!=asa)
        {
            bull = number.Bulls(asa);
            cow = number.Cows(asa);
            cout<<"Bulls "<<bull<<" Cows "<<cow<<endl;
            cout<<"Enter a number";
            cin>>asa;
            cout<<endl;
        }
        else
        {
            cout<<"the number was 2375";
            break;
        }
    }
}