/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:12 by clai-ton          #+#    #+#             */
/*   Updated: 2025/05/16 10:46:33 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

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
/*void	test_tokenizer_new_helper(char *src, char *idx)
{
	t_dblst **tok_lst;
	t_dblst *cur;
	t_dblst *next;
	int		count;
	int		ret_val;

	count = 1;
	printf("\nidx %s, input: %s\n", idx, src);
	tok_lst = malloc(sizeof(t_dblst *));
	if (!tok_lst)
	{
		error_message(RET_MALLOC_ERR, "splitting prompt");
		return;
	}
	ret_val =  split_input(src, tok_lst);
printf("ret_val %i\n", ret_val);
	if (ret_val == RET_NOTHING_DONE)
	{
		printf("[Empty input]\n");
		free(tok_lst);
		return ;
	}
	cur = ft_dblstfirst(*tok_lst);
	while (cur)
	{
		next = cur->next;
		if (cur->content)
			printf("part %i: %s\n", count, (char *) cur->content);
		cur = next;
		++count;
	}
	free_words_dblst(tok_lst);
}*/
/*void	test_split_spaces(void)
{
	char	str3[] = "";
	test_tokenizer_new_helper(str3, "3");
	char	str2a[] = "test   without";
	test_tokenizer_new_helper(str2a, "2a");
	char	str2b[] = "    test   without     ";
	test_tokenizer_new_helper(str2b, "2b");

	char	str1a[] = "'  $USER  'test $USER + without";
	char	str1b[] = "test simple + without'  simpleend  '";
	char	str1c[] = "test '  simplemid  'simple + without";
	char	str4a[] = "\"  doublestart  \"test double + without";
	char	str4b[] = "test double + without\"  doubleend  \"";
	char	str4c[] = "test \"  doublemid  \"double + without";
	char	str5a[] = "test\"double\"'simple'";
	char	str5b[] = "test'simple'\"double\"";
	char	str5c[] = "\"double\"'simple'test";
	char	str5d[] = "'simple'\"double\"test";
	test_tokenizer_new_helper(str1a, "1a");
	test_tokenizer_new_helper(str1b, "1b");
	test_tokenizer_new_helper(str1c, "1b");
	test_tokenizer_new_helper(str4a, "4a");
	test_tokenizer_new_helper(str4b, "4b");
	test_tokenizer_new_helper(str4c, "4c");
	test_tokenizer_new_helper(str5a, "5a");
	test_tokenizer_new_helper(str5b, "5b");
	test_tokenizer_new_helper(str5c, "5c");
	test_tokenizer_new_helper(str5d, "5d");
}*/
/*void test_split_special_and_space(void)
{
	// char	str1a[] = "reblochon    <pa ta te<canard";
	// char	str1b[] = "reblochon>    pa ta te>canard";
	// char	str2a[] = "reblochon<< pa ta te<<canard";
	// char	str2b[] = "reblochon >>pa ta te>>canard";
	// char	str3a[] = "reblochon <<< pa ta te<<<canard";
	// char	str3b[] = "reblochon >>> pa ta te>>>canard";

	// test_tokenizer_new_helper(str1a, "1a");
	// test_tokenizer_new_helper(str1b, "1b");
	// test_tokenizer_new_helper(str2a, "2a");
	// test_tokenizer_new_helper(str2b, "2b");
	// test_tokenizer_new_helper(str3a, "3a");
	// test_tokenizer_new_helper(str3b, "3b");
	
	// char	str5[] = "";
	// test_tokenizer_new_helper(str5, "5");

	char	str6a[] = "reblochon << pa ta te>>canard";
	char	str6b[] = "reblochon >> pa ta te<<canard";
	test_tokenizer_new_helper(str6a, "6a");
	test_tokenizer_new_helper(str6b, "6b");

	char	str4a[] = "reblochon | pa ta te|canard";
	char	str4b[] = "reblochon || pa ta te||canard";
	char	str7a[] = "reblochon | pa ta te<canard";
	char	str7b[] = "reblochon > pa ta te|canard";
	test_tokenizer_new_helper(str4a, "4a");
	test_tokenizer_new_helper(str4b, "4b");
	test_tokenizer_new_helper(str7a, "7a");
	test_tokenizer_new_helper(str7b, "7b");

	char	str8a[] = "reblochon<>pa ta te<canard";
	char	str8b[] = "reblochon><pa ta te>canard";
	test_tokenizer_new_helper(str8a, "8a");
	test_tokenizer_new_helper(str8b, "8b");
}*/
/*void	test_dblist(void)
{
	char str0[] = "0 kflds;d";
	char str1[] = "1 lkfjsdflks;d";
	char str2[] = "2 l;esjf;lkjd;d";
	char str3[] = "3 mnvdxmv;d";
	char str4[] = "4 wkej;d";
	char str5[] = "5 d;lsd'a;d";
	char str6[] = "6 ????;d";

	t_dblst *mid;
	mid = ft_dblstnew(str3);
	ft_dblstadd_back(mid, ft_dblstnew(str5));
	ft_dblstadd_front(mid, ft_dblstnew(str1));
	ft_dblstinsert_after(mid, ft_dblstnew(str4));
	ft_dblstinsert_before(mid, ft_dblstnew(str2));
	ft_dblstadd_back(mid, ft_dblstnew(str6));
	ft_dblstadd_front(mid, ft_dblstnew(str0));
	
	t_dblst *cur;
	t_dblst *next;
	printf("insert and add\n");
	cur = ft_dblstfirst(mid);
	while (cur)
	{
		printf("%s\n", (char *) cur->content);
		next = cur->next;
		cur = next;
	}
	printf("test deletion n\n");
	ft_dblstdel_n_after(mid, ft_do_nothing, 2);
	ft_dblstdel_n_before(mid, ft_do_nothing, 2);
	cur = ft_dblstfirst(mid);
	printf("deletion happened\n");
	while (cur)
	{
		printf("%s\n", (char *) cur->content);
		next = cur->next;
		cur = next;
	}
}
*/

/*void test_create_cmd_helper(char *idx, char *input)
{
	t_cmd *cmd;
	t_cmd *first;
	int i;

printf("\nStr %s: %s\n", idx, input);
	cmd = process_line(input);
	first = cmd;
printf("finished processing\n");
	while (cmd)
	{
		printf("Printing a command:\n");
		if (cmd->redir_tok)
		{
			i = 0;
			while (cmd->redir_tok[i])
			{
				printf("redir %i: %s\n", i, cmd->redir_tok[i]);
				++i;
			}
		}
		if (cmd->arg_tok)
		{
			i = 0;
			while (cmd->arg_tok[i])
			{
				printf("arg %i: %s\n", i, cmd->arg_tok[i]);
				++i;
			}
		}
		cmd = cmd->next;
	}
	if (first)
		free_cmds(first);
}

void test_create_cmd(void)
{
	char	str1[] = "";
	test_create_cmd_helper("1", str1);
	
	char	str2a[] = "reblochon carotte < ananas patate<canard DESTOP";
	char	str2b[] = "reblochon carotte >> ananas patate>>canard DESTOP";
	test_create_cmd_helper("2a", str2a);
	test_create_cmd_helper("2b", str2b);
	
	char	str3[] = "reblochon | patate|canard";
	char	str4[] = "reblochon | patate < test.txt >> output.txt | canard 123456789 > toto.txt";
	test_create_cmd_helper("3", str3);
	test_create_cmd_helper("4", str4);
}
*/
/*void	test_split_set(void)
{
	char **split1 = ft_split_set("\"un 'elephant\"\"\" qui \"se balancait~\"", "\"");
	int i = 0;
	while (split1[i])
	{
		printf("str %i: %s\n", i, split1[i]);
		free(split1[i++]);
	}
	free(split1);

	split1 = ft_split_set("\"un 'elephant\"\"\" qui \"se balancait~\"", "'");
	i = 0;
	while (split1[i])
	{
		printf("str %i: %s\n", i, split1[i]);
		free(split1[i++]);
	}
	free(split1);
}*/

/*static void test_expander_helper(char *str, char *str_idx, t_pipe *pipe)
{
	printf("\nprocessing str %s:\n", str_idx);
	t_cmd *cmds = process_line(str, pipe->envp, pipe);
	t_cmd *cur = cmds;
	while (cur)
	{
		int i = 0;
		while (cur->redir_tok[i])
			printf("red: %s\n", cur->redir_tok[i++]);
		i = 0;
		while (cur->arg_tok[i])
			printf("arg: %s\n", cur->arg_tok[i++]);
		cur = cur->next;
	}
	free_cmds(cmds);
}

static void test_expander(t_pipe *pipe)
{
	// char str4[] = "$USER";
	// char str5[] = "\"$USER\"";
	// char str6[] = "'$USER'";

	// test_expander_helper(str4, "4", pipe);
	// test_expander_helper(str5, "5", pipe);
	// test_expander_helper(str6, "6", pipe);

	// char str10[] = "$\"\"USER\"\" \"\"$''USER'''$USER'";
	// test_expander_helper(str10, "10", pipe);
	
	// char str11[] = "$US $USER $USERRR";
	// test_expander_helper(str11, "11", pipe);

	char str12[] = "$'USER'";
	test_expander_helper(str12, "12", pipe);//casse encore
	// char str13[] = "$";
	// test_expander_helper(str13, "13", pipe);
	
	// char str7[] = "$USER$USER$USER";
	// char str8[] = "\"$USER\"\"$USER\"\"$USER\"";
	// char str9[] = "'$USER''$USER''$USER'";

	// test_expander_helper(str7, "7", pipe);
	// test_expander_helper(str8, "8", pipe);
	// test_expander_helper(str9, "9", pipe);

	// char str7b[] = "$USER $USER $USER";
	// char str8b[] = "\"$USER\" \"$USER\" \"$USER\"";
	// char str9b[] = "'$USER' '$USER' '$USER'";

	// test_expander_helper(str7b, "7b", pipe);
	// test_expander_helper(str8b, "8b", pipe);
	// test_expander_helper(str9b, "9b", pipe);
	
	// char str7c[] = "$USER'$USER'\"$USER\"";
	// char str8c[] = "\"$USER\"'$USER'$USER";
	// char str9c[] = "\"$USER\"$USER'$USER'";

	// test_expander_helper(str7c, "7c", pipe);
	// test_expander_helper(str8c, "8c", pipe);
	// test_expander_helper(str9c, "9c", pipe);

	// char str1[] = "USEr $USEr\n9USER $9USER\nUSER9 "
	// "$USER9\nUSER $USER\n? $?\n";
	// test_expander_helper(str1, "1", pipe);


	// char str2[] = "$USER $USER '$USER' \"$USER\"\"$USER\"";
	// char str3[] = "$USER$USER'$USER'\"$USER\"\"$USER\"";
	
	// test_expander_helper(str2, "2", pipe);
	// test_expander_helper(str3, "3", pipe);
}
*/
/*
int main (int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	t_pipe *pipe;
    // system("clear");
	pipe = malloc(sizeof(t_pipe));
	init(pipe, envp);
	test_expander(pipe);
	free_pipe_env(pipe);
	return(0);
}
*/
/*int main(void)
{
	//test_quotes();
	//test_trim();
	//test_join_multi();
	//test_split_spaces();
	//test_split_special_and_space();
	//test_dblist();
	//test_create_cmd();
	test_split_set();
}*/
