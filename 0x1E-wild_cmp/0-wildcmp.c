#include "holberton.h"

/**
 * wildcmp_helper - Test for cases of wildcmp wherein *s2 is '*' and the
 * following char matches s1
 * @pattern: Char to look for in s1 from s2
 * @place: Char to compare to pattern
 * @ref_star: '*' char to offset pattern from
 *
 * Return: 1 if s1 and s2 can be considered identical, 0 otherwise
 */

int wildcmp_helper(char *pattern, char *place, char *ref_star)
{
	if (*place == '\0')
	{
		if (*pattern != '\0')
			return (0);
		if (*pattern == '\0')
			return (1);
	}
	if (*place == *pattern)
	{
		if (*(pattern + 1) == '*')
			return (wildcmp_helper(pattern + 2, place + 1, pattern + 1));
		return (wildcmp_helper(pattern + 1, place + 1, ref_star));
	}
	return (wildcmp_helper(ref_star + 1, place + 1, ref_star));
}

/**
 * wildcmp - Determine if s1 can be considered identical to s2
 * @s1: String to compare
 * @s2: String to compare
 *
 * Return: 1
 */

int wildcmp(char *s1, char *s2)
{
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '*' || *s1 == '\0')
			return (wildcmp(s1, s2 + 1));
		if (*(s2 + 1) == '\0')
			return (1);
		if (*s1 == *(s2 + 1))
			return (wildcmp_helper(s2 + 1, s1, s2));
		if (*(s1 + 1) != *(s2 + 1))
			return (wildcmp(s1 + 1, s2));
		if (*(s1 + 1) == *(s2 + 1))
			return (wildcmp(s1 + 2, s2 + 2));
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (0);
	return (wildcmp(s1 + 1, s2 + 1));
}
