#include <gtest/gtest.h>
#include "../include/feiqiu.h"
#include "../include/feiqiu_types.h"
#include <pcap.h>

TEST(FeiqiuInitTest, SuccessOnZero)
{
	void *handle;
	void *userdata;
	EXPECT_EQ(0, feiqiu_file_proto_init(&handle, userdata));

}

TEST(FeqiuInitTest, ContainDesireValue)
{
	void *handle;
	void *userdata;
	feiqiu_file_proto_init(&handle, userdata);
	EXPECT_STREQ(((feiqiu *)handle)->filepath, "/dev/temp");
}

TEST(FeiqiuDestory, HandleNULL)
{
	void *handle;
	handle = NULL;

	EXPECT_EQ(-1, feiqiu_file_proto_destory(&handle));
}

TEST(FeqiuDestory, HandleNormal)
{
	void *handle;
	handle = (void *)malloc(10);

	EXPECT_EQ(0, feiqiu_file_proto_destory(&handle));
}

TEST(FeqiuProtoRun, OneFilePkt)
{
	char errbuf[PCAP_ERRBUF_SIZE];
	const char *pcap_file = "test_pkt/test0_zero_file.pcap";

	pcap_t *handle = pcap_open_offline(pcap_file, errbuf);

	void *feiqiu_handle;
	void *userdata;
	const char *protodata;    // tcp data
	int len;

	feiqiu_file_proto_init(&feiqiu_handle, userdata);
	
	// pkt preparation
	struct pcap_pkthdr *cap_header = NULL;
	const u_char *packet = NULL;
	pcap_next_ex(handle, &cap_header, &packet);

	//get proto data
	caught_packet(cap_header, packet, &protodata, &len);

	// testing if it contains desire value
	feiqiu_file_proto_run((feiqiu **)&feiqiu_handle, protodata, len);
	EXPECT_EQ(0, ((feiqiu *)feiqiu_handle)->file_size);
}
	
	
int 
main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



