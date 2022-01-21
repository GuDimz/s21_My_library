# Library C

In this library, I implemented functions from the standard C libraries.

## My library includes:

* Libft
 * Stack (https://en.cppreference.com/w/cpp/container/stack)



# <img src= "https://drive.google.com/uc?export=view&id=1aK82QDdsv3CKy1vBmG5CYrZijvs97h-D" width=200 height=200>

## Instructions.

This program simulates the work of pipes and redirects

## Examples.

 `$> ./pipex infile ``ls -l'' ``wc -l'' outfile` should be the same as 
 
 `“< infile ls -l | wc -l > outfile”`
 ***
`$> ./pipex infile ``grep a1'' ``wc -w'' outfile` should be the same as 

`“< infile grep a1 | wc -w > outfile”`


## How to use?

`make`

`$> ./pipex file1 cmd1 cmd2 file2`


## How to use test?

`make test`

## Good Luck!

