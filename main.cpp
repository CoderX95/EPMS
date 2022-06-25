#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <string.h>
#include <ctime>
#include <conio.h>
#include <stdlib.h>




using namespace std;

const char* hostname = "Localhost";
const char* username = "root";
const char* password = "";
const char* database = "epms";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;
void counter_ut(string, MYSQL*);
void time_ut(string, MYSQL*);
void exit_ut(string, MYSQL*);
void break_ut(string, MYSQL*);
int main();void Q1(MYSQL*);
void Q2(MYSQL*);
void Q3(MYSQL*);
void Q4(MYSQL*);
void Q5(MYSQL*);
void Q6(MYSQL*);
void centerstring(char* s);

MYSQL* connectdatabase(){

     MYSQL* conn;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,hostname,username,password,database,port,unixsocket,clientflag);
     if(conn){
        cout<<""<<endl;
        return conn;
     }
     else{
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
        return conn;
    }

}

checkID(string emp, MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;
    stringstream ss;
    char admin[5];
    int choise;
    ss << "SELECT name,admin FROM emp_data WHERE empid = '"+emp+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x =mysql_num_rows(res);
    row = mysql_fetch_row(res);
    strcpy(admin,row[1]);
        if(x > 0)
        {
            if(admin[0]=='1'){
                cout<<"\nWelcome "<<row[0]<<" you are Admin";
                counter_ut(emp,conn);
                time_ut(emp,conn);
                do{
                ABC:
                getch();
                system("cls");
                cout<<endl;
                centerstring("You Have Now Entered Wipro Banglore Premises!!!");
                cout<<"\n\n\What do u want to do next :p "<<endl<<endl;
                cout<<"1. How many employees came today ?"<<endl;
                cout<<"2. Did a particular employee come today ?"<<endl;
                cout<<"3. How often did an employee enter into the office ?"<<endl;
                cout<<"4. Which employee moves out of office most number of times ?"<<endl;
                cout<<"5. Name of the employees who are all out for a particular time period. "<<endl;
                cout<<"6. Who all came within a range of IDs: and how often they entered ?"<<endl;
                cout<<"7. Take a Break "<<endl;
                cout<<"8. Exit from premises "<<endl<<endl;
                cout<<"Please Choose : ";
                cin>>choise;
                cout<<endl;
                switch(choise){
                case 1 : Q1(conn);
                         goto ABC;
                         break;
                case 2 : Q2(conn);
                         goto ABC;
                         break;
                case 3 : Q3(conn);
                         goto ABC;
                         break;
                case 4 : Q4(conn);
                         goto ABC;
                         break;
                case 5 : Q5(conn);
                         goto ABC;
                         break;
                case 6 : Q6(conn);
                         goto ABC;
                         break;
                case 7 : break_ut(emp,conn);
                         main();
                         break;
                case 8 : exit_ut(emp,conn);
                         main();
                         break;
                default: cout<<"Invalid Option";
                         choise=0;
                         break;
                    }
                }while(choise==0);

            }
            else{
                cout<<"\nWelcome "<<row[0];
                counter_ut(emp,conn);
                time_ut(emp,conn);
                getch();

                do{
                system("cls");
                cout<<endl;
                centerstring("You Have Now Entered Wipro Banglore Premises!!!");
                cout<<"\n\n\nWhat do u want to do next :p "<<endl<<endl;
                cout<<"1. Take a Break "<<endl;
                cout<<"2. Exit from premises "<<endl<<endl;
                cout<<"Please Choose : ";
                cin>>choise;
                switch(choise){
                case 1 : break_ut(emp,conn);
                         main();
                         break;
                case 2 : exit_ut(emp,conn);
                         main();
                         break;
                default: cout<<"Invalid Option";
                         choise=0;
                         break;
                    }
                }while(choise==0);

            }

        }
        else{
            cout<<"\nEmployee ID not Valid!!!";
        }

}

void counter_ut(string emp,MYSQL* conn){

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    MYSQL_ROW row;
    MYSQL_RES* res;

    int intime[2];
    char buffer[80];
    char buff[15];
    char counter[3];

    intime[0] = local_time->tm_hour;
    intime[1] = local_time->tm_min;
    strftime(buff,sizeof(buff),"%H:%M ",local_time);
    std::string timein(buff);

    cout<<"\nYou entered Wipro premise at : "<<timein<<endl;
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);


    stringstream ss;
    ss << "SELECT date,counter FROM attendance WHERE date = '"+date+"' AND empid = '"+emp+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);

    if(x > 0){

        strcpy(counter,row[1]);
        stringstream geek(counter);
        stringstream ss;
        int i;
        geek >> i;
        i=i+1;
        ostringstream str1;
        str1 << i;
        string character = str1.str();
        ss << "UPDATE `attendance` SET `counter` = '"+character+"' WHERE `date` = '"+date+"' && `empid` = '"+emp+"' ";
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(conn,q);

       }
       else{

        stringstream ss;
        ss << "INSERT INTO attendance(empid, date, counter) VALUES ('"+emp+"','"+date+"','1')";
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(conn,q);

       }

}


void time_ut(string emp, MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    int intime[2];
    char buffer[80];
    char buff[15];
    char counter[3];

    intime[0] = local_time->tm_hour;
    intime[1] = local_time->tm_min;
    strftime(buff,sizeof(buff),"%H:%M ",local_time);
    std::string timein(buff);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);

    stringstream in,se;
    in << "INSERT INTO emp_time(empid, intime, date, status) VALUES ('"+emp+"','"+timein+"','"+date+"','IN')";
    string query = in.str();
    const char* q = query.c_str();
    mysql_query(conn,q);

    se << "SELECT date,status FROM emp_time WHERE date = '"+date+"' AND status = 'BREAK' AND empid ='"+emp+"' ORDER BY intime DESC LIMIT 1 ";
    string query1 = se.str();
    const char* q1 = query1.c_str();
    mysql_query(conn,q1);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);

    if(x > 0){

        stringstream ss;
        ss << "UPDATE `emp_time` SET `breaktime` = '"+timein+"' WHERE date = '"+date+"' AND status = 'BREAK' AND empid ='"+emp+"' ORDER BY intime DESC LIMIT 1 ";
        string query = ss.str();
        const char* q = query.c_str();
        mysql_query(conn,q);


    }

}

void exit_ut(string emp, MYSQL* conn){

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    MYSQL_ROW row;
    MYSQL_RES* res;

    int intime[2];
    char buffer[80];
    char buff[15];
    char counter[3];

    intime[0] = local_time->tm_hour;
    intime[1] = local_time->tm_min;
    strftime(buff,sizeof(buff),"%H:%M ",local_time);
    std::string timein(buff);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);


    stringstream se;
    se << "SELECT counter FROM attendance WHERE date = '"+date+"' AND empid = '"+emp+"' ";
    string query1 = se.str();
    const char* q1 = query1.c_str();
    mysql_query(conn,q1);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    strcpy(counter,row[0]);
    stringstream geek(counter);
    stringstream ss;
    int i;
    geek >> i;
    i=i+1;
    ostringstream str1;
    str1 << i;
    string character = str1.str();
    ss << "UPDATE `attendance` SET `counter` = '"+character+"' WHERE `date` = '"+date+"' && `empid` = '"+emp+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);

    stringstream up ;
    up << "UPDATE `emp_time` SET `outtime` = '"+timein+"', `status` = 'OUT' WHERE date = '"+date+"' AND status = 'IN' AND empid ='"+emp+"' ORDER BY intime DESC LIMIT 1 ";
    string query2 = up.str();
    const char* q2 = query2.c_str();
    mysql_query(conn,q2);

    cout<<"\nHi Enjoy ur Remaining time on Earth!!!(tick tock)";

}
void break_ut(string emp , MYSQL* conn){

    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);

    MYSQL_ROW row;
    MYSQL_RES* res;

    int intime[2];
    char buffer[80];
    char buff[15];
    char counter[3];

    intime[0] = local_time->tm_hour;
    intime[1] = local_time->tm_min;
    strftime(buff,sizeof(buff),"%H:%M ",local_time);
    std::string timein(buff);

    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);


    stringstream se;
    se << "SELECT counter FROM attendance WHERE date = '"+date+"' AND empid = '"+emp+"' ";
    string query1 = se.str();
    const char* q1 = query1.c_str();
    mysql_query(conn,q1);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    strcpy(counter,row[0]);
    stringstream geek(counter);
    stringstream ss;
    int i;
    geek >> i;
    i=i+1;
    ostringstream str1;
    str1 << i;
    string character = str1.str();
    ss << "UPDATE `attendance` SET `counter` = '"+character+"' WHERE `date` = '"+date+"' && `empid` = '"+emp+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);

    stringstream up ;
    up << "UPDATE `emp_time` SET `outtime` = '"+timein+"', `status` = 'BREAK' WHERE date = '"+date+"' AND status = 'IN' AND empid ='"+emp+"' ORDER BY intime DESC LIMIT 1 ";
    string query2 = up.str();
    const char* q2 = query2.c_str();
    mysql_query(conn,q2);

    cout<<"\nHi Enjoy ur Break u gotta work real soon!!!";

}

void centerstring(char* s)
{
   int l=strlen(s);
   int pos=(int)((120-l)/2);
   for(int i=0;i<pos;i++)
    cout<<" ";
   cout<<s;

}


int main()
{
    system("cls");
    system("color F0");
    MYSQL* conn;
    conn = connectdatabase();
    string emp;

    centerstring("WIPRO");
    cout<<"\n\nEnter EmpID to Enter the Banglore Wipro Premises : ";
    cin>>emp;
    if(emp!="Exit" || emp!="exit" || emp!="EXIT"){
        checkID(emp,conn);
    }
    return 0;
}




void Q1(MYSQL* conn){

    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT count(empid) FROM attendance WHERE date = '"+date+"' ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);
    if(x > 0){
        cout<<"\nTotal number of employees that are came today are : "<<row[0];
    }else{
        cout<<"\nNo one came today";
    }

}
void Q2(MYSQL* conn){

    string emp;
    cout<<"Enter EmpID to Enter : ";
    cin>>emp;
    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT `name` FROM `emp_data` WHERE `empid`=(SELECT empid FROM attendance WHERE date = '"+date+"' AND empid ='"+emp+"') ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);
    if(x > 0){
        cout<<row[0]<<" is present today.";
    }else{
        cout<<"The Employee did not came today";
    }
}
void Q3(MYSQL* conn){
    string emp;
    cout<<"Enter EmpID to Enter : ";
    cin>>emp;
    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT counter FROM attendance WHERE date = '"+date+"' AND empid ='"+emp+"'";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);
    if(x > 0){
        char counter[3];
        strcpy(counter,row[0]);
        stringstream geek(counter);
        stringstream ss;
        int i;
        geek >> i;
        if(i==1){
            cout<<"\nThe employee entered just once today.";
        }else{
            i=i/2;
            cout<<"\nThe employee entered "<<i<<" times";
        }
    }else{
        cout<<"\nThe Employee did not came today";
    }
}
void Q4(MYSQL* conn){

    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT `name` FROM `emp_data` WHERE `empid`=(SELECT `empid` FROM `attendance` WHERE `date` = '"+date+"' ORDER BY `counter` DESC LIMIT 1) ";
    string query = ss.str();
    const char* q = query.c_str();
    mysql_query(conn,q);
    res = mysql_store_result(conn);
    row = mysql_fetch_row(res);
    my_ulonglong x =mysql_num_rows(res);
    if(x > 0){
        MYSQL_ROW row1;
        MYSQL_RES* res1;
        stringstream ss2;
        ss2 << "SELECT `counter` FROM `attendance` WHERE `date` = '"+date+"' ORDER BY `counter` DESC LIMIT 1";
        string query1 = ss2.str();
        const char* q1 = query1.c_str();
        mysql_query(conn,q1);
        res1 = mysql_store_result(conn);
        row1 = mysql_fetch_row(res1);
        char counter[3];
        strcpy(counter,row1[0]);
        stringstream geek(counter);
        int i;
        geek >> i;
        i=i/2;
        cout<<endl<<row[0]<<" is present today and has been out "<<i<<" times.";

    }else{
        cout<<"\nNo One came today :(";
    }

}
void Q5(MYSQL* conn){
    string start_time,end_time;
    cout<<"Enter start time : ";
    cin>>start_time;
    cout<<"Enter end time : ";
    cin>>end_time;
    cout<<endl;
    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT DISTINCT `emp_time`.`empid`,`emp_data`.`name` FROM `emp_time` INNER JOIN `emp_data`ON `emp_data`.`empid`=`emp_time`.`empid` WHERE `emp_time`.`outtime` >= '"+start_time+"' AND `emp_time`.`breaktime` <= '"+end_time+"' AND `emp_time`.`date` = '"+date+"' AND `emp_time`.`status` LIKE 'BREAK'";
    string query = ss.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn,q);
    if(!qstate){
        res = mysql_store_result(conn);
        my_ulonglong x =mysql_num_rows(res);
        if(x > 0){
            int count = mysql_num_fields(res);
            while(row = mysql_fetch_row(res)){
                for(int i=0;i<count;i++){
                    cout<<"\t"<<row[i];
                }
                cout<<endl;
            }
            cout<<"\nThese all were out during the mentioned time.";
    }else{
        cout<<"\nFailed to find anyone out at the mentioned time period.";
    }
    }else{
        cout<<"Code didnt run";
    }
}
void Q6(MYSQL* conn){
    string start_index,last_index;
    cout<<"Enter first Employee Number : ";
    cin>>start_index;
    cout<<"Enter last Employee Number : ";
    cin>>last_index;
    cout<<endl;
    MYSQL_ROW row;
    MYSQL_RES* res;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    char buffer[80];
    strftime(buffer,sizeof(buffer),"%Y-%m-%d ",local_time);
    std::string date(buffer);
    stringstream ss;
    ss << "SELECT `emp_data`.`name`,`attendance`.`date`,`attendance`.`counter` FROM `attendance` INNER JOIN `emp_data` ON `emp_data`.`empid` = `attendance`.`empid` WHERE `attendance`.`empid` BETWEEN '"+start_index+"' AND '"+last_index+"' AND `attendance`.`date` = '"+date+"' ORDER BY `attendance`.`counter` DESC";
    string query = ss.str();
    const char* q = query.c_str();
    int qstate = mysql_query(conn,q);
    if(!qstate){
        res = mysql_store_result(conn);
        my_ulonglong x =mysql_num_rows(res);
        if(x > 0){
            int count = mysql_num_fields(res);
            while(row = mysql_fetch_row(res)){
                for(int i=0;i<count;i++){

                    if((i+1)%3 == 0){
                        char counter[3];
                        strcpy(counter,row[i]);
                        stringstream geek(counter);
                        int j;
                        geek >> j;
                        if(j==1)
                            j=2;
                        j=j/2;
                        cout<<"\t"<<j;
                    }
                    else
                    cout<<"\t"<<row[i];
                }
                cout<<endl;
            }
            cout<<"\n";
    }else{
        cout<<"\nFailed to find anyone out.";
    }
    }else{
        cout<<"Code didnt run";
    }

}

