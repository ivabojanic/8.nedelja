#include <iostream>

using namespace std;
class Kamera
{
protected:
    int megaPikseli;
    int freeSpace;
    static int photoCounter;
public:
    Kamera(){megaPikseli = 12; freeSpace = 100;}
    Kamera(int m, int f){megaPikseli = m;freeSpace = f;}
    Kamera(const Kamera &k){megaPikseli = k.megaPikseli; freeSpace = k.freeSpace;}

    static int getCounter(){return photoCounter;}

    bool Slikaj()
    {
        if (freeSpace >= megaPikseli)
        {
            freeSpace -= megaPikseli;
            photoCounter++;

            return true;
        }
        return false;
    }
    void ispisi(){cout<<megaPikseli<<","<<freeSpace<<endl;}
};
int Kamera::photoCounter = 0;
class VideoKamera : public Kamera
{
protected:
    static int videoCounter;
public:
    VideoKamera():Kamera(){}
    VideoKamera(int m, int f):Kamera(m,f){}

    static int getVCounter(){return videoCounter;}

    bool snimaj(int sekunde)
    {
        if(sekunde*megaPikseli <= freeSpace)
        {
            freeSpace -= sekunde*megaPikseli;
            videoCounter++;
            return true;
        }
        return false;
    }

};
int VideoKamera::videoCounter = 0;
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
class Telefon
{
protected:
    DinString broj;
public:
    Telefon(){broj = "066 924 96 86";}
    Telefon(DinString brojic){broj = brojic;}

    bool pozovi(DinString brojic)
    {
        if (broj != brojic)
        {
            return true;
        }
        return false;

    }
};
class TelefonGen2 : public Telefon
{
protected:
    Kamera k;
public:
    TelefonGen2(): Telefon(),k(){}
    TelefonGen2(int m, int f, DinString b):Telefon(b),k(m,f){}

    bool slikajSliku()
    {
        return k.Slikaj();
    }
};
class TelefonGen3 : public TelefonGen2
{
private:
    VideoKamera vk;
public:
    TelefonGen3(): TelefonGen2(),vk(){}
    TelefonGen3(int m, int f, DinString b):TelefonGen2(m,f,b),vk(m,f){}

    bool snimiVideo(int sekunde)
    {
        return vk.snimaj(sekunde);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
