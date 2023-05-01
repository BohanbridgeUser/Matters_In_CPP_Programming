#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using std::string;
using std::ostream;
using std::istream;
using std::ofstream;
using std::ifstream;
using std::fstream;
class abstr_emp
{
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp();
    abstr_emp(const string& fn, const string& ln, const string& j);
    abstr_emp(const abstr_emp& a);
    virtual ~abstr_emp() = 0;
    virtual void ShowAll() const;
    virtual fstream& WriteAll(fstream& os) const;
    virtual fstream& ReadAll(fstream& is);
    virtual void SetAll();
    friend ostream& operator<<(ostream& os, abstr_emp& a);
    friend istream& operator>>(istream& is, abstr_emp& a);
};

class employee : public abstr_emp
{
public:
    employee();
    employee(const string& fn, const string& ln, const string& j);
    employee(const employee& e);
    virtual ~employee();
    virtual void ShowAll()const;
    virtual fstream& WriteAll(fstream& os)const;
    virtual fstream& ReadAll(fstream& is);
    virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int Inchargeof() const { return inchargeof; }
    int& Inchargeof() { return inchargeof; }
public:
    manager();
    manager(const string& fn, const string& ln, const string& j, int ico = 0);
    manager(const abstr_emp& e, int ico);
    manager(const manager& m);
    virtual ~manager();
    virtual fstream& WriteAll(fstream& os)const;
    virtual fstream& ReadAll(fstream& is);
    virtual void ShowAll()const;
    virtual void SetAll();
};

class fink : virtual public abstr_emp
{
private:
    string reportsto;
protected:
    string ReportsTo()const { return reportsto; }
    string& ReportsTo() { return reportsto; }
public:
    fink();
    fink(const string& fn, const string& ln, const string& j, const string& rt);
    fink(const abstr_emp& e, const string& rt);
    fink(const fink& f);
    virtual fstream& WriteAll(fstream& os)const;
    virtual fstream& ReadAll(fstream& is);
    virtual ~fink();
    virtual void ShowAll()const;
    virtual void SetAll();
};

class highfink : public fink, public manager
{
public:
    highfink();
    highfink(const string& fn, const string& ln, const string& j, const string& rt, int ico = 0);
    highfink(const abstr_emp& a, const string& rt, int ico = 0);
    highfink(const fink& f, int ico = 0);
    highfink(const manager& m, const string& rt);
    highfink(const highfink& hf);
    virtual fstream& WriteAll(fstream& os)const;
    virtual fstream& ReadAll(fstream& is);
    virtual ~highfink();
    virtual void SetAll();
    virtual void ShowAll()const;
};