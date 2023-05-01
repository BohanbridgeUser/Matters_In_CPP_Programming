#include "emp.h"
#include <iostream>
#include <cstdlib>

const int MAX = 10;

int main(int argc, char* argv[])
{
    using std::cerr;
    using std::cout;
    using std::endl;
    using std::cin;
    using std::ios_base;

    abstr_emp* pc[MAX];
    if (argc == 1)
    {
        cerr << " Usage: " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    ofstream cfile(argv[1], ios_base::app);
    cfile.close();
    fstream fout;
    fout.open(argv[1], ios_base::in | ios_base::out);
    if (!fout.is_open()) {
        cerr << "FAILED OPEN FILE\n";
        exit(EXIT_FAILURE);
    }
    fout.seekg(0, ios_base::end);
    ios_base::streampos sp = fout.tellg();
    if (sp == 0) {
        fout.seekg(0, ios_base::beg);
        int i = 0;
        for (; i < MAX; i++) {
            int c = 0;
            cout << "Select a type of employee:\n"
                << "1.employee\t2.manager\n"
                << "3.fink    \t4.highfink\n"
                << "5.quit" << endl;
            cin >> c;
            if (c == 5) {
                break;
            }
            switch (c) {
            case 1:
                pc[i] = new employee;
                pc[i]->SetAll();
                break;
            case 2:
                pc[i] = new manager;
                pc[i]->SetAll();
                break;
            case 3:
                pc[i] = new fink;
                pc[i]->SetAll();
                break;
            case 4:
                pc[i] = new highfink;
                pc[i]->SetAll();
                break;
            }
            pc[i]->WriteAll(fout);
        }
        fout.close();
    }
    else {
        fout.seekg(0, ios_base::beg);
        int i = 0;
        for (i; i < MAX; i++) {
            int c = 0;
            fout >> c;
            if (fout.eof())break;
            switch (c)
            {
            case 1:
                pc[i] = new employee;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 2:
                pc[i] = new manager;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 3:
                pc[i] = new fink;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 4:
                pc[i] = new highfink;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            }
        }
        fout.clear();
        for (; i < MAX; i++) {
            fout.seekg(0, ios_base::end);
            int c = 0;
            cout << "Select a type of employee to add:\n"
                << "1.employee\t2.manager\n"
                << "3.fink    \t4.highfink\n"
                << "5.quit" << endl;
            cin >> c;
            if (c == 5) {
                break;
            }
            switch (c) {
            case 1:
                pc[i] = new employee;
                pc[i]->SetAll();
                break;
            case 2:
                pc[i] = new manager;
                pc[i]->SetAll();
                break;
            case 3:
                pc[i] = new fink;
                pc[i]->SetAll();
                break;
            case 4:
                pc[i] = new highfink;
                pc[i]->SetAll();
                break;
            }
            pc[i]->WriteAll(fout);
        }
        fout.clear();
        fout.seekg(0, ios_base::beg);
        for (i = 0; i < MAX; ++i) {
            int c = 0;
            fout >> c;
            if (fout.eof()) break;
            switch (c)
            {
            case 1:
                pc[i] = new employee;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 2:
                pc[i] = new manager;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 3:
                pc[i] = new fink;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            case 4:
                pc[i] = new highfink;
                pc[i]->ReadAll(fout);
                pc[i]->ShowAll();
                break;
            }
        }
        cout << "End\n";
        fout.close();
    }

    return 0;
}