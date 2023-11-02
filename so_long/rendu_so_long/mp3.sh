# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mp3.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:17:55 by smonte-e          #+#    #+#              #
#    Updated: 2023/11/02 15:17:56 by smonte-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Vérification des arguments
if [ $# -ne 1 ]; then
  echo "Usage: $0 <nom_du_fichier>"
  exit 1
fi

# Nom du fichier à modifier
file="$1"

# Vérification de l'existence du fichier
if [ ! -f "$file" ]; then
  echo "Le fichier $file n'existe pas."
  exit 1
fi

# Vérification si la ligne 28 contient "src/state.c"
if grep -q "src/state.c" "$file"; then
  # Remplacer "src/state.c" par "src/state_bonus.c" à la ligne 28
  sed -i '' '28s/src\/state\.c/src\/state_bonus\.c/' "$file"
  echo "Remplacement effectué : src/state.c remplacé par src/state_bonus.c à la ligne 28."
else
  # Vérification si la ligne 28 contient "src/state_bonus.c"
  if grep -q "src/state_bonus.c" "$file"; then
    # Remplacer "src/state_bonus.c" par "src/state.c" à la ligne 28
    sed -i '' '28s/src\/state_bonus\.c/src\/state\.c/' "$file"
    echo "Remplacement effectué : src/state_bonus.c remplacé par src/state.c à la ligne 28."
  else
    echo "Aucune occurrence de src/state.c ou src/state_bonus.c à la ligne 28."
  fi
fi

# Exécuter `make re`
make re
