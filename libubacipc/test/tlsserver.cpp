#include <ubacipc/TLSServer.h>
#include <ubacipc/TLSClient.h>
#include <ubacipc/EventFax.h>
#include <ubacipc/Thread.h>

#include <sstream>
#include <string>
#include <iostream>


using namespace std;

EventFax fax;

class MyTLSClient :
        public TLSClient,
        public virtual TCPClient
{
        public:
                MyTLSClient(int fd, SSL_CTX *ctx) : TLSClient(fd, ctx), TCPClient(fd)
                {
                }
                //receiving the request from the client
		void receive_data(void *data , size_t len )
		{
			cout << " Request accepted from the client" << endl;

			cout << (char *) data << endl;

			//sending response to the client
 
			string sRes = "Response from the server" ;
			int len1 = sRes.length();
			this -> sendData( sRes);
		}
};

class MyTLSServer : 
	public TLSServer,
       	public virtual TCPServer
{

	public :

	  MyTLSServer(int iPort, string sCertificate, string sKey, string sKeyPassphrase)
            : TLSServer(iPort, sCertificate, sKey, sKeyPassphrase),TCPServer(iPort)
                {
			
                }
       
	    void createNewClient(int fd ) {

                      //  cout << " creating client " << endl;
                        MyTLSClient *tlsClient = new MyTLSClient(fd, this -> ssl_context);

		    if (tlsClient->isSslAcceptSuccessful()){          
                            fax.addTCPClient(tlsClient);
			    cout << " Client is connected " << endl;
	              }
	    }

};


int main(int argc, char *argv[])
{
	int port;
    string sCertificate(argv[1]); // certificate file
    string sKey(argv[2]); // key file
    string sKeyPassphrase = " "; 
    cout<<"\n Enter the port :  ";
    cin>>port;
    MyTLSServer *server = new MyTLSServer(port, sCertificate, sKey, sKeyPassphrase);
    fax.addTCPServer( server );
    fax.run();
    cout << " initiated " << endl;
    return 0;
}

