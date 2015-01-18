#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <errno.h>
#include <arpa/inet.h>

enum
{
	log_month=0,
	log_day,
	log_time,
	log_host,
	log_pri,
	log_pro,
	log_msg
};

void Search_line_in_File(char *fname, char *str, char *getName)
{
	FILE *fp;
	char temp[512] = "";
	char get_line[512] = "";

	if((fp = fopen(fname, "r")) == NULL){
		//return NULL;
	}
	while(fgets(temp, 512, fp) != NULL){
		if((strstr(temp, str)) != NULL){
			break;
		}
	}
	if(fp)
		fclose(fp);

	strncpy(get_line, temp, sizeof(get_line));

	//char eNBname[64];
	int length = strlen(get_line) -28 -1;
	memcpy(getName, &get_line[28], length);
	getName[length-1] = '\0';
	//return eNBname;
}
char *GetIP()
{
	struct ifreq ifr;
	char *if_name="eth0";
	char *ip=NULL;

	size_t if_name_len=strlen(if_name);
	if (if_name_len<sizeof(ifr.ifr_name)) {
		memcpy(ifr.ifr_name,if_name,if_name_len);
		ifr.ifr_name[if_name_len]=0;
	} else {
		printf("interface name is too long");
	}
	int fd=socket(AF_INET,SOCK_DGRAM,0);
	if (fd==-1) {
		//printf("%s",strerror(errno));
	}
	if (ioctl(fd,SIOCGIFADDR,&ifr)==-1) {
		int temp_errno=errno;
		close(fd);
		//printf("%s",strerror(temp_errno));
	}
	close(fd);
	struct sockaddr_in* ipaddr = (struct sockaddr_in*)&ifr.ifr_addr;
	ip = inet_ntoa(ipaddr->sin_addr);
	return ip;
}


int Get_Words(const char sentence[ ])
{
	int counted = 0; // result

	// state:
	const char* it = sentence;
	int inword = 0;

	do switch(*it) {
		case '\0':
		case ' ': case '\t': case '\n': case '\r': // TODO others?
			if (inword) { inword = 0; counted++; }
			break;
		default: inword = 1;
	} while(*it++);

	return counted;
}
void split_str_to_array(char strr[],char **dest) {
	char **res = NULL;
	char * p = strtok(strr, " ");
	int n_spaces = 0;

	while (p) {
		res = realloc(res, sizeof(char*) * ++n_spaces);

		if (res == NULL)
			exit(-1); 

		res[n_spaces - 1] = p;

		p = strtok(NULL, " ");
	}
	res = realloc(res, sizeof(char*) * (n_spaces + 1));
	res[n_spaces] = 0;
	
	int idx = 0;
	for(idx=0; idx< n_spaces; idx++)
	{
		int width = strlen(res[idx]) + 1;
		dest[idx] = malloc(width);
		memcpy(dest[idx], res[idx], width);
	}

	free(res);
}

void main() {
	char *startup_cfg_path = "startup.cfg";
	char *find_in_starup_cfg = "szenbname";
	char *ip = NULL, eNB_name[64] = "";
	char origin_str[] = "<13>Jan 2 00:00:47 LSM user.notice root: 1234";
	char new_printbuf[512];
	int n_segs = Get_Words(origin_str);
	char **split_array = malloc(n_segs * sizeof(char*));

	split_str_to_array(origin_str, split_array);

	Search_line_in_File(startup_cfg_path, find_in_starup_cfg, eNB_name);
	//eNB_name = Search_line_in_File(startup_cfg_path, find_in_starup_cfg);
	ip = GetIP();
	//snprintf(new_printbuf, sizeof(new_printbuf), "%s %s %s %s %s Type %s",
	//		split_array[log_month], split_array[log_day], split_array[log_time],
	//		ip, eNB_name, split_array[log_msg]);
	//printf("%s\n", new_printbuf);
	
	printf("%s\n", eNB_name);
	
	int idx = 0;
	for(idx = 0; idx < n_segs; idx++)
	{
		//printf("split_array[%d] = %s\n", idx, split_array[idx]);
	}
	free(split_array);
	
}
