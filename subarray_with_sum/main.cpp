#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Result {
	int beg;
	int end;
};


Result sub_with_sum(vector<int> vec, int sum_target){
	Result res = {0,0};
	if(vec.size() == 0 )
		return res;
	int sum =vec.at(0);

	while(res.beg < vec.size()){
		if(sum < sum_target) {
		    if(res.end != vec.size()-1)
		    	break;
			++res.end;
			sum += vec.at(res.end);
		}else if (sum > sum_target) {
			sum -= vec.at(res.beg);
			++res.beg;
		} else if (sum == sum_target){
			res.beg += 1;
			res.end += 1;
			return res;
		}
	}
	res.beg = -1;
	res.end = -1;
	return res;
}

int main() {
    vector<int> vec = {1,1,1,7,1};
    Result res = sub_with_sum(vec,7);
    cout<< res.beg << " " << res.end << "\n";
	return 0;
}