// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar
#include "AVLTreeSet/avl-tree-set.h"

#include <iostream>
#include <stdexcept>

#include <gtest/gtest.h>

//========== Test Fixture를 사용한 Test - Minimum & Maximum Test ==========
class MinMaxTestFixture : public ::testing::Test {
public:
  MinMaxTestFixture();
  virtual ~MinMaxTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  Set<int> *set_;
};

// Fixture 생성자
MinMaxTestFixture::MinMaxTestFixture() { std::cout << "Constructor called\n"; }

// Fixture 소멸자
MinMaxTestFixture::~MinMaxTestFixture() { std::cout << "Destructor called\n"; }

// SetUp - Minimum과 Maximum 테스트 시작 전 set에 적절한 원소들을 삽입하는 함수
void MinMaxTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  set_ = new AVLTreeSet<int>;

  // 테스트 전 1, 5, 3, 9, 4를 차례로 set에 삽입
  set_->Insert(1);
  set_->Insert(5);
  set_->Insert(3);
  set_->Insert(9);
  set_->Insert(4);
}

// TearDown - Minimum과 Maximum 테스트 종료 후 set을 삭제하는 함수
void MinMaxTestFixture::TearDown() {
  std::cout << "TearDown called\n";
  delete set_;
}

// Minumum Tests
TEST_F(MinMaxTestFixture, TestMin) {
  // key가 5, 3인 노드가 root인 서브 트리의 leftmost 노드의 key 값의 기대값은
  // 각각 4, 1
  // key가 1, 9, 4인 노드는 leaf 노드이므로 기댓값은 자기자신의 key 값
  EXPECT_EQ(1, set_->Minimum(1));
  EXPECT_EQ(4, set_->Minimum(5));
  EXPECT_EQ(1, set_->Minimum(3));
  EXPECT_EQ(9, set_->Minimum(9));
  EXPECT_EQ(4, set_->Minimum(4));
  // tree에 없는 노드를 입력받을 때 프로그램이 종료되기를 기대
  EXPECT_DEATH(set_->Minimum(10), "");
}

// Maximum Tests
TEST_F(MinMaxTestFixture, TestMax) {
  // key가 5, 3ㄹ인 노드가 root인 서브 트리의 rightmost 노드의 key 값의 기대값은
  // 9
  // key가 1, 9, 4인 노드는 leaf 노드이므로 기댓값은 자기자신의 key 값
  EXPECT_EQ(1, set_->Maximum(1));
  EXPECT_EQ(9, set_->Maximum(5));
  EXPECT_EQ(9, set_->Maximum(3));
  EXPECT_EQ(9, set_->Maximum(9));
  EXPECT_EQ(4, set_->Maximum(4));
  // tree에 없는 노드를 입력받을 때 프로그램이 종료되기를 기대
  EXPECT_DEATH(set_->Maximum(10), "");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
