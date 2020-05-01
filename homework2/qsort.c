#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct person_struct{  
    char first_name[30]; 
    char last_name[30];
    char city_name[30];
};

typedef struct person_struct person_t;
person_t dbasepeople[100];

int main(void)
{
    size_t ctr =0;
    char str1[30],str2[30],str3[30];

    FILE *fp;
	fp=fopen("data.txt","r");
	if(fp==NULL)
	{
	printf("\n Cannot open the file \n");
	exit(0);
	}
	while(fgetc(fp)!= EOF)
	{
	    fscanf(fp,"%s %s %s \n",str1,str2,str3);
	    strcpy(dbasepeople[ctr].last_name,str1);
	    strcpy(dbasepeople[ctr].first_name,str2);
	    strcpy(dbasepeople[ctr].city_name,str3);
        ctr++;
	}

	int compare(const void *pa,const void *pb)
	{
	  char *Ina = ((person_t*)pa)->last_name;
	  char *Inb = ((person_t*)pb)->last_name;

	   return strcmp(Ina,Inb);
	};
    qsort (dbasepeople, ctr, sizeof(person_t), compare);

    for(int i = 0; i < ctr; i++)
    {
    printf("%s %s %s \n",dbasepeople[i].first_name,dbasepeople[i].last_name,dbasepeople[i].city_name);
    }
    return 0;

}
