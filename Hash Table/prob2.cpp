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
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE *pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE *NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
	NODE* p;
	p = new NODE;
	p->key = x;
	p->pNext = NULL;
	return p;
}
void AddTail(NODE* &head, int x) {
	NODE *p=CreateNode(x);
    if (head == NULL) head = p;
	else {
        NODE* i=head;
        while(i->pNext!=NULL){
            i=i->pNext;
        }
        i->pNext=p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

void InitHashTable(HASHTABLE &H, int numbucket) {
    for (int i = 0; i<numbucket; i++)
        H[i] = NULL;
}

void TraverseBucket(HASHTABLE H, int i) {
    NODEPTR p = H[i];
    while (p != NULL) {
        cout << " --> " << p->key;
        p = p->pNext;
    }
}
void Traverse(HASHTABLE H, int numbucket) {
    for (int i = 0; i<numbucket; i++) {
        cout << i ;
        TraverseBucket(H, i);
        cout << endl;
    }
}

void Insert(HASHTABLE &H, int numbucket, int key) {
    int idx = HF(numbucket, key);
    AddTail(H[idx], key);               
}

bool Remove(HASHTABLE &H, int numbucket, int key) {
    int idx = HF(numbucket, key);
    NODE* cur  = H[idx];
    NODE* prev = nullptr;

    while (cur != nullptr) {
        if (cur->key == key) {
            if (prev == nullptr) H[idx] = cur->pNext;   
            else                 prev->pNext = cur->pNext;
            delete cur;
            return true;
        }
        prev = cur;
        cur  = cur->pNext;
    }
    return false;                                      
}

void CreateHashTable(HASHTABLE &H, int &numbucket) {
    cin >> numbucket;                        
    if (numbucket > M) numbucket = M;        

    InitHashTable(H, numbucket);

    int key;                                 
    while (cin >> key && key != -1) Insert(H, numbucket, key);
}

int main(){
    HASHTABLE H;
    int numbucket;
    int x;

    CreateHashTable(H, numbucket);

    Traverse(H, numbucket);

    cin >> x;
    if (Remove(H, numbucket, x)) {
        cout << endl << x << ": Delete Successful."  << endl << endl;
        Traverse(H, numbucket);
    }
    else cout << endl << x << ": Delete Failed." << endl << endl;

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