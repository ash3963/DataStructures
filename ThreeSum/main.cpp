#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> brute(vector<int> arr, int target)
{
    vector<int> result;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    result.push_back(k);
                }
            }
        }
    }
    return result;
}

bool threeSum(vector<int> arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int lo = i + 1;
        int hi = n - 1;
        while (lo < hi)
        {
            int current = arr[i] + arr[lo] + arr[hi];
            if (current == target)
            {
                return true;
            }
            if (current < target)
                lo++;
            else
                hi--;
        }
    }
    return false;
}

void display(vector<int> arr)
{
    for (auto val : arr)
    {
        cout << " " << val << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> arr{7, 6, 1, 12, 3, 9};
    display(arr);

    if (threeSum(arr, 24))
        cout << "True";
    else
        cout << "False";

    return 0;
}