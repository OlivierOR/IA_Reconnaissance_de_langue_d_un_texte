Prérequis :

Installation de la library fann dont le site officiel est :

https://leenissen.dk/fann/wp/help/installing-fann/

et le dépôt git est accessible à l'adresse ci-dessous :

https://github.com/libfann/fann

1/ Installation de la librarie fann.

#Aller dans votre home.

cd $HOME

#Télécharger le dépot fann.

git clone https://github.com/libfann/fann 

#Aller dans le dépôt cloné.

cd ./fann

#Compiler les sources.

cmake . 

#Pour les utilisateurs d'ubuntu, installation de la library avec un sudo

sudo make install 

#Il sera peut-être nécessaire d'actualiser les liens de la nouvelle librarie avec la commande
#suivante

sudo ldconfig

2 / Compilation des programmes IA_Reconnaissance_de_langue_d_un_texte

