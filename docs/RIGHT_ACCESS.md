<!--

	RIGHT_ACCESS.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/17

-->
# 42cursus - PIPEX - Les droits d'Accès

Le projet nous met fasse à un problème les droits d'accès.
On parlera de droits en **lecture**, **écriture** et **exécution**.

Du faite de la limite en fonctions autorisées, nous allons devoir donc jouer
d'astuce pour faire nos vérifications.

## Les SETUID et SETGID

**Sur les exécutables**

Cela permet de lancer le processus à travers le nom d'un autre utilisateur.

> /!\ La sécurité peut être rompue si une application de droit `root` dispose
> d'une `setuid`.

**Sur les dossiers**

> `setuid` fonctionne uniquement sur les fichiers pour les systèmes UNIX.

Le fonctionnement diffère ici, dans le cas oû un `setgid` est appliqué à un
dossier tout les sous-dossiers et fichiers appartiendrons au groupe de dossier
qui aura cette particularité et donc en hériterons. _Sauf si les sous-dossiers
et fichiers sont déjà existants._

**Documentations**

_Un article sur [Wikipedia](https://fr.wikipedia.org/wiki/Setuid) permet de
mieux comprendre le fonctionnement._

## Réflexions sur nos besoins

**infile**

Nous devons avoir au minimum le droit de lecture via nos droits ou via le
`setuid` de l'application afin de pouvoir récupérer son contenu.

**les commandes**

Nous devons avoir au minimum le droit exécution via nos droits ou via le
`setuid` de l'application appelante, afin de pouvoir lancer la commande.

**outfile**

Nous devons avoir au minimum le droit d'écriture vers le futur fichier où l'on
voudrait écrire les résultats.

**Gestion des erreurs**

Il nous faudra donc effectuer une gestion des erreurs pour les problèmes
de droits. Je détails celan dans la documentation
[gestion des erreurs](./ERRORS_HANDLERS.md)
