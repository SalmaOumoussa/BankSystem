    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <Windows.h>

    int choice;
    int i = 0;
    int j = 0;
    float montantX;
    int accountCount = 0;
    char cin[10];

    typedef struct
    {
        char cin [10];
        char nom [10];
        char prenom[10];
        float solde;
    }client;

        client temp;
        client c[100];

    void fedilisation ()
    {
                    for (i = 1; i < accountCount; i++)
                    {
                        for (j = 0; j < accountCount - i; j++)
                        {
                        if (c[j].solde > c[j + 1].solde) {
                                temp = c[j];
                                c[j] = c[j + 1];
                                c[j + 1] = temp;
                            }
                        }
                    }

                    for(i = 0; i < 3 ; i++)
                    {
                        printf("\n CIN : %s\nle solde de %s AVANT la fedilisation est de %.2f",c[i].cin,c[i].nom,c[i].solde);
                        c[i].solde *= 1.013;
                        printf("le solde APRES la fedilisation est de %.2f",c[i].solde);

                    }

    }

    void rechercheAscDescCond ()
    {
            system("cls");
                    printf("***Recherche par Ordre Ascendant Ou Descendant Conditionne par un seuil***\n\n");
                    printf("Merci d'entrer le seuil\n");
                    scanf("%f",&montantX);

                    printf("Merci d'entrer l'ordre que vous voulez\n");
                    printf("1. Ascendent\n");
                    printf("2. Descendant\n");
                    scanf("%d",&choice);

                    switch(choice)
                    {
                    case 1 :
                        for (i = 1; i < accountCount; i++)
                        {
                            for (j = 0; j < accountCount - i; j++)
                            {
                                if (c[j].solde > c[j + 1].solde)
                                {
                                        temp = c[j];
                                        c[j] = c[j + 1];
                                        c[j + 1] = temp;
                                }
                            }
                        }
                        for (i = 0; i < accountCount; i++)
                            {
                                if(montantX < c[i].solde)
                                {
                                printf("\n%s\t%s\t%f",c[i].cin,c[i].nom,c[i].solde);
                                }
                            }
                    break;

                    case 2:
                            for (i = 1; i < accountCount; i++)
                            {
                                for (j = 0; j < accountCount - i; j++)
                                {
                                    if (c[j].solde < c[j + 1].solde)
                                    {
                                        temp = c[j];
                                        c[j] = c[j + 1];
                                        c[j + 1] = temp;
                                    }
                                }

                            }

                    for (i = 0; i < accountCount; i++)

                        {
                            if(montantX < c[i].solde)
                            {
                            printf("\n%s\t%s\t%f",c[i].cin,c[i].nom,c[i].solde);
                            }
                        }
                    }
    }

    void rechercheCIN ()
    {
        system("cls");
            printf("***RECHERCHE PAR CIN***\n\n");
            printf ("\n entrer le CIN \n");
            scanf("%s",cin);

            for ( i = 0; i < accountCount ;i++)
            {
                    if (strcmp(cin, c[i].cin) == 0)
                    {
                        printf("*LES INFOS DE TITULAIRE DE COMPTE*\n\n NOM : %s\nPRENOM : %s\nCIN : %s\nSOLDE : %.2fDH\n\n",c[i].nom,c[i].prenom,c[i].cin,c[i].solde);

                        system ("PAUSE");
                        menuFonction();
                    }

            }
            printf("\nCompte introuvable\n\n");
            system ("PAUSE");
            rechercheCIN();
    }
    void rechercheAscDesc ()
    {

                printf("***Recherche par Ordre Ascendant Ou Descendant***\n\n");
                printf("Merci d'entree l'ordre que vous voulez\n\n");
                printf("1. Ascendent\n");
                printf("2. Descendant\n");
                scanf("%d",&choice);

                    switch(choice)
                    {
                    case 1 :
                    for (i = 1; i < accountCount; i++)
                    {
                        for (j = 0; j < accountCount - i; j++)
                        {
                            if (c[j].solde > c[j + 1].solde)
                            {
                                temp = c[j];
                                c[j] = c[j + 1];
                                c[j + 1] = temp;
                            }
                        }
                    }
                    for (i = 0; i < accountCount; i++)
                    {

                        printf("\nNOM : %s\tCIN : %s\tSOLDE : %.2f",c[i].cin,c[i].nom,c[i].solde);
                    }
                    break;

                    case 2:
                        for (i = 1; i < accountCount; i++)
                        {
                            for (j = 0; j < accountCount - i; j++)
                            {
                                if (c[j].solde < c[j + 1].solde)
                                {
                                    temp = c[j];
                                    c[j] = c[j + 1];
                                    c[j + 1] = temp;
                                }
                            }
                        }
                        for (i = 0; i < accountCount; i++)
                        {
                        printf("\n%s\t%s\t%.2f",c[i].cin,c[i].nom,c[i].solde);
                        }
                    }

                    system("PAUSE");
                    menuFonction ();
    }
    void affichage ()
    {
        system("cls");
                printf("Veuillez choisir le type d'affichage des infos client !\n\n");
                printf("1. Recherche par CIN\n\n");
                printf("2. Par Ordre Ascendant Ou Descendant\n\n");
                printf("3. Recherche par Ordre Ascendant Ou Descendant (conditionne par un seuil introduit)\n\n");
                scanf("%d",&choice);
        system("cls");
                switch(choice)
                {
                    case 1 :
                        rechercheCIN();
                        break;
                    case 2 :
                        rechercheAscDesc();

                        break;
                    case 3 :
                        printf("4. Recherche par Ordre Ascendant Ou Descendant (conditionne par un seuil introduit)\n");
                        rechercheAscDescCond();
                        break;
                    default:
                        affichage ();
                        break;
                }
    }

    void operations()
    {
        system("cls");
                printf("\n*Verification d'indentite*\n\n");
                printf("entrer un cin\n");
                scanf("%s",cin);

                    for ( i = 0; i < accountCount ;i++)
                    {
                        if (strcmp(cin, c[i].cin) == 0)
                        {
                            printf("Voulez-vous faire un Retrait ou DEPOT d'argent ?\n");
                            printf("1. --RETRAIT--\n");
                            printf("2. --DEPOT--\n");
                            scanf("%d",&choice);

                            printf("Veuillez entrer un montant");
                            scanf("%f",&montantX);

                    system("cls");
                                    switch(choice)
                                    {
                                        case 1:
                                            if(montantX <= c[i].solde)
                                            {
                                                c[i].solde -= montantX ;
                                                printf("Vous avez retire %.2f DH , Votre solde est de %.2f DH\n\n",montantX,c[i].solde);

                                                system("PAUSE");
                                                menuFonction();
                                            }
                                            else
                                            {
                                                printf("Veuillez saisir un montant inferieur ou egale a %.2f\n\n",c[i].solde);
                                                operations ();
                                            }
                                            break;

                                        case 2:
                                                c[i].solde += montantX ;

                                                printf("Vous avez depose %.2f DH , Votre solde est de %.2f DH\n\n",montantX,c[i].solde);

                                                system ("pause");
                                                menuFonction ();

                                            break;

                                        default:
                                            operations();
                                            break;
                                    }
                        }
                    }
            printf("Compte introuvable\n");
    }


    void creationComptes ()
    {
            int x;

                printf("donner le nombre de comptes : \t");
                scanf("%d",&x);
                printf("\n\n");

                for (i = 0; i < x ; i++)
                {
                        printf("Veuillez entrer le nom : ");
                        scanf("%s",c[accountCount + i].nom);

                        printf("Veuillez entrer le prenom : ");
                        scanf("%s",c[accountCount + i].prenom);

                        printf("Veuillez entrer le cin : ");
                        scanf("%s",c[accountCount + i].cin);

                        printf("Veuillez entrer un montant : ");
                        scanf("%f",&c[accountCount + i].solde);
                }
                accountCount += x;
                printf("Les comptes ont ete crees avec succes !\n\n");

                system("PAUSE");
                menuFonction();
    }

    void menuFonction()
    {

    system("cls");	// clean ecran : �a efface ce qui �tait ecrit avant ...
                printf("\n****MENU***\n\n");
                printf("1. Creation comptes\n\n");
                printf("2. Operations\n\n");
                printf("3. Affichage\n\n");
                printf("4. Fedilisation\n\n");
                printf("5. QUITTER\n\n");

                printf("Veuillez entrer le num de votre operation\t");
                scanf("%d",&choice);

                    switch (choice)
                {
                    case 1:

                        system ("cls");
                        printf("***CREATION DE COMPTES***\n\n");
                        creationComptes();
                        break;

                    case 2:
                        printf("***OPERATIONS***\n\n");
                        operations();

                        system("PAUSE");

                        menuFonction ();
                        break;

                    case 3:
                        printf("***AFFICHAGE***\n\n");
                        affichage ();
                        break;
                    case 4:
                        printf("***FEDILISATION\n\n");
                        fedilisation();
                        break;
                    case 5:
                        printf("-------A BIENTOT :)-----\n");
                        break;
                    default:
                    menuFonction();
                        break;
                }
    }



    int main()
    {
    menuFonction();
    }
