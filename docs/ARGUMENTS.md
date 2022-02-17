<!--

	ARGUMENTS.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/17

-->
# 42cursus - PIPEX - Les Arguments et les Variables d'Environnement

Dans cette partie, nous allons parler des arguments récupérables par un
processus. Donc via notre `main()` et par conséquent aussi notre fonction
`execve()`.

## La fonction `main()`

Comme toute programme exécutable en C nous avons une fonction `main()`. On la
connait habituellement sous deux formes de prototype :

```C
# prototype simple
int	main(void);

# prorotype avec arguments
int	main(int argc, char *argv[]);
```

> On parle ici de définition ISO C.

**Les paramètres d'environnement**

Mais, il y a un troisième paramètre possible. (D'ailleurs l'avenir nous le
dira, si un quatrième existe.)

Ce troisième paramètre est expliqué dans le MAN de
[execve](http://manpagesfr.free.fr/man/man2/execve.2.html). Et cela donne accès
au paramètres d'environnement. Voici le nouveau prototype de `main()`:

```C
int	main(int argc, char *argv[], char *envp[]);
```

> Cela est la définition possible pour les systèmes Unix.

Mais ce prototype pose un problème de portabilité sur d'autres systèmes. Il
existe un autre moyen en gardant le prototype ISO C. Via la variable globale
`extern char **environ;`.

Dans le cas de l'utilisation d'application dans notre `PATH`, il nous faudra
donc avoir le `PATH` de l'environnement actuel pour la fonction `execve()`.
_Le détail sera étudier dans le chapitre
[Exécution d'un processus](./EXEC.md)._

## Les arguments

**`int argc`**

Pour rappel, cette variable donne le nombre d'arguments passés dans le
processus.

> Si aucun argument `argc == 1`.

Dans le cas du Mandatory, nous ne devrons avoir exactement `argc == 5`. Pour
le cas du bonus `argc >= 5`.

**`char *argv[]`**

C'est un tableau de chaîne de caractères, se terminant par `NULL`.

Le problème réside dans le fait de découper les parties "cmdN". Car ici, nous
aurons dans une chaine la commande et ses arguments.

**Détails**

- Dans le cas de la partie obligatoire, notre `argv` sera découpé tel que :

	|     argv[0]      | argv[1] | argv[2] | argv[3] | argv[4] |
	|:----------------:|:-------:|:-------:|:-------:|:-------:|
	| nom du programme |  infile |   cmd1  |   cmd2  | outfile |

- Dans le cas du piping de la partie bonus, notre `argv` sera découpé de la
  manière suivante :

	|     argv[0]      | argv[1] | argv[2] | argv[*] | argv[N] |
	|:----------------:|:-------:|:-------:|:-------:|:-------:|
	| nom du programme |  infile |   cmd1  |   cmd*  | outfile |

- Dans le cas du `here_doc` de la partie bonus, notre `argv` sera découpé de la
  manière suivante :

	|     argv[0]      |   argv[1]   |  argv[2]   | argv[3] | argv[4] | argv[5] |
	|:----------------:|:-----------:|:----------:|:-------:|:-------:|:-------:|
	| nom du programme |  `here_doc` |   LIMITER  |   cmd   | cmd1    | outfile |

> A déterminer, si le nombre de commande pour le `here_doc` est variable.

## Les variables d'environnement

Comme expliqué un peu plus haut, `execve()` demandera l'environnement. En
passant par la variable globale `extern char **environ`, nous aurons simplement
à passer celle-ci en paramètre.

---

_Pour plus d'informations sur les arguments, leurs parsing et l'environnement,
voir la
[documentation](https://www.gnu.org/software/libc/manual/html_node/Program-Arguments.html)
de la GNU/LIBC._

