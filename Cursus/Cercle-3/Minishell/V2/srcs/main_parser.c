/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:12 by clai-ton          #+#    #+#             */
/*   Updated: 2025/03/05 17:32:13 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lexer_parser.h"


//temporary
/*void	parser_main(void)
{
	char *input = NULL;
    int i = 0;
	t_list *cmds;
	t_cmd	*cur_cmd;

	system("clear");
	do
	{
		input = readline("\033[0;32mMinishell>\033[0m");
        add_history(input);
		cmds = parse_line(input);
		while (cmds)
		{
			cur_cmd = (t_cmd *) cmds->content;
			printf("Redirections:");
			while (cur_cmd->redir_tok[i])
				printf(" %s", cur_cmd->redir_tok[i++]);
			i = 0;
			printf("\nCommand with arguments:");
			while (cur_cmd->arg_tok[i])
				printf(" %s", cur_cmd->arg_tok[i++]);
			printf("\n");
		}
	} while (input && ft_strncmp("exit", input, 5));
	return (0);
}
*/
/*void	test_quotes(void)
{
	char	str1[] = "je \'ne\' marche\" pas\' \"du\' tout";
	char	str2[] = "je \'ne\' marche\" pas \"non\' plus";
	char	str3[] = "je \'ne\' marche\" pas \'comme\' lautre";
	char	str4[] = "je \'suis\" sense\" marcher, \'hein?";
	char	str5[] = "je \"marche \":D";
	char	str6[] = "je \'marche \':)";
	char	str7[] = "en \"fait je \'marche! \":o";

	printf("%i; %s\n", check_incorrect_quotes(str1), str1);
	printf("%i; %s\n", check_incorrect_quotes(str2), str2);
	printf("%i; %s\n", check_incorrect_quotes(str3), str3);
	printf("%i; %s\n", check_incorrect_quotes(str4), str4);
	printf("%i; %s\n", check_incorrect_quotes(str5), str5);
	printf("%i; %s\n", check_incorrect_quotes(str6), str6);
	printf("%i; %s\n", check_incorrect_quotes(str7), str7);
}
*/
/*void	test_tokenizer_1_helper(char *src, char *idx)
{
	t_list **tok_lst;
	t_list *cur;
	t_list *next;
	t_tok *tok;

	printf("\n%s:\n", idx);
	tok_lst = ft_tokenize_1(src);
	cur = *tok_lst;
	while (cur)
	{
		next = cur->next;
		if (cur->content)
		{
			tok = (t_tok *) cur->content;
			printf("str %i: %s\n", tok->quote_type, tok->str);
		}
		ft_lstdelone(cur, del_token_1);
		cur = next;
	}
}


void	test_tokenizer_1(void)
{
	char	str3[] = "";
	test_tokenizer_1_helper(str3, "3");
	char	str2[] = "test   without";
	char	str1a[] = "'  simplestart  'test simple + without";
	char	str1b[] = "test simple + without'  simpleend  '";
	char	str1c[] = "test '  simplemid  'simple + without";
	char	str4a[] = "\"  doublestart  \"test double + without";
	char	str4b[] = "test double + without\"  doubleend  \"";
	char	str4c[] = "test \"  doublemid  \"double + without";
	char	str5a[] = "test\"double\"'simple'";
	char	str5b[] = "test'simple'\"double\"";
	char	str5c[] = "\"double\"'simple'test";
	char	str5d[] = "'simple'\"double\"test";
	test_tokenizer_1_helper(str2, "2");
	test_tokenizer_1_helper(str1a, "1a");
	test_tokenizer_1_helper(str1b, "1b");
	test_tokenizer_1_helper(str1c, "1b");
	test_tokenizer_1_helper(str4a, "4a");
	test_tokenizer_1_helper(str4b, "4b");
	test_tokenizer_1_helper(str4c, "4c");
	test_tokenizer_1_helper(str5a, "5a");
	test_tokenizer_1_helper(str5b, "5b");
	test_tokenizer_1_helper(str5c, "5c");
	test_tokenizer_1_helper(str5d, "5d");
}
*/
/*void	test_trim_helper(char *str, char *idx)
{
	t_list **tok_lst;
	t_list *cur;
	t_list *next;
	t_tok *tok;

	printf("\n%s:\n", idx);
	tok_lst = ft_tokenize_1(str);
	trim_spaces(tok_lst);
	cur = *tok_lst;
	while (cur)
	{
		next = cur->next;
		if (cur->content)
		{
			tok = (t_tok *) cur->content;
			printf("str: %s\n", tok->str);
		}
		ft_lstdelone(cur, del_token_1);
		cur = next;
	}
}
*/
/*void	test_trim(void)
{
	char	str2[] = "test   no  quote";
	char	str1a[] = "'  simplestart  'test   simple + without  ";
	char	str4b[] = "test double    +  without\"  doubleend  \"";

	test_tokenizer_1_helper(str2, "2");
	test_trim_helper(str2, "2");
	test_tokenizer_1_helper(str1a, "1a");
	test_trim_helper(str1a, "1a");
	test_tokenizer_1_helper(str4b, "4b");
	test_trim_helper(str4b, "4b");
}
*/
/*void	test_var_helper(char *str, char *idx)
{
	t_list **lst;
	t_list *cur;
	t_list *next;
	t_tok *tok;

	printf("string %s: %s\n", idx, str);
	lst = ft_tokenize_1(str);
	replace_var(lst);
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		tok = (t_tok *) cur->content;
		printf("post-replace: %s\n", tok->str);
		ft_lstdelone(cur, del_token_1);
		cur = next;
	}
}

void	test_var(void)
{
	char	str1[] = "$USER is the user";
	char	str2[] = "The user is: $USER";
	char	str3[] = "Now, where is $USER? In the middle!";
	char	str4[] = "$USER";
	char	str5[] = "'$USER'";
	char	str6[] = "\"$USER\"";
	char	str7[] = "$PATH$USER";

	test_var_helper(str3, "3");
	test_var_helper(str1, "1");
	test_var_helper(str2, "2");
	test_var_helper(str4, "4");
	test_var_helper(str5, "5");
	test_var_helper(str6, "6");
	test_var_helper(str7, "7");
}
*/
/*void	test_join_multi(void)
{
	char	**strs;
	char	*final;

	strs = malloc(4 * sizeof(char *));
	strs[0] = ft_strdup("This");
	strs[1] = ft_strdup("String");
	strs[2] = ft_strdup("Rocks");
	strs[3] = ft_strdup("");
	final = ft_strjoin_multi(4, strs, "");
	printf("%s\n", final);
	free(strs[0]);
	free(strs[1]);
	free(strs[2]);
	free(strs[3]);
	free(strs);
	free(final);
}
*/

int main(void)
{
	//return (parser_main());
	//test_quotes();
	//test_trim();
	//test_tokenizer_1();
	//test_trim();
	//test_var();
	//test_join_multi();
}