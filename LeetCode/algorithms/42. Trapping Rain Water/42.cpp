// Example program
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void showdq(deque<pii> &dq, int ans) {
    printf("ans: %d\tdq: ",ans);
    for (auto it = dq.begin(); it != dq.end(); it++)
        printf("(%d,%d) ",it->first,it->second);
    printf("\n");
}

int trap(vector<int>& height) {
    int ans = 0;
    deque<pii> dq;
    
    for (int i = 0; i < height.size(); i++) {
      if (dq.empty() or dq.front().first > height[i]) {
        dq.push_front({height[i],i});
        
        showdq(dq,ans);
        continue;
      }
      
      while (!dq.empty() and dq.front().first <= height[i]) {
        pii f = dq.front(); 

        if (height[i] > dq.back().first) {
          ans += (dq.back().first - f.first)*(f.second - dq.back().second);
        } else {
          if (height[i] == f.first)
            ans += (i-f.second);
          else
            ans += (height[i] - f.first)*(i-f.second);
        }
        
        dq.pop_front();
      }
      
      dq.push_front({height[i],i});
      showdq(dq,ans);
    }
    
    return ans;
}

int main() {
    vector<int> input({0,1,0,2,1,0,0,1,3,2,1,2,1});

    cout << trap(input) << endl;

    return 0;
}
