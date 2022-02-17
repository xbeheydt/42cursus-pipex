#ifndef TESTS_H
# define TESTS_H

# include <cunits42.h>

#ifdef DEBUG
# define DEBUG(...) printf(__VA_ARGS__);
#else
# define DEBUG(...)
#endif /* DEBUG */

# ifdef INTERNAL
#endif /* INTERNAL */

# ifdef MANDATORY
# endif /* MANDATORY */

# ifdef BONUS
# endif /* BONUS */

#endif /* TESTS_H */
