    #include <iostream>
    #include <string>
    using namespace std;

    class student {
        int roll_no;
        string name;

    public:
        void getdata();
        void sort(student s[], int n); 
        void display(student s[], int n); 
    };

    void student::getdata() {
        cout << "\nEnter your Roll No : " << endl;
        cin >> roll_no;
        cout << "\nEnter your name: " << endl;
        cin >> name;
    }

    void student::sort(student s[], int n) {
        for (int i = 1; i < n; i++) {
            student key = s[i];
            int j = i - 1;
            while (j >= 0 && s[j].roll_no > key.roll_no) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = key;
        }
    }

    void student::display(student s[], int n) {
        for (int i = 0; i < n; i++) {
            cout << "Name : " << s[i].name << endl;
            cout << "Roll No : " << s[i].roll_no << endl; 
            cout << "\n";
        }
    }

    int main() {
        
        int n,choice;
        cout<<"\nEnter the number of entries : "<<endl;
        cin>>n;

        student s[n],temp;
            do{
            cout<<"\nPlease enter a choice : \n1.Add data \n2.Sort data \n3.Display data \n4.Exit"<<endl;
            cin>>choice;		
            switch(choice){
                case 1: 
                    for(int i=0;i<n;i++){
                    s[i].getdata();
                }
                break;
                case 2:
                    temp.sort(s,n);
                    cout<<"\nData sorted successfully"<<endl;
                    break;

                case 3:
                    cout<<"\nDisplaying Data : "<<endl;
                    temp.display(s,n);
                    break;
                case 4:
                    cout<<"\nSuccessfully Exited"<<endl;
                break;
                default:
                    cout<<"\nPlease enter a valid choice"<<endl;
            }
            }
            while(choice!=4);
            
        return 0;
    }