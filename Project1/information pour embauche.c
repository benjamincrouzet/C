#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


struct Personne {
    char nom[50];
    int age;
};

struct Employe {
    struct Personne infoPersonne;
    int idEmploye;
    float salaire;
    union {
        char role[50];
        int niveau;
    } details;
};

void afficherPersonne(struct Personne p) {
    printf("Nom: %s\n", p.nom);
    printf("Age: %d\n", p.age);
}

void afficherEmploye(struct Employe e) {
    printf("Informations sur l'employe :\n");
    afficherPersonne(e.infoPersonne);
    printf("ID Employe: %d\n", e.idEmploye);
    printf("Salaire: %.2f\n", e.salaire);
    printf("Role: %s\n", e.details.role);
}

int main() {
    struct Employe employe1;

    printf("Entrez le nom de l'employe : ");
    scanf("%s", employe1.infoPersonne.nom);

    printf("Entrez l'age de l'employe : ");
    scanf("%d", &employe1.infoPersonne.age);

    printf("Entrez l'ID de l'employe : ");
    scanf("%d", &employe1.idEmploye);

    printf("Entrez le salaire de l'employe : ");
    scanf("%f", &employe1.salaire);

    printf("Entrez le role de l'employe : ");
    scanf("%s", employe1.details.role);

    afficherEmploye(employe1);

    return 0;
}


