#include <iostream>

using namespace std;
class DinString
{
private:
        int duzina;
        char *text;
public:
        DinString(){duzina = 0; text = NULL;}
        DinString(const char ulaz[])
        {
            duzina = 0;
            while (ulaz[duzina] != '\0')
            {
                duzina++;
            }
            text = new char [duzina + 1];
            for(int i = 0; i < duzina; i++)
            {
                text[i] = ulaz[i];
            }
            text[duzina] = '\0';
        }
        DinString(const DinString &ds)
        {
            duzina = ds.duzina;
            text = new char [duzina + 1];
            for(int i = 0; i < duzina; i++)
            {
                text[i] = ds.text[i];
            }
            text[duzina] = '\0';
        }
        ~DinString(){ delete[] text;}

        int length() const {return duzina;}
        char& operator[] (int i){return text[i];}
        char operator[] (int i) const {return text[i];}

        DinString& operator=(const DinString &ds)
        {
            if(this != &ds) {
            delete[] text;
            duzina = ds.duzina;
            text = new char[duzina + 1];
            for (int i = 0; i < duzina; i++)
            {
                text[i] = ds.text[i];
            }
            text[duzina] = '\0';
        }
            return *this;
        }
        DinString& operator+=(const DinString &ds)
        {
            int i;
            char *tempText = new char[duzina + ds.duzina + 1];
            for (i = 0; i < duzina; i++)
            {
                 tempText[i] = text[i];
            }
            for (i = 0; i < ds.duzina; i++)
            {
                tempText[duzina + i] = ds.text[i];
            }
            tempText[duzina + ds.duzina] = '\0';
            duzina += ds.duzina;
            delete[] text;
            text = tempText;

            return *this;
        }

        friend bool operator==(const DinString &ds1, const DinString &ds2)
        {
            if(ds1.duzina != ds2.duzina)
            {
                return false;
            }
            for(int i = 1; i < ds1.duzina; i++)
            {
                if(ds1.text[i] != ds2.text[i])
                {
                    return false;
                }
            }
        }
        friend bool operator!=(const DinString &ds1 , const DinString &ds2)
        {
            if(ds1.duzina != ds2.duzina)
            {
                return true;
            }
            for(int i = 1; i < ds1.duzina; i++)
            {
                if(ds1.text[i] != ds2.text[i])
                {
                    return true;
                }
            }
        }
        friend DinString operator+(const DinString &ds1, const DinString &ds2)
        {
            DinString temp;
            temp.duzina = ds1.duzina + ds2.duzina;
            temp.text = new char[temp.duzina + 1];
            int i;
            for(i = 0; i < ds1.duzina; i++)
            {
                temp.text[i] = ds1.text[i];
            }
            for(i = 0; i < ds2.duzina; i++)
            {
                temp.text[ds1.duzina + i] = ds2.text[i];
            }
            temp.text[temp.duzina] = '\0';
            return temp;
        }

        friend ostream& operator<<(ostream &out, const DinString &ds)
        {
            if(ds.duzina > 0)
            {
                cout<<ds.text;
            }
            return out;
        }
};
class Osoba
{
protected:
    DinString Ime;
    DinString Prezime;
public:
    Osoba() : Ime(), Prezime(){}
    Osoba(const char * ime, const char * prezime) : Ime(ime), Prezime(prezime){}
    Osoba(const DinString &i, const DinString &p) : Ime(i), Prezime(p){}
    Osoba(const Osoba &o) : Ime(o.Ime), Prezime(o.Prezime){}

    void predstaviSe()
    {
        cout<<Ime<<","<<Prezime;
    }

};
class Student : public Osoba
{
protected:
    int brojIndeksa;
public:
    Student():Osoba(){brojIndeksa = 123;}
    Student(const char* i, const char* p, int broj):Osoba(i,p){brojIndeksa = broj;}
    Student(const DinString &ime,const DinString &prezime,int brojic): Osoba(ime,prezime){brojIndeksa = brojic;}
    Student(const Osoba &O, int b):Osoba(O){brojIndeksa = b;}
    Student(const Student &S) : Osoba((Osoba)S){brojIndeksa = S.brojIndeksa;}

    void predstaviSe()
    {
        Osoba::predstaviSe();
        cout<<","<<brojIndeksa<<endl;
    }
};
class PhDStudent : public Student
{
private:
    double ProsecnaOcena;
public:
    PhDStudent():Student(){ProsecnaOcena = 10.00;}
    PhDStudent(const char* i, const char *p, int broj, double ocena):Student(i,p,broj){ProsecnaOcena = ocena;}
    PhDStudent(const DinString &ime, const DinString &prezime, int brojcina,double ocenica):Student(ime,prezime,brojcina){ProsecnaOcena = ocenica;}
    PhDStudent(const Osoba &O, int b, double oc):Student(O,b){ProsecnaOcena = oc;}
    PhDStudent(const Student &S, double c): Student(S){ProsecnaOcena = c;}
    PhDStudent(const PhDStudent &p): Student((Student)p){ProsecnaOcena = p.ProsecnaOcena;}

    void predstaviSe()
    {
        Student::predstaviSe();
        cout<<","<<ProsecnaOcena<<endl;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
