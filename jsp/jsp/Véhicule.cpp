#include <stdio.h>

// Définition de la classe Voiture
class Voiture {
private:
    char modele[50]; // Attribut pour stocker le modèle de la voiture

    int annee; // Attribut pour stocker l'année de la voiture

public:
    // Constructeur par défaut
    Voiture() {
        modele[0] = '\0'; // Initialisation de la chaîne de caractères à une chaîne vide
        annee = 0; // Initialisation de l'année à zéro
    }

    // Constructeur avec des paramètres
    Voiture(const char* mode, int year) {
        // Copie de la chaîne de caractères `mode` dans l'attribut `modele`
        // en s'assurant de ne pas dépasser la taille maximale du tampon (49 caractères + le caractère nul)
        snprintf(modele, sizeof(modele), "%s", mode);

        annee = year; // Initialisation de l'année avec la valeur fournie
    }

    // Méthode pour afficher les détails de la voiture
    void afficherDetails() {
        printf("Modèle : %s, Année : %d\n", modele, annee);
    }
};

int main() {
    // Création d'objets de la classe Voiture
    Voiture voiture1; // Utilisation du constructeur par défaut
    Voiture voiture2("Toyota", 2022); // Utilisation du constructeur avec paramètres

    // Affichage des détails des voitures
    printf("Détails de la voiture 1 : ");
    voiture1.afficherDetails();

    printf("Détails de la voiture 2 : ");
    voiture2.afficherDetails();

    return 0;
}

