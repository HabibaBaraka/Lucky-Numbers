/*
								  "??? ??? ?????"
			  * ??????? ??????????? ??? ?????? ????? ?????? ??? ???????????? ? ??????? ????? ?????????? ?????????? *
*/
// BIT MASKS
#include<vector>
#include <iostream>
#include<map>
#include<algorithm>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
int numberOfDigit(ll n) {
	int d = 1;
	while (n / 10 > 0) {
		d++;
		n /= 10;
	}
	return d;
}

int main() {
	int t = 1;// cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		int N = numberOfDigit(n);
		bool f = 0;
		ll ans = 0;
		if (N & 1)N++;
		for (int i = 0; i < (1 << N); i++) {// 0 1 2 3
			int num = 0, fact = 1, seven = 0, four = 0;
			//cout << i << " ";

			for (int bit = 0; bit < N; bit++) {
				if ((i >> bit) & 1) {
					num += 7 * fact;
					seven++;
					//cout << num << " ";
				}
				else {
					num += 4 * fact; four++;
					//cout << num << " ";
				}
				fact *= 10;
			}



			if (num >= n && seven == four) {
				f = 1;
				ans = num;
				break;
			}
		}
		if (f) {
			cout << ans;
		}
		else {

			if ((N + 1) & 1) {
				N += 2;
			}
			else N++;
			for (int i = 0; i < (1 << N); i++) {// 0 1 2 3
				int num = 0, fact = 1, seven = 0, four = 0;
				//cout << i << " ";

				for (int bit = 0; bit < N; bit++) {
					if ((i >> bit) & 1) {
						num += 7 * fact;
						seven++;
						//cout << num << " ";
					}
					else {
						num += 4 * fact; four++;
						//cout << num << " ";
					}
					fact *= 10;
				}



				if (num >= n && seven == four) {
					f = 1;
					ans = num;
					break;
				}
			}
			cout << ans;
			
		}
	}
	
}