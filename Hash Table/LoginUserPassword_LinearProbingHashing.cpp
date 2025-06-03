//                         
//
//       69696969                         69696969
//    6969    696969                   696969    6969
//  969    69  6969696               6969  6969     696
// 969        696969696             696969696969     696
//969        69696969696           6969696969696      696
//696      9696969696969           969696969696       969
// 696     696969696969             969696969        969
//  696     696  96969      _=_      9696969  69    696
//    9696    969696      q(-_-)p      696969    6969
//       96969696         '_) (_`         69696969
//          96            /__/  \            69
//          69          _(<_   / )_          96
//         6969        (__\_\_|_/__)        9696
//
//         Buddha shines, no bugs alive
//         God Bless        Never Crash

#include <iostream>
#include <list>
#include <string>
using namespace std;

const int TableSize = 20011;

struct USER {
    string USERNAME;
    list<string> PASS;
};

struct NODE {
    int flag = 0;
    USER key;
};

struct HashTable {
    NODE table[TableSize];
    int M = TableSize;
};

int HF1(string key) {
    int seed = 131;
    unsigned long hash = 0;
    for (int i = 0; i < key.length(); i++) {
        hash = (hash * seed) + key[i];
    }
    return hash % TableSize;
}

int HF_LinearProbing(int h, int i) {
    return (h + i) % TableSize;
}

void insert(HashTable &ht, string username, string password) {
    int h = HF1(username);
    int i = 0;
    while (true) {
        int pos = HF_LinearProbing(h, i);
        if (ht.table[pos].flag == 0) {
            ht.table[pos].flag = 1;
            ht.table[pos].key.USERNAME = username;
            ht.table[pos].key.PASS.push_back(password);
            break;
        } else if (ht.table[pos].flag == 1 && ht.table[pos].key.USERNAME == username) {
            ht.table[pos].key.PASS.push_back(password);
            break;
        }
        i++;
        if (i == TableSize) break;
    }
}

string getLastPassword(HashTable &ht, string username) {
    int h = HF1(username);
    int i = 0;
    while (i < TableSize) {
        int pos = HF_LinearProbing(h, i);
        if (ht.table[pos].flag == 0) return "Unregistered User.";
        if (ht.table[pos].flag == 1 && ht.table[pos].key.USERNAME == username) {
            return ht.table[pos].key.PASS.back();
        }
        i++;
    }
    return "Unregistered User.";
}

int main() {
    int N, M;
    cin >> N >> M;
    HashTable ht;

    for (int i = 0; i < N; ++i) {
        string user, pass;
        cin >> user >> pass;
        insert(ht, user, pass);
    }

    for (int i = 0; i < M; ++i) {
        string loginUser;
        cin >> loginUser;
        cout << getLastPassword(ht, loginUser) << endl;
    }

    return 0;
}


//          _.-/`)
//         // / / )
//      .=// / / / )
//     //`/ / / / /
//     // /     ` /
//   ||         /
//    \       /
//     ))    .'
//         //    /
//         /