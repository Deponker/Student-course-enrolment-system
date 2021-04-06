#include<stdio.h>
#define c 3
#define s 8
int main()
{
    int c1, c2, c3, total, sum, max, p, c, s, q=0;

    printf("Enter Class Number & Student Number(Positive-value): ");
    scanf("%d %d", &c, &s);
    int enrol[c][s];
    int st_number[s];
    int temp_arr[c];
    printf("Enter Zero '0' at last to indicate that you have entered all student number for each class:");

    printf("\nIf Any Specific Class Has No Student, Press '0':\n");



    while(1){
    /* Initializing the array's */
    for(c1=0; c1<c; c1++)
    {
        for(c2=0; c2<s; c2++)
        {
            enrol[c1][c2]=0;
        }
    }
    for(c1=0; c1<s; c1++)
    {
        st_number[c1]=0;
    }



    /* Taking input from user */

    printf("\n");

    for(c1=0; c1<c; c1++)
    {
        printf("\nEnter all student number one after another who has taken class \"%d\":\n", c1+1);

        for(c2=0; c2<s; c2++)
        {
            scanf("%d", &st_number[c2]);

            if( (st_number[c2]<0) || (st_number[c2]>s) ){
                printf("You Entered \"%d\" Which is Invalid Student Number.\n", st_number[c2]);
                return 0;
            }
            if(st_number[c2]==0)
                break;
        }
        for(c3=0; c3<s; c3++)
        {
            if(st_number[c3]>0)
            {
                enrol[c1][st_number[c3]-1]=1;
            }
            else
            {
                st_number[c3]= st_number[c3] * 0;
                break;
            }
        }
    }

 /* Student number who has enrolled in all the classes */
    printf("\nStudent numbers who are enrolled in all classes: ");

    for(c1=0; c1<s; c1++)
    {
        total=0;
        for(c2=0; c2<c; c2++)
        {
            total=total+enrol[c2][c1];
        }
        if(total==c)
        {
            printf(" %d ",c1+1);
            ++q;
        }

    }
    if(q==0)
       printf(" \"No such student who took all the classes\"");


    /* Classes with maximum students */
    printf("\nClass numbers with maximum students: ");
    for(c1=0; c1<c; c1++)
    {
        sum=0;
        for(c2=0; c2<s; c2++)
        {
            sum= sum + enrol[c1][c2];
        }
        temp_arr[c1]=sum;
    }


    /* Finding maximum in Temp_arr[c1] */
    max = temp_arr[0];
    p=0;
    for(c1=0; c1<c; c1++)
    {
        if(temp_arr[c1]>max)
        {
            max = temp_arr[c1];
            p=c1;
        }
    }
    if(max==0)
       printf(" \"All classes are empty\"\n");
    else
       printf(" %d ", p+1);
    /* --------------------------------- */

    /* Finding equal value of max */
    for(c1=0; c1<c; c1++)
    {
        if(max==0)
            break;
        if((temp_arr[c1]==max) && (c1!=p))
        {
            printf(" %d ", c1+1); // Class number.
        }
    }



      /* Printing enroll[c][s] */
    printf("\n");
    printf("Printing enroll table: \n");
    for(c1=0; c1<c; c1++)
    {
        for(c2=0; c2<s; c2++)
        {
            printf("  %d  ", enrol[c1][c2]);
        }
        printf("\n");
    }


    }
    return 0;
}
