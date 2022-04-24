/*
	
	Programme 	: COVID-19 Patient Management System
	Date		: 22/01/2022
	Author		: Jayasooriya K.P.  E/18/153

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//define the structure 
typedef struct {
    int NIC;
    char fullName [50];
    int age;
    char gender [10];
    char admissionDate [20];
} patient_t;

//define the total number of patients. (Can modify when needed)
int totalPatients = 10000;
patient_t s[10000];



int main()
{   
    //Function prototype (Function declaration)
    void add (patient_t s[] , int numberOfPatients);
    void print (patient_t s[] , int patientNo);
    void delete (patient_t s[] , int patientNo,int numberOfPatients);
    void printAll (patient_t s[] , int numberOfPatients);
    int nicToPatientNo (patient_t s[] , int numberOfPatients);


    int  option;                                            //to select the input option
    int patientNo = 0, start = -1, numberOfPatients = 0 ;   //patientNo - array number of patient ; numberOfPatients - Number of registered patients

    //The UI
    printf("-------------------------------------------------------------------\n");
    printf("COVID-19 PATIENT  MANAGEMENT SYSTEM\n");
    printf("-------------------------------------------------------------------\n");
    printf("0. Quit\n");
    printf("1. Add a Patient Recode\n");
    printf("2. Print a Patient Recode\n");
    printf("3. Print all Patient Recodes\n");
    printf("4. Delete a Patient Recode\n");
    
    printf("-------------------------------------------------------------------\n");
    printf("Enter Option [0-4]\n");
    printf("-------------------------------------------------------------------\n");

    
while (option != 0){
    
    //Print after the 1st time 
    if (start != -1)
    {   printf("\n-------------------------------------------------------------------\n");
        printf("Enter Option [0-4]\n");
        printf("-------------------------------------------------------------------\n");
    }
    start = 0;

    //Select the option
    scanf("%d",&option);       

    //Calling the specific function
    if (option == 0) printf ( "\nThank you for using COVID-19 Patient Management System. See you again! \n");

    else if (option ==1 ) {add (s , numberOfPatients ); numberOfPatients++;}    //numberOfPatients++ to increse the total number of patients

    else if (option ==2 ) print( s, nicToPatientNo (s , numberOfPatients ) );     

    else if (option ==3 ) printAll(s , numberOfPatients);

    else if (option ==4 ){ delete ( s , nicToPatientNo (s , numberOfPatients ) , numberOfPatients  ); numberOfPatients--;}  //numberOfPatients-- to dicrese the total number of patients
    
    else  printf("Invalid  input. Try again! \n") ;                             //print when a wrong option is given


}

}

void add (patient_t s[] , int numberOfPatients){
   
    char first[30];
    char last[30];
    char fullName[50] ;

    
    printf( "Patient's NIC - ");
    scanf(" %d", &s[numberOfPatients].NIC );            //Enter the Patient's NIC
    
    printf("First Name :");                             //Enter the Patient's First name
    scanf("%s",first);
    printf("Last Name :");                              //Enter the Patient's Lsat name
    scanf("%s",last);
  
    strcat(first , " ");                                //Add a space to the end of the first name
    strcat(first , last);                               //Add the last name to first name
    
    strcpy(s[numberOfPatients].fullName , first);       //Assign the full name to the structure 
  
    printf("Patient's age - ");                         //Enter the Patient's age
    scanf(" %d", &s[numberOfPatients].age );            
    printf("Patient's gender - ");
    scanf(" %s", s[numberOfPatients].gender);           //Enter the Patient's gender
    printf( "Patient's admission date (dd/mm/yyyy)- ");
    scanf(" %s", s[numberOfPatients].admissionDate );   //Enter the Patient's admission date

    printf("\nPatient %s sucsucfully added!\n", s[numberOfPatients].fullName);
    return;
}

//Print detail af a patient
void print (patient_t s[] , int patientNo){
    printf( "patient's NIC - %d\npatient's Full Name - %s\npatient's age - %d\npatient's gender - %s\npatient's admission date - %s\n", 
    s[patientNo].NIC, s[patientNo].fullName, s[patientNo].age, s[patientNo].gender, s[patientNo].admissionDate  );
}

//Replase the details from the upper one
void delete (patient_t s[] , int patientNo, int numberOfPatients ){
    for (int i = patientNo ; i <= numberOfPatients ; i++ ){
         s[i] =  s[i+1] ;
    }
    printf("\nSuccessfully deleted\n");
}

//Print all details 
//patient number reffer the possition in s[] ;
void printAll (patient_t s[] , int numberOfPatients){

    for (int j = 0 ; j < numberOfPatients ; j++){
        printf( "patient's No - %d\npatient's NIC - %d\npatient's Full Name - %s\npatient's age - %d\npatient's gender - %s\npatient's admission date - %s\n\n\n", 
        j,s[j].NIC, s[j].fullName, s[j].age, s[j].gender, s[j].admissionDate  );
    }
    printf("All details are printed\n");
}

//Return the patient number (possition in s[]) when the NIC number is given
int nicToPatientNo (patient_t s[] , int numberOfPatients){

    while (1){
        printf("Enter the ID number : ");
            int ID ;
            scanf("%d",&ID);
        
        for (int k = 0; k < numberOfPatients ; k++){
            if (ID == s[k].NIC) return k;
        }
        printf ("Invalid  NIC number. Try again! \n\n");

    }
}