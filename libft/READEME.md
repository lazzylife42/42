# Libft

Libft est une bibliothèque de fonctions standard en C développée dans le cadre du cursus à 42 Lausanne.

## Compilation

Pour compiler votre projet avec la bibliothèque libft, vous pouvez suivre les étapes suivantes :

1. Cloner le repository libft dans votre projet :
   ```sh
   git clone https://github.com/lazzylife42/42.git && cd 42/libft
   ```

2. Compilation avec Makefile et inclusion de la bibliothèque libft

	Le Makefile fournit plusieurs cibles pour la compilation de votre projet. Voici les principales cibles et leur utilisation :

- **all**: Cette cible compile votre projet en créant l'exécutable spécifié dans la variable `NAME`.
- **clean**: Cette cible supprime tous les fichiers objets (`.o`) générés lors de la compilation.
- **fclean**: Cette cible supprime tous les fichiers objets et l'exécutable générés lors de la compilation.
- **re**: Cette cible effectue une recompilation complète du projet en exécutant d'abord la cible `fclean` puis la cible `all`.

	```sh
	make all
	make clean
	make fclean
	make re
	```

3. Compilation avec GCC:

	Dans votre ```main.c``` ou ```header.h```, il faudra en suite include la libft:

	```sh
	#include "libft.h"
	```

	Vous pouvez en suite compiler avec GCC comme ceci :
	```sh
	gcc -Wall -Wextra -Werror -I./libft main.c -L./libft -lft -o <mon_executable>
	```
	
## Liste des Fonctions de la libft

### Fonctions de manipulation de chaînes de caractères

- [**ft_strlen**](ft_strlen.c) : Calcule la longueur d'une chaîne de caractères.
- [**ft_strcpy**](ft_strcpy.c) : Copie une chaîne de caractères source dans une destination.
- [**ft_strdup**](ft_strdup.c) : Duplique une chaîne de caractères.
- [**ft_substr**](ft_substr.c) : Extrait une sous-chaîne de caractères à partir d'une chaîne donnée.
- [**ft_strjoin**](ft_strjoin.c) : Concatène deux chaînes de caractères.
- [**ft_strtrim**](ft_strtrim.c) : Supprime les caractères d'espacement au début et à la fin d'une chaîne de caractères.
- [**ft_split**](ft_split.c) : Découpe une chaîne de caractères en mots à l'aide d'un caractère délimiteur.
- [**ft_itoa**](ft_itoa.c) : Convertit un entier en une chaîne de caractères.

### Fonctions de manipulation de mémoire

- [**ft_memset**](ft_memset.c) : Remplit une zone de mémoire avec une valeur spécifique.
- [**ft_bzero**](ft_bzero.c) : Met à zéro les premiers n octets d'une zone de mémoire.
- [**ft_memcpy**](ft_memcpy.c) : Copie les données d'une zone de mémoire source vers une zone de mémoire destination.
- [**ft_memmove**](ft_memmove.c) : Copie les données d'une zone de mémoire source vers une zone de mémoire destination, même si elles se chevauchent.
- [**ft_memchr**](ft_memchr.c) : Recherche la première occurrence d'un caractère dans une zone de mémoire.
- [**ft_memcmp**](ft_memcmp.c) : Compare deux zones de mémoire.

### Fonctions de conversion et de traitement de caractères

- [**ft_isalpha**](ft_isalpha.c) : Vérifie si un caractère est alphabétique.
- [**ft_isdigit**](ft_isdigit.c) : Vérifie si un caractère est numérique.
- [**ft_isalnum**](ft_isalnum.c) : Vérifie si un caractère est alphanumérique.
- [**ft_isascii**](ft_isascii.c) : Vérifie si un caractère appartient à la table ASCII.
- [**ft_isprint**](ft_isprint.c) : Vérifie si un caractère est imprimable.
- [**ft_toupper**](ft_toupper.c) : Convertit une lettre minuscule en majuscule.
- [**ft_tolower**](ft_tolower.c) : Convertit une lettre majuscule en minuscule.
- [**ft_strchr**](ft_strchr.c) : Recherche la première occurrence d'un caractère dans une chaîne.
- [**ft_strrchr**](ft_strrchr.c) : Recherche la dernière occurrence d'un caractère dans une chaîne.
- [**ft_strcmp**](ft_strcmp.c) : Compare deux chaînes de caractères.
- [**ft_strncmp**](ft_strncmp.c) : Compare les n premiers caractères de deux chaînes de caractères.
- [**ft_strnstr**](ft_strnstr.c) : Recherche les n premiers caractères d'une sous-chaîne dans une chaîne.
- [**ft_atoi**](ft_atoi.c) : Convertit une chaîne de caractères en un entier.
- [**ft_atol**](ft_atol.c) : Convertit une chaîne de caractères en un long entier.
- [**ft_calloc**](ft_calloc.c) : Alloue et initialise une zone de mémoire.
- [**ft_putstr_fd**](ft_putstr_fd.c) : Affiche une chaîne de caractères sur un descripteur de fichier donné.
- [**ft_putchar_fd**](ft_putchar_fd.c) : Affiche un caractère sur un descripteur de fichier donné.
- [**ft_putendl_fd**](ft_putendl_fd.c) : Affiche une chaîne de caractères suivie d'un saut de ligne sur un descripteur de fichier donné.
- [**ft_putnbr_fd**](ft_putnbr_fd.c) : Affiche un entier sur un descripteur de fichier donné.
- [**ft_strmapi**](ft_strmapi.c) : Applique une fonction à chaque caractère d'une chaîne de caractères.
- [**ft_striteri**](ft_striteri.c) : Applique une fonction à chaque caractère d'une chaîne de caractères en lui passant son index en premier argument.
- [**ft_strndup**](ft_strndup.c) : Duplique une partie d'une chaîne de caractères.
- [**ft_free_null**](ft_free_null.c) : Libère la mémoire et met le pointeur à `NULL`.



### Fonctions supplémentaires
  

- [**get_next_line**](get_next_line/get_next_line.c) : Lit une ligne d'un descripteur de fichier. La fonction `get_next_line()` permet de lire et de renvoyer la prochaine ligne d'un fichier (ou d'un autre type de descripteur de fichier) à chaque appel. Elle est utile pour la lecture de fichiers ligne par ligne, comme les fichiers texte ou les fichiers de configuration. La fonction est implémentée de manière à gérer automatiquement la taille de lecture, le tamponnage et la gestion de la fin de fichier (EOF), ce qui la rend très pratique pour les applications de lecture de fichiers.

	- Retour positif : Une ligne a été lue avec succès.
	- Retour 0 : La fin du fichier (EOF) a été atteinte.
	- Retour -1 : Une erreur s'est produite lors de la lecture de la ligne.

- [**ft_printf**](ft_printf/ft_printf.c) : Gestion de l'affichage formaté, similaire à la fonction printf de la bibliothèque standard. La fonction `ft_printf()` permet d'afficher des données formatées sur la sortie standard ou sur un descripteur de fichier donné. Elle prend en charge de nombreux spécificateurs de format pour les entiers, les caractères, les chaînes de caractères, les pointeurs, etc. Cette fonction est très flexible et peut être étendue pour prendre en charge des formats personnalisés.

	- **`%c`** : Affiche un caractère. L'argument correspondant doit être un entier représentant le code ASCII du caractère à afficher.

	- **`%s`** : Affiche une chaîne de caractères. L'argument correspondant doit être un pointeur vers la chaîne de caractères à afficher.

	- **`%d` / `%i`** : Affiche un entier signé en base 10. L'argument correspondant doit être un entier de type `int`.

	- **`%u`** : Affiche un entier non signé en base 10. L'argument correspondant doit être un entier non signé de type `unsigned int`.

	- **`%x`** : Affiche un entier non signé en base 16 avec des lettres minuscules. L'argument correspondant doit être un entier non signé de type `unsigned int`.

	- **`%X`** : Affiche un entier non signé en base 16 avec des lettres majuscules. L'argument correspondant doit être un entier non signé de type `unsigned int`.

	- **`%p`** : Affiche un pointeur en base 16. L'argument correspondant doit être un pointeur vers l'adresse mémoire à afficher.


- [**Linked List (llist_a, llist_b, llist_c)**](linked_list/) : Fonctions de gestion de listes chaînées. Ces catégories de fonctions implémentent différentes opérations sur des listes chaînées, telles que l'initialisation d'une liste, l'ajout d'un élément en tête ou en fin de liste, la suppression d'un élément à une position donnée, la fusion de deux listes, la recherche d'un élément dans la liste, etc. Les fonctions sont réparties en trois fichiers pour une meilleure organisation et une séparation des responsabilités.