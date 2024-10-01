#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct User{
char *name;
char *surname;
char *email;
};

struct User create_user(char *tempName, char *tempSurname, char *tempEmail){
    struct User temp;
    temp.name = tempName;
    temp.surname = tempSurname;
    temp.email = tempEmail;
    return temp;
}
void print_user(const struct User user){
    printf("Name: %s\n", user.name);
    printf("Surname: %s\n", user.surname);
    printf("Email: %s\n", user.email);
}


int main() {
     struct User user[100] = {};
     int index = 0;
    while(true){
        printf("Do you want to:\n 1: Show informations about a user \n 2: Delete an existing user \n 3: Add a user \n");
        int moznost;
        scanf("%i", &moznost);


        switch (moznost) {
            case 1:
                printf("You have chosen 1\n");
                int num;
                printf("which user do you want to print?\n");
                scanf("%i", &num);
                print_user(user[num]);
                break;

            case 2:
                printf("You have chosen 2\n");
                int del_num;
                printf("which user do you want to delete?\n");
                scanf("%i", &del_num);

                if (del_num > index || del_num < 0){
                    printf("NU UH\n");
                    break;
                }

                free(user[del_num].name);
                free(user[del_num].surname);
                free(user[del_num].email);

                for (int i = del_num; i < index; i++) {
                    user[i] = user[i+1];
                }
                index--;

                break;
            case 3:{
                printf("You have chosen 3\n");
                int length_name, length_surname, length_email;

                printf("Enter the length of your name\n");
                scanf("%i", &length_name);

                char *name = (malloc(length_name * sizeof(char) + 1));
                printf("Enter your name\n");
                scanf("%s", name);


                    printf("Enter the length of your surname\n");
                    scanf("%i", &length_surname);

                    char *surname = (malloc(length_surname * sizeof(char) + 1));
                    printf("Enter your surname\n");
                    scanf("%s", surname);

                    printf("Enter the length of your email\n");
                    scanf("%i", &length_email);

                    char *email = (malloc(length_email * sizeof(char) + 1));
                    printf("Enter your email\n");
                    scanf("%s", email);

                    user[index] = create_user(name, surname, email);
                    index++;
                }
                break;
            default:
                printf("You have chosen a unavailable option. Choose again\n");

        }

    }
}
