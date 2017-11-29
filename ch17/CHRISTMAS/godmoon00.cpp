/*
 *
 * 수행시간: 728ms
 *
 * 첫번째 문제는 sort 시킨다음 같은 값이 연속으로 나오면 count를 증가시키다가 값이 바뀌면 count * (count - 1) /2 를 더하는 식으로 구함
 * 그런데 문제는
 *
 * 4 5
 * 5 5 5 5
 *
 * 같은 입력이 들어오면 4C2 인 6을 출력했음(올바른 답은 10).
 * 알고보니 이렇게 하면 첫번째 상자를 절대 포함하지 않는 거였음.
 * 상자 하나만 선택할수도 있는 경우가 문제였나? 싶었지만 의외로 그런 경우는 문제가 되지 않음.
 * 그래서 종만에서 언급된것 처럼 psum[-1] = 0 을 고려해줌. 내 경우에는 for문을 돌리기 전에 prev = 0 을 해준것과 같음.
 *
 * 두번째 문제는 그리디로 품. 백준에 있는 "회의실 배정" 이라는 문제와 느낌이 비슷했음.
 * H번 부터 T번 까지 고른다고 할 때 항상 T를 제일 작게하는 쌍을 고르는 방식.
 *
 * 간단한 증명)
 * 1번부터 H번 까지는 동일하게 고르고, H 이후부터 T1 까지 고른 A 경우와 T2(T1 < T2) 까지 고른 B 경우에
 * 만약 B 가 A 보다 더 많은 쌍을 만들 수 있다고 가정해보자
 * 문제의 조건에 따라 겹치면 안되기 때문에 A는 그 다음에 고를 때 T1 상자 이후부터, B는 T2 상자 이후부터 고를수 밖에 없음.
 * 그러면 A 는 B 보다 [T1+1, T2] 까지의 상자가 더 있음.
 * 어떤 범위에서 쌍을 만들 수 있는 경우의 수는 항상 0 이상이기 때문에
 * A 가 고를 수 있는 쌍의 수는 B 보다 많거나 같음.
 * 가정에 모순되기 때문에 A 가 항상 B 보다 많거나 같은 쌍을 만들 수 있음이 증명됨
 * 증명을 이렇게 하면 되는건지 모르겠어서..태클환영입니다.
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100000];
int sum[100000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        sum[0] = (a[0] % k);
        for (int i=1; i<n; i++) {
            sum[i] = (sum[i-1] + a[i]) % k;
        }

        bitset<100000> b = 1;
        int ans2 = 0;
        for (int i=0; i<n; i++) {
            if (b[sum[i]]) {
                b = 0;
                ans2++;
            }
            b[sum[i]] = true;
        }

        sort(sum, sum+n);
        int ans = 0, prev = 0, count = 1;
        for (int i=0; i<n; i++) {
            if (sum[i] == prev) count ++;
            else {
                ans = (ans + (long long) count * (count - 1) / 2) % 20091101;
                count = 1;
                prev = sum[i];
            }
        }
        ans = (ans + (long long) count * (count - 1) / 2) % 20091101;
        cout << ans << ' ' << ans2 << '\n';
    }
}
