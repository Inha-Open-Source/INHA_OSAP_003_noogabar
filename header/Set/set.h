// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

#ifndef SET_H
#define SET_H

template <typename T> class Set {
public:
  /**
   * @brief Construct a new Set object
   * size 멤버는 Set class에서 관리
   */
  Set() : size_(0) {}

  /**
   * @brief arg값을 key로 갖는 노드를 root로 갖는 sub-tree에서의 최소 key 노드의
   * "key" 반환
   *
   * @param arg : sub-tree의 root 노드의 key
   * @return int : 최소 key 노드의 key
   */
  virtual T Maximum(T arg) = 0;

  /**
   * @brief arg값을 key로 갖는 노드를 root로 갖는 sub-tree에서의 최대 key 노드의
   * "key" 반환
   *
   * @param arg : sub-tree의 root 노드의 key
   * @return int : 최대 key 노드의 key
   */
  virtual T Minimum(T arg) = 0;

  /**
   * @brief Set이 비어있는지 아닌지 확인
   *
   * @return true : Set의 원소 개수 = 0
   * @return false : Set의 원소 개수 > 0
   */
  virtual bool Empty() = 0;

  /**
   * @brief Set의 원소 개수 반환
   *
   * @return int : Set의 원소의 개수
   */
  virtual int Size() = 0;

  /**
   * @brief Set에 존재하는 arg값을 key로 갖는 노드의 depth 반환
   *
   * @param arg : 찾는 노드의 key
   * @return int : 해당 노드의 depth
   */
  virtual int Find(T arg) = 0;

  /**
   * @brief 신규 노드 생성하여 삽입
   *
   * @param arg : 삽입할 노드의 key값
   * @return int : 삽입된 위치에서의 depth
   */
  virtual int Insert(T arg) = 0;

  /**
   * @brief 특정 노드의 rank 계산 함수
   *
   * @param arg : 계산할 노드의 key값
   * @return int : 해당 노드의 rank (없으면 0)
   */
  virtual int Rank(T arg) = 0;

  /**
   * @brief 특정 노드 삭제
   *
   * @param arg : 삭제할 노드의 key값
   * @return int : 삭제하기 전 해당 노드의 depth (없으면 0)
   */
  virtual int Erase(T arg) = 0;

  	//디버깅용 함수
	virtual void debug() = 0;		//AVLTreeSet에서 오버라이딩
	virtual void debugRoot() = 0;	//TreeSet에서 오버라이딩
	virtual void debugBFS() = 0;	//AVLTreeSet에서 오버라이딩

  // size는 set에서 처리하고 getter도 짧은 함수이므로 헤더에서 구현했습니다
  int get_size() { return size_; }
  void IncreaseSize() { size_++; }
  void DecreaseSize() {
    if (size_ > 0)
      size_--;
  }

private:
  unsigned int size_; // Set의 크기
};

#endif
