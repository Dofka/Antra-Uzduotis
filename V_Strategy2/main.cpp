
#include "header.h"

int main ()
{
    ifstream InFile;
    ofstream outFile;
    int Number_of_files=5;
    string filename, nereikalingas;
    int failoSK=1000;
    int k, paz, egz, suma=0;
    vector <studentai> mok;
    vector <studentai> kietiakai;
    vector <studentai> vargsiukai;
    vector<int>::iterator it;

  for (int i=0;i<Number_of_files;i++)
  {
      clock_t startB, endB;
        startB = clock();
        filename="file_" + IntToStr(failoSK) +".txt";

        cout<< filename << "  \n";

        outFile.open(filename.c_str());
        outFile.width(15);
        outFile<<"Vardas";
        outFile.width(15);
        outFile<<"Pavarde";
        outFile.width(15);
        outFile<<"ND1";
        outFile.width(15);
        outFile<<"ND2";
        outFile.width(15);
        outFile<<"ND3";
        outFile.width(15);
        outFile<<"ND4";
         outFile.width(15);
        outFile<<"ND5";
         outFile.width(15);
        outFile<<"Egz."<<endl;;
        for(int i=0;i<failoSK;i++)
        {
            outFile.width(15);
            outFile<<"Vardenis"<<i+1;
            outFile.width(15);
            outFile<<"Pavardenis"<<i+1;

            for(int i=0;i<5;i++)
            {
                k = rand()%11;
                outFile.width(15);
                outFile<<k;
            }
            k = rand()%11;
            outFile.width(15);
            outFile<<k;
            outFile<<endl;

        }

        outFile.close();
        InFile.open(filename.c_str());
        clock_t start, end;
        start = clock();
        InFile>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas>>nereikalingas;
        for(int i=0;i<failoSK;i++)
        {
            mok.push_back(studentai());
            InFile>>mok[i].vardas>>mok[i].pavarde;
           // cout<<mok[i].vardas<<endl;

            for(int t=0;t<5;t++)
            {
                InFile>>paz;
                suma+=paz;
            }
            InFile>>egz;
            mok[i].galutinis=((1.0*suma/5)*0.4)+(0.6*egz);
           // cout<<mok[i].galutinis<<endl;
            suma=0;


        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" nuskaityti failus uztruko: "<< time_taken<< " s"<<endl;
        sort(mok.begin(),mok.end(),lyginimas);
        clock_t start1, end1;
        start1 = clock();
        filename="file_" + IntToStr(failoSK) +"kietiakai" + ".txt";
        outFile.open(filename.c_str());
       int sk=0;
        for(int i=0;i<failoSK;i++)
        {


            //cout<<mok[i].vardas<<endl;
                if(mok[i].galutinis >=5.0)
                {
                    kietiakai.push_back(studentai());
                    kietiakai[sk].vardas=mok[i].vardas;
                    kietiakai[sk].pavarde=mok[i].pavarde;
                    kietiakai[sk].galutinis=mok[i].galutinis;
                    outFile.width(15);
                    outFile<<kietiakai[sk].vardas;
                    outFile.width(15);
                    outFile<<kietiakai[sk].pavarde;
                    outFile.width(15);
                    outFile<<kietiakai[sk].galutinis<<endl;
                //cout<<" "<<mok[i].galutinis<<endl;
                    sk++;
                }


        }
        mok.resize(failoSK-sk);
        int failas=failoSK-sk;
        outFile.close();
        end1 = clock();
        double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" Isskirti i grupe kieti uztruko: "<< time_taken1<< " s"<<endl;
        clock_t start2, end2;
        start2 = clock();

        filename="file_" + IntToStr(failoSK) +"vargsiukai" + ".txt";
        outFile.open(filename.c_str());
          int ks=0;
        for (int i = 0; i<failas; i++)
        {


                    outFile.width(15);
                    outFile<<mok[i].vardas;
                    outFile.width(15);
                    outFile<<mok[i].pavarde;
                    outFile.width(15);
                    outFile<<mok[i].galutinis<<endl;
                //cout<<" "<<mok[i].galutinis<<endl;
                ks++;


        }
        outFile.close();
        end2 = clock();
        double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" Isskirti i grupe nepasisekeliai uztruko: "<< time_taken2<< " s"<<endl;
        failoSK=failoSK*10;
        cout<<"veikia"<<endl;

        InFile.close();
        endB = clock();
        double time_takenB = double(endB - startB) / double(CLOCKS_PER_SEC);
        cout <<failoSK<<" BENDRAS VEIKIMAS"<< time_takenB<< " s"<<endl;
  }


  return 0;
}
