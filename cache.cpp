#include <bits/stdc++.h>
using namespace std;
static int cache_hit = 0;
static int cache_miss = 0;

class LRUCache
{
public:
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> map;
    int n;
    LRUCache(int capacity) { n = capacity; }

    void sendback(int key)
    {
        dll.erase(map[key].first);
        dll.push_front(key);
        map[key].first = dll.begin();
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1;
        }
        sendback(key);
        return map[key].second;
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            map[key].second = value;
            sendback(key);
        }
        else
        {
            dll.push_front(key);
            map[key] = {dll.begin(), value};
            n--;
        }
        if (n < 0)
        {
            int delete_key = dll.back();
            map.erase(delete_key);
            dll.pop_back();
            n++;
        }
    }
};

class SetAssociativeCache
{
private:
    int num_sets;
    int k;
    vector<LRUCache> sets;

    int _index(int address)
    {
        return address % num_sets;
    }

public:
    SetAssociativeCache(int num_sets, int k) : num_sets(num_sets), k(k), sets(num_sets, LRUCache(k)) {}

    int access(int address, int value = -1)
    {
        auto start = chrono::high_resolution_clock::now();

        int index = _index(address);
        int result;
        if (value == -1)
        {
            result = sets[index].get(address);
        }
        else
        {
            sets[index].put(address, value);
            result = 0;
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> duration = end - start;
        if (value == -1 && result != -1)
        {
            cout << "---------------------------------------------" << endl;
            cout << "Memory access time: " << duration.count() << " microseconds" << endl;
        }
        return result;
    }

    void display_cache()
    {
        for (int i = 0; i < num_sets; ++i)
        {
            cout << "Set " << i << ": ";
            for (auto it = sets[i].dll.begin(); it != sets[i].dll.end(); ++it)
            {
                cout << "[Address: " << *it << ", Data: " << sets[i].map[*it].second << "] ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int num_sets = 4;
    int k = 2;

    SetAssociativeCache cache(num_sets, k);

    while (1)
    {
        int data;
        cout << "Enter the operation you want to perform :" << endl;
        cout << "1.Add address with value(Put)" << endl
             << "2.Display" << endl
             << "3.Access Value(Get)" << endl
             << "4.Exit" << endl;
        cin >> data;

        switch (data)
        {
        case 1:
            int address, value;
            cout << "Enter the address and value to be inseted:" << endl;
            cin >> address >> value;
            cache.access(address, value);
            break;
        case 2:
            cache.display_cache();
            break;
        case 3:
        {
            int fetch;
            cout << "Enter the address of the value to be accessed:" << endl;
            cin >> fetch;

            int x = cache.access(fetch);

            if (x == -1)

            {
                cout << "------------------------------------" << endl;
                cache_miss = cache_miss + 1;
                cout << "Cache Miss:" << cache_miss << endl;
                cout << "------------------------------------" << endl;
            }
            else
            {
                cout << "Value:" << fetch << endl;
                cache_hit = cache_hit + 1;
                cout << "Cache Hit:" << cache_hit << endl;
                cout << "------------------------------------" << endl;
            }

            break;
        }
        case 4:
            exit(0);
        }
    }
    return 0;
}
