# 0x06 - Log Parsing

Write a script that reads `stdin` line by line and computes metrics:
* Input format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`

After every 10 lines and/or a keyboard interruption, print the following statistics from the beginning:
* Total file size: `File size: <total size>`
* Where `<total size>` is the sum of all previous `<file size>` (see input format above)

Number lines by status code:
* Possible status codes: `200`, `301`, `400`, `401`, `403`, `404`, `405`, `500`
* If a status code doesn't appear, don't print anything for this status code
* Format: `<status code>: <number>`
* Status codes should be printed in ascending order
