// Valid-License-Identifier: Apache-2.0

// SPDX-URL: https://spdx.org/licenses/Apache-2.0.html
// Version 2.0, January 2004
// http://www.apache.org/licenses/LICENSE-2.0

// Copyright November 2023 Inha Univ. Open Source Project Team noogabar

/**
 * @brief 채점 서버용 main.cpp
 *
 * 돔저지 채점 서버 제출용 main 함수입니다.
 * 최종 제출시 기타 헤더 파일 및 cpp 파일과 병합하여 제출하도록 합니다.
 *
 */

#include "AVLTreeSet/avl-tree-set.h"

#include <iostream>

using namespace std;

int T, Q, arg;
string cmd;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while (T--) {

    // 채점 서버에선 int형 자료만을 다룹니다.
    Set<int> *set = new AVLTreeSet<int>;
    cin >> Q;
    while (Q--) {
      cin >> cmd;

      //====================일반 기능====================

      /**
       * @brief 1. minimum X
       * 최소 노드의 key 얻은 후 search
       * 찾은 노드의 key와 depth를 차례대로 출력
       */
      if (cmd == "minimum") {
        cin >> arg;

        int key = set->Minimum(arg);
        int depth = set->Find(key);
        cout << key << " " << depth << '\n';
      }

      /**
       * @brief 2. maximum X
       * 최대 노드의 key 얻은 후 search
       * 찾은 노드의 key와 depth를 차례대로 출력
       */
      else if (cmd == "maximum") {
        cin >> arg;

        int key = set->Maximum(arg);
        int depth = set->Find(key);
        cout << key << " " << depth << '\n';
      }

      /**
       * @brief 3. empty
       * Set이 비어있으면 1을 출력하고,
       * 비어있지 않으면 0을 출력
       *
       */
      else if (cmd == "empty") {
        cout << set->Empty() << '\n';
      }

      /**
       * @brief 4. size
       * Set에 저장된 원소의 수를 출력
       */
      else if (cmd == "size") {
        cout << set->Size() << "\n";
      }

      /**
       * @brief 5. find X
       * 노드 x의 depth를 출력
       * 만약 노드 X가 없다면, 0을 출력
       */
      else if (cmd == "find") {
        cin >> arg;
        cout << set->Find(arg) << '\n';
      }

      /**
       * @brief 6. insert X
       * 새로운 노드 x를 삽입하고,
       * 노드 x의 depth를 출력
       */
      else if (cmd == "insert") {
        cin >> arg;
        cout << set->Insert(arg) << '\n';
      }

      //====================고급 기능====================

      /**
       * @brief 7. rank x
       * 노드 X의 depth와 rank를 공백으로 구분하여 출력
       * 만약 노드 x가 없다면, 0을 출력
       * rank는 set에서 x보다 작은 원소의 개수 + 1로 정의함.
       */
      else if (cmd == "rank") {
        cin >> arg;
        int rank = set->Rank(arg);
        if (rank == 0) {
          cout << 0 << '\n';
        } else {
          int depth = set->Find(arg);
          cout << depth << " " << rank << '\n';
        }
      }

      /**
       * @brief 8. erase x
       * 노드 X의 depth 출력하고 해당 노드를 삭제
       * 만약 노드 x가 없다면, 0을 출력
       * x의 두 자식이 모두 내부 노드인 경우 후임자를 이용하여 삭제 수행
       */
      else if (cmd == "erase") {
        cin >> arg;
        cout << set->Erase(arg) << '\n';
      }

      /**
       * @brief 예기치 못한 기타 이상 입력에 대한 처리
       * 실제 채점 서버에선 입력될 일이 없는 케이스입니다.
       */
      else {
        cout << "Error: Wrong input" << '\n';
      }
    }
  }
  return 0;
}