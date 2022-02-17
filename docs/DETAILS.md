<!--

	DETAILS.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/17

-->
# 42cursus - PIPEX - Détails et Explications

## Mandatory

**Les redirections**

En bash, il est possible de créer des redirections d'entrée et/ou de sortie,
via les commandes ci-dessous :

```bash
# redirection du STDIN depuis un fichier
< infile cmd
# redirection du STDOUT vers un fichier
cmd > outfile
# combinaison des deux redirections

< infile cmd > outfile
```

**Problèmes des redirections**

- redirection STDIN

	Il faut avoir les droits depuis l'application _lecture_ sur le fichier
	`infile`.

- redirection STDOUT

	Il faut avoir les droits de lecture sur le fichier `outfile`, voir de
	manière implicite le dossier où l'on va écrire.

**Les tubes - piping**

Le principe du piping, est de connecter le STDOUT d'une application au STDIN de
la suivante, voici un exemple de connexion entre le `cmd1` et la `cmd2` :

```bash
cmd1 | cmd2
```

> Il est possible de chainer "autant" de commande que l'on veut, mais cela est
> dans la partie bonus.

**Problèmes du piping**

Comme pour les redirections, il faut avoir les droits d'exécution du les
commandes et donc de manière soujaccente aussi en lecture depuis STDIN et
écriture en STDOUT.

**Combinaison des redirections et piping**

Voici l'équivalent en bash du besoin du projet :

```bash
< infile cmd1 | cmd2 > outfile
```

### PIPEX mandatory

La commande suivante exprime comment nous devons utiliser notre `pipex` :

```bash
./pipex infile "cmd1" "cmd2" outfile
```

## Bonus

La partie bonus ajoute quelques fonctionnalités permettant de devenir plus
proche de la réalité, tel que :

- le piping de `N` commandes.

	```bash
	# en bash
	< infile cmd1 | cmd2 | cmd3 | ... | cmdN > outfile
	# en pipex
	./pipex infile cmd1 cmd2 cmd3 ... cmdN outfile

- La gestion du `here_doc`.

	le `here_doc` est um peu plus complexe car ici on pourrait mélanger texte
	brute et commande. Mais le sujet précise uniquement des commandes.
	
	Donc on part du principe que l'on pipe des commandes vers le STDIN d'une
	commande principale.

	```bash
	# en bash
	cmd << LIMITER | cmd1 >> outfile
	# en pipex
	./pipex here_doc LIMITER cmd cmd1 outfile
	```
	
	On remarque qu'il faut préfixé par le mot clef `here_doc` puis avoir un
	`LIMITER`.

	> Le `LIMITER` ici n'a pas vraiment de sens mais celui-ci permettra une
	> compatibilité dès lors que nous referons un équivalent de `bash`, je
	> suppose.
	
  > la documentation du project n'indique pas si l'on doit pouvoir avoir `N`
  > commandes dans le `here_doc`.

## Points à respecter

Il y a plusieurs points à vérifier :

- [ ] Les droits d'accès fichiers et/ou commandes.
- [ ] Gestion des erreurs.
  - [ ] Messages d'erreurs.
  - [ ] Code de sortie d'erreurs.
