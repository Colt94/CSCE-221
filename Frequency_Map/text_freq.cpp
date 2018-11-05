#include "text_freq.h"
#include "my_map.h"
#include "key_value.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

string read_file(string file_name)
{
	ifstream inFile;
	inFile.open(file_name);
	if (inFile)
	{
		stringstream strStream;
		strStream << inFile.rdbuf();
		string contents = strStream.str();
		string removedPunc = remove_punctuation(contents);
		inFile.close();
		return removedPunc;
	}
	else
	{
		cout << "File was not found..\n";
		return "";
	}
    //FINISH THIS FUNCTION
    //this should read the file, and return the string of the whole file
	//return "";
}

string remove_punctuation(string& text)
{
    string result;
    std::remove_copy_if(text.begin(), text.end(),            
                        std::back_inserter(result), //Store output           
                        std::ptr_fun<int, int>(&ispunct));
    return result;
}

my_map<string, double> create_freq_map(const string& text)
{
    my_map<string,double> freq_map;
	stringstream ss(text);
	string item;
	int count = 0;
	while (ss >> item)
	{
		freq_map[item]++;
		count++; 
	}
	cout << "Count" << count << endl;
	for (auto word : freq_map)
		freq_map[word.key] /= count;
	
    //FINISH THIS FUNCTION
    //this should find the frequecies of every word in the text

    return freq_map;
}

vector<key_value<string,double>> vectorize_map(my_map<string, double>& freq_map)
{
    vector<key_value<string,double>> freq_vec;
	for (auto i = freq_map.begin(); i != freq_map.end(); i++)
	{
		freq_vec.push_back(*i);
	}
    //FINISH THIS FUNCTION
    //this should return a sorted vector of the results

    return freq_vec;
}

void remove_stop_words(vector<key_value<string,double>>& freq_vec, vector<string> stop_words)
{
	
	
	for (int j = 0; j < stop_words.size(); j++)
	{
		for (auto i = freq_vec.begin(); i != freq_vec.end(); i++)
		{
			if ((*i).key == stop_words.at(j))
			{
				freq_vec.erase(i);
				i--;
			}
		}
	}
	
	
	
	
   //FINISH THIS FUNCTION
   //this function should remove the elements contained in stop_words from freq_vec 
}

void print_top_20_freqs(const vector<key_value<string,double>>& freq_vec, ostream& out)
{
	out << "\nTop 20 frequency words" << endl << endl;
	vector<double> values;
	vector<double> topV;
	vector <key_value<string, double>> top_pairs;
	for (auto i = freq_vec.begin(); i != freq_vec.end(); i++)
	{
		values.push_back(i->value);
	}
	sort(values.begin(), values.end());
	if (values.size() > 20)
	{
		values.erase(unique(values.begin(), values.end()), values.end());
		for (int m = (values.size() - 20); m < values.size(); m++)
		{
			topV.push_back(values[m]);
		}
	}
	else
	{
		values.erase(unique(values.begin(), values.end()), values.end());
		for (int m = 0; m < values.size(); m++)
			topV.push_back(values[m]);

	}
	reverse(topV.begin(), topV.end());
	for (int n = 0; n < topV.size(); n++)
	{
		for (auto j = freq_vec.begin(); j != freq_vec.end(); j++)
		{
			if (j->value == topV[n])
				top_pairs.push_back(*j);
		}
	}

	for (auto p = top_pairs.begin(); p != top_pairs.end(); p++)
		out << *p << endl;


    //prints the top 20 frequencies to out
}
