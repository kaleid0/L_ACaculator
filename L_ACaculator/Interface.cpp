#include "Interface.h"
//#include "fraction.h"
//#include "fraction.cpp"

using namespace std;


void Interface::start() {
    bool quit = 1;
    do {
        system("CLS");
        cout << "1.��������" << endl;
        cout << "2.�������" << endl;
        cout << "3.���Է���" << endl;
        cout << "4.�����ڴ�" << endl;////////////////////////////////////////
        cout << "5.�˳�" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1:vector_cacul(); break;
        case 2:matrix_cacul(); break;
        case 3:equation_cacul(); break;
        case 4:cout << "�����ڴ�" << endl; break;
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
        cout << "1.�½�����" << endl;
        cout << "2.ɾ������" << endl;
        cout << "3.��������" << endl;
        cout << "4.����" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "��������ά��:";
            int n;
            cin >> n;
            vec temp(n);
            temp.setVec(n);
            vl.push_back(temp);
            break;
        }
        case 2: {
            cout << "Ҫɾ�����������:";
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
    cout << "ѡ����������:" << endl;
    int i, j;
    cin >> i >> j;
    cout << "ѡ���������" << endl;
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
    /*case '%': {
        vl.push_back(vl[i - 1] % vl[j - 1]);
        break;
    }*/
    }
}

void Interface::matrix_cacul() {
    bool quit = 1;
    do {
        system("CLS");
        ml.showlist();
        cout << "--------------" << endl;
        cout << "--------------" << endl;
        cout << "1.�½�����" << endl;
        cout << "2.ɾ������" << endl;
        cout << "3.��������" << endl;
        cout << "4.����" << endl;

        int k = 0;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "�������ά��(��,��):";
            int n, m;
            cin >> n >> m;
            matrix temp(n, m);
            temp.setMatrix(n, m);
            ml.push_back(temp);
            break;
        }
        case 2: {
            cout << "Ҫɾ���ľ�����:";
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
        cout << "ѡ���������:" << endl;
        cout << "1.���˾���" << endl;
        cout << "2.ת�þ���" << endl;
        cout << "3.��������ʽ" << endl;
        cout << "4.�������" << endl;
        cout << "5.�����" << endl;
        cout << "6.�������" << endl;
        cout << "7.����˾���" << endl;
        cout << "8.����������" << endl;
        cout << "9.����" << endl;
        int k;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "��������:" << endl;
            int n;
            cin >> n;
            cout << "ѡ��Ҫ����ľ���:" << endl;
            int i;
            cin >> i;
            ml[i - 1].numbermult(n);
            break;
        }
        case 2: {
            cout << "ѡ��Ҫת�õľ���:" << endl;
            int n; cin >> n;
            ml.push_back(ml[n - 1].mreverse());
            break;
        }
        case 3: {
            cout << "ѡ�����:" << endl;
            int n; cin >> n;
            fraction f = ml[n - 1].det();
            cout << f << endl;
            system("pause");
            break;
        }
        case 4: {
            cout << "ѡ�����:" << endl;
            int n; cin >> n;
            ml.push_back(ml[n - 1].adjugate());
            break;
        }
        case 5: {
            cout << "ѡ�����:" << endl;
            int n; cin >> n;
            int r = ml[n - 1].rank();
            if (r < ml[n - 1].getlength()) {
                cout << "������,������" << endl;
                system("pause");
                break;
            }
            ml.push_back(ml[n - 1].inversion());
            break;
        }
        case 6: {
            cout << "ѡ�����:" << endl;
            int n; cin >> n;
            cout << "�������Ϊ:" << ml[n - 1].rank() << endl;
            system("pause");
            break;
        }
        case 7: {
            cout << "ѡ����������:" << endl;
            int n, m; cin >> n >> m;
            (ml[n - 1] * ml[m - 1]).showMatrix();
            ml.push_back(ml[n - 1] * ml[m - 1]);
            system("pause");
            break;
        }
        case 8: {
            cout << "ѡ�����:" << endl;
            int n; cin >> n;
            cout << "������:" << endl;
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


void Interface::equation_cacul() {                  //1.����Ĭ,2.������
    bool quit = 1;
    do {
        system("CLS");
        ml.showlist();
        vl.showlist();
        cout << "1.ϵ������" << endl;
        cout << "2.������ֵ" << endl;
        cout << "3.��������Է�����" << endl;
        cout << "4.���������Է�����" << endl;
        cout << "5.����" << endl;
        int k;
        cin >> k;
        switch (k) {
        case 1: {
            cout << "�������������󣩵�������:" << endl;
            int n, m;
            cin >> n >> m;
            matrix temp(n, m);
            temp.setMatrix(n, m);
            ml.push_back(temp);
            break;
        }
        case 2: {
            cout << "������ֵ����:" << endl;
            int n;
            cin >> n;
            vec temp(n);
            temp.setVec(n);
            vl.push_back(temp);
            break;
        }
        case 3: {
            cout << "ѡ��ϵ������:" << endl;
            int n;
            cin >> n;
            matrix temp = ml[n - 1].equationsolve();
            temp.showMatrix();
            ml.push_back(temp);
            system("pause");
            break;
        }
        case 4: {
            cout << "ѡ��ϵ������:" << endl;
            int n;
            cin >> n;
            cout << "ѡ����ֵ:" << endl;
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

