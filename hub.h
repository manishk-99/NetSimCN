#ifndef HUB_H
#define HUB_H
#include<string>

using namespace std;

//Creating HUB-Class
class Hub
{
    public:
        Hub();
        string data2;
        int macAdd;
        void store(string dev, string src, int mac);
        void hub2dev(string dev,string src, int macAdd);
};


#endif // HUB_H