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
class VideoKamera : public Kamera
{
protected:
    static int videoCounter;
public:

};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
