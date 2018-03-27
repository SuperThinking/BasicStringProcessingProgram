#include<iostream>
#include<boost/algorithm/string.hpp>
#include<vector>
#include<map>
using namespace std;
#define loop(i, b, a) for(int i=b; i<a; i++)

vector<string> StrtoArr(string s)
{
	vector<string> ar;
	boost::split(ar, s, [](char c){return c == ' ';});
	return ar;
}

vector<int> Dict_Encode(string input)
{
	vector<string> strVect = StrtoArr(input);
	//val stores the Encoding
	vector<int> val;
	//dict is the Dictionary of Strings
	map<string, int> dict;
	map<string, int>::iterator it;
	int count = 0;
	loop(i, 0, strVect.size())
	{
		if(dict.find(strVect[i])==dict.end())
		{
			dict[strVect[i]] = count;
			val.push_back(count);
			count++;
		}
		else
		{
			it = dict.find(strVect[i]);
			val.push_back(it->second);
		}
	}

	return val;
}

vector<vector<int>> Hot_Encode(string input)
{
	vector<string> strVect = StrtoArr(input);
	vector<vector<int>> val;
	map<string, int> dict;
	loop(i, 0, strVect.size())
	{
		if(dict.find(strVect[i])==dict.end())
		{
			vector<int> sub_val;
			loop(i1, 0, strVect.size())
			{
				if(strVect[i].compare(strVect[i1])==0)
				{
					sub_val.push_back(1);
				}
				else
				{
					sub_val.push_back(0);
				}
			}
			val.push_back(sub_val);
			dict[strVect[i]] = 1;
		}
	}

	return val;
}

int main()
{
	string input = "hello world hello everyone";
	
	//Dict Encoding
	vector<int> dict_enc = Dict_Encode(input);
	cout<<"[";
	loop(i, 0, dict_enc.size()){cout<<dict_enc[i];}
	cout<<"]"<<endl<<endl;

	//One-Hot Dictionary Encoding
	vector<vector<int>> h_dict_enc = Hot_Encode(input);
	cout<<"[";
	loop(i, 0, h_dict_enc.size())
	{
		cout<<"[";
		loop(j, 0, h_dict_enc[i].size())
		{
			cout<<(h_dict_enc[i])[j];
		}
		cout<<"]";
		cout<<endl;
	}
	cout<<"]";
}
