#include "../Includes/Pipex.h"

void	get_input_fd(char **argv, t_ppx *pipex)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->input_fd = open(argv[1], O_RDONLY);
		if (pipex->input_fd < 0)
			error_msg(ERR_INPUT_FD);
	}
}

void	get_output_fd(char *argv, t_ppx *pipex)
{
	if (pipex->here_doc)
		pipex->output_fd = open(argv, O_WRONLY | O_CREAT | O_APPEND, 777);
	else
		pipex->output_fd = open(argv, O_CREAT | O_RDWR | O_TRUNC, 777);
	if (pipex->output_fd < 0)
		error_msg(ERR_OUTPUT_FD);
}