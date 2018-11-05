#include "my_map.h"
#include "text_freq.h"
#include <iostream>
#include <string>
int main()
{
    my_map<string, int> m;
    m["c"] = 10;
    m["f"] = 3;
    m["z"] = 4;
    m["a"] = 5;
    m["b"] = 15;
    m["e"] = 15;
    m["f"] = 15;
    
    cout << endl << m << endl;
    
    auto curr = m.begin();
    
    while(curr != m.end())
    {
        cout << *curr << endl;
        curr++;
    }
    
	string test = read_file("test_text1.txt");
	
	my_map <string, double> m2(create_freq_map(test));
	cout << endl;
	cout << m2;
	vector<string> s = { "There" };
	
	vector<key_value<string, double>> v;
	v = vectorize_map(m2);
	remove_stop_words(v, s);
	
	print_top_20_freqs(v,cout);
	system("pause");
}