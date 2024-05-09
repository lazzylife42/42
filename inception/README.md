# INCEPTION
---
## Part 1 | Configuration de l'environnement de développement

### Étape 1 : Installation de Sudo

```bash
su -
apt-get update -y
apt-get upgrade -y
apt install sudo
usermod -aG $USER
sudo visudo
```

### Étape 2 : Installation de Vim et Make

```bash
apt-get install vim -y
apt-get install make -y
```

### Étape 3 : Installation et configuration de SSH

```bash
sudo apt install openssh-server
sudo systemctl status ssh
sudo vim /etc/ssh/sshd_config
sudo grep '#Port 22' /etc/ssh/sshd_config && sudo sed -i 's/#Port 22/Port 4242/' /etc/ssh/sshd_config
sudo grep Port /etc/ssh/sshd_config
sudo service ssh restart
```

### Étape 4 : Installation et configuration de UFW

```bash
apt-get install ufw
sudo ufw enable
sudo ufw status numbered
sudo ufw allow ssh
sudo ufw allow 4242
sudo ufw status numbered
```

### Étape 5 : Création d'un dossier partagé

```bash
sudo mkdir /mnt/inception
sudo mount -t vboxsf inception /mnt/inception
```

### Étape 6 : Installation de Docker et Docker Compose

```bash
sudo apt update
sudo apt install apt-transport-https ca-certificates curl software-properties-common
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo apt-key add -
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/debian $(lsb_release -cs) stable"
sudo apt update
sudo apt install docker-ce docker-ce-cli containerd.io
sudo docker --version
sudo usermod -aG docker $USER
sudo apt install docker-compose
mkdir -p /home/$USER/data/mariadb
mkdir -p /home/$USER/data/wordpress
```
### Instructions pour VirtualBox

1. Ouvrez VirtualBox et sélectionnez votre machine virtuelle.
2. Accédez aux paramètres de la machine virtuelle.
3. Cliquez sur 'Réseau', puis sur 'Adaptateur 1'.
4. Cliquez sur 'Avancé' et sélectionnez 'Transfert de ports'.
5. Modifiez les champs 'Port hôte' et 'Port invité' pour correspondre au port SSH (4242).
6. Retournez à votre machine virtuelle.
7. Redémarrez le service SSH avec la commande `sudo systemctl restart ssh`.
8. Vérifiez l'état du service SSH avec `sudo service ssh status`.
9. Utilisez un terminal pour vous connecter via SSH avec `ssh your_username@127.0.0.1 -p 4242`.
10. Si une erreur se produit, supprimez le fichier known_hosts avec `rm ~/.ssh/known_hosts` et réessayez.
