// Connexion et execution de requete sur un base de donnees Microsoft Access
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/stat.h>
#include <time.h>

void allWord() {
    const char *filename = "words.csv";
    struct stat sb; //Crée une structure stat
    stat(filename, &sb);
    long int nbr_line = 0;
    unsigned char *line = malloc(sb.st_size); //Crée une allocation de mémoire
    FILE *fichier = NULL; //Crée le fichier
    fichier = fopen(filename,
                    "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
    if (fichier != NULL) { //Si fichier n'est pas null, s'il l'a ouvert correctement
        while (fscanf(fichier, "%[^\n] ", line) != EOF)
            nbr_line++; //Tant qu'il n'a pas fini de lire l'entièreté du fichier, nbr_line augmente
        fclose(fichier); //Ferme le fichier
    }
    fichier = NULL;
    fichier = fopen(filename, "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
    char w[nbr_line][15];
    long int j[nbr_line];
    if (fichier != NULL) {
        for (long int i = 0; i < nbr_line; i++) {
            fscanf(fichier,"%[^\n] ",&w[i]);
            printf("%s\n", w[i]);
        }
        fclose(fichier);
    }
}
void random() {
    const char *filename = "words.csv";
    struct stat sb; //Crée une structure stat
    stat(filename, &sb);
    long int nbr_line = 0;
    unsigned char *line = malloc(sb.st_size); //Crée une allocation de mémoire
    FILE *fichier = NULL; //Crée le fichier
    fichier = fopen(filename,
                    "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
    if (fichier != NULL) { //Si fichier n'est pas null, s'il l'a ouvert correctement
        while (fscanf(fichier, "%[^\n] ", line) != EOF)
            nbr_line++; //Tant qu'il n'a pas fini de lire l'entièreté du fichier, nbr_line augmente
        fclose(fichier); //Ferme le fichier
    }
    fichier = NULL;
    fichier = fopen(filename, "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
    char w[nbr_line][15];
    long int j = rand() % 88722 + 1;
    if (fichier != NULL) {
        for (long int i = 0; i < nbr_line; i++) {
            fscanf(fichier, "%[^\n] ", &w[i]);
        }
        printf("%d - %s",j,w[j]);
        fclose(fichier);
    }
}
void Verif(char *word, long int *nbr_word) {
    const char *filename = "words.csv";
    struct stat sb; //Crée une structure stat
    stat(filename, &sb);
    long int nbr_line = 0;
    unsigned char *line = malloc(sb.st_size); //Crée une allocation de mémoire
    FILE *fichier = NULL; //Crée le fichier
    fichier = fopen(filename,
                    "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
    if (fichier != NULL) { //Si fichier n'est pas null, s'il l'a ouvert correctement
        while (fscanf(fichier, "%[^\n] ", line) != EOF)
            nbr_line++; //Tant qu'il n'a pas fini de lire l'entièreté du fichier, nbr_line augmente
        fclose(fichier); //Ferme le fichier
    }
     fichier = NULL;
     fichier = fopen(filename, "r"); //Ouvre le fichier dans le répertoire 'filename' et crée une permission de lecture (r)
     char w[nbr_line][19];
     long int j[nbr_line];
     if (fichier != NULL) {
         for (long int i = 0; i < nbr_line; i++) {
             fscanf(fichier,"%[^\n] ",&w[i]);
             if (strcmp(w[i], word) == 0) {
                 if (j[i]) {
                     //Gestion des accents dans la console
                     SetConsoleOutputCP(65001);
                     printf("Vous avez déjà pioché ce nombre...\n");
                     //Gestion des accents dans la console
                     SetConsoleOutputCP(437);
                 } else {
                     //Gestion des accents dans la console
                     SetConsoleOutputCP(65001);
                     printf("Un mot de trouvé ! /// %s \\\\\\\n",w[i]);
                     //Gestion des accents dans la console
                     SetConsoleOutputCP(437);
                     j[i]++;
                     (*nbr_word)++;
                 }
             }
           // printf("%s - %s - %d\n", w[i], word, *nbr_word);
         }
         fclose(fichier);
     }
 }
    int main() {
    srand(time(NULL));
        long int nbr_word = 0;
        int choice_int, choice_random;
        char word[0], choice[2];
        choice[1] = '\0';
        do {
            do {
                system("cls");
                //Gestion des accents dans la console
                SetConsoleOutputCP(65001);
                printf("Ce programme référencie plus de 80'000 mots du dictionnaire\n1)Voir combien de mots sais-je en tout\n2)Apprenez-moi de nouveaux mots !\n3)Voir tous les mots du programme (0:35 minutes!)");
                //Gestion des accents dans la console
                SetConsoleOutputCP(437);
                printf("\n{ Choix } = ");
                scanf("%s",&choice);
            } while (strlen(choice) != 1);
            choice_int = choice[0] - '0';
            switch (choice_int) {
                case 1:
                    for (long int i = 0; i < 88722; i++) {
                        system("cls");
                        //Gestion des accents dans la console
                        SetConsoleOutputCP(65001);
                        printf("Mots ( %d -/- %d )\n",nbr_word,88722);
                       // printf("\ncommandes :\n?)Le programme montre le lien du dictionaire en ligne\nXXXX)Retourne au menu précédent");
                        //Gestion des accents dans la console
                        SetConsoleOutputCP(437);
                        printf("\n\nMontrez-moi un mot : ");
                        gets(&word[30]);
                        Verif(&word[30], &nbr_word);
                        system("pause");
                    }
                break;
                case 2:
                    //Gestion des accents dans la console
                    SetConsoleOutputCP(65001);
                    printf("Un conseil : Essayez de trouver les définitions de chacun\n");
                    //Gestion des accents dans la console
                    SetConsoleOutputCP(437);
                    system("pause");
                    system("cls");
                    printf("Combien de fois voulez-vous de mot appris ? ");
                    scanf("%d",&choice_random);
                    for (int i = 0; i < choice_random; i++) {
                        random();
                        printf("\n");
                        system("pause");
                    }
                break;
                case 3:
                    allWord();
                    system("pause");
                break;
                default:
                    break;
            }
        } while (2 == 2); //boucle infinie
        return 0;
    }
