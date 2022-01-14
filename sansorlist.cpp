#include <stdio.h>
#include <string.h>

class SansorList
{
    private:
    const char* fileName;
    int totalSansorsFound;

    public:
    SansorList(const char * fileNamei)
    {
        fileName=fileNamei;
        totalSansorsFound=0;
    }

    void writeAllSansors(char * sansor)
    {
        printf("%s\n",sansor);
        bool check=false;
         FILE* handle=fopen("AllSansor.txt","a");
         
            //for matching string
            char buffer[1024];
            FILE* handleRead=fopen("AllSansor.txt","r");
            while (fgets(buffer,1024,handleRead))
            {
                if((strstr(buffer, sansor)) != NULL) 
                {
			     check=true;
		        }

            }

        if(check==false)
        {
         fputs(sansor, handle);
          fputs("\n",handle);
          totalSansorsFound++;
         }


         fclose(handle);
         fclose(handleRead);

    }

    void generateList()
    {
        char buffer[1024];
        char* token;
        int countSansorList=0;
       
        int count=0;
        
        FILE* handle=fopen(fileName,"r");
         FILE *fp;
         fp = fopen("AllSansor.txt","w");

        if(handle==NULL)
        {
            printf("File Not Open check File Name\n");
            return;
        }

        while (fgets(buffer,1024,handle))
        {   
            
            //code for skipping 
            if(strncmp(buffer,"%",1)==0)
            continue;

             token=strtok(buffer,"\n");

             while (token!=NULL)
             {
                // printf("%s\n", token);
             
                char sansorName[10]={};
                char *list;
                
                 for (int i = 0; i < sizeof(token); i++)
                 {
                    if(token[i]==';')
                      break;
                      else
                      {
                         sansorName[i]=token[i];
                      }
                 }

                writeAllSansors(sansorName);
           
                 
                 countSansorList++;
                 token=strtok(NULL,"\n");
             }
               
           
        }
         printf("Total Scanned Lines is:%d\n",countSansorList); 
       //  printf("%s",*sansors); 
        
    }

    void printTotalSansors()
    {
        printf("Total Sansor Found in file is: %d\n",totalSansorsFound);
    }



};

int main(int argc, char** argv)
{
   printf("%s",argv[1]);
   if(argc >=1)
   {	
     SansorList* sl=new SansorList(argv[1]);
     sl->generateList();
     sl->printTotalSansors();
   }
    return 0;
}
