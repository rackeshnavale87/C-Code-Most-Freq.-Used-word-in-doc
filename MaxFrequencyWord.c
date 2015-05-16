#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 2048
char buf[MAX];

struct word {
	char word[100];
	int count;
	struct word *next;
}word;



int main(int argc, char* argv[]) {
	char *p1, temp1[100];
	int lines=0,j=0,f=0,twords=0,Dword=0,flag=1;
	FILE *fp;
	struct word *temp,*t1,*root = NULL;

	fp = fopen("doc.txt","r");
	while (1) {
	        if (fgets(buf, sizeof(buf), fp) == NULL) {			
				fclose(fp);
				break;
		}
		else { 
			lines++;
			p1 = buf;
			char *p1 = buf;
			int z =0;
			while(buf[z]){
				t1=root;flag=1;
				while(*p1 == ' ' || *p1== '.' || *p1== ';' || *p1== ':' || *p1 == '"' || *p1 =='['|| *p1 ==']'|| *p1 ==','|| *p1 =='('|| *p1 ==')'|| *p1 =='!'|| *p1 =='?'|| *p1 =='\''|| *p1 =='-' || *p1=='\n'||*p1=='\t'||*p1=='/'||*p1=='\\')
				{
					p1++;z++;
				}
			
				while(!(*p1 == ' ' || *p1== '.' || *p1== ';' || *p1== ':' || *p1 == '"' || *p1 =='['|| *p1 ==']'|| *p1 ==','|| *p1 =='('|| *p1 ==')'|| *p1 =='!'|| *p1 =='?'|| *p1 =='\''|| *p1 =='-' || *p1=='\n'|| *p1=='/'||*p1=='\\') && (*p1!='\0') && (*p1!='\t'))
				{
					temp1[j] = *p1;
					j++;p1++;z++;
				}

				if(!buf[z]) 
					break;

				temp1[j]='\0';
				j=0;		
				temp = (struct word *)malloc(1*sizeof(struct word));
				temp->next = NULL;
				temp->count =1;twords++;
				strcpy(temp->word,temp1);
				if(root==NULL)
					{root=temp;Dword++;}
				else {
					while(t1->next!=NULL && flag) {
						if(strcmp(t1->word,temp1)==0) {
							t1->count++;
							free(temp);
							flag=0;
						}
						t1=t1->next;
						
					}
					if(flag) {
						t1->next = temp;Dword++; 
						flag =1;
						}
					}
				}
			}
		}
		printf("\nList of all %d Unique words with their count\n Count : Word\n-------------------------------------------\n",Dword);
		t1=root;
		for(f=0;f<Dword;f++) {
			printf("%3d : %s\n",t1->count,t1->word);
			t1=t1->next;
		}
//------------------------------------------------------------------------------------------------------
		t1=root;
		struct word *max = (struct word *)malloc(1*sizeof(struct word));
		int MaxC = 0;
		for(f=0;f<Dword;f++) {
			if(MaxC < t1->count) {
				max = t1;
				MaxC = t1->count;
			}
			t1=t1->next;
		}
	printf("\nMaximum frequently used word");
	printf("\n-------------------------------------------\n");
	printf("%3d : %s\n",max->count,max->word);
	printf("-------------------------------------------\n");
//------------------------------------------------------------------------------------------------------

return 0;
}
