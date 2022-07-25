#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> umap;
    umap["Ashish"] = 10;
    umap["Parag"] = 20;
    umap["Vijay"] = 30;

    umap.insert(make_pair("Don", 40));

     for (auto x : umap)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }

    string key="Robot";

    if(umap.find(key)==umap.end())
        cout<<"Not Found!"<<endl;
    else    
        cout<<"Found "<<key<<" in the table"<<endl;

    unordered_map<string, int>::iterator itr;
    cout<<"All elements: "<<endl;

    for(itr=umap.begin();itr!=umap.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }

    return 0;
}