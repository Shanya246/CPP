#include<ubacipc/MultiCastClient.h>
#include<iostream>
#include<ubacipc/TCPClient.h>
using namespace std;

class Broadcast  : public MultiCastClient
{
        public :
                string ip;
                int port;

                Broadcast(string ip,int port):MultiCastClient(ip,port)
                {
                }
                void receive_data(void *data,size_t len)
                {
                        cout<<"\n Size of packet : " <<len;
                }
};

int main()
{
        string ip;
        int port;
        cout<<"\n Enter the ip address  :" ;
        cin>>ip;
        cout<<"\n Enter the port number  : ";
        cin>>port;
        MultiCastClient  *br = new Broadcast(ip,port);
        br->start();
        return 0;
}
