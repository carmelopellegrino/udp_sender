#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>

using namespace std;

int main(int argc, char* argv[])
{
  int sockfd,n;
  sockaddr_in servaddr,cliaddr;
  const unsigned int dgram_size = 9216;
  char buffer[dgram_size];

  if (argc != 3)
  {
    cout << "usage: " << argv[0] << " <IP address> <port>\n";
    return 1;
  }

  //  const int send_rate = atoi(argv[3]);
  const int port = atoi(argv[2]);

  sockfd = socket(AF_INET,SOCK_DGRAM,0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr(argv[1]);
  servaddr.sin_port = htons(port);

  while (true)
  {
    cout << "Inserisci un messaggio: ";
    cin >> buffer;
    sendto(sockfd,
        buffer,
        dgram_size,
        0,
        (sockaddr *) &servaddr,
        sizeof(servaddr));
  }
}
