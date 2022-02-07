#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employes.h"

 
char employ_file_location[] = "employes.txt";
char connection_file_location[] = "connexions.txt";
char employ_file_location_tmp[] = "tmp_employes.txt";
char connection_file_location_tmp[] = "tmp_connexions.txt";
 
 
 int user_type(char ur[], char ps[])
{
    FILE * f_lg;
    char usrid[20], usrpass[20];
    int role, pass =0; 
    f_lg = fopen(connection_file_location, "r+");
    if (f_lg != NULL)
    {
        while (fscanf(f_lg, "%s %s %d", usrid, usrpass, &role) != EOF)
        {
            if (role == 2 || role == 4) pass = 1;
            if (strcmp(ur,usrid) == 0)
            {
                if (strcmp(ps, usrpass) == 0)
                {
                    fclose(f_lg);
                    return role;
                }
                else
                {
                    fclose(f_lg);
                    return 3;
                }
            }
        }
        
        fclose(f_lg);
        if (pass == 1) return -1;
        return 5;
    }
    else
    {
        return 5;
    }
}
