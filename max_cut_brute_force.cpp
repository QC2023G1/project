#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    int w[n][n];
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j) w[i][j] = 0;
    for (int i=0; i<n; ++i) {
        int x = 0;
        int y = 0;
        for (int j=0; j<n; ++j) {
            cin >> x >> y;
            if ((x==0)&&(y==0)) break;
            else {
                w[x-1][y-1] = 1;
                w[y-1][x-1] = 1;
            }
        }
        if ((x==0)&&(y==0)) break;
    }
    cout << "The weight matrix is:\n";
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) cout << w[i][j];
        cout << "\n";
    }
    int ans[n];
    int loop[n];
    for (int i=0; i<n; ++i) {
        ans[i]=0;
        loop[i]=0;
    }
    int max = 0;
    for (int i=0; i<pow(2,n); ++i) {
        int temp = 0;
        for (int x=0; x<n; ++x) {
            for (int y=0; y<n; ++y) {
                if (loop[x]!=loop[y]) temp+=w[x][y];
                else continue;
            }
        }
        if (temp>max) {
            max = temp;
            for (int j=0; j<n; ++j) ans[j]=loop[j];
        }
        int carry = 0;
        if (loop[n-1]==0) {
            loop[n-1]++;
            continue;
        }
        if (loop[n-1]==1) {
            loop[n-1]--;
            carry++;
        }
        for (int j=n-2; j>=0; --j) {
            if (carry==0) break;
            if (carry==1) {
                if (loop[j]==0) {
                    loop[j]++;
                    carry--;
                    break;
                }
                if (loop[j]==1) {
                    loop[j]--;
                }
            }
        }
    }
    cout << "x:\n";
    for (int i=0; i<n; ++i) cout << ans[i];
    cout << "\n";
    cout << "Max cut is:" << max/2;
}
