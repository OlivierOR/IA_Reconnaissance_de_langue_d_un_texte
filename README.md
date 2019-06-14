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


2 / Compilation et description des programmes IA_Reconnaissance_de_langue_d_un_texte

Commande de compilation :

Calcul_frequence_lettre_texte

g++ Calcul_frequence_lettre_texte.cpp -o Calcul_frequence_lettre_texte.cpp

Description :

Ce programme sert à constituer notre échantillon de données qui va servir à l'apprentissage du réseau de neuronnes.
Cet échantillon sera constitué dans le fichier f.data .
Pour un texte passer en entrée de ce programme, celui va calculer la fréquence de chacune des 26 lettres de l'alphabet sur le nombre totale de lettre (uniquement) du texte. 

Exemple d'exécution sur le texte ci-dessus (Ce programme sert [...] du texte.) :

./Calcul_frequence_lettre_texte Exemple_Calcul_frequence_lettre_texte.txt 
0.0746269 0.00746269 0.0522388 0.0447761 0.179104 0.011194 0.011194 0.0186567 0.0410448 0 0 0.0597015 0.0223881 0.0820896 0.0447761 0.0261194 0.011194 0.0858209 0.0597015 0.0895522 0.0597015 0.011194 0 0.00746269 0 0 

Calcul_frequence_lettre_texte2

Commande de compilation :

g++ Calcul_frequence_lettre_texte2.cpp -o Calcul_frequence_lettre_texte2.cpp

Description :

C'est un programme qui détaille plus que le précédent, il permet de contrôler le nombre total de caractères trouvés ainsi que le nombre total de lettres trouvées.

Exemple : 

./Calcul_frequence_lettre_texte2 Exemple_Calcul_frequence_lettre_texte.txt 
Nombre de lettres total :268
Nombre de la lettre A :20
Nombre de la lettre B :2
Nombre de la lettre C :14
Nombre de la lettre D :12
Nombre de la lettre E :48
Nombre de la lettre F :3
Nombre de la lettre G :3
Nombre de la lettre H :5
Nombre de la lettre I :11
Nombre de la lettre J :0
Nombre de la lettre K :0
Nombre de la lettre L :16
Nombre de la lettre M :6
Nombre de la lettre N :22
Nombre de la lettre O :12
Nombre de la lettre P :7
Nombre de la lettre Q :3
Nombre de la lettre R :23
Nombre de la lettre S :16
Nombre de la lettre T :24
Nombre de la lettre U :16
Nombre de la lettre V :3
Nombre de la lettre W :0
Nombre de la lettre X :2
Nombre de la lettre Y :0
Nombre de la lettre Z :0
Fréquence de chaque lettre pour le nombre total de lettres du texte
0.0746269 0.00746269 0.0522388 0.0447761 0.179104 0.011194 0.011194 0.0186567 0.0410448 0 0 0.0597015 0.0223881 0.0820896 0.0447761 0.0261194 0.011194 0.0858209 0.0597015 0.0895522 0.0597015 0.011194 0 0.00746269 0 0 

Perceptron_a_2_couches.c

Commande de compilation :

g++ Perceptron_a_2_couches.c -o Perceptron_a_2_couches -lfann

Description :

Une fois notre échantillons de données pour l'apprentissage effectué, ce programme Perceptron_a_2_couches est le réseau de neuronnes qui va s'entraîner à partir de cette échantillon de données pour l'apprentissage. 

Il comporte 26 entrées, pour la fréquence des 26 lettres de l'alphabet et 3 sorties qui correspondent aux 3 neuronnes qui vont déterminer la probablité qu'un texte soit dans une des trois langues choisies.

Le programme se base sur les entrées fournies dans le fichier f.data .
On peut jouer sur différents paramètres tel que le taux d'erreur voulu :

    const float desired_error = (const float) 0.000000001;
    
Et le nombre d'itérations voulues :

    const unsigned int max_epochs = 20000000;

Exemple : 
./Perceptron_a_2_couches 
...
Epochs     11076300. Current error: 0.0000000020. Bit fail 0.
Epochs     11076400. Current error: 0.0000000026. Bit fail 0.
Epochs     11076500. Current error: 0.0000000029. Bit fail 0.
Epochs     11076540. Current error: 0.0000000010. Bit fail 0.

(Affichage des quatre dernières lignes de l'exécution du programme)

Un fichier langue.net est ainsi constitué grâce aux exemples appris dans le fichier f.data.

C'est ce fichier langue.net qui constitue clairement notre réseau neuronal optimisé qui va nous permettre de 
reconnaître quelle est la probabilité qu'un texte est écrit en une langue. 

Detection_de_la_langue.cpp

Commande de compilation :

g++ Detection_de_la_langue.cpp -o Detection_de_la_langue -lfann

Description 

Ce programme va créer un réseau de neuronne idoine à partir des données d'apprises dans le fichier langue.net .

Par exemple, pour connaître la probabilité de l'origine de langue du poème "La mort du loup d'Alfred de Vigny"

./Detection_de_la_langue Exemple-Vigny.txt 
Francais: 0.999951
Espagnol : -0.931117
Anglais : -0.344159



