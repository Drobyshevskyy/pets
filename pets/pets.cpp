#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>

using namespace std;
 
void stat4(multimap<string, int>& m, multimap<string, int>::iterator it, string& key, int& data) {
    if (key != "")
    {
        if (m.find(key) == m.end())
        {
            m.insert(pair<string, int>(key, data));
            m.insert(pair<string, int>(key, data));
        }
        else
        {
            it = m.find(key);
            if (data > it->second)
            {
                it->second = data;
            }
            else
            {
                ++it;
                if (data < it->second)
                {
                    it->second = data;
                }
            }
        }
    }
}
void stat1_3(multimap<string, string>& m, multimap<string, string>::iterator it,string& key,string& data)
{
    if (key != "" && data != "")
    {
        if (m.find(key) == m.end()) {
            m.insert(pair<string, string>(key, data));
        }
        else {
        int k = 1;
        for (it = m.find(key); it->first == key; it++, k++) {
            if (it->second == data) {
                break;
            }
            if (k == m.count(key)) {
                m.insert(pair<string, string>(key, data));
            }
            
            
        }
        }
        
    }
    
}

int main()
{
    
    int age = 0;
    string owner;
    string species;
    string name;
    multimap<string, string>o_s;
    map<string, multimap<string, string>>s_o_n;
    multimap<string, string>n_s;
    multimap<string, string>::iterator i;
    multimap<string, int>s_a;
    multimap<string, int>::iterator i1;
    ifstream fin("input.txt");
    while (!fin.eof()) {
        getline(fin, owner, ',');
        getline(fin, species, ',');
        getline(fin, name, ',');
        fin >> age;
        fin.ignore();
        stat1_3(o_s, i, owner, species);
        stat1_3(n_s, i, name, species);
        stat4(s_a, i1, species, age);
        if (s_o_n.find(species) == s_o_n.end())
        {
            s_o_n[species] = { {owner, name} };
        }
        else
        {
            if (s_o_n[species].find(owner) == s_o_n[species].end())
            {
                s_o_n[species].insert(pair<string, string>(owner, name));
            }
            else
            {
                int k = 1;
                for (i = s_o_n[species].find(owner); i->first == owner; i++, k++)
                {
                    if (i->second == name)
                    {
                        break;
                    }
                    if (k == s_o_n[species].count(owner))
                    {
                        s_o_n[species].insert(pair<string, string>(owner, name));
                    }
                }
            }
        }
    }



int variant;
while (true) {
    system("CLS");
    cout << "1. Number of species for each owner\n";
    cout << "2. List of owners and names for given species\n";
    cout << "3. Number of species for given name\n";
    cout << "4. The youngest and eldest animals for each species\n";
    cout << "5. Get back\n\n";
    cout << "Enter your choice: ";
    cin >> variant;
    switch (variant) { 
    case 1:
        system("CLS");
        i = o_s.begin();
        while (i != o_s.end()) {
            cout << "owner: "<<i->first << " species: " << o_s.count(i->first)<<endl;
            advance(i, o_s.count(i->first));
        }
       
        system("PAUSE");
        break;
    case 2:
        system("CLS");
        cout << "enter the species: ";
        cin >> species;
        if (s_o_n.find(species) == s_o_n.end()) {
            cout << "no such species" << endl;
        }
        else {
            i = s_o_n[species].begin();
            while (i != s_o_n[species].end())
            {
                cout << i->first << " - ";
                for (int k = 1; k < s_o_n[species].count(i->first); i++, k++)
                {
                    cout << i->second << ", ";
                }
                cout << i->second << endl;
                ++i;
            }
        }

        system("PAUSE");
        break;
    case 3:
        system("CLS");
        cout << "enter the name: ";
        cin>>name;
        cout << n_s.count(name) << endl;
        
        system("PAUSE");
        break;
    case 4:
        system("CLS");
        i1 = s_a.begin();
        while (i1 !=s_a.end())
        {
            cout << i1->first << endl;
            cout<<" oldest : " << i1->second << endl;
            ++i1;
            cout << " youngest : " << i1->second << endl;
            ++i1;
        }
        system("PAUSE");
        break;
    case 5:
        system("CLS");
        exit(0);
    default:
        system("CLS");
        cout << "Invalid input\n";
        system("PAUSE");
    }
}
fin.close();
return 0;
}