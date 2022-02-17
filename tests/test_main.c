#include "tests.h"

#include <cunits42.h>

static cunits42_t test_manual(void)
{
	return (CUNITS42_OK);
}

static cunits42_test_t	tests[] = {
	{ TEST_FCN(test_manual), NULL, NULL, CUNITS42_SKIP },
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
