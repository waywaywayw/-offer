/*
	书上的方法：从右上角开始向左下搜。
	我的方法：维护一个矩阵：begx,begy, finx, finy. 用二分查找不断finx, finy，
	begx, begy每次+1.
	如果bex>finx || finx > finy 那么没找到.
	时间复杂度logNlogM(n+m)
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 水平方向二分查找,第begx行
    int horiFind(int target, vector<vector<int> > array) {
        int l = begy, r = finy;
        
        while( l<=r ) {
            int mid = l + (r-l)/2;
            if( array[begx][mid]==target ) return mid;
            if( array[begx][mid] < target ) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return l<finy ? l : finy;	// l 指向end的情况(即target比向量中的所有元素都大)
    }
    // 竖直方向二分查找,第begy列
    int vertFind(int target, vector<vector<int> > array) {
        int l = begx, r = finx;
        
        while( l<=r ) {
            int mid = l + (r-l)/2;
            if( array[mid][begy]==target ) return mid;
            if( array[mid][begy] < target ) {
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return l<finx ? l : finx;
    }
    bool Find(int target, vector<vector<int> > array) {
        begx = begy = 0;
        finx = array.size() -1;
        finy = array[0].size() -1;
        if( finx==-1 || finy==-1 ) return false;
        
        while( 1 ) {
            finy = horiFind(target, array);
            if( begx > finx ) return false;
            if( array[begx][finy]==target ) return true;
            begx ++;
            
            finx = vertFind(target, array);
			if( begy > finy ) return false;
            if( array[finx][begy]==target ) return true;
            begy ++;
        }
    }
    
private:
    int begx, begy, finx, finy;
};


int main(int argc, char* argv[]) {
	int target = 7;

	vector<vector<int> > array;
	vector<int> vt;
	vt.push_back(1);
	vt.push_back(2);
	vt.push_back(8);
	vt.push_back(9);
	array.push_back( vt );
	//auto i = lower_bound(array[0].begin(), array[0].end(), 9);
	//cout << *i << endl;
	vt.clear();
	vt.push_back(2);
	vt.push_back(4);
	vt.push_back(9);
	vt.push_back(12);
	array.push_back( vt );

	vt.clear();
	vt.push_back(4);
	vt.push_back(7);
	vt.push_back(10);
	vt.push_back(13);
	array.push_back( vt );

	vt.clear();
	vt.push_back(6);
	vt.push_back(8);
	vt.push_back(11);
	vt.push_back(15);
	array.push_back( vt );
	cout << (new Solution())->Find(target, array) << endl;
	return 0;
}
