#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h> 
#include <sys/sysinfo.h>

void cpu_info() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("/proc/cpuinfo", "r");
    while ((read = getline(&line, &len, fp)) != -1) {
        if(strstr(line, "model name")!= NULL) {
            printf("\n%.*s", 100, line + 13);
            break;
        }
    }
    fclose(fp);
    if (line)
        free(line);
}

int main(){
    char N;
    struct sysinfo raminfo;
    unsigned long total_bytes;
    sysinfo(&raminfo);
    total_bytes = raminfo.mem_unit * raminfo.totalram;
    printf("\n\nWhat to learn about this computer you want?\n");

    while(1){
        printf("\n0- Quit\n");
        printf("1- CPU\n");
        printf("2- RAM\n");
        printf("3- SSD/HDD Size\n");
        printf("4- Network Interface\n");
        printf("5- Operating System\n");
        printf("0,1,2,3,4,5?:");
        scanf(" %c", &N);

        switch(N){
            case '0':
                return 0;
            case '1':
                cpu_info(); //
                break;
            case '2':
                printf("\ntotal usable main memory is %lu B, %lu MB\n",total_bytes, total_bytes/1024/1024); //
                break;
            case '3':
                printf("\n");
                system("df -h"); //
                printf("\n");
                break;
            case '4':
                printf("\n");
                system("ip -o a show | cut -d ' ' -f 2,7 | grep -v '::'");
                printf("\n");
                break;
            case '5':
                printf("\n");
                system("cat /etc/*-release"); //
                printf("\n");
                break;                                 
            default:
                printf("\nlütfen verilen sayılardan birini giriniz:\n");
        }
    }        
}