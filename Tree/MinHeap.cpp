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
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

bool isMinHeap(int A[], int N) {
    for (int i = 0; i < N; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < N && A[i] > A[left]) return false;
        if (right < N && A[i] > A[right]) return false;
    }
    return true;
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    std::cout << "MinHeap: " << std::boolalpha << isMinHeap(a, n) << std::endl;

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