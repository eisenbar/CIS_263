#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int> item = {1, 2, 3, 4, 5};
vector<int>::iterator it;
vector<int>::reverse_iterator rt;

void perm_helper(string char1, string str)
{
    if (str.empty() )
        cout << char1 << endl;
    else
    {
        for( int i = 0; i < str.size(); i++)
            perm_helper(char1 + str[i], str.substr (0, i) + str. substr (i+1, str.size()));
    }

}

void permute(const string& input)
{
    perm_helper("", input);
}
int main() {
    permute ("CAT");

   // for(it = item.begin(); it != item.end(); ++it)
     //   cout << *it << endl;

    for(rt = item.rbegin(); rt != item.rend(); rt++)
        cout << *rt << endl;
    return 0;

    
}