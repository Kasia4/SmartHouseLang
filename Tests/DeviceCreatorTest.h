#pragma once

#include <memory>
#include <sstream>
#include "../TKOM-proj/DeviceCreator.h"

class DeviceCreatorTest : public ::testing::Test
{
protected:
	virtual void SetUp();
	std::unique_ptr<DeviceCreator> deviceCreator;
};


