42sh
Creation d'un shell complet en langage C gerant toutes les fonctionnalitees decrites ci-dessous. Projet de Epitech soumis a la norme de celle-ci.

Fonctionnalitees
Affichage et edition de ligne :

Affichage d’un prompt.
Lecture de la ligne de commande.
Gestion correcte des espaces et des tabulations.
Ecrire et editer une commande sur plusieurs lignes.
Utiliser les fleches du haut et du bas pour naviguer dans l’historique des commandes.
Aller directement au debut et a la fin d’une ligne avec home et end.
Les builtins suivantes avec toutes leurs options si elles en ont (au strict minimum les options dictees par le standard POSIX) :

alias
cd
exit
env
foreach
getenv
jobs
repeat
setenv
unsetenv
where
which

Execution de commandes simples avec leurs parametres et gestion du PATH :

Gestion des erreurs et de la valeur de retour des commandes
Les operateurs de redirection suivants : ">", ">>", "<" et "|".
Les operateurs logiques "&&" et "||".
Le separateur ";".
Features supplementaires :

Les inhibiteurs """ (double quote), "’" (simple quote), "" (backslash).
Les redirections avancees : l’aggregation des sorties de fichier et le heredoc "<<".
Les variables locales (setvar) et les builtin unset et export.
L’historique des commandes et les builtins history et "!" avec toutes leurs options si elles en ont.
Completion dynamique.
Tests

Pour lancer le shell, lancez la commande suivante :

make ; ./42sh

Contributeurs :
- Yoel Edery
- Valentin Fouillet
- Illyas Chihi
- Thomas Willson
- Yohan Henry
