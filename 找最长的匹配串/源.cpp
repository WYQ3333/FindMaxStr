//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//class Solution{
//public:
//	string FindMaxstr(const string& str){
//		if (str.empty()){
//			return "";
//		}
//		vector<string> v;
//		string result = "";
//		int i = 0;
//		int j = 0;
//		for (i = 0; i<str.size(); ++i){
//			j = str.size() - 1;
//			while (j>i){
//				if (str[i] == str[j]){
//					int temp = i;
//					int temp2 = j;
//					while (temp < temp2){
//						if (str[temp] == str[temp2]){
//							result += str[temp];
//							temp++;
//							temp2--;
//						}
//						else{
//							break;
//						}
//					}
//					if (temp == temp2){
//						v.push_back(str);
//					}
//					else{
//						result = "";
//					}
//				}
//				--j;
//			}
//		}
//		string cur = "";
//		for (size_t i = 0; i<v.size(); ++i){
//			if (v[i].size()>cur.size()){
//				cur = v[i];
//			}
//		}
//		result = cur;
//		return result;
//	}
//};
//
//int main(){
//	Solution s;
//	string input;
//	cin >> input;
//	string maxstr = s.FindMaxstr(input);
//	cout << maxstr << endl;
//	system("pause");
//	return 0;
//}

#include<iostream>
using namespace std;
#include<string>
#include<vector>

class Solution{
public:
	string FincMaxStr(const string& str){
		if (str.empty()){
			return "";
		}
		int i = 0;
		int j = 0;
		vector<string> v;
		string result = "";
		if (str.size() == 1){
			result += str[0];
			return result;
		}
		for (i = 0; i<str.size(); ++i){
			j = str.size() - 1;
			while (j>i){
				int left = i;
				int right = j;
				while (left<right&&str[left] == str[right]){
					left++;
					right--;
				}
				if (i<j&&left >= right){
					result = "";
					for (int tem = i; tem <= j; ++tem){
						result += str[tem];
					}
					v.push_back(result);
				}
				--j;
			}
		}
		for (size_t i = 0; i<v.size(); ++i){
			if (v[i].size()>result.size()){
				result = v[i];
			}
		}
		return result;
	}
};

int main(){
	string input;
	cin >> input;
	Solution s;
	string t = s.FincMaxStr(input);
	cout << t<<endl;
	system("pause");
}