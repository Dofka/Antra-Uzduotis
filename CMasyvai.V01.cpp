#include <bits/stdc++.h>
#include <vector>

struct mokinys{
std::string vardas,pavarde;
int *paz=new int;
int n=0;
int egz;
int suma=0;
float vidurkis;
float mediana;
double galutinis;
};

using namespace std;
void rikiavimas(mokinys studentas[], int zmones);
int main()
{
    double zmone, egz,paza;
    int zmones;
    int pasirinkimas;
    int randas;
    int paz;
    int skaic;
    int medsk;
    int medvid;
    std::cout<<"Iveskite mokiniu skaiciu"<<std::endl;
    std::cin>>zmone;
    while(std::cin.fail() || zmone==0 || zmone !=(int)zmone)
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout << "Ivyko klaida.  Iveskite skaiciu: ";
    std::cin >> zmone;
}
    zmones = (int)zmone;
    mokinys studentas[zmones];
    std::cout<<"galutini skaiciuoti palei mediana(iveskite 1) ar palei namu darbus (iveskite 0)"<<std::endl;
    std::cin>>pasirinkimas;
    while(std::cin.fail() || pasirinkimas>1 || pasirinkimas<0)
{
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout << "Blogas pasirinkimas. Bandykite dar karta ";
    std::cin >> zmones;
}
    for(int i=0;i<zmones;i++)
    {
        std::cout<<"Mokinio vardas:"<<std::endl;
        std::cin>>studentas[i].vardas;
        std::cout<<"Mokinio pavarde:"<<std::endl;
        std::cin>>studentas[i].pavarde;
        std::cout<<"Random(1) ar ne(0)"<<std::endl;
        std::cin>>randas;
        while(randas!=1 && randas!=0)
        {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Blogas pasirinkimas"<<std::endl;
            std::cin>>randas;
        }
        if(randas==1)
        {
            studentas[i].egz=rand() % 11;
            int kiek=rand() % 101;
            for(int u=0;u<kiek;u++)
            {
                paz=rand()%11;
                skaic=studentas[i].n;
                studentas[i].paz[studentas[i].n]=paz;
                studentas[i].suma=studentas[i].suma+paz;
                studentas[i].n++;
            }
        }
        else
        {
            std::cout<<"Egzamino ivertinimas:"<<std::endl;
        std::cin>>egz;
        while(std::cin.fail() || egz>10 || egz<0 || egz!=(int)egz)
        {
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        std::cout << "Ivyko klaida.  Iveskite skaiciu(0-10): ";
        std::cin >> egz;
        }
        studentas[i].egz=(int)egz;
        std::cout<<"Iveskite namu darbu ivertinimus (jei baigete rasykite -1)"<<std::endl;
        while(true)
        {
            std::cin>>paza;
            while(std::cin.fail()||paza>10||paza<-1|| paza!=(int)paza)
            {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Blogai. Iveskite namu darbu ivertinimus (jei baigete rasykite -1)";
                std::cin >> paza;
            }
          if(paza==-1)
                break;
          else
          {
              skaic=studentas[i].n;
              studentas[i].paz[studentas[i].n]=paza;
              studentas[i].suma=studentas[i].suma+paza;
              studentas[i].n++;
          }

        }
        }

        studentas[i].vidurkis=studentas[i].suma/studentas[i].n;
        if(pasirinkimas == 0)
        {
            studentas[i].galutinis=(0.4*studentas[i].vidurkis)+(0.6*studentas[i].egz);
        }
        else
        {
            rikiavimas(studentas,zmones);
            if(studentas[i].n%2==0)
            {
                medvid=studentas[i].n/2;
                studentas[i].galutinis = 0.4*(1.0*(studentas[i].paz[medvid-1]+studentas[i].paz[medvid])/2)+0.6*studentas[i].egz;
            }
            else
            {
                medvid=studentas[i].n/2+1;
                studentas[i].galutinis = 0.4*(studentas[i].paz[medvid-1])+0.6*(studentas[i].egz);

            }
        }


    }






    std::cout<<"Vardas                 Pavarde              Galutinis Ivertinimas"<<std::endl;
    for(int i=0;i<zmones;i++)
    {
        std::cout<<studentas[i].vardas<<"           "<<studentas[i].pavarde<<"             "<<std::fixed<<std::setprecision(2)<<studentas[i].galutinis<<std::endl;
    }


return 0;
}
void rikiavimas(mokinys studentas[], int zmones) //rikiavimo funkcija
{
    for(int z=0;z<zmones;z++)
    {
        for(int i=0;i<studentas[z].n-1;i++)
        for(int j=i+1;j<studentas[z].n;j++)
            if(studentas[z].paz[i]>studentas[z].paz[j])
            {
                swap(studentas[z].paz[i], studentas[z].paz[j]);

            }
    }


}
