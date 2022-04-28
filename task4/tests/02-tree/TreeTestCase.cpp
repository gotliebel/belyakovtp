//
// Created by akhtyamovpavel on 5/1/20.
//

#include <filesystem>
#include "TreeTestCase.h"
#include "Tree.h"
#include <fstream>

TEST(TreeTestCase, GetTreeAndEqual) {
  ASSERT_THROW(GetTree("123 4", true), std::invalid_argument);
  std::filesystem::create_directory("sandbox");
  std::ofstream("sandbox/file");
  ASSERT_THROW(GetTree("sandbox/file", true), std::invalid_argument);
  std::filesystem::remove_all("sandbox");
  FileNode answer = {"02-tree", true, {{"00-aplusb", true, {{std::string("CMakeLists.txt"), false, {}}, {std::string("TreeTestCase.cpp"), false, {}}, {std::string("TreeTestCase.h"), false, {}}}}}};
  EXPECT_FALSE(GetTree({"../tests"}, true) == answer);
  EXPECT_FALSE(GetTree({"../tests/00-aplusb"}, false) == answer);
}
TEST(TreeTestCase, FilterEmptyNodes) {
  std::filesystem::create_directories("../empty/file");
  FilterEmptyNodes({"empty", true, {{"file", true, {}}}}, "../empty");
  EXPECT_FALSE(std::filesystem::exists("../empty/file"));
  FilterEmptyNodes({"TreeTestCase.cpp", false, {}}, ".");
  EXPECT_FALSE(std::filesystem::is_directory("./TreeTestCase.cpp"));
  std::filesystem::remove_all("../empty");
}