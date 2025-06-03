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
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE *table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h=HF(ht, key);
    return (h + i) % ht.M;
}

void InitHashtable(HASHTABLE &ht, int M) {
    ht.M = M;
    ht.n = 0;
    ht.table = new NODE[M];
    for (int i = 0; i < M; ++i) {
        ht.table[i].flag = EMPTY;
        ht.table[i].key  = 0;
    }
}

bool Insert(HASHTABLE &ht, int key) {
    if (ht.n >= static_cast<int>(ht.M * LOAD)) return false;

    for (int i = 0; i < ht.M; ++i) {
        int pos = HF_LinearProbing(ht, key, i);
        int flag = ht.table[pos].flag;

        if (flag == OCCUPIED && ht.table[pos].key == key)
            return false;                       

        if (flag == EMPTY || flag == DELETED) { 
            ht.table[pos].flag = OCCUPIED;
            ht.table[pos].key  = key;
            ++ht.n;
            return true;
        }
    }
    return false;                               
}

void Traverse(const HASHTABLE &ht) {
    for (int i = 0; i < ht.M; ++i) {
        cout << i << " --> ";
        if (ht.table[i].flag == OCCUPIED) cout << ht.table[i].key;
        else                              cout << "EMPTY";
        cout << '\n';
    }
}

void CreateHashTable(HASHTABLE &ht) {
    int M;
    cin >> M;                    
    InitHashtable(ht, M);

    int key;                     
    while (cin >> key && key != -1) Insert(ht, key);
}

void DeleteHashtable(HASHTABLE &ht) {
    delete [] ht.table;
    ht.table = NULL;
    ht.M = 0;
}

int main(){
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
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