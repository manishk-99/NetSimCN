#include "device.h"
#include<iostream>

using namespace std;

Device::Device()
{
    //Constructor
}
void Device::setMACaddress(int MAC)
{
   MACaddress=MAC;
}
void Device::setData(string dat)
{
    data=dat;
}