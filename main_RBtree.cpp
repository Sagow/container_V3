#include "common.hpp"

#define T1 int
#define T2 std::string

struct ft_more {
    bool	operator()(const T1 &first, const T1 &second) const {
        return (first > second);
    }
};

typedef TESTED_NAMESPACE::map<T1, T2> ft_mp;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator ft_mp_it;

int		main(void)
{
    return (0);
}
