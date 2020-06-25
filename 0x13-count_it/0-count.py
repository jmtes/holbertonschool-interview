#!/usr/bin/env python3
''' Count occurrences of given keywords in a subreddit's hot posts. '''

from requests import get


def count_words(subreddit, word_list, hot_titles=[], after='placeholder'):
    ''' Count occurrences of given keywords in a subreddits's hot posts. '''
    if not after:
        # All hot posts have been fetched

        # Create dict to store count of each keyword occurrence
        occ = {}
        for word in word_list:
            occ[word] = 0

        # Split each title and see if any keyword is present.
        for title in hot_titles:
            title = title.split()
            for word in title:
                if word in occ:
                    occ[word] += 1

        # Print occurrences of each keyword, skipping those with 0.
        for k, v in occ.items():
            if v:
                print('{}: {}'.format(k, v))

        return

    # Set base URL for API queries.
    base_url = 'https://www.reddit.com/r/{}/hot.json?limit=100'.format(
        subreddit)

    if after != 'placeholder':
        # Paginate
        h = get(base_url + '&after={}'.format(after),
                headers={'User-agent': 'errata'})
    else:
        # First request, don't need to paginate
        h = get(base_url, headers={'User-agent': 'errata'})

    # Get data from response
    hot = h.json().get('data')
    if hot:
        # Get titles of hot posts and then recurse
        for post in hot.get('children'):
            hot_titles.append(post.get('data').get('title'))
        return count_words(subreddit, word_list, hot_titles, hot.get('after'))
    else:
        return None
