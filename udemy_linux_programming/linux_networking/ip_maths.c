#include <stdio.h>
#include <string.h>
#include <math.h>
#include <arpa/inet.h>
#include <memory.h>

#define COMPLEMENT(num) (num = num ^ 0xFFFFFFFF)
#define SET_BIT(n, pos) (n = n | 1 <<pos)
#define UNSET_BIT(n, pos) (n &=  ((1 << pos) ^ 0xFFFFFFFF))

#define PREFIX_LEN 15 /*max length in string 255.255.255.255*/
#define MAX_MASK_LEN 32;

static unsigned int get_mask_value_in_integer_format(char mask_value)
{
	unsigned int mask = 0xFFFFFFFF;
	char n_trail_bits = MAX_MASK_LEN - mask_value;
	int i = 0;
	for(; i< n_trail_bits; i++){
		UNSET_BIT(mask, i);
	}
	return mask;
}

void get_broadcast_address(char *ip_addr, char mask,
		char *output_buffer)
{
	unsigned int ip_addr_integer = 0;
	inet_pton(AF_INET, ip_addr, &ip_addr_integer);
	ip_addr_integer = htonl(ip_addr_integer);

	unsigned int mask_integer_format = get_mask_value_in_integer_format
						(mask);
	COMPLEMENT(mask_integer_format);
	unsigned int broadcast_addr = ip_addr_integer | mask_integer_format;
	broadcast_addr = htonl(broadcast_addr);
	inet_ntop(AF_INET, &broadcast_addr, output_buffer, PREFIX_LEN + 1);
	output_buffer[PREFIX_LEN] = '\0';
}


int main(int argc, char **argv)
{

	printf("Testing Q1\n");
	char ip_address[PREFIX_LEN +1 ],
		output_buffer[PREFIX_LEN + 1];
	memset(ip_address, 0, PREFIX_LEN + 1);
	memcpy(ip_address, "192.168.2.10", strlen("192.168.2.10"));
	ip_address[strlen(ip_address)] = '\0';
	char mask = 24;
	memset(output_buffer, 0, PREFIX_LEN + 1);
	get_broadcast_address(ip_address, mask, output_buffer);
	printf("Broadcast address = %s\n", output_buffer);
	printf("Testing Q1 Done.\n");

}

