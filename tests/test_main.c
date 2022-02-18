#include "tests.h"

#include <cunits42.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//char *g_infiles[] = {
//	"infile_nonl_txt",
//	"infile_simple_txt",
//	"infile_multi_nl_txt",
//	"foo",
//	NULL
//};
//
//char *g_cmds[] = {
//	"cat.sh",
//	"ls-l.sh",
//	"wc-l.sh",
//	NULL
//};


static char *path_cat(char *path, char *file)
{
	return (strcat(path, file));
}

extern char **environ;

static cunits42_t test_manual(void)
{
	int		i = 0;
	char	*test_dir = "/tmp/test-pipex/";
	char	path[1024];
	char *files[] = {
		"filerrr",
		"filewww",
		"filexxx",
		"filerrrroot",
		"filewwwroot",
		"filexxxroot",
		NULL
	};

	while (files[i])
	{
		strcpy(path, test_dir);
		printf("\nREAD %s %d", path_cat(path, files[i]), access(path, R_OK));
		strcpy(path, test_dir);
		printf("\nWRITE %s %d", path_cat(path, files[i]), access(path, W_OK));
		strcpy(path, test_dir);
		printf("\nEXE %s %d", path_cat(path, files[i]), access(path, X_OK));
		i++;
	}
	i = 0;
	//char *const arg[] = {"/bin/ls", "-al", NULL};
	//execve("/bin/ls", arg, NULL);
	while (environ[i])
	{
		printf("%s ", environ[i]);
		++i;
	}
	i = 0;
	return (CUNITS42_OK);
}

static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_manual), NULL, NULL, CUNITS42_RUN },
#ifdef INTERNAL
#endif /* INTERNAL */
#ifdef MANDATORY
#endif /* MANDATORY */
#ifdef BONUS
#endif /* BONUS */
	CUNITS42_TEST_STOP
};

int	main(int argc, const char *argv[])
{
	return (main_test(tests, argc, argv));
}
