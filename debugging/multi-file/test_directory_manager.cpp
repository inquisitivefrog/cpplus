#include <gtest/gtest.h>
#include "DirectoryManager.hpp"
TEST(DirectoryManagerTest, ScanDirectory) {
    DirectoryManager manager("/tmp");
    std::filesystem::create_directory("/tmp/test");
    std::ofstream("/tmp/test/file.txt") << "Test";
    manager.scanDirectory("/tmp/test", "TestThread");
    EXPECT_EQ(manager.getFileCount(), 1);
    EXPECT_EQ(manager.getDirCount(), 0);
    std::filesystem::remove_all("/tmp/test");
}

