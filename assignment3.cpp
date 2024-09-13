#include<iostream>
using namespace std;

class song
{
        string name;
        song * next;
        song * header = NULL;

    public:
        void insertatEnd(){
            string val;
            song * nn;
            nn = new song;

            cout<<"\nEnter the name of the song  : ";
            getline(cin,nn->name);
            nn -> next = NULL;
            
            if(header == NULL){
                header = nn;
            }

            else
            {
                song * temp;
                temp = header;

                while(temp -> next != NULL)
                {
                    temp = temp -> next;
                }

                temp -> next = nn;
            }
        }

        void print(string s){
            song * temp;
            temp = header;
            int count = 1;

            cout<<"\nDisplaying Playlist "<<s<<" : "<<endl;

            while(temp!=NULL){
                cout<<count<<". "<<temp->name<<endl;
                temp = temp -> next;
                count++;
            }
        }

        void deleteSong(){
            if(header==NULL){
                cout<<"\nYour playlist does not have any song"<<endl;
                return;
            }

            song * temp = header;
            string del;
            song * p;
            cout<<"\nEnter the name of the song you want to delete : ";
            getline(cin,del);

            if(header->name==del){
                header=header->next;
                cout<<"\nSong deleted successfully"<<endl;
                delete temp;
                return;
            }

            while(temp->name!=del){
                p = temp;
                temp = temp->next;
                if(temp==NULL){
                    cout<<"\nSong does not exist in the playlist"<<endl;
                    return;
                }
            }
                p->next = temp->next;
                delete temp;
                cout<<"\nSong deleted successfully"<<endl;      
        }
    
    void playSong(){
        if(header==NULL){
            cout<<"\nYour playlist does not have any song"<<endl;
            return;
        }

        string a;
        song * temp = header;
        cout<<"\nEnter the name of the song you want to play : ";
        getline(cin,a);

        while(temp->name!=a){
            temp = temp->next;
            if(temp==NULL){
                cout<<"\nSong does not exist in your playlist"<<endl;
                rcheturn;
            }
        }

        cout<<"\nCurrently Playing : "<<a<<endl;
    } 

};

int main(){
    
    song s;
    int n,i,c,b;
    string a,p;
    cout<<"\nEnter the name of the playlist : ";
    getline(cin,p);
    cout<<"\nEnter the number of songs : ";
    cin>>n;
    cin.ignore();

    while(c!=4){
            cout<<"\nEnter your choice \n1.Add songs \n2.Delete a song \n3.Print the playlist \n4.Play a Song \n5.Exit"<<endl;
            cin>>c;
            cin.ignore();
            switch(c)
            {
                case 1:
                    for(i=0;i<n;i++){
                        s.insertatEnd(); 
                    }
                    break;

                case 2:
                    s.deleteSong();
                    break;

                case 3:
                    s.print(p);
                    break;

                case 4:
                    s.playSong();
                    break;

                case 5:
                    cout<<"\nExited successfully"<<endl;
                    break;

                default:
                    cout<<"\nPlease enter a valid choice"<<endl;
            }
    }

    return 0;
}

