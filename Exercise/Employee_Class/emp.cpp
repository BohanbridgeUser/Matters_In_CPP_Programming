#include "emp.h"
using std::cout;
using std::endl;
using std::cin;
using std::cerr;
abstr_emp::abstr_emp()
{
}
abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j) :fname(fn), lname(ln), job(j)
{
}
abstr_emp::abstr_emp(const abstr_emp& a) :fname(a.fname), lname(a.lname), job(a.job)
{
}
abstr_emp::~abstr_emp()
{
}
void abstr_emp::ShowAll() const
{
    cout << "Name: " << fname << ' ' << lname << endl;
    cout << "Job: " << job << endl;
}
void abstr_emp::SetAll()
{
    cout << "Enter first name: ";
    cin >> fname;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter job: ";
    cin >> job;
}
fstream& abstr_emp::WriteAll(fstream& os)const
{
    os << fname << endl << lname << endl << job << endl;
    return os;
}
fstream& abstr_emp::ReadAll(fstream& is)
{
    is >> fname;
    is >> lname;
    is >> job;
    return is;
}
ostream& operator<<(ostream& os, abstr_emp& a)
{
    return os << "Name: " << a.fname << ' ' << a.lname << endl
        << "Job: " << a.job << endl;
}
istream& operator>>(istream& is, abstr_emp& a)
{
    if (is >> a.fname) {
        if (is >> a.lname) {
            if (is >> a.job) {
                return is;
            }
            else {
                cerr << "Failed input job.\n";
                exit(0);
            }
        }
        else {
            cerr << "Failed input lastname.\n";
            exit(0);
        }
    }
    else {
        cerr << "Failed input firstname.\n";
        exit(0);
    }
}

employee::employee()
{
}
employee::employee(const string& fn, const string& ln, const string& j) :abstr_emp(fn, ln, j)
{
}
employee::employee(const employee& e) :abstr_emp(e)
{

}
employee::~employee()
{
}
fstream& employee::WriteAll(fstream& os)const
{
    os << 1 << endl;
    abstr_emp::WriteAll(os);
    return os;
}
fstream& employee::ReadAll(fstream& is)
{
    abstr_emp::ReadAll(is);
    return is;
}
void employee::ShowAll()const
{
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    abstr_emp::SetAll();
}

manager::manager()
{
}
manager::manager(const string& fn, const string& ln, const string& j, int ico)
    :abstr_emp(fn, ln, j), inchargeof(ico)
{
}
manager::manager(const abstr_emp& e, int ico) :abstr_emp(e), inchargeof(ico)
{

}
manager::manager(const manager& m) :abstr_emp(m), inchargeof(m.inchargeof)
{
}
manager::~manager()
{
}
fstream& manager::WriteAll(fstream& os)const
{
    os << 2 << endl;
    abstr_emp::WriteAll(os);
    os << inchargeof << endl;
    return os;
}
fstream& manager::ReadAll(fstream& is)
{
    abstr_emp::ReadAll(is);
    is >> inchargeof;
    return is;
}
void manager::ShowAll()const
{
    abstr_emp::ShowAll();
    cout << "Inchargeof: " << inchargeof << endl;
}
void manager::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter inchargeof: ";
    cin >> inchargeof;
}

fink::fink()
{

}
fink::fink(const string& fn, const string& ln, const string& j, const string& rt)
    :abstr_emp(fn, ln, j), reportsto(rt)
{
}
fink::fink(const abstr_emp& e, const string& rt)
    :abstr_emp(e), reportsto(rt)
{
}
fink::fink(const fink& f) :abstr_emp(f), reportsto(f.reportsto)
{
}
fink::~fink()
{
}
fstream& fink::WriteAll(fstream& os)const
{
    os << 3 << endl;
    abstr_emp::WriteAll(os);
    os << reportsto << endl;
    return os;
}
fstream& fink::ReadAll(fstream& is)
{
    abstr_emp::ReadAll(is);
    is >> reportsto;
    return is;
}
void fink::ShowAll()const
{
    abstr_emp::ShowAll();
    cout << "ReportsTo: " << reportsto << endl;
}
void fink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter reportsto: ";
    cin >> reportsto;
}

highfink::highfink()
{
}
highfink::highfink(const string& fn, const string& ln, const string& j, const string& rt, int ico)
    :abstr_emp(fn, ln, j), fink(fn, ln, j, rt), manager(fn, ln, j, ico)
{
}
highfink::highfink(const abstr_emp& a, const string& rt, int ico)
    :abstr_emp(a), fink(a, rt), manager(a, ico)
{
}
highfink::highfink(const fink& f, int ico)
    :abstr_emp(f), manager(f, ico), fink(f)
{
}
highfink::highfink(const manager& m, const string& rt)
    :abstr_emp(m), manager(m), fink(m, rt)
{
}
highfink::highfink(const highfink& hf)
    :abstr_emp(hf), manager(hf), fink(hf)
{
}
highfink::~highfink()
{
}
fstream& highfink::WriteAll(fstream& os)const
{
    os << 4 << endl;
    abstr_emp::WriteAll(os);
    os << Inchargeof() << endl;
    os << ReportsTo() << endl;
    return os;
}
fstream& highfink::ReadAll(fstream& is)
{
    abstr_emp::ReadAll(is);
    is >> Inchargeof();
    is >> ReportsTo();
    return is;
}
void highfink::SetAll()
{
    abstr_emp::SetAll();
    cout << "Enter inchargeof: ";
    cin >> Inchargeof();
    cout << "Enter reportsto: ";
    cin >> ReportsTo();
}
void highfink::ShowAll()const
{
    abstr_emp::ShowAll();
    cout << "Inchargeof: " << Inchargeof() << endl;
    cout << "ReportsTo: " << ReportsTo() << endl;
}