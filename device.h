#ifndef DEVICE_H
#define DEVICE_H
#include<string>

using namespace std;

//Creating DEVICE-class
class Device
{
    public:
        Device();
        string data;
        int MACaddress;
        void setMACaddress(int);
        void setData(string);
};

#endif // DEVICE_H