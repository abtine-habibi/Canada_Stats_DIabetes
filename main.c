#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*------------------------REMOVE QUOTES FUNTION------------------------------*/
void remove_quotes(char str[]) {
    int strcount = 0;
    for (int i = 0; str[i] != '\0'; i++) //As long as the string does not terminate the code runs
    {
        if (str[i] != '"') //If the character in the string is not a quotation mark it runs 
        {
            str[strcount] = str[i]; //Copies data
            strcount++; //Separate count to prevent spaces in the string
        }
    }
    str[strcount] = '\0'; // terminate the string
}
/*---------------------------------------------------------------------------*/

/*-----------------------PROVINCIAL AVERAGE FUNTION--------------------------*/
double p_average(double percent[]) //Provincial average
{
  double avg, sum = 0, n = 0;
  
  for (int i = 0; i <= 42; i++)
  {
    if (percent[i] == 0)
    {
    }
    else
    {
    sum += percent[i];
    n++;
    }
  }
  avg = sum/n;
  return avg;
}
/*---------------------------------------------------------------------------*/

/*----------------------YEARLY AVERAGE FUNCTION------------------------------*/
double  y_average(double percent[], double year[], double *a, double *b, double *c, double *d, double *e, double *f, double *g) //Calculates yearly average 
{
  double sum[7] = {0}; // initialize all sums to 0
  double count[7] = {0}; // initialize all counts to 0
  double average[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (percent[i] == 0)
    {
    }
    else{
    int index = year[i] - 2015; // calculate the index for the current year
    sum[index] += percent[i]; // accumulate the sum for the current year
    count[index]++; // increment the count for the current year
    }
  }

  // calculate the averages for all years
  for (int i = 0; i <= 7; i++)
  {
    average[i] = sum[i] / count[i];
  }

  printf(" 2015: %.2lf%%\n 2016: %.2lf%%\n 2017: %.2lf%%\n 2018: %.2lf%%\n 2019: %.2lf%%\n 2020: %.2lf%%\n 2021: %.2lf%%\n", average[0], average[1], average[2], average[3], average[4], average[5], average[6]); //Prints the values for the user
*a = average[0]; 
*b = average[1];
*c = average[2];  
*d = average[3]; 
*e = average[4]; 
*f = average[5]; 
*g = average[6]; 
  
  return (0);
}
/*---------------------------------------------------------------------------*/

/*-------------YEARLY AVERAGE FUNCTION, PRINT TO FILE------------------------*/
double print_y_average(double cpercent[], double cyear[], double opercent[], double oyear[], double apercent[], double ayear[], double qpercent[], double qyear[], double bcpercent[], double bcyear[]) //Calculates yearly average for and prints into data file for all provinces + canada 
{
  //------------------FOR CANADA------------------------//
  double csums[7] = {0}; // initialize all sums to 0
  double ccounts[7] = {0}; // initialize all counts to 0
  double caverages[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (cpercent[i] == 0)
    {
    }
    else{
    int cindex = cyear[i] - 2015; // calculate the index for the current year
    csums[cindex] += cpercent[i]; // accumulate the sum for the current year
    ccounts[cindex]++; // increment the count for the current year
    }
  }


//------------------FOR ONTARIO------------------------//
  double osums[7] = {0}; // initialize all sums to 0
  double ocounts[7] = {0}; // initialize all counts to 0
  double oaverages[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (opercent[i] == 0)
    {
    }
    else{
    int oindex = oyear[i] - 2015; // calculate the index for the current year
    osums[oindex] += opercent[i]; // accumulate the sum for the current year
    ocounts[oindex]++; // increment the count for the current year
    }
  }

//------------------FOR ALBERTA------------------------//
  double asums[7] = {0}; // initialize all sums to 0
  double acounts[7] = {0}; // initialize all counts to 0
  double aaverages[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (apercent[i] == 0)
    {
    }
    else{
    int aindex = ayear[i] - 2015; // calculate the index for the current year
    asums[aindex] += apercent[i]; // accumulate the sum for the current year
    acounts[aindex]++; // increment the count for the current year
    }
  }
  
//------------------FOR QUEBEC------------------------//
  double qsums[7] = {0}; // initialize all sums to 0
  double qcounts[7] = {0}; // initialize all counts to 0
  double qaverages[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (qpercent[i] == 0)
    {
    }
    else{
    int qindex = qyear[i] - 2015; // calculate the index for the current year
    qsums[qindex] += qpercent[i]; // accumulate the sum for the current year
    qcounts[qindex]++; // increment the count for the current year
    }
  }

//------------------FOR BC------------------------//
  double bcsums[7] = {0}; // initialize all sums to 0
  double bccounts[7] = {0}; // initialize all counts to 0
  double bcaverages[7]; // declare an array to store the averages

  for (int i = 0; i < 1000; i++)
  {
    if (bcpercent[i] == 0)
    {
    }
    else{
    int bcindex = bcyear[i] - 2015; // calculate the index for the current year
    bcsums[bcindex] += bcpercent[i]; // accumulate the sum for the current year
    bccounts[bcindex]++; // increment the count for the current year
    }
  }

  //----------------------------------------------//
  
  for (int i = 0; i <= 7; i++) // fills average data for each province into array
  {
    caverages[i] = csums[i] / ccounts[i];
    oaverages[i] = osums[i] / ocounts[i];
    aaverages[i] = asums[i] / acounts[i];
    qaverages[i] = qsums[i] / qcounts[i];
    bcaverages[i] = bcsums[i] / bccounts[i];
  }
  FILE *out5 = fopen ("plotq5.data", "w"); // output file

 fprintf(out5, " 2015: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2016: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2017: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2018: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2019: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2020: %.2lf %.2lf %.2lf %.2lf %.2lf\n 2021: %.2lf %.2lf %.2lf %.2lf %.2lf\n", caverages[0], oaverages[0], aaverages[0], qaverages[0], bcaverages[0], caverages[1], oaverages[1], aaverages[1], qaverages[1], bcaverages[1], caverages[2], oaverages[2], aaverages[2], qaverages[2], bcaverages[2], caverages[3], oaverages[3], aaverages[3], qaverages[3], bcaverages[3], caverages[4], oaverages[4], aaverages[4], qaverages[4], bcaverages[4], caverages[5], oaverages[5], aaverages[5], qaverages[5], bcaverages[5], caverages[6], oaverages[6], aaverages[6], qaverages[6], bcaverages[6]); //Prints the values for the user in a data file table
  fclose(out5);
 
  return 0;
}
/*---------------------------------------------------------------------------*/

/*----------------------------AGE AVERAGE FUNCTION---------------------------*/
double a_average(char *age[], double percent[]) {
    double avg35to49 = 0, avg50to64 = 0, avg65andOver = 0;
    double count35to49 = 0, count50to64 = 0, count65andOver = 0; //Intialize sums as 0

    for (int i = 0; age[i] != NULL; i++) { //Runs until there is no more ages in the array
      if (percent[i] == 0) //If value is blank it does not count it in the calculation
      {
      }
      else
      {
        if (strcmp(age[i], "35 to 49 years") == 0) { //Checks what string it is using strcmp which checks whether two strings are the same and returns an integer value of 0 (true) or 1 (false)
            avg35to49 += percent[i]; //Sums up the values
            count35to49++; //Determines the number of values
        } else if (strcmp(age[i], "50 to 64 years") == 0) {
            avg50to64 += percent[i];
            count50to64++;
        } else if (strcmp(age[i], "65 years and over") == 0) {
            avg65andOver += percent[i];
            count65andOver++;
        }
      }
    }
  avg35to49 = avg35to49/count35to49; //Calculates averages
  avg50to64 = avg50to64/count50to64; 
  avg65andOver = avg65andOver/count65andOver; 
    printf("Average for age group '35 to 49 years': %.2lf%%\n", avg35to49); //Prints averages
    printf("Average for age group '50 to 64 years': %.2lf%%\n", avg50to64);
    printf("Average for age group '65 years and over': %.2lf%%\n\n", avg65andOver);

    return 0;
}
/*---------------------------------------------------------------------------*/

/*-------------------AGE AVERAGE FUNCTION, PRINT TO FILE---------------------*/
double print_a_average(char *age[], double percent[]) {
    double avg35to49 = 0, avg50to64 = 0, avg65andOver = 0;
    double count35to49 = 0, count50to64 = 0, count65andOver = 0; //Intialize sums as 0

    for (int i = 0; age[i] != NULL; i++) { //Runs until there is no more ages in the array
      if (percent[i] == 0) //If value is blank it does not count it in the calculation
      {
      }
      else
      {
        if (strcmp(age[i], "35 to 49 years") == 0) { //Checks what string it is using strcmp which checks whether two strings are the same and returns an integer value of 0 (true) or 1 (false)
            avg35to49 += percent[i]; //Sums up the values
            count35to49++; //Determines the number of values
        } else if (strcmp(age[i], "50 to 64 years") == 0) {
            avg50to64 += percent[i];
            count50to64++;
        } else if (strcmp(age[i], "65 years and over") == 0) {
            avg65andOver += percent[i];
            count65andOver++;
        }
      }
    }
  avg35to49 = avg35to49/count35to49; //Calculates averages
  avg50to64 = avg50to64/count50to64; 
  avg65andOver = avg65andOver/count65andOver; 
    FILE *out6 = fopen ("plotq6.data", "w"); // output file
    fprintf(out6, "35-49 %.2lf\n", avg35to49); //Prints averages
   fprintf(out6, "50-64 %.2lf\n", avg50to64);
    fprintf(out6, "65+ %.2lf\n\n", avg65andOver);
  fclose(out6);
    return 0;
}
/*---------------------------------------------------------------------------*/

/*------------------GREATER THAN NATIONAL FUNCTION---------------------------*/
char* greatercan(double percent, char name[30], double navg) //Function that determines whether a province has a greater average than the national average it acceps a percent and string that represents the name of the province
{
  char* greater = malloc(100 *sizeof(char)); //Allocates memory for string 

  if (percent > navg) //10.87 is the value of the canadian average (navg)
  {
    sprintf(greater, "The province %s has a greater average than the national average\n\n", name); //Copies content of string to greater and has a variable which is the name of the province so it can be used for any province
  }
  else 
  {
    sprintf(greater, "The province %s has a lower average than the national average\n\n", name);
  }
  
  return greater; //Prints a statement
}
/*---------------------------------------------------------------------------*/

/*----------------------SORT PROVINCE-YEAR AVERAGES--------------------------*/
void sort_string_and_double(double d[], char* strings[], const int n) {//Function that sorts array and moves string along with it
   
  for(int i = 0; i < n - 1; i++) //Sorts an array in descending order
  {
    for(int j = i +1; j < n; j++)
    {
      if(d[i] < d[j]) //If value of the element in the right lower than they switch
      {
        double tempd = d[i];
        d[i] = d[j]; 
        d[j] = tempd;

        char* temps = strings[i]; //Switches the string 
        strings[i] = strings[j];
        strings[j] = temps;
      }
    }
  }
}
/*---------------------------------------------------------------------------*/

/*-----------------------------MAIN FUNCTION---------------------------------*/
int main(void) {

  char *c_name[1000], *c_age[1000], *c_sex[1000]; //Arrays that repersent the provinces, the reason the character arrays are pointers is so a single string is able to point to one point in the array (no need for 2d arrays)
  double c_percentage[1000], c_year[1000]; //Arrays for values
  
  char *o_name[1000], *o_age[1000], *o_sex[1000];
  double o_percentage[1000], o_year[1000];

  char *a_name[1000], *a_age[1000], *a_sex[1000];
  double a_percentage[1000], a_year[1000];

  char *q_name[1000], *q_age[1000], *q_sex[1000];
  double q_percentage[1000], q_year[1000];

  char *bc_name[1000], *bc_age[1000], *bc_sex[1000];
  double bc_percentage[1000], bc_year[1000];

  int a_count = 0, c_count = 0, o_count = 0, q_count = 0, bc_count = 0; //Intialize the count of the provinces as 0 for sorting the data

    FILE *statscan_diabetes = fopen("statscan_diabetes.csv", "r"); //Opens the file
    if (statscan_diabetes == NULL)
    {
        printf("Error Opening File. Please check directory location and if the proper file is downloaded."); //Error Message
        return 1;
    }

    char temp[1000], *temp_province[1000], *temp_age[1000], *temp_sex[1000], *temp_percentage[1000], *temp_year[1000]; //Arrays to sort data into (Can be sorted by province if we want)

    char *token;
    int linecount = 0, i = 0;
    fgets(temp, 1000, statscan_diabetes); //Gets rid of the first line in the CSV file
    linecount++;

    while (fgets(temp, 1000, statscan_diabetes) != NULL /*Reads until the end of file*/)
    {
        token = strtok(temp, ","); //Separates the data based on the position of the commas as CSV means Comma Separated Values
        while (token != NULL) //While expression is still valid 
        {
            if (i == 0) //Puts data into proper array based on position 
            {
                temp_year[linecount] = strdup(token);
                remove_quotes(temp_year[linecount]); // pass the string to remove_quotes
            }
            else if (i == 1)
            {
                temp_province[linecount] = strdup(token);
                remove_quotes(temp_province[linecount]); // pass the string to remove_quotes
            }
            else if (i == 3)
            {
                temp_age[linecount] = strdup(token);
                remove_quotes(temp_age[linecount]); // pass the string to remove_quotes
            }
            else if (i == 4)
            {
                temp_sex[linecount] = strdup(token);
                remove_quotes(temp_sex[linecount]); // pass the string to remove_quotes
            }
            else if (i == 13)
            {
                temp_percentage[linecount] = strdup(token);
                remove_quotes(temp_percentage[linecount]); // pass the string to remove_quotes
            }
            token = strtok(NULL, ","); //Resets the value of token to strtok which separates based on position of comma
            i++;
        }
        i = 0; //resets comma/column position
        linecount++; //Increases linecount to assign string to next position in array
    }
    
    fclose(statscan_diabetes); //Closes file

      for (int i = 1; i < 250; i++) //Sorts temporary data into proper province
      {
        if (temp_province[i] != NULL) //Reads until nothing is left 
        {
            if (strcmp(temp_province[i], "Canada (excluding territories)") == 0)  //Compares the province name using strcmp and if returns 0 (true) then it does the actions below
            {
                c_name[c_count] = "Canada"; //Allows for a shorter string name
                c_age[c_count] = temp_age[i]; //Copies string 
                c_sex[c_count] = temp_sex[i]; //Copies string
                c_percentage[c_count] = atof(temp_percentage[i]); //Converts string to double value
                c_year[c_count] = atof(temp_year[i]); //Converts string to double value
                c_count++;
            }
            else if (strcmp(temp_province[i], "Ontario") == 0) 
            {
                o_name[o_count] = "Ontario";
                o_age[o_count] = temp_age[i];
                o_sex[o_count] = temp_sex[i];
                o_percentage[o_count] = atof(temp_percentage[i]);
                o_year[o_count] = atof(temp_year[i]);
                o_count++;
            }
            else if (strcmp(temp_province[i], "Alberta") == 0) 
            {
                a_name[a_count] = "Alberta";
                a_age[a_count] = temp_age[i];
                a_sex[a_count] = temp_sex[i];
                a_percentage[a_count] = atof(temp_percentage[i]);
                a_year[a_count] = atof(temp_year[i]);
                a_count++;
            }
            else if (strcmp(temp_province[i], "Quebec") == 0) 
            {
                q_name[q_count] = "Quebec";
                q_age[q_count] = temp_age[i];
                q_sex[q_count] = temp_sex[i];
                q_percentage[q_count] = atof(temp_percentage[i]);
                q_year[q_count] = atof(temp_year[i]);
                q_count++;
            }
            else if (strcmp(temp_province[i], "British Columbia") == 0) 
            {
                bc_name[bc_count] = "British Columbia";
                bc_age[bc_count] = temp_age[i];
                bc_sex[bc_count] = temp_sex[i];
                bc_percentage[bc_count] = atof(temp_percentage[i]);
                bc_year[bc_count] = atof(temp_year[i]);
                bc_count++;
            }
        }
      }
    //Answers to Questions
  printf("QUESTION 1\n");
  printf("---------------------------------------------------------------------\n\n");
  printf("a)\n\n"); //Question 1a
  printf("Ontario: %.2lf, Quebec: %.2lf, British Columbia: %.2lf, Alberta: %.2lf\n\n", p_average(o_percentage), p_average(q_percentage), p_average(bc_percentage), p_average(a_percentage)); 

  printf("b)\n\n"); //Question 1b
  printf("Canada national average: %.2lf\n\n", p_average(c_percentage));

  double c2015, c2016, c2017, c2018, c2019, c2020, c2021,o2015, o2016, o2017, o2018, o2019, o2020, o2021, a2015, a2016, a2017, a2018, a2019, a2020, a2021, q2015, q2016, q2017, q2018, q2019, q2020, q2021, b2015, b2016, b2017, b2018, b2019, b2020, b2021;
  printf("c)\n\n"); //Question 1c
  printf("Canada: \n");
  y_average(c_percentage, c_year, &c2015, &c2016, &c2017, &c2018, &c2019, &c2020, &c2021);
  
  printf("\nOntario: \n");
  y_average(o_percentage, o_year, &o2015, &o2016, &o2017, &o2018, &o2019, &o2020, &o2021);

  printf("\nAlberta: \n");
  y_average(a_percentage, a_year, &a2015, &a2016, &a2017, &a2018, &a2019, &a2020, &a2021);

  printf("\nQuebec: \n");
  y_average(q_percentage, q_year, &q2015, &q2016, &q2017, &q2018, &q2019, &q2020, &q2021);

  printf("\nBritish Columbia: \n");
  y_average(bc_percentage, bc_year, &b2015, &b2016, &b2017, &b2018, &b2019, &b2020, &b2021);
  
  printf("\nd)\n\n"); //Question 1d
  printf("Canada: \n"); 
  a_average(c_age, c_percentage);

  printf("Ontario: \n"); 
  a_average(o_age, o_percentage); 

  printf("Alberta: \n"); 
  a_average(a_age, a_percentage); 

  printf("Quebec: \n"); 
  a_average(q_age, q_percentage);

  printf("British Columbia: \n"); 
  a_average(bc_age, bc_percentage); 

  printf("QUESTION 2: \n"); //Question 2
  printf("---------------------------------------------------------------------\n\n");
  double averages[4] = {p_average(o_percentage), p_average(a_percentage), p_average(q_percentage), p_average(bc_percentage)};
  char *q2province[4] = {"Ontario", "Alberta", "Quebec", "British Columbia"};
  int z = sizeof(averages)/sizeof(averages[0]);
  sort_string_and_double(averages, q2province, z);
  printf("The province with the highest average is %s with %.2lf%\n", q2province[0], averages[0]);
  printf("The province with the lowest average is %s with %.2lf%% \n\n", q2province[3], averages[3]);

  
  printf("QUESTION 3: \n"); //Question 3
  printf("---------------------------------------------------------------------\n\n");
  printf("Comparing the provinces to the national average:\n\n");
  printf("%s", greatercan(p_average(o_percentage), o_name[1], p_average(c_percentage)));
  printf("%s", greatercan(p_average(a_percentage), a_name[1], p_average(c_percentage)));
  printf("%s", greatercan(p_average(q_percentage), q_name[1], p_average(c_percentage)));
  printf("%s", greatercan(p_average(bc_percentage), bc_name[1], p_average(c_percentage)));

  printf("QUESTION 4:\n"); //Question 4
  printf("---------------------------------------------------------------------\n\n");

  char *q4province[28] = {"Ontario in 2015", "Ontario in 2016", "Ontario in 2017", "Ontario in 2018", "Ontario in 2019", "Ontario in 2020", "Ontario in 2021","Alberta in 2015", "Alberta in 2016", "Alberta in 2017", "Alberta in 2018", "Alberta in 2019", "Alberta in 2020", "Alberta in 2021","Quebec in 2015", "Quebec in 2016", "Quebec in 2017", "Quebec in 2018", "Quebec in 2019", "Quebec in 2020", "Quebec in 2021","British Columbia in 2015", "British Columbia in 2016", "British Columbia in 2017", "British Columbia in 2018", "British Columbia in 2019", "British Columbia in 2020", "British Columbia in 2021"};
  double year_values[28] = {o2015, o2016, o2017, o2018, o2019, o2020, o2021, a2015, a2016, a2017, a2018, a2019, a2020, a2021, q2015, q2016, q2017, q2018, q2019, q2020, q2021, b2015, b2016, b2017, b2018, b2019, b2020, b2021};
  //Sort these values and as they sort so does the province
  int p = sizeof(year_values)/sizeof(year_values[0]);
  sort_string_and_double(year_values, q4province, p);
  printf("%s had the highest average with %.2lf%%", q4province[0], year_values[0]);
  int tie_hi_loop = 1;

  int if_tie = 0;

  for (tie_hi_loop = 1; tie_hi_loop <= 28; tie_hi_loop++)
  {
    if (year_values[0] == year_values[tie_hi_loop])
    {
      printf(", %s tied for highest average with %.2lf%%", q4province[tie_hi_loop], year_values[tie_hi_loop]);
      if_tie = 1;
    }
    else
    {
      break;
    }
  }

  printf("\n%s had the lowest average with %.2lf%%", q4province[27], year_values[27]);
  
  int tie_low_loop = 26;
  for (tie_low_loop = 26; tie_low_loop >= 0; tie_low_loop--)
  {
    if (year_values[27] == year_values[tie_low_loop])
    {
      printf(", %s tied for lowest average with %.2lf%%", q4province[tie_low_loop], year_values[tie_low_loop]);
      if_tie = 1;
    }
    else
    {
      break;
    }
  }

  if (if_tie == 0)
  {
    printf("\nThere were no ties for this data set\n\n");
  }


  printf("QUESTION 5:\n"); //Question 5
  printf("---------------------------------------------------------------------\n\n");
  print_y_average(c_percentage, c_year, o_percentage, o_year, a_percentage, a_year, q_percentage, q_year, bc_percentage, bc_year);
  printf("This question is coded with GNUPlot, and it's results are not displayable here. Please see CPS188 TERM PROJECT report\n\n");  


  printf("QUESTION 6:\n"); //Question 6
  printf("---------------------------------------------------------------------\n\n");
  print_a_average(c_age, c_percentage);
  printf("This question is coded with GNUPlot, and it's results are not displayable here. Please see CPS188 TERM PROJECT report\n\n");
    printf("---------------------------------------------------------------------\n\n");

}
 