#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>

void main()
{

	struct ifreq ifr;
	char *if_name="eth0";
	//strncpy(ifr.ifr_name, "eth0", IFNAMSIZ-1);


	size_t if_name_len=strlen(if_name);
	if (if_name_len<sizeof(ifr.ifr_name)) {
		memcpy(ifr.ifr_name,if_name,if_name_len);
		ifr.ifr_name[if_name_len]=0;
	} else {
		printf("interface name is too long");
	}
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if (fd==-1) {
		printf("%s",strerror(errno));
	}
	if (ioctl(fd,SIOCGIFADDR,&ifr)==-1) {
		int temp_errno=errno;
		close(fd);
		printf("%s",strerror(temp_errno));
	}
	close(fd);
	struct sockaddr_in* ipaddr = (struct sockaddr_in*)&ifr.ifr_addr;
	printf("IP address: %s\n",inet_ntoa(ipaddr->sin_addr));

}
