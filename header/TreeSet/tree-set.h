// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef TREE_SET_H
#define TREE_SET_H

#include "INHA_OSAP_003_noogabar/header/Node/node.h"
#include "INHA_OSAP_003_noogabar/header/Set/set.h"

/**
 * @brief Set과 AVLTreeSet 사이의 중간 클래스
 *
 * Tree를 이용한 Set구현과
 * Hash 알고리즘을 이용한 Set 구현을 구분 짓기 위해
 * 만들어둔 매개 클래스입니다.
 *
 * Tree를 이용한 구현은 모두 이 클래스를 상속받으므로
 * root 노드를 여기서 추가합니다.
 *
 */
template <typename T> class TreeSet : public Set<T> {
public:
  TreeSet() : root_(nullptr) {}
  Node<T> *get_root() const {
    return root_;
  } // 짧은 getter이므로 그냥 여기서 구현했습니다.
  void set_root(Node<T> *node) { root_ = node; }

  //디버깅
  void debugRoot() override { cout << "root: " << root_->get_key() << "\n"; }

private:
  Node<T> *root_;
};

#endif