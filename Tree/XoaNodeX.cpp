//
//
//       69696969                         69696969
//    6969    696969                   696969    6969
//  969    69  6969696               6969  6969     696
// 969        696969696             696969696969     696
// 969        69696969696           6969696969696      696
// 696      9696969696969           969696969696       969
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

struct TNODE
{
    int key;   // giá trị của phần tử
    int count; // số lần xuất hiện
    TNODE *pLeft;
    TNODE *pRight;
};
typedef TNODE *TREE;

void CreateNode(TREE &p, int x)
{
    p = new TNODE;
    p->key = x;
    p->count = 1;
    p->pLeft = NULL;
    p->pRight = NULL;
}

void InsertNode(TREE &t, int x)
{
    if (t == NULL)
    {
        CreateNode(t, x);
    }
    else
    {
        if (x == t->key)
        {
            t->count++;
        }
        else if (x < t->key)
        {
            InsertNode(t->pLeft, x);
        }
        else
        {
            InsertNode(t->pRight, x);
        }
    }
}

void CreateTree(TREE &t)
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        InsertNode(t, x);
    }
}

void ThayThe(TREE &p, TREE &T)
{
    if (T->pLeft != NULL)

        ThayThe(p, T->pLeft);

    else
    {
        p->key = T->key;
        p = T;
        T = T->pRight;
    }
}

void DeleteNodeX(TREE &T, int x)
{
    if (T != NULL)
    {
        if (T->key < x)
            DeleteNodeX(T->pRight, x);
        else
        {
            if (T->key > x)
                DeleteNodeX(T->pLeft, x);
            else
            { // tim thấy Node có trường dữ liệu = x
                TNODE *p;
                p = T;
                if (T->pLeft == NULL)
                    T = T->pRight;
                else
                {

                    if (T->pRight == NULL)
                        T = T->pLeft;
                    else
                        ThayThe(p, T->pRight); // tìm bên cây con phải
                }
                delete p;
            }
        }
    }
}

int main()
{
    TNODE *T;
    T = NULL;
    CreateTree(T);

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