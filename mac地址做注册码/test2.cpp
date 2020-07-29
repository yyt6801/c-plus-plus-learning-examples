int get_mac_addr(int* pintrface,char *str_mac_addr)
{
int fd, retn = 0;
int intrface; /* int intrface */
struct ifreq buf[MAXINTERFACES];
struct arpreq arp;
struct ifconf ifc;

char mac_addr_max[MAC_ADDR_LEN];
char mac_addr_tmp[MAC_ADDR_LEN];

if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0) 
{
memset(mac_addr_max,0,sizeof(mac_addr_max));
memset(mac_addr_tmp,0,sizeof(mac_addr_tmp));
ifc.ifc_len = sizeof buf;
ifc.ifc_buf = (caddr_t) buf;
if (!ioctl(fd, SIOCGIFCONF, (char *) &ifc)) 
{
intrface = ifc.ifc_len / sizeof (struct ifreq);
*pintrface = intrface;
dprintf(("interface num is intrface=%d\n\n",intrface));
while (intrface-- > 0)
{
dprintf (("net device %s\n", buf[intrface].ifr_name));
arp.arp_pa.sa_family = AF_INET;
arp.arp_ha.sa_family = AF_INET;
((struct sockaddr_in*)&arp.arp_pa)->sin_addr.s_addr =
((struct sockaddr_in*)(&buf[intrface].ifr_addr))->sin_addr.s_addr;
if (!(ioctl (fd, SIOCGARP, (char *) &arp)))
{
memset(mac_addr_tmp,0,sizeof(mac_addr_tmp));
sprintf(mac_addr_tmp,"%02x%02x%02x%02x%02x%02x",
(unsigned char)arp.arp_ha.sa_data[0],
(unsigned char)arp.arp_ha.sa_data[1],
(unsigned char)arp.arp_ha.sa_data[2],
(unsigned char)arp.arp_ha.sa_data[3],
(unsigned char)arp.arp_ha.sa_data[4],
(unsigned char)arp.arp_ha.sa_data[5]);

if( strcmp(mac_addr_max,mac_addr_tmp)<0 )
{
memset(mac_addr_max,0,sizeof(mac_addr_max));
strcpy(mac_addr_max,mac_addr_tmp);
}
}//End of if(!(ioctl(fd,SIOCGARP,(char*) &arp)))
else 
{
dprintf (("cpm: ioctl device %s\n", buf[intrface].ifr_name));
}
}//End of while (intrface-- > 0)
}//End of if (!ioctl (fd, SIOCGIFCONF, (char *) &ifc)) 
else
{
//perror ("cpm: ioctl");
}

}//End of if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0) 
else
{
//perror ("cpm: socket");
}
close (fd);

strcpy(str_mac_addr,mac_addr_max);
return retn;
}