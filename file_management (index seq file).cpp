    /*
    Company maintains employee information as employee ID, name,
    designation and salary. Allow user to add, delete information of
    employee. Display information of particular employee. If employee
    does not exist an appropriate message is displayed. If it is, then the
    system displays the employee details. Use index sequential file to
    maintain the data.
    */
    #include<iostream>
    #include<fstream>
    #include<string.h>
    using namespace std;

    class employee{

        typedef struct emp{
            int emp_id,salary;
            char emp_name[10],designation[10];

        }emp;
        emp record;
        public:
            void create();
            void display();
            int search();
            void Delete();
    };

    void employee :: create(){
        char ans;
        ofstream fout;
        fout.open("emp.dat",ios::out|ios::binary);
        
        do{
            cout<<"Enter name of the employee : ";
            cin>>record.emp_name;
            cout<<"Enter ID of the employee : ";
            cin>>record.emp_id;
            cout<<"Enter salary of the employee : ";
            cin>>record.salary;
            cout<<"Enter designation of the employee : ";
            cin>>record.designation;
            fout.write((char *)&record,sizeof(record))<<flush;
            cout<<"\n\tDo You Want to Add More Records: ";
            cin>>ans;
        }while(ans=='y'||ans=='Y');
        fout.close();
    }

    void employee :: display(){
        ifstream fin;
        fin.open("emp.dat",ios::in|ios::binary);
        fin.seekg(0,ios::beg);
        cout<<"\n\tThe Content of File are:\n";
        cout<<"\n\tEmployee Id\tName\tSalary\tDesignation";
        while(fin.read((char *)&record,sizeof(record)))
        {
            if(record.emp_id!=-1)
            cout<<"\n\t"<<record.emp_id<<"\t"<<record.emp_name<<"\t"<<record.salary<<"\t"<<record.designation;
        }
        fin.close();
    }

    int employee :: search(){
        int id,i=0;
        ifstream fin;
        fin.open("emp.dat",ios::in|ios::binary);
        fin.seekg(0,ios::beg);
        cout<<"Enter Employee id : ";
        cin>>id;
        while(fin.read((char * )&record,sizeof(record))){
            if(record.emp_id==id){
                cout<<"\n\tRecord Found...\n";
                cout<<"\n\tID\tName\tSalary\tDesignation";
                cout<<"\n\t"<<record.emp_id<<"\t"<<record.emp_name<<"\t"<<record.salary<<"\t"<<record.designation;
                return i;
            }
            else{
                cout<<"Sorry record not found..Try again!!";
            }
            i++;
        }      
        fin.close();
        return 0;
    }

    void employee :: Delete(){
        int id;
        id = search();
        fstream f;
        f.open("emp.dat",ios::in|ios::out|ios::binary);
        f.seekg(0,ios::beg);
        if(id==0){
            cout<<"Record not found..!!";
        }
        int offset = id*sizeof(record);
        f.seekp(offset);
        record.emp_id=-1;
        strcpy(record.emp_name,"NULL");
        record.salary = 0;
        strcpy(record.designation,"NULL");
        f.write((char *)&record,sizeof(record));
        f.seekg(0);
        f.close();
        cout<<"\n\tRecord Deleted";
    }
    int main()
    {
        employee obj;
        int ch,key;
        char ans;
        do
        {
            cout<<"\n\t***** Employee Information *****";
            cout<<"\n\t1. Create\n\t2. Display\n\t3. Search\n\t4. Delete\n\t5. Exit";
            cout<<"\n\t..... Enter Your Choice: ";
            cin>>ch;
            switch(ch)
            {
                case 1: obj.create();
                    break;
                case 2:	obj.display();
                    break;
                case 3: obj.search();
                    break;
                case 4: obj.Delete();
                    break;
                case 5:
                    break;
            }
            cout<<"\n\t..... Do You Want to Continue in Main Menu: ";
            cin>>ans;
        }while(ans=='y'||ans=='Y');
    return 1;
    }