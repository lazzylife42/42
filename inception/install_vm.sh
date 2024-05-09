#!/bin/bash

# Step 1: Installing Sudo
echo -e "\e[32m1 / Installing Sudo\e[0m"
su -
apt-get update -y
apt-get upgrade -y
apt install sudo
usermod -aG $USER
sudo visudo

# Step 2: Installing Vim
echo -e "\n\e[32m2 / Installing Vim\e[0m"
apt-get install vim -y
apt-get install make -y

# Step 3: Installing and Configuring SSH
echo -e "\n\e[32m3 / Installing and Configuring SSH (Secure Shell Host)\e[0m"
sudo apt install openssh-server
sudo systemctl status ssh
sudo vim /etc/ssh/sshd_config
sudo grep '#Port 22' /etc/ssh/sshd_config && sudo sed -i 's/#Port 22/Port 4242/' /etc/ssh/sshd_config
sudo grep Port /etc/ssh/sshd_config
sudo service ssh restart

# Step 4: Installing and Configuring UFW
echo -e "\n\e[32m4 / Installing and Configuring UFW (Uncomplicated Firewall)\e[0m"
apt-get install ufw
sudo ufw enable
sudo ufw status numbered
sudo ufw allow ssh
sudo ufw allow 4242
sudo ufw status numbered

# Step 5: Creating a shared folder
echo -e "\n\e[32m5 / Creating a shared folder\e[0m"
sudo mkdir /mnt/inception
sudo mount -t vboxsf inception /mnt/inception

# Step 6: Installing Docker and Docker Compose
echo -e "\n\e[32m6 / Installing Docker and Docker Compose\e[0m"
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


# Instructions for VirtualBox
echo -e "\n\e[36m--- VirtualBox Instructions ---\e[0m"
echo "1. Ouvrez VirtualBox et sélectionnez votre machine virtuelle."
echo "2. Accédez aux paramètres de la machine virtuelle."
echo "3. Cliquez sur 'Réseau', puis sur 'Adaptateur 1'."
echo "4. Cliquez sur 'Avancé' et sélectionnez 'Transfert de ports'."
echo "5. Modifiez les champs 'Port hôte' et 'Port invité' pour correspondre au port SSH (4242)."
echo "6. Retournez à votre machine virtuelle."
echo "7. Redémarrez le service SSH avec la commande 'sudo systemctl restart ssh'."
echo "8. Vérifiez l'état du service SSH avec 'sudo service ssh status'."
echo "9. Utilisez un terminal pour vous connecter via SSH avec 'ssh your_username@127.0.0.1 -p 4242'."
echo "10. Si une erreur se produit, supprimez le fichier known_hosts avec 'rm ~/.ssh/known_hosts' et réessayez."
