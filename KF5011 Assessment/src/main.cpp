#include <mbed.h>
#include <rtos.h>
#include <EthernetInterface.h>
#include <mbed_events.h>
#include <string>

Thread serverComms;
Thread lcdUpdate;
Thread scanHardware;
Thread dashboardComms;
EthernetInterface ethernet;
UDPSocket udp;
char ipOut [80];
int portServ ;
int portDash;

char altitude [20];
char feul [20];
char flying [20];
char crashed [20];
char orientation [20];
char velocityX [20];
char velocityY [20];



int send(char *message, size_t s, SocketAddress dest)
{
  nsapi_size_or_error_t r = udp.sendto(dest,message, s);
  return r;
}

void updateDashboard(void)
{
  SocketAddress dashboard(ipOut,portDash);
  while(1)
  {
    char buffer[1024];
    char line[80];
    sprintf(line, "velocityX:%s\n", velocityX);
    strcat(buffer, line);
    sprintf(line, "velocityY:%s\n", velocityY);
    strcat(buffer, line);
    sprintf(line, "orientation:%s\n", orientation);
    strcat(buffer, line);
    sprintf(line, "crashed:%s\n", crashed);
    strcat(buffer, line);
    sprintf(line, "flying:%s\n", flying);
    strcat(buffer, line);
    sprintf(line, "feul:%s\n", feul);
    strcat(buffer, line);
    sprintf(line, "altitude:%s", altitude);

    printf(buffer);
    send(buffer, strlen(buffer), dashboard);
    wait(1);
  }
}

void communicateServ(void)
{

SocketAddress server(ipOut, portServ);
  while(1)
  {
    char buffer[1024];
    SocketAddress source;
    int len = udp.recvfrom(&source,buffer,
                                   sizeof(buffer));
    buffer[len] = '\0';

    char * pch;

    pch = strtok(buffer, ":\n");

    while(pch != NULL)
    {
      printf("%s\n", pch);
    }



    buffer[0] = '\0';

  }
}



int main()
{

  printf("Enter IP Address: \n");
  scanf("%s", ipOut);
  printf("Enter Dashboard Port: \n");
  scanf("%d", &portDash);

  printf("Enter Server port: \n");
  scanf("%d", &portServ);
  SocketAddress server(ipOut, portServ);


  ethernet.connect();
  const char *ip = ethernet.get_ip_address();
  printf("IP Address is: %s\n", ip ? ip : "No IP" );
  udp.open(&ethernet);

  serverComms.start(communicateServ);
  printf("ServComms: Server Communications Started\n");
  dashboardComms.start(updateDashboard);
  printf("DashboardComms: Dashboard Communications Started\n");

  const char text[] = "command:!\nthrottle:100\nroll:+0.5";
  char buffer[1024];
  sprintf(buffer, text);
  send(buffer, strlen(buffer), server);

  while(1)
  {

  }
}
