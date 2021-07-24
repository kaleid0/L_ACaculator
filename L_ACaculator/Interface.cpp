#include "Interface.h"
//#include "fraction.h"
//#include "fraction.cpp"

using namespace std;


void Interface::start() {
    bool quit = 1;
    do {
        system("CLS");
        cout << "1.向量计算" << endl;
        cout << "2.矩阵计算" << endl;
        cout << "3.线性方程" << endl;
        cout << "4.敬请期待" << endl;////////////////////////////////////////
        cout << "5.退出" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1:vector_cacul(); break;
        case 2:matrix_cacul(); break;
        case 3:equation_cacul(); break;
        case 4:cout << "敬请期待" << endl; break;
        case 5: quit = 0; break;
        }

    } while (quit);
}

void Interface::vector_cacul() {
    bool quit = 1;
    do {
        system("CLS");
        vl.showlist();
        cout << "--------------" << endl;
        cout << "--------------" << endl;
        cout << "1.新建向量" << endl;
        cout << "2.删除向量" << endl;
        cout << "3.向量运算" << endl;
        cout << "4.返回" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "输入向量维数:";
            int n;
            cin >> n;
            vec temp(n);
            temp.setVec(n);
            vl.push_back(temp);
            break;
        }
        case 2: {
            cout << "要删除的向量编号:";
            int n;
            cin >> n;
            vl.deleteVec(n);
            break;
        }
        case 3: {
            vector_cacul2(); 
            break;
        }
        case 4: quit = 0; break;
        }

    } while (quit);
}

void Interface::vector_cacul2() {
    system("CLS");
    cout << "选择运算向量:" << endl;
    int i, j;
    cin >> i >> j;
    cout << "选择运算操作" << endl;
    cout << "'+','-','%'" << endl;
    char k;
    cin >> k;
    switch (k) {
    case '+': {
        vl.push_back(vl[i - 1] + vl[j - 1]);
        break;
    }
    case '-': {
        vl.push_back(vl[i - 1] - vl[j - 1]);
        break;
    }
    //case '*': {
    //    vl.push_back(vl[i - 1] * vl[j - 1]);
    //    break;
    //}
    case '%': {
        vl.push_back(vl[i - 1] % vl[j - 1]);
        break;
    }
    }
}

void Interface::matrix_cacul() {
    bool quit = 1;
    do {
        system("CLS");
        ml.showlist();
        cout << "--------------" << endl;
        cout << "--------------" << endl;
        cout << "1.新建矩阵" << endl;
        cout << "2.删除矩阵" << endl;
        cout << "3.矩阵运算" << endl;
        cout << "4.返回" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "输入矩阵维度(行,列):";
            int n, m;
            cin >> n >> m;
            matrix temp(n, m);
            temp.setMatrix(n, m);
            ml.push_back(temp);
            break;
        }
        case 2: {
            cout << "要删除的矩阵编号:";
            int n;
            cin >> n;
            ml.deleteMat(n);
            break;
        }
        case 3: {
            matrix_cacul2();
            break;
        }
        case 4: quit = 0; break;
        }

    } while (quit);
}

void Interface::matrix_cacul2() {
    bool quit = 1;
    do {
        system("CLS");
        ml.showlist();
        cout << "选择运算操作:" << endl;
        cout << "1.数乘矩阵" << endl;
        cout << "2.转置矩阵" << endl;
        cout << "3.矩阵行列式" << endl;
        cout << "4.伴随矩阵" << endl;
        cout << "5.逆矩阵" << endl;
        cout << "6.矩阵的秩" << endl;
        cout << "7.矩阵乘矩阵" << endl;
        cout << "8.矩阵幂运算" << endl;
        cout << "9.返回" << endl;
        int k;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "输入整数:" << endl;
            int n;
            cin >> n;
            cout << "选择要计算的矩阵:" << endl;
            int i;
            cin >> i;
            ml[i - 1].numbermult(n);
            break;
        }
        case 2: {
            cout << "选择要转置的矩阵:" << endl;
            int n; cin >> n;
            ml.push_back(reverse(ml[n - 1]));
            break;
        }
        case 3: {
            cout << "选择矩阵:" << endl;
            int n; cin >> n;
            fraction f = ml[n - 1].det();
            cout << f << endl;
            system("pause");
            break;
        }
        case 4: {
            cout << "选择矩阵:" << endl;
            int n; cin >> n;
            ml.push_back(ml[n - 1].adjugate());
            break;
        }
        case 5: {
            cout << "选择矩阵:" << endl;
            int n; cin >> n;
            int r = ml[n - 1].rank();
            if (r < ml[n - 1].getlength()) {
                cout << "不满秩,不可逆" << endl;
                system("pause");
                break;
            }
            ml.push_back(ml[n - 1].inversion());
            break;
        }
        case 6: {
            cout << "选择矩阵:" << endl;
            int n; cin >> n;
            cout << "矩阵的秩为:" << ml[n - 1].rank() << endl;
            system("pause");
            break;
        }
        case 7: {
            cout << "选择两个矩阵:" << endl;
            int n, m; cin >> n >> m;
            (ml[n - 1] * ml[m - 1]).showMatrix();
            ml.push_back(ml[n - 1] * ml[m - 1]);
            system("pause");
            break;
        }
        case 8: {
            cout << "选择矩阵:" << endl;
            int n; cin >> n;
            cout << "输入幂:" << endl;
            int t; cin >> t;
            matrix res(ml[n - 1].getlength(), ml[n - 1].getwide(), 1);
            for (int i = 0; i < t; i++) {
                res = res * ml[n - 1];
            }
            ml.push_back(res);
            res.showMatrix();
            system("pause");
            break;
        }
        case 9:quit = 0; break;
        }
    } while (quit);
}


void Interface::equation_cacul() {                  //1.克拉默,2.化阶梯
    bool quit = 1;
    do {
        system("CLS");
        ml.showlist();
        vl.showlist();
        cout << "1.系数矩阵" << endl;
        cout << "2.增广右值" << endl;
        cout << "3.解齐次线性方程组" << endl;
        cout << "4.解非齐次线性方程组" << endl;
        cout << "5.返回" << endl;
        int k;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "输入矩阵（增广矩阵）的行列数:" << endl;
            int n, m;
            cin >> n >> m;
            matrix temp(n, m);
            temp.setMatrix(n, m);
            ml.push_back(temp);
            break;
        }
        case 2: {
            cout << "输入右值数量:" << endl;
            int n;
            cin >> n;
            vec temp(n);
            temp.setVec(n);
            vl.push_back(temp);
            break;
        }
        case 3: {
            cout << "选择系数矩阵:" << endl;
            int n;
            cin >> n;
            matrix temp = ml[n - 1].equationsolve();
            temp.showMatrix();
            ml.push_back(temp);
            system("pause");
            break;
        }
        case 4: {
            cout << "选择系数矩阵:" << endl;
            int n;
            cin >> n;
            cout << "选择右值:" << endl;
            int m;
            cin >> m;
            matrix temp = ml[n - 1].equationsolve(vl[m-1]);
            temp.showMatrix();
            ml.push_back(temp);
            system("pause");
            break;
        }
        case 5:quit = 0; break;
        }
    } while (quit);
}

