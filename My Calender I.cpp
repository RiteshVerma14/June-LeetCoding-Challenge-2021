#include<bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        //vector<int> vec;
    }
    unordered_map<int, int>b;
    bool book(int start, int end) {
        for(auto& [s2, e2] : b) 
            if( !(start >= e2 || s2 >= end) ) 
			    return false; 
        b[start] =  end;
        return true;
    }
};

