#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ubacutils/IFHelper.h>
#include <ubacipc/EventFax.h>
#include <ubacipc/TCPServer.h>
#include <ubacipc/TLSServer.h>
#include <ubacipc/TLSClient.h>

using namespace UBACIPC;

EventFax fax;

class MyTLSClient :
    public TLSClient,
        public virtual TCPClient
{
        public:
                MyTLSClient(string ip, int port)
            : TLSClient(ip, port), TCPClient(ip, port)
		{
                }
                // receiving response from the server
                void receive_data(void *ptr, size_t len)
		{
			cout << " response from server " << endl;
		        cout <<  " length " << len << endl;
			cout << (char *) ptr << endl;
		}
		
		//printing the certificates 
		void printCertificates(){

                       cout << "Received certificate :" << endl;
                       this -> show_certificates();

                }
};

int main(int argc, char *argv[])
{
	int port;
	cout<<"\n Enter the port  : " ;
	cin>>port;

     MyTLSClient *client = new MyTLSClient("localhost", port);

     string req = "Request... " ;  

     if ( client->isSslAcceptSuccessful() ) {
               fax.addTCPClient(client);
	       cout << "Client is connected with server " << endl;
     
      // printing the received certificates 
      client -> printCertificates() ;
       // sending the request 
       client -> sendData(req);

       fax.run();
       }
 
     return 0;
 }




