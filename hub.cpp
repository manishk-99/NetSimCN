#include "hub.h"
#include<iostream>

using namespace std;

Hub::Hub()
{
    macAdd = 0;
    data2 = "0";
}

void Hub::store(string SD_Data, string sourceDevice, int devMACaddress)
{
  data2 = SD_Data;
	macAdd = devMACaddress;
	hub2dev(data2, sourceDevice, macAdd);
}