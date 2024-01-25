#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ldap.h>

int main() {

    for (entry = ldap_first_entry(ld, result); entry != NULL; entry = ldap_next_entry(ld, entry)) {
        char** values = ldap_get_values(ld, entry, "dn");
        char* computerDn = values[0];

        char** domainValues = ldap_get_values(ld, entry, "dnsHostName");
        char* computerDomain = domainValues[0];

        if (computerDomain != NULL && strcmp(computerDomain, "premier_domaine.com") != 0) {
            printf("Transférer l'ordinateur %s vers premier_domaine.com...\n", computerDn);

        }

        ldap_value_free(values);
        ldap_value_free(domainValues);
    }

    return 0;
}
