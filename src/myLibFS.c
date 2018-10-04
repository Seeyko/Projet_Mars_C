#include "LibFS.h"
#include "Disque.h"

typedef struct t_inode 
{ 
    int tf;  //type fichier, 0 data, 1 repertoire
    int sz;  // taille en octets
    int adr[30];  // adresses des blocs
} inode;

// variable errno pour gerer les erreurs
/*Gestion des erreurs: Pour signaler les erreurs, les fonctions devront retourner une
valeur spécifique (-1 par exemple) et affecter un code d’erreur à la variable globale
osErrno. ​ Ceci va permettre aux programmes qui utilisent votre libraire de détecter
qu’une erreur s’est produite et surtout avoir des informations sur la nature de l’erreur
*/
int osErrno;

//_______________________                        ________________
//_______________________FONCTION GENERIQUE DU FS________________|

// Initialisation
/*Cette fonction devra être appelée une seule fois
avant de pouvoir utiliser les autres fonctions du FS. Le paramètre ‘path’ est le
chemin (dans la machine ​ hôte ​ ) vers l’image du disque utilisée par myLibFS.
Si ce fichier n’existe pas, il devra être créé et initialisé correctement pour être
utilisé par myLibFS (formattage). En cas de succès cette fonction retourne 0
et en cas d’erreur, elle retourne -1 et met la valeur E_GENERAL dans
osErrno*/
int FS_Boot(char *path)
{
    printf("FS_Boot %s\n", path);
    
    //Erreur lors de l'initialisation du disque
    if (Disk_Init() == -1) {
	   printf("Disk_Init() failed\n");
	   osErrno = E_GENERAL;
	   return -1;
    }//Initialisation du disque réussi
    else{

    }

    // TODO...

    return 0;
}

/*Cette fonction va assurer l’écriture de toutes les données sur
le disque. En effet, pour améliorer les performances, vous pourrez retarder les
opérations d’écriture (souvent coûteuses) jusqu’à l’appel de FS_Sync. Cette
fonction retourne 0 en cas de succès et la valeur -1 en cas d’erreur, auquel cas
la variable osErrno aura la valeur E_GENERAL*/
int FS_Sync()
{
    printf("FS_Sync\n");
    // TODO...
    return 0;
}


//_______________________                        ________________
//_______________________API D'ACCÈS AUX FICHIERS________________|
/*
Spécification des chemins: Nous allons prendre l’hypothèse que tous les chemins sont
absolus. Par conséquent, tous les chemins vont commencer par le répertoire racine “/”. Les
noms de fichiers sont limités à 16 caractères (15 octets pour le nom et un octet pour le
caractère de fin de string ‘\0’) Enfin, la taille maximale d’un chemin est fixée à 256
caractères.
*/


/*
Crée un nouveau fichier désigné par ​ file . ​ Si le fichier
existe, vous devez retourner la valeur -1 et mettre osErrno à E_CREATE.
*/
int File_Create(char *file)
{
    printf("FS_Create\n");
    // TODO...
    return 0;
}
/*
​ ouvre le fichier désigné par ​ file e ​ t retourne un descripteur
(un entier >= 0) qui sera utilisé pour lire/écrire sur ce fichier. Si le fichier n’existe pas
ou que le nombre maximum de fichiers ouverts est atteint, la valeur -1 est retournée et
la variable osErrno aura comme valeur E_NO_SUCH_FILE et E_TOO_MANY_OPEN_FILES respectivement.
*/
int File_Open(char *file)
{
    printf("FS_Open\n");
    // TODO...
    return 0;
}

/*
​ cette fonction va lire ​ size ​ octets du
fichier désigné par le descripteur ​ fd ​ et les copier dans ​ buffer. L
a lecture sera fera à
partir de la position actuelle du pointeur du fichier (i.e la tête de lecture/écriture); la
position du pointeur de fichier sera mise à jour après la lecture. Si le fichier n’est pas
ouvert, alors la fonction retourne -1 et osErrno aura comme valeur E_BAD_FD. Si le
fichier est ouvert, alors le nombres d’octets effectivement lus sera retourné. Si le
pointeur est à la fin du fichier alors la fonction retournera la valeur 0.
*/
int File_Read(int fd, void *buffer, int size)
{
    printf("FS_Read\n");
    // TODO...
    return 0;
}

/*
​ cette fonction va écrire ​ size o ​ ctets à
partir de ​ buffer d ​ ans le fichier désigné par ​ fd. L’écriture se fera à partir du pointeur ​ du
fichier qui sera mis à jour après l’opération d’écriture. Voici la description des retours
possibles pour cette fonction:
 ○ Si le fichier n’est pas ouvert alors cette fonction devra renvoyer la valeur -1 et 
   mettre le code erreur ​ E_BAD_FD dans la variable osErrno.
 ○ En cas de succès, le nombre d’octets écrits sera retourné.
 ○ En cas d’écriture partielle (espace insuffisant par exemple), alors la fonction
   retournera -1 et mettra la valeur E_NO_SPACE dans osErrno.
 ○ Si la taille du fichier dépasse la taille max, alors la valeur -1 est retournée et le
   code E_FILE_TOO_BIG sera mis dans osErrno
*/

int File_Write(int fd, void *buffer, int size)
{
    printf("FS_Write\n");
    // TODO...
    return 0;
}

/*
​Cette fonction va modifier la valeur du pointeur de
fichier désigné par ​fd. La position du pointeur de fichier sera calculée comme un
décalage de ​ offset octets à partir du début du fichier. Les codes retours de la fonction
sont:
  ○ Si le décalage ​ offset est plus grand que la taille du fichier ou négatif alors la
    fonction retourne -1 et osErrno prend la valeur E_SEEK_OUT_OF_BOUNDS
  ○ Si le fichier n’est pas ouvert, alors la fonction retourne -1 et osErrno prend la
    valeur E_BAD_FD.
  ○ En cas de succès, la fonction retourne la valeur du pointeur de fichier.
*/
int File_Seek(int fd, int offset)
{
    printf("FS_Seek\n");
    // TODO...
    return 0;
}

/*
cette fonction ferme le fichier désigné par le descripteur ​ fd. Si
le fichier n’est pas ouvert alors la valeur -1 est retournée et ​ osErrno prend la valeur
E_BAD_FD. En cas de succès, cette fonction retourne la valeur 0.
*/
int File_Close(int fd)
{
    printf("FS_Close\n");
    // TODO...
    return 0;
}
/*
cette fonction va supprimer le fichier désigné par ​ file. Il
faudra supprimer le nom du fichier du répertoire contenant et libérer tous les blocs de
données et inodes utilisés. Si le fichier n’existe pas, la fonction retourne -1 et met
E_NO_SUCH_FILE dans osErrno. Si le fichier est actuellement ouvert alors la valeur
-1 et renvoyée et osErrno aura comme valeur E_FILE_IN_USE. En cas de succès,
cette fonction retourne la valeur 0.
*/
int File_Unlink(char *file)
{
    printf("FS_Unlink\n");
    // TODO...
    return 0;
}


//_______________________                              ________________
//_______________________API DE GESTION DES REPERTOIRES________________|


/*
​ création d’un nouveau répertoire désigné par ​ path . ​ La
création d’un répertoire se fera en deux étapes: i) création d’un fichier de type
‘directory’; ii) ajout d’une nouvelle entrée dans le répertoire contenant avec le
nom et le numéro d’inode du nouveau répertoire. En cas d’erreur, la valeur -1
est renvoyée et o ​ sErrno est mise à E_CREATE.
*/
int Dir_Create(char *path)
{
    printf("Dir_Create %s\n", path);
    // TODO ...
    return 0;
}
/*
retourne la taille en octets du répertoire désigné par ​ path.
Attention, ce n’est pas la taille des fichiers contenus dans le répertoire mais la taille de
la structure du répertoire déterminée par le nombre d’entrées. Cette fonction est utile
pour avoir la taille des entrées avant d’utiliser la fonction de lecture Dir_Read
*/
int Dir_Size(char *path)
{
    printf("Dir_Size\n");
    // TODO ...
    return 0;
}

/*
Cette fonction va lire le contenu d’un répertoire qui sera copié dans le segment mémoire à partir de ​ buffer. I ​ l s’agit de
lister toutes les entrées du répertoire. Chaque entrée est un tableau de 20 octets: 16
octets pour le nom du fichier ou répertoire contenu et 4 octets pour coder le numéro d’inode de cette entrée. ​ size ​ est la taille max du ​ buffer ​ ; si cette taille est insuffisante
pour contenir toutes les entrées, la fonction retourne la valeur -1 et osErrno prend la
valeur E_BUFFER_TOO_SMALL. En cas de succès, le nombre d’entrées sera
retourné
*/
int Dir_Read(char *path, void *buffer, int size)
{
    printf("Dir_Read\n");
    // TODO ...
    return 0;
}

/*
​ Cette fonction va supprimer le répertoire désigné par
path. ​ Les blocs mémoires ainsi que l’inode seront libérés ainsi que l’entrée dans le
répertoire père. Si le répertoire n’est pas vide alors la fonction retourne -1 et met le
code erreur E_DIR_NOT_EMPTY dans osErrno. Si ​ path désigne le répertoire racine
(“/”) racine, alors la fonction retourne -1 et met le code erreur E_ROOT_DIR dans
osErrno.
*/
int Dir_Unlink(char *path)
{
    printf("Dir_Unlink\n");
    // TODO ...
    return 0;
}
