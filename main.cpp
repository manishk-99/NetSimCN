#include<bits/stdc++.h>
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

//Naming Devices and Hub
Device dev1,dev2,dev3,dev4,dev5;
Hub hb1;

void deviceInfo() {
  //here, I am initializing Devices.
  dev1.setData("0");
  dev2.setData("0");
  dev3.setData("0");
  dev4.setData("0");
  dev5.setData("0");
  dev1.setMACaddress(00-15-9-2-99-3);
  dev2.setMACaddress(00-15-8-3-99-6);
  dev3.setMACaddress(00-15-7-4-99-9);
  dev4.setMACaddress(00-15-6-5-99-2);
  dev5.setMACaddress(00-15-5-6-99-4);
}

//HUB2DEVICE-Connection
void Hub::hub2dev(string data2,string sourceDevice, int macAdd)
{
	if(dev1.MACaddress==macAdd && dev1.data==data2 && sourceDevice!="dev1") {
    cout<<" dev1 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev1") {
      cout<<" Data doesn't belong to  dev1"<<endl;
    }
  }
	if(dev2.MACaddress==macAdd && dev2.data==data2 && sourceDevice!="dev2") {
    cout<<" dev2 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev2") {
      cout<<" Data doesn't belong to dev2"<<endl;
    }
  }
	if(dev3.MACaddress==macAdd && dev3.data==data2 && sourceDevice!="dev3") {
    cout<<" dev3 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev3") {
      cout<<" Data doesn't belong to dev3"<<endl;
    }
  }
	if(dev4.MACaddress==macAdd && dev4.data==data2 && sourceDevice!="dev4") {
    cout<<" dev4 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev4") {
      cout<<" Data doesn't belong to dev4"<<endl;
    }
  }
	if(dev5.MACaddress==macAdd && dev5.data==data2 && sourceDevice!="dev5") {
    cout<<" dev5 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev5") {
      cout<<" Data doesn't belong to dev5"<<endl;
    }
  }
	cout<<endl;
}

//MainFunction
int main() {
  int c1, c2;
  string SD_Data;
  string sourceDevice, destinationDevice;
  cout<<"Choose your Choice? :"<<endl;
  cout<<"1: PhysicalLayer  2: DataLinkLayer " <<endl;
  cin>>c1;
  switch(c1) {
    case 1: {
      //This case is of PhysicalLayer
      deviceInfo();
      cout<<"Devices we have: dev1, dev2, dev3, dev4, dev5"<<endl;
      cout<<"Choose SourceDevice: "<<endl;
      cin>>sourceDevice;//Taking sourceDevice as Input
      //sourceDevice-Validation
      if(sourceDevice!="dev1" && sourceDevice!="dev2" && sourceDevice!="dev3" && sourceDevice!="dev4" && sourceDevice!="dev5") {
        cout<<"Invalid SourceDevice "<<endl;
        break;
      }

      cout<<"Choose DestinationDevice: "<<endl;
      cin>>destinationDevice;//Taking DestinationDevice as Input
      //destinationDevice-Validation
      if(destinationDevice!="dev1" && destinationDevice!="dev2" && destinationDevice!="dev3" && destinationDevice!="dev4" && destinationDevice!="dev5") {
        cout<<"Invalid destinationDevice "<<endl;
        break;
      }

      cout<<"SourceDevice Data Input for transmission: "<<endl;
      cin>>SD_Data;//Taking sourceDeviceData as Input
      //sourceDeviceData Validation
      for(int i=0;i<SD_Data.size();i++) {
        if(SD_Data[i]!='0' && SD_Data[i]!='1') {
          cout<<"Invalid sourceDeviceData "<<endl;
          break;
        }
      }

      //assigning sourceDeviceData to sourceDevice
      if(sourceDevice=="dev1") {
        dev1.setData(SD_Data);
      }
      if(sourceDevice=="dev2") {
        dev2.setData(SD_Data);
      }
      if(sourceDevice=="dev3") {
        dev3.setData(SD_Data);
      }
      if(sourceDevice=="dev4") {
        dev4.setData(SD_Data);
      }
      if(sourceDevice=="dev5") {
        dev5.setData(SD_Data);
      }

      //DevicesData in the initialState
		cout<<" DevicesData before Transmission: "<<endl;
    cout<<"dev1 data before Transmission:    "<<dev1.data<<endl;
		cout<<"dev2 data before Transmission:    "<<dev2.data<<endl;
		cout<<"dev3 data before Transmission:    "<<dev3.data<<endl;
		cout<<"dev4 data before Transmission:    "<<dev4.data<<endl;
		cout<<"dev5 data before Transmission:    "<<dev5.data<<endl; 

    //Choose for DEDICATED-NETWORK-CONNECTION OR STAR-TOPOLOGY-CONNECTION
    cout<<"Choose your Choice: "<<endl;
    cout<<"1: StarTopologyConnection 2: DedicatedNetworkConnection "<<endl;
    cin>>c2;
      switch(c2) {
        case 1: {
          //STAR-TOPOLOGY-CONNECTION
          if(destinationDevice=="dev1")
          {
            dev1.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev1.MACaddress);
          }
          if(destinationDevice=="dev2")
          {
            dev2.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev2.MACaddress);
          }
	        if(destinationDevice=="dev3")
    	    {
	        	dev3.setData(SD_Data);
        		hb1.store(SD_Data, sourceDevice, dev3.MACaddress);
          }
          if(destinationDevice=="dev4")
          {
            dev4.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev4.MACaddress);
          }
          if(destinationDevice=="dev5")
          {
            dev5.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev5.MACaddress);
          }
          break;
        }
        case 2: {
          //DEDICATED-NETWORK-CONNECTION
          if(destinationDevice=="dev1"||destinationDevice=="dev2"||destinationDevice=="dev3"||destinationDevice=="dev4"||destinationDevice=="dev5")
        {

            //sourceDevice-transfer
            if(sourceDevice=="dev1")
            {
                    dev1.setData("0");
            }
            if(sourceDevice=="dev2")
            {
                    dev2.setData("0");
            }
            if(sourceDevice=="dev3")
            {
                    dev3.setData("0");
            }
            if(sourceDevice=="dev4")
            {
                    dev4.setData("0");
            }
            if(sourceDevice=="dev5")
            {
                    dev5.setData("0");
            }

            //DEDICATED-CONNECTION
            if(destinationDevice=="dev1")
            {
              dev1.setData(SD_Data);
            }
            if(destinationDevice=="dev2")
            {
              dev2.setData(SD_Data);
            }
            if(destinationDevice=="dev3")
            {
              dev3.setData(SD_Data);
            }
            if(destinationDevice=="dev4")
            {
              dev4.setData(SD_Data);
            }
            if(destinationDevice=="dev5")
            {
              dev5.setData(SD_Data);
            }
            cout<<" DevicesData after Transmission: "<<endl;
            cout<<"dev1 data after Transmission:    "<<dev1.data<<endl;
            cout<<"dev2 data after Transmission:    "<<dev2.data<<endl;
            cout<<"dev3 data after Transmission:    "<<dev3.data<<endl;
            cout<<"dev4 data after Transmission:    "<<dev4.data<<endl;
            cout<<"dev5 data after Transmission:    "<<dev5.data<<endl;      	
          }
          break;
        }
        default: {
          cout<<"Invalid Choice :( "<<endl;
        }
      }
      break;
    }
  }
  return 0;
}