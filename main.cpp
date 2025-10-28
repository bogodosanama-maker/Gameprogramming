#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}

// ajouter les code a implementer ci dessous

// Fonction 1: Calcul de la longueur d'une chaine
size_t LongueurChaine(const char* chaine) {
    size_t compteur = 0;
   
    for (int i = 0; chaine[i] != '\0'; i++) {
        compteur++;
    }
    return compteur;
}

// Fonction 2: Copier une chaine vers une autre
void CopierChaine(char* destination, const char* source) {
    int i = 0;
 
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';
}

// Fonction 3: Ajouter une chaine a la fin d'une autre
void ConcatenerChaines(char* destination, const char* source) {
    int i = 0;
   
    while (destination[i] != '\0') {
        i++;
    }
   
    int j = 0;
    while (source[j] != '\0') {
        destination[i] = source[j];
        i++;
        j++;
    }
    destination[i] = '\0';
}

// Fonction 4: Chercher un caractere dans une chaine
char* TrouverCaractere(const char* chaine, char caractere) {
    for (int i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] == caractere) {
            
            return (char*)(chaine + i);
        }
    }
    
    return nullptr;
}

// Fonction 5: Compter combien de fois un caractere apparait
size_t CompterOccurrences(const char* chaine, char caractere) {
    size_t compteur = 0;
    int i = 0;
    
    while (chaine[i] != '\0') {
        if (chaine[i] == caractere) {
            compteur = compteur + 1;
        }
        i++;
    }
    return compteur;
}

// Fonction 6: Copier des octets en memoire
void CopierMemoire(void* destination, const void* source, size_t taille) {
    
    unsigned char* dest = (unsigned char*)destination;
    unsigned char* src = (unsigned char*)source;
    
    for (size_t index = 0; index < taille; index++) {
        dest[index] = src[index];
    }
}

// Fonction 7: Remplir une zone memoire avec une valeur
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    unsigned char* ptr = (unsigned char*)zone;
    
    size_t index = 0;
    while (index < taille) {
        ptr[index] = valeur;
        index++;
    }
}

// Fonction 8: Extraire une partie d'une chaine
void ExtraireSousChaine(char* destination, const char* source, 
                        size_t debut, size_t longueur) {
    size_t position = 0;
   
    while (position < longueur && source[debut + position] != '\0') {
        destination[position] = source[debut + position];
        position++;
    }
    // Termine la chaine
    destination[position] = '\0';
}

// Fonction 9: Separer une chaine selon un separateur
size_t DiviserChaine(const char* chaine, char separateur, 
                     char resultat[][100], size_t max_resultats) {
    size_t nb_mots = 0;
    size_t position_dans_mot = 0;
    size_t i = 0;
    
    while (chaine[i] != '\0' && nb_mots < max_resultats) {
        if (chaine[i] == separateur) {
            
            resultat[nb_mots][position_dans_mot] = '\0';
            nb_mots++;
            position_dans_mot = 0;
        } else {
            
            resultat[nb_mots][position_dans_mot] = chaine[i];
            position_dans_mot++;
        }
        i++;
    }
    
    resultat[nb_mots][position_dans_mot] = '\0';
    nb_mots++;
    
    return nb_mots;
}

// Fonction 10: Comparer deux chaines lexicographiquement
int ComparerChaines(const char* chaine1, const char* chaine2) {
    int i = 0;
    
    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i] != chaine2[i]) {
      
            return (unsigned char)chaine1[i] - (unsigned char)chaine2[i];
        }
        i++;
    }
    
    
    return (unsigned char)chaine1[i] - (unsigned char)chaine2[i];
}

// Fonction 11: Transformer en minuscules
void ConvertirMinuscules(char* chaine) {
    int i = 0;
    
    while (chaine[i] != '\0') {
        
        if (chaine[i] >= 'A' && chaine[i] <= 'Z') {
            
            chaine[i] = chaine[i] + ('a' - 'A');
        }
        i++;
    }
}

// Fonction 12: Verifier si la chaine contient que des chiffres
bool EstChaineNumerique(const char* chaine) {
    int i = 0;
    
    
    if (chaine[0] == '-') {
        i = 1;
    }
    
  
    if (chaine[i] == '\0') {
        return false;
    }
    
    
    while (chaine[i] != '\0') {
        if (chaine[i] < '0' || chaine[i] > '9') {
            return false;
        }
        i++;
    }
    
    return true;
}