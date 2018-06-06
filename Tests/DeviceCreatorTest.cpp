#include "gtest/gtest.h"
#include "pch.h"
#include "DeviceCreatorTest.h"
#include "../TKOM-proj/DeviceCreator.cpp"
#include "../TKOM-proj/Device.cpp"

void DeviceCreatorTest::SetUp()
{
	deviceCreator = std::make_unique<DeviceCreator>();
}

TEST_F(DeviceCreatorTest, testCreateOven)
{
	auto dev = deviceCreator->createDevice("Piec", "1.1.1.1");
	EXPECT_EQ(dev->getIpAddress(), "1.1.1.1");
}

TEST_F(DeviceCreatorTest, testCreateWashingMachine)
{
	auto dev = deviceCreator->createDevice("Pralka", "1.1.1.1");
	EXPECT_EQ(dev->getIpAddress(), "1.1.1.1");
}

TEST_F(DeviceCreatorTest, testCreateBulb)
{
	auto dev = deviceCreator->createDevice("Zarowka", "1.1.1.1");
	EXPECT_EQ(dev->getIpAddress(), "1.1.1.1");
}
