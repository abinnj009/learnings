#include <linux/module.h>
#include <linux/netlink.h>
#include <net/sock.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include "kernelutils.h"

static struct sock *nl_sk = NULL;


static void netlink_recv_msg_fn(struct sk_buff *skb_in)
{
	struct nlmsghdr *nlh_recv, *nlh_reply;
	char *user_space_data;
	int user_space_data_len;
	struct sk_buff *skb_out;
	char kernel_reply[256];
	int user_space_process_port_id;
	int res;

	printk(KERN_INFO "%s() invoked", __FUNCTION__);
	nlh_recv = (struct nlmsghdr *)(skb_in->data);
	nlmsg_dump(nlh_recv);

	user_space_process_port_id = nlh_recv->nlmsg_pid;

	printk(KERN_INFO "%s(%d): port id of the sending userspace process
			=%u\n", __FUNCTION__, __LINE__,
			user_space_process_port_id);

	user_space_data = (char *)nlmsg_data(nlh_recv);
	user_space_data_len = skb_in->len;

	printk(KERN_INFO "%s(%d) : msg recvd from user space= %s, skb_in->len = %d, nlh->nlmsg_len = %d\n", 
			__FUNCTION__, __LINE__, user_space_data, user_space_data_len, nlh_recv->nlmsg_len);

	if(nlh_recv->nlmsg_flags & NLM_F_ACK){
		memset(kernel_reply, 0, sizeof(kernel_reply));

		snprintf(kernel_reply, sizeof(kernel_reply),
				"Msg from process %d has been processed
				by kernel", nlh_rec->nlmsg_pid);
		skb_out = nlmsg_new(sizeof(kernel_reply), 0);

		nlh_reply = nlmsg_put(skb_out,
				0,                  /*Sender is kernel, 
						      hence, port-id = 0*/
				nlh_recv->nlmsg_seq, /*reply with same 
						       Sequence no*/
				NLMSG_DONE,          /*Metlink Msg type*/
				sizeof(kernel_reply), /*Payload size*/
				0);

		strncpy(nlmsg_data(nlh_reply), kernel_reply, 
				sizeof(kernel_reply));

		/*Finaly Send the  msg to user space space process*/
		res = nlmsg_unicast(nl_sk, skb_out, user_space_process_port_id);

		if(res < 0){
			printk(KERN_INFO "Error while sending the data 
					back to user-space\n");
			kfree_skb(skb_out); /*free the internal 
					      skb_data also*/
		}
	}

}

static struct netlink_kernel_cfg cfg = {
	.input = netlink_recv_msg_fn,
};

static int __init NetlinkGreetings_init(void){
	printk(KERN_INFO "Hello kernel, I am kernel module 
			Netlinkgreetings\n");
	nl_sk = netlink_kernel_create(&init_net, NETLINK_TEST_PROTOCOL,
			&cfg);
	if(!nl_sk){
		printk(KERN_INFO "KERNEL netlink socket creation for 
				protocol %u failed.\n", 
				NETLINK_TEST_PROTOCOL);
		return -ENOMEM;
	}

	printk(KERN_INFO "Netlink socket created succesfully");
	return 0;
}

static void __exit NetlinkGreetings_exit(void)
{
	printk(KERN_INFO "exiting kernel module netlinkgreetingLKM\n");
	netlink_kernel_release(nl_sk);
	nl_sk = NULL;
}

module_init(NetlinkGreetings_init);
module_exit(NetlinkGreetings_exit);

MODULE_LICENCE("GPL");


