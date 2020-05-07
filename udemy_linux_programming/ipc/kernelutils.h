#ifndef __NL_COMMON__
#define __NL_COMMON__

#include <linux/netlink.h>

#define NLMSG_GREET 20

#define NETLINK_TEST_PROTOCOL 31

static inline char * netlink_get_msg_type(__u16 nlmsg_type)
{
	switch(nlmsg_type){
		case NLMSG_NOOP:
			return "NLMSG_NOOP";
		case NLMSG_ERROR:
			return "NLMSG_NOOP";
		case NLMSG_DONE:
			return "NLMSG_DONE";
		case NLMSG_OVERRUN:
			return "NLMSG_OVERRUN";
		case NLMSG_GREET:
			return "NLMSG_GREET";
		default:
			return "NLMSG_UNKNOWN";
	}
}

static inline void nlmsg_dump(struct nlmsghdr *nlh)
{
	#ifdef __KERNEL__
		printk(KERN_INFO "Dumping Netlink msgs hdr");
	#else
		printf("dumping netlink msgs hdr");
	#endif
	
	#ifdef __KERNEL__
		printk(KERN_INFO "Netlink msg type =%s", 
				netlink_get_msg_type(nlh->nlmsg_type));
	#else
		printf("Netlink msg type=%s", 
				netlink_get_msgtype(nlh->nlmsg_type));
	#endif
	
	#ifdef __KERNEL__
		printk(KERN_INFO "Netlink msg len=%d", nlh->nlmsg_len);
	#else
		printf("netlink msg len=%d", nlh->nlmsg_len);
	#endif
	
	#ifdef __KERNEL__
		printk(KERN_INFO "Netlink msg flags=%d", nlh->nlmsg_flags);
	#else
		printf("Netlink msg flags = %d", nlh->nlmsg_flags);
	#endif
	
	#ifdef __KERNEL__
		printk(KERN_INFO "Netlink msg seq no=%d", nlh->nlmsg_seq);
	#else
		printf("Netlink msg seq no=%d", nlh->nlmsg_seq);
	#endif
	
	#ifdef __KERNEL__
		printk(KERN_INFO "Netlink msg pid=%d", nlh->nlmsg_pid);
	#else
		printf("Netlink msg pid%d", nlh->nlmsg_pid);
	#endif
}

#endif
