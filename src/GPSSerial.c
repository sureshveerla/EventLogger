#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

double convertToDecimal(char *val)
{
    double d = atof(val);
    int deg = (int)(d/100);
    double min = d - (deg*100);
    return deg + (min/60);
}

void utcToIST(char *utc,char *out)
{
    int h,m,s;

    sscanf(utc,"%2d%2d%2d",&h,&m,&s);

    h += 5;
    m += 30;

    if(m>=60)
    {
        h++;
        m-=60;
    }

    if(h>=24)
        h-=24;

    sprintf(out,"%02d:%02d:%02d",h,m,s);
}

int GPSConnect()
{

    int serial = open("/dev/ttyACM0",O_RDONLY);

    if(serial < 0)
    {
        printf("GPS not connected or permission denied\n");
        return 1;
    }

    printf("GPS connected. Waiting for data...\n");

    struct termios tty;
    tcgetattr(serial,&tty);

    cfsetispeed(&tty,B9600);
    cfsetospeed(&tty,B9600);

    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag |= CS8;

    tcsetattr(serial,TCSANOW,&tty);

    char buf[256];
    char line[512]="";

    while(1)
    {
        int n = read(serial,buf,sizeof(buf));

        for(int i=0;i<n;i++)
        {
            if(buf[i]=='\n')
            {
                if(strstr(line,"$GNGGA"))
                {
                    char *token;
                    char *data[20];
                    int index=0;

                    token=strtok(line,",");

                    while(token!=NULL)
                    {
                        data[index++]=token;
                        token=strtok(NULL,",");
                    }

                    if(index>5 && strlen(data[2])>0)
                    {
                        double lat = convertToDecimal(data[2]);
                        double lon = convertToDecimal(data[4]);

                        char utc[10];
                        strncpy(utc,data[1],6);
                        utc[6]='\0';

                        char ist[20];
                        utcToIST(utc,ist);

                        printf("Latitude : %f\n",lat);
                        printf("Longitude: %f\n",lon);
                        printf("UTC Time : %.2s:%.2s:%.2s\n",utc,utc+2,utc+4);
                        printf("IST Time : %s\n",ist);
                        printf("------------------------\n");
                    }
                    else
                    {
                        printf("GPS connected but waiting for satellite fix...\n");
                    }
                }

                strcpy(line,"");
            }
            else
            {
                strncat(line,&buf[i],1);
            }
        }
    }
}
