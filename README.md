<!--

	README.md

	By: xbeheydt <xavier.beheydt@gmail.com>

	Created: 2022/02/17

-->
# 42cursus - PIPEX

Simulation en programme C de la redirection et du piping de Bash.

_Le projet n'autorise pas l'utilisation de la `libft`._

## Status du projet

|  STATUS  | RESULTS |
|:--------:|:-------:|
| en cours |  NONE   |

_Pour plus d'informations sur le projet, une [documentation](./docs/SUMMARY.md)
a été rédigée._

## Installation

Le projet inclus un tester qui dépend de la lib  de tests unitaires 
[cunits42](https://github.com/xbeheydt/cunits42).

**Clone du projet**

```bash
git clone git@github.com/42cursus-pipex.git
```

**Téléchargement de lib cunits42**

```bash
git submodule init deps/cunits42
```

**Ajouts des sources**

Les sources du projet ne sont pas partagées, il faudra donc cloner votre repo
à l'intérieur de celui-ci tel que `./42cursus-pipex/pipex`, vous pouvez aussi
forker le projet pour intégrer vos sources en `submodule`.

```bash
# dans le dossier <your-path>/42cursus-pipex

# Retrait du sous-module d'origine
git submodule rm pipex
git rm --cached pipex
# Intégration de vos sources en sous-module
git submodule add <your-pipex-srcs-repo> pipex

git add pipex .gitmodules; git commit -m "modify sources"
```

> Pour ceux qui ne maitrise pas les sous-modules voici un article pas mal sur
> le sujet : https://chrisjean.com/git-submodules-adding-using-removing-and-updating/

## Le tester

Le tester dispose de recettes :

- `mandatory` : pour la partie obligatoire.
- `bonus` : pour la partie bonus.
- `internal-mandatory`, `internal-bonus` ou `internal` : sont des recettes liées
  spécifiquement à mon projet, celles-ci sont à modifier pour votre projet et
  ses mécaniques internes.
- `install` : cette recette copie l'exécutable dans le path `~/.local/bin`.
- `re`
- `clean`
- `fclean`

> Les recettes `mandatory`, `bonus` et les `internal-*` crée un fichier `a.out`
> de test. -> `./a.out`.

## Usage

**Mandatory**

```bash
cd pipex
# compilation
make mandatory
# utilisation
./pipex infile cmd1 cmd2 outfile
```

**Bonus**

```bash
cd pipex
# compilation
make bonus
# utilisation pipe
./pipex infile cmd1 cmd2 ... cmdN outfile
# utilisation here_doc
./pipex here_doc LIMITER cmd cmd1 outfile
```

## Crédits

- [Xavier Beheydt](https://github.com/xbeheydt)
