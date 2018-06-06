#include <gtest/gtest.h>
#include "../include/feiqiu.h"
#include "../include/feiqiu_types.h"

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

	

int 
main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}



