#!/bin/bash

# Chemin de ton dépôt local
BASE_PATH="/Users/sabino/42_lausanne"
# Nom d'utilisateur GitHub
GITHUB_USER="lazzylife42"
# URL de base pour les nouveaux dépôts sur GitHub
GITHUB_BASE_URL="https://github.com/$GITHUB_USER"

# Liste des dossiers à transformer en dépôts indépendants
DIRECTORIES=("cpp" "cub3d" "ft_transcendence" "inception" "libft" "minishell" "net_practice" "philosophers" "pipex" "push_swap" "so_long" "vscode" "webserv")

cd $BASE_PATH

# Vérifier que nous sommes dans le bon répertoire
if [ ! -d ".git" ]; then
    echo "Ce script doit être exécuté depuis le répertoire racine d'un dépôt Git."
    exit 1
fi

# Commit spécifique pour la restauration en cas de problème
SPECIFIC_COMMIT="33a7de80b99489bf73a1f112ceeb31289a7bf473"

# Fonction pour restaurer le commit spécifique en cas de problème
restore_specific_commit() {
    echo "Restauration au commit spécifique..."
    git reset --hard $SPECIFIC_COMMIT
    echo "Restauration terminée."
    exit 1
}

# Pour chaque dossier dans la liste
for DIR in "${DIRECTORIES[@]}"; do
    DIR_PATH="$BASE_PATH/$DIR"
    if [ -d "$DIR_PATH" ]; then
        # Créer le dépôt sur GitHub
        gh repo create "$GITHUB_USER/$DIR" --public --confirm || restore_specific_commit
        
        # Copier le dossier vers un nouveau répertoire indépendant
        cp -r "$DIR_PATH" "$BASE_PATH/../$DIR" || restore_specific_commit
        
        # Aller dans le nouveau répertoire
        cd "$BASE_PATH/../$DIR" || restore_specific_commit
        
        # Initialiser un nouveau dépôt Git
        git init || restore_specific_commit
        git add . || restore_specific_commit
        git commit -m "Initial commit for $DIR" || restore_specific_commit
        
        # Ajouter l'origine
        git remote add origin "$GITHUB_BASE_URL/$DIR.git" || restore_specific_commit
        git push -u origin main || restore_specific_commit
        
        # Retourner au répertoire de base
        cd $BASE_PATH || restore_specific_commit
        
        # Ajouter le dépôt en tant que sous-module dans le dépôt principal
        git submodule add "$GITHUB_BASE_URL/$DIR.git" "$DIR" || restore_specific_commit
        
        # Supprimer le dossier original (optionnel)
        rm -rf "$DIR_PATH" || restore_specific_commit
    else
        echo "Le dossier $DIR n'existe pas."
    fi
done

# Commiter les changements dans le dépôt principal
git add .gitmodules ${DIRECTORIES[@]} || restore_specific_commit
git commit -m "Ajout des sous-modules" || restore_specific_commit
git push origin main || restore_specific_commit

echo "Tous les dossiers ont été transformés en dépôts indépendants et ajoutés en tant que sous-modules."

