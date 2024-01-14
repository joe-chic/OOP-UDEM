#include <iostream>
#include <string>
using namespace std;

class Hora
{
    int hh;
    int mm;
    
    public:
        Hora();
        Hora(int h, int m);

        int getHH() const;
        void setHH(int h);

        int getMM() const;
        void setMM(int m);

        friend Hora operator+(Hora obj, int m);
        friend bool operator>=(Hora const& obj1, Hora const& obj2);
        friend bool operator<=(Hora const& obj1, Hora const& obj2);
        friend bool operator==(Hora const& obj1, Hora const& obj2);

        friend istream& operator>>(istream& in, Hora& c);
        friend ostream& operator<<(ostream& out, const Hora& c);
};

Hora::Hora()
{
    hh = 0;
    mm = 0;
}

Hora::Hora(int h, int m)
{
    hh = h;
    mm = m;
}

int Hora::getHH() const
{
    return hh;
}

void Hora::setHH(int h)
{
    hh = h;
}

int Hora::getMM() const
{
    return mm;
}

void Hora::setMM(int m)
{
    mm = m;
}

Hora operator+(Hora obj,int m)
{
    Hora res;

    int min_ans = (obj.mm+m)%60;
    int h_ans_add = (obj.mm+m)/60;

    if( h_ans_add+obj.hh > 23)
    {
        res.mm = min_ans; 
        res.hh = (h_ans_add+obj.hh)%24;
    }
    else
    {
        res.mm = min_ans;
        res.hh = h_ans_add+obj.hh;
    }

    return res;
}

bool operator>=(Hora const& obj1, Hora const& obj2)
{
    if(obj1.hh > obj2.hh)
        return true;
    else if(obj1.hh == obj2.hh)
    {
        if(obj1.mm >= obj2.mm)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool operator<=(Hora const& obj1, Hora const& obj2)
{
    if(obj1.hh < obj2.hh)
        return true;
    else if(obj1.hh == obj2.hh)
    {
        if(obj1.mm <= obj2.mm)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool operator==(Hora const& obj1, Hora const& obj2)
{
    if(obj1.hh == obj2.hh)
    {
        if(obj1.mm == obj2.mm)
            return true;
        else
            return false;
    }
    else
        return false;    
}

istream& operator>>(istream& in, Hora& c)
{   
    in >> c.hh >> c.mm;
    return in;
}
ostream& operator<<(ostream& out, const Hora& c)
{
    if( c.hh < 10 )
    {
        if( c.mm < 10 )
            out << "0" << c.hh << ":0" << c.mm;
        else
            out << "0" << c.hh << ":" << c.mm;
    }
    else
    {
        if( c.mm < 10 )
            out << c.hh << ":0" << c.mm;
        else
            out << c.hh << ":" << c.mm;
    } 
    return out;
}