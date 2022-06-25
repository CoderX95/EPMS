# EPMS
Employee Presence Monitoring System (EPMS) to monitor effective working time of an employee.

# Problem Statement
WIPRO — Bangalore wants to devise an Employee Presence Monitoring System (EPMS) to monitor effective working time of an employee. Apart from details such as Emp_ID, Age, address, contact number etc., each employee will have a special counter. First time an employee enters into the
office, the counter is set to 1. From then onwards, each time an employee leaves the office premises for tea break or lunch break, and enters back this id is incremented You can figure out that when is Odd on a day, he is in the office premises and even when he is out. EPMS also records the number of breaks and total duration of the break in a day. The organization uses this data to perform the following analytics: 

1.	How many employees came today? 
2.	Did a particular employee come today? 
3.	How often did an employee enter into the office? 
4.	Which employee moves out of office most of times? 
5.	Name of the employees who are all out for a particular time period 
6.	Who all came within a range of IDs, and how often they entered?

#	Software Requirements:
1. CodeBlocks v14.01 or Above.
2. Dev C++ v5.0 or Above.
3. XAMPP v3.0.0 or Above for the MySQL.
4. MySQL Libraries and DLL’s (Provided in the Folder).

#	Hardware Requirements:
1. Processor: Intel Pentium/ AMD FX or Higher.
2. 1 GB RAM or higher.
3. 160 GB or more Hard Drive or Higher.
4. Minimum 200 MB of available Space.

# Implementation Steps
1.	Install CodeBlocks, Dev C++ and XAMPP
Code Block -> http://www.codeblocks.org/downloads
Dev C++ -> https://sourceforge.net/projects/orwelldevcpp/
XAMPP -> https://www.apachefriends.org/download.html
2.	Open the mysql file.
3.	Copy all the files in mysql\mysqlheaders and save them to C:\Program Files (x86) \Dev-Cpp\MinGW64\include.
4.	Copy the file present in mysql\libmysql.a and save the file to C:\Program Files (x86) \Dev-Cpp\MinGW64\lib.
5.	Open CodeBlocks and go to Settings > Compiler > Linker Settings and choose Add button and locate the C:\Program Files (x86) \Dev-Cpp\MinGW64\lib\libmysql.a and Settings >  Compiler > Search Directories and chose Add button and locate C:\Program Files (x86) \Dev-Cpp\MinGW64\include.
6.	Open XAMPP Control Panel and then start Apache and MySQL services (You can check if your MySQL is working or not by searching localhost/phpMyAdmin/ on any browser).
7.	Now open CodeBlocks and choose open an existing project and choose EPMS.prjoectfile from EMPS Folder.
8.	Now, go to the build and run button on the task bar.
9.	The program will Compile + Run and will open in a New Window.
