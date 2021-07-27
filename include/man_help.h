/*
** EPITECH PROJECT, 2021
** B-PSU-210-PAR-2-1-42sh-yoel.edery
** File description:
** man_help
*/

#ifndef MAN_HELP_H_
#define MAN_HELP_H_

#include <stdlib.h>

typedef struct {
    const char *name;
    const char *description;
} man_t;

static const char alias[] =
"ALIAS                              "
"            42sh Programmer's Manual    "
"                                    ALIA"
"S\n\nNAME\n        alias : Creer un"
" raccourci vers une commande.\n\nDESCRIP"
"TION\n\n        La commande alias p"
"ermet a l'utilisateur de creer une nouvel"
"le commande vers une commande\n   "
"     existante.\n\nFLAGS\n\n        alias"
" :\n                Affiche toutes"
" les commandes qui ont ete creees comme ra"
"ccourci par l'utilisateur.\n\n   "
"     alias [NAME] [COMMAND] :\n           "
"     Recupere la COMMAND qui sera"
" afficher sur la sortie standard de l'util"
"isateur lorsque\n                "
"celui-ci execute le nouveau nom donne a NA"
"ME.\n";

static const char cd[] = "CD               "
"                               42"
"sh Programmer's Manual                                                CD\n"
"\nNAME\n        cd : Change le dossier dan"
"s lequel nous sommes.\n\nDESCRIPT"
"ION\n\n        Si aucun(s) parametre(s) n'"
"est precise pour la commande 'cd'"
", l'utilisateur est redirige instantanemen"
"t\n        au dossier par defaut "
"(celui au 'root').\n\nFLAGS\n\n        cd "
"~ : Redirige l'utilisateur au dos"
"sier par defaut (celui au 'root').\n\n    "
"    cd .. : Redirige l'utilisateu"
"r au dossier parent. C'est a dire, le doss"
"ier qui est juste avant\n        "
"        le dossier actuel.\n\n        cd -"
" : Redirige l'utilisateur vers le"
" dossier precedent.\n\n        cd [NAME] :"
" Redirige l'utilisateur vers le d"
"ossier precise dans [NAME].\n";

static const char dredirl[] = "DB_REDIRLEFT"
"                                 "
"         42sh Programmer's Manual         "
"                               DB"
"_REDIRLEFT\n\nNAME\n        double redirect"
"ion gauche : Recherche le nom qu"
"i sera mit apres l'element.\n\nDESCRIPTION"
"\n\n        La double redirection"
" vers la gauche, creer une boucle dans le "
"terminal de l'utilisateur.\n     "
"   Lorsque l'utilisateur est present dans "
"la boucle, pour en sortir, il est"
" necessaire pour\n        lui d'ecrire le "
"mot qui a ete mit apres l'element"
" de la double redirection. Apres que le\n "
"       mot ai ete trouve, l'utili"
"sateur quitte alors la boucle, et executer"
"a la commande qui a\n        ete "
"place juste avant l'element.\n        ATTE"
"NTION : Il est important de note "
"qu'un mot doit etre mit a droite de l'elem"
"ent et qu'une\n        commande a"
"i ete mit a gauche de l'element.\n\n      "
"  Exemple de commande :\n        "
"    ls << exemple\n";

static const char dredirr[] = "DB_REDIRRIGH"
"T                                "
"          42sh Programmer's Manual        "
"                                D"
"B_REDIRRIGHT\n\nNAME\n        double redir"
"ection droite : Écrit le contenu "
"de la commande dans un fichier.\n\nDESCRIP"
"TION\n\n        La redirection si"
"mple vers la droite, ecrit le contenu de l"
"a commande qui precede\n        l"
"a redirection vers la droite, dans un fichi"
"er precise apres la redirection "
"vers\n        droite. Si le fichier n'existe"
" pas, le fichier se creer et ec"
"rit le contenu de la\n        commande dans "
"le fichier, si le fichier exist"
"e, la commande precise ecrira alors,\n      "
"  a la suite du fichier, le con"
"tenu de la commande precise.\n\n        Exem"
"ple de commande :\n            "
"ls >> file.txt\n";

static const char env[] = "ENV          "
"                                42sh"
" Programmer's Manual                    "
"                    ENV\n\nNAME\n  "
"      env : Affiche toutes les variables "
"de l'environnement.\n\nDESCRIPTION"
"\n\n        La commande 'env' permet d'af"
"ficher l'ensemble des variables pr"
"esente dans l'environnement\n        de b"
"ase de l'utilisateur.\n";

static const char my_exit[] = "EXIT       "
"                                  "
" 42sh Programmer's Manual                "
"                        EXIT\n\nNA"
"ME\n        exit : Permet de sortir de la "
"ligne de commande de base du term"
"inal.\n\nDESCRIPTION\n\n        La commande"
" 'exit' permet a l'utilisateur d"
"e kill le terminal dans lequel il est prese"
"nt.\n        Si plusieurs termin"
"aux ont ete ouvert a la suite, plusieurs exi"
"t a la suite seront\n        de"
"mandes pour pouvoir quitter tous les terminaux.\n";

static const char history[] = "HISTORY       "
"                               "
"    42sh Programmer's Manual                "
"                        HISTORY"
"\n\nNAME\n        history : Affiche les anci"
"ennes commandes executees.\n\nD"
"ESCRIPTION\n\n        La commande 'history' "
"permet d'afficher sur la sortie"
" standard, toutes les commandes\n        qui"
" ont ete autrefois executees pa"
"r l'utilisateur.\n";

static const char my_pipe[] = "PIPE          "
"                               "
" 42sh Programmer's Manual                    "
"                    PIPE\n\nNA"
"ME\n        pipe : Creer un lien entre la sor"
"tie standard et l'entree stand"
"ard.\n\nDESCRIPTION\n\n        Lorsque sur la"
" ligne de commande, l'element "
"'pipe' ('|') a ete trouve sur la ligne de com"
"mande,\n        celle-ci est p"
"ercue comme etant presente pour passer le res"
"ultat d'une commande a une aut"
"re\n        commande.\n\n        Exemple de c"
"ommande :\n            cat Mak"
"efile | grep o\n";

static const char redirl[] = "REDIRLEFT       "
"                              "
"     42sh Programmer's Manual                "
"                        REDIRL"
"EFT\n\nNAME\n        redirection gauche : Aff"
"iche le contenu d'un fichier."
"\n\nDESCRIPTION\n\n        La redirection sim"
"ple vers la gauche, affiche le"
" contenu d'un fichier sur la sortie\n        "
"standard de l'utilisateur.\n"
"\n        Exemple de commande :\n            "
"cat < file.txt\n";

static const char redirr[] = "REDIRRIGHT     "
"                               "
"      42sh Programmer's Manual               "
"                         REDIR"
"RIGHT\n\nNAME\n        redirection gauche : Éc"
"rit le contenu de la commande"
" dans un fichier.\n\nDESCRIPTION\n\n        La"
" redirection simple vers la d"
"roite, ecrit le contenu de la commande qui pr"
"ecede\n        la redirection "
"vers la droite, dans un fichier precise apres "
"la redirection vers\n        "
"droite. Si le fichier n'existe pas, le fichier"
" se creer et ecrit le contenu"
" de la\n        commande dans le fichier, si l"
"e fichier existe, la commande"
" precise ecrasera alors\n        tous le conte"
"nu du fichier existant.\n\n  "
"      Exemple de commande :\n            ls > file.txt\n";

static const char semicolon[] = "SEMICOLON     "
"                             "
"        42sh Programmer's Manual              "
"                          SEM"
"ICOLON\n\n\nNAME\n        semicolon : Éxecute "
"la commande suivant la premie"
"re.\n\nDESCRIPTION\n\n        Lorsque sur la l"
"igne de commande, l'element '"
"semicolon' (';') a ete trouve sur la ligne de "
"commande,\n        la command"
"e qui suit cette element ainsi que celle qui l"
"a precede, seront execute sur"
" la sortie\n        standard, l'une a la suite"
" de l'autre (ou des autres si"
" plusieurs semicolon sont present).\n\n       "
" Exemple de commande :\n     "
"       ls;ls -d || ls; lsd -l ; ls -l ;ls -R |"
"| ls;;;ls -a\n";

static const char my_setenv[] = "SETENV        "
"                             "
"     42sh Programmer's Manual                 "
"                       SETENV"
"\n\nNAME\n        setenv : Change ou ajoute un"
"e variable a l'environnement."
"\n\nDESCRIPTION\n\n        La commande 'setenv"
"' permet de changer une varia"
"ble dans l'environnement si celle-ci est\n    "
"    presente dans l'environne"
"ment. Si la variable n'existe pas dans l'envir"
"onnement, elle est\n        a"
"joute dans l'environnement a la fin de toutes "
"les variables.\n\nEXEMPLES\n"
"\n        setenv :\n                Si la comm"
"ande est execute sans autres "
"parametres, elle affichera l'environnement\n  "
"              de base.\n\n   "
"     setenv [NAME] :\n                La comma"
"nde 'setenv' suivi d'une vari"
"able compose de lettre alphanumerique\n       "
"         (non numerique pour"
" le premier caractere), ajoutera la variable d"
"ans l'\n                envi"
"ronnement.\n\n        setenv [NAME] [VALUE] :"
"\n                La commande '"
"setenv' suivi d'une variable compose de lettre"
" alphanumerique\n           "
"     (non numerique pour le premier caractere)"
" et d'une autre variable, ajo"
"utera la\n                variable dans l'envi"
"ronnement.\n\n        setenv "
"[NAME] [VALUE] [OTHER] :\n                Si 3"
" parametres (ou plus) sont do"
"nnes a la commande 'setenv', un\n             "
"   message d'erreur sera alor"
"s afficher sur la sortie standard.\n";

static const char my_unsetenv[] = "UNSETENV        "
"                         "
"         42sh Programmer's Manual                  "
"                      UN"
"SETENV\n\nNAME\n        unsetenv : Retire une ou p"
"lusieurs variable a l'env"
"ironnement.\n\nDESCRIPTION\n\n        La commande "
"'unsetenv' permet, si la "
"variable existe, de retirer cette element presente"
"\n        dans l'environn"
"ement. Il est aussi possible de retirer plusieurs "
"element de l'environnemen"
"t\n        a partir de la meme commande.\n\nFLAGS"
"\n\n        unsetenv :\n  "
"              Si 'unsetenv' est execute seul, elle"
" affichera un message d'e"
"rreur sur la\n                sortie standard.\n\n"
"        unsetenv [...] :"
"\n                Si la commande 'unsetenv', suivi"
" de un ou plusieurs varia"
"ble(s), est execute\n                elle retirera"
" la ou les element(s) pre"
"sente(nt) dans l'environnement.\n";

static const char global[] = "42SH             "
"                             "
"42sh Programmer's Manual                      "
"                  42SH\n\nDES"
"CRIPTION\n        Bienvenue dans le menu help "
"pour le 42SH.\n\nFLAGS\n     "
"   alias:\n\n            alias : Creer un racc"
"ourci vers une commande.\n   "
"     cd:\n\n            cd : Change le dossier"
" dans lequel nous sommes.\n"
"\n        dredirl:\n\n            double redir"
"ection gauche : Recherche le "
"nom qui sera mit apres l'element.\n\n        d"
"redirr:\n\n            doubl"
"e redirection droite : Écrit le contenu de la "
"commande dans un fichier.\n"
"\n        env:\n\n            env : Affiche to"
"utes les variables de l'envir"
"onnement.\n\n        exit:\n\n            exit"
" : Permet de sortir de la lig"
"ne de commande de base du terminal.\n\n       "
" history:\n\n            hist"
"ory : Affiche les anciennes commandes executee"
"s.\n\n        pipe:\n\n      "
"      pipe : Creer un lien entre la sortie sta"
"ndard et l'entree standard.\n"
"\n        redirl:\n\n            redirection g"
"auche : Affiche le contenu d'"
"un fichier.\n\n        redirr:\n\n            "
"redirection gauche : Écrit le"
" contenu de la commande dans un fichier.\n\n  "
"      semicolon:\n\n         "
"   semicolon : Éxecute la commande suivant la "
"premiere.\n\n        setenv:"
"\n\n            setenv : Change ou ajoute une "
"variable a l'environnement."
"\n\n        unsetenv:\n\n            unsetenv "
": Retire une ou plusieurs v"
"ariable a l'environnement.\n";

static const man_t DESCRIPTION_CASE[] =
{
    {"global", global},
    {"alias", alias},
    {"cd", cd},
    {"dredirl", dredirl},
    {"dredirr", dredirr},
    {"env", env},
    {"exit", my_exit},
    {"history", history},
    {"pipe", my_pipe},
    {"redirl", redirl},
    {"redirr", redirr},
    {"semicolon", semicolon},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {NULL, NULL},
};

#endif /* !MAN_HELP_H_ */
