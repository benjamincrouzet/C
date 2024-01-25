#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ldap.h>

#define SERVER "ldap://votre_serveur_LDAP:port"  
#define BIND_DN "votre_nom_utilisateur"         
#define BIND_PW "votre_mot_de_passe"            

#define BASE_DN "dc=votre_domaine,dc=com"       

int main() {
    LDAP* ld;
    int rc;

    if ((rc = ldap_initialize(&ld, SERVER)) != LDAP_SUCCESS) {
        fprintf(stderr, "Échec de l'initialisation de la connexion : %s\n", ldap_err2string(rc));
        return 1;
    }

    rc = ldap_simple_bind_s(ld, BIND_DN, BIND_PW);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "Échec de la connexion : %s\n", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    LDAPMessage* result;
    rc = ldap_search_ext_s(ld, BASE_DN, LDAP_SCOPE_SUBTREE, "(objectClass=computer)", NULL, 0, NULL, NULL, NULL, LDAP_NO_LIMIT, &result);
    if (rc != LDAP_SUCCESS) {
        fprintf(stderr, "Échec de la recherche : %s\n", ldap_err2string(rc));
        ldap_unbind_ext_s(ld, NULL, NULL);
        return 1;
    }

    LDAPMessage* entry;
    char* dn, * attr;
    BerElement* ber;

    printf("Informations sur les ordinateurs de l'Active Directory :\n");
    printf("----------------------------------------------\n");
    printf("Ordinateur\t|\tDomaine\n");
    printf("----------------------------------------------\n");

    for (entry = ldap_first_entry(ld, result); entry != NULL; entry = ldap_next_entry(ld, entry)) {
        if ((dn = ldap_get_dn(ld, entry)) != NULL) {
            printf("DN: %s\n", dn);
            ldap_memfree(dn);
        }

        for (attr = ldap_first_attribute(ld, entry, &ber); attr != NULL; attr = ldap_next_attribute(ld, entry, ber)) {
            char** values = ldap_get_values(ld, entry, attr);
            if (values != NULL) {
                printf("%s\t\t|\t%s\n", values[0], BASE_DN);
                ldap_value_free(values);
            }
        }

        if (ber != NULL)
            ber_free(ber, 0);
    }

    ldap_msgfree(result);
    ldap_unbind_ext_s(ld, NULL, NULL);

    return 0;
}
