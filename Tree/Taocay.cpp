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
#include <queue>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateNode(int x) {
    TNODE* p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void InsertNode(TREE& t, int x) {
    if (t == NULL) {
        t = CreateNode(x);
    } else {
        if (x < t->key) {
            InsertNode(t->pLeft, x);
        } else if (x > t->key) {
            InsertNode(t->pRight, x);
        }
    }
}

void CreateTree(TREE& t) {
    int x;
    while (cin >> x && x != -1) {
        InsertNode(t, x);
    }
}

// print tree using BFS, each level on a new line

void PrintTreeBFS(TREE t) {
    if (t == NULL) {
        cout << "Empty Tree.";
        return;
    }

    queue<TNODE*> q;
    q.push(t);
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TNODE* current = q.front();
            q.pop();
            cout << current->key << " ";
            if (current->pLeft != NULL) q.push(current->pLeft);
            if (current->pRight != NULL) q.push(current->pRight);
        }
        cout << endl; // New line for each level
    }
}

int main() {
	TNODE* T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);
	PrintTreeBFS(T);
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