# 0x0D. Count It!

## Instructions

Write a recursive function that queries the Reddit API, parses the titles of all hot articles, and prints a sorted count of given keywords.

* Keywords are case-insensitive and delimited by spaces.
* "Javascript" should count as "javascript", but "java" should not.
* "java.", "java!", and "java\_" should not count as "java".

## Requirements

* Prototype should be `def count_words(subreddit, word_list)`
* You may add parameters to the prototype, but the first and second parameters must remain the same.
* Results must be printed in descending order by count.
* Words with no matches should be skipped and not printed.
* Results should be based on the numeber of times a keyword appears, not titles it appears in ("java java java" counts as 3 separate occurrences of "java").
* If no posts match or the subreddit is invalid, print a newline.
* Invalid subreddits may return a redirect to search results. Ensure you are not following redirects.
* You must use recursion
