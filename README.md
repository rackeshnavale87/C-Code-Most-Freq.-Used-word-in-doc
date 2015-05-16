# C-Code-Most-Freq.-Used-word-in-doc
Objective C code to find the maximum frequently used word in the document

#####################################################################################################################

Programming Language : Objective C
Data Structure used - Single Linked List

Time Complexity - O(n); Since we are only finding max freq word.
If we wish to list all words with the descending count of occurance, the complexity would become [O(n*logn) + n].

The progam reads the text file having text. Then with the parsing of text it takes the word and insert into the single linked list.
While inserting, if the word has already inserted in the list, Just increament the cound and free the duplicate word struct node.

#####################################################################################################################
