#include <stdio.h>

// Définition de la classe abstraite Moto
class Moto {
public:
    // Méthode virtuelle pure pour afficher les détails de la moto
    virtual void afficherDetails() = 0;
    // L'utilisation de 'virtual void' indique une méthode virtuelle
    // '= 0' signifie que cette méthode est virtuelle pure et doit être implémentée dans les classes dérivées.
};

// Définition de la classe concrète Vehicule
class Vehicule : public Moto {
protected:
    char modele[50];
    int annee;
    const char* type = "Véhicule";

public:
    // Constructeur avec paramètres pour Vehicule
    Vehicule(const char* mode, int year) {
        snprintf(modele, sizeof(modele), "%s", mode);
        annee = year;
    }

    // Implémentation de la méthode afficherDetails() pour Vehicule
    void afficherDetails() override {
        printf("Type : %s, Modèle : %s, Année : %d\n", type, modele, annee);
    }
};

// Définition de la classe Voiture, dérivée de Vehicule
class Voiture : public Vehicule {
public:
    // Constructeur avec paramètres pour Voiture
    Voiture(const char* mode, int year) : Vehicule(mode, year) {
        // Appel du constructeur de Vehicule pour initialiser les attributs
    }
    // Voiture hérite de la méthode afficherDetails() de Vehicule
    // Pas besoin de la redéfinir ici, car la classe Vehicule a déjà fourni une implémentation.
};

int main() {
    // Création d'objets de la classe Voiture et Vehicule
    Voiture maVoiture("Toyota", 2022);
    Vehicule monVehicule("Moto", 2021);

    // Appel de la méthode afficherDetails() pour chaque objet
    printf("Détails de ma voiture : \n");
    maVoiture.afficherDetails();

    printf("\nDétails de mon véhicule : \n");
    monVehicule.afficherDetails();

    return 0;
}
