#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int check(void)
{
        int hw_mc_passed = 0;
        int user_agree = 0;
        FILE *settings = fopen("/usr/share/applics/settings.txt","r");
        FILE *code = fopen("/usr/local/share/applics","r");
        if(settings != NULL)
        {
                hw_mc_passed = hw_mc_passed + 1;
        }
        else
        {
                printf("There is no settings.txt in /usr/share/applics (or no applics folder");
        }
        if(code != NULL)
        {
                hw_mc_passed = hw_mc_passed + 1;
        }
        else
        {
                printf("   applics is uninstalled right? \n input (1) to start installing in: ");
                scanf("%d",&user_agree);
                if(user_agree == 1)
                // тут мы создаём settings.txt 
                {
                        printf("PLEAAASE,move applics directory with all files to your Download folder do not rename anything!!! \n\n");
                        system("sudo mkdir /usr/share/applics");
                        system("cd ~/Загрузки/applics && touch settings.txt && cd");
                        system("sudo mv ~/Загрузки/applics/settings.txt /usr/share/applics");

                        system("sudo mv ~/Загрузки/applics/applics /usr/share/bin");
                        return 0;
                }
        }
        return 0;
}

int display(void)
{
        FILE *settings = fopen("/usr/share/applics/settings.txt","r");
        char command_show[256];
        int line_id_show = 0;
        while ((fgets(command_show,sizeof(command_show),settings) != NULL))
        {
                command_show[strlen(command_show) - 1] = '\0';
                line_id_show = line_id_show + 1;
                printf("%d - %s \n",line_id_show,command_show);

        }
        rewind(settings);
        return 0;
}


int main(void)
{
        check();
        int inpu = 0;
        FILE *settings = fopen("/usr/share/applics/settings.txt","r");
        int line_id = 0;
        char command[256];
        char comm_inp[256] = "ls";
        display();

        line_id = 0;
        rewind(settings);
        scanf("%d",&inpu);

        if(inpu == 0)
        {
                FILE *nano = fopen("/bin/nano","r");
                if(nano == NULL)
                {
                        fclose(settings);
                        printf("Oh sorry there is no nano text editor! \n input 1 if you want to install it (and run again): ");
                        int inp_nano;
                        scanf("%d",&inp_nano);
                        if(inp_nano == 1)
                        {
                                system("sudo apt install nano -y");
                                return 0;

                        }
                        else
                        {
                                printf("Sorry you need nano :( \n");
                                return 1;
                        }

                }
                fclose(settings);
                fclose(nano);
                system("sudo nano /usr/share/applics/settings.txt");
                return 0;

        }

        while((fgets(command,sizeof(command),settings) != NULL))
        {
                line_id = line_id + 1;
                command[strlen(command) - 1] = '\0';
                if(line_id == inpu)
                {
                        system("clear");
                        system(command);
                }

        }

        fclose(settings);
        return 0;
}

