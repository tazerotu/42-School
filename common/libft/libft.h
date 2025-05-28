/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:52:04 by ttas              #+#    #+#             */
/*   Updated: 2025/05/28 18:06:47 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*----------------------*/
/*       BOOLEANS       */
/*----------------------*/

/**
 * @brief Verifies if the parameter `c` is a number or a letter.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is either a number or a letter,
	and `0` if not.
 */
int					ft_isalnum(int c);

/**
 * @brief Verifies if the parameter `c` is a number or a letter.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is either a number or a letter,
	and `0` if not.
 */
int					ft_isalpha(int c);

/**
 * @brief Verifies if the parameter `c` is a letter.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is a letter, and `0` if not.
 */
int					ft_isdigit(int c);

/**
 * @brief Verifies if the parameter `c` is a number.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is a number, and `0` if not.
 */
int					ft_isprint(int c);

/**
 * @brief Verifies if the parameter `c` is an ascii character.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is an ascii character,
	and `0` if not.
 */
int					ft_isascii(int c);

/**
 * @brief Verifies if the parameter `c` is a whitespace character.
 * @brief Whitespace character are: '\t', '\n', '\v', '\f', '\r', and ' '.
 * @param c Character to be checked (Integer).
 * @return Returns `1` if the parameter `c` is a whitespace character,
	and `0` if not.
 */
int					ft_isspace(int c);

/*----------------------*/
/*       STRING         */
/*----------------------*/

/**
 * @brief Counts how many characters there are in a string `s`.
 * @param s The string to be counted.
 * @return Returns how many characters there are in the given string `s`
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Copies a certain amount `n` of characters from string `src` to `dst`
 * @param dst The string to copy in.
 * @param src The string to be copied from.
 * @param size The number of characters to be copied.
 * @return Returns the amount of characters copied
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Concatenates a certain amount `n` of characters
 * @brief from the string `src` to `dst`
 * @param dst The string to copy in.
 * @param src The string to be copied from.
 * @param size The number of characters to be copied.
 * @return Returns the amount of characters concatenated
 */
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Find the first occurence of the character `c` in the string `s`.
 * @param s The string to look in.
 * @param c The character to find.
 * @return Returns a pointer to the first occurrence
		of the character `c` in the string `s`.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Find the last occurence of the character `c` in the string `s`.
 * @param s The string to look in.
 * @param c The character to find.
 * @return Returns a pointer to the last occurrence
		of the character `c` in the string `s`.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Write a character on the chosen output.
 * @param c The character to write.
 * @param fd The output chosen (1 is Terminal).
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Write a string on the chosen output.
 * @param s The string to write.
 * @param fd The output chosen (1 is Terminal).
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Write a string on the chosen output with EOL (End Of Line).
 * @param s The string to write.
 * @param fd The output chosen (1 is Terminal).
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * @brief - It converts the integer n into its string representation.
 * @brief - It then writes this string to the specified file descriptor `fd`.
 * @param n The integer to be output.
 * @param fd The file descriptor where the output will be sent.
 * @return - The integer n is written as a series of
 * @return characters to the file descriptor `fd`.
 */
void				ft_putnbr_fd(int n, int fd);

/**
 * @brief - It compares at most the first `n` characters
 * @brief of two strings `s1` and `s2`.
 * @brief - Returns an integer less than, equal to, or greater
 * @brief than zero if `s1` is found, respectively,
 * @brief to be less than, to match, or be greater than `s2`.
 * @param s1 Pointer to the first string to be compared.
 * @param s2 Pointer to the second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return - 0 if the first `n` characters of both strings are equal.
 * @return - A negative value if the first differing character
 * @return in s1 is less than the corresponding character in s2.
 * @return - A positive value if the first differing character in `s1` is
 * @return greater than the corresponding character in `s2`.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief - It allocates memory for a new string.
 * @brief - It copies the content of the input string
 * `s` into the newly allocated memory.
 * @brief It returns a pointer to the newly allocated
 * memory containing the duplicated string.
 * @param s A pointer to a null-terminated string (const char *)
 * that you want to duplicate.
 * @return The function returns a pointer to a null-terminated byte string,
 *  which is a duplicate of the input string `s`.
 */
char				*ft_strdup(const char *s);

/**
 * @brief - It searches the first `len` characters
 * of the string `big` for the substring `little`.
 * @brief - If the substring is found within the first `len`
 * characters, it returns a pointer to the first occurrence
 * of the substring within `big`.
 * @brief - If the substring is not found within
 * the first `len` characters, it returns NULL.
 * @param big A pointer to the null-terminated string in
 * which you want to search for the substring.
 * @param little A pointer to the null-terminated
 * substring you want to search for.
 * @param len The maximum number of characters to
 * search in the string `big`.
 * @return - Returns a pointer to the first occurrence of the substring `little`
 *  in the string `big` within the first `len` characters,
 * or NULL if the substring is not found.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/**
 * @brief - It allocates memory for a new string.
 * @brief - It copies a portion of the string `s` starting from index `start`
 * and up to `len` characters (or until the end
 * of `s` if `len` exceeds the length of the remaining string).
 * @brief - It returns a pointer to the newly
 * allocated memory containing the extracted substring.
 * @param s A pointer to the null-terminated
 *  string from which to extract the substring.
 * @param start The index within the
 * string `s` indicating the start of the substring.
 * @param len The maximum length of the substring to extract.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Joins the two string `s1` and `s2`
 * @param s1 the frist string
 * @param s2 the second string
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief - Splits the given string `s` from the
 * @brief  first occurence of the character `c` into two strings
 * @param s the string to be split
 * @param c the character to split from
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Splits the given string `s` into multiple strings,
 * @brief NULL-terminating the char **.
 * @brief Empty strings resulting from two consecutive characters
 * @brief from the `charset` will be skipped.
 * @brief Each time a character in `charset`
 * @brief or the terminating '\0' are encountered,
 * @brief the characters up to this point will be split from the rest.
 * @brief The charset characters will not be included in the resulting char **.
 * @param s the string to be split
 * @param charset the characters according to which the strings will be split
 */

char				**ft_split_set(char *s, char *charset);

/**
 * @brief Takes an integer `n` and changes it into a string (using Malloc)
 * @param n The integer to be changes into a string
 */
char				*ft_itoa(int n);

/**
 * @brief Trims a set of characters `set` from the
 * @brief start and end of the string `s1`
 * @param s1 The string to be trimmed
 * @param set The characters to trim
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Applies the function `f` to each characters of the
 * @brief string `s` to obtain a new string (using Malloc)
 * @param s The string to be iterated
 * @param f The function to apply to each characters
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief iterates through each character of the string s and applies a
 * @brief function f to each character, along with its index in the string.
 * @param s The string to be iterated
 * @param f The function to apply to each character
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*----------------------*/
/*         MATHS        */
/*----------------------*/

/**
 * @brief Converts `nbtr` an array (string) of numbers to an integer.
 * @param s The array to be converted.
 * @return Returns the Integer of the converted array `nptr`.
 */
int					ft_atoi(const char *nptr);

/**
 * @brief Converts `nbtr` an array (string) of numbers to an Long.
 * @param s The array to be converted.
 * @return Returns the Long of the converted array `nptr`.
 */
long				ft_atol(char *nptr);

/*----------------------*/
/*          ARRAY       */
/*----------------------*/

/**
 * @brief Initializes an array `s` of `n` Bytes with the parameter `c`.
 * @param s The array to be initialized.
 * @param c The character to be put in the array.
 * @param n The size of the array to be initialized.
 * @return Returns the initialized array `s`.
 */
void				*ft_memset(void *s, int c, size_t n);

/**
 * @brief Initializes an array `s` of `n` Bytes with the parameter `c`.
 * @param dest The array in which it will be moved.
 * @param src The array to be moved.
 * @param n The number of characters to be moved.
 * @return Returns the array `dest`.
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Initializes an array `s` of `n` Bytes with the parameter `c`.
 * @param dest The array in which it will be moved.
 * @param src The array to be moved.
 * @param n The number of characters to be moved.
 * @return Returns the array `dest`.
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Initializes an array `s` of `n` Bytes with the character `\0`.
 * @param s The array to be initialized.
 * @param n The size of the array to be initialized.
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief - It searches the memory block pointed to
 * by `s` for the first occurrence of the byte `c`.
 * @brief - The search is limited to the first `n` bytes of the memory block.
 * @brief - If the byte `c` is found, it returns a
 * pointer to the first occurrence of `c` within the memory block.
 * @brief - If the byte `c` is not found within the first `n` bytes,
	it returns NULL.
 * @param s A pointer to the memory block to be searched.
 * @param c The byte value to be searched for.
 * @param n The number of bytes to search within the
 * memory block pointed to by `s`.
 * @return - Returns a pointer to the first occurrence of the byte `c`
 *	within the memory block pointed to by `s`,
 *	or NULL if `c` is not found within the first `n` bytes.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief - It compares the first `n` bytes of the
 * memory blocks pointed to by `s1` and `s2`.
 * @brief - If the byte at `s1` is less than the byte at `s2`
 * , it returns a negative value.
 * @brief - If the byte at `s1` is greater than the byte at `s2`
 * , it returns a positive value.
 * @brief - If the bytes at `s1` and
 * `s2` are equal, it continues comparing until
 * `n` bytes have been compared or until a difference is found.
 * @brief - If all compared bytes are equal, it returns zero.
 * @param s1 Pointer to the first memory block to compare.
 * @param s2 Pointer to the second memory block to compare.
 * @param n Number of bytes to compare.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*----------------------*/
/*        OTHERS        */
/*----------------------*/

/**
 * @brief Change a lowercase character into an uppercase one if possible.
 * @param c The character to change.
 * @return The changed character if possible, if not `0`.
 */
int					ft_toupper(int c);

/**
 * @brief Change an uppercase character into a lowercase one if possible.
 * @param c The character to change.
 * @return The changed character if possible, if not `0`.
 */
int					ft_tolower(int c);

/**
 * @brief - It calculates the total memory
 * required to store `nmemb` elements, each of size bytes.
 * @brief - It allocates memory for the calculated size.
 * @brief - It initializes the allocated memory to zero
 * , setting all bytes to 0.
 * @brief - It returns a pointer to the allocated memory block.
 * @param nmemb Number of elements to allocate memory for.
 * @param size Size of each element, in bytes.
 */
void				*ft_calloc(size_t nmemb, size_t size);

/*----------------------*/
/*          BONUS       */
/*----------------------*/

//Linked List
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Creates a new list (using Malloc) with
 * @brief the content given as parameter
 * @param content The content for the new list
 * @return Returns the new list
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Adds a new element `new` to the beginning of the list `lst`
 * @param new a pointer to the new node that
 * needs to be added to the front of the list
 * @param list A pointer to a pointer to the head of the linked list.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Find the size of the list `lst`
 * @param lst the list to find the size of
 * @return Return the size of the list
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Find the last values of the list `lst`
 * @param lst the list to find the last value of
 * @return Returns the last value of the list
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Adds a new element `new` to the end of the list `lst`
 * @param new a pointer to the new node that
 * needs to be added to the end of the list
 * @param list A pointer to a pointer to the head of the linked list.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief This function deletes the current content of the list `lst`
 * @param lst The list to have the content deleted from
 * @param del the funtion to delete the content
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Clears the content of the list `lst`
 * @param lst the list to be cleared
 * @param del The function to delete the content with
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates with the function f in the content of the list `lst`
 * @param lst the list to be iterated in
 * @param f the function to iterate with
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list `lst` with the function
 * @brief `f` and return a new list with after the iteration
 * @param lst The list to be used
 * @param f the function to iterate with
 * @param del the function to delete with
 * @return Returns a new list iterated with the function `f`
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

char				*get_next_line(int fd);
char				*ft_free_join(char *s1, char *s2);
char				*ft_current_line(char *buffer);
char				*ft_read_file(int fd, char *res);
char				*ft_next_line(char *buffer);

// FPRINTF
int					ft_fprintf(int fd, char *format, ...);

// PRINTF
int					ft_printf(const char *format, ...);

// DOUBLE LINKED LIST
typedef struct s_double_list
{
	void					*content;
	struct s_double_list	*next;
	struct s_double_list	*prev;
}	t_dblst;

t_dblst				*ft_dblstnew(void *content);
void				ft_dblstadd_front(t_dblst *list, t_dblst *new);
void				ft_dblstadd_back(t_dblst *list, t_dblst *new);
void				ft_dblstclear(t_dblst *lst, void (*del)(void *));
void				ft_dblstclear_before(t_dblst *lst, void (*del)(void *));
void				ft_dblstclear_after(t_dblst *lst, void (*del)(void *));
void				ft_dblstdelone(t_dblst *node, void (*del)(void *));
void				ft_dblstdel_n_before(
						t_dblst *node, void (*del)(void *), size_t n);
void				ft_dblstdel_n_after(
						t_dblst *node, void (*del)(void *), size_t n);
t_dblst				*ft_dblstfirst(t_dblst *lst);
t_dblst				*ft_dblstlast(t_dblst *lst);
void				ft_dblstinsert_before(t_dblst *lst_node, t_dblst *new);
void				ft_dblstinsert_after(t_dblst *lst_node, t_dblst *new);
int					ft_dblstsize(t_dblst *lst);

char				*ft_strjoin_multi(int size, char **strs, char *sep);

#endif
