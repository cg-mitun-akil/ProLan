#include <iostream>
#include<fstream>
using namespace std;
class Game
{
    public:
    char Question[100];
    char Answer[25];

    void Input()
    {
        cout<<"Enter Question: ";
        cin.getline(Question,100);
        cout<<"Enter Answer: ";
        cin.getline(Answer,25);
        cout<<endl;
    }
};

int main()
{
    Game G;
    ofstream fout("Game.dat",ios::out|ios::binary);
    for(int i=0;i<10;i++)
    {
        G.Input();
        fout.write((char*)&G,sizeof(G));
    }

    fout.close();

    cout<<endl<<endl;
    cout<<"--------------------------------------------";
    cout<<endl<<endl;
    cout<<"Q&A in File 'Game.dat' :";
    cout<<endl<<endl;

    ifstream fin("Game.dat",ios::in|ios::binary);

    while(fin)
    {
        fin.read((char*)&G,sizeof(G));
        cout<<"Question: "<<G.Question<<endl;
        cout<<"Answer: "<<G.Answer;
        cout<<endl<<endl;

    }

    cout<<endl;
    cout<<"--------------------------------------------";
    cout<<endl<<endl;
    fin.close();
    return 0;

}
